#include <stdio.h>
typedef struct datatype
{
	char num[8];
	char name[8];
	int score;
}datatype;
//首元结点，头结点
typedef struct Node
{
	datatype data;//数据域
	struct Node* next;//指针域
}Node,*LinkList;  
void  initList(LinkList L)//带有结点的单链表初始化
{
	L = (LinkList)malloc(sizeof(Node));
	L->next = NULL; 
}
void DestroyList(LinkList L)//销毁单链表
{
	LinkList p;
	p = L;
	p->next;
	free(L);
}
void ClearList(LinkList L)//清空链表
{
	LinkList p, q;
	p = L->next;
	while (p)
	{
		q = p->next;
		free(L);
		p = q;
	}
	L->next = NULL;//将头结点指针域为空
}
int ListLength(LinkList L)
{
	LinkList p;
	p = L->next;//p指向首元结点的地址
	int i = 0;
	while (p)
	{
		i++;
		p = p->next;//遍历单链表，统计结点数
	}
	return i;
}
//取值单链表中第i个元素
datatype GetList(LinkList L, int i, datatype e)//用e带回
{
	LinkList p;
	p = L->next;//指向首元结点
	int j = 0;
	while (p && j < i)
	{
		p = p->next;//指向下一结点
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
//按值查找单链表指定数据的位置
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
	//跳出来，有两个可能，一种找到了，另一种没有找到
	if (p)
	{
		return j;
	}
	else
		return 0;
}
//在单链表第i个元素之前插入数据e
void ListInsert(LinkList L, int i, int e)
{
	//首先要找到i-1的位置
	int j = 1;
	LinkList p;
	p = L->next;
	while (p && j < i - 1)//寻找第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (p == NULL|| j > i - 1)//i大于飙车或者小于1
	{
		return 0;
	}
	//将结点s插入L中
	//首先要定义一个结点s
	LinkList s;
	//将i处的地址放入s的next中
	s->next = p->next;
	p->next = s;
	
}
