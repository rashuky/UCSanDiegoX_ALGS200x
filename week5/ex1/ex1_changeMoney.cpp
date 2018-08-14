#include <iostream>
#include <stdint.h>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::vector;

int64_t changeAlgo(int64_t money, vector<int64_t> &denom);

main()
{
	int64_t num = 950;
	vector <int64_t> denom(3);
	denom[0] = 1;
	denom[1] = 3;
	denom[2] = 4;
	cout << changeAlgo(num, denom);
	return 0;
}

int64_t changeAlgo(int64_t money, vector<int64_t> &denom)
{
	vector <int64_t> MinNumCoins(money);
	MinNumCoins[0] = 0;
	//cout << MinNumCoins[0];
	for(int64_t m = 1; m <= money; m++)
	{
		//cout << m << "\n";
		MinNumCoins[m] = LONG_MAX;
		for(int64_t i = 0; i < denom.size(); i++)
		{
			//cout << "||" << denom[i] << " \t";
			if (m >= denom[i])
			{
					int64_t numCoins = (MinNumCoins[m - denom[i]]) + 1;
					//cout << "index " << m - denom[i] << " " << numCoins << "\t" ;
					if (numCoins < MinNumCoins[m])
					{
						MinNumCoins[m] = numCoins;
					}
			}
		}
	}
	return MinNumCoins[money];
}