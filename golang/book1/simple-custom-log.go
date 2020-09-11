package main

import (
	"fmt"
	"log"
	"os"
)

var logf = "/tmp/t1.log"

/* Creates the above file, user has to change permission chmod +rw /tmp/t1.log before reading */
/* Works, remember */
func main() {

	f, err := os.OpenFile(logf, os.O_APPEND|os.O_CREATE|os.O_WRONLY, log.LstdFlags)
	if err != nil {
		fmt.Println(err)
		return
	}
	defer f.Close()
	iLog := log.New(f, "mylog ", log.LstdFlags)
	iLog.SetFlags(log.LstdFlags)
	iLog.Println("Hello there")
	iLog.Println("Hello there")
}
