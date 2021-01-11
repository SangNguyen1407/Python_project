#include <iostream>
#include <string.h>

#define RST_ERROR			0
#define RST_SUCCESS			1

#define PRIORITY_LOW		10
#define PRIORITY_INTER		11
#define PRIORITY_HIGH		12
#define PRIORITY_NODEFINE	13


#define FORMULAR_LEN		100
#define STACK_OPERATOR_LEN	10

using namespace std;

struct StackNode
{
	char data;
	StackNode *next;
};

struct ListStackNode
{
	StackNode *head;
	StackNode *tail;
	int size;
};

int pushNode (ListStackNode *list, char opera)
{
	/*check input data*/
	if (list == NULL || opera == '\n')
	{
		return RST_ERROR;
	}
	/*create node*/
	StackNode *nodeData = (struct StackNode*) malloc(sizeof(struct StackNode));
	nodeData->data = opera;
	
	/*push node in the head of the stack*/
	if (!list->size)
	{
		list->head = nodeData;
		list->tail = nodeData;
	}
	else 
	{
		nodeData->next = list->head;
		list->head = nodeData;
	}

	list->size++;	
	return RST_SUCCESS;
}

int popNode(ListStackNode *list, char *opera)
{
	StackNode *node = (struct StackNode*) malloc(sizeof(struct StackNode));
	/*check list is not NULL or NODE in stack is not existed*/
	if (list == NULL || !list->size)
	{
		return RST_ERROR;
	}
	*opera = list->head->data;
	node = list->head;
	list->head = list->head->next;
	free(node);
	
	list->size--;
	return RST_SUCCESS;
}

int readFomularData (char *fileName, char *formularData)
{
	if (fileName == NULL)
	{
		return RST_ERROR;
	}
	
	strcpy(formularData, "(2/3+5)*9-4");
	
	if (formularData == NULL)
	{
		return RST_ERROR;
	}
	
	return RST_SUCCESS;
}
bool isDigit(int checkDigit)
{
	if (checkDigit >= '0' && checkDigit <= '9')
	{
		return 1;
	}
	
	return 0;
}

int priority_operator (char checkOperator)
{
	/*check input data*/
	if (checkOperator == '\n')
	{
		return RST_ERROR;
	}
	
	/*check the priority of the operator*/
	switch(checkOperator)
	{
		case '(':
		case ')':
			return PRIORITY_LOW;
		case '+':
		case '-':
			return PRIORITY_INTER;
		case '*':
		case '/':
			return PRIORITY_HIGH;
			
		default:
			return PRIORITY_NODEFINE;
	}
	
	return RST_SUCCESS;
}

int covertInfixToRPN()
{
	char *formularData = (char *) malloc (sizeof(char) * FORMULAR_LEN);
	char *convertFormularRPN;
	char opera;
	int formularSize = 0, pos_formularRPN = 0;
	ListStackNode *list;
	
	/* construct ListStackNode */
	list = (ListStackNode *) malloc(sizeof(ListStackNode));
	list->size = 0;
	
	/*get formular data from file*/
	if (!readFomularData("", formularData))
	{
		cout << "read Formular Data is failed!!!" << endl;
		return RST_ERROR;
	}
	
	/*create formularRPN array*/
	formularSize = strlen(formularData);
	convertFormularRPN = (char *) malloc (sizeof(char) * formularSize);
	cout << "Formular data: " << formularData << endl;
	
	/*read elements in formular*/
	for (int pos = 0; pos < formularSize; pos++)
	{
		if (isDigit(formularData[pos]))
		{
			convertFormularRPN[pos_formularRPN ++] = formularData[pos];
		}
		else 
		{
			if (!list->size) /*no operator in stack*/
			{
				pushNode(list, formularData[pos]);
			}
			else if (formularData[pos] == ')')
			{
				while (list->head->data != '(')
				{
					popNode(list, &opera);
					convertFormularRPN[pos_formularRPN ++] = opera;
				}
				
				if (list->head->data == '(')
				{
					popNode(list, &opera);
				}
				cout << "test1" << list->head->data << endl;
			}
			else if (priority_operator(list->head->data) >=
						priority_operator(formularData[pos]))
			{
				if (formularData[pos] != '(')
				{
					popNode(list, &opera);
					convertFormularRPN[pos_formularRPN ++] = opera;
				}
				pushNode(list, formularData[pos]);
			}
			else
			{
				pushNode(list, formularData[pos]);
			}
		}
	}
	if (list->size)
	{
		while (list->size)
		{
			popNode(list, &opera);
			convertFormularRPN[pos_formularRPN ++] = opera;
		}
	}
	
	cout << "Formular RPN: " << convertFormularRPN << endl;
	
	return RST_SUCCESS;
}

int main ()
{
	covertInfixToRPN();
	return RST_SUCCESS;
}