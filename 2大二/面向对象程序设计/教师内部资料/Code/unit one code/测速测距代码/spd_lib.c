/** 
 * \brief     测速测距主模块
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_lib.c
 * 
 * 测速外部接口实现
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
/*******************************************************************************/
#include "Spd_lib.h"
#include "Spd_Sensor.h"
#include "Spd_State.h"
#include "Spd_Base.h"
/*******************************************************************************/
extern OPG_T      g_OPG_A;
extern OPG_T      g_OPG_B;
extern Radar_T    g_Radar;
extern State_T    g_State;

static BOOL       s_bInitDone = EN_FALSE;       /*是否调用过Init函数*/
static BOOL       s_bMeasureDone = EN_FALSE;    /*是否调用过Measure函数*/
static BOOL       s_bVeloOK;                    /*测速健康标志*/
static uint32_t   s_uiErrorCode;                /*错误码*/

/*******************************************************************************/
/* Function:  ResetVars*/
/* Brief:      测速周期数据重置*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void ResetVars(void)
{
    s_uiErrorCode = 0U;
    Sensor_ResetVars();
    State_ResetVars();
}


/*******************************************************************************/
/* Function:  LoadInput*/
/* Brief:      测速输入数据处理*/
/* Param:     SPDInput_T * const pSPDInput  测速输入数据*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static int32_t LoadInput( SPDInput_T * const pSPDInput)
{
    int32_t ret = ATC_ERROR;
    
    ret = Sensor_LoadInput(pSPDInput);
    if (ATC_OK == ret)
    {
        ret = State_LoadInput(pSPDInput);
    }

    return ret;
}

/*******************************************************************************/
/* Function:  ResetOutput*/
/* Brief:      测速输出数据重置*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void ResetOutput(void)
{
    Sensor_ResetOutput();
    State_ResetOutput();
}
/*******************************************************************************/
/* Function:  SPD_Init*/
/* Brief:     测速初始化*/
/* Param:     void  */
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
int32_t SPD_Init(const SPDParam_T * const pParam)
{
    int32_t ret = ATC_ERROR;
    int32_t ret_sor = ATC_ERROR;
    int32_t ret_sta = ATC_ERROR;

    ResetVars();

    if (ATC_NULL != pParam)
    {
        ret_sor = Sensor_Init(pParam);
        ret_sta = State_Init(pParam);
    } 

    if ((ATC_OK == ret_sor) && (ATC_OK == ret_sta))
    {
        s_bInitDone = EN_TRUE;
        s_bVeloOK = EN_TRUE;
        ret = ATC_OK;
    }
    else
    {
        s_bInitDone = EN_FALSE;
        s_bVeloOK = EN_FALSE;
    }

    return ret;
}

