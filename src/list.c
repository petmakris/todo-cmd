#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

List * newNode(int size) {
	List *item = malloc(sizeof(List));
	if (!item) {
		return 0;
	}
	item->data = 0;
	item->type = 0;
	item->size = size;
	item->r = 0;
	item->l = 0;
	return item;
}

List* deleteNode(List **head, List* item) {
	if (!item) return 0;

	if (item->data) free(item->data);

	if (item->l == 0) {
		if (item->r) item->r->l = 0;
		*head = item->r;
	}
	else {
		item->l->r = item->r;
		if (item->r) item->r->l = item->l;
	}
	return item;
}

void deleteByOrder(List **head, int key) {
	List* aux = getNodeByOrder(*head, key);
	if (aux) {
		deleteNode(head, aux);
		free(aux);
	}
}

void pushFirst(List **head, List *item)  {
	if ( *head == 0 ) {
		(*head) = item;
	}
	else {
		item->r = *head;
		item->l = 0;
		(*head)->l = item;
		(*head) = item;
	}
}

void pushLast(List **head, List *item) {
	if (*head == 0) {
		pushFirst(head, item);
	}
	else {
		List *idx = *head;
		while (idx->r != 0) {
			idx = idx->r;
		}
		item->r = 0;
		item->l = idx;
		idx->r = item;
	}
}

List* popFirst(List **head) {
	if (*head == 0) {
		return 0;
	}
	else {
		List* aux = *head;
		(*head) = (*head)->r;
		return aux;
	}
}

List* popLast(List **head) {
	if (*head == 0)	{
		return 0;
	}
	else {
		if (! (*head)->r) {
			List *aux = newNode((*head)->size);
			*aux = ** head;
			free(*head);
			(*head) = 0;
			return aux;
		}
		List *aux = *head;
		while (aux->r) {
			aux = aux->r;
		}

		aux->l->r = 0;
		return aux;			
	}
}

int length(List *head) {
	int count = 0;
	if (head) {
		count = 1;
		while (head->r) {
			head = head->r;
			count++ ;
		}
	}
	return count;
}

List* getNodeByOrder(List *head, int order) {
	if (order > length(head) || (order<1)) {
		return 0;
	}
	int count = 1;

	if (head) while (head->r && count++ < order) {
		head = head->r;
	}
	return head;
}

void printList(List *p, ListFuncType pf) {
	if (p) {
		pf(p);
		while (p->r != 0) {
			p = p->r;
			pf(p);
		}
	}
}

bool listValidOrder(List* head, int order) {
	return !(order<1 || order>length(head));
}

void clearList(List **p)  {
	while (length(*p)) deleteByOrder(p, 1);
}

