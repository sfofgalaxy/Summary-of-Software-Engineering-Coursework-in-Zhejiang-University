/** 
 * \brief     spd_State.c的头文件
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_State.h
 * 
 * 状态机相关的数据、函数定义
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
#ifndef _SPD_STATE_H_
#define _SPD_STATE_H_

#include "Spd_Base.h"
#include "Spd_lib.h"

#define COAST_TIME_TO_RELOC 1500    /*打滑后1500ms内不能用信标重定位*/
#define VOTE_NUM  3     /*表决个数*/
#define VOTE_2  2       /*表决通过个数2*/
#define VOTE_3  3       /*表决通过个数3*/

/*状态机配置参数*/
typedef struct
{
    int32_t     iCycleTime;         /*测速周期时间-ms*/
    int32_t     iVoteSpareTime;     /*传感器表决不通过宽限时间-ms*/
    int32_t     iVoteDeltaSpeed;    /*传感器表决允许的速度差-mm/s*/
    int32_t     iSlideAccel;        /*打滑判定加速度(小明说：负值)-mm/s^2*/
    int32_t     iSlipAccel;         /*空转判定加速度(正)-mm/s^2*/
    int32_t     iMaxSlideTime;      /*打滑宽限时间-ms*/
    int32_t     iBcnMissTime;       /*信标丢失宽恕时间-ms*/
    int32_t     iBcnMissCycle;      /*信标丢失宽恕周期*/
} StateParam_T;

/**
 *  \brief 状态机初始化
 *
 *  \param[in]  pParam  状态机配置参数
 *  \retval     int32_t 初始化成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t     State_Init(const SPDParam_T * const pParam);

/**
 *  \brief 状态机输入数据加载
 *
 *  \param[in]  pSPDInput  状态机输入数据
 *  \retval     int32_t 输入数据加载成功返回ATC_OK，失败返回ATC_ERROR
 */
int32_t     State_LoadInput( SPDInput_T * const pSPDInput);

/**
 *  \brief 状态机处理
 *
 *  \retval     int32_t 状态机执行成功返回ATC_OK，测速故障返回ATC_ERROR
 */
int32_t     State_Process();

/**
 *  \brief 重置状态机周期数据
 *
 */
void        State_ResetVars(void);

/**
 *  \brief 重置状态机输出
 *
 */
void        State_ResetOutput(void);
#endif
