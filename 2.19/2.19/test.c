#include <stdio.h>
typedef struct datatype
{
	char num[8];
	char name[8];
	int score;
}datatype;
//��Ԫ��㣬ͷ���
typedef struct Node
{
	datatype data;//������
	struct Node* next;//ָ����
}Node,*LinkList;  
void  initList(LinkList L)//���н��ĵ������ʼ��
{
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL; 
}
void DestroyList(LinkList L)//���ٵ�����
{
	LinkList p;
	p = L;
	p->next;
	free(L);
}
void ClearList(LinkList L)//�������
{
	LinkList p, q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(L);
		p = q;
	}
	L->next = NULL;//��ͷ���ָ����Ϊ��
}
int ListLength(LinkList L)
{
	LinkList p;
	p = L->next;//pָ����Ԫ���ĵ�ַ
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;//����������ͳ�ƽ����
	}
	return i;
}
//ȡֵ�������е�i��Ԫ��
datatype GetList(LinkList L, int i, datatype e)//��e����
{
	LinkList p;
	p = L->next;//ָ����Ԫ���
	int j = 0;
	while (p && j < i)
	{
		p = p->next;//ָ����һ���
		j++;
	}
	if (p == NULL || j > i)
	{
		return 0;
	}
	else
	{
		e = p->data;
	}
	return e;
}
//��ֵ���ҵ�����ָ�����ݵ�λ��
int LocateList(LinkList L, datatype e)
{
	LinkList p;
	p = L->next;
	int j = 1;
	while (p && p->data != e)
	{
		p = p->next;
		j++;
	}
	//�����������������ܣ�һ���ҵ��ˣ���һ��û���ҵ�
	if (p)
	{
		return j;
	}
	else
		return 0;
}
//�ڵ������i��Ԫ��֮ǰ��������e
void ListInsert(LinkList L, int i, int e)
{
	//����Ҫ�ҵ�i-1��λ��
	int j = 1;
	LinkList p;
	p = L->next;
	while (p && j < i - 1)//Ѱ�ҵ�i-1�����
	{
		p = p->next;
		j++;
	}
	if (p == NULL|| j > i - 1)//i����쭳�����С��1
	{
		return 0;
	}
	//�����s����L��
	//����Ҫ����һ�����s
	LinkList s;
	//��i���ĵ�ַ����s��next��
	s->next = p->next;
	p->next = s;
	
}
