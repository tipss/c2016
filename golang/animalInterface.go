package main

import (
	"fmt"
	"strings"
)

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

/* Implement all the Interface methods for each type of animal */
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
	return nil, "error"
}

func main() {
	const (
		query     = "query"
		newanimal = "newanimal"
	)
	var nameType, typeAction, command string

	var animalMap = make(map[string]Animal)

	for true {
		fmt.Println("cmd name atype>")
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
				}
				continue
			}
			fmt.Println("Please type an existing animal: ", animalMap)
		} else if command == newanimal {
			animal, err := createAnimal(typeAction, nameType)
			if animal != nil {
				animalMap[nameType] = animal
				fmt.Println("Created!")
				continue
			}
			fmt.Println(err)

		}
	}
}
