/* Simple file used for socker demo */
/*
How to use:
docker build -t go_hw:v1 .
docker run go_hw:v1
/* to upload image */
docker tag go_hw:v1 "thongal/go_hw:v1"
docker push  "thongal/go_hw:v1"
*/
package main

import (
	"fmt"
)

func main() {
	fmt.Println("My First Docker Image")
}
