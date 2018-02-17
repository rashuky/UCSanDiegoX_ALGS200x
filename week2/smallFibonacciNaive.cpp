#include <iostream>
using std::cout;
using std::cin;

long smallFibonacci(int n);

int main(void)
{
	int n;
	cout << "Podja liczbe: \n";
	cin >> n; 	
	cout << smallFibonacci(n);
	return 0;
}

long smallFibonacci(int n)
{	
	long Fib = 0;
	if (n <=1)
		return n; 
	return (smallFibonacci(n-1) + smallFibonacci(n-2));
}
