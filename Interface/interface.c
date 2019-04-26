#include "interface.h"

// Citirea --------------------------------------------------------------------
// Functia returneaza radacina arborelui
Node* readInput(int *N) {
	FILE *file_in = fopen("tree.in", "r");
	int id, pid, noAdr;
	Node *trie = NULL;				// Arborele final
	Node *node = NULL;
	AdrList *tmpAdrList = NULL;		// Lista temporara a adreselor unui nod
	int i;

	char addr[10];

	fscanf(file_in, "%d", N);

	// Un vector de noduri pentru stocarea datelor inainte de prelucrare
	Node **data = (Node**)malloc(*N * sizeof(Node*));	

	for (i = 0; i < *N; ++i) {
		fscanf(file_in, "%d %d %d", &id, &pid, &noAdr);
		tmpAdrList = NULL;

		int j;
		for (j = 0; j < noAdr; ++j) {
			fscanf(file_in, "%s", addr);
			// Crearea listei de adrese
			insertAdrLast (&tmpAdrList, addr);			
		}

		// Initializarea nodului curent
		node = initNode(id, pid, noAdr, tmpAdrList);	

		data[id] = node;
	}


	// Generarea arborelui
	for (i = 0; i < *N; ++i) {
		if (data[i]->pid != -1) { 	// Daca nodul curent nu e radacina
			// Introducem nodul curent in lista de copii a parintelui
			insertListLast(&data[data[i]->pid]->kids, data[i]);

			// Setam tatal
			data[i]->parent = data[data[i]->pid];
		} else {					// Daca nodul curent este radacina
			trie = data[i];
		}
	}

	// Eliberam memoria si fisierele
	free(data);
	fclose(file_in);

	return trie;
}

// Afisarea Task 1 ------------------------------------------------------------
void printTask1 (FILE *file, Node *trie, int flag) {
	if (trie == NULL) {
		return;
	}

	// In cazul in care e prima linie nu dam \n
	if (flag == 1) {			
		fprintf(file, "\n");
	}
	flag = 1;

	// Afisam nodul curent
	fprintf(file, "%d", trie->id);		

	// Afisam id-ul copiilor
	List *aux = trie->kids;
	while (aux != NULL) {
		fprintf(file, " %d", aux->cont->id);
		aux = aux->next;
	}

	// Intram in fiecare nod copil
	aux = trie->kids;
	while (aux != NULL) {
		printTask1(file, aux->cont, flag);
		aux = aux->next;
	}
}

// Afisarea Task 2 ------------------------------------------------------------
void printTask2 (FILE *file, Node *trie, int flag) {
	if (trie == NULL) {
		return;
	}

	// In cazul in care e prima linie nu dam \n
	if (flag == 1) {
		fprintf(file, "\n");
	}
	flag = 1;

	// Afisam nodul curent
	fprintf(file, "%d", trie->id);

	// Afisam adresele pe care le poate rezolva nodul
	AdrList *itAdr = trie->addr;
	while (itAdr != NULL) {
		fprintf(file, " %s", itAdr->addr);
		itAdr = itAdr->next;
	}

	// Intram in fiecare nod copil si repetam procesul
	List *it = trie->kids;
	while (it != NULL) {
		printTask2(file, it->cont, flag);
		it = it->next;
	}
}