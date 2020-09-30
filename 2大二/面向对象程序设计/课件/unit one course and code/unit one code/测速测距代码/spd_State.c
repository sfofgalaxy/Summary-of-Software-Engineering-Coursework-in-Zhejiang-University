/** 
 * \brief     测速状态机
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_State.c
 * 
 * 测速状态机实现
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */

#include "Spd_State.h"

extern OPG_T     g_OPG_A;
extern OPG_T     g_OPG_B;
extern Radar_T     g_Radar;

State_T                 g_State;                    /*状态机信息*/
static StateParam_T     s_StateParam;               /*状态机配置参数*/
static uint32_t         s_uiErrorCode;              /*错误码*/

/*******************************************************************************/
/* Function:  SSCheckParam*/
/* Brief:      检测状态机配置参数*/
/* Param:     SPDParam_T * const pParam  配置参数*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static int32_t STCheckParam(const SPDParam_T * const pParam)
{
    int32_t ret = ATC_ERROR;
    if (ATC_NULL != pParam)
    {
        ret = ATC_OK;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  STLoadParam*/
/* Brief:      加载配置参数*/
/* Param:     SPDParam_T * const pParam  配置参数*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static int32_t STLoadParam(const SPDParam_T * const pParam)
{
    int32_t ret = ATC_ERROR;

    /*TODO check the param here!!!*/
    ret = STCheckParam(pParam);

    if (ATC_OK == ret)
    {
        s_StateParam.iCycleTime = pParam->iCycleTime;
        s_StateParam.iVoteSpareTime = pParam->iVoteSpareTime;
        s_StateParam.iVoteDeltaSpeed = pParam->iVoteDeltaSpeed;
        s_StateParam.iSlideAccel = pParam->iSlideAccel;
        s_StateParam.iSlipAccel = -s_StateParam.iSlideAccel;
        s_StateParam.iMaxSlideTime = pParam->iMaxSlideTime;
        if (0 == pParam->iBcnMissTime)
        {
            s_StateParam.iBcnMissCycle = 1;
        }
        else if (0 == (pParam->iBcnMissTime % s_StateParam.iCycleTime))
        {
            s_StateParam.iBcnMissCycle = pParam->iBcnMissTime / s_StateParam.iCycleTime;
        }
        else
        {
            s_StateParam.iBcnMissCycle = (pParam->iBcnMissTime / s_StateParam.iCycleTime) + 1;
        }
    }
    return ret;
}

/*******************************************************************************/
/* Function:  CalcDist2Bcn*/
/* Brief:     计算到信标的距离*/
/* Param:     int32_t MaxIndex  计算最大距离的索引*/
/* Param:     int32_t MinIndex  计算最小距离的索引*/
/* Param:     int32_t RawIndex  计算原始距离的索引*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
static void CalcDist2Bcn(int32_t MaxIndex, int32_t MinIndex, int32_t RawIndex)
{
    int32_t i = 0;
    /*到信标的最大距离*/
    /*计算锁存脉冲当周期的位移*/
    g_State.Dist2Bcn.iMaxOffset = g_State.Vars.RelocInfo[MaxIndex].iMaxSpeed 
        * Common_Delta_Unsign(g_State.BcnInfo.ulMinTimeStamp, g_State.Vars.RelocInfo[MaxIndex - 1].uiTimeStamp);
    /*累加锁存周期到当前周期的位移*/
    for (i = 0; i < MaxIndex; i++)
    {
        g_State.Dist2Bcn.iMaxOffset += g_State.Vars.RelocInfo[i].iMaxMov;
    }
    /*到信标的最小距离*/
    g_State.Dist2Bcn.iMinOffset = g_State.Vars.RelocInfo[MinIndex].iRawSpeed 
        * Common_Delta_Unsign(g_State.BcnInfo.ulMaxTimeStamp, g_State.Vars.RelocInfo[MinIndex - 1].uiTimeStamp);
    for (i = 0; i < MinIndex; i++)
    {
        g_State.Dist2Bcn.iMinOffset += g_State.Vars.RelocInfo[i].iMinMov;
    }
    /*到信标的原始距离——ATO使用，当锁存脉冲数不可重定位时，用时间戳*/
    if (EN_FALSE == g_State.Dist2Bcn.bReloc)
    {
        g_State.Dist2Bcn.iRawOffset = g_State.Vars.RelocInfo[RawIndex].iRawSpeed 
            * Common_Delta_Unsign(g_State.BcnInfo.ulRawTimeStamp, g_State.Vars.RelocInfo[RawIndex - 1].uiTimeStamp);
        for (i = 0; i < RawIndex; i++)
        {
            g_State.Dist2Bcn.iRawOffset += g_State.Vars.RelocInfo[i].iRawMov;
        }
        g_State.Dist2Bcn.bReloc = EN_TRUE;
    }
}

