#ifndef INTERFACE
#define INTERFACE

#include <stdio.h>
#include <stdlib.h>
#include "../Utilities/defTypes.h"

Node* readInput(int *N);
void printTask1 (FILE *file, Node *trie, int flag);

#endif