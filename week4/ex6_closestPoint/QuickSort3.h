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

void partition3(int64_t a[], int l, int r, int *m);
void partition3(int64_t a[][2], int l, int r, int *m);
void partition3_SecondRow(int64_t a[][2], int l, int r, int *m);
void randomized_quick_sort(int64_t a[], int l, int r);
void randomized_quick_sort(int64_t a[][2], int l, int r);
void randomized_quick_sort_SecondRow(int64_t a[][2], int l, int r);
