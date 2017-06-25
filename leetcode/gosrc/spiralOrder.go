package main
//import "fmt"


func spiralOrder(matrix [][]int) []int {
	var res1 []int
	valid := true
	n:=len(matrix)
	if n == 0 {
		return res1
	} 
	m:=len(matrix[0])
	if m == 0 {
		return res1
	}

	k:=0
	col_left := 0
	row_upper := 0
	col_right := m-1
	row_lower := n-1 
	res := make([]int, m*n, n*m)
        for valid { 
		for x_inc := col_left; x_inc < col_right+1; x_inc++ {	
			res[k] = matrix[row_upper][x_inc]
//			fmt.Printf("%d: %d < %d", k,x_inc, col_right+1)
			k++
		}
//		fmt.Println(row_upper)
		row_upper += 1 
		if row_upper > row_lower { break}
		for y_inc := row_upper; y_inc<row_lower+1; y_inc++{
			res[k]=matrix[y_inc][col_right]
//			fmt.Printf("%d: ", k)
			k++
		}
		col_right -=1 
		if col_right < col_left { break}
		for x_dec := col_right; x_dec > col_left-1; x_dec--{
			res[k]=matrix[row_lower][x_dec]
			k++
		}
		row_lower-=1
		if row_lower < row_upper {break }
		for y_dec := row_lower; y_dec > row_upper-1; y_dec-- {
			res[k]=matrix[y_dec][col_left]
			k++
		}
		col_left +=1
//		fmt.Println(col_left)
		if col_right < col_left { break}
	}
	return res[0:m*n]
}


    

func main(){
        matrix := [][] int{{1,2,3},{4,5,6},{7,8,9} ,{1,2,3},{4,5,6},{7,8,9}   }
	spiralOrder(matrix)

}
