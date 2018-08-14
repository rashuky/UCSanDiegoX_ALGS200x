#include "QuickSort3.h"

void display1(vector<int> a, int n)
{
	
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
  //cout << "Zaczynamy partition " << l << " " << *m << " " << *(m+1) <<"\n";
  for (int i = l + 1; i <= r; i++) 
  {
	
    if (a[i] < x) 
	{
		(*m)++;
		(*(m+1))++;
		//display1(a,r-l+1);
		//cout<< "Mniejszy, pierwszy swap el. i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
		swap(a[i], a[*(m)]); 
		//display1(a,r-l+1);
		if(*(m) != *(m+1))
		{
			//cout<< "Mniejszy, drugi swap el. i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
			swap(a[*(m+1)],a[i]);
			//display1(a,r-l+1);
			//cout << "\n";
		}
	  
    }else if(a[i] == x)
	{
		(*(m+1))++;
		//display1(a,r-l+1);
		//cout << "Takie same i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
		swap(a[i], a[*(m+1)]);
		//display1(a,r-l+1);
		//cout << "\n";
	}else
	{
		//display1(a,r-l+1);
		//cout <<"Wieksze i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
		//display1(a,r-l+1);
		//cout << "\n";
	}
  }
  //display1(a,r-l+1);
  //cout << "Koniec \n";
  swap(a[l], a[*m]);
  //display1(a,r-l+1);
  //cout << "\n";
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //cout << "Random el. " << k << " "<< a[k] << "\n";
  swap(a[l], a[k]);
  int m[2];
  partition3(a, l, r, m);
  //cout << "After partition "<< m[0] << " " << m[1] << "\n";
  //display1(a,r-l+1);
  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}
