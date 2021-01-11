#include<iostream>

using namespace std;

#define NODEDATA_SIZE 200
#define ERROR         0
#define SUCCESS       1


struct node
{
	char data[NODEDATA_SIZE];
	node *next;
};

void printArray(int arr[], int arr_size)
{
	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << "_";
	}
	
	cout << endl;
}

int merge(int arr[], int left, int mid, int right)
{
	/* check input value */
	if (mid < left || mid > right)
	{
		return 0;
	}
	/* create array */
/*	int arr_left_size = mid - left + 1;
	int arr_right_size = right - mid;
	int arrLeft[arr_left_size];
	int arrRight[arr_right_size];	
	
	for (int i = 0 ; i < arr_left_size; i++)
	{
		arrLeft[i] = arr[left + i];
		cout << arrLeft[i] << " ";
	}
	
	for (int j = 0 ; j < arr_right_size; j++)
	{
		arrRight[j] = arr[mid + 1 + j];
		cout << arrRight[j] << " ";
	}
	
	int i_left = 0;
	int i_right = 0;
	int i_arr = left;
	
	while(i_left < arr_left_size && i_right < arr_right_size)
	{
		if (arrLeft[i_left] <= arrRight[i_right])
		{
			arr[i_arr] = arrLeft[i_left];
			i_left++;
		}
		else
		{
			arr[i_arr] = arrRight[i_right];
			i_right++;
		}
		i_arr++;
	}
	
	
	while(i_left < left)
	{
		arr[i_arr] = arrLeft[i_left];
		i_arr++;
		i_left++;
	}
	cout << endl;
	while(i_right < right)
	{
		arr[i_arr] = arrRight[i_right];
		i_arr++;
		i_right++;
	}
	*/
	for(int i = left; i < right; i ++)
	{
		cout << arr[i] << " ";
	}
	cout << endl<< "test" << left << right << mid << endl;
	return 1;
}

void mergeSort(int arr[], int left, int right)
{
	int mid = 0;
	if (left < right)
	{
		mid = left + (right - left)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main()
{
	int arr[] = {12, 11, 1, 5, 6, 7, 10};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	
	cout << "Given array is \n";
	printArray(arr, arr_size);
	
	mergeSort(arr, 0, arr_size - 1);
	
	cout << "Sort array is \n";
	printArray(arr, arr_size);
}