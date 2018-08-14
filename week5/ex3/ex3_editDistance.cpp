#include <iostream>
#include <stdint.h>
#include <vector>
#include <fstream>
#include <string>

using std::cout;
using std::ifstream;
using std::string;
//using std::length;

int64_t editDistance(string string1, uint64_t dis1, string string2, uint64_t dis2);
main()
{
	ifstream input;
	input.open("5_3_edit_distance.in");
	string string1;
	string string2;
	int i = 0;
	std::getline(input,string1);
	std::getline(input,string2);
	cout << string1 << string1.length() << "\n";
	cout << string2 << string2.length() << "\n";
	input.close();
	cout << editDistance(string1, string1.length(), string2, string2.length());
	
	return 0;
}

int64_t editDistance(string string1, uint64_t dis1, string string2, uint64_t dis2)
{
	uint64_t D[dis2+1][dis1+1];
	uint64_t ins = 0, del = 0, mis = 0, match = 0;
	for(uint64_t i = 0; i <= dis2; i++)
	{
		D[i][0] = i;
	}
	cout << "\t";
	for(uint64_t i = 0; i <= dis1; i++)
	{
		D[0][i] = i;
		if(i < 10 && i != 0)
		{
			cout << "0" << i << "|";
		}else if( i != 0)
		{
			cout << i << "|";
		}
	}
	cout << "\n\t";
	for(uint64_t i = 0; i < dis2; i++)
	{
			cout << string2[i] << " |";
	}
	cout << "\n";
	for(uint64_t i = 1; i <= dis2; i++)
	{
		cout << "\n" << i << string1[i-1] << "\t";
		for(uint64_t j = 1; j <= dis1; j++)
		{
			ins = D[i][j - 1] + 1;
			del = D[i - 1][j] + 1;
			mis   = D[i - 1][j - 1] + 1;
			match = D[i - 1][j - 1];
			if(string1[j-1] == string2[i-1])
			{
				if(match <= ins)
				{
					if(match <= del)
					{
						D[i][j] = match;	
					}else 
					{
						D[i][j] = del;
					}
				}
				else if(ins <= del)
				{
					D[i][j] = ins;
				}
				else
				{
					D[i][j] = del;
				}
			}else 
			{
				if(mis <= ins)
				{
					if(mis <= del)
					{
						D[i][j] = mis;	
						//cout << "Success " << mis << "\t" << D[i][j]<< "\t" << i<< "\t" << j << "\n";
					}else 
					{
						D[i][j] = del;
					}
				}
				else if(ins <= del)
				{
					D[i][j] = ins;
				}
				else
				{
					D[i][j] = del;
				}
			}
			if(D[i][j]<10 && D[i][j]!= 0)
			{
				cout << "0"<< D[i][j] << "|";
			}
			else if (D[i][j] != 0)
			{
				cout << D[i][j] << "|";
			}else if(D[i][j] == 0)
			{
				cout << "\nError D:"<< string1[j-1] << "\t" << string2[i-1] << "\t"  << D[i][j]<< "\tmatch: " << match << "\tins: " << ins << "\tdel: " << del << "\tmis: " << mis << "\n";
			}
		}
	}
	return D[dis1][dis2];
}