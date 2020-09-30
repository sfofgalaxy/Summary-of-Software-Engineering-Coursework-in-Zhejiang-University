#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ȫ���ַ����飬����onelineΪ�����ָ���ַ�����outputΪ����Ļ������ַ���
char oneline[50];
char output[40];

//����ָ�� enum
enum operation
{
	//100000,100100,100101,000000,101010,100010
	add, and, or , sll, slt, sub,//R-type
	//001000,001100,001101,001010
	addi, andi, ori, slti,//I-type
	move,//peseudo
	erroroperation//error
};

//�Ĵ��� enum
enum rigister
{
	$zero, $v0, $v1, $a0, $a1, $a2, $a3,
	$t0, $t1, $t2, $t3, $t4, $t5, $t6, $t7,
	$s0, $s1, $s2, $s3, $s4, $s5, $s6, $s7,
	$sp, $ra, errorrigister
};

//���Ĵ����ַ���ת��Ϊenum
enum rigister transrig(char *p)
{
	if (!strcmp(p, "$zero"))return $zero;
	else if (!strcmp(p, "$v0"))return $v0;
	else if (!strcmp(p, "$v1"))return $v1;
	else if (!strcmp(p, "$a0"))return $a0;
	else if (!strcmp(p, "$a1"))return $a1;
	else if (!strcmp(p, "$a2"))return $a2;
	else if (!strcmp(p, "$a3"))return $a3;
	else if (!strcmp(p, "$s0"))return $s0;
	else if (!strcmp(p, "$s1"))return $s1;
	else if (!strcmp(p, "$s2"))return $s2;
	else if (!strcmp(p, "$s3"))return $s3;
	else if (!strcmp(p, "$s4"))return $s4;
	else if (!strcmp(p, "$s5"))return $s5;
	else if (!strcmp(p, "$s6"))return $s6;
	else if (!strcmp(p, "$s7"))return $s7;
	else if (!strcmp(p, "$t0"))return $t0;
	else if (!strcmp(p, "$t1"))return $t1;
	else if (!strcmp(p, "$t2"))return $t2;
	else if (!strcmp(p, "$t3"))return $t3;
	else if (!strcmp(p, "$t4"))return $t4;
	else if (!strcmp(p, "$t5"))return $t5;
	else if (!strcmp(p, "$t6"))return $t6;
	else if (!strcmp(p, "$t7"))return $t7;
	else if (!strcmp(p, "$sp"))return $sp;
	else if (!strcmp(p, "$ra"))return $ra;
	else return errorrigister;
}

//������ָ���ַ���ת��Ϊenum
enum operation compare(char *p)
{
	if (!strcmp(p, "add"))return add;
	else if (!strcmp(p, "and"))return and;
	else if (!strcmp(p, "or"))return or ;
	else if (!strcmp(p, "sll"))return sll;
	else if (!strcmp(p, "slt"))return slt;
	else if (!strcmp(p, "sub"))return sub;
	else if (!strcmp(p, "addi"))return addi;
	else if (!strcmp(p, "andi"))return andi;
	else if (!strcmp(p, "ori"))return ori;
	else if (!strcmp(p, "slti"))return slti;
	else if (!strcmp(p, "move"))return move;
	else return erroroperation;
}

//���ַ���ʮ�������ַ���תΪ�������ַ���
void transimmediate(char *str)
{
	int temp, digit;
	char str_temp[17];
	temp = atoi(str);
	itoa(temp, str_temp, 2);
	for (digit = 0; str_temp[digit]; digit++);
	for (int i = 16; i < 32 - digit; i++)output[i] = '0';
	for (int i = 32 - digit; i < 32; i++)output[i] = str_temp[i - 32 + digit];
	return;
}

