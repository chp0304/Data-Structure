#include<iostream>
#include<string>
#define MAX 100
#define OK 1
#define ERROR 0 
#define OVERFLOW -1
using namespace std;


typedef struct//学生结构体 
{
	string no;
	string name;
}Stu;


typedef struct //循序表结构体 
{
	Stu *elem;//此处必为指针，因为在新建表的时候为他开辟了空间。相当于数组，指向第一个元素
	int length;
}SqList;

void Show(Stu s)
{
	cout << "学号：" << s.no << " " << "姓名：" << s.name << endl;
}

int InitList(SqList &L)//新建顺序表 
{
	L.elem = new Stu[MAX];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	cout << "循序表建立成功！" << endl;
	return OK;
}

int SearchNO(SqList L, string no)//按学号查找 
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i].no == no)
		{
			Show(L.elem[i]);
			return 0;
		}
	}
	cout << "未查询到此学号！！！" << endl;
	return 0 ;
}

int SearchNA(SqList L, string name)//按姓名查找 
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i].name == name)
		{
			Show(L.elem[i]);
			return 0;
		}
	}
	cout << "未查询到此姓名！！！" << endl;
	return 0;
}

int Insert(SqList &L, int i, Stu s)//插入 
{
	if ((i < 1) || (i > L.length + 1))
	{
		return ERROR;
	}
	if (L.length == MAX)
	{
		cout << "储存空间已满" << endl;
	}
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = s;
	L.length++;
	cout << "插入成功！" << endl;
	return OK;
}

int Delete(SqList &L, int i)//删除 
{
	if ((i < 1) || (i > L.length))
	{
		return ERROR;
	}
	for (int j = i - 1; j < L.length; j++)
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;
	cout << "删除成功！" << endl;
	return OK;
}

void Show(SqList L)//显示信息 
{

	for (int i = 0; i < L.length; i++)
	{
		cout << "学号:" << L.elem[i].no << " " << "姓名:" << L.elem[i].name << endl;
	}
}


void Features()
{
	cout << "1. 建立顺序表\n";
	cout << "2. 输入数据\n";
	cout << "3. 按学号查找\n";
	cout << "4. 按姓名查找\n";
	cout << "5. 插入\n";
	cout << "6. 删除\n";
	cout << "7. 输出数据\n";
	cout << "0. 退出\n\n";
	

}
int main()
{
	SqList L;//循序表 
	Stu s;
	string no;
	string name;
	int insert;
	int i;
	int choose = -1;
	Features();
	while (choose != 0)
	{
		cout << "请输入你要选择的操作：\n";
		cin >> choose;
		switch (choose)//选择操作
		{
			case 1:
				InitList(L);
				break;
			case 2:
				cout << "请输入你要输入数据的个数：";
				cin >> i;
				for (int j = 0; j < i; j++)
				{
					cin >> L.elem[j].no >> L.elem[j].name;
				}
				L.length = i;
				break;
			case 3:
				cout << "请输入你要查找的学号" << endl;
				cin >> no;
				SearchNO(L, no);
				break;
			case 4:
				cout << "请输入你要查找的姓名" << endl;
				cin >> name;
				SearchNA(L, name);
				break;
			case 5:
				cout << "请输入你要插入的位置" << endl;
				cin >> insert;
				cout << "请输入你要插入的学生信息" << endl;
				cin >> s.no >> s.name;
				Insert(L, insert, s);
				break;
			case 6:
				cout << "请输入你要删除的位置" << endl;
				cin >> i;
				Delete(L, i);
				break;
			case 7:
				Show(L);
				break;
		}
	}
	cout << "已退出!" << endl;
	return 0;
}