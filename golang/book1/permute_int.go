package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

//Remember recursion
func is_palindrome(ns []int) bool {
	if len(ns) <= 1 {
		return true
	} else if ns[0] != ns[len(ns)-1] {
		return false
	}

	return is_palindrome(ns[1:len(ns)-1])

}

//Remember recursion
//is_palindrome is additional check, not necessary
func permute_numslice(ns []int, l int, r int) {
	if l == r {
		fmt.Println(ns)
		fmt.Println("is_palindrome : ", is_palindrome(ns))
	} else {
		for i := l; i <= r; i++ {
			ns[l], ns[i] = ns[i], ns[l]
			permute_numslice(ns, l+1, r)
			ns[l], ns[i] = ns[i], ns[l]
		}
	}
}

func main() {
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	for scanner.Scan() {
		fmt.Println(">", scanner.Text())
		str := strings.Split(scanner.Text(), " ")
		numslice := make([]int, 0)
		for _, s := range str {
			i, ok := strconv.Atoi(s)
			if ok == nil {
				numslice = append(numslice, i)
			}
		}
		fmt.Println("numslice:", numslice)
		permute_numslice(numslice, 0, len(numslice)-1)
		fmt.Println("numslice after permute:x", numslice)
	}
}

/*
thongal@thongal-000608:~/Documents/practice$::
go run ~/Documents/practice/permute_int.go

10 20
> 10 20
numslice: [10 20]
[10 20]
[20 10]

*/
