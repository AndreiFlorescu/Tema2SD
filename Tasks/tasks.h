#ifndef TASKS
#define TASKS

#include <stdio.h>
#include <stdlib.h>
#include "../Utilities/defTypes.h"

void solveTask2 (Node *trie);
void solveTask3 (Node *trie);
void remakeTrie (Node *fail);
void printPath (FILE *file, Node *trie, char *querry, int flag);

#endif