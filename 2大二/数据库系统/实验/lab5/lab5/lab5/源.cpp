#include <iostream>
#include <string>
#include "mysql.h"

char dbuser[30] = "root";
char dbpasswd[30] = "pzf652827"; // it must be changed
char dbip[30] = "localhost";
char dbname[50] = "book_management_system";

using namespace std;

MYSQL mysql;    //һ�����ݿ�ṹ��
MYSQL_RES* res; //һ��������ṹ��
MYSQL_ROW row;  //char** ��ά���飬���һ������¼
MYSQL * con; //= mysql_init((MYSQL*) 0); 

void managebook()
{
	int option;
	string bookID;
	string select = "select * from book ";
	string insert = "insert into book values( ";
	string book_name, author, stock, total;
	printf("1.��ʾ����ͼ��\n2.����ĳһͼ��\n3.���ͼ��\n");
	cin >> option;
	if (option == 1)
	{
		const char* p = select.c_str();
		mysql_query(con, p);
		res = mysql_store_result(con);
		printf("��ͼ���š� �������� �����ߡ� ���ڹ����� ����������\n");
		while (row = mysql_fetch_row(res))
		{
			printf("��%s�� ", row[0]);//��ӡͼ����
			printf("����%s���� ", row[1]);//��ӡ����
			printf("��%s�� ", row[2]);//��ӡ����
			printf("��%s�� ", row[3]);//��ӡ�ڹ���
			printf("��%s�� ", row[4]);//��ӡ������
			printf("\n");
		}
		mysql_free_result(res);
	}
	else if (option == 2)
	{
		printf("������ͼ���ţ�\n");
		cin >> bookID;
		select += "where book_ID = ";
		select += ("\'" + bookID + "\';");
		const char *p = select.c_str();
		if (!mysql_query(con, p))
		{
			res = mysql_store_result(con);
			printf("��ͼ���š� �������� �����ߡ� ���ڹ����� ����������\n");
			row = mysql_fetch_row(res);
			printf("��%s�� ", row[0]);//��ӡͼ����
			printf("����%s���� ", row[1]);//��ӡ����
			printf("��%s�� ", row[2]);//��ӡ����
			printf("��%s�� ", row[3]);//��ӡ�ڹ���
			printf("��%s�� ", row[4]);//��ӡ������
			printf("\n");
			mysql_free_result(res);
		}
		else cout << "δ�鵽����\n";
	}
	else if (option == 3)
	{
		printf("��������ӵ�ͼ�飨��ʽ������ ���� �ڹ��� ����������\n");
		cin >> book_name >> author >> stock >> total;
		mysql_query(con, "SELECT book_ID FROM book ORDER BY book_ID DESC LIMIT 1; ");
		res = mysql_store_result(con);
		if (row = mysql_fetch_row(res))
		{
			row[0][9] += 1;
			insert += "\'";
			insert += row[0];
			insert += "\',";
		}
		else insert += "\'0000000001\',";
		mysql_free_result(res);
		//cout << book_name << endl << author << endl << stock << endl << total << endl;
		insert += "\'" + book_name + "\',\'" + author + "\'," + stock + "," + total + ");";
		const char *p = insert.c_str();
		cout << p;
		int ret = mysql_query(con, p);
		if (!ret)cout << "��ӳɹ���\n";
		else cout << "����ʧ��error:"<<mysql_error(con) << endl;
	}
	return;
}


void managelicense()
{
	int option;
	string select = "select * from license ";
	string insert = "insert into license values( ";
	string del = "delete from license ";
	string ID;
	printf("1.��ʾ���н���֤\n2.����ĳһ����֤\n3.��ӽ���֤\n");
	cin >> option;
	if (option == 1)
	{
		const char* p = select.c_str();
		mysql_query(con, p);
		res = mysql_store_result(con);
		printf("������֤�š� ��ѧ�š�\n");
		while (row = mysql_fetch_row(res))
		{
			printf("��%s�� ", row[0]);//��ӡ����֤���
			printf("��%s�� ", row[1]);//��ӡѧ��
			printf("\n");
		}
		mysql_free_result(res);
	}
	else if (option == 2)
	{
		int suboption,subsuboption;
		cout << "��ѡ������ģʽ:\n1.���ý���֤����\n2.����ѧ��\n";
		cin >> suboption;
		cout << "�����룺\n";
		cin >> ID;
		if (suboption == 1)select += "where license_ID = \'" + ID + "\';";
		else if (suboption == 2)select += "where stu_ID = \'" + ID + "\';";
		else return;

		const char *p = select.c_str();
		if (!mysql_query(con, p))
		{
			res = mysql_store_result(con);
			printf("������֤�š� ��ѧ�š�\n");
			while (row = mysql_fetch_row(res))
			{
				printf("��%s�� ", row[0]);//��ӡ����֤���
				printf("��%s�� ", row[1]);//��ӡѧ��
				printf("\n����1��ɾ���ý���֤�����������˳�\n");
				cin >> subsuboption;
				if (subsuboption == 1)
				{
					if (suboption == 1)del += "where license_ID = \'" + ID + "\'";
					else del += "where stu_ID = \'" + ID + "\'";
					p = del.c_str();
					if(!mysql_query(con, p))cout << "ɾ���ɹ���\n";
					else cout << "ɾ��ʧ�ܣ�\n";
				}
			}
			mysql_free_result(res);
		}
		else
			cout << "δ�鵽�ý���֤\n";
	}
	else if (option == 3)
	{
		string stu_ID;
		printf("��������ӵĽ���֤��Ӧ��ѧ�ţ�10λ����\n");
		cin >> stu_ID;
		mysql_query(con, "SELECT license_ID FROM license ORDER BY license_ID DESC LIMIT 1; ");
		res = mysql_store_result(con);
		if (row = mysql_fetch_row(res))
		{
			row[0][9] += 1;
			insert += "\'";
			insert += row[0];
			insert += "\',";
		}
		else insert += "\'0000000001\',";
		mysql_free_result(res);
		insert += "\'" + stu_ID + "\');" ;
		const char *p = insert.c_str();
		int ret = mysql_query(con, p);
		if (!ret)cout << "��ӳɹ���\n";
		else cout << "����ʧ��error:" << mysql_error(con) << endl;
	}
	return;
}


