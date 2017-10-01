package main

import "fmt"

func dfs(matrix [][]int, visited [][]int, x int, y int, xz int, yz int) {
	visited[x][y] = 1
	direction := [][]int{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}

	for _, d := range direction {
		xd := x + d[0]
		yd := y + d[1]
		if xd >= 0 && yd >= 0 && xd < xz && yd < yz {
			if visited[xd][yd] != 1 && matrix[x][y] <= matrix[xd][yd] {
				// move to next position
				dfs(matrix, visited, xd, yd, xz, yz)
			}
		}
	}
}

func pacificAtlantic(matrix [][]int) [][]int {
	xz := len(matrix)
	res := make([][]int, 0)
	if xz <= 0 {
		return res
	}
	yz := len(matrix[0])
	if yz <= 0 {
		return res
	}

	// reachablity matrices
	p_visited := make([][]int, xz)
	a_visited := make([][]int, xz)
	for i := 0; i < xz; i++ {
		p_visited[i] = make([]int, yz)
		a_visited[i] = make([]int, yz)
		for j := 0; j < yz; j++ {
			p_visited[i][j] = 0
			a_visited[i][j] = 0
		}
	}

	for i := 0; i < xz; i++ {
		dfs(matrix, p_visited, i, 0, xz, yz)    // test the reachablity from pacific
		dfs(matrix, a_visited, i, yz-1, xz, yz) // test the reachablity from altantic
	}
	for i := 0; i < yz; i++ {
		dfs(matrix, p_visited, 0, i, xz, yz)    // test the reachablity from pacific
		dfs(matrix, a_visited, xz-1, i, xz, yz) // test the reachablity from altantic
	}
	for i := 0; i < xz; i++ {
		for j := 0; j < yz; j++ {
			if p_visited[i][j] == 1 && a_visited[i][j] == 1 {
				// reachable from pacific and altantic
				res_tmp := []int{i, j}
				res = append(res, res_tmp)
			}
		}
	}
	return res
}

func main() {
	matrix := [][]int{{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}}
	fmt.Println(pacificAtlantic(matrix))
}
