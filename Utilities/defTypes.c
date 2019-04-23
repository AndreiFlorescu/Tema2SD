#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "defTypes.h"

// AdrList -----------

AdrList *initAdr (char *addr) {
	AdrList *new = (AdrList*)malloc(sizeof(AdrList));
	new->next = NULL;
	strcpy(new->addr, addr);
	return new;
}

void insertAdrLast (AdrList **list, char *addr) {
	if (*list == NULL) {
		*list = initAdr(addr);
		return;
	}
	AdrList *aux = *list;
	while (aux->next != NULL) {
		aux = aux->next;
	}
	aux->next = initAdr(addr);
	return;
}

void printAdrList (AdrList *list) {
	AdrList *aux = list;
	while (aux != NULL) {
		printf("%s ", aux->addr);
		aux = aux->next;
	}
	printf("\n");
}

// List ----------
List *initList (Node *node) {
	List *new = (List*)malloc(sizeof(List));
	new->cont = node;
	new->next = NULL;
	return new;
}

void insertListLast (List **list, Node *new) {
	if (*list == NULL) {
		*list = initList(new);
		return;
	}
	List *aux = *list;
	while (aux->next != NULL) {
		aux = aux->next;
	}
	aux->next = initList(new);
}

// Node ----------
Node *initNode (int id, int pid, int noAdr, AdrList *list) {
	Node *new = (Node*)malloc(sizeof(Node));
	new->id = id;
	new->pid = pid;
	new->noAdr = noAdr;
	new->parent = NULL;
	new->addr = list;
	new->kids = NULL;
	return new;
}