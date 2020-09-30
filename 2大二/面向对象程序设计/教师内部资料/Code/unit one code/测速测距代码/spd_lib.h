/** 
 * \brief     测速测距主模块头文件
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_lib.h
 * 
 * 测速对外接口、数据定义
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
#ifndef _SPD_LIB_H_
#define _SPD_LIB_H_

#include "AtcDataType.h"

#define MAX_DR_PACKET     15    /*周期最大雷达报文个数*/

/*使用的传感器*/
typedef enum
{
    SST_NULL = 0,        /*无*/
    SST_OPGA,            /*速度计A*/
    SST_OPGB,            /*速度计B*/
    SST_DR               /*雷达*/
} Sensor_E;  

/*测速方向*/
typedef enum
{
    SPD_FWD = 0,            /*向前为正方向*/
    SPD_REV                 /*向后为正方向*/
}SPDPolarity_E;

/*测速状态*/
typedef enum 
{    
    VS_COAST = 0,       /*惰行*/
    VS_SLIDE,           /*打滑*/
    VS_FAULT            /*故障*/
}SPDState_E;

/*车轮状态/**/
typedef enum
{
    WS_COAST =0,             /*惰行状态/**/
    WS_SLIDE,                /*打滑状态/**/
} WheelStatus_E;

typedef enum
{
    SS_FAULT = 0,       /*故障状态*/
    SS_UNAVAIL,     /*不可用状态*/
    SS_OK           /*可用状态*/
}SensorState_E;

/*雷达状态*/
typedef enum
{
    DR_QALITY_HIGH = 0,     /*高质量*/
    DR_QALITY_LOW,      /*低质量*/
    DR_QALITY_BLACKOUT,        /*无反射*/
    DR_QALITY_FREQSWEEP        /*获取状态*/
} DRQality_E;

/*雷达模式*/
typedef enum
{
    DR_MODE_BOTH = 0,       /*全模式*/
    DR_MODE_40,         /*40度模式*/
    DR_MODE_50,         /*50度模式*/
    DR_MODE_FAULT       /*故障模式*/
} DRMode_E;

/*雷达方向*/
typedef enum
{
    DR_MOVE_NULL = 0,       /*无方向表示信息*/
    DR_MOVE_FWD,        /*行进方向为前进*/
    DR_MOVE_REV         /*行进方向为后退*/
} DRDir_E;

/*传感器表决结果*/
typedef enum
{
    VOTE_NULL = 0,       /*不需要表决*/
    VOTE_PASS2,      /*表决部分通过*/
    VOTE_PASS3,     /*表决全部通过*/
    VOTE_FAIL           /*表决失败*/
}VoteRet_E;

/*单速度计脉冲距*/
typedef struct
{
    int32_t         iMaxPulseDist;  /*最大脉冲距-um*/
    int32_t         iMinPulseDist;  /*最小脉冲距-um*/
    int32_t         iRawPulseDist;  /*原始脉冲距-um*/
} OPGPulseDist_T;

/*到新信标的距离*/
typedef struct
{
    BOOL            bRead;          /*是否读到新信标*/
    BOOL            bReloc;         /*新信标是否可以用来重定位-对ATO有效，在非空转打滑时为TRUE*/
    int32_t         iMaxOffset;     /*相对参考信标的最大偏移-mm*/
    int32_t         iMinOffset;     /*相对参考信标的最小偏移-mm*/
    int32_t         iRawOffset;     /*相对参考信标的原始偏移-mm*/
}DistToBcn_T;

typedef struct  
{
    int32_t         iCycleTime;         /*测速模块周期时间-ms*/
    SPDPolarity_E   Polarity;           /*测速配置方向*/
    int32_t         iMaxTrainAccel;     /*列车最大加速度-mm/s^2*/
    int32_t         iDRError;           /*雷达测速误差-mm/s*/
    int32_t         iVoteSpareTime;     /*传感器表决宽限时间-ms*/
    int32_t         iVoteDeltaSpeed;    /*传感器表决宽限速度差-mm/s*/
    int32_t         iSlideAccel;        /*打滑判定加速度-mm/s^2*/
    int32_t         iMaxSlideTime;      /*打滑宽限时间-ms*/
    int32_t         iAccelFiltedTime;   /*过滤加速度计算时间-ms*/
    int32_t         iBcnMissTime;       /*信标丢失宽恕时间-ms*/
}SPDParam_T;

/*测速传感器状态*/
typedef struct
{
    SensorState_E   OPGStateA;      /*速度计A状态*/
    SensorState_E   OPGStateB;      /*速度计B状态*/
    SensorState_E   DRState;        /*雷达状态*/
}SensorState_T;

/*测速测距调试信息*/
typedef struct
{
    Sensor_E        Selected;           /*选用的速度计*/
    VoteRet_E       VoteRet;            /*传感器表决结果*/
    SPDState_E      State;              /*测速状态机状态*/
    WheelStatus_E   Status;             /*车轮状态*/
    int32_t         iVoteFailTime;      /*表决不一致时间-ms*/
    int32_t         iSlideTime;         /*打滑时间-ms*/
}SPDDbgInfo_T;

