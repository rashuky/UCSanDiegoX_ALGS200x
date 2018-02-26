#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//#include <cstdlib>

using namespace std;

class propertiesOfGoods
{
	long W;
	long n;
	vector <long> weigth;
	vector <float> ratio;	
	public: 
		propertiesOfGoods(long size) : weigth(size,0), ratio(size,0)
		{
			fstream input;
			input.open("3_2_loot.in");
			int w;
			int value;
			input >> n;
			input >> W;
			if(input.is_open())
			{
				long i = 0;
				while (!input.eof())
				{
					input >> value;
					input >> w;
					weigth[i] = w;
					ratio[i] = (float)value/(float)w;
					i ++;
				}
			}
			input.close();
		}

		display()
		{
			for(int i = 0; i < n; i++)
			{
				cout << weigth[i] << "\t" << ratio[i] << "\n";
			}
		}
		
		long knapsack()		
		{
			long totalValue = 0;
			int i = 0;
			while(W > 0)
			{
				i = bestItem();
				if(weigth[i] > W)
				{
					totalValue = W * ratio[i];
					W =0;
				}else 
				{
					totalValue = weigth[i] * ratio[i];
					W -= weigth[i];
				}
				cout << "Właśnie dodaleś: " <<  weigth[i] << " pozostało: " << W << " kosztowało to " << weigth[i] * ratio[i] << " masz teraz " << totalValue;
				//ratio.erase(ratio.begin()+ i);
				//weigth.erase(weigth.begin()+ i);
			}
		}
		~propertiesOfGoods()
		{
		}
	private:
		float bestItem()
		{
			float best = 0;
			int number = 0;
			for(int i = 0; i < n; i++)
			{
				if(ratio[i] > best)
				{
					number = i;
				}
			}
			return number;
		}
};

int main(void)
{
	/*Read amound of data*/
	fstream input;
	input.open("3_2_loot.in");
	int n;
	input >> n;
	input.close();
	/**/

	propertiesOfGoods goods = propertiesOfGoods(n);
	goods.knapsack();
	return 0;
}

