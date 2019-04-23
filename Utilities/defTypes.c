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
	if (AdrInList(*list, addr)) {
		return;
	}
	AdrList *aux = *list;
	while (aux->next != NULL) {
		aux = aux->next;
	}
	aux->next = initAdr(addr);
	return;
}

int AdrInList (AdrList *list, char *addr) {
	if (list == NULL) {
		return 0;
	}
	AdrList *aux = list;
	while (aux != NULL) {
		if (strcmp(aux->addr, addr) == 0) {
			return 1;
		}
		aux = aux->next;
	}
	return 0;
}

void printAdrList (AdrList *list) {
	AdrList *aux = list;
	while (aux != NULL) {
		printf("%s ", aux->addr);
		aux = aux->next;
	}
	printf("\n");
}

void freeAdrList (AdrList *list) {
	if (list == NULL) {
		return;
	}
	freeAdrList(list->next);
	free(list);
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

void removeFromList (List **list, Node* del) {
	List *aux = *list;
	if (aux->cont == del) {
		*list = (*list)->next;
		free(aux);
	} else {
		while (aux->next != NULL && aux->next->cont != del) {
			aux = aux->next;
		}
		List *tmp = aux->next;
		aux->next = tmp->next;
		free(tmp);
	}
}

void freeList (List *list) {
	if (list == NULL) {
		return;
	}
	freeList(list->next);
	free(list);
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

void findNode (Node **sol, Node *trie, int node) {
	if (trie == NULL) {
		return;
	}

	if (trie->id == node) {
		*sol = trie;
		return;
	}

	List *aux = trie->kids;
	while (aux != NULL) {
		findNode(sol, aux->cont, node);
		aux = aux->next;
	}
}

void freeTrie (Node *trie) {
	if (trie == NULL) {
		return;
	}

	List *aux = trie->kids;
	while (aux != NULL) {
		freeTrie(aux->cont);
		freeNode(aux->cont);
		aux = aux->next;
	}
}

void freeNode (Node *del) {
	freeAdrList(del->addr);
	freeList(del->kids);
	free(del);
}