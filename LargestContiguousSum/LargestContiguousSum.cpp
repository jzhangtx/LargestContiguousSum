// LargestContiguousSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int LargestContiguousSum(std::vector<int>& arr)
{
	int sum = 0;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		// keep the bigger one between the sum and the single element subarray
		if (sum < arr[i])
			sum = arr[i];

		// calculate the sum of the subarraies that have contiguous elements
		int sum1 = arr[i];
		for (size_t j = i + 1; j < arr.size(); ++j)
		{
			if (arr[j] > arr[j - 1] != 1)
				break;
			sum1 += arr[j];
			if (sum < sum1)	// keep the bigger sum
				sum = sum1;
		}
	}

	return sum;
}

int main()
{
	while (true)
	{
		int count = 0;
		std::cout << "Number of elements in the array: ";
		std::cin >> count;
		if (count == 0)
			break;

		std::vector<int> vec(count);
		std::cout << "The number array: ";
		for (int i = 0; i < count; ++i)
			std::cin >> vec[i];

		std::cout << "The largest Contiguous Sum is: " << LargestContiguousSum(vec) << std::endl;
	}
}