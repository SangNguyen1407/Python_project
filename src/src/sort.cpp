#include <iostream>
#include <string.h>
#include "../inc/sort.h"
#include "../inc/printLog.h"

using namespace std;

int printArr(int *arr, int arr_size)
{
	if (arr == NULL && arr_size == 0)
	{
		return RST_ERROR;
	}
	
	cout << "print arr" << endl;
	for (int i=0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	
	return RST_SUCCESS;
}

int swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
	
	return RST_SUCCESS;
}

int selectSort (int *arr, int arr_size)
{
	print_log(CODE_LOG_NORMAL, "call selectSort function... \n");
	int numberPos = 0;
	if (arr == NULL)
	{
		return RST_ERROR;
	}
	
	if (arr_size == 1)
	{
		return RST_SUCCESS;
	}
	
	for(int i = 0; i < arr_size - 1; i++)
	{
		numberPos = i;
		for (int j = i+1; j < arr_size; j ++)
		{
			if (arr[numberPos] > arr[j])
			{
				numberPos = j;
			}
		}
		if (numberPos != i)
		{
			int temp = 0;
			temp = arr[i];
			arr[i] = arr[numberPos];
			arr[numberPos] = temp;
		}
	}
	
	print_log(CODE_LOG_NORMAL, "END selectSort function... \n");
	return RST_SUCCESS;
}


int bubbleSort(int *arr, int arr_size)
{
	print_log(CODE_LOG_NORMAL, "call bubbleSort function... \n");
	int temp = 0;
	
	if (arr == NULL)
	{
		return RST_ERROR;
	}
	
	if (arr_size == 1)
	{
		return RST_SUCCESS;
	}
	
	for(int i=1; i < arr_size; i++ )
	{
		for (int j=arr_size-1; j>i; j-- )
		{
			if(arr[j] < arr[j-1])
			{
				temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	print_log(CODE_LOG_NORMAL, "END selectSort function... \n");
	return RST_SUCCESS;
}

int partition(int *arr, int low, int high)
{
	int pivot = arr[high];//先頭要素をpivotとする
	int i = low - 1; 
	
	for (int j = low; j < high; j++)
	{
		//pivotより小さいものを左へ、大きいものを右へ
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]);
	
	return (i+1);
}


/*
 * Quick sort do not use Recursion logic for code
 */
int quickSort_temp(int *arr, int low, int high)
{
	if (arr == NULL)
	{
		cout << "ERROR" << endl;
		return RST_ERROR;
	}
	int left_pos = 0, high_pos = 0;
	int swap_pos = high;
	int flag = 0;
	int swap_temp = 0;
	
	while (swap_pos > 1)
	{
		swap_pos = partition(arr, 0, swap_pos);
		if (!flag)
		{
			swap_temp = swap_pos;
			flag = 1;
		}
		swap_pos--;
		cout << "test" << swap_pos << endl;
	}
	
	swap_pos = swap_temp+1;
	while (swap_pos < high)
	{
		swap_pos = partition(arr, swap_pos, high);
		swap_pos++;
	}
	
	return RST_SUCCESS;
}

/*
 * Quick sort 
 */
int quickSort(int *arr, int low, int high)
{
	int pivot = 0;
	int left_pos = 0, high_pos = 0;
	
	if (arr == NULL)
	{
		return RST_ERROR;
	}
	
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi-1);
		/*piは*/
		quickSort(arr, pi+1, high);
	}
	return RST_SUCCESS;
}

int adjust(int *arr, int arr_size, int rootNodePos)
{
	int key = arr[rootNodePos];
	int checkNodePos = 0;
	
	while (true)
	{
		checkNodePos = (rootNodePos * 2 ) + 1;
		if (checkNodePos > arr_size)
		{
			break;
		}
		
		if (checkNodePos != arr_size)
		{
			if (arr[checkNodePos + 1] > arr[checkNodePos])
			{
				checkNodePos = checkNodePos + 1;
			}
		}
		
		if (key >= arr[checkNodePos])
		{
			break;
		}
		
		arr[rootNodePos] = arr[checkNodePos];
		rootNodePos = checkNodePos;
	}
	arr[rootNodePos] = key;
	
	
	return RST_SUCCESS;
}

int heapSort(int *arr, int arr_size)
{
	print_log(CODE_LOG_NORMAL, "call heapSort function... \n");
	int j, v;
	for (int i = (arr_size - 1)/2; i >= 0; i--)
	{
		adjust(arr, arr_size, i);
	}
	
	for (int i = arr_size - 1; i > 0;i--)
	{
		swap(&arr[0], &arr[i]);		
		adjust(arr, i-1, 0);
	}
	
	print_log(CODE_LOG_NORMAL, "END heapSort function... \n");
	return RST_SUCCESS;
}

int merge(int *arr_left, int left_size, int *arr_right, int right_size, int *arr)
{
	int left_pos = 0, right_pos = 0, arr_pos = 0;
	while(left_pos < left_size || right_pos < right_size)
	{
		if (right_pos >= right_size || 
		    (left_pos< left_size && 
			 arr_left[left_pos] < arr_right[right_pos]
			)
		   )
		{
			arr[arr_pos++] = arr_left[left_pos];
			left_pos++;
		}
		else
		{
			arr[arr_pos++] = arr_right[right_pos];
			right_pos++;
		}
	}
	
	return RST_SUCCESS;
}

int mergeSort(int *arr, int arr_size)
{
	if (arr == NULL)
	{
		return RST_ERROR;
	}
	int left_size   = arr_size/2;
	int right_size  = arr_size - left_size;
	int *arr_left  = new int[left_size];
	int *arr_right = new int[right_size];

	if (arr_size > 1)
	{
		for (int i = 0; i< left_size; i++)
		{
			arr_left[i] = arr[i];
		}
		
		for (int i = 0; i< right_size; i++)
		{
			arr_right[i] = arr[left_size+i];
		}

		mergeSort(arr_left, left_size);
		mergeSort(arr_right, right_size);
		merge(arr_left, left_size, arr_right, right_size, arr);

	}
	
	return RST_SUCCESS;
}
/*
int main ()
{
	int arr[] = {42, 13, 69, 1, 100, 67, 3};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int rst = 0; 
	
	cout << endl;
	printArr(arr, arr_size);
	
	
	
	rst = selectSort (arr, arr_size);
	printArr(arr, arr_size);
	cout << endl;
	rst = bubbleSort (arr, arr_size);
	printArr(arr, arr_size);
	
	rst = quickSort (arr, 0 , arr_size-1);
	printArr(arr, arr_size);
	
	rst = heapSort (arr, arr_size);
	cout << endl;
	printArr(arr, arr_size);

	rst = mergeSort (arr, arr_size);
	cout << endl;
	printArr(arr, arr_size);
	
	if (!rst)
	{
		cout << "ERROR" << endl;
		return RST_ERROR;
	}
	return RST_SUCCESS;
}
*/