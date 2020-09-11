package main

import (
	"fmt"
	"runtime"
)

/* 
Note that GC take long time about 11sec with maps with or wihtout pointer,
But it take 1sec with Slices.
time go run simple-map.go
*/

func main() {
	defer fmt.Println("Done")
	var N = 40000000
	/* define a map which store pointer to int*/
	mymap := make(map[int] *int)
	for i := 0; i < N; i++ {
		value := int(i)
		/* Store an int */
		mymap[value] = &value
	}
	/* Force GC now */
	runtime.GC()
	_ = mymap[0]
	
	/* You can disable GC by calling : debug.SetGCPercent(-1) */
	/* You can compile with this variableGOGC=100;go runn xxx. or Setting GOGC=off  */
}
