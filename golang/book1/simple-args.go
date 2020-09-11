package main

import (
	"fmt"
	"os"
	"strconv"
)

/*
* Get an idea how to use blank identifier, args, strconv, for loop
*/
func main() {
	if len(os.Args) <= 1 {
		fmt.Println("Please give one or more float, Will find, min and max")
		os.Exit(1)
	}
	/* underscore used below is called blank identifier, is the Go way of
		discarding a value, you can use it multiple times, if function returns
	        multiple values
	*/
	arg := os.Args
	min, _ := strconv.ParseFloat(arg[1], 64)
	max, _ := strconv.ParseFloat(arg[1], 64)
	for i := 2; i < len(arg); i++ {
		n, _ := strconv.ParseFloat(arg[i], 64)
		if n > max {
			max = n
		}
		if n < min {
			min = n
		}
	}
	fmt.Printf("Min %f Max %f\n", min, max)
}
