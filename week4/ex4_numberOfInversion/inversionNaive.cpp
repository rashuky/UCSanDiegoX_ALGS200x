#ifndef INC
	#define INC
	#include <vector>
	#include <stdint.h>
	#include <cstdlib>
	#include <iostream>
	#include <fstream>

	using std::fstream;
	using std::vector;
	using std::swap;
	using std::cin;
	using std::cout;
#endif

int64_t naive(int64_t array[], int64_t n);

main()
{
	fstream input;
	input.open("4_4_inversions.in");
	int64_t n;
	input >> n;
	long data[n];
	for(int i = 0; i < n; i++)
	{
		input >> data[i];
	}
	cout << naive(data, n);
	return 0;
}

int64_t naive(int64_t array[], int64_t n)
{
	int64_t pairs = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(array[i] > array[j])
			{
				pairs++;
			}
		}
	}
	return pairs;
}