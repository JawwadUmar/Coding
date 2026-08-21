package main

import (
	"fmt"
	"strings"
)

func printingAndModifyingCharacters() {
	fmt.Println("PRINTING CHARACTERS")
	s := "hello this is world"
	for idx, ch := range s {
		fmt.Printf("The character at %v is %c", idx, ch) //use %c for rune and byte
		fmt.Println()
	}
	fmt.Println()

	fmt.Println("MODIFYING CHARACTERS")
	arr := []byte(s)
	arr[0] = 'b'
	s = string(arr)
	fmt.Println(s)
	fmt.Println()

	fmt.Println("IMPORTANT STRING FUNCTIONS")
	var flag bool = strings.Contains(s, "this is")
	fmt.Println(flag)

	var idx int = strings.Index(s, "this is")
	fmt.Println(idx)

	// var totalOccurrenceSubstr int = strings.Count(s, "world")
	// fmt.Println(totalOccurrenceSubstr)

	s = strings.ReplaceAll(s, "bello", "hello")
	fmt.Println(s)

	words := strings.Split(s, " ")
	fmt.Println(words)

	s = strings.Join(words, ",")
	fmt.Println(s)

}

func main() {

	printingAndModifyingCharacters()

}
