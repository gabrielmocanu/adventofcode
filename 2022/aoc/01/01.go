package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
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
	calories := [300]int{}
	index := 0

	// Count calories for each elf
	for _, v := range input {
		if len(v) > 0 {
			cal, err := strconv.Atoi(v)

			if err != nil {
				fmt.Println(err)
			}

			calories[index] += cal

		} else {
			index++
		}
	}
	// Sort them descending
	sort.Slice(calories[:], func(i, j int) bool {
		return calories[i] > calories[j]
	})

	// Print the most calories
	fmt.Printf("Calories: %d\n", calories[0])

	// Print sum of top 3 calories
	fmt.Printf("Calories: %d\n", calories[0]+calories[1]+calories[2])

}
