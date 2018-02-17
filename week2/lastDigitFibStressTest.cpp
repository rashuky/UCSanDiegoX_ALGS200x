#include <iostream>
#include <stdint.h>
#include <cstdlib>

using std::cout;
using std::cin;

int32_t fib(int32_t n);
int32_t fibN(int32_t n);

int main(void)
{
	int32_t n;
	int32_t N = 0;
	cout << "Podaj max liczbe ciagu fibonacciego jaka chcesz uzyskac\n";
	cin >> N;
	cout << "Vektor bedzie miał: " << N << "\n";
	//for(int i = 0; i < 1000; i++)
	int cont = 0;
	int32_t fib1 = 0;
	int32_t fib2 = 0;
	int32_t i =0;
	do{
		
		n = rand() % N;
		fib1 = fibN(n);
		fib2 = fib(n);
		cont = (fib1 == fib2);
		i++ ;
		if((i%1000) == 0)
		{
			cout << i << "\n";
		}
	}while(cont);
	cout << "Algorytm polegl. Naiwny: " << fib1 << " Szybki: " << fib2 << " proba numer: " << i << " wylosowany fibonacci " << n <<"\n";
	
	return 0;
}

int32_t fib(int32_t n)
{
	int32_t fibA[n + 2];
	fibA[0] = 0;
	fibA[1] = 1;
	fibA[2] = 1;
	for(int32_t i = 3; i <= n + 2; i++)
	{
		fibA[i]=(fibA[i-1]+fibA[i-2]) % 10;
	}
	return (fibA[n+2]-1) < 0 ? 9 : fibA[n+2]-1;
}

int32_t fibN(int32_t n)
{
	int32_t fibA[n + 1];
	fibA[0] = 0;
	fibA[1] = 1;
	fibA[2] = 1;
	if(n < 2)
		return fibA[n];
	int32_t sum = 2;
	for(int32_t i = 3; i <= n; i++)
	{
		fibA[i]=(fibA[i-1]+fibA[i-2]);
		sum= sum + fibA[i];
	}
	return sum % 10;
}
