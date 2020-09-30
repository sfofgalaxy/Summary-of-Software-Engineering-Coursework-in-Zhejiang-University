/** 
 * \brief     �ٶȼ����״���Ϣ����
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_Sensor.c
 * 
 * �ٶȼ����״﹦��ʵ��
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */

#include "Spd_Sensor.h"
#include "Spd_base.h"

OPG_T     g_OPG_A;      /*�ٶȼ�A��Ϣ*/
OPG_T     g_OPG_B;      /*�ٶȼ�B��Ϣ*/
Radar_T   g_Radar;      /*�״���Ϣ*/
static SS_PARAM_T s_SSParam;    /*���������ò���*/
static int32_t s_uiErrorCode;   /*������*/
/* Function name rules */
/* for out : Sensor_XXX*/
/* for internal: SSXXX*/
/* for Radar DRXXX*/
/* for OPG   OPGXXXX*/
/*******************************************************************************/
/* Function:  OPGResetVars*/
/* Brief:      �ٶȼ�������������*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void OPGResetVars(void)
{
    /*ATPData ����*/
    Common_Memset(&g_OPG_A.OPGInput, 0, sizeof(OPGRawData_T));
    Common_Memset(&g_OPG_B.OPGInput, 0, sizeof(OPGRawData_T));
    Common_Memset(&g_OPG_A.BcnFrozenData, 0, sizeof(BcnFrozonData_T));
    Common_Memset(&g_OPG_B.BcnFrozenData, 0, sizeof(BcnFrozonData_T));

    /*�ǲ�������*/
    g_OPG_A.iSign = 0;
    g_OPG_A.Vars.iMaxPulseOneCycle = 0;
    g_OPG_A.Vars.iMinPulseOneCycle = 0;
    g_OPG_A.Vars.iPulseOneCycle = 0;
    g_OPG_A.Vars.iMaxPulseFreq = 0;
    g_OPG_A.Vars.uiPulseCnt0 = 0U;
    g_OPG_A.Vars.uiPulseCnt1 = 0U;

    g_OPG_B.iSign = 0;
    g_OPG_B.Vars.iMaxPulseOneCycle = 0;
    g_OPG_B.Vars.iMinPulseOneCycle = 0;
    g_OPG_B.Vars.iPulseOneCycle = 0;
    g_OPG_B.Vars.iMaxPulseFreq = 0;
    g_OPG_B.Vars.uiPulseCnt0 = 0U;
    g_OPG_B.Vars.uiPulseCnt1 = 0U;
    
    /*��ͬ�������*/
    Common_Memset(&g_OPG_A.Dist2Bcn, 0, sizeof(DistToBcn_T));
    Common_Memset(&g_OPG_A.SpdDist, 0, sizeof(SensorOutput_T));
    Common_Memset(&g_OPG_B.Dist2Bcn, 0, sizeof(DistToBcn_T));
    Common_Memset(&g_OPG_B.SpdDist, 0, sizeof(SensorOutput_T));
    s_uiErrorCode = 0;
}

/*******************************************************************************/
/* Function:  OPGSetPolarity*/
/* Brief:      �����ٶȼƼ���*/
/* Param:     Sensor_E SType  �ٶȼ�����*/
/* Param:     SPDPolarity_E Polarity  ����*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void OPGSetPolarity(Sensor_E SType,SPDPolarity_E Polarity)
{
    /*TODO check the input, and do some process(such as the sign) for sensor_process.*/
    /*if there are some vars need to be stored,please put into the pOPG->Vars struct.*/
    if (SST_OPGA == SType)
    {
        g_OPG_A.iSign = SIGN_PLUS;
        if (SPD_REV == Polarity)
        {
            g_OPG_A.iSign = SIGN_MINUS;
        }
    }
    else if (SST_OPGB == SType)
    {
        g_OPG_B.iSign = SIGN_MINUS;
        if (SPD_REV == Polarity)
        {
            g_OPG_B.iSign = SIGN_PLUS;
        }
    }
    else
    {
        NOP;
    }
}

