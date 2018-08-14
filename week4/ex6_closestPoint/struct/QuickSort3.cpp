#include "closest.h"
#include "QuickSort3.h"

void partition3(struct Point a[], int l, int r, int *m) {
  int64_t x = a[l].x;
  *m = l;
  *(m+1) = l;
  //cout << "Zaczynamy partition " << l << " " << *m << " " << *(m+1) <<"\n";
  for (int i = l + 1; i <= r; i++) 
  {
    if (a[i].x < x) 
	{
		(*m)++;
		(*(m+1))++;
		swap(a[i].x, a[*(m)].x); 
		swap(a[i].y, a[*(m)].y);
		if(*(m) != *(m+1))
		{
			swap(a[*(m+1)].x,a[i].x);
			swap(a[*(m+1)].y,a[i].y);
		}
	  
    }else if(a[i].x == x)
	{
		(*(m+1))++;
		swap(a[i].x, a[*(m+1)].x);
		swap(a[i].y, a[*(m+1)].y);
	}else
	{
	}
  }
  swap(a[l].x, a[*m].x);
  swap(a[l].y, a[*m].y);
}
// Polimorph. function 1D array
void partition3(int64_t a[], int l, int r, int *m) {
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

void randomized_quick_sort(struct Point a[], int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //cout << "Random el. " << k << " "<< a[k] << "\n";
  swap(a[l].x, a[k].x);
  swap(a[l].y, a[k].y);
  int m[2];
  partition3(a, l, r, m);
  //cout << "After partition "<< m[0] << " " << m[1] << "\n";
  //display1(a,r-l+1);
  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}
// Polimorph. function 1D array
void randomized_quick_sort(int64_t a[], int l, int r) {
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

void randomized_quick_sort_SecondRow(struct Point a[], int l, int r)
{
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //cout << "Random el. " << k << " "<< a[k] << "\n";
  swap(a[l].x, a[k].x);
  swap(a[l].y, a[k].y);
  int m[2];
  partition3_SecondRow(a, l, r, m);
  //cout << "After partition "<< m[0] << " " << m[1] << "\n";
  //display1(a,r-l+1);
  randomized_quick_sort_SecondRow(a, l, m[0] - 1);
  randomized_quick_sort_SecondRow(a, m[1] + 1, r);
}

void partition3_SecondRow(struct Point a[], int l, int r, int *m) 
{
  int64_t x = a[l].y;
  *m = l;
  *(m+1) = l;
  //cout << "Zaczynamy partition " << l << " " << *m << " " << *(m+1) <<"\n";
  for (int i = l + 1; i <= r; i++) 
  {
    if (a[i].y < x) 
	{
		(*m)++;
		(*(m+1))++;
		swap(a[i].x, a[*(m)].x); 
		swap(a[i].y, a[*(m)].y);
		if(*(m) != *(m+1))
		{
			swap(a[*(m+1)].x,a[i].x);
			swap(a[*(m+1)].y,a[i].y);
		}
	  
    }else if(a[i].y == x)
	{
		(*(m+1))++;
		swap(a[i].x, a[*(m+1)].x);
		swap(a[i].y, a[*(m+1)].y);
	}else
	{
	}
  }
  swap(a[l].x, a[*m].x);
  swap(a[l].y, a[*m].y);
}