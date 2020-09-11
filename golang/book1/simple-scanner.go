package main

import (
	"bufio"
	"fmt"
	"os"
)
/*
Prints whatever user types in on the screen, scan and print in loop
*/
func main() {
	f := os.Stdin
	defer f.Close()
	scanner := bufio.NewScanner(f)
  for scanner.Scan() {
		fmt.Println(">", scanner.Text())
	}
}
