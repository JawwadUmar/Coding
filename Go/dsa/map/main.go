package main

import "fmt"

func main() {
	var mp map[int]int
	mp = make(map[int]int)

	for range 3 {
		var key int
		var val int

		fmt.Scan(&key)
		fmt.Scan(&val)
		mp[key] = val
	}

	for key, val := range mp {
		fmt.Println(key, " ", val)
	}
}