/*******************************************************************************/
/* Function:  FindCycleByTime*/
/* Brief:     根据时间戳找出周期索引*/
/* Param:     uint32_t uiTimeStamp  时间戳*/
/* Param:     BOOL bOverFlow  数组中是否发生了溢出卷绕*/
/* Param:     int32_t iBoundary  卷绕边界索引*/
/* Param:     int32_t * const iIndex  周期索引*/
/* RetVal:    int32_t 搜索成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
static int32_t FindCycleByTime(uint32_t uiTimeStamp, BOOL bOverFlow, int32_t iBoundary, int32_t * const iIndex)
{
    int32_t ret = EN_FALSE;
    int32_t i = 0;

    /*发生时间戳卷绕，且锁存时间刚好在卷绕的两个周期之间*/
    if ((EN_TRUE == bOverFlow) 
        && ((uiTimeStamp > g_State.Vars.RelocInfo[iBoundary + 1].uiTimeStamp) 
        || (uiTimeStamp <= g_State.Vars.RelocInfo[iBoundary].uiTimeStamp)))
    {
        *iIndex = iBoundary + 1;
        ret = EN_TRUE;
    }
    else
    {
        for (i = 0; i < (s_StateParam.iBcnMissCycle - 1); i++)
        {
            if ((uiTimeStamp <= g_State.Vars.RelocInfo[i].uiTimeStamp) && (uiTimeStamp > g_State.Vars.RelocInfo[i + 1].uiTimeStamp))
            {
                *iIndex = i + 1;
                ret = EN_TRUE;
            }
        }
    }
    return ret;
}

/*******************************************************************************/
/* Function:  CheckArrayOverFlow*/
/* Brief:     检查重定位信息结构体数组中的时间戳是否发生卷绕*/
/* Param:     int32_t * const iBoundary  卷绕边界索引*/
/* RetVal:    BOOL 发生卷绕则返回EN_TRUE，未卷绕返回EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
static BOOL CheckArrayOverFlow(int32_t * const iBoundary)
{
    BOOL ret = EN_FALSE;
    int32_t i = 0;
    BOOL break_flag = EN_FALSE;

    /*发现本周期时间戳比上周期小，则认为是溢出卷绕，将本周期索引设置为卷绕边界*/
    for (i = 0; i<((s_StateParam.iBcnMissCycle - 1) && (EN_TRUE != break_flag)); i++)
    {
        if (g_State.Vars.RelocInfo[i].uiTimeStamp < g_State.Vars.RelocInfo[i + 1].uiTimeStamp)
        {
            ret = EN_TRUE;
            break_flag = EN_TRUE;
            *iBoundary = i;
        }
    }
    return ret;
}

/*******************************************************************************/
/* Function:  RelocInfoFIFOWrite*/
/* Brief:     将重定位信息加入数组*/
/* Param:     const RelocInfo_T Data  本周期重定位信息*/
/* Param:     int32_t iSize  数组大小*/
/* Param:     RelocInfo_T FIFO[]  重定位信息数组*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
static void RelocInfoFIFOWrite(const RelocInfo_T Data, int32_t iSize, RelocInfo_T FIFO[] )
{
    /*initial the variable point the end member of the array*/
    int32_t    index = iSize - 1; 
    /*shift the member in the array by one and clear the first member of the memory*/
    for (; index > 0; index--)
    {
        FIFO[index] = FIFO[index-1];
    }
    /*push the new member into the array*/
    FIFO[index] = Data;
}

