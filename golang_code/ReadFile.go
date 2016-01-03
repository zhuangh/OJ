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

func read_file(file_list []string, i int) {
	start := time.Now()

	bin_size := 0

	for _, file_name := range file_list {
		dat, err := ioutil.ReadFile(file_name)
		// f, err := os.Open(file_name)
		check(err)
		bin_size += len(dat)
	}
	//	defer f.Close()
	//fmt.Printf("content %s , @ thread %d\n", string(dat), i)
	elapsed := time.Since(start)
	fmt.Printf("finish time %s , file size = %d @ thread %d\n", elapsed, bin_size, i)
}

func main() {

	start_main := time.Now()

	time.Sleep(time.Second * 5)
	// file_name := "spG.dat"
	file_list := []string{"spC.dat", "Isrc.dat", "spG.dat", "Isrc.dat"}
	for i := 1; i <= 8; i++ {
		// read_file(file_name, i)
		go read_file(file_list, i)
	}
	time.Sleep(time.Second * 15)

	elapsed_main := time.Since(start_main)
	fmt.Printf("-------------\nfinish time %s @ main thread\n-------------\n", elapsed_main)

}
