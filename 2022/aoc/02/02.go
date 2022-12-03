package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
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
	/*
		for _, line := range input {
			// Split the line into words
			words := strings.Split(line, " ")

			if words[0] == "A" {
				if words[1] == "X" {
					score += 3 + 1
				} else if words[1] == "Y" {
					score += 6 + 2
				} else if words[1] == "Z" {
					score += 0 + 3
				}
			}

			if words[0] == "B" {
				if words[1] == "X" {
					score += 0 + 1
				} else if words[1] == "Y" {
					score += 3 + 2
				} else if words[1] == "Z" {
					score += 6 + 3
				}
			}

			if words[0] == "C" {
				if words[1] == "X" {
					score += 6 + 1
				} else if words[1] == "Y" {
					score += 0 + 2
				} else if words[1] == "Z" {
					score += 3 + 3
				}
			}
		}

	*/
	for _, line := range input {
		// Split the line into words
		words := strings.Split(line, " ")

		if words[0] == "A" {
			if words[1] == "X" {
				score += 0 + 3
			} else if words[1] == "Y" {
				score += 3 + 1
			} else if words[1] == "Z" {
				score += 6 + 2
			}
		}

		if words[0] == "B" {
			if words[1] == "X" {
				score += 0 + 1
			} else if words[1] == "Y" {
				score += 3 + 2
			} else if words[1] == "Z" {
				score += 6 + 3
			}
		}

		if words[0] == "C" {
			if words[1] == "X" {
				score += 0 + 2
			} else if words[1] == "Y" {
				score += 3 + 3
			} else if words[1] == "Z" {
				score += 6 + 1
			}
		}
	}

	fmt.Printf("Score: %d\n", score)
}
