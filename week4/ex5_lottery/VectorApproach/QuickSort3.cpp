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
void partition3Second(vector <vector <long> > &a, int l, int r, int *m) {
  int x = a[l][1];
  *m = l;
  *(m+1) = l;
  //cout << "Zaczynamy partition " << l << " " << *m << " " << *(m+1) <<"\n";
  for (int i = l + 1; i <= r; i++) 
  {
	
    if (a[i][1] < x) 
	{
		(*m)++;
		(*(m+1))++;
		//display1(a,r-l+1);
		//cout<< "Mniejszy, pierwszy swap el. i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
		swap(a[i][0], a[*(m)][0]); 
		swap(a[i][1], a[*(m)][1]); 
		//display1(a,r-l+1);
		if(*(m) != *(m+1))
		{
			//cout<< "Mniejszy, drugi swap el. i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
			swap(a[*(m+1)][0],a[i][0]);
			swap(a[*(m+1)][1],a[i][1]);
			//display1(a,r-l+1);
			//cout << "\n";
		}
	  
    }else if(a[i][1] == x)
	{
		(*(m+1))++;
		//display1(a,r-l+1);
		//cout << "Takie same i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
		swap(a[i][0], a[*(m+1)][0]);
		swap(a[i][1], a[*(m+1)][1]);
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
  swap(a[l][0], a[*m][0]);
  swap(a[l][1], a[*m][1]);
  //display1(a,r-l+1);
  //cout << "\n";
}

void partition3(vector <vector <long> > &a, int l, int r, int *m) {
  int x = a[l][0];
  *m = l;
  *(m+1) = l;
  //cout << "Zaczynamy partition " << l << " " << *m << " " << *(m+1) <<"\n";
  for (int i = l + 1; i <= r; i++) 
  {
	
    if (a[i][0] < x) 
	{
		(*m)++;
		(*(m+1))++;
		//display1(a,r-l+1);
		//cout<< "Mniejszy, pierwszy swap el. i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
		swap(a[i][0], a[*(m)][0]); 
		swap(a[i][1], a[*(m)][1]); 
		//display1(a,r-l+1);
		if(*(m) != *(m+1))
		{
			//cout<< "Mniejszy, drugi swap el. i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
			swap(a[*(m+1)][0],a[i][0]);
			swap(a[*(m+1)][1],a[i][1]);
			//display1(a,r-l+1);
			//cout << "\n";
		}
	  
    }else if(a[i][0] == x)
	{
		(*(m+1))++;
		//display1(a,r-l+1);
		//cout << "Takie same i=" << i << " a[i]=" << a[i] << ", m1=" << *m << " a[m1]=" << a[*m] << " m2=" << *(m+1) << " a[m2]=" << a[*(m+1)] << "\n" ;
		swap(a[i][0], a[*(m+1)][0]);
		swap(a[i][1], a[*(m+1)][1]);
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
  swap(a[l][0], a[*m][0]);
  swap(a[l][1], a[*m][1]);
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

void randomized_quick_sort(vector <vector <long> >  &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //cout << "Random el. " << k << " "<< a[k] << "\n";
  swap(a[l][0], a[k][0]);
  swap(a[l][1], a[k][1]);
  int m[2];
  partition3(a, l, r, m);
  //cout << "After partition "<< m[0] << " " << m[1] << "\n";
  //display1(a,r-l+1);
  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}


void randomized_quick_sortSecond(vector <vector <long> >  &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //cout << "Random el. " << k << " "<< a[k] << "\n";
  swap(a[l][0], a[k][0]);
  swap(a[l][1], a[k][1]);
  int m[2];
  partition3Second(a, l, r, m);
  //cout << "After partition "<< m[0] << " " << m[1] << "\n";
  //display1(a,r-l+1);
  randomized_quick_sortSecond(a, l, m[0] - 1);
  randomized_quick_sortSecond(a, m[1] + 1, r);
}