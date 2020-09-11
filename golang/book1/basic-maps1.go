/*
* Maps are builtin types equivalent to hash
* Basically a key:value slice(dynamic array)
* Key can be any basic datatype , as long as they are comparable
* e.g bool can also be used as key, but you have only two keys, so not much use.
 */

package main

import (
	"fmt"
)

//How to use const, and it also become global variable
//Note type is not used, GO figures out this on its own
//Value of this can't be changed
const PI = 3.1415926
//Note two different styles of string const
const s1 = "my string"
const s2 string = "my string"

func main() {
 //not global, but a const for within main
 cost k = 100
	/*
	* A Go type is a way of defining a new named type that uses the same
	* underlying type as an existing type.
	*/
	type Digit int
	type Power2 int 
//Create an empty map, not keyword map is used,   this word is missing for a slice!
// map[key-type]value-type
	m1 := make(map[string]int)
	m1["a1"] = 1
	m1["a2"] = 2
	for value, key := range m1 {
		fmt.Println(value, key)
	}
//Remember , how to delete a single element
//There is no add like this
	delete(m1, "a1")
// Check if thereis a key
	_, ok := m1["a1"]
	fmt.Println("ok[a1]=", ok)
	_, ok = m1["a2"]
	fmt.Println("ok[a2]=", ok)
	fmt.Println("const/global variable PI is ", PI)
/*
 Go supports pointers like C.
 & is used to get address of variable
 * is used to get the value of pointer type variable
 Function paramemter can be of type pointer

 Make function accept a pointer
 func getPointer(n *int) {
   }

 Make function return a pointer 
func returnPointer(n int) *int {
   }

 i := -10
assign value to pointer variable
create a pointer variable pI
pI := &i
*pI = 123456
change value of pointer
*pI--
 Strings in Go are value type , as oppposed to C, where they are pointer types
Why use pointers ?.
Pointers allow you to share data especially between Go function

*/
}
