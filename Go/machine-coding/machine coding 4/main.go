package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strings"
)

func main() {
	var selectionArray []string = []string{"Rock", "Paper", "Scissor"}

	count_user_win := 0
	count_computer_win := 0

	for count_user_win < 3 && count_computer_win < 3 {
		fmt.Print("Please enter your selection ")

		var input string
		reader := bufio.NewReader(os.Stdin)
		input, _ = reader.ReadString('\n')
		input = strings.Replace(input, "\n", "", -1)
		// strings.ReplaceAll(input, "\n", "")

		computer_selection := selectionArray[rand.Intn(3)]
		fmt.Println("The computer selected: " + computer_selection)

		if computer_selection == input {
			fmt.Println("It's a draw")
		} else if input == "Rock" {
			if computer_selection == "Scissor" {
				count_user_win++
				fmt.Println("You won ", count_user_win, " times")
				fmt.Println("The computer won ", count_computer_win, " times")
			} else {
				count_computer_win++
				fmt.Println("You won ", count_user_win, " times")
				fmt.Println("The computer won ", count_computer_win, " times")
			}
		} else if input == "Paper" {
			if computer_selection == "Scissor" {
				count_computer_win++
				fmt.Println("You won ", count_user_win, " times")
				fmt.Println("The computer won ", count_computer_win, " times")
			} else {
				count_user_win++
				fmt.Println("You won ", count_user_win, " times")
				fmt.Println("The computer won ", count_computer_win, " times")
			}
		} else if input == "Scissor" {
			if computer_selection == "Rock" {
				count_computer_win++
				fmt.Println("You won ", count_user_win, " times")
				fmt.Println("The computer won ", count_computer_win, " times")
			} else {
				count_user_win++
				fmt.Println("You won ", count_user_win, " times")
				fmt.Println("The computer won ", count_computer_win, " times")
			}
		} else {
			fmt.Println("Please enter a valid value")
			fmt.Println("You won ", count_user_win, " times")
			fmt.Println("The computer won ", count_computer_win, " times")
		}

	}

	fmt.Print()

	if count_computer_win == 3 {
		fmt.Println("Computer won")
	}
	if count_user_win == 3 {
		fmt.Println("User won")
	}

}
