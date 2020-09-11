package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"strconv"
)

//Note , when you pass slice as argument, its better to return this as function argument
// so modifications are reflected.  There no pointer here, but Go remembers
// anything that it returns in function, it keeps it alive until its use is no longer needed.
// No malloc or new is needed here, as golang does not free locally allocated var, even after function
// returns, as long as we have a return value.

func movezerotobeginning(a [] int) []int {
	idx2 := len(a)-1
	for i:= len(a) - 1; i >= 0; i-- {
		if a[i] != 0 {
			a[idx2] = a[i]
			idx2--
		}
	}
	for i := 0; i <= idx2; i++ {
		a[i] = 0;
	}
	return a
}

func movezerotoend(a []int) []int {
	idx2 := 0;
	for idx, val := range a {
		fmt.Println(idx, val)
		if(val != 0) {
			a[idx2] = val
			idx2++
		}
	}
	
	for i := idx2; i < len(a); i++ {
		a[i] = 0
	}
	return a
}

func main() {
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	for scanner.Scan() {
		str := strings.Split(scanner.Text(), " ")
		numslice := make([]int, 0)
		for _, s := range str {
			i, ok := strconv.Atoi(s)
			if (ok == nil) {
				numslice =  append(numslice, i)
			}
		}
		fmt.Println("Move to end      : ", movezerotoend(numslice))
		fmt.Println("Move to beginning:", movezerotobeginning(numslice))
	}
}
