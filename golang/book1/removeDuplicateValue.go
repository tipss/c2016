package main

import (
	"fmt"
)

func removeDuplicateValues(in []int) []int {
	/*
	a. create slice where new list with no duplicate is stored.
	b. create a map where you can identify duplicate
	c. while adding incoming slice to map, copy only items that are not duplicated
	   into new list, by adding check in map before add.
	*/
	m1 := make(map[int]int)
	a1 := make([]int, 0)

	//Note slice return idex, value
	for _, val := range in {
		if _, mval := m1[val]; !mval {
			a1 = append(a1, val)
		}
		m1[val] += 1
	}
	return a1
}

func main() {

	// Assigning values to the slice
	intSliceValues := []int{1, 2, 3, 4, 5, 2, 3, 5, 7, 9, 6, 7}

	// Printing orignial value of slice
	fmt.Println(intSliceValues)

	// Calling function where we
	// are removing the duplicates
	removeDuplicateValuesSlice := removeDuplicateValues(intSliceValues)

	// Printing the filtered slice
	// without duplicates
	fmt.Println(removeDuplicateValuesSlice)
}
