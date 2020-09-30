/** 
 * \brief     spd_State.c��ͷ�ļ�
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_State.h
 * 
 * ״̬����ص����ݡ���������
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */
#ifndef _SPD_STATE_H_
#define _SPD_STATE_H_

#include "Spd_Base.h"
#include "Spd_lib.h"

#define COAST_TIME_TO_RELOC 1500    /*�򻬺�1500ms�ڲ������ű��ض�λ*/
#define VOTE_NUM  3     /*�������*/
#define VOTE_2  2       /*���ͨ������2*/
#define VOTE_3  3       /*���ͨ������3*/

/*״̬�����ò���*/
typedef struct
{
    int32_t     iCycleTime;         /*��������ʱ��-ms*/
    int32_t     iVoteSpareTime;     /*�����������ͨ������ʱ��-ms*/
    int32_t     iVoteDeltaSpeed;    /*���������������ٶȲ�-mm/s*/
    int32_t     iSlideAccel;        /*���ж����ٶ�(С��˵����ֵ)-mm/s^2*/
    int32_t     iSlipAccel;         /*��ת�ж����ٶ�(��)-mm/s^2*/
    int32_t     iMaxSlideTime;      /*�򻬿���ʱ��-ms*/
    int32_t     iBcnMissTime;       /*�ű궪ʧ��ˡʱ��-ms*/
    int32_t     iBcnMissCycle;      /*�ű궪ʧ��ˡ����*/
} StateParam_T;

/**
 *  \brief ״̬����ʼ��
 *
 *  \param[in]  pParam  ״̬�����ò���
 *  \retval     int32_t ��ʼ���ɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t     State_Init(const SPDParam_T * const pParam);

/**
 *  \brief ״̬���������ݼ���
 *
 *  \param[in]  pSPDInput  ״̬����������
 *  \retval     int32_t �������ݼ��سɹ�����ATC_OK��ʧ�ܷ���ATC_ERROR
 */
int32_t     State_LoadInput( SPDInput_T * const pSPDInput);

/**
 *  \brief ״̬������
 *
 *  \retval     int32_t ״̬��ִ�гɹ�����ATC_OK�����ٹ��Ϸ���ATC_ERROR
 */
int32_t     State_Process();

/**
 *  \brief ����״̬����������
 *
 */
void        State_ResetVars(void);

/**
 *  \brief ����״̬�����
 *
 */
void        State_ResetOutput(void);
#endif