/*******************************************************************************/
/* Function:  OPGCheckFreq*/
/* Brief:     ��������Ƶ���Ƿ����Ҫ��*/
/* Param:     OPG_T * pOPG  �ٶȼ���Ϣ*/
/* RetVal:    BOOL  ���ͨ������EN_TRUE����ͨ������EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/17*/
/*******************************************************************************/
static BOOL OPGCheckFreq(OPG_T *pOPG)
{
    BOOL ret = EN_FALSE;

    /*�ٶȼ�����ͨ����Ƶ��һ��һ��������ͨ����ֵ���ϴ�*/
    if ((pOPG->OPGInput.iPulseFreq0 > 0) && (pOPG->OPGInput.iPulseFreq1 < 0)
        || (pOPG->OPGInput.iPulseFreq0 < 0) && (pOPG->OPGInput.iPulseFreq1 > 0))
    {
        if (Common_ABS(pOPG->OPGInput.iPulseFreq0 - pOPG->OPGInput.iPulseFreq1) > OPG_DELTA_FREQ_BETWEEN_2CH) 
        {
            pOPG->Status = SS_UNAVAIL;
        }
        else
        {
            ret = EN_TRUE;
        }
    }
    else
    {
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  OPGCheckInput*/
/* Brief:      ����ٶȼ�����Ϸ���*/
/* Param:     OPG_T * pOPG  �ٶȼ���Ϣ*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void OPGCheckInput(OPG_T *pOPG)
{
    /*TODO other check ,such as the scope of the input values in "pOPG->OPGInput"*/
    if ((EN_TRUE != pOPG->OPGInput.bRead) || (EN_TRUE != pOPG->OPGInput.bValid))
    {
        pOPG->Status = SS_FAULT;
    }
    else
    {
        if (EN_TRUE == OPGCheckFreq(pOPG))
        {
            pOPG->Status = SS_OK;
        }
        else
        {
            pOPG->Status = SS_UNAVAIL;
        }
    }
}

/*******************************************************************************/
/* Function:  OPGCheckPulse*/
/* Brief:     �������仯�Ƿ����*/
/* Param:     const uint32_t uiPulse1 �仯ǰ��������*/
/* Param:     const uint32_t uiPulse2 �仯���������*/
/* Param:     const int32_t iTolerance ������������仯��*/
/* RetVal:    BOOL ����仯��������EN_TRUE����������EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/12*/
/*******************************************************************************/
static BOOL OPGCheckPulse(const uint32_t uiPulse1, const uint32_t uiPulse2, const int32_t iTolerance)
{
    BOOL ret = EN_FALSE;
    if (Common_ABS(Common_Delta_Sign(uiPulse1, uiPulse2)) <= iTolerance)
    {
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  OPGCalcPulseCnt*/
/* Brief:      �����ٶȼ�����仯��*/
/* Param:     OPG_T * pOPG  �ٶȼ���Ϣ*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void OPGCalcPulseCnt(OPG_T *pOPG)
{
    int32_t  ss_pulse_count_1 = 0;                    /*pulse count per cycle channel 1*/
    int32_t  ss_pulse_count_2 = 0;                    /*pulse count per cycle channel 2*/
    BOOL    pulse_count_ret_1 = EN_FALSE;
    BOOL    pulse_count_ret_2 = EN_FALSE;
    BOOL    pulse_count_ret_3 = EN_FALSE;

    if (EN_TRUE == pOPG->Vars.bFirstCycle)
    {
        pOPG->Vars.uiPulseCnt0 = pOPG->OPGInput.uiPulseCnt0;
        pOPG->Vars.uiPulseCnt1 = pOPG->OPGInput.uiPulseCnt1;
        pOPG->Vars.iMaxPulseOneCycle = 0;
        pOPG->Vars.iMinPulseOneCycle = 0;
        pOPG->Vars.iPulseOneCycle = 0;
        /*���³�ʼ����־*/
        pOPG->Vars.bFirstCycle = EN_FALSE;
    }
    else
    {
        /*calc the raw,max and min pulse count*/
        /*�������仯�Ƿ����*/
        pulse_count_ret_1 = OPGCheckPulse(pOPG->Vars.PreOPGInput.uiPulseCnt0, pOPG->OPGInput.uiPulseCnt0, MAX_DELTA_PULSE_CNT);
        pulse_count_ret_2 = OPGCheckPulse(pOPG->Vars.PreOPGInput.uiPulseCnt0, pOPG->OPGInput.uiPulseCnt0, MAX_DELTA_PULSE_CNT);
        pulse_count_ret_3 = OPGCheckPulse(pOPG->Vars.PreOPGInput.uiPulseCnt1, pOPG->OPGInput.uiPulseCnt1, MAX_DELTA_PULSE_CNT);
        if ((EN_TRUE == pulse_count_ret_1) && (EN_TRUE == pulse_count_ret_2) && (EN_TRUE == pulse_count_ret_3))
        {
            pOPG->Vars.iPulseOneCycle = pOPG->iSign * Common_Delta_Sign(pOPG->Vars.PreOPGInput.uiPulseCnt0, pOPG->OPGInput.uiPulseCnt0);
            ss_pulse_count_1 = pOPG->iSign * Common_Delta_Sign(pOPG->Vars.PreOPGInput.uiPulseCnt0, pOPG->OPGInput.uiPulseCnt0);
            ss_pulse_count_2 = pOPG->iSign * Common_Delta_Sign(pOPG->Vars.PreOPGInput.uiPulseCnt1, pOPG->OPGInput.uiPulseCnt1);

            /*if the channel 1 is bigger than channel 2*/
            if (ss_pulse_count_1 >= ss_pulse_count_2)
            {
                pOPG->Vars.iMaxPulseOneCycle = ss_pulse_count_1;
                pOPG->Vars.iMinPulseOneCycle = ss_pulse_count_2;
            }
            /*if the channel 2 is bigger than channel 1*/
            else
            {
                pOPG->Vars.iMaxPulseOneCycle = ss_pulse_count_2;
                pOPG->Vars.iMinPulseOneCycle = ss_pulse_count_1;
            }
        }
        else
        {
            pOPG->Status = SS_UNAVAIL;
            pOPG->Vars.iPulseOneCycle = 0;
            pOPG->Vars.iMaxPulseOneCycle = 0;
            pOPG->Vars.iMinPulseOneCycle = 0;
        }
        /*�����ۼ�����ֵ*/
        pOPG->Vars.uiPulseCnt0 = pOPG->OPGInput.uiPulseCnt0;
        pOPG->Vars.uiPulseCnt1 = pOPG->OPGInput.uiPulseCnt1;
    }
}

/*******************************************************************************/
/* Function:  OPGCalcPulseFreq*/
/* Brief:      �����ٶȼ�Ƶ��*/
/* Param:     OPG_T * pOPG  �ٶȼ���Ϣ*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void OPGCalcPulseFreq(OPG_T *pOPG)
{
    int32_t  pulse_freq_1 = 0;                    
    int32_t  pulse_freq_2 = 0;                    

    pulse_freq_1 = pOPG->iSign * pOPG->OPGInput.iPulseFreq0;
    pulse_freq_2 = pOPG->iSign * pOPG->OPGInput.iPulseFreq1;


    /*�����ٶȼ�Ƶ��-������һ��һ������������Χ�ڣ�ȡ��ֵ��Ϊ���Ƶ��*/
    if (pulse_freq_1 >= pulse_freq_2)
    {
        if (pulse_freq_1 < 0)                    /*if the frequence is negative*/
        {
            pOPG->Vars.iMaxPulseFreq = pulse_freq_2;    
        }
        else                                /*if the frequence is positive*/
        {
            pOPG->Vars.iMaxPulseFreq = pulse_freq_1;
        }        
    }
    else
    {
        if (pulse_freq_2 < 0)                    /*if the frequence is negative*/
        {
            pOPG->Vars.iMaxPulseFreq = pulse_freq_1;
        }
        else                                /*if the frequence is positive*/
        {
            pOPG->Vars.iMaxPulseFreq = pulse_freq_2;
        }
    }
}

/*******************************************************************************/
/* Function:  OPGInputProc*/
/* Brief:      �ٶȼ��������ݴ���*/
/* Param:     OPG_T * pOPG  �ٶȼ���Ϣ*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void OPGInputProc(OPG_T *pOPG)
{
    /*TODO check the input, and do some process(such as filter,sign,and so on) for sensor_process.*/
    /*if there are some vars need to be stored,please put into the pRadar->Vars struct.*/

    OPGCheckInput(pOPG);
    if (SS_OK == pOPG->Status)
    {
        OPGCalcPulseCnt(pOPG);
        OPGCalcPulseFreq(pOPG);
        pOPG->Vars.PreOPGInput = pOPG->OPGInput;
    }
}