/*******************************************************************************/
/* Function:  STCalcDist2Bcn*/
/* Brief:     计算到信标的距离*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
static void STRelocProcess(void)
{
    int32_t raw_index = 0;
    int32_t max_index = 0;
    int32_t min_index = 0;
    int32_t ret_max = ATC_ERROR;
    int32_t ret_min = ATC_ERROR;
    int32_t ret_raw = ATC_ERROR;
    BOOL bOverflow = EN_FALSE;
    int32_t iBoundary = 0;
    RelocInfo_T reloc = {0, 0, 0, 0, 0, 0};

    /*将本周期的重定位信息加入数组*/
    reloc.uiTimeStamp = g_State.uiTimeStamp;
    reloc.iMaxSpeed = g_State.Speed.iMaxSpeed;
    reloc.iRawSpeed = g_State.Speed.iRawSpeed;
    reloc.iMaxMov = g_State.Speed.iMaxMov;
    reloc.iMinMov = g_State.Speed.iMinMov;
    reloc.iRawMov = g_State.Speed.iRawMov;
    RelocInfoFIFOWrite(reloc, s_StateParam.iBcnMissCycle, g_State.Vars.RelocInfo);

    /*读到新信标，则进行重定位*/
    if (EN_TRUE == g_State.BcnInfo.bBcnRead)
    {
        bOverflow = CheckArrayOverFlow(&iBoundary);
        ret_raw = FindCycleByTime(g_State.BcnInfo.ulRawTimeStamp, bOverflow, iBoundary, &raw_index);
        ret_max = FindCycleByTime(g_State.BcnInfo.ulMaxTimeStamp, bOverflow, iBoundary, &max_index);
        ret_min = FindCycleByTime(g_State.BcnInfo.ulMinTimeStamp, bOverflow, iBoundary, &min_index);

        if ((ATC_OK == ret_raw) && (ATC_OK == ret_max) && (ATC_OK == ret_min))
        {
            CalcDist2Bcn(max_index, min_index, raw_index);
        }
        else
        {
            g_State.Dist2Bcn.bReloc = EN_FALSE;
            g_State.Dist2Bcn.iMaxOffset = 0;
            g_State.Dist2Bcn.iMinOffset = 0;
            g_State.Dist2Bcn.iRawOffset = 0;
        }
    }
}

/*******************************************************************************/
/* Function:  StateDebugProcess*/
/* Brief:      状态机调试信息*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void STDebugProcess(void)
{
    int32_t i = 0;

    g_State.Vars.iVoteFailTime = 0;
    for (i = 0; i < VOTE_NUM; i++)
    {
        /*同时只可能有一个速度计有表决不通过时间计数*/
        if (0 != g_State.Vars.VoteAst[i].iFailTime)
        {
            g_State.Vars.iVoteFailTime = g_State.Vars.VoteAst[i].iFailTime;
        }
    }
}

/*******************************************************************************/
/* Function:  STUpdateOutput*/
/* Brief:      从传感器信息中获取速度位移*/
/* Param:     SensorOutput_T SensorOutput  传感器信息*/
/* Param:     Speed_T * const pSpeed  测速测距输出信息*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void STUpdateOutput(SensorOutput_T SensorOutput, Speed_T * const pSpeed)
{
    pSpeed->iMaxMov = SensorOutput.iMaxMov;
    pSpeed->iMinMov = SensorOutput.iMinMov;
    pSpeed->iRawMov = SensorOutput.iRawMov;
    pSpeed->iRawSpeed = SensorOutput.iRawSpeed;
    pSpeed->iMaxSpeed = SensorOutput.iMaxSpeed;
    pSpeed->iAccel = SensorOutput.iFiltedAccel;
}

/*******************************************************************************/
/* Function:  VotePrepare*/
/* Brief:      表决数据准备*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void VotePrepare(void)
{
    int32_t i = 0;

    g_State.Vars.VoteAst[0].Status = g_OPG_A.Status;
    g_State.Vars.VoteAst[0].iSpeed = g_OPG_A.SpdDist.iMaxSpeed;
    g_State.Vars.VoteAst[0].Sensor = SST_OPGA;
    g_State.Vars.VoteAst[0].iWeight = 0;

    g_State.Vars.VoteAst[1].Status = g_OPG_B.Status;
    g_State.Vars.VoteAst[1].iSpeed = g_OPG_B.SpdDist.iMaxSpeed;
    g_State.Vars.VoteAst[1].Sensor = SST_OPGB;
    g_State.Vars.VoteAst[1].iWeight = 0;

    g_State.Vars.VoteAst[2].Status = g_Radar.Status;
    g_State.Vars.VoteAst[2].iSpeed = g_Radar.SpdDist.iMaxSpeed;
    g_State.Vars.VoteAst[2].Sensor = SST_DR;
    g_State.Vars.VoteAst[2].iWeight = 0;

    /*将已经超时的传感器置成故障*/
    for (i = 0; i < VOTE_NUM; i++)
    {
        if (g_State.Vars.VoteAst[i].iFailTime > s_StateParam.iVoteSpareTime)
        {
            g_State.Vars.VoteAst[i].Status = SS_FAULT;
            g_State.Vars.VoteAst[i].iFailTime = 0;
        }
    }
}


