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

typedef struct sequence
{
	int64_t x;
	int64_t y;
};

void display(vector <vector <long> > & seq, int64_t n);
void display(vector <int64_t> points, int n);
void dataCorrectness(vector <vector <long> > a, int n);
int64_t binarySearchFirst(vector <vector <long> > & seq, int64_t left, int64_t right, int64_t point);
int64_t binarySearchSecond(vector <vector <long> > & seq, int64_t left, int64_t right, int64_t point);
