/** 
 * \brief     ����״̬��
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_State.c
 * 
 * ����״̬��ʵ��
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */

#include "Spd_State.h"

extern OPG_T     g_OPG_A;
extern OPG_T     g_OPG_B;
extern Radar_T     g_Radar;

State_T                 g_State;                    /*״̬����Ϣ*/
static StateParam_T     s_StateParam;               /*״̬�����ò���*/
static uint32_t         s_uiErrorCode;              /*������*/

/*******************************************************************************/
/* Function:  SSCheckParam*/
/* Brief:      ���״̬�����ò���*/
/* Param:     SPDParam_T * const pParam  ���ò���*/
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
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
/* Brief:      �������ò���*/
/* Param:     SPDParam_T * const pParam  ���ò���*/
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
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
/* Brief:     ���㵽�ű�ľ���*/
/* Param:     int32_t MaxIndex  ���������������*/
/* Param:     int32_t MinIndex  ������С���������*/
/* Param:     int32_t RawIndex  ����ԭʼ���������*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
static void CalcDist2Bcn(int32_t MaxIndex, int32_t MinIndex, int32_t RawIndex)
{
    int32_t i = 0;
    /*���ű��������*/
    /*�����������嵱���ڵ�λ��*/
    g_State.Dist2Bcn.iMaxOffset = g_State.Vars.RelocInfo[MaxIndex].iMaxSpeed 
        * Common_Delta_Unsign(g_State.BcnInfo.ulMinTimeStamp, g_State.Vars.RelocInfo[MaxIndex - 1].uiTimeStamp);
    /*�ۼ��������ڵ���ǰ���ڵ�λ��*/
    for (i = 0; i < MaxIndex; i++)
    {
        g_State.Dist2Bcn.iMaxOffset += g_State.Vars.RelocInfo[i].iMaxMov;
    }
    /*���ű����С����*/
    g_State.Dist2Bcn.iMinOffset = g_State.Vars.RelocInfo[MinIndex].iRawSpeed 
        * Common_Delta_Unsign(g_State.BcnInfo.ulMaxTimeStamp, g_State.Vars.RelocInfo[MinIndex - 1].uiTimeStamp);
    for (i = 0; i < MinIndex; i++)
    {
        g_State.Dist2Bcn.iMinOffset += g_State.Vars.RelocInfo[i].iMinMov;
    }
    /*���ű��ԭʼ���롪��ATOʹ�ã������������������ض�λʱ����ʱ���*/
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
/* Brief:     ����ʱ����ҳ���������*/
/* Param:     uint32_t uiTimeStamp  ʱ���*/
/* Param:     BOOL bOverFlow  �������Ƿ������������*/
/* Param:     int32_t iBoundary  ���Ʊ߽�����*/
/* Param:     int32_t * const iIndex  ��������*/
/* RetVal:    int32_t �����ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
static int32_t FindCycleByTime(uint32_t uiTimeStamp, BOOL bOverFlow, int32_t iBoundary, int32_t * const iIndex)
{
    int32_t ret = EN_FALSE;
    int32_t i = 0;

    /*����ʱ������ƣ�������ʱ��պ��ھ��Ƶ���������֮��*/
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
/* Brief:     ����ض�λ��Ϣ�ṹ�������е�ʱ����Ƿ�������*/
/* Param:     int32_t * const iBoundary  ���Ʊ߽�����*/
/* RetVal:    BOOL ���������򷵻�EN_TRUE��δ���Ʒ���EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
static BOOL CheckArrayOverFlow(int32_t * const iBoundary)
{
    BOOL ret = EN_FALSE;
    int32_t i = 0;
    BOOL break_flag = EN_FALSE;

    /*���ֱ�����ʱ�����������С������Ϊ��������ƣ�����������������Ϊ���Ʊ߽�*/
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
/* Brief:     ���ض�λ��Ϣ��������*/
/* Param:     const RelocInfo_T Data  �������ض�λ��Ϣ*/
/* Param:     int32_t iSize  �����С*/
/* Param:     RelocInfo_T FIFO[]  �ض�λ��Ϣ����*/
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
/* Brief:     ���㵽�ű�ľ���*/
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

    /*�������ڵ��ض�λ��Ϣ��������*/
    reloc.uiTimeStamp = g_State.uiTimeStamp;
    reloc.iMaxSpeed = g_State.Speed.iMaxSpeed;
    reloc.iRawSpeed = g_State.Speed.iRawSpeed;
    reloc.iMaxMov = g_State.Speed.iMaxMov;
    reloc.iMinMov = g_State.Speed.iMinMov;
    reloc.iRawMov = g_State.Speed.iRawMov;
    RelocInfoFIFOWrite(reloc, s_StateParam.iBcnMissCycle, g_State.Vars.RelocInfo);

    /*�������ű꣬������ض�λ*/
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
/* Brief:      ״̬��������Ϣ*/
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
        /*ͬʱֻ������һ���ٶȼ��б����ͨ��ʱ�����*/
        if (0 != g_State.Vars.VoteAst[i].iFailTime)
        {
            g_State.Vars.iVoteFailTime = g_State.Vars.VoteAst[i].iFailTime;
        }
    }
}

