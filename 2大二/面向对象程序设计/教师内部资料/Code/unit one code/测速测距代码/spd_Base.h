/** 
 * \brief     基本结构与公共函数定义
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_Base.h
 * 
 * 测速内部的基本结构与公共函数定义
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
#ifndef _SPD_BASE_H_INCLUDED_
#define _SPD_BASE_H_INCLUDED_

#include "Spd_lib.h"

#define     M_2_MM          1000            /*m到mm单位转换*/
#define     MM_2_UM         1000            /*mm到um单位转换*/
#define     S_2_MS          1000            /*s到ms单位转换*/
#define     NOP                             /*空*/
#define     RAW_SPEED_MAX_CYCLE   10        /*速度数组的最大长度*/
#define     RELOC_INFO_MAX_CYCLE  12        /*重定位信息数组的最大长度*/
#define     MAX_DR_PACK_NUM     20          /*每周期可能的最大雷达报文个数*/
#define     MAX_THEORY_SPEED    0x7FFFFFFF  /*理论最大速度*/
#define     MAX_THEORY_MOV      0x7FFFFFFF  /*理论最大位移*/
#define     MIN_THEORY_MOV      0x80000000  /*理论最小位移*/

#define U8BOUNDARY 256U /*8位无符号数溢出边界*/
#define MAX_U32 0xFFFFFFFFU /*最大的32位无符号数*/
#define MAX_I32 0x7FFFFFFF  /*最大的32位有符号数*/
#define ONE 1U   /*处理边界溢出时使用的1-例：0xFF+1=0*/

/*传感器输出信息*/
typedef struct
{
    int32_t            iMaxMov;        /*最大周期位移*/
    int32_t            iMinMov;        /*最小周期位移*/
    int32_t            iMaxSpeed;      /*最大速度*/
    int32_t            iRawMov;        /*原始周期位移*/
    int32_t            iRawSpeed;      /*原始速度*/
    int32_t            iFiltedAccel;   /*一段时间的过滤加速度*/
}SensorOutput_T;

/*传感器中间变量*/
typedef struct 
{    
    BOOL            bFirstCycle;        /*初始周期*/
    int32_t         iPreRawSpeed;       /*上周期原始速度*/
    int32_t         aiRawSpeed[RAW_SPEED_MAX_CYCLE];  /*原始速度数组*/
    int32_t         iPulseOneCycle;     /*周期内变化的原始脉冲数*/
    int32_t         iMaxPulseOneCycle;  /*周期内变化的最大脉冲数*/
    int32_t         iMinPulseOneCycle;  /*周期内变化的最小脉冲数*/
    int32_t         iMaxPulseFreq;         /*周期脉冲频率*/
    uint32_t        uiPulseCnt0;        /*最大累积脉冲数*/
    uint32_t        uiPulseCnt1;        /*最小累积脉冲数*/
    OPGRawData_T    PreOPGInput;        /*上周期OPG输入数据*/
} OPGInVars_T;

/*雷达调试信息*/
typedef struct  
{
    BOOL        bSerialFault;       /*报文序列号错误*/
    BOOL        bMoveDirNull;       /*报文方向错误*/
    uint8_t     ucStatusValidNum;   /*状态有效的报文个数*/
    uint8_t     ucSpeedValidNum;    /*速度有效的报文个数*/
    uint8_t     ucDirValidNum;      /*方向有效的报文个数*/
    uint8_t     ucHighQualityNum;   /*高质量的报文个数*/
    uint32_t    uiMaxSpeed;         /*原始报文中的最大速度*/
    uint32_t    uiMinSpeed;         /*原始报文中的最小速度*/
}DRDebug_T;