/*******************************************************************************/
/* Function:  SPD_Measure*/
/* Brief:      测速测距主函数*/
/* Param:     SPDInput_T * const pSPDInput  测速输入数据*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_Measure(SPDInput_T * const pSPDInput)
{
    int32_t ret = ATC_ERROR;
    int32_t ret_in = ATC_ERROR;
    int32_t ret_sta = ATC_ERROR;
    
    s_bMeasureDone = EN_TRUE;

    if ((ATC_NULL != pSPDInput) && (EN_TRUE == s_bVeloOK) && (EN_TRUE == s_bInitDone))
    {
        /*重置周期变量*/
        ResetVars();
        /*输入数据读取及验证*/
        ret_in = LoadInput(pSPDInput);

        if (ATC_OK == ret_in)
        {
            /*传感器信息处理*/
            Sensor_Process();
            /*状态机信息处理*/
            ret_sta = State_Process();
        }
    }
    if ((ATC_OK == ret_in) && (ATC_OK == ret_sta))
    {
        ret = ATC_OK;
    }
    else
    {
        ResetOutput();
        s_bVeloOK = EN_FALSE;    
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetMaxMov*/
/* Brief:      获取最大周期位移*/
/* Param:     int32_t * const pMaxMov  最大周期位移*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_GetMaxMov(int32_t * const pMaxMov)
{
    int32_t ret = ATC_ERROR;
    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);

    if ((ATC_NULL != pMaxMov) && (EN_TRUE == b_avail))
    {
        *pMaxMov = g_State.Speed.iMaxMov;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetMinMov*/
/* Brief:      获取最小周期位移*/
/* Param:     int32_t * const pMinMov  最小周期位移*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_GetMinMov(int32_t * const pMinMov)
{
    int32_t ret = ATC_ERROR;
    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);

    if ((ATC_NULL != pMinMov) && (EN_TRUE == b_avail))
    {
        *pMinMov = g_State.Speed.iMinMov;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetRawMov*/
/* Brief:      获取原始周期位移*/
/* Param:     int32_t * const pRawMov  原始周期位移*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_GetRawMov(int32_t * const pRawMov)
{
    int32_t ret = ATC_ERROR;

    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);

    if ((ATC_NULL != pRawMov) && (EN_TRUE == b_avail))
    {
        *pRawMov = g_State.Speed.iRawMov;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetDst2Bcn*/
/* Brief:      获取到信标的距离*/
/* Param:     DistToBcn_T * const pDist2Bcn  到信标的距离*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_GetDst2Bcn( DistToBcn_T * const pDist2Bcn )
{
    int32_t ret = ATC_ERROR;
    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);

    if ((ATC_NULL != pDist2Bcn) && (EN_TRUE == b_avail))
    {
        *pDist2Bcn = g_State.Dist2Bcn;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetMaxSpeed*/
/* Brief:      获取最大速度*/
/* Param:     int32_t * const pMaxSpeed  最大速度*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_GetMaxSpeed(int32_t * const pMaxSpeed)
{
    int32_t ret = ATC_ERROR;
    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);
    
    if ((ATC_NULL != pMaxSpeed) && (EN_TRUE == b_avail))
    {
        *pMaxSpeed = g_State.Speed.iMaxSpeed;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetRawSpeed*/
/* Brief:      获取原始速度*/
/* Param:     int32_t * const pRawSpeed  原始速度*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_GetRawSpeed(int32_t * const pRawSpeed)
{
    int32_t ret = ATC_ERROR;
    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);

    if ((ATC_NULL != pRawSpeed) && (EN_TRUE == b_avail))
    {
        *pRawSpeed = g_State.Speed.iRawSpeed;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetAccel*/
/* Brief:     获取加速度*/
/* Param:     int32_t * const pAccel  加速度*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/9*/
/*******************************************************************************/
int32_t SPD_GetAccel(int32_t * const pAccel)
{
    int32_t ret = ATC_ERROR;
    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);

    if ((ATC_NULL != pAccel) && (EN_TRUE == b_avail))
    {
        *pAccel = g_State.Speed.iAccel;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetState*/
/* Brief:      获取测速状态机状态*/
/* Param:     SPDState_E * const pState  测速状态*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_GetState( SPDState_E * const pState )
{
    int32_t ret = ATC_ERROR;
    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);

    if ((ATC_NULL != pState) && (EN_TRUE == b_avail))
    {
        *pState = g_State.Speed.State;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_GetSensorState*/
/* Brief:      获取传感器状态*/
/* Param:     SensorState_T * const pState  传感器状态*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_GetSensorState( SensorState_T * const pState )
{
    int32_t ret = ATC_ERROR;
    BOOL b_avail = (s_bInitDone & s_bMeasureDone & s_bVeloOK);

    if ((ATC_NULL != pState) && (EN_TRUE == b_avail))
    {
        pState->OPGStateA = g_OPG_A.Status;
        pState->OPGStateB = g_OPG_B.Status;
        pState->DRState = g_Radar.Status;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_DBG_GetErrorCode*/
/* Brief:      获取错误码*/
/* Param:     uint32_t * const pErrorCode  测速错误码*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_DBG_GetErrorCode(uint32_t * const pErrorCode)
{
    int32_t ret = ATC_ERROR;

    if ((ATC_NULL != pErrorCode) && (EN_TRUE == s_bInitDone))
    {
        *pErrorCode = s_uiErrorCode;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SPD_DBG_GetSPDInfo*/
/* Brief:      获取测速调试信息*/
/* Param:     SPDDbgInfo_T * pSPDDbgInfo  测速调试信息*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_DBG_GetSPDInfo( SPDDbgInfo_T *pSPDDbgInfo )
{
    int32_t ret = ATC_ERROR;

    if ((ATC_NULL != pSPDDbgInfo) && (EN_TRUE == s_bInitDone))
    {
        pSPDDbgInfo->Selected = g_State.Speed.Selected;
        pSPDDbgInfo->VoteRet = g_State.Vars.VoteRet;
        pSPDDbgInfo->State = g_State.Speed.State;
        pSPDDbgInfo->Status = g_State.Speed.Status;
        pSPDDbgInfo->iVoteFailTime = g_State.Vars.iVoteFailTime;
        pSPDDbgInfo->iSlideTime = g_State.Vars.iSlideTime;
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  DRInfoDebug*/
/* Brief:     雷达调试信息*/
/* Param:     DRDbgInfo_T * const pDRDbgInfo  雷达调试信息*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void DBG_DRInfoCollect(DRDbgInfo_T * const pDRDbgInfo)
{
    pDRDbgInfo->SensorState = g_Radar.Status;
    pDRDbgInfo->bDRMsgValid = g_Radar.Input.bMsgValid;
    pDRDbgInfo->bDRPulseValid = g_Radar.Input.bPulseValid;
    pDRDbgInfo->ucMsgNum = g_Radar.Input.ucMsgNum;
    pDRDbgInfo->bHighQuality = g_Radar.Vars.bHighQuality;
    pDRDbgInfo->Dir = g_Radar.Vars.Dir;
    pDRDbgInfo->bSerialFault = g_Radar.Vars.DRDebug.bSerialFault;
    pDRDbgInfo->bMoveDirNull = g_Radar.Vars.DRDebug.bMoveDirNull;
    pDRDbgInfo->ucStatusValidNum = g_Radar.Vars.DRDebug.ucStatusValidNum;
    pDRDbgInfo->ucSpeedValidNum = g_Radar.Vars.DRDebug.ucSpeedValidNum;
    pDRDbgInfo->ucDirValidNum = g_Radar.Vars.DRDebug.ucDirValidNum;
    pDRDbgInfo->uiMaxSpeed = g_Radar.Vars.DRDebug.uiMaxSpeed;
    pDRDbgInfo->uiMinSpeed = g_Radar.Vars.DRDebug.uiMinSpeed;
    pDRDbgInfo->iRawSpeed = g_Radar.SpdDist.iRawSpeed;
    pDRDbgInfo->iMaxSpeed = g_Radar.SpdDist.iMaxSpeed;
    pDRDbgInfo->iRawMov = g_Radar.SpdDist.iRawMov;
    pDRDbgInfo->iMaxMov = g_Radar.SpdDist.iMaxMov;
    pDRDbgInfo->iMinMov = g_Radar.SpdDist.iMinMov;
    pDRDbgInfo->iFiltedAccel = g_Radar.SpdDist.iFiltedAccel;
}

/*******************************************************************************/
/* Function:  SingleOPGDebug*/
/* Brief:      单个OPG调试信息*/
/* Param:     const OPG_T OPG  速度计信息*/
/* Param:     OPGDbgInfo_T * const pOPGDbgInfo  速度计调试信息*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void DBG_OPGInfoCollect(const OPG_T *pOPG, OPGDbgInfo_T * const pOPGDbgInfo)
{    
    pOPGDbgInfo->PulseDist.iMaxPulseDist = pOPG->OPGInput.iMaxPulseDist;
    pOPGDbgInfo->PulseDist.iMinPulseDist = pOPG->OPGInput.iMinPulseDist;
    pOPGDbgInfo->PulseDist.iRawPulseDist = pOPG->OPGInput.iRawPulseDist;
    pOPGDbgInfo->SensorState = pOPG->Status;
    pOPGDbgInfo->iPulseOneCycle = pOPG->Vars.iPulseOneCycle;
    pOPGDbgInfo->iMaxPulseOneCycle = pOPG->Vars.iMaxPulseOneCycle;
    pOPGDbgInfo->iMinPulseOneCycle = pOPG->Vars.iMinPulseOneCycle;
    pOPGDbgInfo->iMaxPulseFreq = pOPG->Vars.iMaxPulseFreq;
    pOPGDbgInfo->uiPulseCntCh0 = pOPG->Vars.uiPulseCnt0;
    pOPGDbgInfo->uiPulseCntCh1 = pOPG->Vars.uiPulseCnt1;
    pOPGDbgInfo->iRawSpeed = pOPG->SpdDist.iRawSpeed;
    pOPGDbgInfo->iMaxSpeed = pOPG->SpdDist.iMaxSpeed;
    pOPGDbgInfo->iRawMov = pOPG->SpdDist.iRawMov;
    pOPGDbgInfo->iMaxMov = pOPG->SpdDist.iMaxMov;
    pOPGDbgInfo->iMinMov = pOPG->SpdDist.iMinMov;
    pOPGDbgInfo->iFiltedAccel = pOPG->SpdDist.iFiltedAccel;  
}

/*******************************************************************************/
/* Function:  SPD_DBG_GetSSInfo*/
/* Brief:      获取传感器调试信息*/
/* Param:     SSDbgInfo_T * pSSDbgInfo  传感器调试信息*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t SPD_DBG_GetSSInfo( SSDbgInfo_T *pSSDbgInfo )
{
    int32_t ret = ATC_ERROR;

    if ((ATC_NULL != pSSDbgInfo) && (EN_TRUE == s_bInitDone))
    {
        DBG_OPGInfoCollect(&g_OPG_A, &(pSSDbgInfo->OPGDbgInfoA));
        DBG_OPGInfoCollect(&g_OPG_B, &(pSSDbgInfo->OPGDbgInfoB));
        DBG_DRInfoCollect(&(pSSDbgInfo->DRDbgInfo));
        ret = ATC_OK;
    }
    return ret;
}

