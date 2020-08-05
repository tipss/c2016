package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)


var aniMap map[string]*Animal
var aniArray = []string{"cow", "bird", "snake"}
var requestArray = []string{"eat", "move", "speak"}


func init() {
	cow := new(Animal)
	bird := new(Animal)
	snake := new(Animal)
	aniMap = make(map[string]*Animal)
	aniMap[aniArray[0]] = cow.Init("grass", "walk", "moo")
	aniMap[aniArray[1]] = bird.Init("worms", "fly", "peep")
	aniMap[aniArray[2]] = snake.Init("mice", "slither", "hsss")
}

func test() {
	fmt.Printf(aniArray[0])
	aniMap[aniArray[0]].Eat()
	fmt.Printf(aniArray[1])
	aniMap[aniArray[1]].Move()
	fmt.Printf(aniArray[2])
	aniMap[aniArray[2]].Speak()
}

func processRequest(strAnimal string, strRequest string) {
	animal := aniMap[strAnimal]
	switch strRequest {
	case requestArray[0]:
		animal.Eat()
	case requestArray[1]:
		animal.Move()
	case requestArray[2]:
		animal.Speak()
	default:
		fmt.Printf("%s: Invalid Request.\n", strRequest)
	}
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if err := scanner.Err(); err != nil {
		log.Println(err)
	}
	fmt.Println(">")
	for scanner.Scan() {
		var strVal string = scanner.Text()
		if strVal == "X" {
			os.Exit(0)
		}
		strVal = strings.ToLower(strVal)
		var list = strings.Split(strVal, " ")
		if len(list) != 2 {
			continue
		}
		animal  := list[0]
		request := list[1]
		if !(itemIsInArray(animal, aniArray) && itemIsInArray(request, requestArray)) {
			continue
		}
		processRequest(animal, request)
		fmt.Println(">")
	}
}

type Animal struct{ food, locomotion, noise string }

func (a *Animal) Eat() {
	fmt.Printf("%s\n", a.food)
}

func (a *Animal) Move() {
	fmt.Printf("%s\n", a.locomotion)
}

func (a *Animal) Speak() {
	fmt.Printf("%s\n", a.noise)
}

func (a *Animal) Init(f, l, n string) *Animal {
	a.food = f
	a.locomotion = l
	a.noise = n
	return a
}
func itemIsInArray(item string, array []string) bool {
	for _, i := range array {
		if i == item {
			return true
		}
	}
	return false
}
