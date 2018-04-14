#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::fstream;

void display(long * dane, long n);
long binarySearch(long * dane, long low, long high, long k, long * steps, long * occured);
long iterativeBinarySearch(long * dane, long low, long high, long k, long * steps, long * occured);

int main()
{
	fstream input;
	input.open("4_1_binary_search.in");
	long n;
	input >> n;	
	long sortedData[n];
	for(long i = 0; i < n; i++)
	{
		input >> sortedData[i];
	}

	long k;
	input >> k;
	long searchData[k];
	for(long i = 0; i < k; i++)
	{
		input >> searchData[i];
	}

	input.close();
	//display(sortedData, n);
	long steps = 0;
	long occured = 0;
	long i;
	for( i = 0; i < k; i ++)
	{
		iterativeBinarySearch(sortedData, 0, n - 1, searchData[i], &steps, &occured); 
	}	
	cout  << "Items: " << i << " steps: " << steps << " Occured: " << occured << "\n";
	steps = 0;
	occured = 0;
	for( i = 0; i < k; i ++)
	{
		binarySearch(sortedData, 0, n, searchData[i], &steps, &occured);
	}	
	cout  << "Items: " << i << " steps: " << steps << " Occured: " << occured << "\n";

	return 0;
}

void display(long * dane, long n)
{
	for(int i = 0; i < n; i++)
	{
		cout << dane[i] <<"\n";
	}
}

long iterativeBinarySearch(long * dane, long low, long high, long k, long * steps, long * occured)
{
	while(low <= high)
	{
		(*steps)++;
		int mid = low + (high-low) / 2;
		if(k == dane[mid])
		{
			(*occured)++;
			return mid;
		}
		else if(k < dane[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}
long binarySearch(long * dane, long low, long high, long k, long * steps, long * occured)
{	
	(*steps)++;
	long mid = 0;
	if(high < low)
	{
		return -1;
	}else if(high == low)
	{
		if(k == dane[high])
		{
			(*occured)++;
			return mid;
		}else 
		{
			return -1;
		}
	}	
	mid = low + (high - low)/2;
	if(k == dane[mid])
	{
		(*occured)++;
		return mid;
	}else if(k < dane[mid])
	{
		return binarySearch(dane, low, mid - 1, k, steps, occured);
	}else
	{
		return binarySearch(dane, mid + 1, high, k, steps, occured);
	}
}
