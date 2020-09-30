#include<iostream>
double Cm, D, Davg;
int N;
double price[600];
double position[600];
double Cg = 0;//当前油量
double Cd = 0;//当前公里数
double cost = 0;//当前花费

using namespace std;

/*
1.找到起点

2.判断从该点到满油耗完是否有加油站；没有则跳3.有则跳4.；
3.判断是否能到终点则上一个加油站加油到到终点的油，不能到终点则退出并写出最远公里；

4.有则判断是否有满油耗完前比其价格便宜的加油站，有则跳5.没有则跳6.；
5.选择离该加油站最近的最便宜的加油站，并且上一个加油站仅加到到该加油站的油；
6.判断能否到终点，能则到终点，不能则选择油耗完前最便宜的加油站，并且上一个加油站加满油；

7.对于该加油站重复2；
*/

//该加油站到满油量耗完有加油站则返回下标，没有则返回-1
int findgas(int index)
{
	double minposition = 1000000;
	double minprice = 1000000;
	int minindex=-1;
	double temp = Cd + Cm * Davg;
	int flag = 0;
	for (int i = 0; i < N; i++)
	{
		if (position[i] <= temp && position[i] > position[index])//*******未判断是否同一个地方有两个加油站*********
		{
			if(!flag)flag = 2;//代表有加油站但是价格较贵
			//先判断距离内是否有价格比该加油站低的加油站
			if (minposition > position[i]&&price[i]<price[index])
			{
				flag = 1;
				minposition = position[i];
				minindex = i;
			}
		}
	}
	//没有则找距离内价格最低的加油站
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

//核心函数，返回1则证明到终点，0则代表未到终点
int GP()
{
	//1.找起点
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