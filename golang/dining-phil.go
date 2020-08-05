/*
Implement the dining philosopher’s problem with the following constraints/modifications.

There should be 5 philosophers sharing chopsticks, with one chopstick between each adjacent pair of philosophers.
Each philosopher should eat only 3 times (not in an infinite loop as we did in lecture)
The philosophers pick up the chopsticks in any order, not lowest-numbered first (which we did in lecture).
In order to eat, a philosopher must get permission from a host which executes in its own goroutine.
The host allows no more than 2 philosophers to eat concurrently.
Each philosopher is numbered, 1 through 5.
When a philosopher starts eating (after it has obtained necessary locks) it prints “starting to eat <number>” on a line by itself, where <number> is the number of the philosopher.
When a philosopher finishes eating (before it has released its locks) it prints “finishing eating <number>” on a line by itself, where <number> is the number of the philosopher.

*/

package main

import (
	"fmt"
	"sync"
	"time"
)

type ChopS struct {
	sync.Mutex
}

type Philo struct {
	name    string
	leftCS  *ChopS
	rightCS *ChopS
}

func (p *Philo) InitMe(lc *ChopS, rc *ChopS, name string) {
	p.rightCS = rc
	p.leftCS = lc
	p.name = name
}
/* 
Send two message at a time in a for loop, and
wait to receive two message,  
This API will close as soon as there are no channel receiver
*/
func host(wg *sync.WaitGroup, h_msg chan<- string, p_msg <-chan string) {
	defer wg.Done()
	for {
		h_msg <- " ok1"
		h_msg <- " ok2"
		for i := 0; i < 2; i++ {
			t:= <-p_msg
			fmt.Println(t)
		}
	}
}

func (p Philo) eat(wg *sync.WaitGroup, h_msg <-chan string, p_msg chan<- string) {
	defer wg.Done()
	for i := 0; i < 3; i++ {
		/* Wait for permission */
		permission := <-h_msg
		p.leftCS.Lock()
		p.rightCS.Lock()
		fmt.Println("starting to eat " + p.name + permission)
		time.Sleep(time.Second)
		fmt.Println("  finish eating " + p.name + permission)
		p.rightCS.Unlock()
		p.leftCS.Unlock()
		p_msg <- permission

	}
}

func main() {
	var p1, p2, p3, p4, p5 Philo
	var cs1, cs2, cs3, cs4, cs5 ChopS
	var wg sync.WaitGroup
	host_message := make(chan string, 2)
	pmsg         := make(chan string, 2)
	p1.InitMe(&cs1, &cs2, "1")
	p2.InitMe(&cs2, &cs3, "2")
	p3.InitMe(&cs3, &cs4, "3")
	p4.InitMe(&cs4, &cs5, "4")
	/* Dead lock p5.InitMe(&cs5, &cs1, "p5") , deadlocak is not ok */
	p5.InitMe(&cs1, &cs5, "5") /* No deadlocak as we force lower ID lock is take always  starvation is ok*/
	//We add only  5 in this list, host() we do not add
	wg.Add(5)
	go p1.eat(&wg, host_message, pmsg)
	go p2.eat(&wg, host_message, pmsg)
	go p3.eat(&wg, host_message, pmsg)
	go p4.eat(&wg, host_message, pmsg)
	go p5.eat(&wg, host_message, pmsg)
	go host(&wg, host_message, pmsg)
	wg.Wait()
	close(pmsg) //Only after this host will exit.
	close(host_message)
}

/*
mplement the dining philosopher’s problem with the following constraints/modifications.

There should be 5 philosophers sharing chopsticks, with one chopstick between each adjacent pair of philosophers.
Each philosopher should eat only 3 times (not in an infinite loop as we did in lecture)

The philosophers pick up the chopsticks in any order, not lowest-numbered first (which we did in lecture).
In order to eat, a philosopher must get permission from a host which executes in its own goroutine.
The host allows no more than 2 philosophers to eat concurrently.

Each philosopher is numbered, 1 through 5.
When a philosopher starts eating (after it has obtained necessary locks) it prints “starting to eat <number>” on a line by itself, where <number> is the number of the philosopher.
When a philosopher finishes eating (before it has released its locks) it prints “finishing eating <number>” on a line by itself, where <number> is the number of the philosopher.
*/
