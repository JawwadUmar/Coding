package main

import (
	"container/heap"
	"fmt"
)

type Patient struct {
	name        string
	severity    int
	arrivalTime int
}

type PriorityQueue []Patient

func (pq PriorityQueue) Len() int {
	return len(pq)
}

func (pq PriorityQueue) Less(i, j int) bool {
	if pq[i].severity == pq[j].severity {
		return pq[i].arrivalTime < pq[j].arrivalTime // earlier first
	}
	return pq[i].severity > pq[j].severity // higher severity first
}

func (pq PriorityQueue) Swap(i, j int) {
	pq[i], pq[j] = pq[j], pq[i]
}

func (pq *PriorityQueue) Push(x interface{}) {
	*pq = append(*pq, x.(Patient))
}

func (pq *PriorityQueue) Pop() interface{} {
	old := *pq
	n := len(old)
	patient := old[n-1]
	*pq = old[:n-1]
	return patient
}

func main() {

	var pq PriorityQueue
	// heap.Init(&pq)
	heap.Push(&pq, Patient{"jae", 45, 2})
	heap.Push(&pq, Patient{"fhd", 22, 2})
	heap.Push(&pq, Patient{"hj", 42, 2})
	fmt.Println(pq[0])

}
