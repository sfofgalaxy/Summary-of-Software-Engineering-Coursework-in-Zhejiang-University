#include "myheadfile.h"

struct terms *multihead1,*multihead2,*result;

int main(void) {

	int judge;
	do{
		printf("��ѡ�����֣�\n[1]�������ʽ���\n[2]�������ʽ���\n[3]�������ʽ���\n[4]�˳�\n");
		scanf("%d",&judge);
		switch(judge){
			case 1:{
				printf("���������ʽ 1��");
				multihead1 = inputmultinomial();
				printf("���������ʽ 2��");
				multihead2 = inputmultinomial();
				result = multinomialplus(multihead1,multihead2);
				printmultinomial(result);
				multihead1->next=multihead2->next=result->next=NULL;
				break;
			}
			case 2:{
				printf("���������ʽ 1��");
				multihead1 = inputmultinomial();
				printf("���������ʽ 2��");
				multihead2 = inputmultinomial();
				result = multinomialsubtract(multihead1,multihead2);
				printmultinomial(result);
				multihead1->next=multihead2->next=result->next=NULL;
				break;
			}
			case 3:{
				printf("���������ʽ 1��");
				multihead1 = inputmultinomial();
				printf("���������ʽ 2��");
				multihead2 = inputmultinomial();
				result = multiplication(multihead1,multihead2);
				printmultinomial(result);
				multihead1->next=multihead2->next=result->next=NULL;
				break;
			}
			case 4:{
				printf("�˳��ɹ���");
				return 0;
			}
			default:{
				printf("���벻�Ϸ������������룺\n");
				continue;
			}
		}		
	}while(1);
}
