#include <iostream>

using std::cout;
using std::cin;

long gcdN(long a, long b);

int main(void)
{	
	long a, b;
	cin >> a;
	cin >> b;
	cout << gcdN(a , b);
	return 0;
}

long gcdN(long a, long b)
{
	cout << a << "\t" << b << "\n";
	for(long i = (a+b); i > 1; i--)
	{
		if((a%i == 0) && (b%i == 0))
		{
			return i;
		}
	}
	return 0;
}

