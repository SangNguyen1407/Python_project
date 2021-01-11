#include <iostream>
#include <fstream>
#include "string.h"
#include "../inc/printLog.h"
#include "../inc/fileHandler.h"

using namespace std;
#define SIZE_MAX	10000


char *readTextFile(char *fileName, char *type)
{
	print_log(CODE_LOG_NORMAL, "call readTextFile function... \n");
	if (fileName == NULL || strcmp(fileName, "") == 0)
	{
		return NULL;
	}
	
	FILE *fp = fopen(fileName, type);
	if (fp == NULL)
	{
		return NULL;
	}
	
	char *buff = (char *)malloc(sizeof(char)* SIZE_MAX);
	fread(buff, SIZE_MAX, sizeof(char), fp);
	fclose(fp);
	
	print_log(CODE_LOG_NORMAL, "the end readTextFile function... \n");
	return (buff);
}

char *readTextFile_org(char *fileName, char type)
{
	print_log(CODE_LOG_NORMAL, "call readTextFile function... \n");
	if (fileName == NULL || strcmp(fileName, "") == 0)
	{
		return RST_ERROR;
	}
	ifstream file;
	string lines;
	
	file.open(fileName);
	if (file.is_open())
	{
		while(getline(file,lines))
		{
			cout << lines << endl;
		}
		file.close();
	}
	else
	{
		print_log(CODE_LOG_ERROR, "Unable to open file... \n");
	}
	
	print_log(CODE_LOG_NORMAL, "the end readTextFile function... \n");
	return "OK";
}

int writeTextFile (char *fileName, char *type, char *content)
{
	if (fileName == NULL || strcmp(fileName, "") == 0)
	{
		return RST_ERROR;
	}
	
	FILE *fp = fopen(fileName, "a+");
	if (fp == NULL)
	{
		cout << "Unable to open file"<< endl;
	}
	fwrite(content, strlen(content), 1, fp);
	fclose(fp);
	
	return RST_SUCCESS;
}
