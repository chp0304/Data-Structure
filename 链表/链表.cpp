#include<iostream>
#include<string>
#define MAX 100
#define OK 1
#define ERROR 0 
#define OVERFLOW -1
using namespace std;

typedef struct//学生结构体 
{
	string no;//学号
	string name;//姓名
}Stu;

typedef struct LNode 
{
	Stu data;
	struct LNode *next;
}LNode;

void Show(Stu s)
{
	cout << "学号：" << s.no << " " << "姓名：" << s.name << endl;
}

int InitList(LNode * &L)//初始化链表
{
	L = new LNode;
	L->next = NULL;
	cout << "成功建立链表！" << endl;
	return OK;
}

int SearchNo(LNode *L, string no)//按学号查找
{
	LNode *p = L->next;//p 指向首元节点
	while (p && p->data.no != no)
	{
		p = p->next;
	}
	if(p)//判断是否查到
		Show(p->data);//显示信息
	else 
		cout << "未查询到此学号！！！" << endl;
	return OK;
}

int SearchNA(LNode *L, string name)//按姓名查找
{
	LNode *p = L->next;
	while (p && p->data.name != name)
	{
		p = p->next;
	}
	if (p)
		Show(p->data);
	else
		cout << "未查询到此姓名！！！" << endl;
	return OK;
}

int Insert(LNode *&L, int i, Stu s)//插入
{
	LNode *p = L;
	LNode *a = new LNode;
	int j = 0;//计数器
	while (p && (j < i - 1))//第一次指向的为首元节点
	{
		p = p->next;//查找第i-1的节点，并使p指向a
		j++;
	}
	if (!p || j > i - 1)//i < 1
	{
		cout << "插入失败！！！" << endl;
		return ERROR;
	}
	a->data = s;//输入数据域
	a->next = p->next;//a的next 指向p的next
	p->next = a;//p的next 指向a,完成插入
	cout << "插入成功！！！" << endl;
	return OK;
}

int Delete(LNode * &L, int i)//删除
{
	LNode *p = L;
	LNode *a;
	int j = 0;
	while (p && (j < i - 1))//第一次指向的为首元节点
	{
		p = p->next;//查询第i-1个节点
		j++;
	}
	if (!(p->next) || (i < 1))//i<1 或者 删除位置不存在
	{
		cout << "删除失败！！！" << endl;
		return ERROR;
	}
	LNode *q = p->next;//q 为要删除的节点
	p->next = q->next;//q的前任节点 指向q的下任节点
	delete q;//释放q的地址
	cout << "删除成功！！！" << endl;
	return OK;
}

void Show(LNode *L)//重载
{
	LNode *p = L->next;
	while (p)
	{
		cout << "学号:" << p->data.no << " " << "姓名:" << p->data.name << endl;
		p = p->next;
	}
	
}

void Features()//功能
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

void CreateList(LNode * & L, int i)//后插法输入数据,输入顺序和输出顺序一样
{
	LNode *r = new LNode;
	/*L = new LNode;
	L->next = NULL;*/
	r = L;	//指向头节点
	for (int j = 0; j < i; j++)
	{
		LNode *p = new LNode;
		cin >> p->data.no >> p->data.name;
		p->next = NULL;	//p的next为空
		r->next = p;	//r的next指向p
		r = p;			//r指向p
	}
	cout << "输入成功！！！" << endl;
}

//void CreateList(LNode * & L, int i)//前插法输入数据，输入顺序和输出顺序相反
//{
//	for (int j = 0; j < i; j++)
//	{
//		LNode *p = new LNode;
//		cin >> p->data.no >> p->data.name;
//		p->next = L->next;	//p的next指向L的next,刚开始时L->next 为NULL
//		L->next = p;	//L的next指向p
//	}
//	cout << "输入成功！！！" << endl;
//}

int main()
{
	LNode * L = new LNode;//初始化
	int choose = -1;
	Features();
	int i;
	string no;
	string name;
	int insert;
	Stu s;
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
			CreateList(L, i);
			break;
		case 3:
			cout << "请输入你要查找的学号" << endl;
			cin >> no;
			SearchNo(L, no);
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