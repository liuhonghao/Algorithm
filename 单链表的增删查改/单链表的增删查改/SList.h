#include <bits/stdc++.h>

typedef int SListDataType;
//���
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
//β��
void SListPushBack(SListNode** pphead, SListDataType x);
//βɾ
void SListPopBack(SListNode** pphead);
//ͷ��
void SListPushFront(SListNode* phead, SListDataType x);
//ͷɾ
void SListPopBack(SListNode* phead);

//��ӡ����
void SListPrint(SListNode* phead);