//ת������mipsָ��  �����д���ͷ���0
int transfer()
{
	char *fragment;
	char operate[10];
	char temp[10];
	int times = 1;//��¼�ôδ������һ���еĿո�����ĵ�times������

	//��strtok���������ַ����ָ�
	fragment = strtok(oneline, " ");
	strcpy(operate, fragment);
	output[32] = 0;

	//�������ģ���ָ��ת���ɻ�����
	while (fragment)
	{
		if (times == 1)
		{
			if ((add <= compare(operate)) && (compare(operate) <= sub) || (compare(operate)==move))//R-typy
			{
				for (int i = 0; i < 6; i++)output[i] = '0';
				for (int i = 21; i < 26; i++)output[i] = '0';
				switch (compare(operate)) {
				case add:
				case move:
					output[26] = '1';
					for (int i = 27; i < 32; i++)output[i] = '0';
					break;
				case and:
					output[26] = '1';
					output[27] = '0';
					output[28] = '0';
					output[29] = '1';
					output[30] = '0';
					output[31] = '0';
					break;
				case or :
					output[26] = '1';
					output[27] = '0';
					output[28] = '0';
					output[29] = '1';
					output[30] = '0';
					output[31] = '1';
					break;
				case sll:
					for (int i = 25; i < 32; i++)output[i] = '0';
					break;
				case slt:
					output[26] = '1';
					output[27] = '0';
					output[28] = '1';
					output[29] = '0';
					output[30] = '1';
					output[31] = '0';
					break;
				case sub:
					output[26] = '1';
					output[27] = '0';
					output[28] = '0';
					output[29] = '0';
					output[30] = '1';
					output[31] = '0';
					break;
				}
			}
			else if ((addi <= compare(operate)) && (compare(operate) <= slti))//I-type
			{
				switch (compare(operate))
				{
				case addi:
					output[0] = '0';
					output[1] = '0';
					output[2] = '1';
					output[3] = '0';
					output[4] = '0';
					output[5] = '0';
					break;
				case andi:
					output[0] = '0';
					output[1] = '0';
					output[2] = '1';
					output[3] = '1';
					output[4] = '0';
					output[5] = '0';
					break;
				case ori:
					output[0] = '0';
					output[1] = '0';
					output[2] = '1';
					output[3] = '1';
					output[4] = '0';
					output[5] = '1';
					break;
				case slti:
					output[0] = '0';
					output[1] = '0';
					output[2] = '1';
					output[3] = '0';
					output[4] = '1';
					output[5] = '0';
					break;
				default:
					break;
				}
			}
			else//����
			{
				return 0;
			}
		}
		else if ((times >= 2) && (times <= 4))
		{
			if (!((compare(operate)>=addi) && (compare(operate) <= slti) && times == 4))
			{
				switch (transrig(fragment))
				{
				case $zero:
					strcpy(temp, "00000");
					break;
				case $v0:
					strcpy(temp, "00010");
					break;
				case $v1:
					strcpy(temp, "00011");
					break;
				case $a0:
					strcpy(temp, "00100");
					break;
				case $a1:
					strcpy(temp, "00101");
					break;
				case $a2:
					strcpy(temp, "00110");
					break;
				case $a3:
					strcpy(temp, "00111");
					break;
				case $t0:
					strcpy(temp, "01000");
					break;
				case $t1:
					strcpy(temp, "01001");
					break;
				case $t2:
					strcpy(temp, "01010");
					break;
				case $t3:
					strcpy(temp, "01011");
					break;
				case $t4:
					strcpy(temp, "01100");
					break;
				case $t5:
					strcpy(temp, "01101");
					break;
				case $t6:
					strcpy(temp, "01110");
					break;
				case $t7:
					strcpy(temp, "01111");
					break;
				case $s0:
					strcpy(temp, "10000");
					break;
				case $s1:
					strcpy(temp, "10001");
					break;
				case $s2:
					strcpy(temp, "10010");
					break;
				case $s3:
					strcpy(temp, "10011");
					break;
				case $s4:
					strcpy(temp, "10100");
					break;
				case $s5:
					strcpy(temp, "10101");
					break;
				case $s6:
					strcpy(temp, "10110");
					break;
				case $s7:
					strcpy(temp, "10111");
				case $sp:
					strcpy(temp, "11101");
					break;
				case $ra:
					strcpy(temp, "11111");
					break;
				case errorrigister:
				default:
					return 0;
				}
				if (times == 2)
				{
					if (((add <= compare(operate)) && (compare(operate) <= sub)) || compare(operate) == move)
						for (int i = 0; i < 5; i++)
							output[i + 16] = temp[i];
					else if ((addi <= compare(operate)) && (compare(operate) < slti))
						for (int i = 0; i < 5; i++)
							output[i + 11] = temp[i];
				}
				else if (times == 3)
				{
					for (int i = 0; i < 5; i++)
						output[i + 6] = temp[i];
					if (compare(operate) == move)
						for (int i = 11; i < 16; i++)
							output[i] = '0';
				}
				else if (times == 4)
					for (int i = 0; i < 5; i++)
						output[i + 11] = temp[i];
			}
			else transimmediate(fragment);
		}
		else return 0;
		times++;
		fragment = strtok(NULL, " ");
	}
	return 1;
}

//�ļ��������
int filetransfer()
{
	FILE *fpr, *fpw;
	int flag = 1;//1��ʾû���⣬0��ʾ������

	//�ж��Ƿ����input.txt
	if ((fpr = fopen("input.txt", "r")) == NULL)
	{
		printf("��input.txt�ļ���������ļ�������\n");
		return 2;
	}
	fpw = fopen("output.txt", "w");

	//����ÿ��ָ��
	while ((fgets(oneline, 25, fpr)))
	{
		for (int i = 0; oneline[i]; i++)
			if (oneline[i] == 10)oneline[i] = 0;
		if (!transfer())flag = 0;
		fprintf(fpw, "%s\n", output);
	}

	fclose(fpw);
	fclose(fpr);
	return flag;
}


int main()
{
	int mode = 0, i;
	FILE *fp;

	//����������ʾѡ���ļ�����ģʽ���ǵ�����������ʽ
	while (mode != 4)
	{
		system("cls");
		printf("��������Ӧ����ѡ��ģʽ��\n1.���ж�����(������ӵ�oneline.txtĩβ)\n2.���oneline.txt\n3.�ļ�����(�����output.txt)\n4.�˳�\n");
		scanf("%d", &mode);
		if (mode == 1)
		{
			printf("������ָ��\n");
			getchar();
			gets(oneline);
			if (!transfer())printf("�������ָ���δʵ�֣�\n");
			else
			{
				fp = fopen("oneline.txt", "a");
				fprintf(fp, "%s\n", output);
				fclose(fp);
				printf("%s\n", output);
			}
			system("pause");
		}
		else if (mode == 2)
		{
			if (!(fp = fopen("oneline.txt", "w")))printf("δ�ҵ����ļ������Ѵ������ļ���\n");
			else
			{
				fclose(fp);
				printf("�����ɹ�\n");
			}
			system("pause");
		}
		else if (mode == 3)
		{
			i = filetransfer();
			if (i != 2)
			{
				if (!i)printf("�ļ����д���ָ���δʵ�֣�\n");
				else printf("�����ɹ���\n");
			}
			system("pause");
		}
	}
	return 0;
}