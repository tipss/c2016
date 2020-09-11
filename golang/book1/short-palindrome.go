/*
I have an ASCII-only string which is either already a palindrome, or else can be made a palindrome by removing one character. I need to determine whether it's already a palindrome, and if not, I need to find the index of the character that would need to be removed. For example, if the string is 'aaba', then it can be made into the palindrome 'aba' by removing the first character, so I need to return 0.
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func is_pal(s string) bool {
	fmt.Println(len(s), s)
	l := len(s)
	for i := 0; i < l/2; i++ {
		if s[i] != s[l-1-i] {
			fmt.Println("false ", s)
			return false
		}
	}
	fmt.Println("true ", s)
	return true
}

func findIdx(s string) (int, int) {
	if is_pal(s) {
		return (-1),(-1)
	}
	for i := 0; i < len(s)/2; i++ {
		if s[i] != s[len(s)-1-i] {
			if is_pal(s[i+1 : len(s) - i]) {
				return (i), (len(s) - 1 - i)
			} else {
				return (len(s) - 1 - i),(i)
			}

		}
	}
	return (-1), (-1)
}

/*
Note : index start at 0
note s[0:0]  will produce no output
This helps remove char with index 0,
*/
func rem_char(s string, i int) string {
	return s[0:i] + s[i+1:len(s)]
}

func main() {
	var str string
	var str2 []string
	//Note how to create and use scanner via bufio
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	for scanner.Scan() {
		str = scanner.Text()
		if strings.Compare(str, "*") == 0 {
			break
		}
		str2 = strings.Split(str, " ")
		fmt.Println(str2[1])
		//Note how to use Atoi, similarly you can use Itoa(interger to asic)
		tmp, ok := strconv.Atoi(str2[1])
		if ok != nil {
			continue
		}
		fmt.Println(tmp)
		dstidx, srcidx := findIdx(str2[0])
		fmt.Println("Index that needs be removed to make palidtrome :",
			srcidx, dstidx)
		ba := make([]byte,0)
		ba = append(ba, str2[0]...)
		ba[dstidx] = ba[srcidx]
		fmt.Println("After fix:", string(ba))
		//fmt.Println(str2[0], is_pal(str2[0]))
		//fmt.Println(str2[0], rem_char(str2[0],tmp))
	}
}
/*
thongal@thongal-000608:~/Documents/c2016/golang/book1$::go run ~/Documents/practice/short-padrome.go
test 10
10
10
4 test
false  test
1 s
true  s
Index that needs be removed to make palidtrome : 2 1
After fix: tsst <----now its a palindrome
*/
