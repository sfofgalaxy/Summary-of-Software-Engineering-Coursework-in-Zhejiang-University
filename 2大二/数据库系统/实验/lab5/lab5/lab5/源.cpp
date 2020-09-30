#include <iostream>
#include <string>
#include "mysql.h"

char dbuser[30] = "root";
char dbpasswd[30] = "pzf652827"; // it must be changed
char dbip[30] = "localhost";
char dbname[50] = "book_management_system";

using namespace std;

MYSQL mysql;    //一个数据库结构体
MYSQL_RES* res; //一个结果集结构体
MYSQL_ROW row;  //char** 二维数组，存放一条条记录
MYSQL * con; //= mysql_init((MYSQL*) 0); 

void managebook()
{
	int option;
	string bookID;
	string select = "select * from book ";
	string insert = "insert into book values( ";
	string book_name, author, stock, total;
	printf("1.显示所有图书\n2.搜索某一图书\n3.添加图书\n");
	cin >> option;
	if (option == 1)
	{
		const char* p = select.c_str();
		mysql_query(con, p);
		res = mysql_store_result(con);
		printf("【图书编号】 【书名】 【作者】 【在馆数】 【总数量】\n");
		while (row = mysql_fetch_row(res))
		{
			printf("【%s】 ", row[0]);//打印图书编号
			printf("【《%s》】 ", row[1]);//打印书名
			printf("【%s】 ", row[2]);//打印作者
			printf("【%s】 ", row[3]);//打印在馆数
			printf("【%s】 ", row[4]);//打印总数量
			printf("\n");
		}
		mysql_free_result(res);
	}
	else if (option == 2)
	{
		printf("请输入图书编号：\n");
		cin >> bookID;
		select += "where book_ID = ";
		select += ("\'" + bookID + "\';");
		const char *p = select.c_str();
		if (!mysql_query(con, p))
		{
			res = mysql_store_result(con);
			printf("【图书编号】 【书名】 【作者】 【在馆数】 【总数量】\n");
			row = mysql_fetch_row(res);
			printf("【%s】 ", row[0]);//打印图书编号
			printf("【《%s》】 ", row[1]);//打印书名
			printf("【%s】 ", row[2]);//打印作者
			printf("【%s】 ", row[3]);//打印在馆数
			printf("【%s】 ", row[4]);//打印总数量
			printf("\n");
			mysql_free_result(res);
		}
		else cout << "未查到该书\n";
	}
	else if (option == 3)
	{
		printf("请输入添加的图书（格式：书名 作者 在馆数 总数量）：\n");
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
		if (!ret)cout << "添加成功！\n";
		else cout << "插入失败error:"<<mysql_error(con) << endl;
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
	printf("1.显示所有借书证\n2.搜索某一借书证\n3.添加借书证\n");
	cin >> option;
	if (option == 1)
	{
		const char* p = select.c_str();
		mysql_query(con, p);
		res = mysql_store_result(con);
		printf("【借书证号】 【学号】\n");
		while (row = mysql_fetch_row(res))
		{
			printf("【%s】 ", row[0]);//打印借书证编号
			printf("【%s】 ", row[1]);//打印学号
			printf("\n");
		}
		mysql_free_result(res);
	}
	else if (option == 2)
	{
		int suboption,subsuboption;
		cout << "请选择搜索模式:\n1.利用借书证搜索\n2.利用学号\n";
		cin >> suboption;
		cout << "请输入：\n";
		cin >> ID;
		if (suboption == 1)select += "where license_ID = \'" + ID + "\';";
		else if (suboption == 2)select += "where stu_ID = \'" + ID + "\';";
		else return;

		const char *p = select.c_str();
		if (!mysql_query(con, p))
		{
			res = mysql_store_result(con);
			printf("【借书证号】 【学号】\n");
			while (row = mysql_fetch_row(res))
			{
				printf("【%s】 ", row[0]);//打印借书证编号
				printf("【%s】 ", row[1]);//打印学号
				printf("\n输入1可删除该借书证，输入其他退出\n");
				cin >> subsuboption;
				if (subsuboption == 1)
				{
					if (suboption == 1)del += "where license_ID = \'" + ID + "\'";
					else del += "where stu_ID = \'" + ID + "\'";
					p = del.c_str();
					if(!mysql_query(con, p))cout << "删除成功！\n";
					else cout << "删除失败！\n";
				}
			}
			mysql_free_result(res);
		}
		else
			cout << "未查到该借书证\n";
	}
	else if (option == 3)
	{
		string stu_ID;
		printf("请输入添加的借书证对应的学号（10位）：\n");
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
		if (!ret)cout << "添加成功！\n";
		else cout << "插入失败error:" << mysql_error(con) << endl;
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
	cout << "选择功能：\n1.显示借阅记录\n2.搜索某一借书证的记录\n3.搜索某本书的借阅记录\n4.借阅某书\n5.归还某书\n";
	cin >> option;
	if (option == 1)
	{
		p = select.c_str();
		mysql_query(con, p);
		res = mysql_store_result(con);
		printf("【图书编号】 \t【借书证号】 \t【借阅时间】 \t【归还时间】\n");
		while (row = mysql_fetch_row(res))
		{
			printf("【%s】 \t", row[0]);//打印图书编号
			printf("【%s】 \t", row[1]);//打印借书证编号
			printf("【%s】 \t", row[2]);//打印借阅时间
			string temp1 = row[3];
			string temp2 = "1000-01-01";
			if (temp1 == temp2)printf("【未归还】\t");//打印归还时间
			else cout << "【" << temp1 << "】";//打印借阅时间
			printf("\n");
		}
		mysql_free_result(res);
	}
	else if (option <= 3 && option >= 2)
	{
		if (option == 2)select += " where license_ID = ";
		else select += " where book_ID = ";
		cout << "请输入编号：\n";
		cin >> ID;
		select += "\'" + ID + "\';";
		p = select.c_str();
		if (!mysql_query(con, p))
		{
			res = mysql_store_result(con);
			if (row = mysql_fetch_row(res))
			{
				printf("【图书编号】 \t【借书证号】 \t【借阅时间】 \t【归还时间】\n");
				printf("【%s】 \t", row[0]);//打印图书编号
				printf("【%s】 \t", row[1]);//打印借书证编号
				printf("【%s】 \t", row[2]);//打印借阅时间
				string temp1 = row[3];
				string temp2 = "1000-01-01";
				if (temp1==temp2)printf("【未归还】\t");//打印归还时间
				else cout<<temp1;//打印借阅时间
				printf("\n");
			}
			else 
				cout << "未查到该编号" << endl;
		}
		else
			cout << "未查到该编号" << endl;

	}
	else if (option == 4)
	{
		cout << "请输入图书书编号以及借书证号（格式：图书编号 借书证号）:\n";
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
		cout << "借阅成功！\n";

	}
	else if (option == 5)
	{
		cout << "请输入要归还的图书编号以及借书证号（格式 图书编号 借书证号）：\n";
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
		else cout << "未查询到该借书证借该书记录！\n";
	}
	return;
}

//初始化
void init()
{
	int option;
	do
	{
		system("cls");
		printf("请选择功能：\n0.退出\n1.图书管理\n2.借书证管理\n3.图书借阅/归还\n");
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
