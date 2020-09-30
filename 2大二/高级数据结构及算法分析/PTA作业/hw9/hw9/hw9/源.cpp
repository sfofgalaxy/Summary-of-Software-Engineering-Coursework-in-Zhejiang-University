#include<iostream>
double Cm, D, Davg;
int N;
double price[600];
double position[600];
double Cg = 0;//��ǰ����
double Cd = 0;//��ǰ������
double cost = 0;//��ǰ����

using namespace std;

/*
1.�ҵ����

2.�жϴӸõ㵽���ͺ����Ƿ��м���վ��û������3.������4.��
3.�ж��Ƿ��ܵ��յ�����һ������վ���͵����յ���ͣ����ܵ��յ����˳���д����Զ���

4.�����ж��Ƿ������ͺ���ǰ����۸���˵ļ���վ��������5.û������6.��
5.ѡ����ü���վ���������˵ļ���վ��������һ������վ���ӵ����ü���վ���ͣ�
6.�ж��ܷ��յ㣬�����յ㣬������ѡ���ͺ���ǰ����˵ļ���վ��������һ������վ�����ͣ�

7.���ڸü���վ�ظ�2��
*/

//�ü���վ�������������м���վ�򷵻��±꣬û���򷵻�-1
int findgas(int index)
{
	double minposition = 1000000;
	double minprice = 1000000;
	int minindex=-1;
	double temp = Cd + Cm * Davg;
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if (position[i] <= temp && position[i] > position[index])//*******δ�ж��Ƿ�ͬһ���ط�����������վ*********
		{
			if(!flag)flag = 2;//�����м���վ���Ǽ۸�Ϲ�
			//���жϾ������Ƿ��м۸�ȸü���վ�͵ļ���վ
			if (minposition > position[i]&&price[i]<price[index])
			{
				flag = 1;
				minposition = position[i];
				minindex = i;
			}
		}
	}
	//û�����Ҿ����ڼ۸���͵ļ���վ
	if (flag==2)
	{
		for (int i = 0; i < N; i++)
		{
			if (position[i] <= temp && position[i] > position[index])
			{
				if (minprice > price[i])
				{
					minprice = price[i];
					minindex = i;
				}
			}
		}
	}
	return minindex;
}

//���ĺ���������1��֤�����յ㣬0�����δ���յ�
int GP()
{
	//1.�����
	int index, flag = 0, temp;
	for (int i = 0; i < N; i++)
	{
		if (position[i] == 0)
		{
			flag = 1;
			index = i;
		}
	}
	if (!flag)return 0;


	while (1)
	{
		temp = findgas(index);
		if (temp < 0)
		{
			if (Cd + Cm * Davg >= D)
			{
				cost += ((D - position[index]) - Cg * Davg) / Davg * price[index];
				return 1;
			}
			else
			{
				Cd += Cm * Davg;
				return 0;
			}
		}
		else
		{
			if (price[temp] <= price[index])
			{
				Cd = position[temp];
				cost += ((position[temp] - position[index]) - Cg * Davg) / Davg * price[index];
				Cg = 0;
			}
			else
			{
				if (Cd + Cm * Davg >= D)
				{
					cost += ((D - position[index]) - Cg * Davg) / Davg * price[index];
					return 1;
				}
				else
				{
					Cd = position[temp];
					cost += (Cm - Cg) * price[index];
					Cg = Cm - (position[temp] - position[index]) / Davg;
				}
			}
		}
		index = temp;
	}
}

int main()
{
	cin >> Cm >> D >> Davg >> N;
	for (int i = 0; i < N; i++)
		cin >> price[i] >> position[i];

	if (GP())
		printf("%.2f\n", cost);
	else 
		printf("The maximum travel distance = %.2f",Cd);
	//system("pause");
	return 0;
}