/*******************************************************************************/
/* Function:  STUpdateOutput*/
/* Brief:      �Ӵ�������Ϣ�л�ȡ�ٶ�λ��*/
/* Param:     SensorOutput_T SensorOutput  ��������Ϣ*/
/* Param:     Speed_T * const pSpeed  ���ٲ�������Ϣ*/
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
/* Brief:      �������׼��*/
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

    /*���Ѿ���ʱ�Ĵ������óɹ���*/
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
/* Brief:      ���ʱ�ж�����ֵ�Ƿ�һ��*/
/* Param:     Vote_T Vote1  ���ֵ1*/
/* Param:     Vote_T Vote2  ���ֵ2*/
/* RetVal:    BOOL  һ�·���EN_TRUE����һ�·���EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static BOOL VoteEqual(Vote_T Vote1, Vote_T Vote2)
{
    BOOL ret = EN_FALSE;

    /*����״̬��ΪOK�����ٶ����С�ڵ�����������һ�룬�������Ա�֤���ͨ����������������֮������������*/
    if ((SS_OK == Vote1.Status) && (SS_OK == Vote2.Status)
        && (Common_ABS(Vote1.iSpeed - Vote2.iSpeed) <= (s_StateParam.iVoteDeltaSpeed / 2)))
    {
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  VoteProcess*/
/* Brief:      ���������*/
/* Param:     Vote_T VoteAst[]  �������*/
/* Param:     int32_t count  �������*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
static void VoteProcess(Vote_T VoteAst[], int32_t count)
{
    int32_t i = 0;
    int32_t j = 0;
    int32_t count_all = 0;

    /*���1������ȫ����ͬ            - ͨ��*/
    /*���2��������ͬ����һ����ͬ    - ͨ��*/
    /*���3������������ͬ            - ��*/

    /*����������飬��������һ�µģ���������һ*/
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
        /*��Ч����Ϊ0����Ŀ�����óɲ�����״̬*/
        if ( 0 == VoteAst[i].iWeight)
        {
            if (SS_FAULT != VoteAst[i].Status)
            {
                VoteAst[i].Status = SS_UNAVAIL;
                VoteAst[i].iFailTime += s_StateParam.iCycleTime;
            }
        }
        /*ͳ��OK����Ŀ����,����OK�ı����ͨ��ʱ������*/
        if (SS_OK == VoteAst[i].Status)
        {
            count_all++;
            VoteAst[i].iFailTime = 0;
        }
    }
    /*����OK����Ŀ����ͳ�Ʊ�����*/
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
/* Brief:      ����ת��*/
/* Param:     void  */
/* RetVal:    BOOL  �п�ת�򻬷���EN_TRUE�����з���EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL CheckSlipSlide( void )
{
    BOOL ret = EN_FALSE;

    g_State.Speed.Status = WS_COAST;

    /*��һ�ٶȼƴ򻬼��ж�Ϊ��,������ת������OPG����*/
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
/* Brief:     ���´�����״̬*/
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
/* Brief:      COAST״̬��ʼ��*/
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
/* Brief:     ����״̬�Ĺ��̴���*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void COAST_Duration(void)
{
    /*�����Ƿ�����ٶȼ�����ֵ�����ض�λ-For ATO*/
    g_State.Vars.iCoastTime += s_StateParam.iCycleTime;
    if (g_State.Vars.iCoastTime > COAST_TIME_TO_RELOC)
    {
        g_State.Vars.iCoastTime = COAST_TIME_TO_RELOC;
        g_State.Vars.bReloc = EN_TRUE;
    }
    /*��OPGA���ã�ʹ��OPGA��������Ϊ��ȫ�ٶ�*/
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
    /*����ʹ��OPGB������ʱ���A�����ã���B�ؿ��ã�*/
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
/* Brief:     ���е���״̬��ת���ж�*/
/* Param:     void  */
/* RetVal:    BOOL �����״̬����EN_TRUE�����򷵻�EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL COAST_2_SLIDE(void)
{
    BOOL ret = EN_FALSE;

    /*�����򻬣����״����*/
    if ((WS_SLIDE == g_State.Speed.Status) && (SS_OK == g_Radar.Status))
    {
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  COAST_2_FAULT*/
/* Brief:     ���е�����״̬��ת��*/
/* Param:     void  */
/* RetVal:    BOOL  �������״̬����EN_TRUE�����򷵻�EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL COAST_2_FAULT( void )
{
    BOOL ret = EN_FALSE;
    /*�����״����*/
    if ((WS_SLIDE == g_State.Speed.Status) && (SS_OK != g_Radar.Status))
    {
        ret = EN_TRUE;
    }
    /*���ʧ��*/
    if (VOTE_FAIL == g_State.Vars.VoteRet)
    {
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  FAULT_Duration*/
/* Brief:     ����״̬���̴���*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void FAULT_Duration(void)
{
    /*ȫ���óɹ���״̬*/
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
/* Brief:     �����ϵ�OPG�Ƿ���Իָ�*/
/* Param:     void  */
/* RetVal:    BOOL  �ɻָ�����EN_TRUE�����򷵻�EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL CheckOPGRecover( OPG_T * pOPG )
{
    BOOL ret = EN_FALSE;

    /*�״�״̬���ã����ٶȼ�δ���ϣ����ж��Ƿ�ɻָ�*/
    if ((SS_OK == g_Radar.Status) && (SS_FAULT != pOPG->Status))
    {
        /*�ٶȼ����״��ٶȲ�С�ڵ�������������Ϊ�ɻָ�*/
        if (Common_ABS(pOPG->SpdDist.iMaxSpeed - g_Radar.SpdDist.iMaxSpeed) <= s_StateParam.iVoteDeltaSpeed)
        {
            ret = EN_TRUE;
            pOPG->Status = SS_OK;
        }
        /*���ָܻ����ٶȼ����óɹ���״̬*/
        else
        {
            pOPG->Status = SS_FAULT;
        }
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SLIDE_Entry*/
/* Brief:     ��״̬��ʼ��*/
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
/* Brief:     ��״̬���̴���*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void SLIDE_Duration(void)
{
    /*�ۼӴ�ʱ��*/
    g_State.Vars.iSlideTime += s_StateParam.iCycleTime;

    /*��δ���ϵ�OPG���óɲ�����*/
    if (SS_FAULT != g_OPG_A.Status)
    {
        g_OPG_A.Status = SS_UNAVAIL;
    }
    if (SS_FAULT != g_OPG_B.Status)
    {
        g_OPG_B.Status = SS_UNAVAIL;
    }

    /*ʹ���״�������Ϊ��ȫ�ٶ�*/
    STUpdateOutput(g_Radar.SpdDist, &g_State.Speed);
    g_State.Speed.Status = WS_SLIDE;
    g_State.Speed.State = VS_SLIDE;
    g_State.Speed.Selected = SST_DR;
}

/*******************************************************************************/
/* Function:  SLIDE_2_FAULT*/
/* Brief:     �򻬵�����״̬��ת��*/
/* Param:     void  */
/* RetVal:    BOOL  �������״̬����EN_TRUE�����򷵻�EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL SLIDE_2_FAULT(void)
{
    BOOL ret = EN_FALSE;

    /*�״ﲻ���ã���򻬳�ʱ�ٶȼ�δ�ָ�*/
    if ((SS_OK != g_Radar.Status) || ((g_State.Vars.iSlideTime >= s_StateParam.iMaxSlideTime) && (EN_TRUE != g_State.Vars.bOPGRecover)))
    {    
        ret = EN_TRUE;
    }
    return ret;
}

/*******************************************************************************/
/* Function:  SLIDE_2_COAST*/
/* Brief:     �򻬵����е�״̬ת��*/
/* Param:     void  */
/* RetVal:    BOOL  �������״̬����EN_TRUE�����򷵻�EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static BOOL SLIDE_2_COAST(void)
{
    BOOL ret = EN_FALSE;

    /*�򻬵��ٶȼƻָ�*/
    if ((EN_TRUE == g_State.Vars.bOPGRecover))
    {
        ret = EN_TRUE;
    }
    return ret;
}


