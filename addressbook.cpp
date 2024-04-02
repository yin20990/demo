#include<iostream>
using namespace std;
#define MAX 1000
//version 6
void showmenu()
{
	cout << "     1.������ϵ��" << endl;
	cout << "     2.��ʾ��ϵ��" << endl;
	cout << "     3.ɾ����ϵ��" << endl;
	cout << "     4.������ϵ��" << endl;
	cout << "     5.�޸���ϵ��" << endl;
	cout << "     6.�����ϵ��" << endl;
	cout << "     0.�˳�ͨѶ¼" << endl;
}

struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_Phone;
	string m_addr;

};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;

};

void Addperson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷�����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;

		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1����" << endl;
		cout << "2��Ů" << endl;

		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex== 2)
			{
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_age = age;

		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "������סַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_addr = address;

		abs->m_Size++;

		cout << "���ӳɹ�" << endl;

		system("pause");
		system("cls");
	}
}

void showperson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_name <<" ";
			cout << "���䣺" << abs->personArray[i].m_age<<" ";
			cout << "�Ա�" << (abs->personArray[i].m_sex==1?"��":"Ů") << " ";
			cout << "�绰��" << abs->personArray[i].m_Phone<<" ";
			cout << "סַ��" << abs->personArray[i].m_addr << endl;;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
		if (abs->personArray[i].m_name == name)
			return i;
	return -1;
}

void deleteperson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ�˵�����" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
		cout << "���޴���" << endl;
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}

void findperson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_name << " ";
		cout << "���䣺" << abs->personArray[ret].m_age << " ";
		cout << "�Ա�" << (abs->personArray[ret].m_sex == 1 ? "��" : "Ů") << " ";
		cout << "�绰��" << abs->personArray[ret].m_Phone << " ";
		cout << "סַ��" << abs->personArray[ret].m_addr << endl;;
	}
	else
		cout << "���޴���" << endl;
	system("pause");
	system("cls");
}

void modifyperson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != 1)
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;

		cout << "�������Ա�" << endl;
		cout << "1����" << endl;
		cout << "2��Ů" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}

		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone;

		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_addr = address;
	}
	else
		cout << "���޴���" << endl;

	system("pause");
	system("cls");
}

void cleanperson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	Addressbooks abs;
	abs.m_Size = 0;
	int select = 0;
	while (1)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:
			Addperson(&abs);
			break;
		case 2:
			showperson(&abs);
			break;
		case 3:
			deleteperson(&abs);
			break;
		case 4:
			findperson(&abs);
			break;
		case 5:
			modifyperson(&abs);
			break;
		case 6:
			cleanperson(&abs);
			break;
		case 0:
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
