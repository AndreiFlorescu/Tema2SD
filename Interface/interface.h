/* Headerul care contine functiile de I/O folosite */

#ifndef INTERFACE
#define INTERFACE

#include <stdio.h>
#include <stdlib.h>
#include "../Utilities/defTypes.h"

Node* readInput(int *N);
void printTask1 (FILE *file, Node *trie, int flag);
void printTask2 (FILE *file, Node *trie, int flag);

#endif