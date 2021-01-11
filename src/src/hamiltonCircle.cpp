#include <iostream>
#include <string.h>


using namespace std;
#define v 5
int flag = 0;
int firstNode = 0;

void printPath(int path[], int len)
{
	cout << endl << "the Path:  ";
	for (int i = 0; i < len; i++)
	{
		cout << path[i] << " ";
	}
	cout << endl;
}

bool isSafe(int node, int G[v][v], int path[], int pos)
{
	if (G[path[pos-1]-1][node-1] == 0)
	{
		return false;
	}
	for (int i = 0; i < pos; i++)
	{
		if (path[i] == node)
		{
			return false;
		}
	}
	
	return true;
}

bool hamCycleUntil(int G[v][v], int len, int path[], int pos)
{
	if(pos == len)
	{
		if (G[path[pos-1]-1][path[0]-1] == 1)
		{
			path[v] = path[0];
			printPath(path, v+1);
			
			return true;
		}
		else
		{
			return false;
		}
	}
	
	for (int i = 1; i < len+1; i++)
	{

		if (isSafe(i, G, path, pos))
		{ 
			path[pos] = i;  
			if (hamCycleUntil(G, len, path, pos+1) == true)
			{
				flag++;
			}
		}
	}
	if (flag)
	{
		return true;
	}
	
	return false;
}

int hamCycle(int G[v][v], int len)
{
	int *path = new int[len+1];
	int theFirstNode = 1;
	for (int i = 0; i < len; i++)
	{
		path[i] = -1;
	}
	
	path[0] = theFirstNode;
	if (hamCycleUntil(G, len, path, 1) == false)
	{
		cout << "Solution does not exist";
		return false;
	}
	
	return true;
}

int main ()
{
//	int len = 5;
	int G[v][v] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};  
				   
	
	hamCycle(G, v);
	return 1;
}