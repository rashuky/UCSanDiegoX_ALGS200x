#ifndef INC
	#define INC
	#include <iostream>
	#include <vector>
	#include <stdint.h>
	#include <cstdlib>

	using std::vector;
	using std::swap;
	using std::cin;
	using std::cout;
#endif

void MergeSort(int64_t A[], int64_t p, int64_t q);
void Merge(int64_t A[], int64_t l, int64_t m, int64_t r);
void MergeSort(int64_t A[][2], int64_t p, int64_t q);
void Merge(int64_t A[][2], int64_t l, int64_t m, int64_t r);