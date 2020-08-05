/*
Write two goroutines which have a race condition when executed concurrently.
Explain what the race condition is and how it can occur.
Submission: Upload your source code for the program along with
your written explanation of race conditions.
*/

package main

import (
	"fmt"
	"time"
)

func f1(x *int) {
	for i := 0; i < 100; i++ {
		time.Sleep(100)
		(*x) += 1
	}
	fmt.Println(*x)
}

func f2(x *int) {
	for i := 0; i < 110; i++ {
		time.Sleep(80)
		(*x) += 1
	}
	fmt.Println(*x)
}

/*
*
What is race-condition?.

Outcome of executing goroutine f1 and f2 concurrently
which basically increment value x passed by reference
is unpredictable. This is mainly due to race-condition
where in both routines f1 and f2 are scheduled without
an order, instead ordered by availability of CPU(core) resources
available to OS(e.g MAC OS).

This race-condition can be avoid if we maintain a fixed order of
execution of these goroutine. This fix is also termed as synchronization.

Here the output when executed, value of x is uncertain in each run

tt@tt-000608:~/mygo/src$::./racecondition
134
209
209
tt@tt-000608:~/mygo/src$::./racecondition
179
206
206
tt@tt-000608:~/mygo/src$::./racecondition
170
206
206
tt@tt-000608:~/mygo/src$::./racecondition
176
208
208
tt@tt-000608:~/mygo/src$::./racecondition
134
210
210
tt@tt-000608:~/mygo/src$:
*/
func main() {
	x := 0
	go f1(&x)
	go f2(&x)
	time.Sleep(time.Second)
	fmt.Println(x)
}
