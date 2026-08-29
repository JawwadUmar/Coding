package main

import (
	"fmt"
	"sort"
)

func understandingArray() {
	fmt.Println("UNDERSTADNING ARRAYS")
	var arr [4]int
	arr = [4]int{4, 7, 2, 4}

	for i, x := range arr {
		fmt.Printf("The element at index %v is %v \n", i, x)
	}
	fmt.Println()
}

func understandingSlices() {
	fmt.Println("UNDERSTADNING SLICES")
	var arr []int
	arr = []int{1, 2, 3, 4, 5}
	arr = append(arr, 7)

	for i, x := range arr {
		fmt.Printf("The element at index %v is %v \n", i, x)
	}
	fmt.Println()

	fmt.Println("SLICES POINTER")
	arr = arr[1:3]
	fmt.Println(arr, arr[0])
	fmt.Println()

	fmt.Println("REMOVING AN ELEMENT FROM ith INDEX in SLICE")

	arr = []int{4, 5, 8, 7}

	//Removing an element at index 2
	arr = append(arr[:2], arr[3:]...) //The ... means expand the slice into individual arguments
	fmt.Println(arr)
	fmt.Println()

	fmt.Println("COPYING SLICE")
	//if you want to copy by value
	brr := append([]int{}, arr...)
	brr[0] = 100
	fmt.Println(brr)
	fmt.Println(arr)

	fmt.Println("USING MAKE TO MAKE SLICE")
	crr := make([]int, len(arr))
	copy(crr, arr)
	fmt.Println(crr)

	sort.Ints(crr)

}

func main() {
	// understandingSlices()
	// understandingArray()

}
