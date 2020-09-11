/*
$ mkdir /usr/local/go/src/aPackage
$ cp aPackage.go /usr/local/go/src/aPackage/
$ go install aPackage
*/
package aPackage

import (
	"fmt"
)

func A() {
	fmt.Println("This is function A!")
}
func B() {
	fmt.Println("privateConstant:", privateConstant)
}

const MyConstant = 123
const privateConstant = 21
