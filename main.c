#include "Utilities/defTypes.h"
#include "Interface/interface.h"
#include "Tasks/tasks.h"

int main () {
	int N;
	FILE *file_out;

// Citirea datelor si crearea arborelui ---------------------------------------
	Node *trie = readInput(&N);

// Task 1 ---------------------------------------------------------------------
	file_out = fopen("tree.out", "w");
	printTask1(file_out, trie, 0);				// Afisarea solutiei
	fclose(file_out);

// Task 2 ---------------------------------------------------------------------
	solveTask2(trie);							// Rezolvare task 2

	file_out = fopen("hierarchy.out", "w");
	printTask2(file_out, trie, 0);				// Afisarea solutiei
	fclose(file_out);

// Task 3 ---------------------------------------------------------------------
	solveTask3(trie);							// Rezolvare + afisare task 3

// Eliberarea memoriei --------------------------------------------------------
	freeTrie(trie);
	freeNode(trie);

	return 0;
}