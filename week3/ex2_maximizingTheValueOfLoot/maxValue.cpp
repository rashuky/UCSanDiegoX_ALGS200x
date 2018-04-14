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
	vector <int> values;
	public: 
		propertiesOfGoods(long size) : weigth(size,0), ratio(size,0), values(size,0)
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
					values[i] = value;
					i ++;
				}
			}
			input.close();
		}

		display()
		{
			for(int i = 0; i < n; i++)
			{
				cout << weigth[i] << "\t" << ratio[i] << "\t\t" << values[i] << "\n";
			}
		}
		
		long knapsack()		
		{
			float totalValue = 0;
			int i = 0;
			long waga = 0;
			while(W > 0)
			{
				i = bestItem();
				if(weigth[i] > W)
				{
					totalValue = totalValue + W * ratio[i];
					waga = W;
					W =0;
				}else 
				{
					totalValue = totalValue + weigth[i] * ratio[i];
					W -= weigth[i];
					waga = weigth[i];
				}
				printf("Właśnie dodaleś: %d, pozostało %d: ,kosztowało to %6.4f: ,masz teraz: %6.4f\n", waga, W, waga * ratio[i], totalValue);

				if(ratio.size() >= 2)
				{
					ratio.erase(ratio.begin() + i);
					weigth.erase(weigth.begin() + i);
				}else
				{
					ratio.clear();
					weigth.clear();
				}
				n = n -1;
			}
		}
		~propertiesOfGoods()
		{
		}
	//public:
		float bestItem()
		{
			float best = 0;
			int number = 0;
			//cout << "Przed wyszukaniem" << "\n";
			//display();
			for(int i = 0; i < n; i++)
			{
				if(ratio[i] > best)
				{
					//cout << " Znalazlem lepszy item!" << ratio[i] << ">" << best << "\n";
					number = i;
					best = ratio[i];
				}
			}
			//cout << "Po wyszukaniu, wyszuknay item"<< number << "\n";
						
			//display();
			
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
	cout << "Ilość danych: " << n << "\n"; 
	input.close();
	/**/

	propertiesOfGoods goods = propertiesOfGoods(n);
	goods.display();
	//while (goods.bestItem() != 0);
	goods.knapsack();
	return 0;
}
