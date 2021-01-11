#include<iostream>
#include<string.h>



#define NODEDATA_SIZE 200
#define OK            1
#define ERROR         0

static int test = 123;

struct Node
{
	char data[NODEDATA_SIZE];
	Node *next;
};
 
struct ListNode
{
	Node *head;
	Node *tail;
	int size;
};


int nodeDataContructor(ListNode *list);
int printNodeData(ListNode *list);
int insertNode (ListNode *list, char *data);
int deleteNode (ListNode *list, char *findData);
int insertNode (ListNode *list, char *data, int pos);