package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)
//Remember,  convert map to slice(of struct), and sort using golang buillt in
func getMaxVal(m1 map[rune]int) (retCh string) {
	//Convert map to slice(of struct)
	//Use sort.Slice(), to sort
	type kv struct {
		k rune
		v int
	}
	var kv1 []kv
	for k, v := range m1 {
		kv1 = append(kv1, kv{k,v})
	}
	sort.Slice(kv1, func (i,j int)  bool {	return (kv1[i].k > kv1[j].k) } )
	fmt.Println("After sort", kv1)
	retCh = string(kv1[0].k)
	return
}

//Remember how to return nil
func firstNonRepeatChar(a string) (retCh string) {
	m1 := make(map[rune]int)
	for _, c := range a {
		m1[c]++
	}

	fmt.Println("Max repeated char : ", getMaxVal(m1))
	for _, c := range a {
		if m1[c] == 1 {
			retCh = string(c)
			return
		}
	}
	return //returns nil in retCh automatically
}

func main() {
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	for scanner.Scan() {
		c := firstNonRepeatChar(scanner.Text())
		fmt.Println(c)
	}

}
