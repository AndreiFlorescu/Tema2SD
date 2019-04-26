#include "defTypes.h"

// Functii pentru lista de adrese ---------------------------------------------
// Initializeaza un element
AdrList *initAdr (char *addr) {
	AdrList *new = (AdrList*)malloc(sizeof(AdrList));
	new->next = NULL;
	strcpy(new->addr, addr);
	return new;
}

// Inserarea la coada listei
void insertAdrLast (AdrList **list, char *addr) {
	// Daca lista e goala o initializam
	if (*list == NULL) {
		*list = initAdr(addr);
		return;
	}

	// Verificam daca adrese apartine deja listei
	if (AdrInList(*list, addr)) { // Daca da, nu o mai adaugam
		return;
	}

	// Iteram pana la sfarsit
	AdrList *aux = *list;
	while (aux->next != NULL) {
		aux = aux->next;
	}

	// Inseram noul element
	aux->next = initAdr(addr);
	return;
}

// Verifica daca o adresa exista in lista
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

// Afiseaza lista de adrese
void printAdrList (AdrList *list) {
	AdrList *aux = list;
	while (aux != NULL) {
		printf("%s ", aux->addr);
		aux = aux->next;
	}
	printf("\n");
}

// Elibereaza memoria listei de adrese
void freeAdrList (AdrList *list) {
	if (list == NULL) {
		return;
	}
	freeAdrList(list->next);
	free(list);
}

// Functii pentru lista de copii ----------------------------------------------
// Initializeaza un element
List *initList (Node *node) {
	List *new = (List*)malloc(sizeof(List));
	new->cont = node;
	new->next = NULL;
	return new;
}

// Inserare la coada listei
void insertListLast (List **list, Node *new) {
	// Daca lista e goala o initializam
	if (*list == NULL) {
		*list = initList(new);
		return;
	}

	// Iteram pana la sfarsit
	List *aux = *list;
	while (aux->next != NULL) {
		aux = aux->next;
	}

	// Inseram noul element
	aux->next = initList(new);
}

// Stergerea unui nod din lista de copii
void removeFromList (List **list, Node* del) {
	List *aux = *list;
	if (aux->cont == del) {		// Daca e la inceput
		*list = (*list)->next;
		free(aux);
	} else {					// Daca e la mijloc sau sfarsit
		while (aux->next != NULL && aux->next->cont != del) {
			aux = aux->next;
		}
		List *tmp = aux->next;
		aux->next = tmp->next;
		free(tmp);
	}
}

// Elibereaza memoria listei de copii 
void freeList (List *list) {
	if (list == NULL) {
		return;
	}
	freeList(list->next);
	free(list);
}

// Functii pentru nodurile arborelui ------------------------------------------
// Initializeaza un nod
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

// Gaseste un nod dupa indice in arbore
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

// Elibereaza arborele
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

// Elibereaza un nod
void freeNode (Node *del) {
	freeAdrList(del->addr);
	freeList(del->kids);
	free(del);
}