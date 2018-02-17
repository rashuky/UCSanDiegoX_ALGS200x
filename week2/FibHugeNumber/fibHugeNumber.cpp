#include <iostream>
#include <vector>
#include <stdint.h>
using std::cin;
using std::cout;
using std::vector;

vector <int32_t> * pisanoPeriod(int32_t m);
int32_t fibHuge(int64_t n, int32_t m);

int main(void)
{
	int64_t N = 0, M = 0;
	cin >> N >> M;
	cout << fibHuge(N, M);
	return 0;
}

vector <int32_t>* pisanoPeriod(int32_t m)
{
	// Pisano period always starts from 01. There is no place in the period where sequence of this numbers appear
	// Because the first elements of Fibonacci sequence is 0, 1 and 1, these numbers always gives the same reminder, we are going to skip them and start from 4th.	
	/*int64_t fib = 2;
	int64_t fib1 = 1;
	int64_t tmp;	*/
	vector <int32_t>* reminders = new vector<int32_t	>;
	reminders->push_back(0);
	reminders->push_back(1);
	reminders->push_back(1);
	//cout << "0 1 1 ";
	long i = 2;
	while(!((*reminders)[i] == 1 && (*reminders)[i-1] == 0) && m >1)
	{
		
		reminders->push_back(((*reminders)[i] + (*reminders)[i-1])  % m);
		/*cout << (*reminders)[i] << "\t" ;
		cout << i << "\n";*/
		i++;
	}
	return reminders;
}

int32_t fibHuge(int64_t n, int32_t m)
{
	vector<int32_t>* pisa = pisanoPeriod(m);
	//cout << pisa->size() - 2 << "\n";
	long i = n % (pisa->size()-2);
	//cout << i << "\n";
	return (*pisa)[i];
}
