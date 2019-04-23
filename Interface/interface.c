#include "interface.h"

Node* readInput(int *N) {
	FILE *file_in = fopen("tree.in", "r");
	int id, pid, noAdr;
	Node *trie = NULL;
	Node *node = NULL;
	AdrList *tmpAdrList = NULL;
	int i;

	char addr[10];

	fscanf(file_in, "%d", N);

	Node **data = (Node**)malloc(*N * sizeof(Node*));

	for (i = 0; i < *N; ++i) {
		fscanf(file_in, "%d %d %d", &id, &pid, &noAdr);
		tmpAdrList = NULL;

		int j;
		for (j = 0; j < noAdr; ++j) {
			fscanf(file_in, "%s", addr);
			insertAdrLast (&tmpAdrList, addr);
		}
		node = initNode(id, pid, noAdr, tmpAdrList);

		data[id] = node;
	}


	// Generarea vectorului care contine lista copiilor
	for (i = 0; i < *N; ++i) {
		if (data[i]->pid != -1) {
			insertListLast(&data[data[i]->pid]->kids, data[i]);
			data[i]->parent = data[data[i]->pid];
		} else {
			trie = data[i];
		}
	}

	free(data);
	fclose(file_in);
	return trie;
}

void printTask1 (FILE *file, Node *trie, int flag) {
	if (trie == NULL) {
		return;
	}
	if (flag == 1) {
		fprintf(file, "\n");
	}
	flag = 1;

	fprintf(file, "%d", trie->id);
	List *aux = trie->kids;
	while (aux != NULL) {
		fprintf(file, " %d", aux->cont->id);
		aux = aux->next;
	}

	aux = trie->kids;
	while (aux != NULL) {
		printTask1(file, aux->cont, flag);
		aux = aux->next;
	}
}


/// DE MUTAT +=======================+++++++++++++++++===+++++=====+++=========

/*void solveTask2 (Node *trie) {
	List *aux = trie->kids;
	while (aux != NULL) {
		solveTask2(aux->cont);
		AdrList *adrList = aux->cont->addr;
		while (adrList != NULL) {
			insertAdrLast(&(trie->addr), adrList->addr);
			adrList = adrList->next;
		}
		aux = aux->next;
	}
}*/

void printTask2 (FILE *file, Node *trie, int flag) {
	if (trie == NULL) {
		return;
	}
	if (flag == 1) {
		fprintf(file, "\n");
	}
	flag = 1;

	fprintf(file, "%d", trie->id);
	AdrList *itAdr = trie->addr;
	while (itAdr != NULL) {
		fprintf(file, " %s", itAdr->addr);
		itAdr = itAdr->next;
	}

	List *it = trie->kids;
	while (it != NULL) {
		printTask2(file, it->cont, flag);
		it = it->next;
	}
}

/*void solveTask3 (Node *trie) {
	FILE *file_in;
	Node *fail;
	int noUser;
	int noQueries;
	int i, j;
	file_in = fopen("users.in", "r");
	
	fscanf(file_in, "%d", &noUser);

	Node **nodes = (Node**)malloc(noUser * sizeof(Node*));

	char type;
	int user, node;
	char querry[10];

	for (i = 0; i < noUser; ++i) {
		fscanf(file_in, "%d %d", &user, &node);
		findNode(&nodes[user], trie, node);
	}
	fclose(file_in);

	file_in = fopen("queries.in", "r");
	FILE *file_out = fopen("queries.out", "w");
	fscanf(file_in, "%d\n", &noQueries);

	for (i = 0; i < noQueries; ++i) {
		fscanf(file_in, "\n%c", &type);
		if (type == 'q') {
			fscanf(file_in, "%d %s", &user, querry);
			
			printPath(file_out, nodes[user], querry, 0);
			fprintf(file_out, "\n");
		} else {
			fscanf(file_in, "%d", &node);
			fail = NULL;
			findNode(&fail, trie, node);
			if (fail == NULL) {
				continue;
			}

			for (j = 0; j < noUser; ++j) {
				if (nodes[j]->id == node) {
					nodes[j] = nodes[j]->parent;
				}
			}

			remakeTrie(fail);
			freeNode(fail);
		}
	}
	free(nodes);
	fclose(file_out);
	fclose(file_in);
}

void remakeTrie (Node *fail) {
	Node *parent = fail->parent;
	List *aux = fail->kids;
	
	while (aux != NULL) {
		aux->cont->parent = fail->parent;
		insertListLast(&parent->kids, aux->cont);
		aux = aux->next;
	}

	removeFromList(&parent->kids, fail);
}

void printPath (FILE *file, Node *trie, char *querry, int flag) {
	if (flag == 1) {
		fprintf(file, " ");
	}
	flag = 1;

	fprintf(file, "%d", trie->id);
	if (!AdrInList(trie->addr, querry)) {
		insertAdrLast(&trie->addr, querry);
		createPath(file, trie->parent, querry, flag);
	}
}*/