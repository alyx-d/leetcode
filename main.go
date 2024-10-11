package main

import (
	"fmt"
	"time"
)

func work(done chan string) {
	time.Sleep(time.Second)
	done <- "true u are right"
}

func main() {
	done := make(chan string, 1)
	go work(done)
	res := <-done
	fmt.Println(res)
}
