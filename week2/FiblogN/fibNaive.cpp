#include "fibNaive.h"

uint64_t fibNaive(uint64_t n)
{	
	uint64_t array[n + 1];
	array[0] = 0;
	array[1] = 1;
	{
		for (uint64_t i = 2; i <= n; i++)
		{
			array[i]= array[i - 2] + array[i - 1];
		}
	}
	return (array[n]);
}
