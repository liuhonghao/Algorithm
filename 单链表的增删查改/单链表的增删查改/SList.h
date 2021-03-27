#include <bits/stdc++.h>

typedef int SListDataType;
//结点
typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;

}SListNode;

//struct Slist
//{
//	SListNode* head;
//
//};
//尾插
void SListPushBack(SListNode** pphead, SListDataType x);
//尾删
void SListPopBack(SListNode** pphead);
//头插
void SListPushFront(SListNode* phead, SListDataType x);
//头删
void SListPopBack(SListNode* phead);

//打印链表
void SListPrint(SListNode* phead);