package main

import (
	"sort"
)

func findMin(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func createRhombus(r int, c int, sideLength int, grid [][]int) int {
	n := len(grid)
	m := len(grid[0])

	if r+2*sideLength >= n || c+sideLength >= m || c-sideLength < 0 {
		return 0
	}

	if sideLength == 0 {
		return grid[r][c]
	}

	temp := 0
	res := 0

	for temp < sideLength {
		res += grid[r][c]
		r += 1
		c += 1
		temp += 1
	}

	temp = 0
	for temp < sideLength {
		res += grid[r][c]
		r += 1
		c -= 1
		temp += 1
	}

	temp = 0
	for temp < sideLength {
		res += grid[r][c]
		r -= 1
		c -= 1
		temp += 1
	}

	temp = 0
	for temp < sideLength {
		res += grid[r][c]
		r -= 1
		c += 1
		temp += 1
	}

	return res
}

func getBiggestThree(grid [][]int) []int {
	n := len(grid)
	m := len(grid[0])

	sideLength := (findMin(n, m) - 1) / 2
	var res []int
	mp := make(map[int]int)

	for sideLength >= 0 {
		for i := 0; i < n; i++ {
			for j := 0; j < m; j++ {
				x := createRhombus(i, j, sideLength, grid)
				mp[x]++
			}
		}
		sideLength--
	}

	//get sorted key
	var keys []int
	for key := range mp {
		keys = append(keys, key)
	}

	sort.Slice(keys, func(i, j int) bool {
		return keys[i] > keys[j]
	})

	for _, val := range keys {
		res = append(res, val)
	}

	return res
}

func main() {

}
