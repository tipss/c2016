package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)
//Remember very useful
func rotate_and_match(str1 string, match string) bool {
	//Convert incoming string to an array/slice
	arr := strings.Split(str1, "")
	for i := 0; i < len(str1); i++ {
		//Create a new slice by cutting first chat and appendint that to end
		arr = append(arr[1:], arr[0])
		//Joint string arrary and check it matches with incoming strx
		if strings.Join(arr, "") == match {
			return true
		}
	}
	return false
}

func main() {
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	for scanner.Scan() {
		fmt.Println("enter two words>", scanner.Text())
		str := strings.Split(scanner.Text(), " ")
		fmt.Println(rotate_and_match(str[0], str[1]))
	}
}
