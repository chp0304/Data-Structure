#include<iostream>
#include<string>
#define MAX 100
#define OK 1
#define ERROR 0 
#define OVERFLOW -1
using namespace std;


typedef struct//ѧ���ṹ�� 
{
	string no;
	string name;
}Stu;


typedef struct //ѭ���ṹ�� 
{
	Stu *elem;//�˴���Ϊָ�룬��Ϊ���½����ʱ��Ϊ�������˿ռ䡣�൱�����飬ָ���һ��Ԫ��
	int length;
}SqList;

void Show(Stu s)
{
	cout << "ѧ�ţ�" << s.no << " " << "������" << s.name << endl;
}

int InitList(SqList &L)//�½�˳��� 
{
	L.elem = new Stu[MAX];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	cout << "ѭ������ɹ���" << endl;
	return OK;
}

int SearchNO(SqList L, string no)//��ѧ�Ų��� 
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i].no == no)
		{
			Show(L.elem[i]);
			return 0;
		}
	}
	cout << "δ��ѯ����ѧ�ţ�����" << endl;
	return 0 ;
}

int SearchNA(SqList L, string name)//���������� 
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i].name == name)
		{
			Show(L.elem[i]);
			return 0;
		}
	}
	cout << "δ��ѯ��������������" << endl;
	return 0;
}

int Insert(SqList &L, int i, Stu s)//���� 
{
	if ((i < 1) || (i > L.length + 1))
	{
		return ERROR;
	}
	if (L.length == MAX)
	{
		cout << "����ռ�����" << endl;
	}
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = s;
	L.length++;
	cout << "����ɹ���" << endl;
	return OK;
}

int Delete(SqList &L, int i)//ɾ�� 
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
	cout << "ɾ���ɹ���" << endl;
	return OK;
}

void Show(SqList L)//��ʾ��Ϣ 
{

	for (int i = 0; i < L.length; i++)
	{
		cout << "ѧ��:" << L.elem[i].no << " " << "����:" << L.elem[i].name << endl;
	}
}


void Features()
{
	cout << "1. ����˳���\n";
	cout << "2. ��������\n";
	cout << "3. ��ѧ�Ų���\n";
	cout << "4. ����������\n";
	cout << "5. ����\n";
	cout << "6. ɾ��\n";
	cout << "7. �������\n";
	cout << "0. �˳�\n\n";
	

}
int main()
{
	SqList L;//ѭ��� 
	Stu s;
	string no;
	string name;
	int insert;
	int i;
	int choose = -1;
	Features();
	while (choose != 0)
	{
		cout << "��������Ҫѡ��Ĳ�����\n";
		cin >> choose;
		switch (choose)//ѡ�����
		{
			case 1:
				InitList(L);
				break;
			case 2:
				cout << "��������Ҫ�������ݵĸ�����";
				cin >> i;
				for (int j = 0; j < i; j++)
				{
					cin >> L.elem[j].no >> L.elem[j].name;
				}
				L.length = i;
				break;
			case 3:
				cout << "��������Ҫ���ҵ�ѧ��" << endl;
				cin >> no;
				SearchNO(L, no);
				break;
			case 4:
				cout << "��������Ҫ���ҵ�����" << endl;
				cin >> name;
				SearchNA(L, name);
				break;
			case 5:
				cout << "��������Ҫ�����λ��" << endl;
				cin >> insert;
				cout << "��������Ҫ�����ѧ����Ϣ" << endl;
				cin >> s.no >> s.name;
				Insert(L, insert, s);
				break;
			case 6:
				cout << "��������Ҫɾ����λ��" << endl;
				cin >> i;
				Delete(L, i);
				break;
			case 7:
				Show(L);
				break;
		}
	}
	cout << "���˳�!" << endl;
	return 0;
}