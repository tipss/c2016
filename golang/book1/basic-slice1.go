
/*
Slice is a type of array , which can grow
re-slice: builds a reference to original slices
apppend an element to slices : orignal array element is not referenced
*/
package main

import (
	"fmt"
)

func printSlice(a []int) {
	fmt.Println(a, len(a), cap(a))
}
func main() {
  /* One way to init ,same like array except it has no size*/
	a1 := []int{2, 4, 8}
	//Note len,capacity, if you omit capacity it becomes same as len
	// Go intializes values to zero automatically
	// e.g zero len/cap slice
  // Second way to init
  // []int<---an slice of int
  // []string<---an slice of string
  //Another way to init a slice, not we never use make for to init a array
	a2 := make([]int, 0, 0)

	//Not ok a2 := make([]int)
	fmt.Println(a1)
  //Add one element at the tail of slice array, it will adjust len/cap as needed
 // There is no add
	a2 = append(a2, 100)
	fmt.Println(a2)

	a2 = append(a2, 101)
	a2 = append(a2, 102)
  //Remember  range returns two value,
  // Index, and value in the slice for that index
  // Similarly a map returns key, value when either assign, or in range
	for index, val := range a2 {
		fmt.Println(index, val)
	}
	a2 = nil
	fmt.Println("Emptied slice:")
	fmt.Println(a2)
	//New slice from old slice , or slice of a slice
	// 1 means element 1, note that starting element is always 0
	// 3 means uptto 2.
	// So it picks elements with index 1,2
	// re-slice only references original slice, never duplicates
	new_slice := a1[1:3]
	fmt.Println(new_slice)
	//Last element access
	fmt.Println((new_slice[len(new_slice)-1]))
	new_slice[0] = 10
	new_slice[1] = 11
	// Notice, original slice gets changed!!.
	fmt.Println(a1)
	fmt.Println(new_slice)

	fmt.Println(len(a1), cap(a1))
	//Notice, everytime we hit len==cap, and add an element to it, cap doubles automatically
	//Here is an exmple
	a1 = append(a1, 105)
	fmt.Println(a1)
	//cap is doubled, len is increased by only 1
	fmt.Println(len(a1), cap(a1))
	//Note slice is passed to a function by reference
	printSlice(a1)
	printSlice(new_slice)

	/*
	        * Go knows that most slices of bytes are used to store strings
		* and so makes it easy to switch between this type and the string type.
	*/
	b := make([]byte, 0)
	b = append(b, 'k')
	fmt.Println(b) //It will print number value of 'k'
	fmt.Println(string(b))
}

//Important, remember, how to remove an element from slice
//Maintains the order
//However, this is inefficient because you may end up with moving all of the elements, which is costy.
//Re-slicing method  take 224sec for 1mil number
func remove(my_slice []int, idx_to_remove int) []int {
    return append(my_slice[:idx_to_remove], my_slice[idx_to_remove+1:]...)
}
//If the order is not important, there is a efficient way,
// Fill the element that is getting removed with last element, and return smaller slice
// non-reslicing, take 0.06ns for 1mil
//Remember
func remove(my_slice []int, idx int) []int {
my_slice[idx] = my_slice[len(my_slice)-1]
return my_slice[:len(my_slice)-1]
}
