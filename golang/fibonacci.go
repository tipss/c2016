package main

import (
	"fmt"
	"time"
)

// non-recursive and also not concurrent
func fib1(n int) int {
	if n <= 1 {
		return (n)
	}
	a := 0
	b := 1
	for i := 1; i < n; i++ {
		a, b = b, a + b
	}
	return b
}

//Recursive, but not concurrent
func fib(n int) int {

	if n <= 1 {
		return n
	}
	return fib(n-1) + fib(n-2)

}

func fibChan(n int) chan int{
	c := make(chan int)
	go func() {
		a,b := 0,1
		for i := 0; i < n; i++ {
			c <- a
			a, b = b, a + b
		}
		close(c)
	} ()
	return c
}

func main() {
	n := 10
	start := time.Now()
	for i := 0; i <  n; i++ {
		fmt.Println(fib(i))
	}
	end := time.Now()
	fmt.Println(end.Sub(start))
	start = time.Now()
	for i := 0; i <  n; i++ {
		fmt.Println(fib1(i))
	}
	end = time.Now()
	fmt.Println(end.Sub(start))
	
	//Unbuffered, so it does sequiential 
	c := fibChan(n)
	start = time.Now()
	for i := range c {
		fmt.Println(i)
	}
	end = time.Now()
	fmt.Println(end.Sub(start))
}
