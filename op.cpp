#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

#define MAX 5

//定义联系人结构体
struct LXR
{
	string name;
	int age;
	string sex;
	int number;
};

//定义通讯录结构体
struct TXL
{
	struct LXR LXRarr[MAX];
	int pernum;
};

//添加联系人
void addLXR(TXL* TXL1)
{
	if (TXL1->pernum >= MAX)
	{
		cout << "联系人数量已达上限\n";
		system("pause");
	}
	else
	{
		//创建
	nameback:
		string name;
		cout << "请输入联系人姓名：";
		cin >> name;
		TXL1->LXRarr[TXL1->pernum].name = name;
		//姓名查重
		for (int i = 0; i < TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].name == name)
			{
				cout << "该联系人已存在\n";
				system("pause");
				goto nameback;
			}
		}

		int age;
		cout << "请输入联系人年龄：";
		cin >> age;
		TXL1->LXRarr[TXL1->pernum].age = age;

		string sex;
		cout << "请输入联系人性别：";
		cin >> sex;
		TXL1->LXRarr[TXL1->pernum].sex = sex;

	numberback:
		int number;
		cout << "请输入联系人号码：";
		cin >> number;
		TXL1->LXRarr[TXL1->pernum].number = number;
		//号码查重
		for (int i = 0; i < TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].number == number)
			{
				cout << "该联系号码 已存在\n";
				system("pause");
				goto numberback;
			}
		}

		//确认
		cout << "已创建联系人：\n";
		cout << TXL1->LXRarr[TXL1->pernum].name << " " << TXL1->LXRarr[TXL1->pernum].age << " ";
		cout << TXL1->LXRarr[TXL1->pernum].sex << " " << TXL1->LXRarr[TXL1->pernum].number << "\n";
		TXL1->pernum++;
		system("pause");
	}

}

//显示联系人
void showLXR(TXL* TXL1)
{
	if (TXL1->pernum == 0)
	{
		cout << "暂无联系人\n";
		system("pause");
	}
	else
	{
		cout << "共有" << TXL1->pernum << "位联系人\n";
		for (int i = 0; i < TXL1->pernum; i++)
		{
			cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
		}
		system("pause");
	}
}

//删除联系人
void delLXR(TXL* TXL1)
{
	//选择
	int n = -1;
	cout << "现有联系人：\n";
	for (int i = 0; i < TXL1->pernum; i++)
	{
		cout << i << ":" << TXL1->LXRarr[i].name << "\n";
	}
	cout << "请输入要删除的联系人的序号：";
	cin >> n;

	//删除

	for (n; n < TXL1->pernum - 1; n++)
	{
		TXL1->LXRarr[n] = TXL1->LXRarr[n + 1];
	}
	TXL1->pernum--;
	system("pause");
}

//查找联系人
void seekLXR(TXL* TXL1)
{
seekstart:
	//选择按照**查找
	cout << "选择查找方式：\n";
	cout << "\t1、按照姓名查找\n";
	cout << "\t2、按照年龄查找\n";
	cout << "\t3、按照性别查找\n";
	cout << "\t4、按照号码查找\n";
	cout << "\t0、退出\n\n";
	int n = -1;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		cout << "请输入需要查询的姓名：";
		string temname;
		cin >> temname;
		int k = 0;
		for (int i = 0; i <= TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].name == temname)
			{
				cout << "已找到联系人:\n";
				cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
				k++;
			}
		}
		if (k == 0)
			cout << "未找到对应联系人\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	case 2:
	{
		cout << "请输入需要查询的年龄：";
		int temage;
		cin >> temage;
		int j = 1, k = 0;
		for (int i = 0; i <= TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].age == temage)
			{
				while (j)
				{
					cout << "已找到联系人:\n";
					j--;
				}
				cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
				k++;
			}
		}
		if (k == 0)
			cout << "未找到对应联系人\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	case 3:
	{
		cout << "请输入需要查询的性别：";
		string temsex;
		cin >> temsex;
		int j = 1, k = 0;
		for (int i = 0; i <= TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].sex == temsex)
			{
				while (j)
				{
					cout << "已找到联系人:\n";
					j--;
				}
				cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
				k++;
			}
		}
		if (k == 0)
			cout << "未找到对应联系人\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	case 4:
	{
		cout << "请输入需要查询的号码：";
		int temnumber;
		cin >> temnumber;
		int k = 0;
		for (int i = 0; i <= TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].number == temnumber)
			{
				cout << "已找到联系人:\n";
				cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
				k++;
			}
		}
		if (k == 0)
			cout << "未找到对应联系人\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	case 0:
		goto seekend;
	default:
	{
		cout << "请按上表输入\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	}
seekend:
	n = -1;


}

