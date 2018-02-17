#include "stressTestModulo.h"

int main(void)
{
	uint64_t n, m;
	uint64_t N;
	uint64_t M;
	cout << "Podaj liczbe ktora bedzie najwyzsza liczba ciagu fibonacciego mozliwa do wylosowania \n";
	cin >> N >> M;
	uint64_t fibLog = 0;
	uint64_t fibN = 0;
	uint64_t i = 0;
	do
	{
		n = rand() % N;
		m = rand() % M +1;
		fibN = fibNaive(n,m); //	fibNaive(n);
		fibLog = fib(n,m);
		i++ ;
		if((i%1000) == 0)
		{
			cout << i << "\n";
		}
	}while(fibLog == fibN);
	cout << "Algorytm polegl. Naiwny: " << fibN << " Szybki: " << fibLog << " proba numer: " << i << " wylosowany fibonacci " << n << "\n";
	return 0;
}
	
