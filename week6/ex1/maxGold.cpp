#include <iostream>
#include <stdio.h>
#include <fstream>

using std::cout;
using std::cin;
using std::fstream;

int maxKnapsack(int64_t n, int64_t val[], int64_t W, int64_t w[]);
int max(int a, int b);
int main()
{
	fstream input;
	input.open("6_1_knapsack.in");
	int64_t W = 0;
	int64_t n = 0;
	input >> W;
	input >> n;
	cout << W << "\t" << n;
	int64_t w[n];
	int64_t val[n];
	for( int i = 0; i < n; i++)
	{
		input >> w[i];
		val[i] = w[i];
	}
	cout << maxKnapsack(n,val,W,w);
	return 0;
}

int max(int a, int b) 
{ 
	return (a > b)? a : b; 
}

int maxKnapsack(int64_t n, int64_t val[], int64_t W, int64_t w[])
{
	int i, j;
	int K[n + 1][W + 1];
	for( i = 0; i <= n; i ++)
	{
		for( j = 0; j <= W; j++)
		{
			if(i == 0 || j == 0)
				K[i][j] = 0;
			else if(w[i - 1] <= j)
				K[i][j] = max(val[i - 1] + K[i - 1][j - w[i-1]],K[i - 1][j]);
			else 
				K[i][j] = K[i - 1][j];
			cout << i << " ";
		}
		cout << "\n";
	}
	return K[n][W];
}