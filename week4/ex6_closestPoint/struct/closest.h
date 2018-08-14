
	#define INC
	#include <iostream>
	#include <vector>
	#include <stdint.h>
	#include <cstdlib>
	#include <fstream>
	#include <float.h>
	#include <math.h>
	#include "QuickSort3.h"

	using std::fstream;
	using std::cout;
	using std::cin;
	using std::vector;
	using std::swap;

	typedef struct Point
	{
		int64_t x;
		int64_t y;
	};

void display(Point points[], int64_t n);
void checkFR(Point points[], int64_t n);
void checkSR(Point points[], int64_t n);
int compareX(const void* a, const void* b);
int compareY(const void* a, const void* b);
float dist(Point p1, Point p2);
float bruteForce(Point points[], int64_t n);
float min(float x, float y);
float stripClosest(Point points[], int64_t n, float d);
float closestUtil(Point P[], int n);
float closest(Point points[], int64_t n);