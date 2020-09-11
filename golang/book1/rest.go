package main

import (
	"flag"
	"fmt"
	"github.com/julienschmidt/httprouter"
	"log"
	"net/http"
)

var (
	// w -l  ,, to parse -l  we can use flag like this, for command lines
	addr = flag.String("addr", ":8080", "http service address")
	data map[string]string
)

/*
REST has client and server.
REST operation: Create(Post) Read(Get) Update(Put)  Delete (CRUD)
mostly based on HTTP proto, 
URL will never include method name.

*/
func show(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	k := p.ByName("key")
	if k == "" {
		fmt.Fprintf(w, "Read list: %v", data)
	}
}

func update(w http.ResponseWriter, r *http.Request, p httprouter.Params) {
	k := p.ByName("key")
	v := p.ByName("value")
	data[k] = v
	fmt.Fprintf(w, "Update: data[%s] = %s", k, data[k])
}

/*
Remember, very short version of web server/client
how to use client:(after server is started)
e.g key= first
    value = hello
    curl -X PUT localhost:8080/entry/key/val

curl -X PUT localhost:8080/entry/first/hello
curl localhost:8080/list/
*/
/*
* go get github.com/julienschmidt/httprouter
* go install github.com/julienschmidt/httprouter
 */
func main() {
	flag.Parse()
	//Init your dict here its a simple key-value store
	data = map[string]string{}
	//httpserver instance created
	r := httprouter.New()
	
	//Define URL based methods and implement methods
	r.GET("/entry/:key", show)
	
	// caller uses curl localhost:8080/list/
	r.GET("/list/", show)
	
	//caller uses curl -X PUT localhost:8080/entry/key/val
	r.PUT("/entry/:key/:value", update)
	
	//Start server
	err := http.ListenAndServe(*addr, r)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}
}
