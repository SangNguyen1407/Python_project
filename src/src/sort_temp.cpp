#include<iostream>
#include<string.h>
#include "../inc/linkedList.h"
 
using namespace std;


int main ()
{
	cout << "test" << endl;
	ListNode *list = NULL;
	list = new ListNode;
	nodeDataContructor(list);

	insertNode(list, "test1");
	insertNode(list, "test2");
	insertNode(list, "test3");
	insertNode(list, "test4");
	insertNode(list, "test5");
	insertNode(list, "test6");
	insertNode(list, "test7");
	insertNode(list, "test8");

	cout << "Given Linked List: ";
	printNodeData(list);
	deleteNode(list, "test1");
	deleteNode(list, "test7");
	deleteNode(list, "test8");
	cout << endl;
	
	cout << "Modified Linked List: ";
	printNodeData(list);
	cout << endl;

	insertNode(list, "test10");
	insertNode(list, "test11");
	insertNode(list, "test12");
	insertNode(list, "test2");
	cout << "Modified Linked List: ";
	printNodeData(list);
	cout << endl;	
	
	insertNode(list, "TEST2", 3);
	cout << "Modified Linked List: ";
	printNodeData(list);
	cout << endl;	
	
	return OK;
}