/*******************************************************************************/
/* Function:  _CalcFiltedAccel*/
/* Brief:      ������˼��ٶ�*/
/* Param:     void  */
/* RetVal:    INT32 ���˼��ٶ�*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static int32_t SSCalcFiltedAccel(int32_t RawSpeedArray[], int32_t size)
{
    /*initial the variable */
    int32_t    filted_accel = 0;        /*filted acceleration*/

    /*���ٶȡ���(���ٶȼӼ���)��(�ٶ������ٶȼ���0)��(���ٶȱ�����ٶ�)*/
    if ((RawSpeedArray[0] > 0)
        || ((RawSpeedArray[0] == 0) && (RawSpeedArray[size-1] >= 0)))
    {
        filted_accel = (RawSpeedArray[0] - RawSpeedArray[size-1]) / s_SSParam.iAccelFiltedTime;
    }
    /*���ٶȡ���(���ٶȼӼ���)��(�ٶ��ɸ��ٶȼ���0)��(���ٶȱ�ɸ��ٶ�)*/
    else
    {
        filted_accel = -((RawSpeedArray[0] - RawSpeedArray[size-1]) / s_SSParam.iAccelFiltedTime);
    }

    return filted_accel;
}

/*******************************************************************************/
/* Function:  OPGCalcSpeed*/
/* Brief:      �����ٶȼƲ�����Ϣ*/
/* Param:     OPG_T * pOPG  �ٶȼ���Ϣ*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void OPGCalcSpeed(OPG_T *pOPG)
{
    /*TODO calc the OPG speed and accel with the OPG input*/
    /*store the result into the OPG.SpdDist struct*/
    int32_t raw_accel = 0;
    /*�����ٶȡ�ԭʼ���ٶ�*/
    pOPG->SpdDist.iMaxSpeed = (pOPG->Vars.iMaxPulseFreq * pOPG->OPGInput.iMaxPulseDist) / MM_2_UM;

    pOPG->SpdDist.iRawSpeed = (pOPG->Vars.iMaxPulseFreq * pOPG->OPGInput.iRawPulseDist) / MM_2_UM; 

    pOPG->Vars.iPreRawSpeed = pOPG->SpdDist.iRawSpeed;

    /*�����ٶ�����*/
    Common_FIFOWrite(pOPG->SpdDist.iRawSpeed, s_SSParam.iAccelFiltedCycle, pOPG->Vars.aiRawSpeed);
    /*������˼��ٶ�*/
    pOPG->SpdDist.iFiltedAccel = SSCalcFiltedAccel(pOPG->Vars.aiRawSpeed, s_SSParam.iAccelFiltedCycle);

}


