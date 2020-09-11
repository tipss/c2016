
/*
Given a string, find permutations, and identify if they are palindrome recursively
*/
package main

import (
	"bufio"
	"fmt"
	"os"
)
//Remember
func is_pal(txt string) bool {
	if len(txt) == 1 {
		return true
	}
	if txt[0] != txt[len(txt)-1] {
		return false
	}
	return is_pal(txt[1 : len(txt)-1])
}

/*
ab : ab ba P(n,r) = n!/ (n-r)!  p= position matters.   always higher in number
ab : ab    C(n,r) = n!/ (r! * (n-r)!)    position does not matter , always lower in number
*/
//Remember
func permute(a []byte, l int, r int) {
	if l == r {
		fmt.Println(string(a), is_pal(string(a)))
	} else {
		for i := l; i <= r; i++ {
			a[l], a[i] = a[i], a[l]
			permute(a, l+1, r)
			a[l], a[i] = a[i], a[l]
		}
	}
}

func main() {
	f := os.Stdin
	defer f.Close()
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		fmt.Println(">", scanner.Text())
		str := make([]byte, 0)
		str = append(str, scanner.Text()...)
		permute(str, 0, len(str)-1)
	}
}

func permutations(arr []int) [][]int {
	var helper func([]int, int)
	res := [][]int{}

	helper = func(arr []int, n int) {
		if n == 1 {
			tmp := make([]int, len(arr))
			copy(tmp, arr)
			res = append(res, tmp)
		} else {
			for i := 0; i < n; i++ {
				helper(arr, n-1)
				if n%2 == 1 {
					tmp := arr[i]
					arr[i] = arr[n-1]
					arr[n-1] = tmp
				} else {
					tmp := arr[0]
					arr[0] = arr[n-1]
					arr[n-1] = tmp
				}
			}
		}
	}
	helper(arr, len(arr))
	return res
}

/*
arr := []int{1, 2, 3}
fmt.Println(permutations(arr))
[[1 2 3] [2 1 3] [3 2 1] [2 3 1] [3 1 2] [1 3 2]]
*/
