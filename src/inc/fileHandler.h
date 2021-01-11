#include<iostream>
#include<string.h>

#define RST_ERROR			0
#define RST_SUCCESS			1

char *readTextFile(char *fileName, char *type);
int writeTextFile (char *fileName, char *type, char *content);