/*
*  Given a list of numbers and a number k,
*  return two index whether any two numbers from the list add up to k.
*  else return -1 -1
 */
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

/*
* if sort.SearchInts() is not available, then implement a binary search
* Note that binary search is possible only on a sorted list!!.(ascending)
 */
func binary(haystack []int, needle int ,beginAt int) int {

	pivot := len(haystack) / 2
	if haystack[pivot] == needle {
		fmt.Println("Returning index ", pivot, needle, len(haystack))
		return pivot +beginAt
	} else if haystack[pivot] > needle {
		return binary(haystack[:pivot],   needle,               beginAt)
	} else if haystack[pivot] < needle {
		return binary(haystack[pivot+1:], needle, (pivot + 1) + beginAt)
	}
	return (-1)
}

/*
Remember : Needs sorted input,
Understand how to use sort.SearchInts() (it needs a storted input!!)
Means, we have to store orignial index somewhere to map back the results.
*/
func twoSumSorted(nums []int, target int) (int, int) {
	fmt.Println(nums, target)
	for i, val := range nums {
		v2 := target - val
		j := sort.SearchInts(nums, v2)
		fmt.Println("SearchInts:", nums[i], " + ", nums[j], "=", nums[i]+nums[j])
		j = binary(nums, v2, 0)
		fmt.Println("BinarySear:", nums[i], " + ", nums[j], "=", nums[i]+nums[j])
		return i, j
	}
	return -1, -1
}

func main() {
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	for scanner.Scan() {
		fmt.Println("Enter numbers seperated by space, last number is target number.>>\n>", scanner.Text())
		//Remember how to convert input string to list of numbers
		strs := strings.Split(scanner.Text(), " ")
		nums := make([]int, 0)
		for _, str := range strs {
			num, ok := strconv.Atoi(str)
			if ok == nil {
				nums = append(nums, num)
			}
		}
		fmt.Println(twoSumSorted(nums[0:len(nums)-1], nums[len(nums)-1]))
	}
}
