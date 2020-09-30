/** 
 * \brief     公共函数
 * \copyright 1999-2014, Zhejiang United Electronic Industry Co.,Ltd.
 * \author    Xiaojing Yang
 * \file      Spd_base.c
 * 
 * 测速公共函数实现
 * 
 *    
 * \date 2014/01/08  Xiaojing Yang: created
 *
 */

#include "Spd_lib.h"
#include "Spd_Base.h"

/*******************************************************************************/
/* Function:  Common_FIFOWrite*/
/* Brief:      将参数加入数组*/
/* Param:     const int32_t iData  需加入的参数*/
/* Param:     int32_t iSize  数组大小*/
/* Param:     int32_t FIFO[]  数组*/
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
/* Brief:     获取uiValue2-uiValue1的差值对应的有符号值(考虑溢出时的差值)*/
/* Param:     uint32_t const uiValue1  减数*/
/* Param:     uint32_t const uiValue2  被减数*/
/* RetVal:    int32_t  差值*/
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
/* Brief:     获取uiValue2-uiValue1的差值(无符号，考虑因溢出导致uiValue2<uiValue1的情况)*/
/* Param:     uint32_t const uiValue1  减数*/
/* Param:     uint32_t const uiValue2  被减数*/
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
/* Brief:      取2个值的较大值*/
/* Param:     const int32_t iInput1  参数1*/
/* Param:     const int32_t iInput2  参数2*/
/* RetVal:    int32_t  较大值*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/8*/
/*******************************************************************************/
int32_t Common_MAX2( const int32_t iInput1, const int32_t iInput2 )
{
    return ((iInput1 >= iInput2) ? iInput1 : iInput2);
}

/*******************************************************************************/
/* Function:  Common_MIN2*/
/* Brief:      取2个值的较小值*/
/* Param:     const int32_t iInput1  参数1*/
/* Param:     const int32_t iInput2  参数2*/
/* RetVal:    int32_t  较小值*/
/* Author:    Xiaojing Yang*/
/* Date:      2014/1/8*/
/*******************************************************************************/
int32_t Common_MIN2( const int32_t iInput1, const int32_t iInput2 )
{
    return ((iInput1 >= iInput2) ? iInput2 : iInput1);
}

/*******************************************************************************/
/* Function:  Common_ABS*/
/* Brief:      取绝对值*/
/* Param:     const int32_t value  参数*/
/* RetVal:    int32_t  绝对值*/
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
/* Param:     void * const pAddr  初始化的空间首地址*/
/* Param:     const int8_t cValue  初始化的初值*/
/* Param:     uint32_t uiSize  初始化的空间大小*/
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
/* Brief:     判断iValue是否在[iMin, iMax]之间*/
/* Param:     int32_t iValue  参数*/
/* Param:     int32_t iMin  最小范围*/
/* Param:     int32_t iMax  最大范围*/
/* RetVal:    BOOL 在[iMin, iMax]内返回EN_TRUE，否则返回EN_FALSE*/
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
