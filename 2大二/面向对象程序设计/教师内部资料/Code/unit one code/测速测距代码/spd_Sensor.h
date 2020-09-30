/** 
 * \brief     spd_Sensor.c的头文件
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_Sensor.h
 * 
 * 传感器相关的数据、函数定义
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
#ifndef _SENSOR_H_INCLUDED_
#define _SENSOR_H_INCLUDED_

#include "Spd_Base.h"

#define    OPG_DELTA_FREQ_BETWEEN_2CH  11  /*速度计双通道数据之间允许的频率差*/
#define    MAX_DELTA_PULSE_CNT  10000   /*最大的脉冲变化个数*/

#define    RADAR_SPEED_LSB 9155         /*雷达报文速度使用的单位-1LBS=0.009155km/h*/
#define    MMPS_2_KPH 3600              /*mm/s到km/h的转换单位*/

#define MAX_DR_SPEED  27777           /*最大雷达速度mm/s*/
#define DR_SPEED_ZVI        (((3*M_2_MM)*M_2_MM)/RADAR_SPEED_LSB)     /*雷达速度报文DR_SPEED_ZVI以内允许方向为NULL-mm/s*/

#define DR_DATA_CYCLE 10             /*雷达报文发送周期-ms*/
#define RAW_PACK_PERCENT 80          /*原始包占理论包个数的百分比*/
#define VALID_PACK_PERCENT 60        /*可用包占理论包个数的百分比*/

#define MAX_DELTA_DR_INDEX 60U          /*两个雷达包序列号的最大差*/

#define SS_2  2       /*可用个数2*/
#define SS_3  3       /*可用个数3*/

#define SIGN_PLUS  1    /*测速传感器标志-正*/
#define SIGN_MINUS  -1   /*测速传感器标志-负*/
#define SIGN_ZERO  0    /*测速传感器标志-零*/

#define MIN_CNT 1   /*最小个数计数*/
#define PERSENT_BASE  100   /*百分比基数*/

/*传感器配置参数*/
typedef struct
{
    int32_t  iCycleTime;            /*测速周期时间-ms*/
    int32_t  iMaxDRError;           /*雷达测速误差*/
    int32_t  iMaxAccel;             /*列车最大加速度*/
    int32_t  iAccelFiltedTime;      /*过滤加速度计算时间*/
    int32_t  iAccelFiltedCycle;     /*实际计算过滤加速度时的周期数*/

    int32_t     iDRMaxSpeed;        /*最大雷达速度*/
    int32_t     iDRDeltaSpeed;      /*每周期可能变化的最大雷达速度*/

    int32_t  iDRMaxPack;            /*每周期收到的最大雷达报文个数*/
    int32_t  iDRMinPack;            /*每周期收到的最小雷达报文个数*/
    int32_t  iDRMinValidPack;       /*每周期收到的最小有效雷达报文个数*/
} SS_PARAM_T;

/**
 *  \brief 传感器初始化
 *
 *  \param[in]  pParam  传感器配置参数
 *  \retval     int32_t 初始化成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t     Sensor_Init(const SPDParam_T * const pParam);

/**
 *  \brief 传感器信息处理
 *
 */
void        Sensor_Process(void);

/**
 *  \brief 传感器输入数据加载并校验
 *
 *  \param[in]  pSPDInput  传感器输入数据
 *  \retval     int32_t 输入数据加载并校验成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t     Sensor_LoadInput(SPDInput_T * const pSPDInput);

/**
 *  \brief 重置传感器周期数据
 *
 */
void        Sensor_ResetVars(void);

/**
 *  \brief 重置传感器输出
 *
 */
void        Sensor_ResetOutput(void);

#endif
