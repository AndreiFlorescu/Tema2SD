#include "Utilities/defTypes.h"
#include "Interface/interface.h"

int main () {
	int N;

	Node *trie = readInput(&N);

	FILE *file_out = fopen("tree.out", "w");
	printTask1(file_out, trie, 0);
	fclose(file_out);
	
	return 0;
}