package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
/* push at the end*/
func push(a []int, val int) []int {
	return append(a, val)
}

/* popo from the tail */
func pop(a []int) (int, []int) {
	l := len(a)-1
	return a[l], a[:l]
}

/* stack(pop) from the  head of slice */
func shift(a []int) (int, []int) {
	return a[0,] a[1:]
}

/* stack(push) add an element to the head */
func unshift(a []int, val int) ([]int) {
	return append([]int{val}, a...)
}

func Insert(a []int, val int, idx int) []int {
	fmt.Printf("Value to insert %d at index %d\n", val, idx)
	return append(a[:idx], append([]int{val}, a[idx:]...)...)
}

func main() {
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	for scanner.Scan() {
		fmt.Println("Enter slice values, followed by a " +
			"value and index to insert that value\n>")
		str := strings.Split(scanner.Text(), " ")
		numslice := make([]int, 0)
		for _,s := range str {
			num,_ := strconv.Atoi(s)
			numslice = append(numslice, num)
		}
		Insert(numslice, numslice[len(numslice)-3], numslice[len(numslice)-2])
		fmt.Println(numslice[:len(numslice)-2])

	}
}
