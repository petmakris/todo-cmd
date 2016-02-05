#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

ctList * NewNode(int size)
{
	ctList *item = malloc(sizeof(ctList));
	if (!item)
	{
		fprintf(stderr, "::NewNode()\n");
		return 0;
	}
	item->data = 0;
	item->type = 0;
	item->size = size;
	item->r = 0;
	item->l = 0;
	return item;
}

ctList* DeleteNode(ctList **head, ctList* item)
{
	if (!item) return 0;

	if (item->data) free(item->data);

	if (item->l == 0)
	{
		if (item->r) item->r->l = 0;
		*head = item->r;
	}
	else
	{
		item->l->r = item->r;
		if (item->r) item->r->l = item->l;
	}
	return item;
}

void DeleteByOrder(ctList **head, int key)
{
	ctList* aux = GetNodeByOrder(*head, key);
	if (aux) 
	{
		DeleteNode(head, aux);
		free(aux);
	}
}

void PushFirst(ctList **head, ctList *item) 
{
	if ( *head == 0 )
		(*head) = item;
	else
	{
		item->r = *head;
		item->l = 0;
		(*head)->l = item;
		(*head) = item;
	}
}

void PushLast(ctList **head, ctList *item)
{
	if (*head == 0)
		PushFirst(head, item);
	else
	{
		ctList *idx = *head;
		while (idx->r != 0)
			idx = idx->r;

		item->r = 0;
		item->l = idx;
		idx->r = item;
	}
}

ctList* PopFirst(ctList **head)
{
	if (*head == 0)
		return 0;
	else
	{
		ctList* aux = *head;
		(*head) = (*head)->r;
		return aux;
	}
}

ctList* PopLast(ctList **head)
{
	if (*head == 0)	return 0;
	else
	{
		if (! (*head)->r)
		{
			ctList *aux = NewNode((*head)->size);
			*aux = ** head;
			free(*head);
			(*head) = 0;
			return aux;
		}
		ctList *aux = *head;
		while (aux->r) aux = aux->r;

		aux->l->r = 0;
		return aux;			
	}
}


int Length(ctList *head)
{
	int count = 0;
	if (head)
	{
		count = 1;
		while (head->r)
		{
			head = head->r;
			count++ ;
		}
	}
	return count;
}

ctList* GetNodeByOrder(ctList *head, int order)
{
	if (order > Length(head) || (order<1))
		return 0;

	int count = 1;

	if (head) while (head->r && count++ < order)
		head = head->r;
		
	return head;
}

void PrintList(ctList *p, ListFuncType pf)
{
	if (p)
	{
		pf(p);
		while (p->r != 0)
		{
			p = p->r;
			pf(p);
		}
	}
}

bool ListValidOrder(ctList* head, int order)
{
	return !(order<1 || order>Length(head));
}

void ClearList(ctList **p) 
{
	while (Length(*p)) DeleteByOrder(p, 1);
}

