#include <iostream>
using std::cout;
using std::cin;

long Fibonacci(int n);

int main(void)
{
	int n;
	cout << "Podja liczbe: \n";
	cin >> n; 	
	cout << Fibonacci(n);
	return 0;
}

long Fibonacci(int n)
{	
	int array[n + 1];
	array[0] = 0;
	array[1] = 1;
	{
		for (int i = 2; i <= n; i++)
		{
			array[i]= (array[i - 2] + array[i - 1]) % 10;
		}
	}
	return array[n];
}