/*******************************************************************************/
/* Function:  OPGCalcDist*/
/* Brief:      �����ٶȼƲ����Ϣ*/
/* Param:     OPG_T * pOPG  �ٶȼ���Ϣ*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void OPGCalcDist(OPG_T *pOPG)
{
    int32_t PulseCntFromBcnCh0 = 0;
    int32_t PulseCntFromBcnCh1 = 0;
    int32_t iMargin = 0;
    BOOL    pulse_cnt_ret_1 = EN_FALSE;
    BOOL    pulse_cnt_ret_2 = EN_FALSE;

    /*TODO calc the OPG dist with the OPG input*/
    /*�����ٶȼ�λ��-����*/
    if (pOPG->Vars.iPulseOneCycle >= 0)
    {
        pOPG->SpdDist.iMaxMov = (pOPG->Vars.iMaxPulseOneCycle * pOPG->OPGInput.iMaxPulseDist) / MM_2_UM;
        pOPG->SpdDist.iMinMov = (pOPG->Vars.iMinPulseOneCycle * pOPG->OPGInput.iMinPulseDist) / MM_2_UM;
        pOPG->SpdDist.iRawMov = (pOPG->Vars.iPulseOneCycle * pOPG->OPGInput.iRawPulseDist) / MM_2_UM;    
    }
    /*�����ٶȼ�λ��-����*/
    else
    {
        pOPG->SpdDist.iMaxMov = (pOPG->Vars.iMaxPulseOneCycle * pOPG->OPGInput.iMinPulseDist) / MM_2_UM;
        pOPG->SpdDist.iMinMov = (pOPG->Vars.iMinPulseOneCycle * pOPG->OPGInput.iMaxPulseDist) / MM_2_UM;
        pOPG->SpdDist.iRawMov = (pOPG->Vars.iPulseOneCycle * pOPG->OPGInput.iRawPulseDist) / MM_2_UM;
    }
    /*TODO calc the dist2bcn with the OPG input*/
    if (EN_TRUE == pOPG->BcnFrozenData.bBcnRead)
    {
        pulse_cnt_ret_1 = OPGCheckPulse(pOPG->BcnFrozenData.uiOPGFrozenCnt0, pOPG->Vars.uiPulseCnt0, MAX_DELTA_PULSE_CNT);
        pulse_cnt_ret_2 = OPGCheckPulse(pOPG->BcnFrozenData.uiOPGFrozenCnt1, pOPG->Vars.uiPulseCnt1, MAX_DELTA_PULSE_CNT);
        if ((EN_TRUE == pulse_cnt_ret_1) && (EN_TRUE == pulse_cnt_ret_2))
        {
            PulseCntFromBcnCh0 = pOPG->iSign * Common_Delta_Sign(pOPG->BcnFrozenData.uiOPGFrozenCnt0, pOPG->Vars.uiPulseCnt0);
            PulseCntFromBcnCh1 = pOPG->iSign * Common_Delta_Sign(pOPG->BcnFrozenData.uiOPGFrozenCnt1, pOPG->Vars.uiPulseCnt1);
            iMargin = pOPG->OPGInput.iMaxPulseDist;          /*����һ����������*/
            pOPG->Dist2Bcn.iMaxOffset = ((Common_MAX2(PulseCntFromBcnCh0, PulseCntFromBcnCh1) * pOPG->OPGInput.iMaxPulseDist) + iMargin) / MM_2_UM;
            pOPG->Dist2Bcn.iMinOffset = ((Common_MIN2(PulseCntFromBcnCh0, PulseCntFromBcnCh1) * pOPG->OPGInput.iMinPulseDist) - iMargin) / MM_2_UM;
            pOPG->Dist2Bcn.iRawOffset = (Common_MAX2(PulseCntFromBcnCh0, PulseCntFromBcnCh1) * pOPG->OPGInput.iRawPulseDist) / MM_2_UM;
        }
        else
        {
            /*��Ϊ�ű����ݴ��󣬶����ű�*/
            pOPG->BcnFrozenData.bBcnRead = EN_FALSE;
            pOPG->Dist2Bcn.iMaxOffset = 0;
            pOPG->Dist2Bcn.iMinOffset = 0;
            pOPG->Dist2Bcn.iRawOffset = 0;
        }
    }
    /*store the result into the OPG.SpdDsit and OPG.Dist2Bcn struct.*/
}
/*******************************************************************************/
/* Function:  DRResetVars*/
/* Brief:      �״�������������*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void DRResetVars(void)
{
    DRDebug_T DRDebug = {EN_FALSE, EN_FALSE, 0, 0, 0, 0, 0, 0};
    int32_t num = 0;

    /*ATPData ����*/
    Common_Memset((void*)(&g_Radar.Input), 0, sizeof(DRRawData_T));
    /*�ǲ�������*/
    g_Radar.Vars.DRDebug = DRDebug;
    g_Radar.Vars.bHighQuality = EN_FALSE;

    for (num = 0; num < MAX_DR_PACK_NUM; num++)
    {
        g_Radar.Vars.DRSpeedArray[num] = 0;
    }
    /*��ͬ�������*/
    Common_Memset((void*)(&g_Radar.SpdDist), 0, sizeof(SensorOutput_T));
}
/*******************************************************************************/
/* Function:  DRSetPolarity*/
/* Brief:      �����״���ټ���*/
/* Param:     SPDPolarity_E Polarity  ����*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void DRSetPolarity(SPDPolarity_E Polarity)
{
    /*TODO check the input, and do some process(such as the sign) for sensor_process.*/
    /*if there are some vars need to be stored,please put into the pOPG->Vars struct.*/
    int32_t pack_cnt;

    if (SPD_REV == Polarity)
    {
        for (pack_cnt = 0; pack_cnt < (int32_t)(g_Radar.Input.ucMsgNum); pack_cnt++)
        {
            if (DR_MOVE_FWD == g_Radar.Input.DRMsgAst[pack_cnt].Dir)
            {
                g_Radar.Input.DRMsgAst[pack_cnt].Dir = DR_MOVE_REV;
            }
            else if (DR_MOVE_REV == g_Radar.Input.DRMsgAst[pack_cnt].Dir)
            {
                g_Radar.Input.DRMsgAst[pack_cnt].Dir = DR_MOVE_FWD;
            }
            else
            {
                NOP;
            }
        }
    }
}

/*******************************************************************************/
/* Function:  _CalcSafeSpeed*/
/* Brief:      �����״ﰲȫ�ٶ�*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void DRCalcSafeSpeed( void )
{
    int32_t num = 0;
    int32_t temp = 0;
    int32_t maxspeed = g_Radar.Vars.DRSpeedArray[0];
    int32_t minspeed = g_Radar.Vars.DRSpeedArray[0];

    /*�ҳ���Ч���ٶ������������С���ٶ�ֵ*/
    for (num = 0; num < (int32_t)(g_Radar.Vars.DRDebug.ucSpeedValidNum); num++)
    {
        if (g_Radar.Vars.DRSpeedArray[num] > maxspeed)
        {
            maxspeed = g_Radar.Vars.DRSpeedArray[num];
        }
        if (g_Radar.Vars.DRSpeedArray[num] < minspeed)
        {
            minspeed = g_Radar.Vars.DRSpeedArray[num];
        }
    }

    /*��ǰ������ֵ����������ٶȣ��������ֵ��С��������ٶ�*/
    if (DR_MOVE_FWD == g_Radar.Vars.Dir)
    {
        maxspeed = (maxspeed * RADAR_SPEED_LSB) / MMPS_2_KPH;
        minspeed = (minspeed * RADAR_SPEED_LSB) / MMPS_2_KPH;

        /*�����״����õ��������ٶ�*/
        g_Radar.SpdDist.iMaxSpeed = maxspeed + s_SSParam.iMaxDRError;
        g_Radar.Vars.iMinSpeed = minspeed - s_SSParam.iMaxDRError;
        /*����������ı�����������ֵΪ0*/
        if ( 0 > g_Radar.Vars.iMinSpeed )
        {
            g_Radar.Vars.iMinSpeed = 0;
        }
    }
    else
    {
        temp = (maxspeed * RADAR_SPEED_LSB) / MMPS_2_KPH;
        maxspeed = (minspeed * RADAR_SPEED_LSB) / MMPS_2_KPH;
        minspeed = temp;

        g_Radar.SpdDist.iMaxSpeed = maxspeed - s_SSParam.iMaxDRError;
        g_Radar.Vars.iMinSpeed = minspeed + s_SSParam.iMaxDRError;
        /*����������ı�����������ֵΪ0*/
        if ( 0 < g_Radar.Vars.iMinSpeed )
        {
            g_Radar.Vars.iMinSpeed = 0;
        }
    }
}

