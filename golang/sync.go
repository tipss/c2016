package main
import (
  "fmt"
  "sync"
)
//Demonstrate how to intialized something once  only
var on sync.Once
var wg sync.WaitGroup

func setup() {
  fmt.Println("Init")
}


func dostuff(){
 on.Do(setup)
 fmt.Println("hello")
 wg.Done()
}


func main(){
wg.Add(2)
go dostuff()
go dostuff()
wg.Wait()
}
