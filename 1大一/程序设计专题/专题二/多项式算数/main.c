#include "myheadfile.h"

struct terms *multihead1,*multihead2,*result;

int main(void) {

	int judge;
	do{
		printf("请选择数字：\n[1]计算多项式相加\n[2]计算多项式相减\n[3]计算多项式相乘\n[4]退出\n");
		scanf("%d",&judge);
		switch(judge){
			case 1:{
				printf("请输入多项式 1：");
				multihead1 = inputmultinomial();
				printf("请输入多项式 2：");
				multihead2 = inputmultinomial();
				result = multinomialplus(multihead1,multihead2);
				printmultinomial(result);
				multihead1->next=multihead2->next=result->next=NULL;
				break;
			}
			case 2:{
				printf("请输入多项式 1：");
				multihead1 = inputmultinomial();
				printf("请输入多项式 2：");
				multihead2 = inputmultinomial();
				result = multinomialsubtract(multihead1,multihead2);
				printmultinomial(result);
				multihead1->next=multihead2->next=result->next=NULL;
				break;
			}
			case 3:{
				printf("请输入多项式 1：");
				multihead1 = inputmultinomial();
				printf("请输入多项式 2：");
				multihead2 = inputmultinomial();
				result = multiplication(multihead1,multihead2);
				printmultinomial(result);
				multihead1->next=multihead2->next=result->next=NULL;
				break;
			}
			case 4:{
				printf("退出成功！");
				return 0;
			}
			default:{
				printf("输入不合法！请重新输入：\n");
				continue;
			}
		}		
	}while(1);
}
