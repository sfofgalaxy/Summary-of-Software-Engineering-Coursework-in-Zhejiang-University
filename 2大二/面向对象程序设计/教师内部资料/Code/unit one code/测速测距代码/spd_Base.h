/** 
 * \brief     �����ṹ�빫����������
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_Base.h
 * 
 * �����ڲ��Ļ����ṹ�빫����������
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
#ifndef _SPD_BASE_H_INCLUDED_
#define _SPD_BASE_H_INCLUDED_

#include "Spd_lib.h"

#define     M_2_MM          1000            /*m��mm��λת��*/
#define     MM_2_UM         1000            /*mm��um��λת��*/
#define     S_2_MS          1000            /*s��ms��λת��*/
#define     NOP                             /*��*/
#define     RAW_SPEED_MAX_CYCLE   10        /*�ٶ��������󳤶�*/
#define     RELOC_INFO_MAX_CYCLE  12        /*�ض�λ��Ϣ�������󳤶�*/
#define     MAX_DR_PACK_NUM     20          /*ÿ���ڿ��ܵ�����״ﱨ�ĸ���*/
#define     MAX_THEORY_SPEED    0x7FFFFFFF  /*��������ٶ�*/
#define     MAX_THEORY_MOV      0x7FFFFFFF  /*�������λ��*/
#define     MIN_THEORY_MOV      0x80000000  /*������Сλ��*/

#define U8BOUNDARY 256U /*8λ�޷���������߽�*/
#define MAX_U32 0xFFFFFFFFU /*����32λ�޷�����*/
#define MAX_I32 0x7FFFFFFF  /*����32λ�з�����*/
#define ONE 1U   /*����߽����ʱʹ�õ�1-����0xFF+1=0*/

/*�����������Ϣ*/
typedef struct
{
    int32_t            iMaxMov;        /*�������λ��*/
    int32_t            iMinMov;        /*��С����λ��*/
    int32_t            iMaxSpeed;      /*����ٶ�*/
    int32_t            iRawMov;        /*ԭʼ����λ��*/
    int32_t            iRawSpeed;      /*ԭʼ�ٶ�*/
    int32_t            iFiltedAccel;   /*һ��ʱ��Ĺ��˼��ٶ�*/
}SensorOutput_T;

/*�������м����*/
typedef struct 
{    
    BOOL            bFirstCycle;        /*��ʼ����*/
    int32_t         iPreRawSpeed;       /*������ԭʼ�ٶ�*/
    int32_t         aiRawSpeed[RAW_SPEED_MAX_CYCLE];  /*ԭʼ�ٶ�����*/
    int32_t         iPulseOneCycle;     /*�����ڱ仯��ԭʼ������*/
    int32_t         iMaxPulseOneCycle;  /*�����ڱ仯�����������*/
    int32_t         iMinPulseOneCycle;  /*�����ڱ仯����С������*/
    int32_t         iMaxPulseFreq;         /*��������Ƶ��*/
    uint32_t        uiPulseCnt0;        /*����ۻ�������*/
    uint32_t        uiPulseCnt1;        /*��С�ۻ�������*/
    OPGRawData_T    PreOPGInput;        /*������OPG��������*/
} OPGInVars_T;

/*�״������Ϣ*/
typedef struct  
{
    BOOL        bSerialFault;       /*�������кŴ���*/
    BOOL        bMoveDirNull;       /*���ķ������*/
    uint8_t     ucStatusValidNum;   /*״̬��Ч�ı��ĸ���*/
    uint8_t     ucSpeedValidNum;    /*�ٶ���Ч�ı��ĸ���*/
    uint8_t     ucDirValidNum;      /*������Ч�ı��ĸ���*/
    uint8_t     ucHighQualityNum;   /*�������ı��ĸ���*/
    uint32_t    uiMaxSpeed;         /*ԭʼ�����е�����ٶ�*/
    uint32_t    uiMinSpeed;         /*ԭʼ�����е���С�ٶ�*/
}DRDebug_T;

/*�״��м����*/
typedef struct 
{    
    BOOL        bFirstCycle;            /*��ʼ������*/
    int32_t     iPreRawSpeed;           /*������ԭʼ�ٶ�*/
    uint8_t    ucPreMaxPacketID;       /*������������к�*/
    int32_t     DRSpeedArray[MAX_DR_PACK_NUM];   /*��¼��Ч���״��ٶ�����*/
    int32_t     aiRawSpeed[RAW_SPEED_MAX_CYCLE];  /*�״�����ԭʼ�ٶ�����*/
    BOOL        bHighQuality;           /*�����ڱ仯��ԭʼ������*/
    DRDir_E     Dir;                    /*�״﷽��*/
    uint32_t    uiPulseCnt;             /*�״��������*/
    int32_t     iMinSpeed;              /*��С�״��ٶ�*/
    DRDebug_T   DRDebug;                /*�״������Ϣ*/
} DRInVars_T;

