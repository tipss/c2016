package main

import (
	"fmt"
	"sync"
)

type Chops struct {
	sync.Mutex
}
type Philo struct {
	left, right *Chops
}
func (ph Philo) eat(number int, wg *sync.WaitGroup) {
	for i := 0; i < 3; i++ {
		ph.left.Lock()
		ph.right.Lock()
		fmt.Println("starting to eat", number)
		ph.right.Unlock()
		ph.left.Unlock()
		fmt.Println("finishing eating", number)
	}
	wg.Done()
}
func main() {
	CSticks := make([]*Chops, 5)
	for i := 0; i < 5; i++ {
		CSticks[i] = new(Chops)
	}

	phs := make([]*Philo, 5)
	for i := 0; i < 5; i++ {
		phs[i] = &Philo{CSticks[i], CSticks[(i + 1) % 5]}
	}

	var wg sync.WaitGroup
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go phs[i].eat(i + 1, &wg)
	}
	wg.Wait()
}
