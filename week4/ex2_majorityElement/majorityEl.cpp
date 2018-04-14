#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::fstream;

long bstAlgo(long * data, long n);		//bst binary search tree
long naiveAlgo(long * data, long n);
long divideConquer(long * data, long start, long end);
long boolAlgo(long * data, long n);
int main()
{
	fstream input;
	input.open("4_2_majority_element.in");
	long n;
	input >> n;	
	long data[n];
	for(long i = 0; i < n; i++)
	{
		input >> data[i];
	}
	long num = naiveAlgo(data, n);
	cout << num<< "\n";
	cout << data[num] << "\n";
	
	/*num = divideConquer(data,0, n-1);
	cout << num<< "\n";*/

	num = boolAlgo(data,n);
	cout << num<< "\n";

	return 0;
}

long boolAlgo(long * data, long n)
{
	long count = 0; 	
	long majEl = 0;		
	for(long i = 0; i < n; i++)
	{
		if(count == 0)
		{
			majEl = data[i];
		}
		if(majEl == data[i])
		{
			count ++;
		}else
		{
			count --;
		}
	}
	count = 0;
	for(long i = 0; i < n; i++)
	{
		if(majEl = data[i])
		{
			count ++;
		}
		if(count > n/2)
		{
			return majEl;
		}
	}
	return(-1);
}
long naiveAlgo(long * data, long n)
{
	for(long i = 0; i < n; i++)
	{
		long count = 0;
		long val = data[i];		
		for(long j = 0; j < n; j++)
		{
			if(data[i] == data[j])
			{
				count ++;
			}
			if(count > n/2)
			{
				return(i);
			}
		}
	}
	return(-1);
}

long bstAlgo(long * data, long n)
{
	for(long i = 0; i < n; i++)
	{
		long val = data[i];
		
	}
}

long divideConquer(long * data, long start, long end)
{
	long count = 0;	
	long el1;
	long el2;
	if(end >= start)
	{
		cout << "\nPodzielon " << start << "-" << end << "\n";
		if((end - start) == 2)
		{
			cout << "\nRozbrojono macierz " << start << "-" << end << "\n";
			if(data[start] == data[end])
			{
				return(data[start]);
			}		
			else
			{
				return(-1);
			}
		}else if((end - start) == 1)
		{
			cout << "\nRozbrojono macierz " << start << "-" << end << "\n";
			return(data[start]);
		}
	}else
	{
		return (data[start]);
	}
	el1 = divideConquer(data,start, (start + end - 1)/2);
	cout << "\n el1 done " << el1 << "\n" ;
	el2 = divideConquer(data, (start + end - 1)/2, end);
	cout << "\n el1 done " << el1 << "\n" ;
	cout << "\n po recursive callu\n";
	if(el1 == -1 && el2 >= 0)
	{
		cout << "\n element 2 majority " << el2 << "\n";
		return el2;
	}
	else if(el2 == -1 && el1 >= 0)
	{
		cout << "\n element 1 majority " << el1 << "\n";
		return el1;
	}
	if(el1 == el2)
	{		
		cout << "\n rowne " << el1 << "\n";
		return el1;
	}	
	else
	{	
		return(-1);
	}
}
