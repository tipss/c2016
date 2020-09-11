package main

import (
	"fmt"
)

func main() {
	anArray := [5]int{0, 1, -1, 2, -2}
	//Note 'range' return two values, index and value
	for index, value := range anArray {
		fmt.Println("index:", index, "value: ", value)
	}
}

/*
There is no 'while, or do while' in Go, but you can mimic the same
while loop example
for {
}
for <condition> {
}
 Note: All the three parts of for loop are optional  in Go
 Note: Why use range ?, : You do not need to to know cardinals or type of complext data types.
output:
index: 0 value:  0
index: 1 value:  1
index: 2 value:  -1
index: 3 value:  2
index: 4 value:  -2
*/
