package main

import (
	"fmt"
	"strings"
)

//Remember very good written program

type AnimalType struct {
	name string
}
type Cow AnimalType
type Bird AnimalType
type Snake AnimalType

type Animal interface {
	Speak()
	Move()
	Eat()
}

func (a Snake) Speak() {
	fmt.Println("hsss")
}

func (a Snake) Move() {
	fmt.Println("slither")
}

func (a Snake) Eat() {
	fmt.Println("mice")
}
func (a Bird) Speak() {
	fmt.Println("peep")
}

func (a Bird) Move() {
	fmt.Println("fly")
}

func (a Bird) Eat() {
	fmt.Println("worms")
}
func (a Cow) Speak() {
	fmt.Println("moo")
}

func (a Cow) Move() {
	fmt.Println("walk")
}

func (a Cow) Eat() {
	fmt.Println("grass")
}

func createAnimal(typeAnimal string, name string) (Animal, string) {
	switch strings.ToLower(typeAnimal) {
	case "cow":
		return Cow{name: name}, ""
	case "snake":
		return Snake{name: name}, ""
	case "bird":
		return Bird{name: name}, ""
	}
	return nil, "error During creation"
}

func main() {
	defer fmt.Println("Leaving the program")
	const (
		query     = "query"
		newanimal = "newanimal"
	)
	var nameType, typeAction, command string

	var animalMap = make(map[string]Animal)

	for true {
		fmt.Println("Input what do you wanna do (command, name/type, type/action ):")
		fmt.Print("> ")
		fmt.Scanf("%s %s %s", &command, &nameType, &typeAction)
		if command == query {
			if val, ok := animalMap[nameType]; ok {
				switch strings.ToLower(typeAction) {
				case "eat":
					val.Eat()
				case "move":
					val.Move()
				case "speak":
					val.Speak()
				default:
					fmt.Println("Please enter a valid Method (Speak, Eat, Move)")
				}
				continue
			}
			fmt.Println("Please type an existing animal: ", animalMap)
		} else if command == "exit" || nameType == "exit" {
			break
		} else if command == newanimal {
			animal, err := createAnimal(typeAction, nameType)
			if animal != nil {
				animalMap[nameType] = animal
				fmt.Println("Created!")
				continue
			}
			fmt.Println(err)

		} else {
			fmt.Println("This command is not supported, please entre 'query' or 'newanimal")
		}
	}
}
