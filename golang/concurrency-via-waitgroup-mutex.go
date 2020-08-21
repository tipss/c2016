package main


import (
	"fmt"
	"sync"
	"os"
	"net/http"
)

var wg sync.WaitGroup
var my_mutex sync.Mutex

func do_request(url string) {
	defer wg.Done()
	res, err := http.Get(url)
	if err != nil {
		panic(err)
	}
	
	//This mutex helps, when printing to console, thread switch will not happen
	my_mutex.Lock()
	defer my_mutex.Unlock()
	fmt.Printf("%d %s\n", res.StatusCode, url)
}

func main() {
	if len(os.Args) < 2 {
		fmt.Println("Usage go run <url1> <url2> .. <url3>.")
	}
	for _, url := range os.Args[1:] {
		wg.Add(1)
		go do_request("https://"+ url+".com")
	}
	wg.Wait()
}
