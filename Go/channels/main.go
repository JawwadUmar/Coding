package main

import "fmt"

func main() {

	//CREATING A CHANNEL
	var integerChannel chan int
	integerChannel = make(chan int)

	//UNIDIRECTION CHANNEL
	// WHEN <- IS PLACED IN FRONT OF chan KEYWORD : READ ONLY CHANNEL
	// readOnlyIntegerChannel := make(<-chan int)

	// WHEN <- IS PLACED IN AFTER THE chan KEYWORD : WRITE ONLY CHANNEL
	// writeOnlyIntegerChannel := make(chan<- int)

	//UNIDIRECTIONAL CHANNELS ARE USED AS FUNCTION PARAMETERS
	//CHANNEL CONVERSION FROM BI TO UNI IS IMPLICIT

	//WRITE AND READ TO CHANNEL SHOULD HAPPEN CONCURRENTLY
	// go writeToChannel(integerChannel)

	// value := readFromChannel(integerChannel)

	// fmt.Println(value)

	underStandingClosingChannel(integerChannel)

}

func readFromChannel(integerChannel chan int) int {
	value := <-integerChannel
	return value
}

func writeToChannel(integerChannel chan int) {
	integerChannel <- 10
}

//READING FROM A CHANNEL IS A BLOCKING BEHAVIOUR
//MEANS IT WILL KEEP WAITING FOR A VALUE TO BE READ BEFORE PROGRESSING FURTHER

//WRITING TO A FULL CHANNEL IS ALSO BLOCKING
//IT WILL NOT WRITE UNTIL SOMEONE IS READING IT CONCURRENTLY

//CLOSING A CHANNEL AND UNDERSTANDING CLOSED CHANNEL
func underStandingClosingChannel(integerChannel chan int) {
	go writeToChannel(integerChannel)

	value, isChannelOpened := <-integerChannel
	fmt.Println(value, isChannelOpened)

	close(integerChannel) //THAT'S HOW WE CLOSE CHANNEL

	value, isChannelOpened = <-integerChannel
	fmt.Println(value, isChannelOpened)

}
