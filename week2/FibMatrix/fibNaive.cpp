#include "fibNaive.h"

long fibNaive(long n, long m)
{	
	long array[n + 1];
	array[0] = 0;
	array[1] = 1;
	{
		for (long i = 2; i <= n; i++)
		{
			array[i]= array[i - 2] + array[i - 1];
		}
	}
	return (array[n] % m);
}
