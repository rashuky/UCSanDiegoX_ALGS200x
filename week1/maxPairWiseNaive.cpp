#include <iostream>
using namespace std;

int maxPairWise(int * a, int length);


int main()
{
	int n;
	int * a;
	cout << "hello podaj dlugosc tablicy \n";
	cin >> n;
	a = new int [n+1];
	for(int i = 0; i < n+1; i++)
	{
		a[i] = i;
	}
	cout << "Największa liczba to " << maxPairWise(a,n);
	delete a;	
	return 0;
}

int maxPairWise(int * a, int length)
{
	int result;
	for(int i = 0; i <= length; i++)
	{
		for(int j = 0; j <length; j++)
		{
			if(result < a[i] * a[j])
			{
				result= a[i] * a[j];
			}
		}
	}
	return result;
}
