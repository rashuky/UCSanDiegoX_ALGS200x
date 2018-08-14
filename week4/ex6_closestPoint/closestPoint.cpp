#include <iostream>
#include <fstream>
#include <math.h>
#include <stdint.h>
#include "MergeSort.h"
#include "QuickSort3.h"

using std::cin;
using std::cout;
using std::fstream;

float closestPoint(int64_t points[][2], int64_t n);
float closest(int64_t points[][2], int64_t n);
float bruteForce(int64_t points[][2], int64_t n);
float min(float a, float b);
float distance(int64_t px, int64_t py, int64_t qx, int64_t qy);
float stripClosest(int64_t points[][2], int64_t n, float d);
void display(int64_t a[][2], int n);

main()
{
	fstream input;
	input.open("4_6_closest.in");
	int64_t n = 0;
	input >> n;
	int64_t points[n][2];
	for(int64_t i = 0; i < n; i++)
	{
		input >> points[i][0];
		input >> points[i][1];
	}
	
	cout << n << "\n";
	//display(points, n);
	cout << closest(points, n/2);
//input.close();
	return 0;
}

float closestPoint(int64_t points[][2], int64_t n)
{
	//float closest = 0;
	if(n <= 3)
	{
		return bruteForce(points, n);
	}
	int64_t mid = n/2;
	float dl = closestPoint(points, mid);
	float dr = closestPoint(points+mid, n-mid);//points[mid][1]
	float d = min(dl,dr);

	int64_t strip[n][2];
	int64_t j = 0;
	for(int64_t i = 0; i < n; i++)
	{
		if(abs(points[i][0] -points[mid][0]) < d)
		{
			strip[j][0] = points[i][0];
			strip[j][1] = points[i][1];
			cout << j << "\t" << strip[j][0] << "\t" << strip[j][1] << "\n";
			j++;
		}
	}
	return min(d, stripClosest(strip,j,d));
}

float min(float x, float y)
{
	return (x < y)? x : y;
}

float bruteForce(int64_t points[][2], int64_t n)
{
	float minDist = 3.402823e+38;// distance(points[0][0], points[0][1],points[1][0], points[1][1]);
	for(int i = 0; i <n; i++)
		for(int j = i+1; j < n; j++)
			if(minDist > distance(points[j][0], points[j][1],points[i][0], points[i][1]) )
				minDist = distance(points[j][0], points[j][1],points[i][0], points[i][1]);
	return minDist;
}

float distance(int64_t px, int64_t py, int64_t qx, int64_t qy)
{
	return sqrt(((qx-px)*(qx-px))+((qy-py)*(qy-py)));
}

float closest(int64_t points[][2], int64_t n)
{
	randomized_quick_sort(points,0,n);
	return closestPoint(points,n);
}

float stripClosest(int64_t strip[][2], int64_t n, float d)
{
	cout << "wlazl tu \n";
	float min = d;
	randomized_quick_sort_SecondRow(strip, 0, n);
	cout << "nie random sort \n";
	for(int64_t i = 0; i < n; i++)
	{
		for(int64_t j = i + 1; j < n && (strip[j][1] - strip[i][1]) < min; j++)
		{
			if(distance(strip[i][0], strip[i][1], strip[j][0], strip[j][1]) < min )
				min = distance(strip[i][0], strip[i][1], strip[j][0], strip[j][1]);
		}
	}
}

void display(int64_t a[][2], int n)
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << a[i][0] << "\t" << a[i][1] << "\t" << i << "\n";
	}
	cout << "\n";
}