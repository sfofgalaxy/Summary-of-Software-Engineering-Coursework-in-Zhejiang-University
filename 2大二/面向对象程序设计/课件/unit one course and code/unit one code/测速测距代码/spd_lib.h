/** 
 * \brief     ���ٲ����ģ��ͷ�ļ�
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_lib.h
 * 
 * ���ٶ���ӿڡ����ݶ���
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
#ifndef _SPD_LIB_H_
#define _SPD_LIB_H_

#include "AtcDataType.h"

#define MAX_DR_PACKET     15    /*��������״ﱨ�ĸ���*/

/*ʹ�õĴ�����*/
typedef enum
{
    SST_NULL = 0,        /*��*/
    SST_OPGA,            /*�ٶȼ�A*/
    SST_OPGB,            /*�ٶȼ�B*/
    SST_DR               /*�״�*/
} Sensor_E;  

/*���ٷ���*/
typedef enum
{
    SPD_FWD = 0,            /*��ǰΪ������*/
    SPD_REV                 /*���Ϊ������*/
}SPDPolarity_E;

/*����״̬*/
typedef enum 
{    
    VS_COAST = 0,       /*����*/
    VS_SLIDE,           /*��*/
    VS_FAULT            /*����*/
}SPDState_E;

/*����״̬/**/
typedef enum
{
    WS_COAST =0,             /*����״̬/**/
    WS_SLIDE,                /*��״̬/**/
} WheelStatus_E;

typedef enum
{
    SS_FAULT = 0,       /*����״̬*/
    SS_UNAVAIL,     /*������״̬*/
    SS_OK           /*����״̬*/
}SensorState_E;

/*�״�״̬*/
typedef enum
{
    DR_QALITY_HIGH = 0,     /*������*/
    DR_QALITY_LOW,      /*������*/
    DR_QALITY_BLACKOUT,        /*�޷���*/
    DR_QALITY_FREQSWEEP        /*��ȡ״̬*/
} DRQality_E;

/*�״�ģʽ*/
typedef enum
{
    DR_MODE_BOTH = 0,       /*ȫģʽ*/
    DR_MODE_40,         /*40��ģʽ*/
    DR_MODE_50,         /*50��ģʽ*/
    DR_MODE_FAULT       /*����ģʽ*/
} DRMode_E;

/*�״﷽��*/
typedef enum
{
    DR_MOVE_NULL = 0,       /*�޷����ʾ��Ϣ*/
    DR_MOVE_FWD,        /*�н�����Ϊǰ��*/
    DR_MOVE_REV         /*�н�����Ϊ����*/
} DRDir_E;

/*������������*/
typedef enum
{
    VOTE_NULL = 0,       /*����Ҫ���*/
    VOTE_PASS2,      /*�������ͨ��*/
    VOTE_PASS3,     /*���ȫ��ͨ��*/
    VOTE_FAIL           /*���ʧ��*/
}VoteRet_E;

/*���ٶȼ������*/
typedef struct
{
    int32_t         iMaxPulseDist;  /*��������-um*/
    int32_t         iMinPulseDist;  /*��С�����-um*/
    int32_t         iRawPulseDist;  /*ԭʼ�����-um*/
} OPGPulseDist_T;

/*�����ű�ľ���*/
typedef struct
{
    BOOL            bRead;          /*�Ƿ�������ű�*/
    BOOL            bReloc;         /*���ű��Ƿ���������ض�λ-��ATO��Ч���ڷǿ�ת��ʱΪTRUE*/
    int32_t         iMaxOffset;     /*��Բο��ű�����ƫ��-mm*/
    int32_t         iMinOffset;     /*��Բο��ű����Сƫ��-mm*/
    int32_t         iRawOffset;     /*��Բο��ű��ԭʼƫ��-mm*/
}DistToBcn_T;

