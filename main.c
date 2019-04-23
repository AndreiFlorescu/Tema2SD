#include "Utilities/defTypes.h"
#include "Interface/interface.h"
#include "Tasks/tasks.h"

int main () {
	int N;
	FILE *file_out;

	Node *trie = readInput(&N);

// Afisare solutie Task 1 -----------------------------------------------------
	file_out = fopen("tree.out", "w");
	printTask1(file_out, trie, 0);
	fclose(file_out);

// Task 2 ---------------------------------------------------------------------
	solveTask2(trie);

	file_out = fopen("hierarchy.out", "w");
	printTask2(file_out, trie, 0);
	fclose(file_out);

// Task 3 ---------------------------------------------------------------------
	solveTask3(trie);

	freeTrie(trie);
	freeNode(trie);

	return 0;
}