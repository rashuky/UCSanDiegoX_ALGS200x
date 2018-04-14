#include <iostream>
#include <vector>
#include <stdint.h>
#include <cstdlib>

using std::vector;
using std::swap;
using std::cin;
using std::cout;

void display(vector<int> a, int n)
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

void partition3(vector<int> &a, int l, int r, int *m) {
  int x = a[l];
  *m = l;
  *(m+1) = l;
  cout << "Zaczynamy partition " << l << " " << *m << " " << *(m+1) <<"\n";
  for (int i = l + 1; i <= r; i++) 
  {
    if (a[i] < x) 
	{
		(*m)++;
		(*(m+1))++;
		cout<< "Mniejszy, pierwszy swap el. " << i << "=" << a[i] << ", " << *m << "=" << a[*m] << "\n" ;
		display(a,r-l+1);
		swap(a[i], a[*(m)]); 
		if(*(m) != *(m+1))
		{
			swap(a[*(m+1)],a[i]);
			cout<< "Mniejszy, drugi swap el. " << i << "=" << a[i] << ", " << *(m+1) << "=" << a[*(m+1)] << "\n" ;
			display(a,r-l+1);
		}
	  
    }else if(a[i] = x)
	{
		(*(m+1))++;
		cout << "Takie same " << i << "=" << a[i] << "," << *(m+1) << "=" <<a[*(m+1)] <<"\n";
		swap(a[i], a[*(m+1)]);
		
	}else
	{
	}
  }
  swap(a[l], a[*m]);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  cout << "Random el. " << k << " "<< a[k] << "\n";
  swap(a[l], a[k]);
  int m[2];
  partition3(a, l, r, m);
  cout << "After partition "<< m[0] << " " << m[1] << "\n";
  display(a,r-l+1);
  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
	uint64_t N;
	cout << "Podaj liczbe ktora bedzie najwyzsza liczba mozliwa do wylosowania \n";
	cin >> N;
  	int n;
	cout << "Podaj długość zbioru \n";
  	std::cin >> n;
  	vector<int> a(n);
  	for (size_t i = 0; i < a.size(); ++i) 
	{
    		//std::cin >> a[i];
			a[i] = rand() % N;
  	}
	display(a,n);
	
  	randomized_quick_sort(a, 0, a.size() - 1);
  	for (size_t i = 0; i < a.size(); ++i) 
	{
  		std::cout << a[i] << ' ';
  	}
}
