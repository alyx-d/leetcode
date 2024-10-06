package main

import "fmt"

func main() {
	a := 1

	f := func() {
		fmt.Println(a)
	}
	a = 2000
	f()
}
