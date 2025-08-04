package main

import (
    "fmt"
	"bufio"
	"os"
)

var stdio = bufio.NewReadWriter(
	bufio.NewReader(os.Stdin),
	bufio.NewWriter(os.Stdout),
)

func main() {
	defer stdio.Flush()

	var a, b int
	fmt.Fscan(stdio, &a, &b)
	fmt.Fprintln(stdio, a+b)
}