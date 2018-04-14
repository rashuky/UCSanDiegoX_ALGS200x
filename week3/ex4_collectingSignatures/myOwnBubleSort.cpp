#include <iostream>
#include <vector>
#include <fstream>

using std::cout;
using std::cin;
using std::vector;
using std::fstream;

class signatures
{
	long size;
	long amountCommon;
	vector <vector <long> > segments;
	vector <long> commonPoints;
	public:	
		signatures(long n): segments(n, vector<long>(2, 0)), commonPoints(77,0), amountCommon(0)
		{
			fstream input;
			input.open("3_4_covering_segments.in");
			input >> size;	
			//cout << "Size = " << size << "\n";	
			for(long i = 0; i < size; i ++)
			{
				input >> segments[i][0];
				input >> segments[i][1];
			}
			input.close();
		}
		sort()
		{
			int onceAgain = 1;
			while(onceAgain)
			{
				onceAgain = 0;
				for(long i = 0; i < size -1 ; i++)
				{
					if(segments[i][1] > segments[i+1][1])
					{
						onceAgain = 1;
						long temp = 0;
						// Swap ends
						temp = segments[i][1];
						segments[i][1] = segments[i + 1][1];
						segments[i + 1][1] = temp;
						// Swap starts
						temp = segments[i][0];
						segments[i][0] = segments[i + 1][0];
						segments[i + 1][0] = temp;
					}
				}
			}
		}
		display()
		{
			//cout << "Size = " << size << "\n";
			for(long i = 0; i < size; i++)
			{
				cout << segments[i][0] << "\t" << segments[i][1] << "\n";
			}
		}
};

int main()
{
	fstream input;
	input.open("3_4_covering_segments.in");
	long size = 0;
	input >> size;
	input.close();
	signatures sig = signatures(size);
	sig.display();
	cout << "\nPosortowan\n";
	sig.sort();
	sig.display();
	return 0 ;
}
