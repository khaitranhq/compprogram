package main

import "fmt"

func test(a [][]byte) {
	a[0][0] = 'c'
}

func main() {
	tmp := [][]byte{
		{'a', 'b'},
	}
	test(tmp)
	fmt.Printf("%c", tmp[0][0])
}
