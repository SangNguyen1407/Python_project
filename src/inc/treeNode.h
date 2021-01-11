#include<iostream>
#include<string.h>

using namspace std;

#define RST_ERROR			0
#define RST_SUCCESS			1

struct Tnode
{
	int data;
	Tnode *rNode;
	Tnode *lNode;
	
	Tnode(int val)
	{
		data = 0;
		rNode = NULL;
		lNode = NULL;
	}
};

int nodeDataContructor(ListNode *list);
int printNodeData(ListNode *list);
int insertNode (ListNode *list, char *data);
int deleteNode (ListNode *list, char *findData);
int insertNode (ListNode *list, char *data, int pos);