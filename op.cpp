#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
using namespace std;

#define MAX 5

//������ϵ�˽ṹ��
struct LXR
{
	string name;
	int age;
	string sex;
	int number;
};

//����ͨѶ¼�ṹ��
struct TXL
{
	struct LXR LXRarr[MAX];
	int pernum;
};

//�����ϵ��
void addLXR(TXL* TXL1)
{
	if (TXL1->pernum >= MAX)
	{
		cout << "��ϵ�������Ѵ�����\n";
		system("pause");
	}
	else
	{
		//����
	nameback:
		string name;
		cout << "��������ϵ��������";
		cin >> name;
		TXL1->LXRarr[TXL1->pernum].name = name;
		//��������
		for (int i = 0; i < TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].name == name)
			{
				cout << "����ϵ���Ѵ���\n";
				system("pause");
				goto nameback;
			}
		}

		int age;
		cout << "��������ϵ�����䣺";
		cin >> age;
		TXL1->LXRarr[TXL1->pernum].age = age;

		string sex;
		cout << "��������ϵ���Ա�";
		cin >> sex;
		TXL1->LXRarr[TXL1->pernum].sex = sex;

	numberback:
		int number;
		cout << "��������ϵ�˺��룺";
		cin >> number;
		TXL1->LXRarr[TXL1->pernum].number = number;
		//�������
		for (int i = 0; i < TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].number == number)
			{
				cout << "����ϵ���� �Ѵ���\n";
				system("pause");
				goto numberback;
			}
		}

		//ȷ��
		cout << "�Ѵ�����ϵ�ˣ�\n";
		cout << TXL1->LXRarr[TXL1->pernum].name << " " << TXL1->LXRarr[TXL1->pernum].age << " ";
		cout << TXL1->LXRarr[TXL1->pernum].sex << " " << TXL1->LXRarr[TXL1->pernum].number << "\n";
		TXL1->pernum++;
		system("pause");
	}

}

//��ʾ��ϵ��
void showLXR(TXL* TXL1)
{
	if (TXL1->pernum == 0)
	{
		cout << "������ϵ��\n";
		system("pause");
	}
	else
	{
		cout << "����" << TXL1->pernum << "λ��ϵ��\n";
		for (int i = 0; i < TXL1->pernum; i++)
		{
			cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
		}
		system("pause");
	}
}

//ɾ����ϵ��
void delLXR(TXL* TXL1)
{
	//ѡ��
	int n = -1;
	cout << "������ϵ�ˣ�\n";
	for (int i = 0; i < TXL1->pernum; i++)
	{
		cout << i << ":" << TXL1->LXRarr[i].name << "\n";
	}
	cout << "������Ҫɾ������ϵ�˵���ţ�";
	cin >> n;

	//ɾ��

	for (n; n < TXL1->pernum - 1; n++)
	{
		TXL1->LXRarr[n] = TXL1->LXRarr[n + 1];
	}
	TXL1->pernum--;
	system("pause");
}

//������ϵ��
void seekLXR(TXL* TXL1)
{
seekstart:
	//ѡ����**����
	cout << "ѡ����ҷ�ʽ��\n";
	cout << "\t1��������������\n";
	cout << "\t2�������������\n";
	cout << "\t3�������Ա����\n";
	cout << "\t4�����պ������\n";
	cout << "\t0���˳�\n\n";
	int n = -1;
	cin >> n;
	switch (n)
	{
	case 1:
	{
		cout << "��������Ҫ��ѯ��������";
		string temname;
		cin >> temname;
		int k = 0;
		for (int i = 0; i <= TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].name == temname)
			{
				cout << "���ҵ���ϵ��:\n";
				cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
				k++;
			}
		}
		if (k == 0)
			cout << "δ�ҵ���Ӧ��ϵ��\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	case 2:
	{
		cout << "��������Ҫ��ѯ�����䣺";
		int temage;
		cin >> temage;
		int j = 1, k = 0;
		for (int i = 0; i <= TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].age == temage)
			{
				while (j)
				{
					cout << "���ҵ���ϵ��:\n";
					j--;
				}
				cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
				k++;
			}
		}
		if (k == 0)
			cout << "δ�ҵ���Ӧ��ϵ��\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	case 3:
	{
		cout << "��������Ҫ��ѯ���Ա�";
		string temsex;
		cin >> temsex;
		int j = 1, k = 0;
		for (int i = 0; i <= TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].sex == temsex)
			{
				while (j)
				{
					cout << "���ҵ���ϵ��:\n";
					j--;
				}
				cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
				k++;
			}
		}
		if (k == 0)
			cout << "δ�ҵ���Ӧ��ϵ��\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	case 4:
	{
		cout << "��������Ҫ��ѯ�ĺ��룺";
		int temnumber;
		cin >> temnumber;
		int k = 0;
		for (int i = 0; i <= TXL1->pernum; i++)
		{
			if (TXL1->LXRarr[i].number == temnumber)
			{
				cout << "���ҵ���ϵ��:\n";
				cout << TXL1->LXRarr[i].name << " " << TXL1->LXRarr[i].age << " " << TXL1->LXRarr[i].sex << " " << TXL1->LXRarr[i].number << "\n";
				k++;
			}
		}
		if (k == 0)
			cout << "δ�ҵ���Ӧ��ϵ��\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	case 0:
		goto seekend;
	default:
	{
		cout << "�밴�ϱ�����\n";
		system("pause");
		system("cls");
		goto seekstart;
		break;
	}
	}
