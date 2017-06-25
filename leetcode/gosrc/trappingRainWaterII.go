package main

// references:
// https://husobee.github.io/heaps/golang/safe/2016/09/01/safe-heaps-golang.html
// https://play.golang.org/p/Vz_mpb85uR

import (
	"container/heap"
	"fmt"
)

type tupleItem struct {
	x int
	y int
	h int
}

func (r tupleItem) Get() (int, int, int) {
	return r.x, r.y, r.h
}

type tupleItemHeap []tupleItem

func (h tupleItemHeap) Len() int { return len(h) }

func (h tupleItemHeap) Less(i, j int) bool { return h[i].h < h[j].h }

func (h tupleItemHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h *tupleItemHeap) Push(x interface{}) {
	*h = append(*h, x.(tupleItem))
}

func (h *tupleItemHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

type Pair struct {
	x int
	y int
}

func trapRainWater(heightMap [][]int) int {

	// heap
	rlen := len(heightMap)
	var clen int
	if rlen > 0 {
		clen = len(heightMap[0])
	}

	visited := make([][]bool, rlen)
	for i := range visited {
		visited[i] = make([]bool, clen)
	}

	//pq = make(PriorityQueue)
	//type pq []tupleItem
	//type PriorityQueue []tupleItem
	pq := &tupleItemHeap{}
	heap.Init(pq)
	for j := 0; j < clen; j++ {
		var tmp1 tupleItem
		tmp1.x, tmp1.y, tmp1.h = 0, j, heightMap[0][j]
		visited[0][j] = true
		heap.Push(pq, tmp1)
		var tmp2 tupleItem
		tmp2.x, tmp2.y, tmp2.h = rlen-1, j, heightMap[rlen-1][j]
		visited[rlen-1][j] = true
		heap.Push(pq, tmp2)
	}

	for i := 1; i < rlen-1; i++ {
		var tmp1 tupleItem
		tmp1.x, tmp1.y, tmp1.h = i, 0, heightMap[i][0]
		visited[i][0] = true
		heap.Push(pq, tmp1)
		var tmp2 tupleItem
		tmp2.x, tmp2.y, tmp2.h = i, clen-1, heightMap[i][clen-1]
		visited[i][clen-1] = true
		heap.Push(pq, tmp2)
	}
	//t := heap.Pop(pq)
	//fmt.Print(t)
	var max_h int
	max_h = -1
	direction := []Pair{Pair{0, 1}, Pair{-1, 0}, Pair{1, 0}, Pair{0, -1}}
	//d := Pair{0, -1}
	store := 0
	for pq.Len() > 0 {
		t := heap.Pop(pq)
		x, y, h := t.(tupleItem).Get()
		//fmt.Println(h)
		if h > max_h {
			max_h = h
		}
		for _, val := range direction {
			xx, yy := val.x, val.y
			tx, ty := x+xx, y+yy
			if tx < 0 || tx >= rlen || ty < 0 || ty >= clen || visited[tx][ty] {
				continue
			}
			if heightMap[tx][ty] < max_h {
				store += (max_h - heightMap[tx][ty])
			}
			visited[tx][ty] = true
			tmp := tupleItem{tx, ty, heightMap[tx][ty]}
			//fmt.Printf("push %d %d\n", tx, ty)
			heap.Push(pq, tmp)
		}
	}
	return store
}

func main() {
	hm := [][]int{{5, 5, 5, 1}, {5, 1, 1, 5}, {5, 1, 5, 5}, {5, 2, 5, 8}}
	fmt.Println(trapRainWater(hm))
}