/*******************************************************************************/
/* Function:  SLIDE_PROCESS*/
/* Brief:     ��״̬����*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void  SLIDE_PROCESS(void)
{
    BOOL bRecoverA = EN_FALSE;
    BOOL bRecoverB = EN_FALSE;
    /*�������ʱ����󣬴򻬵��ٶȼ��Ƿ�ָ�*/
    if (g_State.Vars.iSlideTime >= s_StateParam.iMaxSlideTime)
    {
        bRecoverA = CheckOPGRecover(&g_OPG_A);
        bRecoverB = CheckOPGRecover(&g_OPG_B);
        if ((EN_TRUE == bRecoverA) || (EN_TRUE == bRecoverB))
        {
            g_State.Vars.bOPGRecover = EN_TRUE;
        }
    }

    /*�������״̬�ж�*/
    if ((EN_TRUE == SLIDE_2_FAULT()))
    {
        g_State.Speed.State = VS_FAULT;
        FAULT_Duration();
    }
    /*�������״̬�ж�*/
    else if (EN_TRUE == SLIDE_2_COAST())
    {
        COAST_Entry();
        COAST_Duration();
    }
    /*ά�ִ�״̬*/
    else
    {
        SLIDE_Duration();
    }
}

/*******************************************************************************/
/* Function:  COAST_PROCESS*/
/* Brief:     ����״̬����*/
/* Param:     void  */
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2013/11/1*/
/*******************************************************************************/
static void  COAST_PROCESS(void)
{
    /*����ת��*/
    (void)CheckSlipSlide();

    /*δ��ʱ������ȡ�����*/
    if (WS_COAST == g_State.Speed.Status)
    {
        /*����������ת��Ϊ����ṹ��*/
        VotePrepare();
        /*���*/
        VoteProcess(g_State.Vars.VoteAst, VOTE_NUM);
        /*���������µ���������Ϣ�ṹ��*/
        UpdateSSState();
    }
    else
    {
        /*��������*/
        g_State.Vars.VoteRet = VOTE_NULL;
    }

    /*�������״̬�ж�*/
    if (EN_TRUE == COAST_2_FAULT())
    {
        g_State.Speed.State = VS_FAULT;
        g_State.Vars.iCoastTime = 0;
        FAULT_Duration();
    }
    /*�����״̬�ж�*/
    else if (EN_TRUE == COAST_2_SLIDE())
    {
        SLIDE_Entry();
        SLIDE_Duration();
    }
    /*ά�ֶ���*/
    else
    {
        COAST_Duration();
    }
}

/*******************************************************************************/
/* Function:  FAULT_PROCESS*/
/* Brief:     ����״̬����*/
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
/* Brief:      ��ʼ��*/
/* Param:     SPDParam_T * const pParam  ���ò���*/
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
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
/* Brief:     ״̬���������ݼ���*/
/* Param:     SPDInput_T * const pSPDInput  ״̬����������*/
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
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
/* Brief:      ״̬�����*/
/* Param:     void  */
/* RetVal:    int32_t  �ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR*/
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
/* Brief:      ������������*/
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
/* Brief:      �����������*/
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