typedef struct  
{
    int32_t         iCycleTime;         /*����ģ������ʱ��-ms*/
    SPDPolarity_E   Polarity;           /*�������÷���*/
    int32_t         iMaxTrainAccel;     /*�г������ٶ�-mm/s^2*/
    int32_t         iDRError;           /*�״�������-mm/s*/
    int32_t         iVoteSpareTime;     /*�������������ʱ��-ms*/
    int32_t         iVoteDeltaSpeed;    /*��������������ٶȲ�-mm/s*/
    int32_t         iSlideAccel;        /*���ж����ٶ�-mm/s^2*/
    int32_t         iMaxSlideTime;      /*�򻬿���ʱ��-ms*/
    int32_t         iAccelFiltedTime;   /*���˼��ٶȼ���ʱ��-ms*/
    int32_t         iBcnMissTime;       /*�ű궪ʧ��ˡʱ��-ms*/
}SPDParam_T;

/*���ٴ�����״̬*/
typedef struct
{
    SensorState_E   OPGStateA;      /*�ٶȼ�A״̬*/
    SensorState_E   OPGStateB;      /*�ٶȼ�B״̬*/
    SensorState_E   DRState;        /*�״�״̬*/
}SensorState_T;

/*���ٲ�������Ϣ*/
typedef struct
{
    Sensor_E        Selected;           /*ѡ�õ��ٶȼ�*/
    VoteRet_E       VoteRet;            /*������������*/
    SPDState_E      State;              /*����״̬��״̬*/
    WheelStatus_E   Status;             /*����״̬*/
    int32_t         iVoteFailTime;      /*�����һ��ʱ��-ms*/
    int32_t         iSlideTime;         /*��ʱ��-ms*/
}SPDDbgInfo_T;

/*�ٶȼƵ�����Ϣ*/
typedef struct
{
    OPGPulseDist_T  PulseDist;          /*�����*/
    SensorState_E   SensorState;        /*������״̬*/
    int32_t         iPulseOneCycle;     /*�����ڱ仯��ԭʼ������*/
    int32_t         iMaxPulseOneCycle;  /*�����ڱ仯�����������*/
    int32_t         iMinPulseOneCycle;  /*�����ڱ仯����С������*/
    int32_t         iMaxPulseFreq;         /*��������Ƶ��*/
    uint32_t        uiPulseCntCh0;      /*����ۻ�������*/
    uint32_t        uiPulseCntCh1;      /*��С�ۻ�������*/
    int32_t         iRawSpeed;          /*ԭʼ�ٶ�-mm/s*/
    int32_t         iMaxSpeed;         /*��ȫ�ٶ�-mm/s*/
    int32_t         iRawMov;            /*ԭʼ����λ��-mm*/
    int32_t         iMaxMov;            /*�������λ��-mm*/
    int32_t         iMinMov;            /*��С����λ��-mm*/
    int32_t         iFiltedAccel;       /*���˼��ٶ�-mm/s^2*/
}OPGDbgInfo_T;

/*�״������Ϣ*/
typedef struct
{
    SensorState_E   SensorState;        /*������״̬*/
    BOOL            bDRMsgValid;        /*�״ﱨ����Ч*/
    BOOL            bDRPulseValid;      /*�״�������Ч*/
    uint8_t         ucMsgNum;           /*�״������*/
    DRDir_E         Dir;                /*�״﷽��*/
    BOOL            bHighQuality;       /*�״������*/
    BOOL            bSerialFault;       /*���кŴ���*/
    BOOL            bMoveDirNull;       /*�״﷽�����*/
    uint8_t         ucStatusValidNum;   /*�״�״̬��Ч������*/
    uint8_t         ucSpeedValidNum;    /*�״��ٶ���Ч������*/
    uint8_t         ucDirValidNum;      /*�״﷽����Ч������*/
    uint32_t        uiMaxSpeed;         /*�״ﱨ���������ٶ�*/
    uint32_t        uiMinSpeed;         /*�״ﱨ������С���ٶ�*/
    int32_t         iRawSpeed;          /*ԭʼ�ٶ�-mm/s*/
    int32_t         iMaxSpeed;         /*��ȫ�ٶ�-mm/s*/
    int32_t         iRawMov;            /*ԭʼ����λ��-mm*/
    int32_t         iMaxMov;            /*�������λ��-mm*/
    int32_t         iMinMov;            /*��С����λ��-mm*/
    int32_t         iFiltedAccel;       /*���˼��ٶ�-mm/s^2*/
}DRDbgInfo_T;

