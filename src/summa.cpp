 
#include <stdio.h> 
#include<limits.h>

 
#define V 9 


int mindist(int distance[], 
				bool visited[]) 
{ 
	
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (visited[v] == false && 
				distance[v] <= min) 
			min = distance[v], min_index = v; 

	return min_index; 
} 

// Function to print shortest 
// path from source to j 
// using parent array 
void printPath(int indexing[], int j) 
{ 
	
	// Base Case : If j is source 
	if (indexing[j] == - 1) 
		return; 

	printPath(indexing, indexing[j]); 

	printf("%d ", j); 
} 

// A utility function to print 
// the constructed distance 
// array 
int printSolution(int distance[], int n, 
					int indexing[],int x) 
{ 

	
		for(int i=0;i<V;i++)
	{
	    if(x!=i)
	    printPath(indexing, i); 
	}
} 

// Funtion that implements Dijkstra's 
// single source shortest path 
// algorithm for a graph represented 
// using adjacency matrix representation 
void dijkstra(int graph[V][V], int src) 
{ 
	
	// The output array. dist[i] 
	// will hold the shortest 
	// distance from src to i 
	int distance[V]; 

	// sptSet[i] will true if vertex 
	// i is included / in shortest 
	// path tree or shortest distance 
	// from src to i is finalized 
	bool visited[V]; 

	// Parent array to store 
	// shortest path tree 
	int indexing[V]; 

	// Initialize all distances as 
	// INFINITE and stpSet[] as false 
	for (int i = 0; i < V; i++) 
	{ 
		indexing[0] = -1; 
		distance[i] = INT_MAX; 
		visited[i] = false; 
	} 

	// Distance of source vertex 
	// from itself is always 0 
	distance[src] = 0; 

	// Find shortest path 
	// for all vertices 
	for (int count = 0; count < V - 1; count++) 
	{ 
		// Pick the minimum distance 
		// vertex from the set of 
		// vertices not yet processed. 
		// u is always equal to src 
		// in first iteration. 
		int u = mindist(distance, visited); 

		// Mark the picked vertex 
		// as processed 
		visited[u] = true; 

		// Update dist value of the 
		// adjacent vertices of the 
		// picked vertex. 
		for (int v = 0; v < V; v++) 

			// Update dist[v] only if is 
			// not in sptSet, there is 
			// an edge from u to v, and 
			// total weight of path from 
			// src to v through u is smaller 
			// than current value of 
			// dist[v] 
			if (!visited[v] && graph[u][v] && 
				distance[u] + graph[u][v] < distance[v]) 
			{ 
				indexing[v] = u; 
				distance[v] = distance[u] + graph[u][v]; 
			} 
	} 

	// print the constructed 
	// distance array 
	printSolution(distance, V, indexing,src); 
} 

// Driver Code 
int main() 
{ 
	// Let us create the example 
	// graph discussed above 
	
	int n;
	
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
					{4, 0, 8, 0, 0, 0, 0, 11, 0}, 
						{0, 8, 0, 7, 0, 4, 0, 0, 2}, 
						{0, 0, 7, 0, 9, 14, 0, 0, 0}, 
						{0, 0, 0, 9, 0, 10, 0, 0, 0}, 
						{0, 0, 4, 0, 10, 0, 2, 0, 0}, 
						{0, 0, 0, 14, 0, 2, 0, 1, 6}, 
						{8, 11, 0, 0, 0, 0, 1, 0, 7}, 
						{0, 0, 2, 0, 0, 0, 6, 7, 0} 
					}; 
				

	dijkstra(graph, 0); 
	return 0; 
} 