/*******************************************************************************/
/* Function:  VoteEqual*/
/* Brief:      表决时判断两个值是否一致*/
/* Param:     Vote_T Vote1  表决值1*/
/* Param:     Vote_T Vote2  表决值2*/
/* RetVal:    BOOL  一致返回EN_TRUE，不一致返回EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static BOOL VoteEqual(Vote_T Vote1, Vote_T Vote2)
{
    BOOL ret = EN_FALSE;

    /*两者状态均为OK，且速度相差小于等于允许误差的一半，这样可以保证表决通过的任意两个数据之差不大于允许误差*/
    if ((SS_OK == Vote1.Status) && (SS_OK == Vote2.Status)
        && (Common_ABS(Vote1.iSpeed - Vote2.iSpeed) <= (s_StateParam.iVoteDeltaSpeed / 2)))
    {
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  VoteProcess*/
/* Brief:      传感器表决*/
/* Param:     Vote_T VoteAst[]  表决数组*/
/* Param:     int32_t count  表决个数*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void VoteProcess(Vote_T VoteAst[], int32_t count)
{
    int32_t i = 0;
    int32_t j = 0;
    int32_t count_all = 0;

    /*情况1：三个全部相同            - 通过*/
    /*情况2：两个相同，另一个不同    - 通过*/
    /*情况3：三个都不相同            - 挂*/

    /*遍历表决数组，遇到两两一致的，计数各加一*/
    for (i = 0; i < (count - 1); i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (EN_TRUE == VoteEqual(VoteAst[i], VoteAst[j]))
            {
                VoteAst[i].iWeight++;
                VoteAst[j].iWeight++;
            }
        }
    }

    for (i = 0; i < count; i++)
    {
        /*有效计数为0的项目，设置成不可用状态*/
        if ( 0 == VoteAst[i].iWeight)
        {
            if (SS_FAULT != VoteAst[i].Status)
            {
                VoteAst[i].Status = SS_UNAVAIL;
                VoteAst[i].iFailTime += s_StateParam.iCycleTime;
            }
        }
        /*统计OK的项目个数,并将OK的表决不通过时间清零*/
        if (SS_OK == VoteAst[i].Status)
        {
            count_all++;
            VoteAst[i].iFailTime = 0;
        }
    }
    /*根据OK的项目个数统计表决结果*/
    if (VOTE_3 == count_all)
    {
        g_State.Vars.VoteRet = VOTE_PASS3;
    }
    else if (VOTE_2 == count_all)
    {
        g_State.Vars.VoteRet = VOTE_PASS2;
    }
    else
    {
        g_State.Vars.VoteRet = VOTE_FAIL;
        for (i = 0; i < VOTE_NUM; i++)
        {
            VoteAst[i].Status = SS_FAULT;
            VoteAst[i].iFailTime = 0;
        }
    }
}

