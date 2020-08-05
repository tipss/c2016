/*
Write a program which prompts the user to first enter a name, and then enter an address.
Your program should create a map and add the name and address to the map using the
keys “name” and “address”, respectively.
Your program should use Marshal() to create a JSON object from the map,
and then your program should print the JSON object.
*/
package main

import (
	"fmt"
	"encoding/json"
)


func main() {
	//var personMap map[string]string
	type Person struct {
		name string
		addr string
	}
	pMap := make(map[string]string)
	var p1 Person
	fmt.Scanf("%s", &p1.name)
	fmt.Scanf("%s", &p1.addr)
	pMap[p1.name] = p1.addr
	barr, _ := json.Marshal(pMap)
	fmt.Println(string(barr))
}