/*速度计调试信息*/
typedef struct
{
    OPGPulseDist_T  PulseDist;          /*脉冲距*/
    SensorState_E   SensorState;        /*传感器状态*/
    int32_t         iPulseOneCycle;     /*周期内变化的原始脉冲数*/
    int32_t         iMaxPulseOneCycle;  /*周期内变化的最大脉冲数*/
    int32_t         iMinPulseOneCycle;  /*周期内变化的最小脉冲数*/
    int32_t         iMaxPulseFreq;         /*周期脉冲频率*/
    uint32_t        uiPulseCntCh0;      /*最大累积脉冲数*/
    uint32_t        uiPulseCntCh1;      /*最小累积脉冲数*/
    int32_t         iRawSpeed;          /*原始速度-mm/s*/
    int32_t         iMaxSpeed;         /*安全速度-mm/s*/
    int32_t         iRawMov;            /*原始周期位移-mm*/
    int32_t         iMaxMov;            /*最大周期位移-mm*/
    int32_t         iMinMov;            /*最小周期位移-mm*/
    int32_t         iFiltedAccel;       /*过滤加速度-mm/s^2*/
}OPGDbgInfo_T;

/*雷达调试信息*/
typedef struct
{
    SensorState_E   SensorState;        /*传感器状态*/
    BOOL            bDRMsgValid;        /*雷达报文有效*/
    BOOL            bDRPulseValid;      /*雷达脉冲有效*/
    uint8_t         ucMsgNum;           /*雷达包个数*/
    DRDir_E         Dir;                /*雷达方向*/
    BOOL            bHighQuality;       /*雷达高质量*/
    BOOL            bSerialFault;       /*序列号错误*/
    BOOL            bMoveDirNull;       /*雷达方向错误*/
    uint8_t         ucStatusValidNum;   /*雷达状态有效包个数*/
    uint8_t         ucSpeedValidNum;    /*雷达速度有效包个数*/
    uint8_t         ucDirValidNum;      /*雷达方向有效包个数*/
    uint32_t        uiMaxSpeed;         /*雷达报文中最大的速度*/
    uint32_t        uiMinSpeed;         /*雷达报文中最小的速度*/
    int32_t         iRawSpeed;          /*原始速度-mm/s*/
    int32_t         iMaxSpeed;         /*安全速度-mm/s*/
    int32_t         iRawMov;            /*原始周期位移-mm*/
    int32_t         iMaxMov;            /*最大周期位移-mm*/
    int32_t         iMinMov;            /*最小周期位移-mm*/
    int32_t         iFiltedAccel;       /*过滤加速度-mm/s^2*/
}DRDbgInfo_T;

/*测速传感器调试信息*/
typedef struct
{
    OPGDbgInfo_T    OPGDbgInfoA;           /*速度计A调试信息*/
    OPGDbgInfo_T    OPGDbgInfoB;           /*速度计B调试信息*/
    DRDbgInfo_T     DRDbgInfo;             /*雷达调试信息*/
}SSDbgInfo_T;

/*速度计原始数据*/
typedef struct
{
    BOOL        bRead;               /*有速度计包*/
    BOOL        bValid;              /*速度计故障标志 TRUE: 速度计发生故障    FALSE: 速度计工作正常*/
    int32_t     iPulseFreq0;         /*速度计通道0脉冲频率*/
    int32_t     iPulseFreq1;         /*速度计通道1脉冲频率*/
    uint32_t    uiPulseCnt0;         /*速度计通道0脉冲计数值*/
    uint32_t    uiPulseCnt1;         /*速度计通道1脉冲计数值*/
    int32_t     iMaxPulseDist;       /*最大脉冲距-um*/
    int32_t     iMinPulseDist;       /*最小脉冲距-um*/
    int32_t     iRawPulseDist;       /*原始脉冲距-um*/
} OPGRawData_T;

/*原始信标数据*/
typedef struct
{
    BOOL        bBcnRead;            /* 读到信标标志*/
    uint32_t    ulTimeStamp;         /* 过信标点时间戳 */
    uint32_t    ulTimeStampTol;      /* 过信标点时间戳容差 */
    uint32_t    uiOPGAFrozenCnt0;     /* 读取到信标时的速度传感器A通道0脉冲计数 */
    uint32_t    uiOPGAFrozenCnt1;     /* 读取到信标时的速度传感器A通道1脉冲计数 */
    uint32_t    uiOPGBFrozenCnt0;     /* 读取到信标时的速度传感器B通道0脉冲计数 */
    uint32_t    uiOPGBFrozenCnt1;     /* 读取到信标时的速度传感器B通道1脉冲计数 */
}BcnRawData_T;