/*******************************************************************************/
/* Function:  CheckSlipSlide*/
/* Brief:      检查空转打滑*/
/* Param:     void  */
/* RetVal:    BOOL  有空转打滑返回EN_TRUE，惰行返回EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL CheckSlipSlide( void )
{
    BOOL ret = EN_FALSE;

    g_State.Speed.Status = WS_COAST;

    /*任一速度计打滑即判定为打滑,产生空转则设置OPG故障*/
    if (SS_OK == g_OPG_A.Status) 
    {
        if (g_OPG_A.SpdDist.iFiltedAccel < s_StateParam.iSlideAccel)
        {
            g_State.Speed.Status = WS_SLIDE;
            ret = EN_TRUE;        
        }
        else if (g_OPG_A.SpdDist.iFiltedAccel > s_StateParam.iSlipAccel)
        {
            g_OPG_A.Status = SS_FAULT;
        }
        else
        {
            NOP;
        }
    }
    if (SS_OK == g_OPG_B.Status)
    {
        if (g_OPG_B.SpdDist.iFiltedAccel < s_StateParam.iSlideAccel)
        {
            g_State.Speed.Status = WS_SLIDE;
            ret = EN_TRUE;        
        }
        else if (g_OPG_B.SpdDist.iFiltedAccel > s_StateParam.iSlipAccel)
        {
            g_OPG_B.Status = SS_FAULT;
        }
        else
        {
            NOP;
        }
    }
    return ret;
}

/*******************************************************************************/
/* Function:  UpdateSSState*/
/* Brief:     更新传感器状态*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/9*/
/*******************************************************************************/
static void UpdateSSState(void)
{
    g_OPG_A.Status = g_State.Vars.VoteAst[0].Status;
    g_OPG_B.Status = g_State.Vars.VoteAst[1].Status;
    g_Radar.Status = g_State.Vars.VoteAst[2].Status;
}

