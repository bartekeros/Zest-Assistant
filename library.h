#ifndef ZEST_ASSISTANT_LIBRARY_H
#define ZEST_ASSISTANT_LIBRARY_H

#include <stdbool.h>

bool isNumber(char[]);
bool isFolderExisting(char[]);
char* getURL();
int currentLevel();
bool isLevelExisting(int);

#endif
