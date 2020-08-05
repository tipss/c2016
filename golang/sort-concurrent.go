/*
Write a program to sort an array of integers.
The program should partition the array into 4 parts,
each of which is sorted by a different goroutine.
Each partition should be of approximately equal size.
Then the main goroutine should merge the 4 sorted subarrays into one large sorted array.

The program should prompt the user to input a series of integers.
Each goroutine which sorts ¼ of the array should print the subarray that it will sort.
When sorting is complete, the main goroutine should print the entire sorted list.

Submission: Upload your source code for the program.
*/
package main

import (
	"fmt"
	"sync"
	"sort"
	"strconv"
)

func swap(a []int, b[]int) {
	for i:=0; i < len(a); i++ {
		a[i],b[i] = b[i],a[i]
	}
}
func bubble(ar []int, wg *sync.WaitGroup) {

	defer wg.Done()
	sort_done := 0
	for sort_done == 0 {
		sort_done = 1
		for i := 0; i < len(ar)-1; i++ {
			if ar[i] > ar[i+1] {
				ar[i], ar[i+1] = ar[i+1], ar[i]
				sort_done = 0
			}
		}
	}
	fmt.Println("Sub array:", ar, len(ar))
}

func main() {
	var str string
	ar := make([]int, 0, 0)
	fmt.Println("Enter numbers to sort, and type 'end' when done")
	for {
		fmt.Scan(&str)
		if(string(str) == "end") {
			break;
		} else {
			number,_ := strconv.Atoi(str)
			ar = append(ar, number)
		}
	}
	//ar   := []int{ 9, 8, 7, 6, 5, 4, 3, 2 }
	part := len(ar) / 4
	if part <= 1 {
		sort.Ints(ar);
		fmt.Println(ar);
		return
	}
	for i := 0; i < len(ar)-1; i++ {
		fmt.Printf("%d ", ar[i])
	}
	
	fmt.Println("")
	var wg sync.WaitGroup
	
	start := 0
	end   := part

	for i := 1; i < 5; i++ {
		wg.Add(1)
		go bubble(ar[start:end], &wg)
		start  = end
		end   += part
		/* Fix odd size at the end subarray by including last element */
		if (end == len(ar) - 1) {
			end++;
		}
		
	}
	wg.Wait()

	fmt.Println("")
	/* Do final sort */
	sort.Ints(ar)
	for i := 0; i < len(ar)-1; i++ {
		fmt.Printf("%d ", ar[i])
	}
	fmt.Println("")
}
