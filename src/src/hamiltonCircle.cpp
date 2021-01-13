#include <iostream>
#include <string.h>

using namespace std;

/* define parameter using in hamilton Cycle */
#define v 5              /* the number of node */
#define FIRST_NODE_POS 0 /* the first node in array of path*/
#define PRINT_ONE_PATH 0 /* print a path in Hamilton cycle. 
                            if setting 0, print all paths in Hamilton cycle */
#define SUCCESS        1
#define FAILED         0

/* public parameters */
bool isHamCycleExisted = false;


/*************************************************
 * Handle print the path in grap                 *
 * Input :    int path[]  : the path of graph    *
 *            int len   : the number of node int *
 *                        graph                  *
 * Output: void                                  *
 *************************************************/
void printPath(int path[], int len)
{
	cout << endl << "the Path:  ";
	
	for (int i = 0; i < len; i++)
	{
		cout << path[i] << " ";
	}
	
	cout << endl;
}

/*************************************************
 * Check the existed path between node-pos and   *
 * the node does not exist in the path           *
 * Input :    int node  : all node in the graph  *
 *            int G[][] : the graph 2D           *
 *            int path[]: the path of graph      *
 *            int pos   : the node having in the *
 *                        path                   *
 * Output: TRUE if node is not in path AND       *
 *              connect pos                      *
 *         FALSE if node is in the path OR       *
 *               not connect pos                 *
 *************************************************/
bool isSafe(int node, int G[v][v], int path[], int pos)
{
	/* if not connected "pos" */
	if (G[path[pos-1]-1][node-1] == 0)
	{
		return FAILED;
	}
	
	/* checking "node" in the path */
	/* if node is existed in the path -> return FALSE*/
	for (int i = 0; i < pos; i++)
	{
		if (path[i] == node)
		{
			return FAILED;
		}
	}
	
	return SUCCESS;
}


/*************************************************
 * The backstracing solution                     *
 * Input:     int G[][] : the graph 2D           *
 *            int len   : the number of node     *
 *            int path[]: the path of graph      *
 *            int pos   : the node having in the *
 *                        path                   *
 * Output: TRUE if having the cycle path         *
 *         FALSE if not have the cycle path      *
 *************************************************/
bool hamCycleUntil(int G[v][v], int len, int path[], int pos)
{
	/* checking last <pos> node in the graph */
	/* Existing vertex <pos> to the first node, 
	   print the path and return TRUE */
	if(pos == len)
	{
		if (G[path[pos-1]-1][path[FIRST_NODE_POS]-1] == 1)
		{
			path[v] = path[FIRST_NODE_POS];
			printPath(path, v+1); /* v+1 means adding the first node in the path */
			
			return SUCCESS;
		}
		else
		{
			return FAILED;
		}
	}
	
	/* check all node [node1, node2, node3, ..., len] 
	   if node is not existed in the path AND the path of vertex <pos> to its
	   -> recursion with this node.
	 */
	for (int i = 1; i < len+1; i++)
	{
		if (isSafe(i, G, path, pos))
		{ 
			path[pos] = i;  
			if (hamCycleUntil(G, len, path, pos+1) == true)
			{
				isHamCycleExisted = true; /* existed a HamCycle */
				if (PRINT_ONE_PATH)
				{
					return SUCCESS;
				}
			}
		}
	}

	/* Existed HamCycle or not */
	if (isHamCycleExisted)
	{
		return SUCCESS;
	}
	
	
	return FAILED;
}

/*************************************************
 * Handle Hamilton alogrithm                     *
 * Parameter: int G[][] : the graph 2D           *
 *            int len   : the number of node int *
 *                        graph                  *
 * Return   : TRUE if the graph come back the    *
 *                 first node                    *
 *            FALSE if not graph                 * 
 *************************************************/
int hamCycle(int G[v][v], int len)
{
	int *path = new int[len+1]; /* create a array of path with len*/
	int iStartNode = 5; /* setting started node*/
	
	
	/* constructor path array*/
	for (int i = 0; i < len; i++)
	{
		path[i] = -1;
	}
	
	/* choose the first node and get into path[0]*/
	path[FIRST_NODE_POS] = iStartNode;
	
	/* find the path in Graph
	 *   if not come back the first node -> return FALSE
	 *      come back the first node -> return TRUE
	 */
	 
	/* starting to check from node1 (node1 is default)
	   ex: 5 1 x x x
	 */
	if (hamCycleUntil(G, len, path, 1) == false)
	{
		cout << "Solution does not exist";
		return FAILED;
	}
	
	return SUCCESS;
}



int main ()
{
	/* input the graph data */
	int G[v][v] =      {{0, 1, 1, 0, 1},  
                        {1, 0, 1, 1, 1},  
                        {1, 1, 0, 1, 0},  
                        {0, 1, 1, 0, 1},  
                        {1, 1, 0, 1, 0}};  
				   
	
	/* calling the hamilton cycle */
	hamCycle(G, v);
	
	return SUCCESS;
}