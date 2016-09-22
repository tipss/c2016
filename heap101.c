#include <stdio.h>
#include <stdlib.h>
/* ADT : Heap(Priority Queue): Its a tree based data structure, common implementation is based on binary tree
*   max-heap: Highest key is at the root, key's of parent node is always >= to those of the child
* =======BST vs Heap======
    The abstract data structures (objects stored, their operations) in this question are different. 
    One implements a priority queue(heap), the other a set(BST). 
    A priority queue is not interested in finding an arbitrary element, only the one with largest priority.
    The concrete implementation of the structures. 
    Here on first sight both are (binary) trees,  with different structural properties though. 
    Both the relative ordering of the keys and the possible global structures differ. 

    (Somewhat imprecise, in a BST keys are ordered left-to-right(left being smallest, right being largest), 
    in a heap they are ordered top-down, but top either max or min, but 'down' does not mean min or max as in BST!) 
    As IPlant correctly remarks an heap should also be "complete"(no waste of memory, so array is suited).

    There is a final difference in the low level implementation. A (unbalanced) binary search-tree has a 
    standard implementation using pointers. 
    A binary heap to the contrary has an efficient implementation using an array (precisely because of the restricted structure).
*/


/*
 * A node's RChild is at the array location 2i+2
 *          LChild is at the array location 2i+1
 * A node's Parent is at (i-1)/2 location.
 * All leaves should be at the height H or H-1, meaning it must be a complete binary tree.
 *    e.g  17
 *       13  6
 *     1  4 2 5
 *    how its actually stored :[17,13,6,1,4,2,5]
 */
typedef enum { min_h, max_h} h_type;

typedef struct heap_s {
	int *array;
	int count;
	int max;
	h_type type; //min or max heap
} heap_t;

heap_t *CreateHeap(int max) {
	heap_t *h;
	if(max <= 0){
		return NULL;
	}
	h = (heap_t *)malloc(sizeof(heap_t));
	h->max = max;
	h->array = (int *)malloc(sizeof(int)* max);
	return h;
}

void PercolateDown(heap_t *h, int index){
//TBD
}

/*
 * Replace 0th element with last element,
 * Reduce array size
 * Percolate Down
 */
void Delete(heap_t *h){
//TBD
}

/* Insert : Insert at the end and precolate-up */
void Insert(heap_t *h, int val){
//TBD
}

void HeapSort(heap_t *h, int *a){
//TBD
}

int main(int argc, char *argv[]) {

	heap_t *h101 = CreateHeap(100);
}
