package main

import "fmt"

func main() {

	// arr := make([]int, 6)
	// arr = append(arr, 8)

	// for i, _ := range arr {
	// 	arr[i] = i*5 + 7
	// }

	// brr := []int{1, 2, 4, 5}

	// crr := append(arr, brr...)

	// fmt.Print(crr)

	s := "this is a string"

	// for i, x := range s {
	// 	fmt.Println(i, fmt.Sprintf("%c", x))
	// }

	//To cahnge a character
	arr := []rune(s)

	arr[0] = 'a'

	s = string(arr)

	for i, x := range s {
		fmt.Println(i, fmt.Sprintf("%c", x))
	}

}