void lend_return()
{
	int option;
	const char*p;
	string select = "select * from record ";
	string insert = "insert into record values( \'";
	string ID;
	string book_ID, license_ID;
	cout << "ѡ���ܣ�\n1.��ʾ���ļ�¼\n2.����ĳһ����֤�ļ�¼\n3.����ĳ����Ľ��ļ�¼\n4.����ĳ��\n5.�黹ĳ��\n";
	cin >> option;
	if (option == 1)
	{
		p = select.c_str();
		mysql_query(con, p);
		res = mysql_store_result(con);
		printf("��ͼ���š� \t������֤�š� \t������ʱ�䡿 \t���黹ʱ�䡿\n");
		while (row = mysql_fetch_row(res))
		{
			printf("��%s�� \t", row[0]);//��ӡͼ����
			printf("��%s�� \t", row[1]);//��ӡ����֤���
			printf("��%s�� \t", row[2]);//��ӡ����ʱ��
			string temp1 = row[3];
			string temp2 = "1000-01-01";
			if (temp1 == temp2)printf("��δ�黹��\t");//��ӡ�黹ʱ��
			else cout << "��" << temp1 << "��";//��ӡ����ʱ��
			printf("\n");
		}
		mysql_free_result(res);
	}
	else if (option <= 3 && option >= 2)
	{
		if (option == 2)select += " where license_ID = ";
		else select += " where book_ID = ";
		cout << "�������ţ�\n";
		cin >> ID;
		select += "\'" + ID + "\';";
		p = select.c_str();
		if (!mysql_query(con, p))
		{
			res = mysql_store_result(con);
			if (row = mysql_fetch_row(res))
			{
				printf("��ͼ���š� \t������֤�š� \t������ʱ�䡿 \t���黹ʱ�䡿\n");
				printf("��%s�� \t", row[0]);//��ӡͼ����
				printf("��%s�� \t", row[1]);//��ӡ����֤���
				printf("��%s�� \t", row[2]);//��ӡ����ʱ��
				string temp1 = row[3];
				string temp2 = "1000-01-01";
				if (temp1==temp2)printf("��δ�黹��\t");//��ӡ�黹ʱ��
				else cout<<temp1;//��ӡ����ʱ��
				printf("\n");
			}
			else 
				cout << "δ�鵽�ñ��" << endl;
		}
		else
			cout << "δ�鵽�ñ��" << endl;

	}
	else if (option == 4)
	{
		cout << "������ͼ�������Լ�����֤�ţ���ʽ��ͼ���� ����֤�ţ�:\n";
		cin >> book_ID >> license_ID;
		string temp1 = "select license_ID from license where license_ID = \'";
		temp1 += license_ID + "\';";
		const char* p1 = temp1.c_str();
		string temp2 = "select book_ID from book where book_ID = \'";
		temp2 += book_ID + "\';";
		const char* p2 = temp2.c_str();
		insert += book_ID + "\',\'" + license_ID + "\'," + "curdate(), \'1000-01-01\')";
		p = insert.c_str();
		mysql_query(con, p);
		cout << "���ĳɹ���\n";

	}
	else if (option == 5)
	{
		cout << "������Ҫ�黹��ͼ�����Լ�����֤�ţ���ʽ ͼ���� ����֤�ţ���\n";
		cin >> book_ID >> license_ID;
		string update = "update record set escheat = curdate() where book_ID =\'";
		string search = "select lend from record where book_ID = \'";
		search += book_ID + "\' and license_ID = \'" + license_ID + "\'";
		const char* p = search.c_str();
		if (!mysql_query(con, p))
		{
			res = mysql_store_result(con);
			row = mysql_fetch_row(res);
			update += book_ID + "\' and license_ID = \'" + license_ID + "\'";
			update += "and lend = \'";
			update += row[2];
			update += "\';";
			mysql_free_result(res);
			p = update.c_str();
			mysql_query(con, p);
		}
		else cout << "δ��ѯ���ý���֤������¼��\n";
	}
	return;
}

//��ʼ��
void init()
{
	int option;
	do
	{
		system("cls");
		printf("��ѡ���ܣ�\n0.�˳�\n1.ͼ�����\n2.����֤����\n3.ͼ�����/�黹\n");
		cin >> option;
		if (option == 1)
		{
			managebook();
			system("pause");
		}
		else if (option == 2)
		{
			managelicense();
			system("pause");
		}
		else if (option == 3)
		{
			lend_return();
			system("pause");
		}
		else
		{
			mysql_close(con);
			break;
		}
	} while (1);
}

int main()
{
	//database configuartion


	con = mysql_init((MYSQL*)0);

	if (con != NULL && mysql_real_connect(con, dbip, dbuser, dbpasswd, dbname, 3306, NULL, 0))
	{
		if (!mysql_select_db(con, dbname)) {
			printf("Selectthe database successfully !\n");
			con->reconnect = 1;
			init();
		}
	}
	else {
		MessageBoxA(NULL, "Unable to connect the database,check your configuration!", "", NULL);
		return 0;
	}
	system("pause");
	return 0;
}
