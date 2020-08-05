package main

import (
	"fmt"
	"math"
)

func main() {
	// Formula: s =½ a t^2 + v0t + s0
	var a, v0, s0, t float64

	// Get initial velocity, displacement and acceleration from user
	fmt.Print("Enter the initial displacement (s0): ")
	fmt.Scan(&s0)
	fmt.Print("Enter the initial velocity (v0): ")
	fmt.Scan(&v0)
	fmt.Print("Enter the acceleration (a): ")
	fmt.Scan(&a)

	// generate and store displacement function
	DisplaceFunc := GenDisplaceFunc(a, v0, s0)

	// get user input and print the appropriate answer
	fmt.Println("==== Enter -1 to exit the program ====")
	for {
		fmt.Print("Enter time (t) to calculate displacement: ")
		fmt.Scan(&t)
		// exit if t is -1
		if t == -1 {
			break
		}
		if t < 0 {
			fmt.Print("Invalid Input!")
		} else {
			fmt.Printf("The displacement after time %f is %f.\n", t, DisplaceFunc(t))
		}
	}

}

func GenDisplaceFunc(a, v0, s0 float64) func (t float64) float64 {
	// generate a time function
	fn := func (t float64) float64 {
		return s0 + (v0 * t) + 0.5 * a * math.Pow(t, 2)
	}
	return fn
}