/*******************************************************************************/
/* Function:  _CalcFiltedSpeed*/
/* Brief:      �����˲��ٶ�*/
/* Param:     void  */
/* RetVal:    INT32 �״��˲��ٶ�*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static int32_t DRCalcFiltedSpeed(void)
{
    int32_t speed = 0;
    int32_t i = 0;
    for (i = 0; i < (int32_t)(g_Radar.Vars.DRDebug.ucSpeedValidNum); i++)
    {
        speed += g_Radar.Vars.DRSpeedArray[i];/*�ۼ���Ч�ٶ�*/
    }
    /*ȡ��Ч�ٶȵ�ƽ��ֵ*/

    speed = speed / (int32_t)(g_Radar.Vars.DRDebug.ucSpeedValidNum);
    g_Radar.Vars.iPreRawSpeed = speed;/*���»�׼�ٶ�*/
    return speed;
}

/*******************************************************************************/
/* Function:  _CalcRawSpeed*/
/* Brief:      ����ԭʼ�״��ٶ�*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void DRCalcRawSpeed( void )
{
    /*��������ٶ�*/
    const int32_t filtedspeed = DRCalcFiltedSpeed();
    g_Radar.SpdDist.iRawSpeed = (filtedspeed * RADAR_SPEED_LSB) / MMPS_2_KPH;

    /*���ݹ����ٶ��ж��״﷽��*/
    if ( 0 <= g_Radar.SpdDist.iRawSpeed )
    {
        g_Radar.Vars.Dir = DR_MOVE_FWD;
    }
    else
    {
        g_Radar.Vars.Dir = DR_MOVE_REV;
    }
}

/*******************************************************************************/
/* Function:  DRMsgGetValidCnt*/
/* Brief:      ��Ч�״������*/
/* Param:     void  */
/* RetVal:    BOOL ��Ч�״����������Ԥ�ڷ���EN_TRUE�����򷵻�EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static BOOL DRMsgGetValidCnt(void)
{
    BOOL ret = EN_FALSE;
    BOOL ret_dir = EN_FALSE;
    BOOL ret_status = EN_FALSE;
    BOOL ret_speed = EN_FALSE;

    if (EN_FALSE == g_Radar.Vars.DRDebug.bSerialFault)
    {
        ret_dir = Common_IsBetween((int32_t)(g_Radar.Vars.DRDebug.ucDirValidNum), 
            s_SSParam.iDRMinValidPack, s_SSParam.iDRMaxPack);
        if (EN_TRUE != ret_dir)
        {
            g_Radar.Vars.DRDebug.bMoveDirNull = EN_TRUE;
        }
        ret_status = Common_IsBetween((int32_t)(g_Radar.Vars.DRDebug.ucStatusValidNum), 
                            s_SSParam.iDRMinValidPack, s_SSParam.iDRMaxPack);
        ret_speed = Common_IsBetween((int32_t)(g_Radar.Vars.DRDebug.ucSpeedValidNum), 
                            s_SSParam.iDRMinValidPack, s_SSParam.iDRMaxPack);
    }

    ret = ret_dir & ret_status & ret_speed;

    return ret;
}

/*******************************************************************************/
/* Function:  DRMsgMarkSN*/
/* Brief:      ��ȡ�����״��ID*/
/* Param:     void  */
/* RetVal:    uint32_t �����״��ID*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static uint8_t DRMsgMarkSN( void ) 
{
    uint8_t maxID = 0U;
    uint8_t num = 0U;
    for (num = 0U; num < g_Radar.Input.ucMsgNum; num++)
    {
        if (g_Radar.Input.DRMsgAst[num].ucID > maxID)
        {
            maxID = g_Radar.Input.DRMsgAst[num].ucID;
        }
    }
    return maxID;
}

/*******************************************************************************/
/* Function:  DRMsgCheckSpeed*/
/* Brief:      ����״ﱨ���ٶ�*/
/* Param:     DRMsg_T * DRMsg  �״ﱨ��*/
/* RetVal:    BOOL  �ɹ�����EN_TRUE��ʧ�ܷ���EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static BOOL DRMsgCheckSpeed( DRMsg_T * pDRMsg )
{
    BOOL ret = EN_FALSE;
    int32_t raw_speed = 0;

    if (EN_TRUE == pDRMsg->bValid)
    {
        raw_speed = pDRMsg->iSign * (int32_t)(pDRMsg->usSpeed);

        if (EN_TRUE == Common_IsBetween(raw_speed, g_Radar.Vars.iPreRawSpeed - s_SSParam.iDRDeltaSpeed,
            g_Radar.Vars.iPreRawSpeed + s_SSParam.iDRDeltaSpeed))
        {
            /*����Ч�ٶȷŽ����飬���ں��氲ȫ�ٶȼ���*/
            g_Radar.Vars.DRSpeedArray[g_Radar.Vars.DRDebug.ucSpeedValidNum] = raw_speed;
            g_Radar.Vars.DRDebug.ucSpeedValidNum++;
        }
        ret = EN_TRUE;
    }
    return ret;                
}

