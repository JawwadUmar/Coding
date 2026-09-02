package main

import "fmt"

// import "sync"

// type Order struct {
// 	OrderId int
// }

// var wg sync.WaitGroup
// var mx sync.Mutex

// func main() {
// 	mx.Lock()
// 	mx.Unlock()
// }

// func processOrder(order Order) {

// }

func main() {
	mp := make(map[int]int)

	mp[4] = 7
	mp[5] = 2
	mp[8] = 9

	for key, val := range mp {
		fmt.Println(key, val)
	}

}
