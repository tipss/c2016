/*
Understand difference between new() vs make()
make() is used only for slice, maps and channel, it returns value, it also zeros values
new() something like C/C++, return memory address of type passed(pointer), it does not zero values.

Learn about pointer usage(note that a function can return &x, where x is a local variable
of the function, but its value/address is not lost(like in c) upon exiting the function.
Meaning, function can return pointer variable wihtout actually calling new().

How to access pointer variable?.   (*p).name
How to allocate array/slice of struct ?

Tuples: Go does not support tuples,but it can return a tuple variable as return to function.
n1, n2 = n2, n1

*/

package main

import (
	p "fmt"
)

type person struct {
	name   string
	height int
	age    int
}

func ptrPerson(name string, h int, a int) *person {
	return &person{name, h, a}
}
func normalPerson(name string, h int, a int) person {
	return person{name, h, a}
}

//Function that returns tuple
func retThree(x int) (int, int, int) { return 2 * x, x * x, -x
}

func main() {
	//Remember how to init values of struct
	var p1 person = person{"ram", 10, 10}
	var p2 person = person{name: "sham", height: 11, age: 11}
	p.Println(p1)
	p.Println(p2)

	pSlice := make([]person, 0)
	pSlice = append(pSlice, person{"rum", 10, 10})
	pSlice = append(pSlice, p1)
	pSlice = append(pSlice, p2)
	p.Println(pSlice)

	p3 := new(person)
	p.Println(*p3)
	p3.name = "num"
	p3.age = 10
	p3.height = 11
	p.Println(*p3)
	//Another way to return a pointer to struct,
	p4 := ptrPerson("gan",33,43)
	p.Println(*p4)
	p5 := normalPerson("gandha",35,45)
	p.Println(p5)
	//pointer to an Array of person 
	p6 := new( [1]person )
	//Creates a nil slice p6 := new( []person )
	(*p6)[0].name   = "good"
	(*p6)[0].height = 10
	(*p6)[0].age    = 10
	p.Println((p6))
}
