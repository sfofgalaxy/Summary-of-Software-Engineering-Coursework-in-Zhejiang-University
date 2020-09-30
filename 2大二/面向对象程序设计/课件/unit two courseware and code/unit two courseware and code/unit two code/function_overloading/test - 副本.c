#include "SString.h"
#include "Drv.h"
#include "Stype.h"
#define PKT_PRI_LOW  (1)  /*�����ȼ�����*/
#define PKT_PRI_MID  (2)  /*�����ȼ�����*/
#define PKT_PRI_HIGH (3)  /*�����ȼ�����*/
#define PKT_USERDATA_MAX (232) /*����û������ֽ���*/
#define PKT_HEAD_LEN (4) /*����ͷ����4���ֽ�*/
#define PKT_TOTAL_LAN_MAX (4+232)  /*������󳤶�*/

/** \���²�������ݣ�������Ϣ���ͺ���ŵĽ��Ϊ��ȷ�����û������ϴ����û������򷵻ش���ֵ���ú����ɽ������ݵ��û����á�
 *
 *  \param [in]   ulMaxDataLen    �û��������ݵĻ�����󳤶�
 *  \param [out]  pucMsgType      ���յ�����Ϣ����
 *  \param [out]  pulUserDataLen  �û��������ݵ�ʵ�ʳ���
 *  \param [out]  pucUserDataBuf  �û����ݵ���ʼ��ַ
 *  \retval S_OK                  ���չ���û�д���
 *  \retval ��S_OK�������ֵ       ���չ����з����Ĵ���
 */
int32_t PKT_ReceiveUserData(uint32_t ulMaxDataLen, 
uint8_t *pucMsgType, uint32_t *pulUserDataLen, uint8_t *pucUserDataBuf)
{
	int32_t lRet = S_OK;
	uint8_t aucBuf[PKT_TOTAL_LAN_MAX] = {0u};  /*�������ݻ�����*/
	uint8_t ucType = 0u;      /*���յ�����Ϣ����*/
	uint8_t ulDataLen = 0u;  /*ʵ�ʽ��յ����ݳ���*/
	uint8_t ulUserDataLen = 0u;  /*�û����ݳ���*/
	uint16_t ucSeq = 0u;

	/*��μ��*/
	if (null==pucMsgType || null==pulUserDataLen || null==pucUserDataBuf)
	{
		lRet = S_ERROR;
	}
	else
	{
		lRet = DRV_Receive(PKT_TOTAL_LAN_MAX,&ulDataLen,aucBuf);
		/*DRV_Receive��������ֵ���*/
		if (lRet!=S_OK || ulDataLen>PKT_TOTAL_LAN_MAX || ulDataLen<PKT_HEAD_LEN)
		{
			lRet = S_ERROR;
		}
		else
		{
			/*��Ϣ���ͼ��*/
			ucType = aucBuf[0];
			if (ucType!=PKT_PRI_LOW && ucType!=PKT_PRI_MID && ucType!=PKT_PRI_HIGH)
			{
				lRet = S_ERROR;
			}
			else
			{		
			    /*��Ϣ���ȵ��ڻ�С��DRV_Receive������ȡ�ĳ���-4����Ϣ�г���С�ڵ���232*/
			    ulUserDataLen = aucBuf[3]; 
			    if (ulUserDataLen > PKT_USERDATA_MAX)
			    {
				    lRet = S_ERROR;
			    }
			    else
			    { 
			       /*��Ϣ���ת���ֽ���*/
			       ucSeq = S_ntohs((uint16_t)(*aucBuf[1]));
			       if (ucSeq�а���Ų���ȷ) 
				   {
				       lRet = S_ERROR;
			       }
			       else
			       {
				       /*��Ϣ���͸�ֵ����*/
				       *pucMsgType = ucType;
				       /*��Ϣ���ȸ�ֵ����*/
				       *pulUserDataLen = ulDataLen - 4;
				       /*��Ϣ���ݸ�ֵ����*/
				       S_MemCpy(pucUserDataBuf,aucBuf+4, ulDataLen - 4);
					   lRet = S_OK;
				   }
				}
			}
		}
	}
	return lRet;
}