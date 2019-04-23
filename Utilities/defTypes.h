#ifndef DEFTYPES
#define DEFTYPES

typedef struct AdrList {
	char addr[10];
	struct AdrList *next;
} AdrList;

typedef struct List {
	struct Node *cont;
	struct List *next;
} List;

typedef struct Node {
	int id;
	int pid;
	int noAdr;
	struct Node *parent;
	struct AdrList *addr;
	struct List *kids;
} Node;

AdrList *initAdr (char *addr);
void insertAdrLast (AdrList **list, char *addr);
int AdrInList (AdrList *list, char *addr);
void printAdrList (AdrList *list);
void freeAdrList (AdrList *list);

List *initList (Node *node);
void insertListLast (List **list, Node *new);
void removeFromList (List **list, Node* del);
void freeList (List *list);

Node *initNode (int id, int pid, int noAdr, AdrList *list);
void findNode (Node **sol, Node *trie, int node);
void freeTrie (Node *trie);
void freeNode (Node *del);

#endif