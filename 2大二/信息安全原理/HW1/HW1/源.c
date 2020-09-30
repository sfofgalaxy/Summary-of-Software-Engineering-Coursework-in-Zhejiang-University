#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char plaintext[100000];/*����ȫ������*/
char ciphertext[100000];/*����ȫ������*/
char key[11];/*��Կȫ������*/
char sequence[38];/*����Կ����������*/
const char initial[38] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','@','0','1','2','3','4','5','6','7','8','9' ,0 };
/*��ʼ����*/

int judge(char *text)/*�ж����������Կ�Ƿ�Ϸ�*/
{
	int i, flag = 1;
	for (i = 0; text[i]; i++)
	{
		if ((text[i] >= 'a'&&text[i] <= 'z') || (text[i] <= '9'&&text >= '0') || text[i] == '@');
		else
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void sortsequence()/*����Կ�����н�������*/
{
	int i, j, position;
	char temp[38];
	for (i = 0, j = 0; i < 37; i++)
	{
		if (sequence[i] == key[0])
		{
			temp[j++] = key[0];
			temp[j++] = key[2];
			temp[j++] = key[4];
			temp[j++] = key[6];
			temp[j++] = key[8];
		}
		else if (sequence[i] == key[2] || sequence[i] == key[4] || sequence[i] == key[6] || sequence[i] == key[8]);
		else
		{
			temp[j++] = sequence[i];
		}
	}
	temp[37] = 0;
	strcpy(sequence, temp);
	return;
}

void transpkey(int *pkey)
{
	int i, j, position, flag;
	for (i = 0; i < 5; i++)pkey[i] = -1;
	for (i = 0; i < 5; i++)
	{
		flag = 0;
		for (position = 0; key[i * 2 + 1] != sequence[position]; position++);
		while (!flag)
		{
			flag = 1;
			position = position % 5;
			for (j = 0; j < i; j++)
			{
				if (position == pkey[j])
				{
					flag = 0;
					position++;
					break;
				}
			}
		}
		pkey[i] = position;
	}
	return;
}

void encrypt()/*���ܺ���*/
{
	int i, j, times, position;
	char temp[100000];
	int pkey[5];
	printf("��������Կ��ʮλ��������ĸ���ֻ�@�����ַ�������\n");
	scanf("%s", key);
	while (!judge(key))
	{
		printf("���벻�Ϸ�������������:\n");
		scanf("%s", key);
	}
	sortsequence();
	/*S-BOX �滻����*/

	for (i = 0; plaintext[i]; i++)
	{
		for (position = 0; plaintext[i] != sequence[position]; position++);
		ciphertext[i] = sequence[(position + (i + 1)*(i + 1)) % 37];
	}
	ciphertext[i] = 0;

	/*P-BOX ��λ����*/
	/*ȷ����λ������Կ*/

	transpkey(pkey);

	/*��ʼ��λ*/
	for (i = 0; ciphertext[i]; i++);
	if (i % 5 == 0)times = i / 5;
	else
	{
		times = i / 5 + 1;
		for (position = i; position < times * 5; position++)ciphertext[position] = '&';
	}

	for (j = 0, position = 0; j < 5; j++)
	{
		for (i = 0; i < times; i++)
		{
			temp[position++] = ciphertext[5 * i + pkey[j]];
		}
	}

	temp[position] = 0;

	strcpy(ciphertext, temp);
	return;
}

void decrypt()/*���ܺ���*/
{
	int i, j, position, times, pkey[5];
	char temp[100000];
	printf("��������Կ��ʮλ��������ĸ��Сд�����ֻ�@�����ַ�������\n");
	scanf("%s", key);
	while (!judge(key))
	{
		scanf("%s", key);
	}
	sortsequence();

	/*��λ�Ļ�ԭ*/
	transpkey(pkey);

	for (times = 0; ciphertext[times]; times++);
	times = times / 5;
	for (i = 0, position = 0; i < 5; i++)
	{
		for (j = 0; j < times; j++)
		{
			temp[j * 5 + pkey[i]] = ciphertext[position++];
		}
	}
	for (i = 0; i < position&&temp[i] != '&'; i++);
	temp[i] = 0;




	/*�滻�Ļ�ԭ*/
	for (i = 0; temp[i]; i++)
	{
		for (position = 0; temp[i] != sequence[position]; position++);
		if ((position - (i + 1)*(i + 1)) % 37 < 0)position = (position - (i + 1)*(i + 1)) % 37 + 37;
		else position = (position - (i + 1)*(i + 1)) % 37;
		temp[i] = sequence[position];
	}
	strcpy(plaintext, temp);
	return;
}

int main()
{
	int choice;
	while (1)
	{
		strcpy(sequence, initial);
		system("cls");
		printf("1.���������Լ�ѧ�ţ�pengzifan3170105860\n2.���������ı��ļ���\n3.��������\n4.�˳�\n");
		scanf("%d", &choice);
		if (choice == 1)
		{
			strcpy(plaintext, "pengzifan3170105860");
			encrypt();
			printf("�õ����������£�\n%s\n", ciphertext);
		}
		else if (choice == 2)
		{
			printf("���������ģ�Сд�����֣���\n");
			scanf("%s", plaintext);
			while (!judge(plaintext))
			{
				printf("�������벻�Ϸ����������룺\n");
				scanf("%s", plaintext);
			}
			encrypt();
			printf("�õ����������£�\n%s\n", ciphertext);
		}
		else if (choice == 3)
		{
			printf("���������ģ�\n");
			scanf("%s", ciphertext);
			while (!judge(ciphertext))
			{
				printf("�������벻�Ϸ����������룺\n");
				scanf("%s", ciphertext);
			}
			decrypt();
			printf("�õ����������£�\n%s\n", plaintext);
		}
		else if (choice == 4)
		{
			break;
		}
		system("pause");
	}
}