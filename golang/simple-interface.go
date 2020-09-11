package main

import (
	"fmt"
	"math"
)
//Remember and practice this
/*
* Interface defines list of 'type methods' 
* that must be implemented to comply with an interface
*/

/* 
   'Interface Type' definition:
    what we do here ? 
       Group and Link a set of 'Type Methods' to 'interface' 
       and call it with a name
    Generally this will be in one package,
    and users of this interface actually implement this function in another file and use it
    e.g    func (f *file) Close() {
                ...
           }

How to compare this to Object Oriented Programming, where in there is a Object, Class etc are there.
Interface Type : allows you to  define a common behavior between different elements
                 such that all these different elements share the characteristics of an object.
                 This might permit you to say that these different elements are objects of the same 
                 class(Interface Type). However objects and classes of an actual 
                 OO languare can do many more things

*/
type shape interface {
	area() float64      // a Type Method
	perimeter() float64 // a Type Method
}

type circle struct {
	radius float64
}

type rectangle struct {
	length float64
	width  float64
}
/*
"Type Methods": Its a function with a special receiver argument.
 Parameter in the 'receiver argument' connects that argument with a function.
 As a result , this parameter is called the 'receiver of the method'
e.g area() is a Type Method.
    c is this special argument.
    c receive 'area()' method.
    Thus, type circle complies with Interface 'shape'
*/
/* Implement Rquired interface methods */
func (c circle) area() float64 {
	return math.Pi * c.radius * c.radius
}

func (c circle) perimeter() float64 {
	return (2 * c.radius * math.Pi)
}

func (c rectangle) area() float64 {
	return c.length * c.width
}

func (c rectangle) perimeter() float64 {
	return 2 * (c.length + c.width)
}

/*  interface based methods which will accept any type of object instance */
func measure(a shape) {
	fmt.Printf("%f", a.area())
}
func main() {
	c := circle{radius: 100}
	fmt.Printf(
		"Area of circle with radius %f \nis %f measure, perimeter %f\n",
		c.radius, c.area(), c.perimeter())
	measure(c)

	r := rectangle{length: 100, width: 200}
	fmt.Printf(
		"Area of rectanble with length %f and width %f \nis %f, measure perimeter %f \n",
		r.length, r.width, r.area(), r.perimeter())
	measure(r)
}
