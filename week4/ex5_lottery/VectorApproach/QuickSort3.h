#ifndef INC
	#define INC
	#include <iostream>
	#include <vector>
	#include <stdint.h>
	#include <cstdlib>

	using std::vector;
	using std::swap;
	using std::cin;
	using std::cout;
#endif

void partition3(vector<int> &a, int l, int r, int *m);
void partition3(vector <vector <long> > &a, int l, int r, int *m);
void randomized_quick_sort(vector<int> &a, int l, int r);
void randomized_quick_sort(vector <vector <long> > &a, int l, int r);
void randomized_quick_sortSecond(vector <vector <long> >  &a, int l, int r);
void partition3Second(vector <vector <long> > &a, int l, int r, int);