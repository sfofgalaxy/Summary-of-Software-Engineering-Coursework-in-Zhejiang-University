/** 
 * \brief     spd_Sensor.c��ͷ�ļ�
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_Sensor.h
 * 
 * ��������ص����ݡ���������
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
#ifndef _SENSOR_H_INCLUDED_
#define _SENSOR_H_INCLUDED_

#include "Spd_Base.h"

#define    OPG_DELTA_FREQ_BETWEEN_2CH  11  /*�ٶȼ�˫ͨ������֮�������Ƶ�ʲ�*/
#define    MAX_DELTA_PULSE_CNT  10000   /*��������仯����*/

#define    RADAR_SPEED_LSB 9155         /*�״ﱨ���ٶ�ʹ�õĵ�λ-1LBS=0.009155km/h*/
#define    MMPS_2_KPH 3600              /*mm/s��km/h��ת����λ*/

#define MAX_DR_SPEED  27777           /*����״��ٶ�mm/s*/
#define DR_SPEED_ZVI        (((3*M_2_MM)*M_2_MM)/RADAR_SPEED_LSB)     /*�״��ٶȱ���DR_SPEED_ZVI����������ΪNULL-mm/s*/

#define DR_DATA_CYCLE 10             /*�״ﱨ�ķ�������-ms*/
#define RAW_PACK_PERCENT 80          /*ԭʼ��ռ���۰������İٷֱ�*/
#define VALID_PACK_PERCENT 60        /*���ð�ռ���۰������İٷֱ�*/

#define MAX_DELTA_DR_INDEX 60U          /*�����״�����кŵ�����*/

#define SS_2  2       /*���ø���2*/
#define SS_3  3       /*���ø���3*/

#define SIGN_PLUS  1    /*���ٴ�������־-��*/
#define SIGN_MINUS  -1   /*���ٴ�������־-��*/
#define SIGN_ZERO  0    /*���ٴ�������־-��*/

#define MIN_CNT 1   /*��С��������*/
#define PERSENT_BASE  100   /*�ٷֱȻ���*/

/*���������ò���*/
typedef struct
{
    int32_t  iCycleTime;            /*��������ʱ��-ms*/
    int32_t  iMaxDRError;           /*�״�������*/
    int32_t  iMaxAccel;             /*�г������ٶ�*/
    int32_t  iAccelFiltedTime;      /*���˼��ٶȼ���ʱ��*/
    int32_t  iAccelFiltedCycle;     /*ʵ�ʼ�����˼��ٶ�ʱ��������*/

    int32_t     iDRMaxSpeed;        /*����״��ٶ�*/
    int32_t     iDRDeltaSpeed;      /*ÿ���ڿ��ܱ仯������״��ٶ�*/

    int32_t  iDRMaxPack;            /*ÿ�����յ�������״ﱨ�ĸ���*/
    int32_t  iDRMinPack;            /*ÿ�����յ�����С�״ﱨ�ĸ���*/
    int32_t  iDRMinValidPack;       /*ÿ�����յ�����С��Ч�״ﱨ�ĸ���*/
} SS_PARAM_T;

/**
 *  \brief ��������ʼ��
 *
 *  \param[in]  pParam  ���������ò���
 *  \retval     int32_t ��ʼ���ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t     Sensor_Init(const SPDParam_T * const pParam);

/**
 *  \brief ��������Ϣ����
 *
 */
void        Sensor_Process(void);

/**
 *  \brief �������������ݼ��ز�У��
 *
 *  \param[in]  pSPDInput  ��������������
 *  \retval     int32_t �������ݼ��ز�У��ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t     Sensor_LoadInput(SPDInput_T * const pSPDInput);

/**
 *  \brief ���ô�������������
 *
 */
void        Sensor_ResetVars(void);

/**
 *  \brief ���ô��������
 *
 */
void        Sensor_ResetOutput(void);

#endif
