#include "VecmaxPairWiseFast.h"

/*int main(void)
{
	int n;
	cin >> n;
	vector<long> numbers(n);
	for(int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	cout << maxPair(numbers);
	return 0;
}*/

long maxPairF(const vector<long> & v)
{	
	long max = 0, max1 = 0;

	for(int i = 0; i < v.size(); i++)
	{
		if(max < v[i])
		{
			max1 = max;
			max = v[i];
			
		}else if(max1 < v[i] && v[i] != max)
		{
			max1 = v[i];`
		}
	}
	if (max1 == max)
		return 0;
	return max1*max;
}
