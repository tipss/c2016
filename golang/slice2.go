package main

import (
	"fmt"
	"sort"
	"strconv"
)

func main() {

	slice := make([]int, 0, 3)
	var text string
	for {
		fmt.Scan(&text)
		if string(text) == "X" {
			fmt.Println("Exiting...")
			break
		} else {
			number, _ := strconv.Atoi(text)
			slice = append(slice, number)
			sort.Ints(slice)
			fmt.Println(slice)
		}
	}
}
