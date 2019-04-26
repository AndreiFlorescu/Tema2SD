#include "tasks.h"

// Task 2 ---------------------------------------------------------------------
void solveTask2 (Node *trie) {
	List *aux = trie->kids;
	while (aux != NULL) {
		// "Coboram" in arbore
		solveTask2(aux->cont);

		// Inseram adresele copiilor in tata
		AdrList *adrList = aux->cont->addr;
		while (adrList != NULL) {
			insertAdrLast(&(trie->addr), adrList->addr);
			adrList = adrList->next;
		}
		aux = aux->next;
	}
}

// Task 3 ---------------------------------------------------------------------
void solveTask3 (Node *trie) {
	FILE *file_in;
	Node *fail;
	int noUser;
	int noQueries;
	int i, j;
	file_in = fopen("users.in", "r");
	
	fscanf(file_in, "%d", &noUser);

	// Salveaza adresa nodului la care este legat fiecare user
	Node **nodes = (Node**)malloc(noUser * sizeof(Node*));

	char type;
	int user, node;
	char querry[10];

	// Se creeaza vectorul de adrese de noduri
	for (i = 0; i < noUser; ++i) {
		fscanf(file_in, "%d %d", &user, &node);
		findNode(&nodes[user], trie, node);
	}
	fclose(file_in);

	file_in = fopen("queries.in", "r");
	FILE *file_out = fopen("queries.out", "w");
	fscanf(file_in, "%d\n", &noQueries);

	// Se itereaza prin querry-uri
	for (i = 0; i < noQueries; ++i) {
		fscanf(file_in, "\n%c", &type);

		// Verificam tipul de querry
		if (type == 'q') {
			fscanf(file_in, "%d %s", &user, querry);
			
			// Afisam calea pana la cel mai apropiat nod care contine adresa
			printPath(file_out, nodes[user], querry, 0);
			fprintf(file_out, "\n");
		} else {
			fscanf(file_in, "%d", &node);
			
			// Aflam pozitia serverului cazut
			fail = NULL;
			findNode(&fail, trie, node);
			
			// Daca acesta era deja cazut trecem la urmatorul querry
			if (fail == NULL) {
				continue;
			}

			// Actualizam pozitia utilizatorilor aflati in nodul care a cazut
			for (j = 0; j < noUser; ++j) {
				if (nodes[j]->id == node) {
					nodes[j] = nodes[j]->parent;
				}
			}

			// Refacem Arborele
			remakeTrie(fail);

			// Eliberam nodul
			freeNode(fail);
		}
	}

	// Eliberam memoria si fisierele folosite
	free(nodes);
	fclose(file_out);
	fclose(file_in);
}

// Refacerea arborelui
void remakeTrie (Node *fail) {
	Node *parent = fail->parent;
	List *aux = fail->kids;
	
	while (aux != NULL) {
		// Updatam tatal copiilor nodului care a cazut
		aux->cont->parent = fail->parent;

		// Inseram copii nodului cazut in lista de copii a tatalui
		insertListLast(&parent->kids, aux->cont);

		aux = aux->next;
	}

	// Scoatem nodul cazut din copii tatalui
	removeFromList(&parent->kids, fail);
}

// Afisarea caii
void printPath (FILE *file, Node *trie, char *querry, int flag) {
	if (flag == 1) {
		fprintf(file, " ");
	}
	flag = 1;

	// Afiseaza nodul curent
	fprintf(file, "%d", trie->id);

	// Daca adresa nu poate fi rezolvata de nodul curent mergem in parinte 
	if (!AdrInList(trie->addr, querry)) {
		// Updatam lista de adrese cu noua adresa
		insertAdrLast(&trie->addr, querry);
		printPath(file, trie->parent, querry, flag);
	}
}