/*�ű���������*/
typedef struct
{
    BOOL        bBcnRead;               /*�����ڶ����ű��־*/
    uint32_t    uiOPGFrozenCnt0;     /*��ȡ���ű�ʱ���ٶȴ�����ͨ��0������� */
    uint32_t    uiOPGFrozenCnt1;     /*��ȡ���ű�ʱ���ٶȴ�����ͨ��1������� */
}BcnFrozonData_T;

/*�ٶȼ���Ϣ*/
typedef struct
{
    int32_t             iSign;          /*���Ա�־*/
    SensorState_E       Status;         /*������״̬*/
    OPGRawData_T        OPGInput;       /*�ٶȼ���������*/
    BcnFrozonData_T     BcnFrozenData;  /*�ű���������*/
    OPGInVars_T         Vars;           /*�ٶȼ��м����*/
    DistToBcn_T         Dist2Bcn;       /*���ű�ľ���*/
    SensorOutput_T      SpdDist;        /*�ٶȼ��ٶ�λ�����*/
} OPG_T;

/*�״���Ϣ*/
typedef struct  
{
    SensorState_E       Status;         /*������״̬*/
    DRRawData_T         Input;          /*�״���������*/
    DRInVars_T          Vars;           /*�״��м����*/
    SensorOutput_T      SpdDist;        /*�״��ٶȾ������*/
} Radar_T;

/*���ٲ�������Ϣ*/
typedef struct
{
    int32_t             iMaxMov;        /*�������λ��-mm*/
    int32_t             iMinMov;        /*��С����λ��-mm*/
    int32_t             iRawMov;        /*ԭʼ����λ��-mm*/
    int32_t             iMaxSpeed;      /*��ȫ�ٶ�-mm/s*/
    int32_t             iRawSpeed;      /*ԭʼ�ٶ�-mm/s*/
    int32_t             iAccel;         /*���ٶ�-mm/s^2*/
    WheelStatus_E       Status;         /*����״̬*/
    Sensor_E            Selected;       /*ѡ�õĴ�����*/
    SPDState_E          State;          /*״̬��״̬*/
}Speed_T;

/*�����Ϣ*/
typedef struct
{
    SensorState_E       Status;     /*������״̬*/
    Sensor_E            Sensor;     /*����������*/
    int32_t             iSpeed;     /*�ٶ�*/
    int32_t             iWeight;    /*Ȩ��*/
    int32_t             iFailTime;  /*���ʧ��ʱ�䣬��ͬ��-ms*/
}Vote_T;

/*�ض�λ��Ĵ����Ϣ*/
typedef struct
{
    uint32_t         uiTimeStamp;   /*����ʱ���-ms*/
    int32_t          iMaxSpeed;     /*��ȫ�ٶ�-mm/s*/
    int32_t          iRawSpeed;     /*ԭʼ�ٶ�-mm/s*/
    int32_t          iMaxMov;       /*�������λ��-mm*/
    int32_t          iMinMov;       /*��С����λ��-mm*/
    int32_t          iRawMov;       /*ԭʼ����λ��-mm*/
}RelocInfo_T;


/*״̬���м����*/
typedef struct
{
    SPDState_E       Status;              /*״̬��״̬*/
    int32_t          iSlideTime;          /*��ʱ��*/
    int32_t          iCoastTime;          /*����ʱ��*/
    BOOL             bOPGRecover;         /*�򻬵��ٶȼƻָ���־*/
    VoteRet_E        VoteRet;             /*������*/
    Vote_T           VoteAst[3];          /*����ṹ������*/
    int32_t          iVoteFailTime;       /*���ʧ�ܳ���ʱ��*/
    BOOL             bReloc;              /*���ض�λ��־*/
    RelocInfo_T      RelocInfo[RELOC_INFO_MAX_CYCLE];         /*�ض�λ�Ĵ���Ϣ�ṹ��*/
}StateInVars_T;

