/*
Write a program which allows the user to create a set of animals and to get information about those animals.
Each animal has a name and can be either a cow, bird, or snake.
With each command, the user can either create a new animal of one of the three types,
or the user can request information about an animal that he/she has already created.
Each animal has a unique name, defined by the user. Note that the user can define
animals of a chosen type, but the types of animals are restricted to either cow, bird, or snake.
The following table contains the three types of animals and their associated data.

Your program should present the user with a prompt, “>”, to indicate that the user can
type a request. Your program should accept one command at a time from the user, print out a response,
and print out a new prompt on a new line.

Your program should continue in this loop forever.
Every command from the user must be either a “newanimal” command or a “query” command.

Each “newanimal” command must be a single line containing three strings.
The first string is “newanimal”.
The second string is an arbitrary string which will be the name of the new animal.
The third string is the type of the new animal, either “cow”, “bird”, or “snake”.

Your program should process each newanimal command by creating the
new animal and printing “Created it!” on the screen.

Each “query” command must be a single line containing 3 strings.
The first string is “query”.
The second string is the name of the animal.
The third string is the name of the information requested about the animal,
either “eat”, “move”, or “speak”.
Your program should process each query command by printing out the requested data.

Define an interface type called Animal which describes the methods of an animal. Specifically, the Animal interface should contain the methods Eat(), Move(), and Speak(), which take no arguments and return no values. The Eat() method should print the animal’s food, the Move() method should print the animal’s locomotion, and the Speak() method should print the animal’s spoken sound. Define three types Cow, Bird, and Snake. For each of these three types, define methods Eat(), Move(), and Speak() so that the types Cow, Bird, and Snake all satisfy the Animal interface. When the user creates an animal, create an object of the appropriate type. Your program should call the appropriate method when the user issues a query command.
e.g
input               : output
newanimal  xxx cow  : Created it!;
query xxx eat  : grass
*/
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type Animal struct {
	atype string
	name  string
	
}

func (a *Animal) InitMe(atype string, name string) {
	a.atype = atype
	a.name = name
}

func (a *Animal) Eat() {
	if a.atype == "cow" {
		fmt.Println("grass")
	}
	if a.atype == "bird" {
		fmt.Println("worms")
	}
	if a.atype == "snake" {
		fmt.Println("mice")
	}
}

func (a *Animal) Move() {
	if a.atype == "cow" {
		fmt.Println("walk")
	}
	if a.atype == "bird" {
		fmt.Println("fly")
	}
	if a.atype == "snake" {
		fmt.Println("slither")
	}
}

func (a *Animal) Speak() {
	if a.atype == "cow" {
		fmt.Println("moo")
	}
	if a.atype == "bird" {
		fmt.Println("pee")
	}
	if a.atype == "snake" {
		fmt.Println("hsss")
	}
}
func (a *Animal) GetName() string {
	return a.name
}

func (a *Animal) GetType() string {
	return a.atype
}

func main() {
	var cmd, name, atype, reader string
	list := []Animal{}
	var ani Animal
	scanner := bufio.NewScanner(os.Stdin)
	for {
		fmt.Print("cmd name action>")
		scanner.Scan()
		reader = scanner.Text()
		if err := scanner.Err(); err != nil {
			os.Exit(1)
		}
		words := strings.Split(reader, " ")
		cmd   = words[0]
		name  = words[1]
		atype = words[2]
		if cmd == "newanimal" {
			var a1 Animal
			a1.InitMe(atype, name)
			list = append(list, a1)
		} else if cmd == "query" {
			for _, ani = range list {
				if ani.GetName() == name {
					if atype == "speak" {
						ani.Speak()
					}
					if atype == "eat" {
						ani.Eat()
					}
					if atype == "move" {
						ani.Move()
					}
					break
				}
			}
		}
	}
}
