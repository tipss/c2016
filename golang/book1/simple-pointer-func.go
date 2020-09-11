package main
import "fmt"

func main() {
	x := 0
	inc(&x)  //Increment value of x, passed as pointer to a function
	fmt.Println(x)
}

func inc(z *int) {
	(*z)++
}
