package main

import "fmt"

// ReverseRunes returns its argument string reversed rune-wise left to right.
func ReverseRunes(s string) string {
	//Convert to byte array rune
	r := []rune(s)
	for i, j := 0, len(r)-1; i < len(r)/2; i, j = i+1, j-1 {
		r[i], r[j] = r[j], r[i]
	}
	return string(r)
}

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
	var i int
	fmt.Printf("len %d\n", len(r))
	if r[0] != 'i' && r[0] != 'I' {
		return "Not Found!"
	}

	if r[len(r)-1] != 'n' && r[len(r)-1] != 'N' {
		return "Not Found!"
	}
	
	for i = 1; i < len(r) - 1; i++ {
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
	fmt.Printf("Find i a n: %s\n", findian(str1));
}
