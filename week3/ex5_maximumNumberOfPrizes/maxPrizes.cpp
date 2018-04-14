#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

vector <long> maxPrize(long n);
void display(vector <long> prizes);

int main()
{
	long n = 0;
	cout << "Podaj liczbe cukierkow\n";
	cin >> n;
	vector <long> prizes = maxPrize(n);
	display(prizes);
	return 0;
}

vector <long> maxPrize(long n)
{
	vector <long> prizes;
	unsigned long i = 0;
	unsigned long candies = 0;
	while(n)
	{
		candies = i + 1;
		if((n - candies) < (i+1))
		{
			prizes.push_back(n);
			n = 0;
		}else 
		{
			prizes.push_back(candies);
			n = n - candies;
		}
		cout << prizes[i] << "\n";
		i ++;
	}
	return prizes;
}

void display(vector <long> prizes)
{
	cout <<"\n";
	for(long i = 0; i < prizes.size(); i++)
	{
		cout << prizes[i] << "\n";
	}
	cout << "Nagrodzimy: " << prizes.size() << " dzieci\n";
}
