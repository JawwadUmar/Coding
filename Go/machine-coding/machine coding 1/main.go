package main

import (
	"fmt"
)

type Car struct {
	registrationNumber string
	color              string
}

type ParkingLot struct {
	capacity int
	slots    map[int]*Car
}

func NewParkingLot(capacity int) *ParkingLot {
	return &ParkingLot{
		capacity: capacity,
		slots:    make(map[int]*Car),
	}
}

func (p *ParkingLot) Park(regNumber, color string) {
	for i := 1; i <= p.capacity; i++ {
		if _, occupied := p.slots[i]; !occupied {
			p.slots[i] = &Car{regNumber, color}
			fmt.Println("Car parked at slot", i)
			return
		}
	}
	fmt.Println("Parking lot full")
}

func (p *ParkingLot) Leave(slot int) {
	if _, exists := p.slots[slot]; exists {
		delete(p.slots, slot)
		fmt.Println("Slot", slot, "is now free")
	} else {
		fmt.Println("Slot already empty")
	}
}

func (p *ParkingLot) Status() {
	fmt.Println("Slot | Registration | Color")
	for i := 1; i <= p.capacity; i++ {
		if car, exists := p.slots[i]; exists {
			fmt.Println(i, "|", car.registrationNumber, "|", car.color)
		}
	}
}

func (p *ParkingLot) GetRegNumbersByColor(color string) {
	for _, car := range p.slots {
		if car.color == color {
			fmt.Println(car.registrationNumber)
		}
	}
}

func (p *ParkingLot) GetSlotByRegNumber(reg string) {
	for slot, car := range p.slots {
		if car.registrationNumber == reg {
			fmt.Println("Slot:", slot)
			return
		}
	}
	fmt.Println("Not found")
}

func main() {

	lot := NewParkingLot(3)

	lot.Park("KA-01-HH-1234", "White")
	lot.Park("KA-01-HH-9999", "Black")
	lot.Park("KA-01-BB-0001", "White")

	lot.Status()

	lot.GetRegNumbersByColor("White")

	lot.GetSlotByRegNumber("KA-01-HH-9999")

	lot.Leave(2)

	lot.Status()
}