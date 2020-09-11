package main

import (
	"fmt"
	"time"
	"strconv"
)
/*
Channels are blocking by default, so they can be used for channel syncronization
* in main
*/
func main() {
	//Channels are the pipes that connect concurrent routines
	// We are creating buffered channel here with value 2,
	// Meaning, channel accept 2 message, without receiver for these messages
	out1 := make(chan string, 2)
	//Note this is not buffered
	out2 := make(chan string)
	go func() { //Annonymous function(which does order processing
		defer close(out1)
		for i := 0; i < 5; i++ {
			time.Sleep(time.Second / 2) //Order take half time of refund!
			//Sending into channel
			out1 <- "order processed "+ strconv.Itoa(i+1)
		}
	}()
	go func() { //Annonymous function(which does refund processing
		defer close(out2)
		for i := 0; i < 5; i++ {
			time.Sleep(time.Second)
			out2 <- "refund processed " + strconv.Itoa(i+1)
		}
	}()
	//Process out channels
	for {
		//Select only channels that have input
		// Select with no option a special case for channel use
		// Without this, channnels receve is blocked by default
		select {
		case msg := <-out1:
			fmt.Println(msg)
		case msg := <-out2:
			fmt.Println(msg)
		default:
			fmt.Println("no activity")
		}
	}
}
