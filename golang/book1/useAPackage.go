/* Demonstrate how to use package.
* this file is part 2.
*/

package main

import (
	"aPackage"
	"fmt"
)

func main() {
	fmt.Println("Using aPackage!")
	aPackage.A()
	aPackage.B()
	fmt.Println(aPackage.MyConstant)
}
