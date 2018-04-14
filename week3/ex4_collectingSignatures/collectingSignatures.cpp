#include <iostream>
#include <vector>
#include <fstream>

using std::cin;
using std::cout;
using std::vector;
using std::fstream;
class signatures
{
	long size;
	long amountCommon;
	vector <vector <long> > segments;
	vector <long> commonPoints;
	public:	
		signatures(long n): segments(n, vector<long>(2, 0)), commonPoints(1,0), amountCommon(0)
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
		optimalTime()
		{
			long start = 0;
			long end = 0;
			start = segments[0][0]; 
			end = segments[0][1];
			segments.erase(segments.begin());
			size --;
			commonPoints[0] = end;
			amountCommon ++;
			long i = 0;
			while(size)
			{
				
				if(segments[0][0] > end || segments[0][1] < end)
				{
					
					cout << "\n\nCommon segment:\n"<< segments[0][0] << "\n" << end << "\n";
					end = segments[0][1];
					commonPoints.push_back(end);
					amountCommon ++;
					i ++;
				}
				cout << "(" << segments[0][0] << "-" << segments[0][1] << ")\t";
				segments.erase(segments.begin());
				size --;
				
			}
			cout << "\nWykonałem tyle operacji: " << i << "\n";
			amountCommon --;
		}
		display()
		{
			//cout << "Size = " << size << "\n";
			for(long i = 0; i < size; i++)
			{
				cout << segments[i][0] << "\t" << segments[i][1] << "\n";
			}
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
		displayCommonPoints()
		{
			cout << "\nLiczba punktów wspólnych: " << amountCommon << "\t" << commonPoints.size() << " oto one: " << "\n";
			for(long i = 1; i < commonPoints.size()+1; i ++)
			{
				cout << commonPoints[i-1] << "\t" << i << "\n";
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
	//
	sig.sort();
sig.display();
	sig.optimalTime();
	sig.displayCommonPoints();
	return 0;
}

