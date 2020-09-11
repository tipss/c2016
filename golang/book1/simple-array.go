
/*
Make note how to create and access multidimension array.
You can replace len() with range, its just fine.
Not that index-out-of-range error is generated at compile time, so no need to worry during run time.

Limitations of arry: 
Size should be known before  and once created, it can't be re-sized (same like C).
Its possible , by creating a new array with bigger size and copying all the elements
This issue is addressed by introducing 'slices'
Because of this limiation, arrays are rarely used in Go!, instead they use slices

Go maps are hashtables, and not comparable to slices

*/
func main() {
	anArray := [4]int{1, 2, 4, -4} // if you omit 4, then it become slice
	twoD := [4][4]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14,
		15, 16}}
	threeD := [2][2][2]int{{{1, 0}, {-2, 4}}, {{5, -1}, {7, 0}}}

	fmt.Println("The length of", anArray, "is", len(anArray)) fmt.Println("The first element of", twoD, "is", twoD[0][0]) fmt.Println("The length of", threeD, "is", len(threeD))
	for i := 0; i < len(threeD); i++ { v := threeD[i]
		for j := 0; j < len(v); j++ { m := v[j]
			for k := 0; k < len(m); k++ { fmt.Print(m[k], " ")
			}
		}
	}
}
