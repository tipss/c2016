package main

import (
	"fmt"
	"runtime"
)

type data struct {
	i, j int
}

func main() {
	defer fmt.Println("Done ")
	N := 40000000
	var s []data
	for i := 0; i < N; i++ {
		value := int(i)
		/* Init a struct and append */
		s = append(s, data{value, value})
	}
	runtime.GC()
	_ = s[0]
}
