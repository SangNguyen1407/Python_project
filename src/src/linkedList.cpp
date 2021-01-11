#include<iostream>
#include<string.h>
#include "../inc/linkedList.h"
 
using namespace std;
extern int test;
int nodeDataContructor(ListNode *list)
{
	if(list == NULL)
	{
		return ERROR;
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;	
	
	return OK;
}

int printNodeData(ListNode *list)
{
	if (list == NULL)
	{
		return ERROR;
	}
	Node *nodeData = new Node;
	if (list->head == NULL)
	{
		cout << "No data in list" << endl;
		return OK;
	}
	
	nodeData = list->head;
	
	for (int i = 0; i < list->size; i++)
	{
		if (nodeData->data == NULL)
		{
			break;
		}
		cout << nodeData->data << " ";
		nodeData = nodeData->next;
	}
	
	return OK;
}

int insertNode (ListNode *list, char *data)
{
	if (data == NULL)
	{
		return ERROR;
	}
	Node *nodeData = (struct Node*) malloc(sizeof(struct Node));
	strcpy(nodeData->data, data);
	nodeData->next = NULL;
	
	if (list != NULL &&list->head == NULL)
	{
		list->head = nodeData;
		list->tail = nodeData;
		list->size++;
	}
	else
	{
		list->tail->next = nodeData;
		list->tail = list->tail->next;
		list->size++;
	}
	
	return OK;
}

int insertNode (ListNode *list, char *data, int pos)
{
	if (list == NULL || list->size < pos || pos < 0)
	{
		return ERROR;
	}
	Node *nodeData = (struct Node*) malloc(sizeof(struct Node));
	Node *tempNodeData = (struct Node*) malloc(sizeof(struct Node));
	int nodePos = 0;
	
	strcpy(nodeData->data, data);
	nodeData->next = NULL;
	
	tempNodeData = list->head;
	while(nodePos < pos - 1)
	{
		tempNodeData = tempNodeData->next;
		nodePos++;
	}
	
	nodeData->next = tempNodeData->next;
	tempNodeData->next = nodeData;
	list->size++;
	
	return OK;
}

int deleteNode (ListNode *list, char *findData)
{
	if (findData == NULL)
	{
		return ERROR;
	}
	Node *nodeData = (struct Node*) malloc(sizeof(struct Node));
	nodeData->next = NULL;
	int i = 0;
	int cmpRt = 0;
	int list_size = list->size;
	if (list != NULL && list->head == NULL)
	{
		return OK;
	}
	
	/*Node Head*/
	nodeData = list->head;
	cmpRt = strcmp(nodeData->data, findData);
	if (nodeData->next == NULL && cmpRt == 0)
	{
		list->head = NULL;
		list->tail = NULL;
		list->size --;		
	}
	else if (nodeData->next != NULL && cmpRt == 0)
	{
		list->head = nodeData->next;
		free(nodeData);
		list->size --;
	}
	else
	{
		while(i < list->size-1)
		{
			if (nodeData->next == NULL)
			{
				break;
			}
			cmpRt = strcmp(nodeData->next->data, findData);
			if (cmpRt == 0)
			{
				Node *tempData = (struct Node*) malloc(sizeof(struct Node));
				tempData = nodeData->next;
				nodeData->next = tempData->next;
				if (i == list->size-2)
				{
					list->tail = nodeData;
				}
				free(tempData);
				list->size --;
				break;
			}
			nodeData = nodeData->next;
			i++;
		}
	}
	
	return OK;

}
