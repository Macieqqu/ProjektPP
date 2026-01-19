#ifndef FILE_UTIL_H
#define FILE_UTIL_H
#include "common.h"

List loadFile(char *fileName);
int saveFile(char *fileName, List *list);

#endif