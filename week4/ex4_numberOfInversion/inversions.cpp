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


int64_t MergeSort(int64_t A[], int64_t p, int64_t q);
int64_t Merge(int64_t A[], int64_t l, int64_t m, int64_t r);

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
	cout << MergeSort(data,0, n-1);
	return 0;
}


int64_t Merge(int64_t A[], int64_t l, int64_t m, int64_t r)
{
	int64_t nb = m-l+1;
	int64_t nc = r-m;
	int64_t B[nb];
	int64_t C[nc];
	int64_t pairs = 0;
	for(int64_t i = 0; i < nb; i++)
	{
		B[i] = A[l + i];
	}
	for(int64_t j = 0; j < nc ; j++)
	{
		C[j] = A[m + 1 + j];		
	}
	int64_t i = 0;
	int64_t j = 0;
	int64_t k = l;
	// Merging two arrays	
	while(i < nb && j < nc)
	{
		if(B[i] <= C[j])
		{
			A[k] = B[i];
			i++;
		}else
		{
			A[k] = C[j];
			j++;
			pairs += nb - i;
		}
		k++;
	}
	
	
	// Merging the rest of array B (C is empty if this while is working)
	while(j < nc)
	{
		A[k] = C[j];
		j++;
		k++;
	}
	// Merging the rest of array C (B is empty if this while is working)
	
	while(i < nb)
	{
		A[k] = B[i];
		i++; 
		k++;
	}
	return pairs;
}

int64_t MergeSort(int64_t A[], int64_t l, int64_t r)
{
	int64_t pairs = 0;
	int64_t m = (l + r)/2;
	if(l < r)
	{
		
		pairs = MergeSort(A,l,m);
		pairs += MergeSort(A,m+1,r);
		//pairs = pairs + Merge(A,l,m,r);
		//Merge(A,l,m,r);
		/*MergeSort(A,l,m);
		MergeSort(A,m+1,r);*/
		pairs += Merge(A,l,m,r);
		cout << " Liczba par=" << pairs << "\n";
	}
	return(pairs);
	
}