#include "MergeSort.h"

void Merge(int64_t A[], int64_t l, int64_t m, int64_t r)
{
	int64_t nb = m-l+1;
	int64_t nc = r-m;
	int64_t B[nb];
	int64_t C[nc];
	
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
}

void MergeSort(int64_t A[], int64_t l, int64_t r)
{
	if(l < r)
	{
		int64_t m = (l + r)/2;
		MergeSort(A,l,m);
		MergeSort(A,m+1,r);
		Merge(A,l,m,r);
	}
}