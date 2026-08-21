package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func solveExpression(str string) {
	str = strings.Replace(str, " ", "", -1)
	str = strings.Replace(str, "-", "+-", -1)
	str = strings.Replace(str, "\r\n", "", -1)

	arrStr := strings.Split(str, "+")
	// fmt.Println(arrStr)
	var sum int64 = 0
	for _, elem := range arrStr {
		x, err := strconv.ParseInt(elem, 10, 64)
		// fmt.Println(x)
		if err != nil {
			fmt.Println(err.Error())
			return
		}

		sum += x
	}

	fmt.Println(sum)
}

func main() {
	var str string
	reader := bufio.NewReader(os.Stdin)
	str, _ = reader.ReadString('\n')

	solveExpression(str)
}

//stack
// 6*3 + 2
//2+4*3+7
//2 + 4*5/5 + 8