/*雷达中间变量*/
typedef struct 
{    
    BOOL        bFirstCycle;            /*初始化周期*/
    int32_t     iPreRawSpeed;           /*上周期原始速度*/
    uint8_t    ucPreMaxPacketID;       /*上周期最大序列号*/
    int32_t     DRSpeedArray[MAX_DR_PACK_NUM];   /*记录有效的雷达速度数组*/
    int32_t     aiRawSpeed[RAW_SPEED_MAX_CYCLE];  /*雷达周期原始速度数组*/
    BOOL        bHighQuality;           /*周期内变化的原始脉冲数*/
    DRDir_E     Dir;                    /*雷达方向*/
    uint32_t    uiPulseCnt;             /*雷达脉冲计数*/
    int32_t     iMinSpeed;              /*最小雷达速度*/
    DRDebug_T   DRDebug;                /*雷达调试信息*/
} DRInVars_T;

/*信标锁存数据*/
typedef struct
{
    BOOL        bBcnRead;               /*本周期读到信标标志*/
    uint32_t    uiOPGFrozenCnt0;     /*读取到信标时的速度传感器通道0脉冲计数 */
    uint32_t    uiOPGFrozenCnt1;     /*读取到信标时的速度传感器通道1脉冲计数 */
}BcnFrozonData_T;

/*速度计信息*/
typedef struct
{
    int32_t             iSign;          /*极性标志*/
    SensorState_E       Status;         /*传感器状态*/
    OPGRawData_T        OPGInput;       /*速度计输入数据*/
    BcnFrozonData_T     BcnFrozenData;  /*信标锁存数据*/
    OPGInVars_T         Vars;           /*速度计中间变量*/
    DistToBcn_T         Dist2Bcn;       /*到信标的距离*/
    SensorOutput_T      SpdDist;        /*速度计速度位移输出*/
} OPG_T;

/*雷达信息*/
typedef struct  
{
    SensorState_E       Status;         /*传感器状态*/
    DRRawData_T         Input;          /*雷达输入数据*/
    DRInVars_T          Vars;           /*雷达中间变量*/
    SensorOutput_T      SpdDist;        /*雷达速度距离输出*/
} Radar_T;

/*测速测距输出信息*/
typedef struct
{
    int32_t             iMaxMov;        /*最大周期位移-mm*/
    int32_t             iMinMov;        /*最小周期位移-mm*/
    int32_t             iRawMov;        /*原始周期位移-mm*/
    int32_t             iMaxSpeed;      /*安全速度-mm/s*/
    int32_t             iRawSpeed;      /*原始速度-mm/s*/
    int32_t             iAccel;         /*加速度-mm/s^2*/
    WheelStatus_E       Status;         /*车轮状态*/
    Sensor_E            Selected;       /*选用的传感器*/
    SPDState_E          State;          /*状态机状态*/
}Speed_T;

/*表决信息*/
typedef struct
{
    SensorState_E       Status;     /*传感器状态*/
    Sensor_E            Sensor;     /*传感器类型*/
    int32_t             iSpeed;     /*速度*/
    int32_t             iWeight;    /*权重*/
    int32_t             iFailTime;  /*表决失败时间，需同步-ms*/
}Vote_T;

/*重定位需寄存的信息*/
typedef struct
{
    uint32_t         uiTimeStamp;   /*周期时间戳-ms*/
    int32_t          iMaxSpeed;     /*安全速度-mm/s*/
    int32_t          iRawSpeed;     /*原始速度-mm/s*/
    int32_t          iMaxMov;       /*最大周期位移-mm*/
    int32_t          iMinMov;       /*最小周期位移-mm*/
    int32_t          iRawMov;       /*原始周期位移-mm*/
}RelocInfo_T;


/*状态机中间变量*/
typedef struct
{
    SPDState_E       Status;              /*状态机状态*/
    int32_t          iSlideTime;          /*打滑时间*/
    int32_t          iCoastTime;          /*惰行时间*/
    BOOL             bOPGRecover;         /*打滑的速度计恢复标志*/
    VoteRet_E        VoteRet;             /*表决结果*/
    Vote_T           VoteAst[3];          /*表决结构体数组*/
    int32_t          iVoteFailTime;       /*表决失败持续时间*/
    BOOL             bReloc;              /*可重定位标志*/
    RelocInfo_T      RelocInfo[RELOC_INFO_MAX_CYCLE];         /*重定位寄存信息结构体*/
}StateInVars_T;

