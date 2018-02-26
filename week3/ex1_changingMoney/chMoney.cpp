#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

vector<long> & chMoney(long n, vector<long> & v);

int main()
{
	long n;
	cin >> n;
	vector <long> vec(3);
	chMoney(n , vec);
	cout <<	 vec[0] + vec[1]+ vec[2];
	return 0;
}

vector<long> & chMoney(long n, vector<long> & v)
{
	int a[3] = {10, 5, 1};
	int i = 0;	
	while(n)
	{
		v[i] = n / a[i];
		n = n % a[i];
		i ++ ;
	}
	return v;
}
