#include "fibMatrix.h"

long Fib(long n, long m)
{
	long A[3] = {0, 1, 1};
	if(n < 2)
	{
		return (A[n] % m);
	}else
	{
		return (FibMatrix(n, A, m));
	}
}

long FibMatrix(long n, long * A, long m)
{
	if((n-2) == 0)
	{
		return (A[2] % m);
	}else
	{
		A[0] = A[1]; 
		A[1] = A[2];
		A[2] = A[0]+A[1];
		FibMatrix(n-1, A, m);		
	}
}


