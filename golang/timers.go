package main

import (
	"fmt"
	"time"
)

func main() {
	done := make(chan bool)
	ticker := time.NewTicker(500 * time.Millisecond)
	go func() {
		for {
			select {
			case <-done:
				return
			case t := <- ticker.C:
				fmt.Println("%d", t)
			case abort():
				fmt.Println("Abort called")
			}
		}
	} ()
 	time.Sleep(1600 * time.Millisecond)
	ticker.Stop()
	done <- true
	fmt.Println("Ticker stopped")
}