/*信标信息*/
typedef struct
{
    BOOL        bBcnRead;           /*本周期读到信标标志*/
    uint32_t    ulRawTimeStamp;     /* 过信标点原始时间戳 */
    uint32_t    ulMaxTimeStamp;     /* 过信标点最大时间戳(考虑容差) */
    uint32_t    ulMinTimeStamp;     /* 过信标点最小时间戳(考虑容差) */
}BcnInfo_T;

/*状态机信息*/
typedef struct
{
    uint32_t        uiTimeStamp;    /*周期时间戳-ms*/
    BcnInfo_T       BcnInfo;        /*信标信息*/
    StateInVars_T   Vars;           /*状态机中间变量*/
    Speed_T         Speed;          /*测速测距输出*/
    DistToBcn_T     Dist2Bcn;       /*到信标的距离输出*/
}State_T;

/**
 *  \brief 将变量加入数组
 *
 *  \param[in]  iData  需要加入到数组的变量
 *  \param[in]  iSize 数组大小
 *  \param[in][out]  FIFO[] 加入的数组
 */
void Common_FIFOWrite(const int32_t iData, int32_t iSize, int32_t FIFO[] );

/**
 *  \brief 取两个无符号数据的差值uiValue2-uiValue1对应的有符号值，用于累计脉冲数等可能逐渐增加也可能逐渐减小的变量的计算
 *
 *  \param[in]  uiValue1  减数
 *  \param[in]  uiValue2  被减数
 *  \retval     int32_t   差值，uiValue2>=uiValue1返回uiValue2-uiValue1对应的有符号值，uiValue2<uiValue1返回卷绕后的差值对应的有符号值
 */
int32_t Common_Delta_Sign(uint32_t const uiValue1, uint32_t const uiValue2);

/**
 *  \brief 取两个无符号数据的差值uiValue2-uiValue1，考虑因溢出导致uiValue2<uiValue1的情况，用于序列号、时间戳等逐渐增加的变量的计算
 *
 *  \param[in]  uiValue1  减数
 *  \param[in]  uiValue2  被减数
 *  \retval     int32_t   差值，uiValue2>=uiValue1返回uiValue2-uiValue1，uiValue2<uiValue1返回卷绕后的差值
 */
int32_t Common_Delta_Unsign(uint32_t const uiValue1, uint32_t const uiValue2);

/**
 *  \brief 取iInput1和iInput2的较大值
 *
 *  \param[in]  iInput1  参与大小比较的参数1
 *  \param[in]  iInput2  参与大小比较的参数2
 *  \retval     int32_t  较大值，iInput1>=iInput2返回iInput1，iInput1<iInput2返回iInput2
 */
int32_t Common_MAX2( const int32_t iInput1, const int32_t iInput2 );

/**
 *  \brief 取iInput1和iInput2的较小值
 *
 *  \param[in]  iInput1  参与大小比较的参数1
 *  \param[in]  iInput2  参与大小比较的参数2
 *  \retval     int32_t  较小值，iInput1>=iInput2返回iInput2，iInput1<iInput2返回iInput1
 */
int32_t Common_MIN2( const int32_t iInput1, const int32_t iInput2 );

/**
 *  \brief 取绝对值
 *
 *  \param[in]  value  需要取绝对值的参数
 *  \retval     int32_t  绝对值，value>=0返回value，value<0返回-value
 */
int32_t Common_ABS( const int32_t value );

/**
 *  \brief Memset
 *
 *  \param[in][out]  pAddr  需要memset的空间首地址
 *  \param[in]  cValue   memset的初值
 *  \param[in]  uiSize   需要memset的空间大小
 */
void Common_Memset(void * const pAddr, const int8_t cValue, uint32_t uiSize);

/**
 *  \brief 判断iValue是否在[iMin, iMax]之间
 *
 *  \param[in]  iMin  最小范围
 *  \param[in]  iMax  最大范围
 *  \retval     BOOL  比较结果，在[iMin, iMax]内返回EN_TRUE，否则返回EN_FALSE
 */
BOOL Common_IsBetween(int32_t iValue, int32_t iMin, int32_t iMax);
#endif
