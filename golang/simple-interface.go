package main

import (
	"fmt"
	"math"
)


type shape interface {
	area() float64
}

type circle struct {
	radius float64
}

type rectangle struct {
	length float64
	width float64
}

/* Implement Rquired interface methods */
func (c circle) area() float64 {
	return math.Pi * c.radius *  c.radius
}

func (c rectangle) area() float64 {
	return  c.length * c.width
}

/*  interface based methods whic will accept any type of object instance */
func measure(a shape){
  fmt.Printf("%f", a.area())
}
func main () {
	c := circle{ radius:100 }
	fmt.Printf(
		"Area of circle with radius %f is %f measure\n",
		c.radius,c.area())
	 measure(c)
	
	r := rectangle{ length:100, width:200 }
	fmt.Printf(
		"Area of rectanble with length %f and width %f is %f, measure \n",
		r.length, r.width, r.area())
	measure(r)
}
