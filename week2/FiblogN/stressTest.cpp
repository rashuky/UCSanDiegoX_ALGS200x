#include "stressTest.h"

int main(void)
{
	uint64_t n;
	uint64_t N;
	cout << "Podaj liczbe ktora bedzie najwyzsza liczba ciagu fibonacciego mozliwa do wylosowania \n";
	cin >> N;
	uint64_t fibLog = 0;
	uint64_t fibN = 0;
	uint64_t i = 0;
	do
	{
		n = rand() % N;
		fibN = fib(n); //	fibNaive(n);
		fibLog = fib(n);
		i++ ;
		if((i%1000) == 0)
		{
			cout << i << "\n";
		}
	}while(fibLog == fibN);
	cout << "Algorytm polegl. Naiwny: " << fibN << " Szybki: " << fibLog << " proba numer: " << i << " wylosowany fibonacci " << n << "\n";
	return 0;
}
	
