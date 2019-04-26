/* Headerul care contine structutile folosite si functiile acestora*/

#ifndef DEFTYPES
#define DEFTYPES

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Lista de adrese
typedef struct AdrList {
	char addr[10];
	struct AdrList *next;
} AdrList;

// Lista de copii
typedef struct List {
	struct Node *cont;
	struct List *next;
} List;

// Nodurile arborelui
typedef struct Node {
	int id;
	int pid;
	int noAdr;
	struct Node *parent;
	struct AdrList *addr;
	struct List *kids;
} Node;

// Functii pentru lista de adrese ---------------------------------------------
AdrList *initAdr (char *addr);
void insertAdrLast (AdrList **list, char *addr);
int AdrInList (AdrList *list, char *addr);
void printAdrList (AdrList *list);
void freeAdrList (AdrList *list);

// Functii pentru lista de copii ----------------------------------------------
List *initList (Node *node);
void insertListLast (List **list, Node *new);
void removeFromList (List **list, Node* del);
void freeList (List *list);

// Functii pentru nodurile arborelui ------------------------------------------
Node *initNode (int id, int pid, int noAdr, AdrList *list);
void findNode (Node **sol, Node *trie, int node);
void freeTrie (Node *trie);
void freeNode (Node *del);

#endif