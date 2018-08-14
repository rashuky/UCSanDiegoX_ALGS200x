#include "lotteryVector.h"

main()
{
	/*Ładowanie danych z pliku*/
	fstream input;
	input.open("4_5_lottery.txt");
	int64_t s = 0, p = 0;
	input >> s;
	input >> p;
	vector <vector <long> > seq(s, vector<long>(2, 0));
	vector <int64_t> points(p);
	for (int i = 0; i < s; i++)
	{
		input >> seq[i][0];
		input >> seq[i][1];
	}
	for (int i = 0; i < p; i++)
	{
		input >> points[i];
	}
	display(points, p);
	input.close();
	
	int64_t cnt = 0;
	for(int i = 0; i <points.size(); i++)
	{
		randomized_quick_sort(seq, 0, s-1);
		int64_t pos1 = binarySearchFirst(seq,0,s,points[i]);
		//cout << pos1 << "\t" << points[0] <<"\n";
		randomized_quick_sortSecond(seq, 0, pos1);
		//display(seq, pos1);
		int64_t pos = binarySearchSecond(seq,0,pos1,points[i]);
		//cout << pos << "\t" << points[0] <<"\n";
		pos = pos != -1 ? pos1 - pos : 0;
		//cout << pos << pos1;
		cnt += pos;
	}
	cout << cnt << "\n";
	return 0;
}

void dataCorrectness(vector <vector <long> > a, int n)
{
	for(int i = 0; i < n-1; i++)
	{
		if(a[i][0] > a[i][1] || a[i+1][0] < a[i][0])
		{
			cout << "\nERRORw miejscu: " << i <<" \n";
			break;
		}
	}
}

void display(vector <int64_t> points, int n)
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << points[i] << "\n ";
	}
	cout << "\n";
}

void display(vector <vector <long> > & seq, int64_t n)
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << seq[i][0]<< "\t" << seq[i][1] << "\t" << i << "\n";
	}
	cout << "\n";
}

int64_t binarySearchFirst(vector <vector <long> > & seq, int64_t left, int64_t right, int64_t point)
{
	int64_t pos = -1;
	while(left <= right)
	{
		if(left == right)
		{
			if(seq[left][0] <= point)
			{
				pos = left;
			}
			break;
		}
		int64_t mid = left + (right - left) / 2;
		if(seq[mid][0] <= point)
		{
			pos = mid;
			left = mid + 1;
		}else if( seq[mid][0] > point)
		{
			right = mid;
		}
	}
	return pos;
}

int64_t binarySearchSecond(vector <vector <long> > & seq, int64_t left, int64_t right, int64_t point)
{
	if(seq.empty()) return -1;
	if (left == right) {
            return seq[left][1] >= point ? left : -1;
        }
        int mid = left + (right - left) / 2;
        if (seq[mid][1] >= point) {
            return binarySearchSecond(seq, left, mid, point);
        } 
        else 
            return binarySearchSecond(seq, mid + 1, right, point);
}