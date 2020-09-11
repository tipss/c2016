package main

import (
	"fmt"
)

// Write a function that merges an arbitrary number of maps and
// returns the merged map. Write and run one unit test for your function.
// // Keep the last value if you find duplicate value.

//This specific for [string]int type, golang do not have generic for this
func addmap(a map[string]int, b map[string]int) {
    for k,v := range b {
        a[k] = v
    }
}
func merge_maps(mp_in ...map[string]int) map[string]int {
	tmp := make(map[string]int, 0)
	for idx, val := range mp_in {
		fmt.Printf("key %T value %T\n", idx, val)
		fmt.Println(idx, val)
		addmap(tmp,val)
	}
	return tmp
}

/*
variadic function : used as pack type.
note in is of slice, we pack and send into function
*/
func merge_slices(in ...[]int) []int {
	tmp := make([]int, 0)
	for _, val := range in {
		// variadic used as unpack
		// (note val is slice, we unpack and use in append)
		tmp = append(tmp, val...)
	}
	return tmp
}

func main() {
	a1 := []int{1, 2, 3}
	a2 := []int{4, 5, 6}
	m1 := make(map[string]int)
	m2 := make(map[string]int)
	m1["g1"] = 1
	m1["g2"] = 2
	m1["g3"] = 3

	m2["p1"] = 1
	m2["p2"] = 2
	m2["p3"] = 3

	fmt.Println(a1[:], a2[:], "\nMerged slices:", merge_slices(a1, a2))
	fmt.Println(m1, m2, "Merged maps", merge_maps(m1, m2))
}
