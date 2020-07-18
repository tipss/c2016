#include <stdio.h>

/* 
 * How priority queue(min-heap) is used during Dikstra Calculation.
 * Heaps or Priority Queues are generally implemented using Array, as they fit best in array,
 * One use case is in SPF computation,
 * In SPF, we start with root(self).
 * Ideas is to add routes advertised by all the NBRs in the area and build 
 * with correct next-hop to FIB/RIB table.
 * We first process directly ADJcent NBRS . Each NBRs give details of their connected NBR's.
 * So shortes-path-first vertex(NBR)'s routes are processed at every iteration.
 * To acheive this, we need a priority-queue, where in it keeps its root as shortest-distance vertex.
 * Note that this heap keeps getting modified in two ways.
 * 1. pull(): where root node is pulled out of heap, as its directly advertised routes are processed.
 *    a[0] removed.   
 * 2. add():While processing a root node, its direct NBR's are added to this heap. 
 *    a[max] added.
 *    
 * 3. When heap is empty,  computation of SPF is complete.
 *    size == 0
 * In the above steps,  structural integrity of the priority-queue is disturbed.
 * Below methods explain them, but in summary there are two auxilary functions are needed.
 * heapyfyDown()<----done after pull()   
 * heapyfyUp()<------done after add()
 * e.g 
 */
#define parent(a) ((a-1)/2)
void heapifyUp( int a[], int cap) {
  int tmp = 0;
  /*
    If his parent value is higher than him, swap them and continue upward
   */
  int cur = cap;
  if (cur < 1)
    return;
    printf("start cur %d\n", cur);
  while(cur >= 0 && a[cur] < a[(cur - 1)/2]) {
    tmp    = a[cur];
    a[cur] = a[(cur-1)/2];
    a[(cur-1)/2] = tmp;
    cur    = (cur-1)/2;
    printf("new cur %d\n", cur);
  }
}

//TBD bit complex
void heapifyDown( int a[], int *cap) {

}

void add(int *pq, int *cap, int val) {
  /* Assume user takes care of pq size to new capacity */
  pq[*cap] = val;
  *cap     = *cap + 1;
  /* 
   * Fix the integrity of priority queue,
   * as last element added could be  lowest, and that should 
   * be moved to the  root
   */
  heapifyUp(pq, *cap-1);
}

int del(int *pq, int *cap) {
  /* Assume user takes care of pq size to new capacity */
  int val  = pq[0];
  pq[0] = pq[*cap];
  *cap = *cap - 1;
  /* 
   * Fix the integrity of priority queue, as last element added could be  lowest, and that should 
   * be moved to the  root
   */
  heapifyDown(pq, cap);
  return val;
}


/*
 *  Find the running median.
 * What is it?.
 * Assuming we receive number in any order,  median is index
 * of an element in that list after sorting ascending , 
 * which partitions list in two pieces left half and right half.
 * left side has numbers whose values are lower than right half.
 *
 * Solution : 
 * One simple way is to  walk list and compute median every time a new
 * element is added, in that case its order will be n^2.
 *
 * Optimal way is to maintain MinHeap and MaxHeap and keep balancing
 * heaps root based on new element coming into the list.
 * 
 */

int get_median(int *max_q, int *max_cap, int *min_q, int *min_cap, int new) {
  int median;

  /* Find where the new element will fit in  */
  if (*min_q == 0 || new < min_q[0]) {
    add(min_q, min_cap, new);
  } else {
    add(max_q, max_cap, new);
  }
  /* If heap size differs by at least two, then rebalance them */
  if((*min_cap - *max_cap) >= 2) {
    if(*min_cap > *max_cap) {
      add(min_q,min_cap, del(max_q, max_cap));
    } else {
      add(max_q,max_cap, del(min_q, min_cap));
    }
  }
  
  if (*max_cap > *min_cap) {
    return max_q[0];
  } else if(*max_cap < *min_cap){
    return min_q[0];
  }
    return (max_q[0] + min_q[0])/2;
}

int main(int argc, char *argv[]) {

  int pri_q[5] = {}; /* Priority queue */
  int min_q[5] = {}; /* Priority queue */
  int max_q[5] = {}; /* Priority queue */
  
  int dist[5]  = { 50, 10, 20, 40, 30 }; /* Input values to prirority queue */
  int cap      = 0; // Current size priority queue.
  int min_cap  = 0; // Current size priority queue.
  int max_cap  = 0; // Current size priority queue.
  
  for(int i = 0; i < sizeof(dist)/sizeof(int); i++) {
    add(pri_q, &cap, dist[i]);
    printf("\nAdd node %d, root[0] is %d, capacity %d ",
	   dist[i], pri_q[0], cap);
  }
  
  printf("\nPull nodes, note that values are in asending order now\n");
  cap--;
  while (cap >= 0) {
    printf("Pull root node with : value is %d, new capaciity is %d\n",
	   del (pri_q, &cap), cap);
  }
  int val = 0;
  for(int i = 0; i < sizeof (dist)/sizeof(int); i++) {
    val = get_median(min_q, &min_cap, max_q, &max_cap, dist[i]);
    printf("\nAdd node %d, min_q[0]=%d,cap=%d, "
	   "max_q[0]=%d, cap=%d median %d\n",
	   dist[i], min_q[0], min_cap, max_q[0], max_cap, val);
  }
}
