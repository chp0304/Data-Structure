#include<iostream>
#include<string>
#define MAX 100
#define OK 1
#define ERROR 0 
#define OVERFLOW -1
using namespace std;

typedef struct//ѧ���ṹ�� 
{
	string no;//ѧ��
	string name;//����
}Stu;

typedef struct LNode 
{
	Stu data;
	struct LNode *next;
}LNode;

void Show(Stu s)
{
	cout << "ѧ�ţ�" << s.no << " " << "������" << s.name << endl;
}

int InitList(LNode * &L)//��ʼ������
{
	L = new LNode;
	L->next = NULL;
	cout << "�ɹ���������" << endl;
	return OK;
}

int SearchNo(LNode *L, string no)//��ѧ�Ų���
{
	LNode *p = L->next;//p ָ����Ԫ�ڵ�
	while (p && p->data.no != no)
	{
		p = p->next;
	}
	if(p)//�ж��Ƿ�鵽
		Show(p->data);//��ʾ��Ϣ
	else 
		cout << "δ��ѯ����ѧ�ţ�����" << endl;
	return OK;
}

int SearchNA(LNode *L, string name)//����������
{
	LNode *p = L->next;
	while (p && p->data.name != name)
	{
		p = p->next;
	}
	if (p)
		Show(p->data);
	else
		cout << "δ��ѯ��������������" << endl;
	return OK;
}

int Insert(LNode *&L, int i, Stu s)//����
{
	LNode *p = L;
	LNode *a = new LNode;
	int j = 0;//������
	while (p && (j < i - 1))//��һ��ָ���Ϊ��Ԫ�ڵ�
	{
		p = p->next;//���ҵ�i-1�Ľڵ㣬��ʹpָ��a
		j++;
	}
	if (!p || j > i - 1)//i < 1
	{
		cout << "����ʧ�ܣ�����" << endl;
		return ERROR;
	}
	a->data = s;//����������
	a->next = p->next;//a��next ָ��p��next
	p->next = a;//p��next ָ��a,��ɲ���
	cout << "����ɹ�������" << endl;
	return OK;
}

int Delete(LNode * &L, int i)//ɾ��
{
	LNode *p = L;
	LNode *a;
	int j = 0;
	while (p && (j < i - 1))//��һ��ָ���Ϊ��Ԫ�ڵ�
	{
		p = p->next;//��ѯ��i-1���ڵ�
		j++;
	}
	if (!(p->next) || (i < 1))//i<1 ���� ɾ��λ�ò�����
	{
		cout << "ɾ��ʧ�ܣ�����" << endl;
		return ERROR;
	}
	LNode *q = p->next;//q ΪҪɾ���Ľڵ�
	p->next = q->next;//q��ǰ�νڵ� ָ��q�����νڵ�
	delete q;//�ͷ�q�ĵ�ַ
	cout << "ɾ���ɹ�������" << endl;
	return OK;
}

void Show(LNode *L)//����
{
	LNode *p = L->next;
	while (p)
	{
		cout << "ѧ��:" << p->data.no << " " << "����:" << p->data.name << endl;
		p = p->next;
	}
	
}

void Features()//����
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

void CreateList(LNode * & L, int i)//��巨��������,����˳������˳��һ��
{
	LNode *r = new LNode;
	/*L = new LNode;
	L->next = NULL;*/
	r = L;	//ָ��ͷ�ڵ�
	for (int j = 0; j < i; j++)
	{
		LNode *p = new LNode;
		cin >> p->data.no >> p->data.name;
		p->next = NULL;	//p��nextΪ��
		r->next = p;	//r��nextָ��p
		r = p;			//rָ��p
	}
	cout << "����ɹ�������" << endl;
}

//void CreateList(LNode * & L, int i)//ǰ�巨�������ݣ�����˳������˳���෴
//{
//	for (int j = 0; j < i; j++)
//	{
//		LNode *p = new LNode;
//		cin >> p->data.no >> p->data.name;
//		p->next = L->next;	//p��nextָ��L��next,�տ�ʼʱL->next ΪNULL
//		L->next = p;	//L��nextָ��p
//	}
//	cout << "����ɹ�������" << endl;
//}

int main()
{
	LNode * L = new LNode;//��ʼ��
	int choose = -1;
	Features();
	int i;
	string no;
	string name;
	int insert;
	Stu s;
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
			CreateList(L, i);
			break;
		case 3:
			cout << "��������Ҫ���ҵ�ѧ��" << endl;
			cin >> no;
			SearchNo(L, no);
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