seekend:
	n = -1;


}

//�޸���ϵ��
void changeLXR(TXL* TXL1)
{
changeback:
	cout << "��������Ҫ�޸ĵ���ϵ�˵�������";
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
		cout << "δ�ҵ���Ӧ��ϵ��\n";
		system("pause");
		system("cls");
		goto changeback;
	}
	else
	{
	changeagain:
		system("cls");
		cout << "�޸���ϵ��:\n";
		cout << TXL1->LXRarr[m].name << " " << TXL1->LXRarr[m].age << " " << TXL1->LXRarr[m].sex << " " << TXL1->LXRarr[m].number << "\n";
		cout << "��ѡ��Ҫ�޸ĵ���Ŀ��\n";
		cout << "\t1������\n";
		cout << "\t2������\n";
		cout << "\t3���Ա�\n";
		cout << "\t4������\n";
		cout << "\t0���˳�\n";
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "�������޸ĺ��������";
			string temname;
			cin >> temname;
			for (int j = 0; j <= TXL1->pernum; j++)
			{
				if (TXL1->LXRarr[j].name == temname)
				{
					cout << "��ϵ�������ظ�\n";
					system("pause");
					system("cls");
					goto changeagain;
				}
			}
			TXL1->LXRarr[m].name = temname;
			cout << "�޸ĳɹ�\n";
			goto changeagain;
		}
		case 2:
		{
			cout << "�������޸ĺ�����䣺";
			int temage;
			cin >> temage;
			TXL1->LXRarr[m].age = temage;
			cout << "�޸ĳɹ�\n";
			goto changeagain;
		}
		case 3:
		{
			cout << "�������޸ĺ���Ա�";
			string temsex;
			cin >> temsex;
			TXL1->LXRarr[m].sex = temsex;
			cout << "�޸ĳɹ�\n";
			goto changeagain;
		}
		case 4:
		{
			cout << "�������޸ĺ�ĺ��룺";
			int temnumber;
			cin >> temnumber;
			for (int j = 0; j <= TXL1->pernum; j++)
			{
				if (TXL1->LXRarr[j].name == temname)
				{
					cout << "��ϵ�˺����ظ�\n";
					system("pause");
					system("cls");
					goto changeagain;
				}
			}
			TXL1->LXRarr[m].number = temnumber;
			cout << "�޸ĳɹ�\n";
			goto changeagain;
		}
		case 0:
			goto changeend;
		default:
		{
			cout << "�밴�ϱ�����\n";
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

//�����ϵ��
void clearLXR(TXL* TXL1)
{
clearagain:
	cout << "ȷ��Ҫ���������ϵ����?\n";
	cout << "ȷ����������֤��,�˳������롰0��\n";
	srand((unsigned int)time(NULL));
	int yzm = rand() % 998 + 1;
	int sryzm = 1000;
	cout << "��֤�룺" << yzm << endl;
	cin >> sryzm;
	system("cls");
	if (sryzm == yzm)
	{
		TXL1->pernum = 0;
		cout << "�������ϵ��";
	}
	else if (sryzm == 0)
		goto clearend;
	else
	{
		cout << "��֤���������������\n";
		system("cls");
		goto clearagain;
	}
clearend:
	sryzm = 1000;

}

int main()
{
	//������ʼ��
	int i = 0;
	string a, c;
	int b = 0, d = 0;
	string p;

	//����ͨѶ¼�ṹ�����
	struct TXL TXL1;
	TXL1.pernum = 0;

	while (1)
	{
		//��������
	mainstart:
		{
			system("cls");
			cout << "*****" << "*************" << "*****\n";
			cout << "*****" << "1�������ϵ��" << "*****\n";
			cout << "*****" << "2����ʾ��ϵ��" << "*****\n";
			cout << "*****" << "3��ɾ����ϵ��" << "*****\n";
			cout << "*****" << "4��������ϵ��" << "*****\n";
			cout << "*****" << "5���޸���ϵ��" << "*****\n";
			cout << "*****" << "6�������ϵ��" << "*****\n";
			cout << "*****" << "0���˳�ͨѶ¼" << "*****\n";
			cout << "*****" << "*************" << "*****\n";
		}

		//����ѡ��
		while (1)
		{
			cin >> i;
			switch (i)
			{
			case 1://�����ϵ��
			{
				system("cls");
				addLXR(&TXL1);
				goto mainstart;
			}
			case 2://��ʾ��ϵ��
			{
				system("cls");
				showLXR(&TXL1);
				goto mainstart;
			}
			case 3://ɾ����ϵ��
			{
				system("cls");
				delLXR(&TXL1);
				goto mainstart;
			}
			case 4://������ϵ��
			{
				system("cls");
				seekLXR(&TXL1);
				goto mainstart;
			}
			case 5://�޸���ϵ��
			{
				system("cls");
				changeLXR(&TXL1);
				goto mainstart;
			}
			case 6://�����ϵ��
			{
				system("cls");
				clearLXR(&TXL1);
				goto mainstart;
			}
			case 0://�˳�ͨѶ¼
			{
				goto mainend;
			}
			default:
				break;
			}
		}
	}
mainend:
	cout << "��������˳�";
}