/** 
 * \brief     ��������
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_base.c
 * 
 * ���ٹ�������ʵ��
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */

#include "Spd_lib.h"
#include "Spd_Base.h"

/*******************************************************************************/
/* Function:  Common_FIFOWrite*/
/* Brief:      ��������������*/
/* Param:     const int32_t iData  �����Ĳ���*/
/* Param:     int32_t iSize  �����С*/
/* Param:     int32_t FIFO[]  ����*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
void Common_FIFOWrite(const int32_t iData, int32_t iSize, int32_t FIFO[] )
{
    /*initial the variable point the end member of the array*/
    int32_t    index = iSize - 1; 
    /*shift the member in the array by one and clear the first member of the memory*/
    for (; index > 0; index--)
    {
        FIFO[index] = FIFO[index-1];
    }
    /*push the new member into the array*/
    FIFO[index] = iData;
}

/*******************************************************************************/
/* Function:  Common_Delta_Sign*/
/* Brief:     ��ȡuiValue2-uiValue1�Ĳ�ֵ��Ӧ���з���ֵ(�������ʱ�Ĳ�ֵ)*/
/* Param:     uint32_t const uiValue1  ����*/
/* Param:     uint32_t const uiValue2  ������*/
/* RetVal:    int32_t  ��ֵ*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/7*/
/*******************************************************************************/
int32_t Common_Delta_Sign(uint32_t const uiValue1, uint32_t const uiValue2)
{
    uint32_t delta_value = 0U;
    if (uiValue1 <= uiValue2)
    {
        delta_value = uiValue2 - uiValue1;
    }
    else
    {
        delta_value = (MAX_U32 - uiValue1) + uiValue2 + ONE;
    }
    return (int32_t)(delta_value);
}

/*******************************************************************************/
/* Function:  Common_Delta_Unsign*/
/* Brief:     ��ȡuiValue2-uiValue1�Ĳ�ֵ(�޷��ţ��������������uiValue2<uiValue1�����)*/
/* Param:     uint32_t const uiValue1  ����*/
/* Param:     uint32_t const uiValue2  ������*/
/* RetVal:    int32_t*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/2/8*/
/*******************************************************************************/
int32_t Common_Delta_Unsign(uint32_t const uiValue1, uint32_t const uiValue2)
{
    uint32_t delta_value = 0U;
    if (uiValue1 <= uiValue2)
    {
        delta_value = uiValue2 - uiValue1;
    }
    else
    {
        delta_value = (MAX_U32 - uiValue1) + uiValue2 + ONE;
    }
    return delta_value;
}

/*******************************************************************************/
/* Function:  Common_MAX2*/
/* Brief:      ȡ2��ֵ�Ľϴ�ֵ*/
/* Param:     const int32_t iInput1  ����1*/
/* Param:     const int32_t iInput2  ����2*/
/* RetVal:    int32_t  �ϴ�ֵ*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/8*/
/*******************************************************************************/
int32_t Common_MAX2( const int32_t iInput1, const int32_t iInput2 )
{
    return ((iInput1 >= iInput2) ? iInput1 : iInput2);
}

/*******************************************************************************/
/* Function:  Common_MIN2*/
/* Brief:      ȡ2��ֵ�Ľ�Сֵ*/
/* Param:     const int32_t iInput1  ����1*/
/* Param:     const int32_t iInput2  ����2*/
/* RetVal:    int32_t  ��Сֵ*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/8*/
/*******************************************************************************/
int32_t Common_MIN2( const int32_t iInput1, const int32_t iInput2 )
{
    return ((iInput1 >= iInput2) ? iInput2 : iInput1);
}

/*******************************************************************************/
/* Function:  Common_ABS*/
/* Brief:      ȡ����ֵ*/
/* Param:     const int32_t value  ����*/
/* RetVal:    int32_t  ����ֵ*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/8*/
/*******************************************************************************/
int32_t Common_ABS( const int32_t value )
{
    return ((value > 0) ? value : (-value));
}

/*******************************************************************************/
/* Function:  Common_Memset*/
/* Brief:      memset*/
/* Param:     void * const pAddr  ��ʼ���Ŀռ��׵�ַ*/
/* Param:     const int8_t cValue  ��ʼ���ĳ�ֵ*/
/* Param:     uint32_t uiSize  ��ʼ���Ŀռ��С*/
/* RetVal:    void*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/8*/
/*******************************************************************************/
void Common_Memset(void * const pAddr, const int8_t cValue, uint32_t uiSize)
{
    int8_t *pcaddr = ATC_NULL;
    if (ATC_NULL != pAddr)
    {
        pcaddr = (int8_t*)(pAddr);    /* start address of the array*/
        while ( uiSize > 0U )
        {
            *pcaddr = cValue;    /* set cValue to pcaddr*/

            uiSize--;
            pcaddr++;
        }
    }
}

/*******************************************************************************/
/* Function:  Common_IsBetween*/
/* Brief:     �ж�iValue�Ƿ���[iMin, iMax]֮��*/
/* Param:     int32_t iValue  ����*/
/* Param:     int32_t iMin  ��С��Χ*/
/* Param:     int32_t iMax  ���Χ*/
/* RetVal:    BOOL ��[iMin, iMax]�ڷ���EN_TRUE�����򷵻�EN_FALSE*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/17*/
/*******************************************************************************/
BOOL Common_IsBetween(int32_t iValue, int32_t iMin, int32_t iMax)
{
    BOOL ret = EN_FALSE;
    if ((iValue >= iMin) && (iValue <= iMax))
    {
        ret = EN_TRUE;
    }
    return ret;
}
