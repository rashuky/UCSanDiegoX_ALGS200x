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
		optimalTime()
		{
			long start = 0;
			long end = 0;
			while(size)
			{
				start = segments[0][0];
				end = segments[0][1];
				// delete the segment it is no longer needed
				segments.erase(segments.begin());
				// reflect the changes on size
				size --;
				cout << "\n";
				display();
				cout << "\nWybrano przedział: "<< start<< " do "<< end << "\n";
/* 
 * This loop looks for the segments that lays within previously choosen segment, by looking whether starting or ending point of that segment lays within previously choosen segment
 * When the loop finds the segment the common point became new starting or ending point of common segment ( common segment shrinks ). Matched segments are erase from the vector. 
 * They are no longer needed.
 */
				cout << "Dopasowano: ";
				for(long j = 0; j < size; j++)
				{
					if(segments[j][0] >= start && segments[j][0] <= end)
					{
						start = segments[j][0]; 
						if(segments[j][1] < end)
						{
							end = segments[j][1];
						}
						cout <<"("<< segments[j][0] << "-"<< segments[j][1]<< ")"<< "\t";
						segments.erase(segments.begin()+ j);
						size --;
					}else if(segments[j][1] >= start && segments[j][1] <= end)
					{
						end = segments[j][1]; 
						if(segments[j][0] > start)
						{
							start = segments[j][0];
						}
						cout <<"("<< segments[j][0] << "-"<< segments[j][1]<< ")"<< "\t";
						segments.erase(segments.begin()+ j);
						size --;
					}
				}
				commonPoints[amountCommon] = start;
				amountCommon ++;
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
		displayCommonPoints()
		{
			cout << "\nLiczba punktów wspólnych: " << amountCommon << " oto one: " << "\n";
			for(long i = 0; i < amountCommon-1; i ++)
			{
				cout << commonPoints[i] << "\t" << i << "\n";
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
	//sig.display();
	sig.optimalTime();
	sig.displayCommonPoints();
	return 0;
}

