package main

import (
	"fmt"

	"github.com/joho/godotenv"
	"test.com/utils"
)

func main() {
	godotenv.Load()
	text := "Benefits of banana"
	str, err := utils.AnalyzeMedicalReport(text)

	if err != nil {
		fmt.Printf("Found error %v", err)
	} else {
		fmt.Println(str)
	}

}
