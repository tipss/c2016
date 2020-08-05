package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func BubbleSort(sli []int) {
	for range sli {
		for j := 0; j < len(sli)-1; j++ {
			if sli[j] > sli[j+1] {
				Swap(sli, j)
			}
		}
	}
}

func Swap(sli []int, j int) {
	sli[j], sli[j+1] = sli[j+1], sli[j]
}

func main() {
	fmt.Print("Please input a sequence of numbers separated by spaces, " +
		"ex: (1 2 3), only first 10 will be used: ")
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	seq := strings.Fields(scanner.Text())
	numbers := make([]int, 0, 10)
	for i := 0; i < len(seq) && i < 10; i++ {
		n, err := strconv.Atoi(seq[i])
		if err == nil {
			numbers = append(numbers, n)
		} else {
			fmt.Println("Please check input")
			os.Exit(-1)
		}
	}
	fmt.Println("Unsorted sequence:", numbers)
	BubbleSort(numbers)
	fmt.Println("Sorted sequence:", numbers)
}
