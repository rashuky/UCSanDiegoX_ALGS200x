#include <iostream>

using std::cin;
using std::cout;
using std::max;

long Fib(long n, long m);
long FibMatrix(long n, long long * A, long m);

int main(void)
{
	long n, m;
	cin >> n >> m; 
	long a =Fib(n, m); 
	cout <<  a << " "<< a % m ;
	return 0;
}

long Fib(long n, long m)
{
	long long A[3] = {0, 1, 1};
	if(n < 2)
	{
		return A[n];
	}else
	{
		return (FibMatrix(n, A, m));
	}
}

long FibMatrix(long n, long long * A, long m)
{
	if((n-2) == 0)
	{
		return (A[2]);
	}else
	{
		A[0] = A[1]; 
		A[1] = A[2];
		A[2] = A[0]+A[1];
		FibMatrix(n-1, A, m);		
	}
}
