package main

import (
	"fmt"
	"math/rand"
	_ "strconv"
	"time"
)

var x = make(map[int]int, 100000001)

func main() {
	ttime := time.Now().UnixNano()

	fmt.Printf("len x %d \n", len(x))
	for i := 1; i < 100000001; i++ {
		x[rand.Intn(i)] = rand.Intn(i)
	}
	fmt.Printf("len1 x%d \n", len(x))

	ttime1 := time.Now().UnixNano()

	fmt.Printf("time cal %f\n", float64(ttime1-ttime)/float64(1*time.Second))
}
