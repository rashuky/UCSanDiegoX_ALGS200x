#include "VecmaxPairWiseNaive.h"

/*int main()
{
	int n;
	cin >> n;
	vector<long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	long product = maxPair(v);
	cout << product << "\n";
	return 0;
}*/

long maxPairN(const vector<long>& vect)
{	
	long product = 0;
	int n = vect.size();
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(vect[i] != vect[j]) 
			{
				product = max(product, vect[i] * vect[j]);
			}
		}
	}
	return product;
}
