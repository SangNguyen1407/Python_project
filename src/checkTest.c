#include<stdio.h>
#include<string.h>

#define DATA_CONTENT_SIZE 100
int main()
{
	char strData[DATA_CONTENT_SIZE];
	char strComp[DATA_CONTENT_SIZE];
	int strData_size = 0;
	int strComp_size = 0;
	int flag = 0;
	int count = 0;
	
	strcpy(strData, "Hello World, Nguyenang Hoang Sang");
	strcpy(strComp, "ang");
	
	strData_size = strlen(strData);
	strComp_size = strlen(strComp);
	
	for (int i = 0; i < (strData_size - strComp_size) + 1; i++)
	{
		flag = -1;
		for (int j = 0; j < strComp_size; j++)
		{
		//	printf ("%c - %c\n", strData[i+j], strComp[j]);
			if (strComp[j] != strData[i+j])
			{
				flag = 0;
				break;
			}
			else if ((j == strComp_size-1) && (flag == -1))
			{
				flag = 1;
				break;
			}
		}
		
		if (flag == 1)
		{
			count++;
		}
	}
	printf ("The string Data: %s\n", strData);
	printf ("The string Component: %s\n", strComp);
	
	if (count > 0)
	{
		printf ("%d\n", count);
	}
	else
	{
		printf ("SEARCH UNSUCCESSFUL\n");
	}
	
}
