#include<iostream>
#include<string.h>

using namespace std;


#define RST_ERROR			0
#define RST_SUCCESS			1

struct Tnode
{
	int data;
	Tnode *rNode;
	Tnode *lNode;
	int size;
	
	Tnode(int val)
	{
		data = val;
		size = 1;
		rNode = NULL;
		lNode = NULL;
	}
	
	Tnode()
	{
		data = 0;
		size = 0;
		rNode = NULL;
		lNode = NULL;
	}
};
void printTnode(Tnode *tNode)
{
	if (tNode == NULL)
	{
		cout << "test" << endl;
		return;
	}
	
	if (tNode->lNode != NULL)
	{
		printTnode(tNode->lNode);
	}
	
	if (tNode->rNode != NULL)
	{
		printTnode(tNode->rNode);
	}
	
	cout << tNode->data << " ";
	
}

Tnode *insertTnode(Tnode *tNode, int val)
{
	if (tNode->size == 0 || tNode == NULL)
	{
		tNode = new Tnode(val);
		return tNode;
	}
	Tnode *newNode = new Tnode(val);
	Tnode *node_temp = new Tnode();
	node_temp = tNode;
	
	/*node is a tree
	 * node is not leaf
     * node data < val -> move left node
	 *                 -> others : right node  
	 */
	while(node_temp != NULL)
	{ 
		if (node_temp->data > newNode->data)
		{
			if (node_temp->lNode == NULL)
			{
				node_temp->lNode = newNode; 
				break;
			}
			node_temp = node_temp->lNode;
		}
		else
		{
			if (node_temp->rNode == NULL)
			{
				node_temp->rNode = newNode;
				break;
			}
			node_temp = node_temp->rNode;
		}		
	}
	tNode->size++;
	
	return tNode;
}

/*
 * tNodeにval値を検索する
 * 関数：tNodeはすべてデータを存在する
 *     valは検索する値
 */
int searchNode(Tnode *tNode, int val)
{
	if (tNode == NULL)
	{
		return RST_ERROR;
	}
	Tnode *tNode_temp = new Tnode;
	tNode_temp = tNode;
	int flag = 0; // data is not existed in tree
	
	while (tNode_temp != NULL)
	{
		if (tNode_temp->data > val)
		{
			tNode_temp = tNode_temp->lNode;
		}
		else if (tNode_temp->data < val)
		{
			tNode_temp = tNode_temp->rNode;
		}
		else if (tNode_temp->data == val)
		{
			flag = 1; 
			break;
		}
	}
	
	return flag;
}

int deleteNode(Tnode *tNode, int val)
{
	if (tNode == NULL)
	{
		return RST_ERROR;
	}

	Tnode *tNode_temp = new Tnode;
	Tnode *tNode_temp_before = new Tnode;
	tNode_temp = tNode;
	
	while (tNode_temp != NULL)
	{
		if (tNode_temp->data > val)
		{
			tNode_temp_before = tNode_temp;
			tNode_temp = tNode_temp->lNode;
		}
		else if (tNode_temp->data < val)
		{
			tNode_temp_before = tNode_temp;
			tNode_temp = tNode_temp->rNode;
		}
		else if (tNode_temp->data == val)
		{
			if (tNode_temp->lNode == NULL && tNode_temp->rNode == NULL)
			{
				cout << "test" << endl;
				delete[]tNode_temp;
			}
			else if (tNode_temp->rNode != NULL)
			{
				tNode_temp_before->rNode = tNode_temp->rNode;
			}
			else
			{
				tNode_temp_before->lNode = tNode_temp->lNode;
			}
			tNode->size--;	
			break;
		}
	}	
	
	return RST_SUCCESS;
}

int main ()
{
	int arr[] = {5, 1, 6, 2, 3, 7, -1, 100, 123, 9, 45, -4};
	int arr_size = sizeof(arr) / sizeof(arr[0]);
	Tnode *tNode = new Tnode();
	int valSearch = 10;
	int rst = 0;
	for (int i = 0; i < arr_size; i++)
	{
		tNode = insertTnode(tNode, arr[i]);
	}
	
	cout << "print tree node" << endl;
	printTnode(tNode);
	
	cout << endl;
	rst = searchNode(tNode, valSearch);
	if (rst == 1)
	{
		cout << "searching data "  << valSearch << " is existed in tree."<< endl;
	}
	else
	{
		cout << "searching data "  << valSearch << " is NOT existed in tree." << endl; 
	}
	
	cout << endl;
	rst = deleteNode(tNode, -4);
	printTnode(tNode);
	
	
	return RST_SUCCESS;
}