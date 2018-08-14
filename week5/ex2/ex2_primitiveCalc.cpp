#include <iostream>
#include <stdint.h>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::vector;

int64_t primCalc(int64_t num);

main()
{
	int64_t num = 98734;
	cout << "\n" << primCalc(num);
	return 0;
}

int64_t primCalc(int64_t num)
{
	vector <int64_t> MinNumCoins(num);
	MinNumCoins[0] = 0;
	//cout << MinNumCoins[0];
	for(int64_t m = 1; m <= num; m++)
	{
		//cout << "\n#" << m << "#";
		MinNumCoins[m] = LONG_MAX;
		for(int64_t i = 0; i < 3; i++)
		{
			int64_t numOp;
			//cout << "\t||" << i << " \t";
			switch(i)
			{
				case 0:
					numOp = (MinNumCoins[m - 1]) + 1;
					/*cout << m - 1;
					cout << " N: " << numOp;*/
				break;
				case 1:
					if(!(m%2))
					{
						numOp = (MinNumCoins[m/2]) + 1;
						/*cout << m << " " << m%2;
						cout << " N: " << numOp;*/
					}
				break;
				case 2:
					if(!(m%3))
					{
						numOp = (MinNumCoins[m/3]) + 1;
						/*cout << m << " " << m%3;
						cout << " N: " << numOp;*/
					} 
				break;
				default:
					
				break;
			}
			if (numOp < MinNumCoins[m])
			{
				MinNumCoins[m] = numOp;
			}	
		}
	}
	return MinNumCoins[num]-1;
}