/*******************************************************************************/
/* Function:  COAST_Entry*/
/* Brief:      COAST状态初始化*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void COAST_Entry( void )
{
    int32_t num = 0;
    for (num = 0; num < VOTE_NUM; num++)
    {
        g_State.Vars.VoteAst[num].iFailTime = 0;
    }
    g_State.Speed.State = VS_COAST;    
    g_State.Vars.iCoastTime = 0;
}
/*******************************************************************************/
/* Function:  COAST_Duration*/
/* Brief:     惰行状态的过程处理*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void COAST_Duration(void)
{
    /*计算是否可用速度计锁存值进行重定位-For ATO*/
    g_State.Vars.iCoastTime += s_StateParam.iCycleTime;
    if (g_State.Vars.iCoastTime > COAST_TIME_TO_RELOC)
    {
        g_State.Vars.iCoastTime = COAST_TIME_TO_RELOC;
        g_State.Vars.bReloc = EN_TRUE;
    }
    /*若OPGA可用，使用OPGA的数据作为安全速度*/
    if (SS_OK == g_OPG_A.Status)
    {
        STUpdateOutput(g_OPG_A.SpdDist, &g_State.Speed);
        g_State.Speed.Selected = SST_OPGA;
        if ((EN_TRUE == g_OPG_A.BcnFrozenData.bBcnRead) && (EN_TRUE == g_State.Vars.bReloc))
        {
            g_State.Dist2Bcn.bRead = EN_TRUE;
            g_State.Dist2Bcn.bReloc = EN_TRUE;
            //g_State.Dist2Bcn.iMaxOffset = g_OPG_A.Dist2Bcn.iMaxOffset;
            //g_State.Dist2Bcn.iMinOffset = g_OPG_A.Dist2Bcn.iMinOffset;
            g_State.Dist2Bcn.iRawOffset = g_OPG_A.Dist2Bcn.iRawOffset;
        }
    }
    /*否则使用OPGB（惰行时如果A不可用，则B必可用）*/
    else
    {
        STUpdateOutput(g_OPG_B.SpdDist, &g_State.Speed);
        g_State.Speed.Selected = SST_OPGB;
        if ((EN_TRUE == g_OPG_B.BcnFrozenData.bBcnRead) && (EN_TRUE == g_State.Vars.bReloc))
        {
            g_State.Dist2Bcn.bRead = EN_TRUE;
            g_State.Dist2Bcn.bReloc = EN_TRUE;
            //g_State.Dist2Bcn.iMaxOffset = g_OPG_B.Dist2Bcn.iMaxOffset;
            //g_State.Dist2Bcn.iMinOffset = g_OPG_B.Dist2Bcn.iMinOffset;
            g_State.Dist2Bcn.iRawOffset = g_OPG_B.Dist2Bcn.iRawOffset;
        }
    }
    g_State.Speed.Status = WS_COAST;
    g_State.Speed.State = VS_COAST;
}
/*******************************************************************************/
/* Function:  COAST_2_SLIDE*/
/* Brief:     惰行到打滑状态的转换判断*/
/* Param:     void  */
/* RetVal:    BOOL 进入打滑状态返回EN_TRUE，否则返回EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL COAST_2_SLIDE(void)
{
    BOOL ret = EN_FALSE;

    /*发生打滑，且雷达可用*/
    if ((WS_SLIDE == g_State.Speed.Status) && (SS_OK == g_Radar.Status))
    {
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  COAST_2_FAULT*/
/* Brief:     惰行到故障状态的转换*/
/* Param:     void  */
/* RetVal:    BOOL  进入故障状态返回EN_TRUE，否则返回EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL COAST_2_FAULT( void )
{
    BOOL ret = EN_FALSE;
    /*打滑且雷达故障*/
    if ((WS_SLIDE == g_State.Speed.Status) && (SS_OK != g_Radar.Status))
    {
        ret = EN_TRUE;
    }
    /*表决失败*/
    if (VOTE_FAIL == g_State.Vars.VoteRet)
    {
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  FAULT_Duration*/
/* Brief:     故障状态过程处理*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void FAULT_Duration(void)
{
    /*全部置成故障状态*/
    g_OPG_A.Status = SS_FAULT;
    g_OPG_B.Status = SS_FAULT;
    g_Radar.Status = SS_FAULT;

    g_State.Speed.iMaxMov = MAX_THEORY_MOV;
    g_State.Speed.iMinMov = MIN_THEORY_MOV;
    g_State.Speed.iRawMov = MAX_THEORY_MOV;
    g_State.Speed.iRawSpeed = MAX_THEORY_SPEED;
    g_State.Speed.iMaxSpeed = MAX_THEORY_SPEED;
    g_State.Speed.iAccel = 0;
    g_State.Speed.Selected = SST_NULL;
    g_State.Speed.State = VS_FAULT;
}

/*******************************************************************************/
/* Function:  CheckOPGRecover*/
/* Brief:     检查故障的OPG是否可以恢复*/
/* Param:     void  */
/* RetVal:    BOOL  可恢复返回EN_TRUE，否则返回EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL CheckOPGRecover( OPG_T * pOPG )
{
    BOOL ret = EN_FALSE;

    /*雷达状态可用，且速度计未故障，则判断是否可恢复*/
    if ((SS_OK == g_Radar.Status) && (SS_FAULT != pOPG->Status))
    {
        /*速度计与雷达速度差小于等于允许误差，则认为可恢复*/
        if (Common_ABS(pOPG->SpdDist.iMaxSpeed - g_Radar.SpdDist.iMaxSpeed) <= s_StateParam.iVoteDeltaSpeed)
        {
            ret = EN_TRUE;
            pOPG->Status = SS_OK;
        }
        /*不能恢复的速度计设置成故障状态*/
        else
        {
            pOPG->Status = SS_FAULT;
        }
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SLIDE_Entry*/
/* Brief:     打滑状态初始化*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void SLIDE_Entry( void )
{
    g_State.Speed.State = VS_SLIDE;
    g_State.Vars.iSlideTime = 0;
    g_State.Vars.iCoastTime = 0;
}
/*******************************************************************************/
/* Function:  SLIDE_Duration*/
/* Brief:     打滑状态过程处理*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void SLIDE_Duration(void)
{
    /*累加打滑时间*/
    g_State.Vars.iSlideTime += s_StateParam.iCycleTime;

    /*将未故障的OPG设置成不可用*/
    if (SS_FAULT != g_OPG_A.Status)
    {
        g_OPG_A.Status = SS_UNAVAIL;
    }
    if (SS_FAULT != g_OPG_B.Status)
    {
        g_OPG_B.Status = SS_UNAVAIL;
    }

    /*使用雷达数据作为安全速度*/
    STUpdateOutput(g_Radar.SpdDist, &g_State.Speed);
    g_State.Speed.Status = WS_SLIDE;
    g_State.Speed.State = VS_SLIDE;
    g_State.Speed.Selected = SST_DR;
}

/*******************************************************************************/
/* Function:  SLIDE_2_FAULT*/
/* Brief:     打滑到故障状态的转换*/
/* Param:     void  */
/* RetVal:    BOOL  进入故障状态返回EN_TRUE，否则返回EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL SLIDE_2_FAULT(void)
{
    BOOL ret = EN_FALSE;

    /*雷达不可用，或打滑超时速度计未恢复*/
    if ((SS_OK != g_Radar.Status) || ((g_State.Vars.iSlideTime >= s_StateParam.iMaxSlideTime) && (EN_TRUE != g_State.Vars.bOPGRecover)))
    {    
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SLIDE_2_COAST*/
/* Brief:     打滑到惰行的状态转换*/
/* Param:     void  */
/* RetVal:    BOOL  进入惰行状态返回EN_TRUE，否则返回EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL SLIDE_2_COAST(void)
{
    BOOL ret = EN_FALSE;

    /*打滑的速度计恢复*/
    if ((EN_TRUE == g_State.Vars.bOPGRecover))
    {
        ret = EN_TRUE;
    }
    return ret;
}


/*******************************************************************************/
/* Function:  SLIDE_PROCESS*/
/* Brief:     打滑状态调度*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void  SLIDE_PROCESS(void)
{
    BOOL bRecoverA = EN_FALSE;
    BOOL bRecoverB = EN_FALSE;
    /*检测最大打滑时间过后，打滑的速度计是否恢复*/
    if (g_State.Vars.iSlideTime >= s_StateParam.iMaxSlideTime)
    {
        bRecoverA = CheckOPGRecover(&g_OPG_A);
        bRecoverB = CheckOPGRecover(&g_OPG_B);
        if ((EN_TRUE == bRecoverA) || (EN_TRUE == bRecoverB))
        {
            g_State.Vars.bOPGRecover = EN_TRUE;
        }
    }

    /*进入故障状态判断*/
    if ((EN_TRUE == SLIDE_2_FAULT()))
    {
        g_State.Speed.State = VS_FAULT;
        FAULT_Duration();
    }
    /*进入惰行状态判断*/
    else if (EN_TRUE == SLIDE_2_COAST())
    {
        COAST_Entry();
        COAST_Duration();
    }
    /*维持打滑状态*/
    else
    {
        SLIDE_Duration();
    }
}

