package main

import (
	"fmt"
	"runtime"
	"time"
)

/*
 * Prints garbage collection details
* Go garbage collector is a real- time garbage collector that runs
* concurrently with the other goroutines of a Go program and only
* optimizes for low latency.
*/

/*
 * You can also run like this: GODEBUG=gctrace=1 go run gColl.go
 *  will give more detailed trace
 */
func printStats(mem runtime.MemStats) {
	runtime.ReadMemStats(&mem)
	fmt.Println("mem.Alloc:", mem.Alloc)
	fmt.Println("mem.TotalAlloc:", mem.TotalAlloc)
	fmt.Println("mem.HeapAlloc:", mem.HeapAlloc)
	fmt.Println("mem.NumGC:", mem.NumGC)
	fmt.Println("-----")
}

func main() {
	var mem runtime.MemStats
	printStats(mem)
	for i := 0; i < 10; i++ {
		s := make([]byte, 50000000)
		if s == nil {
			fmt.Println("Operation failed!")
			printStats(mem)
		}
	}
}
