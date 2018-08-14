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
	typedef struct Point
	{
		int64_t x;
		int64_t y;
	};

#endif

void partition3(int64_t a[], int l, int r, int *m);
void partition3(struct Point a[], int l, int r, int *m);
void partition3_SecondRow(struct Point a[], int l, int r, int *m);
void randomized_quick_sort(struct Point a[], int l, int r);
void randomized_quick_sort(int64_t a[][2], int l, int r);
void randomized_quick_sort_SecondRow(struct Point a[], int l, int r);
