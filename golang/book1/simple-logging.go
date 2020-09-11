package main

import (
	"fmt"
	"log"
	"log/syslog"
	"os"
	"path/filepath"
)

func main() {
	programName := filepath.Base(os.Args[0])
	sysLog, err := syslog.New(syslog.LOG_INFO|syslog.LOG_LOCAL7, programName)
	if err != nil {
		log.Fatal(err)
	} else {
		log.SetOutput(sysLog)
	}
	log.Println("LOG_INFO + LOG_LOCAL7: Logging in Go!")
	fmt.Println("Done sending log output")
/* program terminated at this line */
	//log.Fatal(err)
	log.Panic(err)
  fmt.Println("You will not see this line, panic is similar to fatal, but with more detailed output")
}
