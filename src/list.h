#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>

typedef struct node_t
{
	void *data;
	int type;
	int size;
	struct node_t *r;
	struct node_t *l;
} ctList;

ctList* NewNode(int size);

typedef void (*ListFuncType)(ctList*);

ctList * NewNode(int size);
ctList* DeleteNode(ctList **head, ctList* item);
void DeleteByOrder(ctList **head, int key);
void PushFirst(ctList **head, ctList *item);
void PushLast(ctList **head, ctList *item);
ctList* PopFirst(ctList **head);
ctList* PopLast(ctList **head);
int Length(ctList *head);
ctList* GetNodeByOrder(ctList *head, int order);
void PrintList(ctList *p, ListFuncType pf);
bool ListValidOrder(ctList* head, int order);
void ClearList(ctList **p);

#endif
