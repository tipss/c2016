package main
//package sorting101

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

/*
Everything in Go is passed by value, slices too. 
But a slice value is a header, describing a contiguous section of a backing array, and a slice value only contains a pointer to the array where the elements are actually stored. The slice value does not include its elements (unlike arrays).

So when you pass a slice to a function, a copy will be made from this header, including the pointer, which will point to the same backing array. Modifying the elements of the slice implies modifying the elements of the backing array, and so all slices which share the same backing array will "observe" the change.

*/

//Not i is never used as index
//Meaning, we walk iteratively inner loop exchanging elements
// When no work is needed , its complexity will be O(n),
// Meaning worst case case is O(n2), best case is O(n)
// Compare and swap moves one step at a time, swapped element can move again
func sortBubbleSort(a []int)  {
	var swapped int
	for i := 0; i < len(a); i++ {
		swapped = 0
		//Note j's max length, to avoid out of index error
		for j := 0; j < len(a)-1; j++ {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
				swapped = 1
			}
		}
		//This logic should be used for selection sort
		if swapped != 1 {
			break
		}
	}
}

//Note both i and j are used, note in one scan from inner loop
//We fix one element from outer loop at a time.
//Ascending , best,worst complexity is always O(n2)
//Compare and swap move one element at a time over entire list.
func sortSelectionSort(a []int)  {
	m := len(a)
	for i := 0; i < m; i++ {
		//Fix a[i], by sacanning rest of the list to place it to right position.
		//Which will be its final position.
		for j := i + 1; j < m; j++ {
			if a[i] > a[j] {
				a[i], a[j] = a[j], a[i]
			}
		}
	}
}

func main() {
	f := os.Stdin
	defer f.Close()
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		fmt.Println("Enter number seperated by space>>")
		str := strings.Split(scanner.Text(), " ")
		a := make([]int, 0)
		for _, s := range str {
			i, ok := strconv.Atoi(s)
			if ok == nil {
				a = append(a, i)
			}
		}
		sortBubbleSort(a)
		b := make([]int, len(a))
		copy(b, a)
		fmt.Println(a)
		sortSelectionSort(b)
		fmt.Println(b)
	}
}
