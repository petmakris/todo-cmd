#ifndef __LIST_H__
#define __LIST_H__

#include <stdbool.h>

typedef struct node_t {
	void *data;
	int type;
	int size;
	struct node_t *r;
	struct node_t *l;
} List;

List* newNode(int size);

typedef void (*ListFuncType)(List*);

List * newNode(int size);
List* deleteNode(List **head, List* item);
void deleteByOrder(List **head, int key);
void pushFirst(List **head, List *item);
void pushLast(List **head, List *item);
List* popFirst(List **head);
List* popLast(List **head);
int length(List *head);
List* getNodeByOrder(List *head, int order);
void printList(List *p, ListFuncType pf);
bool listValidOrder(List* head, int order);
void clearList(List **p);

#endif
