#include <iostream>

using std::cout;
using std::cin;

long gcdF(long a, long b);

int main(void)
{	
	long a, b;
	cin >> a;
	cin >> b;
	cout << gcdF(a , b);
	return 0;
}

long gcdF(long a, long b)
{
	if(b == 0)
		return a;
	return gcdF(b, a%b);
}

