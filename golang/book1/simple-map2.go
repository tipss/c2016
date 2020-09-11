package main

import (
	"fmt"
	"runtime"
)

func main() {
	defer fmt.Println("Done")
	var N = 40000000
	/* define a map */
	mymap := make(map[int] int)
	for i := 0; i < N; i++ {
		value := int(i)
		mymap[value] = value
	}
	runtime.GC()
	_ = mymap[0]
}
