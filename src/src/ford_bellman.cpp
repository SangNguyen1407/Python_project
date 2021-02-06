#include <iostream>
#include "string.h"
#include "../inc/fileHandler.h"

#define MAX_NUMBER     1000
#define MAX_CHAR_LINE  100

#define SUCCESS        1
#define FAILED         0

using namespace std;


/*************************************************
 * Constuctor graph with n nodes                 *
 * init value is MAX_NUMBER                      *
 * Input :    int *graph  : the graph with n*n   *
 *            int numberofNode: the number of    *
 *                              node             *
 * Output: int                                   *
 *************************************************/
int initGraph(int *graph, int numberOfNode)
{
	if (graph == NULL && numberOfNode < 1)
	{
		return FAILED;
	}
	
	// init value into Graph
	for (int node = 0; node < numberOfNode; node++)
	{
		for (int vector = 0; vector < numberOfNode; vector++)
		{
			// graph[n][n] = 0 && graph[n][m] = MAX_NUMBER
			if (node == vector)
			{
				*(graph + (node*numberOfNode + vector) ) = 0;
			}
			else
			{
				*(graph + (node*numberOfNode + vector) ) = MAX_NUMBER;
			}
		}
	}
	
	return SUCCESS;
}

/*************************************************
 * Load graph from MINPATH.INP file              *
 * Input :    int *graph  : the graph with n*n   *
 *            int numberofNode: the number of    *
 *                              node             *
 * Output: int                                   *
 *************************************************/
int loadGraph(int *graph, int numberOfNode)
{
	if (graph == NULL)
	{
		return FAILED;
	}
	
	char *data = (char *) malloc(sizeof(char) * MAX_CHAR_LINE);
	char *data_temp; // data temp for getting a line in data file
	char *data_info; // the first line of data file 
	int node = 0, vector = 0, weigh = 0;
	
	/* Read file */
	data = readTextFile("./src/MINPATH.INP", "r");
	
	/* Get the first line in MINPATH.INP */
	data_info = strtok(data, "\r\n");
	
	/* Get line in datat file */
	data_temp = strtok(NULL, " ");
	while(data_temp != NULL)
	{
		node      = atoi(data_temp);
		data_temp = strtok(NULL, " ");
		vector    = atoi(data_temp);
		data_temp = strtok(NULL, "\r\n");
		weigh     = atoi(data_temp);
		*(graph + ((node-1)*numberOfNode+ (vector-1))) = weigh;
		
		// get next line
		data_temp = strtok(NULL, " ");
	}
	
	return SUCCESS;
}

/*************************************************
 * Print trace from the first node to the last   *
 * node                                          *
 * Input :    int *trace  : the graph with n node*
 *            int numberofNode: the number of    *
 *                              node             *
 *            int firstNode                      *
 *            int lastNode                       *
 * Output: int                                   *
 *************************************************/
int printTrace(int *trace, int numberOfNode, int firstNode, int lastNode)
{
	if ( (trace == NULL && numberOfNode < 1) && 
	     (firstNode < 1 || firstNode > numberOfNode-1) && 
	     (lastNode < 1 || lastNode > numberOfNode-1))
	{
		return 0;
	}

	int isFirstNode = 0; // first node OR NOT
	// trace from first node to last node
	int *data = (int *) malloc(sizeof(int) * numberOfNode); 
	// init data
	for (int i = 0; i < numberOfNode; i++)
	{
		data[i] = 0;
	}	
	
	// first node
	data[0] = lastNode;
	// others node
	for (int i=0; i < numberOfNode-1; i++)
	{
		for (int j=0; j < numberOfNode; j++)
		{
			if (j == data[i]-1)
			{
				data[i+1] = trace[j];
				if (data[i+1] == firstNode-1)
				{
					isFirstNode = 1;
				}
				break;
			}

			if (j == numberOfNode-1 && data[i+1] != firstNode-1)
			{
				isFirstNode = -1;
				break;
			}
		}
		if (isFirstNode)
		{
			break;
		}
	}

	if (isFirstNode == -1)
	{
		cout << endl << "not vertge to " << endl;
		return 0;
	}

	// print trace
	for(int i = numberOfNode-1; i>=0 ; i--)
	{
		if (data[i] == 0)
		{
			continue;
		}
		
		cout << data[i];
	
		if (i != 0)
		{
			cout << " -> ";
		}
	}
	
	return 1;
}

/*************************************************
 * FORD BELLMAN                                  *
 * Input :                                       *
 * Output: int                                   *
 *************************************************/
int ford_bellman ()
{
	int *graph; // graph with n*n
	char *data; // data in file
	int *trace; // trace mininum path
	int *cost; // mininum cost from first node to last node
	int firstNode; // default 1
	int lastNode;
	bool stop;
	char *data_temp, *data_info;
	int numberOfPath = 0, numberOfNode = 0; 
	
	cout << "--------FORD BELLMAN------" << endl;
	
	/* Get the first line in MINPATH.INP */
	data = (char *) malloc(sizeof(char) * 100);
	data = readTextFile("./src/MINPATH.INP", "r");
	data_info = strtok(data, "\r\n");
	numberOfNode  = atoi(strtok(data_info, " "));
	numberOfPath  = atoi(strtok(NULL, " "));
	firstNode     = atoi(strtok(NULL, " "));
	lastNode      = atoi(strtok(NULL, " "));
	
	/* Get graph data */
	graph = (int *)malloc(sizeof(int) * numberOfNode * numberOfNode);
	cost  = (int *)malloc(sizeof(int) * numberOfNode);
	trace = (int *)malloc(sizeof(int) * numberOfNode);
	initGraph(graph, numberOfNode);
	loadGraph(graph, numberOfNode);
	
	/* Create trace and cost array */
	for (int i=0; i<numberOfNode ; i++)
	{
		trace[i] = 0;
		cost[i] = MAX_NUMBER;
	}
	
	cost[firstNode - 1]  = 0;
	trace[firstNode - 1] = 0;
	
	for (int i=0; i < numberOfNode; i++)
	{
		stop = true;
		for (int u=0; u<numberOfNode; u++)
		{
			for (int v=0; v<numberOfNode; v++)
			{
				if (u != v && cost[v] > cost[u] + *(graph + u*numberOfNode+v))
				{
					cost[v]  = cost[u] + *(graph + u*numberOfNode+v);
					trace[v] = u+1;
					stop = false;
				}
			}
		}
		if (stop)
		{
			break;
		}
	}
	
	cout << "cost of G: " << endl;
	for (int i=0; i<numberOfNode ; i++)
	{
		cout << cost[i] << " ";
	}
	
	cout << endl << "Trace of line:" << endl;
	for (int i=0; i<numberOfNode ; i++)
	{
		cout << trace[i] << " ";
	}
	
	cout << endl << "Print trace for user:" << endl;
	printTrace(trace, numberOfNode, firstNode, lastNode);

	return 0;
}