/*******************************************************************************/
/* Function:  _CheckDRStatus*/
/* Brief:      ����״ﱨ��״̬*/
/* Param:     void  */
/* RetVal:    BOOL  ���ͨ������EN_TRUE����ͨ������EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL DRMsgCheckStatus( DRMsg_T * DRMsg )
{
    BOOL ret = EN_FALSE;

    if (EN_TRUE == DRMsg->bValid)
    {
        /*check DR valid status*/
        if ((DR_MODE_FAULT != DRMsg->Mode) 
            && ((DR_QALITY_HIGH == DRMsg->Status) || (DR_QALITY_LOW == DRMsg->Status)))
        {
            g_Radar.Vars.DRDebug.ucStatusValidNum++;
        }
        else
        {
            DRMsg->bValid = EN_FALSE;
        }
        /*check DR high quality status*/
        if ((DR_MODE_BOTH == DRMsg->Mode) && (DR_QALITY_HIGH == DRMsg->Status))
        {
            g_Radar.Vars.DRDebug.ucHighQualityNum++;
        }
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  _CheckDRDir*/
/* Brief:      ����״ﱨ�ķ���*/
/* Param:     void  */
/* RetVal:    BOOL ���ͨ������EN_TRUE����ͨ������EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL DRMsgCheckDir( DRMsg_T * DRMsg )
{
    BOOL ret = EN_FALSE;

    if (EN_TRUE == DRMsg->bValid)
    {
        if (DR_MOVE_FWD == DRMsg->Dir )
        {
            DRMsg->iSign = SIGN_PLUS;
        }
        else if (DR_MOVE_REV == DRMsg->Dir )
        {
            DRMsg->iSign = SIGN_MINUS;
        }
        else if ((DR_MOVE_NULL == DRMsg->Dir ) && ((uint16_t)(DR_SPEED_ZVI) < DRMsg->usSpeed))
        {
            DRMsg->bValid = EN_FALSE;
            DRMsg->iSign = SIGN_ZERO;
        }
        else
        {
            DRMsg->iSign = SIGN_ZERO;
        }
        ret = EN_TRUE;
    }
    if (EN_TRUE == DRMsg->bValid)
    {
        g_Radar.Vars.DRDebug.ucDirValidNum++;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  _CheckSerialID*/
/* Brief:      ����״ﱨ�����к�*/
/* Param:     void  */
/* RetVal:    BOOL  ���ͨ������EN_TRUE����ͨ������EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL DRMsgCheckSN( DRMsg_T * pDRMsg )
{
    BOOL valid = EN_TRUE;
    uint32_t delta_index = 0U;

    if (EN_TRUE == g_Radar.Vars.bFirstCycle)
    {
        g_Radar.Vars.bFirstCycle = EN_FALSE;
    }
    else
    {
        /*��鱾�����״�������к�--0~255��Χ*/
        if (pDRMsg->ucID < g_Radar.Vars.ucPreMaxPacketID)
        {
            /*�����ڵ�ID�������ڵ�С������ѭ�����*/
            delta_index = (U8BOUNDARY - (uint32_t)(g_Radar.Vars.ucPreMaxPacketID)) + (uint32_t)(pDRMsg->ucID);
        }
        else
        {
            /*�����ڱ������ڵĴ�*/
            delta_index = (uint32_t)(pDRMsg->ucID) - (uint32_t)(g_Radar.Vars.ucPreMaxPacketID);
        }
        /*������MAX_DELTA_DR_INDEX������Ϊ�������յ�����ǰ�İ�*/
        if (MAX_DELTA_DR_INDEX < delta_index)
        {
            valid = EN_FALSE;
            pDRMsg->bValid = EN_FALSE;
            g_Radar.Vars.DRDebug.bSerialFault = EN_TRUE;
        }
    }
    return valid;
}
/*******************************************************************************/
/* Function:  _DRDataPreProc*/
/* Brief:      �״���ϢԤ����*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void DRMsgDebug( void )
{
    uint32_t maxspeed = g_Radar.Input.DRMsgAst[0].usSpeed;
    uint32_t minspeed = g_Radar.Input.DRMsgAst[0].usSpeed;
    uint32_t num = 0U;
    for (num = 0U; num < (uint32_t)(g_Radar.Input.ucMsgNum); num++)
    {
        if (g_Radar.Input.DRMsgAst[num].usSpeed > maxspeed)
        {
            maxspeed = g_Radar.Input.DRMsgAst[num].usSpeed;
        }
        if (g_Radar.Input.DRMsgAst[num].usSpeed < minspeed)
        {
            minspeed = g_Radar.Input.DRMsgAst[num].usSpeed;
        }
    }
    g_Radar.Vars.DRDebug.uiMaxSpeed = maxspeed;
    g_Radar.Vars.DRDebug.uiMinSpeed = minspeed;
    g_Radar.Vars.uiPulseCnt = g_Radar.Input.uiPulseCount;
}

/*******************************************************************************/
/* Function:  DRMsgFilter*/
/* Brief:      �״���Ч������*/
/* Param:     void  */
/* RetVal:    BOOL  ���ͨ������EN_TRUE����ͨ������EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL DRMsgFilter(void)
{
    BOOL valid = EN_FALSE;
    int32_t num = 0;

    /*��鱾�����״���ĸ���*/
    valid = Common_IsBetween((int32_t)(g_Radar.Input.ucMsgNum), s_SSParam.iDRMinPack, s_SSParam.iDRMaxPack);
    if (EN_TRUE == valid)
    {
        for (num = 0; (num < (int32_t)(g_Radar.Input.ucMsgNum)) && (EN_TRUE == valid); num++)
        {
            valid = DRMsgCheckSN(&g_Radar.Input.DRMsgAst[num]);
            (void)DRMsgCheckDir(&g_Radar.Input.DRMsgAst[num]);
            (void)DRMsgCheckStatus(&g_Radar.Input.DRMsgAst[num]);
            (void)DRMsgCheckSpeed(&g_Radar.Input.DRMsgAst[num]);
        }
        g_Radar.Vars.ucPreMaxPacketID = DRMsgMarkSN();
        g_Radar.Vars.bHighQuality = Common_IsBetween((int32_t)(g_Radar.Vars.DRDebug.ucHighQualityNum), 
            s_SSParam.iDRMinValidPack, s_SSParam.iDRMaxPack);
        valid = DRMsgGetValidCnt();
    }

    return valid;
}

/*******************************************************************************/
/* Function:  DRCheckInput*/
/* Brief:      ����״��������ݺϷ���*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void DRCheckInput(void)
{
    /*TODO check the input, and do some process(such as filter,sign,and so on) for sensor_process.*/
    /*if there are some vars need to be stored,please put into the pRadar->Vars struct.*/

    /*δ�յ������ù���*/
    if (EN_TRUE != g_Radar.Input.bRead)
    {
        g_Radar.Status = SS_FAULT;
    }
    /*ƽ̨�����״���Ϣ����������Ϊ������*/
    else if ((EN_TRUE != g_Radar.Input.bMsgValid) || (EN_TRUE != g_Radar.Input.bPulseValid))
    {
        g_Radar.Status = SS_UNAVAIL;
    }
    else
    {
        if (EN_TRUE == DRMsgFilter())
        {
            g_Radar.Status = SS_OK;
        }
        else
        {
            g_Radar.Status = SS_UNAVAIL;
        }
    }
}

