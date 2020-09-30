#include<iostream>
#include<cmath>

using namespace std;

int N, M, L;
int worfnum;
int player[200];//��¼�ǻ��� 0���ˣ�1����
int speech[200];//��¼˵�Ļ�

int judge()
{
	int worfliar = 0, liar = 0;
	int flag;
	for (int i = 1; i <= N; i++)
	{
		flag = 1;//1˵�ѣ�0û˵��
		if ((speech[i] < 0 && player[abs(speech[i])]) || (speech[i] > 0 && (!player[speech[i]])))
		{
			flag = 0;
		}
		if (flag)
		{
			liar++;
			if (player[i])worfliar++;
		}
		
	}
	if (liar != L || worfliar == 0 || worfliar >= M || worfnum != M)return 0;
	else 
		return 1;
}

int backtracking(int num)
{
	if (!num)return judge();
	player[num] = 1;
	worfnum++;
	if (backtracking(num - 1))return 1;
	player[num] = 0;
	worfnum--;
	if (backtracking(num - 1))return 1;
	return 0;
}

int main(void)
{
	int num = 0, i;
	cin >> N >> M >> L;

	//��ȡ
	for (i = 1; i <= N; i++)
	{
		cin >> speech[i];
	}

	//���
	int output = 1;
	if (backtracking(N))
	{
		for (i = N; i >= 1; i--)
		{
			if (player[i])
			{
				if (output == 1)
				{
					output = 0;
					printf("%d", i);
				}
				else
					printf(" %d", i);
			}
			}
	}
	else printf("No Solution");

	return 0;
}
