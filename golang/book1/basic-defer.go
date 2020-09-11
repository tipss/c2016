package main

/*
* defer keyword postpones the execution of a function/statement
* until the surrounding function return. Can be included many times e.g in for loops etc or per function
* deferred functions are executed in last in first out order.
* f1 ->f2->f3, say all the three function have defer keyword,
* f3's defer is executed fist, then f2s and f1.
 */
import (
	"fmt"
)

func d1() {
	for i := 3; i > 0; i-- {
		defer fmt.Print(i, " ")
	}
}
func d2() {
	for i := 3; i > 0; i-- {
		defer func() { fmt.Print(i, " ") }() //anonymous function
	}
}
func d3() {
	for i := 3; i > 0; i-- {
		defer func(n int) { fmt.Print(n, " ") }(i) //anonymous function with ARG
	}
}

func main() {
	d1()
	fmt.Println()
	d2()
	fmt.Println()
	d3()
	fmt.Println()
}

/*
thongal@thongal-000608:~/Documents/c2016/golang/book1$::go run ./basic-defer.go
1 2 3  <------- defered print is exeduted last in first out.
0 0 0  <---------defered function do not have input value assigned correctly
1 2 3  <------- deferred function  take correct input values print in LIFO
*/
