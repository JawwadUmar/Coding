package main

import "fmt"

type Stack struct {
	stack []int
	size  int
}

func (st *Stack) push(val int) {
	st.stack = append(st.stack, val)
	st.size = st.size + 1
}

// s.items = s.items[:lastIndex]
func (st *Stack) pop() *int {
	if st.isEmpty() {
		fmt.Println("The stack is already empty")
		return nil
	}

	val := st.stack[st.size-1]
	st.stack = st.stack[:(st.size - 1)]
	st.size = st.size - 1

	return &val
}

func (st *Stack) isEmpty() bool {
	return (st.size == 0)
}

func (st *Stack) stackSize() int {
	return st.size
}

// s.items = s.items[:lastIndex]
func (st *Stack) top() int {
	val := st.stack[st.size-1]
	return val
}

type Queue struct {
	queue []int
	size  int
}

func (q *Queue) enque(val int) {
	q.queue = append(q.queue, val)
	q.size += 1
}

// s.items = s.items[:lastIndex]
func (q *Queue) deque() *int {
	if q.isEmpty() {
		fmt.Print("The queue is already empty")
		return nil
	}
	val := q.queue[0]
	q.queue = q.queue[1:]

	return &val
}

func (q *Queue) isEmpty() bool {
	return (q.size == 0)
}

func (q *Queue) queueSize() int {
	return q.size
}

// s.items = s.items[:lastIndex]
func (q *Queue) front() int {
	val := q.queue[0]
	return val
}

func main() {
	st := Stack{}

	st.push(5)
	st.push(4)
	st.push(7)
	st.push(9)

	fmt.Println(st.top())
	fmt.Println(*st.pop())
	fmt.Println(st.top())

	st.pop()
	st.pop()
	st.pop()
	st.pop()
	st.pop()
	st.pop()
}