/*���ٴ�����������Ϣ*/
typedef struct
{
    OPGDbgInfo_T    OPGDbgInfoA;           /*�ٶȼ�A������Ϣ*/
    OPGDbgInfo_T    OPGDbgInfoB;           /*�ٶȼ�B������Ϣ*/
    DRDbgInfo_T     DRDbgInfo;             /*�״������Ϣ*/
}SSDbgInfo_T;

/*�ٶȼ�ԭʼ����*/
typedef struct
{
    BOOL        bRead;               /*���ٶȼư�*/
    BOOL        bValid;              /*�ٶȼƹ��ϱ�־ TRUE: �ٶȼƷ�������    FALSE: �ٶȼƹ�������*/
    int32_t     iPulseFreq0;         /*�ٶȼ�ͨ��0����Ƶ��*/
    int32_t     iPulseFreq1;         /*�ٶȼ�ͨ��1����Ƶ��*/
    uint32_t    uiPulseCnt0;         /*�ٶȼ�ͨ��0�������ֵ*/
    uint32_t    uiPulseCnt1;         /*�ٶȼ�ͨ��1�������ֵ*/
    int32_t     iMaxPulseDist;       /*��������-um*/
    int32_t     iMinPulseDist;       /*��С�����-um*/
    int32_t     iRawPulseDist;       /*ԭʼ�����-um*/
} OPGRawData_T;

/*ԭʼ�ű�����*/
typedef struct
{
    BOOL        bBcnRead;            /* �����ű��־*/
    uint32_t    ulTimeStamp;         /* ���ű��ʱ��� */
    uint32_t    ulTimeStampTol;      /* ���ű��ʱ����ݲ� */
    uint32_t    uiOPGAFrozenCnt0;     /* ��ȡ���ű�ʱ���ٶȴ�����Aͨ��0������� */
    uint32_t    uiOPGAFrozenCnt1;     /* ��ȡ���ű�ʱ���ٶȴ�����Aͨ��1������� */
    uint32_t    uiOPGBFrozenCnt0;     /* ��ȡ���ű�ʱ���ٶȴ�����Bͨ��0������� */
    uint32_t    uiOPGBFrozenCnt1;     /* ��ȡ���ű�ʱ���ٶȴ�����Bͨ��1������� */
}BcnRawData_T;

/*�״ﱨ��*/
typedef struct
{
    uint8_t     ucID;           /*���İ�ID*/
    DRQality_E  Status;         /*DR status*/
    DRMode_E    Mode;           /*DR mode*/
    DRDir_E     Dir;            /*�״��⵽�����з���*/
    uint16_t    usSpeed;        /*�����ٶ�*/
    uint16_t    usOffset;       /*����λ��*/
    BOOL        bValid;         /*�����Ƿ����-�����ж�*/
    int32_t     iSign;          /*�����ٶȵķ������λ-�����ж�*/
} DRMsg_T;

/*�״�ԭʼ����*/
typedef struct
{
    BOOL        bRead;          /*���״��*/
    BOOL        bMsgValid;      /*����״̬*/
    BOOL        bPulseValid;    /*����״̬*/
    uint8_t     ucMsgNum;       /*���İ�����*/
    uint32_t    uiPulseFreq;    /*����Ƶ��*/
    uint32_t    uiPulseCount;   /*�������*/
    DRMsg_T     DRMsgAst[MAX_DR_PACKET]; /*���Ľṹ������*/
} DRRawData_T;

/*���ٲ����������*/
typedef struct
{
    uint32_t        uiTimeStamp;    /*����ʱ���-ms*/
    BcnRawData_T       BcnData;        /*�ű���Ϣ*/
    OPGRawData_T    OPGRawDataA;    /*�ٶȼ�A����*/
    OPGRawData_T    OPGRawDataB;    /*�ٶȼ�B����*/
    DRRawData_T     DRRawData;      /*�״�����*/
    SPDPolarity_E   Polarity;       /*���ټ���*/
}SPDInput_T;

