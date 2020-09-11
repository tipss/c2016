package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"strconv"
)

/*

Native maps of go are hash, But keys expand for each unique key .
But if we have key generating function for the map, we can group a collection of objects to one unique key.
Thus we can reduce length of maps. Lookups will be baster.

Look up speed in native maps is order n, based on n keys-value pair.
Say we have hash function which generate a unique key  based on certain algorithm,
we can store n items in k buckets like below

1-> [] []..
2.->[] [] ..
...
...
k-> [] []

e.g   key = hashfunc(value)

e.g implmenntation could be,    (value % 10 )

So look up speed for n elements will become n/k, which is faster than O(n).
*/

type Node struct {
	Value int
	Next  *Node
}

/* Linked list of nodes are stored in maps*/
//Remember
type HashTable struct {
	Table map[int]*Node
	Size  int
}

func hashFunction(val int, size int) int {
	return (val % size)
}

/*
* Insert new element to hash, as head of identified bucket
* Otherwise you have to walk to the end of bucket .
 */
func insert(h *HashTable, value int) int {

	index := hashFunction(value, h.Size)
	element := Node{Value: value, Next: h.Table[index]}
	h.Table[index] = &element
	return index
}
//TBD need bit more work, but code looks good for study
func traverse(h *HashTable) {
	for k := range h.Table {
		if(h.Table[k] != nil) {
		t := h.Table[k]
		for t != nil {
			fmt.Print(k, t.Value)
		}
			fmt.Println()
		}
	}
}

func main() {
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	for scanner.Scan() {
		fmt.Println("Enter an array of number to store in hash separated by space:")
		str := strings.Split(scanner.Text(), " ")
		a := make([]int, 0)
		table := make(map[int]*Node, 10)
		hash := &HashTable{Table: table, Size: 10}
		for _, s := range str {
			val, _ := strconv.Atoi(s)
			a = append(a, val)
			insert(hash, val)
		}
		traverse(hash)
	}
}
