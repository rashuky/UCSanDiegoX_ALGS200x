#ifndef INC
	#define INC
	#include <iostream>
	#include <vector>
	#include <stdint.h>
	#include <cstdlib>
	#include <fstream>

	using std::vector;
	using std::swap;
	using std::cin;
	using std::cout;
	using std::fstream;
#endif

#include "QuickSort3.h"
#include "MergeSort.h"
void display(int64_t a[], int n);
void display(int64_t a[][2], int n);
void dataCorrectness(int64_t a[][2], int n);
int64_t searchSmaller(int64_t a[][2], int64_t n, int64_t Item);
int64_t searchGreater(int64_t a[][2], int64_t n, int64_t Item);
int64_t naive(int64_t seq[][2], int64_t s, int64_t points[], int64_t p);
int64_t binarySearchGreater(int64_t a[][2], int64_t n, int64_t Item);