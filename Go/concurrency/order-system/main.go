package main

import (
	"fmt"
	"sync"
	"time"
)

type Order struct {
	OrderId   int
	OrderName string
}

var wg sync.WaitGroup

func main() {

	orders := []Order{
		Order{2, "my-order"},
		Order{3, "my-order"},
		Order{1, "my-order"},
		Order{6, "my-order"},
		Order{9, "my-order"},
		Order{11, "my-order"},
		Order{12, "my-order"},
		Order{13, "my-order"},
		Order{14, "my-order"},
		Order{15, "my-order"},
		Order{16, "my-order"},
	}

	var mutex sync.Mutex
	stringChannel := make(chan string)

	for _, order := range orders {
		wg.Add(1)
		go processOrder(order, &mutex, stringChannel)
	}

	go func() {
		wg.Wait()
		close(stringChannel)
	}()

	for msg := range stringChannel {
		fmt.Println(msg)
	}

}

func processOrder(order Order, mutex *sync.Mutex, stringChannel chan string) {

	defer wg.Done()
	time.Sleep(1 * time.Second)

	msg := fmt.Sprintf("Channel message | On order %d", order.OrderId)
	stringChannel <- msg

	mutex.Lock()
	fmt.Printf("Process order %d", order.OrderId)
	fmt.Println()
	mutex.Unlock()
}
