/*
Demonstrate:
copy : Note copy is not append, and it takes slices as input, not array, but results will
       remain to its original type form. Copy copes into dst starting index 0, 
       unless specified
             e.g copy(dst,src)
append : Creates/allocates/uses an element from slice at the end(tail) and copy value
e.g a = append(dst,src...) < ----very important, first argument must be slice
... says, all elements of src

sort. < very important  sort.Slice(s, sort-func.....), sort.Ints(s)
*/
package main

import (
	p "fmt"
	"sort"
)

func main() {
	//Array
	a3 := [3]int{10, 20, 30}
	a5 := [5]int{1, 2, 3, 5, 4}

	//You cant do this, 	copy(a5, a3)
	p.Printf("%T, %d\n", a3, a3)
	p.Printf("%T, %d\n", a5, a5)
	//Must convert to slices before copy
	copy(a5[:], a3[0:1])  //Note you can just copy 1 element(0th element here)
	a3[0]=11 //Has no affect on a5, as copy replaces elements from original slice
	p.Printf("after copy\n a3 into a5 %T %d\n", a5,a5)
	//Note end result of copy a5 is still an array

	s1 := []int{ 1, 2, 3 }
	s2 := []int{ 4, 5, 6 }
  //s1 element are replaced with s2's
	copy(s1,s2)
	p.Printf("after copy\n a3 into a5 %T %d\n", s1,s1)
	//Note s1 is still a slice.
	copy(s1[2:], s2)  //Note you can just append 1 element
	//Only copies as much as it can hold, without chaning the size of dst.
	p.Printf("after copy\n s2 into s1 %T %d\n", s1,s1)
	s3 := []int{ 1, 2, 3 }
	s4 := []int{ 4, 5, 6 }
	s3 = append(s3, s4...)
	p.Printf("after append\n a3 into a5 %T %d\n", s3,s3)
	//Remember how to write sort function, use myarray, not just index.
	sort.Slice(s3, func (i,j int) bool { return s3[i] < s3[j] })
	p.Printf("after sort(asce)\n a3 into a5 %T %d\n", s3,s3)
	
	//Remember
	sort.Slice(s3, func (i,j int) bool { return s3[i] > s3[j] })
	p.Printf("after sort(desc)\n a3 into a5 %T %d\n", s3,s3)
	//There are built in intefaces,  sort.String() etc.
	sort.Ints(s3)
	p.Printf("after sort.Ints(asce)\n a3 into a5 %T %d\n", s3,s3)

	s3 = append(s3, s3...)  //Yes, you can append to yourself
	p.Printf("after append to self s3 %T %d\n", s3,s3)

	arr := [3]int{1,2,3}
	sli := []int{4,5,6,7}
	//Note below, append only take take slice arguments,
	// arr[:] is very important
	sli = append(sli, arr[:]...)
	p.Printf("after append to self slice %T %d\n", sli,sli)
	arr[2] = 100 //no affect
	p.Printf("after append to self slice %T %d\n", sli,sli)
}