/*******************************************************************************/
/* Function:  COAST_PROCESS*/
/* Brief:     惰行状态调度*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void  COAST_PROCESS(void)
{
    /*检测空转打滑*/
    (void)CheckSlipSlide();

    /*未打滑时进行三取二表决*/
    if (WS_COAST == g_State.Speed.Status)
    {
        /*传感器数据转换为表决结构体*/
        VotePrepare();
        /*表决*/
        VoteProcess(g_State.Vars.VoteAst, VOTE_NUM);
        /*表决结果更新到传感器信息结构体*/
        UpdateSSState();
    }
    else
    {
        /*打滑无需表决*/
        g_State.Vars.VoteRet = VOTE_NULL;
    }

    /*进入故障状态判断*/
    if (EN_TRUE == COAST_2_FAULT())
    {
        g_State.Speed.State = VS_FAULT;
        g_State.Vars.iCoastTime = 0;
        FAULT_Duration();
    }
    /*进入打滑状态判断*/
    else if (EN_TRUE == COAST_2_SLIDE())
    {
        SLIDE_Entry();
        SLIDE_Duration();
    }
    /*维持惰行*/
    else
    {
        COAST_Duration();
    }
}

/*******************************************************************************/
/* Function:  FAULT_PROCESS*/
/* Brief:     故障状态调度*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void FAULT_PROCESS(void)
{
    FAULT_Duration();
}

/*******************************************************************************/
/* Function:  State_Init*/
/* Brief:      初始化*/
/* Param:     SPDParam_T * const pParam  配置参数*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t State_Init( const SPDParam_T * const pParam )
{ 
    int32_t ret = ATC_ERROR;
    int32_t num = 0;

    g_State.Vars.iSlideTime = 0;

    ret = STLoadParam(pParam);

    for (num = 0; num < RELOC_INFO_MAX_CYCLE; num++)
    {
        g_State.Vars.RelocInfo[num].uiTimeStamp = 0;
        g_State.Vars.RelocInfo[num].iMaxSpeed = 0;
        g_State.Vars.RelocInfo[num].iRawSpeed = 0;
        g_State.Vars.RelocInfo[num].iMaxMov = 0;
        g_State.Vars.RelocInfo[num].iMinMov = 0;
        g_State.Vars.RelocInfo[num].iRawMov = 0;
    }
    for (num = 0; num < VOTE_NUM; num++)
    {
        g_State.Vars.VoteAst[num].iFailTime = 0;
    }
    g_State.Speed.State = VS_COAST;    
    g_State.Vars.iCoastTime = COAST_TIME_TO_RELOC;
    
    return ret;
}

/*******************************************************************************/
/* Function:  State_LoadInput*/
/* Brief:     状态机输入数据加载*/
/* Param:     SPDInput_T * const pSPDInput  状态机输入数据*/
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
int32_t State_LoadInput( SPDInput_T * const pSPDInput)
{
    int32_t ret = ATC_ERROR;

    g_State.uiTimeStamp = pSPDInput->uiTimeStamp;
    g_State.BcnInfo.bBcnRead = pSPDInput->BcnData.bBcnRead;
    g_State.BcnInfo.ulRawTimeStamp = pSPDInput->BcnData.ulTimeStamp;
    g_State.BcnInfo.ulMaxTimeStamp = g_State.BcnInfo.ulRawTimeStamp + pSPDInput->BcnData.ulTimeStampTol;
    g_State.BcnInfo.ulMinTimeStamp = g_State.BcnInfo.ulRawTimeStamp - pSPDInput->BcnData.ulTimeStampTol;

    ret = ATC_OK;
    return ret;
}

