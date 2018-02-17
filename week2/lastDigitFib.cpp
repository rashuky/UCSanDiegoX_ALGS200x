#include <iostream>
#include <stdint.h>
#include <cstdlib>

using std::cout;
using std::cin;

int32_t fib(int64_t n);

int main(void)
{
	int32_t n;
	cin >> n;
	cout << fib(n);
	return 0;
}

int32_t fib(int64_t n)
{
	int32_t fibA[n + 2];
	fibA[0] = 0;
	fibA[1] = 1;
	fibA[2] = 1;
	for(int64_t i = 3; i <= n + 2; i++)
	{
		fibA[i]=(fibA[i-1]+fibA[i-2]) % 10;
	}
	return (fibA[n+2]-1) < 0 ? 9 : fibA[n+2]-1;
}

