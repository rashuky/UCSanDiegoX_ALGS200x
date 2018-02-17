#include <iostream>

using std::cout;
using std::cin;

long gcd(long a, long b);
long lcd(long a, long b);

int main(void)
{
	long a, b;
	cin >> a;
	cin >> b;
	cout << lcd(a,b);	
	return 0;
}

long gcd(long a, long b)
{
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

long lcd(long a, long b)
{
	long d = gcd(a,b);
	return ((a/d)* b); 
}
