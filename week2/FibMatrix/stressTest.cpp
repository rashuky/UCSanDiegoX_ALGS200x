#include "stressTest.h"

int main(void)
{
	long N = 0, M = 0;
	cout << "Podaj max liczbe ciagu fibonacciego jaka chcesz uzyskac\n";
	cin >> N >> M;
	cout << "Vektor bedzie miał: " << N << "\n";
	//for(int i = 0; i < 1000; i++)
	int cont = 0;
	long fib1 = 0;
	long fib2 = 0;
	long i =0;
	static long n = 0;
	static long m = 0;
	do{
		
		n = rand() % N;
		m = rand() % M + 1;
		fib1 = fibNaive(n, m);
		fib2 = Fib(n, m);
		cont = (fib1 == fib2);
		i++ ;
		if((i%1000) == 0)
		{
			cout << i << "\n";
		}
	}while(cont);
	cout << "Algorytm polegl. Naiwny: " << fib1 << " Szybki: " << fib2 << " proba numer: " << i << " wylosowany fibonacci " << n << "wylosowany dzielnik: " << m <<"\n";
	return 0;
}
