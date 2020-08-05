package main

import "fmt"

/*
Write a program which prompts the user to enter a string.
The program searches through the entered string for the characters ‘i’, ‘a’, and ‘n’.
The program should print “Found!” if the entered string starts with the character ‘i’,
ends with the character ‘n’, and contains the character ‘a’.
The program should print “Not Found!” otherwise.

The program should not be case-sensitive,
so it does not matter if the characters are upper-case or lower-case.

Examples: The program should print “Found!” for the following example entered strings, “ian”, “Ian”, “iuiygaygn”, “I d skd a efju N”. The program should print “Not Found!” for the following strings, “ihhhhhn”, “ina”, “xian”.
*/
func findian(s string) string {
	r := []rune(s)
	fmt.Printf("len %d\n", len(r))
	if r[0] != 'i' && r[0] != 'I' {
		return "Not Found!"
	}

	if r[len(r)-1] != 'n' && r[len(r)-1] != 'N' {
		return "Not Found!"
	}
	
	for i := 1; i < len(r) - 1; i++ {
		if r[i] == 'a' || r[i] == 'A' {
			return "Found!"
		}
	}
	return "Not Found!"
}

func main() {
	var str1 string
	fmt.Printf("Enter String\n")
	fmt.Scanf("%s", &str1)
	fmt.Printf("%s\n", findian(str1));
}


/*
package main

import (
  "fmt"
  "strings"
  "bufio"
  "os"
)

func main() {
  var str string
  scanner := bufio.NewScanner(os.Stdin)

  fmt.Println("Input the sentence:")
  scanner.Scan()
  str = scanner.Text()
  str = strings.ToLower(str)
  str = strings.TrimSpace(str)
  if strings.HasPrefix(str, "i") && strings.HasSuffix(str, "n") && strings.Contains(str,"a"){
    fmt.Println("Found!")
    }else{
      fmt.Println("Not Found!")
  }
}
*/