/*******************************************************************************/
/* Function:  State_Process*/
/* Brief:      状态机入口*/
/* Param:     void  */
/* RetVal:    int32_t  成功返回ATC_OK，失败返回ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t State_Process(void)
{
    int32_t ret = ATC_OK;

    /* check which state to in*/
    switch (g_State.Vars.Status)
    {
    case VS_COAST:
        {
            COAST_PROCESS();
            break;
        }
    case VS_SLIDE:
        {
            SLIDE_PROCESS();
            break;
        }
    case VS_FAULT:
        {
            FAULT_PROCESS();
            break;
        }
    default:
        {
            break;
        }                
    }
    if (VS_FAULT == g_State.Vars.Status)
    {
        ret = ATC_ERROR;
    }
    else
    {
        STRelocProcess();
    }

    STDebugProcess();

    return ret;
}
/*******************************************************************************/
/* Function:  State_ResetVars*/
/* Brief:      重置周期数据*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
void State_ResetVars(void)
{
    int32_t num = 0;

    for (num = 0; num < VOTE_NUM; num++)
    {
        g_State.Vars.VoteAst[num].iWeight = 0;
        g_State.Vars.VoteAst[num].iSpeed = 0;
        g_State.Vars.VoteAst[num].Status = SS_FAULT;
        g_State.Vars.VoteAst[num].Sensor = SST_NULL;
    }
    g_State.Vars.bOPGRecover = EN_FALSE;
    g_State.Vars.VoteRet = VOTE_FAIL;
    g_State.Vars.bReloc = EN_FALSE;
    g_State.uiTimeStamp = 0U;

    Common_Memset(&g_State.BcnInfo, 0, sizeof(BcnInfo_T));
    Common_Memset(&g_State.Dist2Bcn, 0, sizeof(DistToBcn_T));
    Common_Memset(&g_State.Speed, 0, sizeof(Speed_T));

    s_uiErrorCode = 0U;
}


/*******************************************************************************/
/* Function:  State_ResetOutput*/
/* Brief:      重置输出数据*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
void State_ResetOutput( void )
{
    Common_Memset(&g_State.Dist2Bcn, 0, sizeof(DistToBcn_T));
    
    g_OPG_A.Status = SS_FAULT;
    g_OPG_B.Status = SS_FAULT;
    g_Radar.Status = SS_FAULT;

    g_State.Speed.iMaxMov = MAX_THEORY_MOV;
    g_State.Speed.iMinMov = MIN_THEORY_MOV;
    g_State.Speed.iRawMov = MAX_THEORY_MOV;
    g_State.Speed.iRawSpeed = MAX_THEORY_SPEED;
    g_State.Speed.iMaxSpeed = MAX_THEORY_SPEED;
    g_State.Speed.iAccel = 0;
    g_State.Speed.Selected = SST_NULL;
    g_State.Speed.State = VS_FAULT;
}

