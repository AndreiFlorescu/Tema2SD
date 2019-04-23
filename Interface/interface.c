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