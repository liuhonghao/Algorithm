#define _CRT_SECURE_NO_WARNINGS 1


#include "SList.h"

int main()
{
	SListNode *pList = NULL;

	//¥Ú”°¡¥±Ì
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPrint(pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);

	return 0;
}