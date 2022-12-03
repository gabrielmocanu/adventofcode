package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

func scanLines(file string) []string {
	var strArray []string

	readFile, err := os.Open(file)

	if err != nil {
		fmt.Println(err)
	}

	fileScanner := bufio.NewScanner(readFile)
	fileScanner.Split(bufio.ScanLines)

	for fileScanner.Scan() {
		strArray = append(strArray, fileScanner.Text())
	}

	readFile.Close()

	return strArray
}

func main() {

	// Read file
	input := scanLines("input.txt")
	score := 0

	// Part 1
	// for _, line := range input {
	// 	for _, char := range line[0 : len(line)/2] {
	// 		if strings.Index(line[len(line)/2:], string(char)) > -1 {
	// 			if unicode.IsUpper(char) {
	// 				score += int(char) - 65 + 27
	// 			} else {
	// 				score += int(char) - 97 + 1
	// 			}
	// 			break
	// 		}
	// 	}
	// }

	// Part 2
	for i := 0; i < len(input); i++ {
		if i%3 == 0 {
			for _, char := range input[i] {
				if strings.Index(input[i+1], string(char)) > -1 && strings.Index(input[i+2], string(char)) > -1 {
					if unicode.IsUpper(char) {
						score += int(char) - 65 + 27
					} else {
						score += int(char) - 97 + 1
					}
					fmt.Println(string(char))
					break
				}
			}
		}
	}

	fmt.Printf("Score: %d\n", score)

}