/*******************************************************************************/
/* Function:  DRInputProc*/
/* Brief:      �״��������ݴ���*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void DRInputProc(void)
{
    /*TODO check the input, and do some process(such as filter,sign,and so on) for sensor_process.*/
    /*if there are some vars need to be stored,please put into the pRadar->Vars struct.*/
    DRMsgDebug();
    DRCheckInput();
}

/*******************************************************************************/
/* Function:  DRCalcSpeed*/
/* Brief:      �����״������Ϣ*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void DRCalcSpeed(void)
{
    /*TODO calc the OPG speed and accel with the DR input*/
    /*calculate the raw dr speed*/
    DRCalcRawSpeed();
    /*calculate the max and min speed*/
    DRCalcSafeSpeed();
    /*store the result into the Radar.SpdDist struct*/
    /*�����ٶ�����*/
    Common_FIFOWrite(g_Radar.SpdDist.iRawSpeed, s_SSParam.iAccelFiltedCycle, g_Radar.Vars.aiRawSpeed);
    /*������˼��ٶ�*/
    g_Radar.SpdDist.iFiltedAccel = SSCalcFiltedAccel(g_Radar.Vars.aiRawSpeed, s_SSParam.iAccelFiltedCycle);
}

/*******************************************************************************/
/* Function:  DRCalcDist*/
/* Brief:      �����״�����Ϣ*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void DRCalcDist(void)
{
    /*TODO calc the DR dist with the DR input*/
    if (DR_MOVE_FWD == g_Radar.Vars.Dir)
    {
        g_Radar.SpdDist.iMaxMov = (g_Radar.SpdDist.iMaxSpeed * s_SSParam.iCycleTime) / S_2_MS;
        g_Radar.SpdDist.iMinMov = (g_Radar.Vars.iMinSpeed * s_SSParam.iCycleTime) / S_2_MS;
        g_Radar.SpdDist.iRawMov = (g_Radar.SpdDist.iRawSpeed * s_SSParam.iCycleTime) / S_2_MS;
    }
    else
    {
        g_Radar.SpdDist.iMaxMov = (g_Radar.Vars.iMinSpeed * s_SSParam.iCycleTime) / S_2_MS;
        g_Radar.SpdDist.iMinMov = (g_Radar.SpdDist.iMaxSpeed * s_SSParam.iCycleTime) / S_2_MS;
        g_Radar.SpdDist.iRawMov = (g_Radar.SpdDist.iRawSpeed * s_SSParam.iCycleTime) / S_2_MS;
    }
    /*store the result into the Radar.SpdDsit struct.*/
}

