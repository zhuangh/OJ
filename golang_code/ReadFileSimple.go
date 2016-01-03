package main

import (
	// "bufio"
	"fmt"
	// "io"
	"io/ioutil"
	"time"
	//"os"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func read_file(file_name string, i int) {
	start := time.Now()

	_, err := ioutil.ReadFile(file_name)
	//	f, err := os.Open(file_name)
	check(err)
	//	defer f.Close()
	//fmt.Printf("content %s , @ thread %d\n", string(dat), i)
	elapsed := time.Since(start)
	fmt.Printf("Finish time %s @ thread %d\n", elapsed, i)
}

func main() {

	start_main := time.Now()
	file_name := "test.dat"
	for i := 1; i <= 100; i++ {
		go read_file(file_name, i)
	}
	time.Sleep(time.Second * 5)
	elapsed_main := time.Since(start_main)
	fmt.Printf("Finish time %s @ main thread %d\n", elapsed_main, 0)

}
