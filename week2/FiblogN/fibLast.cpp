#include <iostream>
#include <stdint.h>
#include <cstdlib>
using std::cout;
using std::cin;

uint64_t fib(uint64_t n);

int main(void)
{
	uint64_t n;
	cin >> n;
	cout << fib(n);
	return 0;
}

uint64_t fib(uint64_t n)
{
	/*
	 * Init of Arrays:
	 * Q- Fibonacci	Array
	 * O- Output 	Array
	 * T- Temprary 	Array 
	 * Allways all of those arrays will have the same element a12 and a21 thus element 11 is a1 element 12 and 21 a2 and 22 a3
	 * Q is first fibonacci matrix	[1	1]
	 *				[1	0]
	 * O is diagonal matrix		[1	0]
	 *				[0	1]
	 */
	uint64_t q1 = 1, q2 = 1, q3 = 0;
	uint64_t o1 = 1, o2 = 0, o3 = 1;
	uint64_t t1 = 0, t2 = 0, t3 = 0;
	uint8_t overflow = 0;
	if(n < 2)
	{
	 	return n;
	}
	if(n == 0xFFFFFFFFFFFFFFFF)
	{
		overflow = 1;
		n = 0x1000000000000000;
		//cout << "Overflow appear \n";
	}else
		n = n + 1; // It turned out that sume of F(0)+F(1)+ ... + F(n) = F(n+2) - 1
	while(n || overflow)
	{
		if(n & 1)
		{
			// T = O x Q
			t1 = o1 * q1 + o2 * q2; 
			t2 = o1 * q2 + o2 * q3;
			t3 = o2 * q2 + o3 * q3;
			// O = T
			o1 = t1 % 10;
			o2 = t2 % 10;
			o3 = t3 % 10;	
			//cout << "\t" << "o:" << o1 << "\t" << o2 << "\t" << o3 << "\t" << "\n";
		}
		if(overflow)
		{
			overflow = 0;
		}else
			n >>= 1;		// Delete checked bit
		if(n)
		{
			// T = Q x Q
			t1 = q1 * q1 + q2 * q2;	
			t2 = q1 * q2 + q2 * q3;
			t3 = q2 * q2 + q3 * q3;
			// Q = T
			q1 = t1 % 10;
			q2 = t2 % 10;
			q3 = t3 % 10;

			//cout << "\t" << "q:" << q1 << "\t" << q2 << "\t" << q3 << "\t" << "\n";
		}		
	}
	int64_t ret = o1 - 1;
	//cout << ret << "\t" << o1 << "\n";
 	if (ret < 0)
     		return 9;
	return ret;
}
