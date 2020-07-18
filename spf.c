#include <stdio.h>
#include <stdlib.h>

#define V 9
#define INT_MAX 0xffffff


void printSolution(int dist[], int n)
{
  printf("Vertex   Distance from Source\n");
  for (int i = 0; i < V; i++)
    printf("%d \t\t %d\n", i, dist[i]);
}

/*
 return -1 : No more node left
 MIN-HEAP  : Find a vertex, which is at a minimum distance from soure 
*/
int min_vertex_index(int sptSet[], int dist[]) {
  int min   = INT_MAX;
  int index = -1;
  for (int i = 0; i< V; i++) {
    if (sptSet[i] == 0 && dist[i] < min) {
      min   = dist[i];
      index = i;
    }
  }
  printf("Return Vertex %d with min-distance %d\n", index, min);
  return (index);
}

/*
 * 1. PATH : sptSet[] : Hold vertices that are already part of Shortest Path Tree
 * 2. TENT : distance[]: Minimum distance from a single source Vertix to this node found
 * 3. Initialize distance[] to INFINITI for all vertices, except for the source vertice(Val Zero)
 * 4. Find index of vertex, whose distance is minimum from the 'distance[] using min_key API,
 * 5. Add this vertex to sptSet[] by setting it to 1/TRUE.
 * 6. Find all its adjacent vertices using supplied Graph[current-vertex][i]
 * 7. Update the distance of those adjacent vertices into distance[],if vertex is not in sptSet[].
 * 8. Continue, until there are no more index with min-distance
*/

/* Given adjacency graph in two dimensional array, find shortest path tree from given source */
/* 
 * Add parent list , next hops can be tracked TBD 
 * Note: It is similar to greedy BFS(Breadth First Search), where a Queue is used
 * In Other words:
 * It mainly uses priority-queue(min-heap), where in a list is used as underlying struct
 * to store different vertices ordered by distance, root node representing min-distance at all time.
 *  
 * This is used in Link State protocols like IS-IS and OSPF to compute shortest distrance
 * from root(self) to all other vertices(nodes) in the network.
 */
void dijkstra(int G[V][V], int source_index) {
  int dist[V]   = {0};
  int sptSet[V] = {0};
  int u=0; //Rows
  int v=0; //Columns
  for(int i=0;i<V;i++){
    dist[i]= INT_MAX;
  }

  dist[source_index] = 0;

  for(int count = 0; count < V; count++) {
    //Get a index for vertex with min-distance from source
    //which is not already in the PATH list(sptSet).
    u = min_vertex_index(sptSet, dist);
    if (u == -1) {
      printf("Exit Dijkstra(no more vertices to add\n");
    }

    sptSet[u]= 1;
    //Find all the adjacent nodes for this vertex in u, using supplied graph G
    for(int v = 0; v < V; v++) {
      if((sptSet[v] == 1 || G[u][v] == 0 || dist[u] == INT_MAX) {
	  continue;
      }
      if(dist[v] > (dist[u]+ G[u][v])) {
	dist[v] = dist[u] + G[u][v];
      }
    }//End of for loop

  }//End of for loop

  printSolution(dist,V);
}


// driver program to test above function
int main(int argc, char *argv[])
{
  /* Let us create the example graph discussed above */
  int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
		     {4, 0, 8, 0, 0, 0, 0, 11, 0},
		     {0, 8, 0, 7, 0, 4, 0, 0, 2},
		     {0, 0, 7, 0, 9, 14, 0, 0, 0},
		     {0, 0, 0, 9, 0, 10, 0, 0, 0},
		     {0, 0, 4, 14, 10, 0, 2, 0, 0},
		     {0, 0, 0, 0, 0, 2, 0, 1, 6},
		     {8, 11, 0, 0, 0, 0, 1, 0, 7},
		     {0, 0, 2, 0, 0, 0, 6, 7, 0}
  };
  
  dijkstra(graph, 0);
  
  return 0;
}
