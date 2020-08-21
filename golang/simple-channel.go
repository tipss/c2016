package main

import (
"fmt"
)

//Producer
func prod(a int, b int, c chan int) {
  //Note that this go routine will be blocked
  //until main received this data
  c <- a * b
}

func main() {

//it can hold two results(buffered) before it starts blocking
c := make(chan int, 2)  

//c := make(chan int)
go prod(2, 4, c)
go prod(8, 2, c)
//Note that main is blocked until prod does comptation and send data on channel
//Consumer
c1 :=  <- c
c2 :=  <- c
//c2  = <- c  creates a dead lock, as it waits infinitely
fmt.Println(c1)
fmt.Println(c2)
fmt.Println(c1*c2)
}
