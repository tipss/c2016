package main

import (
	"bytes"
	"encoding/json"
	"fmt"
	"log"
	"time"
	"net/http"
	"net/url"
	"os/exec"
	"strings"
)

/*
 * e.g curl -s -X PUT http://localhost:8000/iptables\?cmd\=1
 * ./pn-iptables.sh /sbin/ping -c 1 localhost
 * curl -s -X PUT http://10.14.26.163:8000/iptables?\cmd="ls+-l"
 * Handle iptable requests
 * exec iptable request
 */
func iptableHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Content-Type", "application/json")
	q := r.URL.Query()
	m := make(map[string]interface{})
	if tz := q.Get("cmd"); tz != "" {
		fmt.Printf("Input: %s\n", tz)
		tz, _ = url.PathUnescape(tz)
		f := strings.Fields(tz)
		app := strings.Split(f[0], "/")
		f[0] = app[len(app) - 1]
		app2, err := exec.LookPath(f[0])
		if err != nil {
			fmt.Println(f,  err.Error())
			return
		}
		f[0] = app2
		k := f[1:]
		var out bytes.Buffer
		cmd := exec.Command(f[0])
		if len(f) >  1 {
			cmd = exec.Command(f[0], k...)
		}
		cmd.Stdout = &out
		fmt.Printf("exec.Command(%s, parms %s  \n" , f[0],  k);
		err2 := cmd.Start()
		// Use a channel to signal completion so we can use a select statement
		done := make(chan error)
		go func() { done <- cmd.Wait() }()

		// Start a timer
		timeout := time.After(5 * time.Second)

		// The select statement allows us to execute based on which channel
		// we get a message from first.
		select {
		case <-timeout:
			// Timeout happened first, kill the process and print a message.
			cmd.Process.Kill()
			fmt.Println("Command timed out")
		case err := <-done:
			// Command completed before timeout. Print output and error if it exists.
			fmt.Println("Output:", out.String())
			if err != nil {
				fmt.Println("Non-zero exit code:", err)
			}
		}
		m["out"] = out.String()
		if err2 != nil {
			m["err"] = err2.Error()
		}
	}
	json.NewEncoder(w).Encode(m)
}

/*
 1. Add gRPC so it can run as both http server an
*/
func main() {
	/* Various Handlers */

	/* iptable config handler */
	http.HandleFunc("/iptables", iptableHandler)
	/* Run server at port 8000 */
	log.Fatal(http.ListenAndServe(":8000", nil))
}
