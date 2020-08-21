package main
import ("fmt")
/*
Demonstrate how to cath error at the end of the program.
Similar like python /Jave
try
//do something
except 
except raise
*/

func explode() {
	//Something not ok
	panic("panic mode")
}
func main() {
	defer func() {
		if err := recover();err != nil {
			fmt.Println("Fix error", err)
		}
	} ()

	fmt.Println("Hello")
	explode()
}