/*******************************************************************************/
/* Function:  SSCheckParam*/
/* Brief:      ��⴫�������ò���*/
/* Param:     SPDParam_T * const pParam  ���ò���*/
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static int32_t SSCheckParam(const SPDParam_T * const pParam)
{
    int32_t ret = ATC_ERROR;
    if (ATC_NULL != pParam)
    {
        if ((0 != s_SSParam.iCycleTime))
        {
            ret = ATC_OK;
        }
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SSLoadParam*/
/* Brief:      �������ò���*/
/* Param:     SPDParam_T * const pParam  ���ò���*/
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static int32_t SSLoadParam(const SPDParam_T * const pParam)
{
    int32_t ret = ATC_ERROR;

    int64_t dr_max_speed = 0;
    int64_t temp_speed = 0;

    /*TODO check the param here!!!*/
    ret = SSCheckParam(pParam);

    if (ATC_OK == ret)
    {
        s_SSParam.iCycleTime = pParam->iCycleTime;
        s_SSParam.iMaxDRError = pParam->iDRError;
        s_SSParam.iMaxAccel = pParam->iMaxTrainAccel;
        s_SSParam.iAccelFiltedTime = pParam->iAccelFiltedTime;
        if (0 == pParam->iAccelFiltedTime)
        {
            s_SSParam.iAccelFiltedCycle = MIN_CNT;
        }
        else if (0 == (pParam->iAccelFiltedTime % s_SSParam.iCycleTime))
        {
            s_SSParam.iAccelFiltedCycle = pParam->iAccelFiltedTime / s_SSParam.iCycleTime;
        }
        else
        {
            s_SSParam.iAccelFiltedCycle = (pParam->iAccelFiltedTime / s_SSParam.iCycleTime) + MIN_CNT;
        }
        dr_max_speed = ((int64_t)(MAX_DR_SPEED) * (int64_t)(MMPS_2_KPH)) / (int64_t)(RADAR_SPEED_LSB);

        s_SSParam.iDRMaxSpeed = (int32_t)(dr_max_speed);

        temp_speed = ((int64_t)(s_SSParam.iMaxAccel) * (int64_t)(s_SSParam.iCycleTime) * (int64_t)(MMPS_2_KPH)) 
                    / (int64_t)(M_2_MM) / (int64_t)(RADAR_SPEED_LSB);
        /*�����״ﱾ������Ϳ��ܵ������ٶȴ������ٶȱ仯֮�͵�������Ϊ�״�ȡ�˲�ƽ����ԣ��*/
        s_SSParam.iDRDeltaSpeed= 2 * ((int32_t)(temp_speed) + ((s_SSParam.iMaxDRError * MMPS_2_KPH) / RADAR_SPEED_LSB));

        if (0 == (s_SSParam.iCycleTime % DR_DATA_CYCLE))
        {
            s_SSParam.iDRMaxPack = s_SSParam.iCycleTime / DR_DATA_CYCLE;
        }
        else
        {
            s_SSParam.iDRMaxPack = (s_SSParam.iCycleTime / DR_DATA_CYCLE) + MIN_CNT;
        }
        s_SSParam.iDRMinPack = (s_SSParam.iDRMaxPack * RAW_PACK_PERCENT) / PERSENT_BASE;
        s_SSParam.iDRMinValidPack = (s_SSParam.iDRMaxPack * VALID_PACK_PERCENT) / PERSENT_BASE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SSCheckStatus*/
/* Brief:      ������״̬���*/
/* RetVal:    int32_t  ���ͨ������ATC_OK����ͨ������ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static int32_t SSCheckStatus(void)
{
    /*TODO Check the OPG,RADAR status, if less than 2 sensor is available,return ATC_ERROR*/
    int32_t num_ok = 0;
    int32_t ret = ATC_ERROR;

    if (SS_OK == g_OPG_A.Status)
    {
        num_ok++;
    }
    if (SS_OK == g_OPG_B.Status)
    {
        num_ok++;
    }
    if (SS_OK == g_Radar.Status)
    {
        num_ok++;
    }

    if ((SS_2 == num_ok) ||(SS_3 == num_ok)) /*less than 2 sensor available,  can't work any longer.*/
    {
        ret = ATC_OK;
    }
    
    return ret;
}

/*******************************************************************************/
/* Function:  Sensor_Init*/
/* Brief:      ��������ʼ��*/
/* Param:     SPDParam_T * const pParam  ���ò���*/
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t Sensor_Init(const SPDParam_T * const pParam)
{
    int32_t ret = ATC_ERROR;

    Common_Memset(&g_OPG_A, 0, sizeof(OPG_T));
    Common_Memset(&g_OPG_B, 0, sizeof(OPG_T));
    Common_Memset(&g_Radar, 0, sizeof(Radar_T));
    Common_Memset(&s_SSParam, 0, sizeof(SS_PARAM_T));

    s_uiErrorCode = 0;

    /*TODO other initial jobs here, especially the no-zero vars. */
    g_OPG_A.Status = SS_OK;
    g_OPG_B.Status = SS_OK;
    g_Radar.Status = SS_OK;

    g_OPG_A.Vars.bFirstCycle = EN_TRUE;
    g_OPG_B.Vars.bFirstCycle = EN_TRUE;
    g_Radar.Vars.bFirstCycle = EN_TRUE;

    ret = SSLoadParam(pParam);
    return ret;
}

/*******************************************************************************/
/* Function:  Sensor_LoadInput*/
/* Brief:      �������������ݼ���*/
/* Param:     SPDInput_T * const pSPDInput  ��������������*/
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t Sensor_LoadInput( SPDInput_T * const pSPDInput)
{
    int32_t ret = ATC_ERROR;

    /*�ٶȼ���Ϣ*/
    if (SS_FAULT != g_OPG_A.Status)
    {
        g_OPG_A.OPGInput = pSPDInput->OPGRawDataA;
        g_OPG_A.BcnFrozenData.bBcnRead = pSPDInput->BcnData.bBcnRead;
        g_OPG_A.BcnFrozenData.uiOPGFrozenCnt0 = pSPDInput->BcnData.uiOPGAFrozenCnt0;
        g_OPG_A.BcnFrozenData.uiOPGFrozenCnt1 = pSPDInput->BcnData.uiOPGAFrozenCnt1;
        OPGSetPolarity(SST_OPGA, pSPDInput->Polarity);
        OPGInputProc(&g_OPG_A);
    }
    if (SS_FAULT != g_OPG_B.Status)
    {
        g_OPG_B.OPGInput = pSPDInput->OPGRawDataB;
        g_OPG_B.BcnFrozenData.bBcnRead = pSPDInput->BcnData.bBcnRead;
        g_OPG_B.BcnFrozenData.uiOPGFrozenCnt0 = pSPDInput->BcnData.uiOPGBFrozenCnt0;
        g_OPG_B.BcnFrozenData.uiOPGFrozenCnt1 = pSPDInput->BcnData.uiOPGBFrozenCnt1;
        OPGSetPolarity(SST_OPGB, pSPDInput->Polarity);
        OPGInputProc(&g_OPG_B);
    }
    if (SS_FAULT != g_Radar.Status)
    {
        g_Radar.Input = pSPDInput->DRRawData;
        DRSetPolarity(pSPDInput->Polarity);
        DRInputProc();
    }

    ret = SSCheckStatus();

    return ret;
}

/*******************************************************************************/
/* Function:  Sensor_Process*/
/* Brief:      ��������Ϣ����*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
void Sensor_Process(void)
{
    if (SS_FAULT == g_OPG_A.Status)
    {
       /*TODO set safty-sate;*/
    }
    else
    {
        OPGCalcSpeed(&g_OPG_A);
        OPGCalcDist(&g_OPG_A);
    }
    if (SS_FAULT == g_OPG_B.Status)
    {
       /*TODO set safty-sate;*/
    }
    else
    {
        OPGCalcSpeed(&g_OPG_B);
        OPGCalcDist(&g_OPG_B);
    }

    if (SS_FAULT == g_Radar.Status)
    {
       /*TODO set safty-sate;*/
    }
    else
    {
        DRCalcSpeed();
        DRCalcDist();
    }   
}

/*******************************************************************************/
/* Function:  Sensor_ResetVars*/
/* Brief:      ������������������*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
void Sensor_ResetVars( void )
{
    OPGResetVars();
    DRResetVars();
}

/*******************************************************************************/
/* Function:  Sensor_ResetOutput*/
/* Brief:      �����������Ϣ����*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
void Sensor_ResetOutput( void )
{
    Common_Memset(&g_OPG_A.Dist2Bcn, 0, sizeof(DistToBcn_T));
    Common_Memset(&g_OPG_A.SpdDist, 0, sizeof(SensorOutput_T));
    Common_Memset(&g_OPG_B.Dist2Bcn, 0, sizeof(DistToBcn_T));
    Common_Memset(&g_OPG_B.SpdDist, 0, sizeof(SensorOutput_T));
    Common_Memset(&g_Radar.SpdDist, 0, sizeof(SensorOutput_T));
}


