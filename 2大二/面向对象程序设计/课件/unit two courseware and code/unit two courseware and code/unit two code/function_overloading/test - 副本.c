#include "SString.h"
#include "Drv.h"
#include "Stype.h"
#define PKT_PRI_LOW  (1)  /*低优先级数据*/
#define PKT_PRI_MID  (2)  /*中优先级数据*/
#define PKT_PRI_HIGH (3)  /*高优先级数据*/
#define PKT_USERDATA_MAX (232) /*最大用户数据字节数*/
#define PKT_HEAD_LEN (4) /*报文头长度4个字节*/
#define PKT_TOTAL_LAN_MAX (4+232)  /*报文最大长度*/

/** \从下层接收数据，如检查消息类型和序号的结果为正确，则将用户数据上传给用户，否则返回错误值。该函数由接收数据的用户调用。
 *
 *  \param [in]   ulMaxDataLen    用户接收数据的缓存最大长度
 *  \param [out]  pucMsgType      接收到的消息类型
 *  \param [out]  pulUserDataLen  用户接收数据的实际长度
 *  \param [out]  pucUserDataBuf  用户数据的起始地址
 *  \retval S_OK                  接收过程没有错误
 *  \retval 除S_OK外的其他值       接收过程中发生的错误
 */
int32_t PKT_ReceiveUserData(uint32_t ulMaxDataLen, 
uint8_t *pucMsgType, uint32_t *pulUserDataLen, uint8_t *pucUserDataBuf)
{
	int32_t lRet = S_OK;
	uint8_t aucBuf[PKT_TOTAL_LAN_MAX] = {0u};  /*接收数据缓冲区*/
	uint8_t ucType = 0u;      /*接收到的消息类型*/
	uint8_t ulDataLen = 0u;  /*实际接收的数据长度*/
	uint8_t ulUserDataLen = 0u;  /*用户数据长度*/
	uint16_t ucSeq = 0u;

	/*入参检查*/
	if (null==pucMsgType || null==pulUserDataLen || null==pucUserDataBuf)
	{
		lRet = S_ERROR;
	}
	else
	{
		lRet = DRV_Receive(PKT_TOTAL_LAN_MAX,&ulDataLen,aucBuf);
		/*DRV_Receive函数返回值检查*/
		if (lRet!=S_OK || ulDataLen>PKT_TOTAL_LAN_MAX || ulDataLen<PKT_HEAD_LEN)
		{
			lRet = S_ERROR;
		}
		else
		{
			/*消息类型检查*/
			ucType = aucBuf[0];
			if (ucType!=PKT_PRI_LOW && ucType!=PKT_PRI_MID && ucType!=PKT_PRI_HIGH)
			{
				lRet = S_ERROR;
			}
			else
			{		
			    /*消息长度等于或小于DRV_Receive函数获取的长度-4；消息中长度小于等于232*/
			    ulUserDataLen = aucBuf[3]; 
			    if (ulUserDataLen > PKT_USERDATA_MAX)
			    {
				    lRet = S_ERROR;
			    }
			    else
			    { 
			       /*消息序号转换字节序*/
			       ucSeq = S_ntohs((uint16_t)(*aucBuf[1]));
			       if (ucSeq中包序号不正确) 
				   {
				       lRet = S_ERROR;
			       }
			       else
			       {
				       /*消息类型赋值出参*/
				       *pucMsgType = ucType;
				       /*消息长度赋值出参*/
				       *pulUserDataLen = ulDataLen - 4;
				       /*消息内容赋值出参*/
				       S_MemCpy(pucUserDataBuf,aucBuf+4, ulDataLen - 4);
					   lRet = S_OK;
				   }
				}
			}
		}
	}
	return lRet;
}