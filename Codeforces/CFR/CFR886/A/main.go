package main

import (
	"fmt"
)

func main() {
	var t int

	fmt.Scan(&t)

	for t > 0 {
		var a, b, c int

		fmt.Scan(&a, &b, &c)

		if a + b >= 10 || a + c >= 10 || b + c >= 10 {
			fmt.Print("YES\n")			
		} else {
			fmt.Print("NO\n")
		}

		t--
	}
}
