#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

void findPair(std::vector<int>, int);

int main()
{
	int length = 0;
	std::vector<int> data;

	std::cout << "Enter array size: " << std::endl;
	std::cin >> length;

	std::srand(std::time(0));
	for (int i = 0; i < length; i++)
	{
		data.push_back(std::rand() % 200);
	}

	std::cout << "Before sorting..." << std::endl;
	for (auto x : data)
		std::cout << x << ", ";

	// std::sort(data.begin(), data.end());
	// std::cout << std::endl << "After sorting..." << std::endl;
	// for(auto x: data)
	// 	std::cout << x << ", ";

	int sum = 0;
	std::cout << std::endl
			  << "Enter sum:";
	std::cin >> sum;

	findPair(data, sum);
	std::cout << std::endl;
}

void findPair(std::vector<int> vec, int sum)
{
	// first sort the data in ascendng order
	std::sort(vec.begin(), vec.end());
	std::cout << "Sorted data :" << std::endl;
	for (auto x : vec)
		std::cout << x << ",";
	std::cout << std::endl;

	// iterate over the sorted array and for each element:X binary search the sum-X element
	//
	bool found = false;

	for (auto e : vec)
	{
		if (e < sum)
		{
			int a = e;
			int b = sum - a;
			if (std::binary_search(vec.begin(), vec.end(), b))
			{
				std::cout << "For Sum=" << sum << ", foud pair: " << a << " + " << b << std::endl;
				found = true;
			}
		}
	}
	if (!found)
	{
		std::cout << "for sum=" << sum << " no pair found " << std::endl;
	}
}
