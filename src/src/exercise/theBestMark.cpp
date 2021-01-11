
int printArr(char *arr[], int arr_size)
{
	if (arr == NULL && arr_size == 0)
	{
		return RST_ERROR;
	}
	
	cout << "print arr" << endl;
	for (int i=0; i < arr_size; i++)
	{
		cout << arr[i] << endl;
	}
	
	return RST_SUCCESS;
}

int getTheBestMarkInClass (float *listMark, int len, int *listPos, int group)
{
	if (listMark == NULL || len == 0)
	{
		return 0;
	}
	float listTheBestMark[group];
	int worstMark_pos = 0;
	int worstMark = listMark[worstMark_pos];
	
	for (int i = 0; i < group; i++)
	{
		listPos[i] = i;
		if (worstMark > listMark[i])
		{
			worstMark = listMark[i];
			worstMark_pos = i;
		}
	}
	
	for (int i = group; i < len; i++)
	{
		if (worstMark < listMark[i])
		{
			// update worst Mark
			listPos[worstMark_pos] = i;
			worstMark = listMark[i];
			
			for (int i = 0; i < group; i++)
			{
				if (worstMark > listMark[listPos[i]])
				{
					worstMark = listMark[listPos[i]];
					worstMark_pos = i;
				}
			}
			
		}
		
	}
	
	return 1;
}

int getDatainList (char *listData[], int len, float *listMark)
{
	if(listData == NULL || len == 0)
	{
		return 0;
	}
	char *delimiter = ",";
	char *data;
	char data_temp[100];
	int flag = 1;
	
	for (int i = 0; i< len; i++)
	{
		strcpy(data_temp, listData[i]);
		data = strtok(data_temp, ",");
		while (data != NULL)
		{
			data = strtok(NULL, ",");
			if (flag == 2)
			{
				listMark[i] = (float)atof(data);
				break;
			}
			flag ++;
		}
		flag = 1;
	}
	return 1;
}

int prepareDataForSearch(char *listData[], char *buff)
{
	if (listData == NULL)
	{
		return 0;
	}
	int len, j = 0;
	char *data;
	data = strtok(buff, "\n");
	len = atoi(data);
	cout << len << endl;
	*listData = (char*)malloc(sizeof(char) * len);
	
	for (int i = 0; i < len; i++)
	{
		listData[i] = (char*)malloc(sizeof(char) * 100);
	}
	
	while (j < len)
	{
		data = strtok(NULL, "\r\n");
		strcpy(listData[j], data);
		cout << listData[j] << endl;
		j++;
	}
	
	
	return len;
}

int main ()
{
/*	//test sort
	int arr[] = {4, 13, 69, 1, 100, 67, 30};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int rst = 0; 
	
	cout << "Orginal Sort:" << endl;
	printArr(arr, arr_size);
	cout << endl << endl;
	
	// Merge Sort
	rst = quickSort_temp (arr, 0, arr_size - 1);
	cout << "Merge Sort:" << endl;
	printArr(arr, arr_size);
*/
	char *buff = readTextFile("GradeAclass.txt", "r");
	char **listData; 
	char **listName;
	float *listMark;
	int listPos[3];
	int len = 0;
	
	cout << "3 persons of the best marks" << endl;
	len = prepareDataForSearch(listData, buff);
	cout << endl << endl;
	printArr(listData, len);
	
	listMark = (float *) malloc(sizeof(float) * len);
	getDatainList(listData, len, listMark);
	
	getTheBestMarkInClass(listMark, len, listPos, 3);
	int i = 0;
	
	cout << endl << "list the best Mark:" << endl;
	while (i < 3)
	{
		cout << listData[listPos[i++]] << endl;
	}
	
	
	return RST_SUCCESS;
}