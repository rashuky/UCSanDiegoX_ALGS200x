#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class adsData
{
	vector <long> clicks;
	vector <long> profit;
	long amount;
	long revenue;
	public:
		adsData(long size): clicks(size,0), profit(size,0)
		{
			fstream input;
			input.open("3_3_dot_product.in");
			input >> amount;
			cout << "ilosc danych to: " << amount << "\n";
			for(long i = 0; i < amount; i++)
			{
				input >> profit[i];
			}
			for(long i = 0; i < amount; i++)
			{
				input >> clicks[i];
			}
			input.close();
		}
		display()
		{
			for(long i = 0; i < amount; i++)
			{
				cout << profit[i] << "\t" << clicks[i] << "\n";
			}
		}
		maxRevenue()
		{
			long j = 0;
			long temp = 0;
			while(amount)
			{
				j = bestItem(clicks);
				cout << "Chosen click: " << clicks[j] << "\t";
				temp = clicks[j];
				clicks.erase(clicks.begin() + j);
				j = bestItem(profit);
				cout << "Chosen profit: " << profit[j] << "\t";
				revenue = revenue + temp * profit[j];
				cout << "tyle hajsu: " << revenue <<"\n";
				profit.erase(profit.begin() + j);
				amount -= 1;

			}
		}
	private:
		bestItem(vector<long> data)
		{
			long best = 0;
			long num = 0;
			for(long i = 0; i < amount; i++)
			{
				if(data[i] > best)
				{
					best = data[i];
					num = i;
				}
			}
			return num;
		}
};

int main()
{
	fstream input;
	input.open("3_3_dot_product.in");
	int n;
	input >> n;
	cout << "Ilość danych: " << n << "\n"; 
	input.close();
	adsData ads = adsData(n); 
	ads.display();
	ads.maxRevenue();
	return 0;
}
