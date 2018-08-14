#include "stressTest.h"

void display(vector<int> a, int n)
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

int main() {
	uint64_t N;
	cout << "Podaj liczbe ktora bedzie najwyzsza liczba mozliwa do wylosowania \n";
	cin >> N;
  	int n;
	cout << "Podaj długość zbioru \n";
  	std::cin >> n;
  	vector<int> a(n);
	int64_t b[n];
	while(1)
	{
		for (size_t i = 0; i < a.size(); ++i) 
		{
				//std::cin >> a[i];
				a[i] = rand() % N;
				b[i] = a[i];
		}
		display(a,n);
		
		randomized_quick_sort(a, 0, a.size() - 1);
		MergeSort(b,0, n-1);
		for (size_t i = 0; i < a.size(); ++i) 
		{
			std::cout << a[i] << ' ';
		}
		std::cout << "\n";
		for (size_t i = 0; i < a.size(); ++i) 
		{
			std::cout << b[i] << ' ';
		}
		cout << "\n";
		for(size_t i = 0; i < a.size(); ++i)
		{
			if(b[i] != a[i])
			{
				break;
			}
		}
	}
}