/*================================���ýӿ�===================================*/
/**
 *  \brief ��ʼ��:����������Ĳ������ݵ����ٵ�Ԫ
 *
 *  \param[in]  pParam  ���ٲ�����ò���
 *  \retval     int32_t ��ʼ���ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_Init(const SPDParam_T * const pParam);


/*================================�����ӿ�===================================*/
/**
 *  \brief �����Ե��ã����в��ٲ����Ϣ����
 *
 *  \param[in]  pSPDInput  ���ٲ����������
 *  \retval     int32_t    ������������ATC_OK�����Ϸ���ATC_ERROR
 */
int32_t SPD_Measure( SPDInput_T * const pSPDInput);

/*==============================�����ȡ�ӿ�=================================*/
/**
 *  \brief ��ȡ���ڵ����λ��
 *
 *  \param[in][out]  pMaxMov  �������λ��
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetMaxMov(int32_t * const pMaxMov);

/**
 *  \brief ��ȡ���ڵ���Сλ��
 *
 *  \param[in][out]  pMinMov  ��С����λ��
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetMinMov(int32_t * const pMinMov);

/**
 *  \brief ��ȡ���ڵ�ԭʼλ��
 *
 *  \param[in][out]  pRawMov  ԭʼ����λ��
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetRawMov(int32_t * const pRawMov);

/*==============================�����ȡ�ӿ�=================================*/
/**
 *  \brief �����������µĶ�λ�ű�ʱ��ͨ���˽ӿڿɻ�ȡ����ǰ����ű��λ��
 *
 *  \param[in][out]  pDist2Bcn  ���ű�ľ���
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetDst2Bcn(DistToBcn_T * const pDist2Bcn);

/*==============================�ٶȻ�ȡ�ӿ�=================================*/
/**
 *  \brief ��ȡ����ٶ�
 *
 *  \param[in][out]  pMaxSpeed  ����ٶ�
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetMaxSpeed(int32_t * const pMaxSpeed);

/**
 *  \brief ��ȡԭʼ�ٶ�
 *
 *  \param[in][out]  pRawSpeed  ԭʼ�ٶ�
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetRawSpeed(int32_t * const pRawSpeed);

/**
 *  \brief ��ȡ���ٶ�
 *
 *  \param[in][out]  pAccel  ���ٶ�
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetAccel(int32_t * const pAccel);
/*==============================״̬��ȡ�ӿ�=================================*/
/**
 *  \brief ��ȡ��ǰ��״̬�����С��򻬡�����
 *         ����״̬�£���Ӧʹ���ٶȡ��������Ϣ
 *  \param[in][out]  pState  ����״̬
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetState(SPDState_E * const pState);

/**
 *  \brief ��ȡ���в��ٴ�������״̬�����á������á�����
 *
 *  \param[in][out]  pState  ������״̬
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_GetSensorState(SensorState_T * const pState);

/*==============================������Ϣ�ӿ�=================================*/
/**
 *  \brief ��ȡ���ٲ�൥Ԫ�Ĵ����룬�����������д���λ
 *
 *  \param[in][out]  pErrorCode  ������
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_DBG_GetErrorCode(uint32_t * const pErrorCode);

/**
 *  \brief ����ҵ���ĵ�����Ϣ����ȡ�����߼�����ĵ�����Ϣ
 *
 *  \param[in][out]  pSPDDbgInfo  ���ٵ�����Ϣ
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_DBG_GetSPDInfo(SPDDbgInfo_T *pSPDDbgInfo);

/**
 *  \brief ���������ĵ�����Ϣ����ȡ�����Ĵ�������Ϣ
 *
 *  \param[in][out]  pSSDbgInfo  ������������Ϣ
 *  \retval  int32_t  ��ȡ�ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t SPD_DBG_GetSSInfo(SSDbgInfo_T *pSSDbgInfo);

#endif
