package main

import "fmt"

/*
Illustrate how to use channnel to receive or send only one direction
*/
func ping(pings chan<- string, msg string) {
	pings <- msg
}

func pong(pings <-chan string, pongs chan<- string) {
	msg := <-pings
	pongs <- msg
}

func main() {
	pings := make(chan string, 1)
	pongs := make(chan string, 1)
	ping(pings, "passed message")
	//This ensures that message goes to ping, and then to pong, and then exit
	pong(pings, pongs)

	fmt.Println(<-pongs)
}
