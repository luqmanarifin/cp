package main

import (
	"C"
	"bufio"
	"fmt"
	"os"
)

func main() {
	var n, m int
	fmt.Sscan("%d %d", &n, &m)
	fmt.Println(n, m)
	i := 0
	greyscale := true
	reader := bufio.NewReader(os.Stdin)

	for i < n {
		j := 0
		for j < m {
			c, _, _ := reader.ReadRune()
			if c != 'W' && c != 'B' {
				greyscale = false
			}
		}
	}
	if greyscale {
		fmt.Println("#Black&White")
	} else {
		fmt.Println("#Color")
	}
}
