package utils

import (
	"bufio"
	"fmt"
	"os"
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