/*�ű���Ϣ*/
typedef struct
{
    BOOL        bBcnRead;           /*�����ڶ����ű��־*/
    uint32_t    ulRawTimeStamp;     /* ���ű��ԭʼʱ��� */
    uint32_t    ulMaxTimeStamp;     /* ���ű�����ʱ���(�����ݲ�) */
    uint32_t    ulMinTimeStamp;     /* ���ű����Сʱ���(�����ݲ�) */
}BcnInfo_T;

/*״̬����Ϣ*/
typedef struct
{
    uint32_t        uiTimeStamp;    /*����ʱ���-ms*/
    BcnInfo_T       BcnInfo;        /*�ű���Ϣ*/
    StateInVars_T   Vars;           /*״̬���м����*/
    Speed_T         Speed;          /*���ٲ�����*/
    DistToBcn_T     Dist2Bcn;       /*���ű�ľ������*/
}State_T;

/**
 *  \brief ��������������
 *
 *  \param[in]  iData  ��Ҫ���뵽����ı���
 *  \param[in]  iSize �����С
 *  \param[in][out]  FIFO[] ���������
 */
void Common_FIFOWrite(const int32_t iData, int32_t iSize, int32_t FIFO[] );

/**
 *  \brief ȡ�����޷������ݵĲ�ֵuiValue2-uiValue1��Ӧ���з���ֵ�������ۼ��������ȿ���������Ҳ�����𽥼�С�ı����ļ���
 *
 *  \param[in]  uiValue1  ����
 *  \param[in]  uiValue2  ������
 *  \retval     int32_t   ��ֵ��uiValue2>=uiValue1����uiValue2-uiValue1��Ӧ���з���ֵ��uiValue2<uiValue1���ؾ��ƺ�Ĳ�ֵ��Ӧ���з���ֵ
 */
int32_t Common_Delta_Sign(uint32_t const uiValue1, uint32_t const uiValue2);

/**
 *  \brief ȡ�����޷������ݵĲ�ֵuiValue2-uiValue1���������������uiValue2<uiValue1��������������кš�ʱ����������ӵı����ļ���
 *
 *  \param[in]  uiValue1  ����
 *  \param[in]  uiValue2  ������
 *  \retval     int32_t   ��ֵ��uiValue2>=uiValue1����uiValue2-uiValue1��uiValue2<uiValue1���ؾ��ƺ�Ĳ�ֵ
 */
int32_t Common_Delta_Unsign(uint32_t const uiValue1, uint32_t const uiValue2);

/**
 *  \brief ȡiInput1��iInput2�Ľϴ�ֵ
 *
 *  \param[in]  iInput1  �����С�ȽϵĲ���1
 *  \param[in]  iInput2  �����С�ȽϵĲ���2
 *  \retval     int32_t  �ϴ�ֵ��iInput1>=iInput2����iInput1��iInput1<iInput2����iInput2
 */
int32_t Common_MAX2( const int32_t iInput1, const int32_t iInput2 );

/**
 *  \brief ȡiInput1��iInput2�Ľ�Сֵ
 *
 *  \param[in]  iInput1  �����С�ȽϵĲ���1
 *  \param[in]  iInput2  �����С�ȽϵĲ���2
 *  \retval     int32_t  ��Сֵ��iInput1>=iInput2����iInput2��iInput1<iInput2����iInput1
 */
int32_t Common_MIN2( const int32_t iInput1, const int32_t iInput2 );

/**
 *  \brief ȡ����ֵ
 *
 *  \param[in]  value  ��Ҫȡ����ֵ�Ĳ���
 *  \retval     int32_t  ����ֵ��value>=0����value��value<0����-value
 */
int32_t Common_ABS( const int32_t value );

/**
 *  \brief Memset
 *
 *  \param[in][out]  pAddr  ��Ҫmemset�Ŀռ��׵�ַ
 *  \param[in]  cValue   memset�ĳ�ֵ
 *  \param[in]  uiSize   ��Ҫmemset�Ŀռ��С
 */
void Common_Memset(void * const pAddr, const int8_t cValue, uint32_t uiSize);

/**
 *  \brief �ж�iValue�Ƿ���[iMin, iMax]֮��
 *
 *  \param[in]  iMin  ��С��Χ
 *  \param[in]  iMax  ���Χ
 *  \retval     BOOL  �ȽϽ������[iMin, iMax]�ڷ���EN_TRUE�����򷵻�EN_FALSE
 */
BOOL Common_IsBetween(int32_t iValue, int32_t iMin, int32_t iMax);
#endif
