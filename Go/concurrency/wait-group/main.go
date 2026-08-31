package main

import (
	"fmt"
	"sync"
)

var wg sync.WaitGroup

func main() {
	wg.Add(1)
	go printOneToTen()
	wg.Wait()
}

func printOneToTen() {

	defer wg.Done()
	i := 0
	for i <= 10 {
		fmt.Println(i)
		i++

	}
}