/*雷达报文*/
typedef struct
{
    uint8_t     ucID;           /*报文包ID*/
    DRQality_E  Status;         /*DR status*/
    DRMode_E    Mode;           /*DR mode*/
    DRDir_E     Dir;            /*雷达检测到的运行方向*/
    uint16_t    usSpeed;        /*报文速度*/
    uint16_t    usOffset;       /*报文位移*/
    BOOL        bValid;         /*报文是否可用-后续判断*/
    int32_t     iSign;          /*计算速度的方向符号位-后续判断*/
} DRMsg_T;

/*雷达原始数据*/
typedef struct
{
    BOOL        bRead;          /*有雷达包*/
    BOOL        bMsgValid;      /*报文状态*/
    BOOL        bPulseValid;    /*脉冲状态*/
    uint8_t     ucMsgNum;       /*报文包个数*/
    uint32_t    uiPulseFreq;    /*脉冲频率*/
    uint32_t    uiPulseCount;   /*脉冲计数*/
    DRMsg_T     DRMsgAst[MAX_DR_PACKET]; /*报文结构体数组*/
} DRRawData_T;

/*测速测距输入数据*/
typedef struct
{
    uint32_t        uiTimeStamp;    /*周期时间戳-ms*/
    BcnRawData_T       BcnData;        /*信标信息*/
    OPGRawData_T    OPGRawDataA;    /*速度计A数据*/
    OPGRawData_T    OPGRawDataB;    /*速度计B数据*/
    DRRawData_T     DRRawData;      /*雷达数据*/
    SPDPolarity_E   Polarity;       /*测速极性*/
}SPDInput_T;

/*================================配置接口===================================*/
/**
 *  \brief 初始化:将测速所需的参数传递到测速单元
 *
 *  \param[in]  pParam  测速测距配置参数
 *  \retval     int32_t 初始化成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_Init(const SPDParam_T * const pParam);


/*================================主调接口===================================*/
/**
 *  \brief 周期性调用，进行测速测距信息更新
 *
 *  \param[in]  pSPDInput  测速测距输入数据
 *  \retval     int32_t    测速正常返回ATC_OK，故障返回ATC_ERROR
 */
int32_t SPD_Measure( SPDInput_T * const pSPDInput);

/*==============================距离获取接口=================================*/
/**
 *  \brief 获取周期的最大位移
 *
 *  \param[in][out]  pMaxMov  最大周期位移
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetMaxMov(int32_t * const pMaxMov);

/**
 *  \brief 获取周期的最小位移
 *
 *  \param[in][out]  pMinMov  最小周期位移
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetMinMov(int32_t * const pMinMov);

/**
 *  \brief 获取周期的原始位移
 *
 *  \param[in][out]  pRawMov  原始周期位移
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetRawMov(int32_t * const pRawMov);

/*==============================距离获取接口=================================*/
/**
 *  \brief 当本周期有新的定位信标时，通过此接口可获取到当前距此信标的位移
 *
 *  \param[in][out]  pDist2Bcn  到信标的距离
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetDst2Bcn(DistToBcn_T * const pDist2Bcn);

/*==============================速度获取接口=================================*/
/**
 *  \brief 获取最大速度
 *
 *  \param[in][out]  pMaxSpeed  最大速度
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetMaxSpeed(int32_t * const pMaxSpeed);

/**
 *  \brief 获取原始速度
 *
 *  \param[in][out]  pRawSpeed  原始速度
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetRawSpeed(int32_t * const pRawSpeed);

/**
 *  \brief 获取加速度
 *
 *  \param[in][out]  pAccel  加速度
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetAccel(int32_t * const pAccel);
/*==============================状态获取接口=================================*/
/**
 *  \brief 获取当前的状态：惰行、打滑、故障
 *         故障状态下，不应使用速度、距离等信息
 *  \param[in][out]  pState  测速状态
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetState(SPDState_E * const pState);

/**
 *  \brief 获取所有测速传感器的状态：可用、不可用、故障
 *
 *  \param[in][out]  pState  传感器状态
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_GetSensorState(SensorState_T * const pState);

/*==============================调试信息接口=================================*/
/**
 *  \brief 获取测速测距单元的错误码，可与码表定义进行错误定位
 *
 *  \param[in][out]  pErrorCode  错误码
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_DBG_GetErrorCode(uint32_t * const pErrorCode);

/**
 *  \brief 测速业务层的调试信息，获取测速逻辑方面的调试信息
 *
 *  \param[in][out]  pSPDDbgInfo  测速调试信息
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_DBG_GetSPDInfo(SPDDbgInfo_T *pSPDDbgInfo);

/**
 *  \brief 传感器级的调试信息，获取处理后的传感器信息
 *
 *  \param[in][out]  pSSDbgInfo  传感器调试信息
 *  \retval  int32_t  获取成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t SPD_DBG_GetSSInfo(SSDbgInfo_T *pSSDbgInfo);

#endif
