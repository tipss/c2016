package main

import (
	"encoding/json"
	"fmt"
)

type Person struct {
	FirstName  string `json:"first_name"`
	LastName   string `json:"last_name"`
	MiddleName string `json:"middle_name,omitempty"`
}

func main() {
	json_string := `
    {
        "first_name": "John",
        "last_name": "Smith"
    }`

	person := new(Person)
	json.Unmarshal([]byte(json_string), person)
	fmt.Println(person)

	new_json, _ := json.Marshal(person)
	fmt.Printf("%s\n", new_json)
}