//修改联系人
void changeLXR(TXL* TXL1)
{
changeback:
	cout << "请输入需要修改的联系人的姓名：";
	string temname;
	cin >> temname;
	int k = 0, m = 0, n = 0;
	for (int i = 0; i <= TXL1->pernum; i++)
	{
		if (TXL1->LXRarr[i].name == temname)
		{
			k++;
			m = i;
		}
	}
	if (k == 0)
	{
		cout << "未找到对应联系人\n";
		system("pause");
		system("cls");
		goto changeback;
	}
	else
	{
	changeagain:
		system("cls");
		cout << "修改联系人:\n";
		cout << TXL1->LXRarr[m].name << " " << TXL1->LXRarr[m].age << " " << TXL1->LXRarr[m].sex << " " << TXL1->LXRarr[m].number << "\n";
		cout << "请选择要修改的项目：\n";
		cout << "\t1、姓名\n";
		cout << "\t2、年龄\n";
		cout << "\t3、性别\n";
		cout << "\t4、号码\n";
		cout << "\t0、退出\n";
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "请输入修改后的姓名：";
			string temname;
			cin >> temname;
			for (int j = 0; j <= TXL1->pernum; j++)
			{
				if (TXL1->LXRarr[j].name == temname)
				{
					cout << "联系人姓名重复\n";
					system("pause");
					system("cls");
					goto changeagain;
				}
			}
			TXL1->LXRarr[m].name = temname;
			cout << "修改成功\n";
			goto changeagain;
		}
		case 2:
		{
			cout << "请输入修改后的年龄：";
			int temage;
			cin >> temage;
			TXL1->LXRarr[m].age = temage;
			cout << "修改成功\n";
			goto changeagain;
		}
		case 3:
		{
			cout << "请输入修改后的性别：";
			string temsex;
			cin >> temsex;
			TXL1->LXRarr[m].sex = temsex;
			cout << "修改成功\n";
			goto changeagain;
		}
		case 4:
		{
			cout << "请输入修改后的号码：";
			int temnumber;
			cin >> temnumber;
			for (int j = 0; j <= TXL1->pernum; j++)
			{
				if (TXL1->LXRarr[j].name == temname)
				{
					cout << "联系人号码重复\n";
					system("pause");
					system("cls");
					goto changeagain;
				}
			}
			TXL1->LXRarr[m].number = temnumber;
			cout << "修改成功\n";
			goto changeagain;
		}
		case 0:
			goto changeend;
		default:
		{
			cout << "请按上表输入\n";
			system("pause");
			system("cls");
			goto changeagain;
			break;
		}
		}

	}





changeend:
	k = 0;
}

//清空联系人
void clearLXR(TXL* TXL1)
{
clearagain:
	cout << "确认要清空所有联系人吗?\n";
	cout << "确认请输入验证码,退出请输入“0”\n";
	srand((unsigned int)time(NULL));
	int yzm = rand() % 998 + 1;
	int sryzm = 1000;
	cout << "验证码：" << yzm << endl;
	cin >> sryzm;
	system("cls");
	if (sryzm == yzm)
	{
		TXL1->pernum = 0;
		cout << "已清空联系人";
	}
	else if (sryzm == 0)
		goto clearend;
	else
	{
		cout << "验证码错误，请重新输入\n";
		system("cls");
		goto clearagain;
	}
clearend:
	sryzm = 1000;

}

int main()
{
	//变量初始化
	int i = 0;
	string a, c;
	int b = 0, d = 0;
	string p;

	//创建通讯录结构体变量
	struct TXL TXL1;
	TXL1.pernum = 0;

	while (1)
	{
		//启动界面
	mainstart:
		{
			system("cls");
			cout << "*****" << "*************" << "*****\n";
			cout << "*****" << "1、添加联系人" << "*****\n";
			cout << "*****" << "2、显示联系人" << "*****\n";
			cout << "*****" << "3、删除联系人" << "*****\n";
			cout << "*****" << "4、查找联系人" << "*****\n";
			cout << "*****" << "5、修改联系人" << "*****\n";
			cout << "*****" << "6、清空联系人" << "*****\n";
			cout << "*****" << "0、退出通讯录" << "*****\n";
			cout << "*****" << "*************" << "*****\n";
		}

		//功能选择
		while (1)
		{
			cin >> i;
			switch (i)
			{
			case 1://添加联系人
			{
				system("cls");
				addLXR(&TXL1);
				goto mainstart;
			}
			case 2://显示联系人
			{
				system("cls");
				showLXR(&TXL1);
				goto mainstart;
			}
			case 3://删除联系人
			{
				system("cls");
				delLXR(&TXL1);
				goto mainstart;
			}
			case 4://查找联系人
			{
				system("cls");
				seekLXR(&TXL1);
				goto mainstart;
			}
			case 5://修改联系人
			{
				system("cls");
				changeLXR(&TXL1);
				goto mainstart;
			}
			case 6://清空联系人
			{
				system("cls");
				clearLXR(&TXL1);
				goto mainstart;
			}
			case 0://退出通讯录
			{
				goto mainend;
			}
			default:
				break;
			}
		}
	}
mainend:
	cout << "按任意键退出";
}