#include<iostream>
using namespace std;
#define MAX 1000
//菜单界面

void showmenu()
{
	cout << "     1.添加联系人" << endl;
	cout << "     2.显示联系人" << endl;
	cout << "     3.删除联系人" << endl;
	cout << "     4.查找联系人" << endl;
	cout << "     5.修改联系人" << endl;
	cout << "     6.清空联系人" << endl;
	cout << "     0.退出通讯录" << endl;
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
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_name = name;

		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1—男" << endl;
		cout << "2—女" << endl;

		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex== 2)
			{
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_age = age;

		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_addr = address;

		abs->m_Size++;

		cout << "添加成功" << endl;

		system("pause");
		system("cls");


	}
}

void showperson(Addressbooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_name <<" ";
			cout << "年龄：" << abs->personArray[i].m_age<<" ";
			cout << "性别：" << (abs->personArray[i].m_sex==1?"男":"女") << " ";
			cout << "电话：" << abs->personArray[i].m_Phone<<" ";
			cout << "住址：" << abs->personArray[i].m_addr << endl;;
		}
	}
	system("pause");
	system("cls");
}

int isExist(Addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;
}

void deleteperson(Addressbooks* abs)
{
	cout << "请输入需要删除的联系人的姓名" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}

void findperson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_name << " ";
		cout << "年龄：" << abs->personArray[ret].m_age << " ";
		cout << "性别：" << (abs->personArray[ret].m_sex == 1 ? "男" : "女") << " ";
		cout << "电话：" << abs->personArray[ret].m_Phone << " ";
		cout << "住址：" << abs->personArray[ret].m_addr << endl;;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");

}

void modifyperson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);

	if (ret != 1)
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;

		cout << "请输入性别" << endl;
		cout << "1—男" << endl;
		cout << "2—女" << endl;
		int sex = 0;
		while (1)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}

		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_age = age;

		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone;

		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_addr = address;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

void cleanperson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
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
			cout << "欢迎下次使用" << endl;
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