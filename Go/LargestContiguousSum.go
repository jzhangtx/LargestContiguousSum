package main

import (
	"fmt"
	"math"
)

func LargestContiguousSum(arr []int) int {
	maxSum := math.MinInt
	for i := 0; i < len(arr)-1; i++ {
		sum := arr[i]
		for j := i + 1; j < len(arr); j++ {
			if arr[j] <= arr[i] {
				break
			}
			sum = max(sum, sum+arr[j])
		}

		maxSum = max(maxSum, sum)
	}

	return maxSum
}

func main() {
	for {
		fmt.Print("Number of elements in array: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		fmt.Print("The array: ")
		vec := make([]int, count)
		for i := 0; i < count; i++ {
			fmt.Scan(&vec[i])
		}

		fmt.Print("The largest contiguous sum of array ")
		fmt.Print(vec)
		fmt.Printf(" is %d\n", LargestContiguousSum(vec))
	}
}
