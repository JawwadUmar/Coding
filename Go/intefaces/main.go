package main

import "fmt"

type Animal interface {
	Speak() string
	NumberOfLegs() int
}

type Dog struct {
	Name  string
	Color string
}

func (d Dog) Speak() string {
	return "bhoww bhoww"
}

func (d Dog) NumberOfLegs() int {
	return 4
}

type Cat struct {
	Name string
}

func (c Cat) Speak() string {
	return "meow"
}

func (c Cat) NumberOfLegs() int {
	return 4
}

// "I don't care what concrete type this is. I only care that it can Speak() and tell me its number of legs
func printAnimal(a Animal) {
	fmt.Println(a.Speak())
	fmt.Println(a.NumberOfLegs())
	fmt.Println()
}

func main() {
	dog := Dog{
		Name:  "kutta",
		Color: "brown",
	}

	cat := Cat{
		Name: "kitty",
	}

	printAnimal(dog)
	printAnimal(cat)
}
