#include "stressTest.h"

int main(int argc, char * argv[])
{
	int N = 0, M = 0;
	cout << "Podaj dlugosc vektora do testów i max wartosc liczby w wektorze \n";
	cin >> N >> M;
	cout << "Vektor bedzie miał: " << N << " elementow. Najwiekszy z nich bedzie: " << M << "\n";
	//for(int i = 0; i < 1000; i++)
	int cont = 0;
	long productN = 0;
	long productF = 0;
	long i =0;
	do{
		static long n = N + N % M, m = M - N % M;
		n = rand() % N;
		vector <long> v(n);
		for(int j = 0; j < n; j++)
		{
			v[j] = rand() % M;
		}
		productN = maxPairN(v);
		productF = maxPairF(v);
		cont = (productN == productF);
		i++ ;
		if((i%1000) == 0)
		{
			cout << i << "\n";
		}
	}while(cont);
	cout << "Algorytm polegl. Naiwny: " << productN << " Szybki: " << productF << "proba numer: " << i << "\n";
	return 0;
}
