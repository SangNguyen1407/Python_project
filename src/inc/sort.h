#include<iostream>
#include<string>

#define RST_ERROR			0
#define RST_SUCCESS			1

int printArr(int *arr, int arr_size);
int swap(int *a, int *b);


/*Sort code*/
int selectSort (int *arr, int arr_size);
int bubbleSort(int *arr, int arr_size);
int quickSort(int *arr, int low, int high);
int quickSort_temp(int *arr, int low, int high); /* no use recursion*/
int heapSort(int *arr, int arr_size);
int mergeSort(int *arr, int arr_size);