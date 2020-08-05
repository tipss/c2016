package main

import "fmt"

func main() {

	//Create initial array and loop scan prompt
	primary := make([]int, 12)
	fmt.Println("Please enter 12 integers: ")
	for i := 0; i < 12; i++ {
		fmt.Scan(&primary[i])
	}

	// Create a buffered channel
	c := make(chan []int, 4)

	//Run sub array sorts
	go SubSort(primary[:3], c)
	go SubSort(primary[3:6], c)
	go SubSort(primary[6:9], c)
	go SubSort(primary[9:12], c)
	array1 := <-c
	array2 := <-c
	array3 := <-c
	array4 := <-c

	// Merge sub arrays then sort and print new merged array
	MainSort(array1, array2, array3, array4)

}

// Func for sorting the sub arrays by calling Swap func inside
func SubSort(arr []int, c chan []int) {

	for i := len(arr); i > 0; i-- {

		Swap(arr, i)
	}

	fmt.Println(arr)

	c <- arr
}

// Func for merging creating and sorting the final array , also calling sort func.
func MainSort(arr1 []int, arr2 []int, arr3 []int, arr4 []int) {
	arr0 := []int{}
	arr0 = append(arr1, arr2...)
	arr0 = append(arr0, arr3...)
	arr0 = append(arr0, arr4...)

	for i := len(arr0); i > 0; i-- {

		Swap(arr0, i)
	}
	fmt.Printf("This is the final array")
	fmt.Println(arr0)

}

//Where the real sorting magic happens
func Swap(arr []int, i int) {
	for j := 1; j < i; j++ {
		if arr[j-1] > arr[j] {
			intermediate := arr[j]
			arr[j] = arr[j-1]
			arr[j-1] = intermediate
		}
	}
}
