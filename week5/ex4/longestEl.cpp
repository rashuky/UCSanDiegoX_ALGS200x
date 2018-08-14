#include <iostream>
#include <stdint.h>
#include <vector>
#include <fstream>
//#include <string>

using std::cout;
//using std::ifstream;
using std::fstream;
//using std::string;
//using std::length;

typedef struct backtrack
{
	uint8_t value;
	backtrack * pointer;
}backtrack;

int64_t editDistance(uint8_t string1[], uint64_t dis1, uint8_t string2[], uint64_t dis2);
int64_t max(int64_t a, int64_t b);

main()
{
	fstream input;
	input.open("5_4_lcs2.in");
	uint8_t seq2[100];
	uint8_t seq1[100];
	uint64_t l1;
	uint64_t l2;
	int i = 0;
	input >> l1;
	cout << "\n" << l1 << "\n";
	for(int i = 0 ; i < l1; i++)
	{
		input >> seq1[i];
	}
	cout << "\n" << l1 << "\n";
	input >> l2;
	for(int i = 0 ; i < l2; i++)
	{
		input >> seq2[i];
	}
	input.close();
	cout << editDistance(seq1, l1, seq2, l2);
	
	return 0;
}

int64_t editDistance(uint8_t string1[], uint64_t dis1, uint8_t string2[], uint64_t dis2)
{
	/*Define backtrace*/
	backtrack bt[dis2+1][dis1+1];
	uint64_t D[dis2+1][dis1+1];
	uint64_t ins = 0, del = 0, mis = 0, match = 0;
	for(uint64_t i = 0; i <= dis2; i++)
	{
		D[i][0] = 0;
		/*Fill the backtrace with default values*/
		if( i == 0 )
		{
			bt[i][0].pointer = NULL;
			bt[i][0].value = 'e';
		}else{
			bt[i][0].pointer = &bt[i-1][0];
			bt[i][0].value = 'u';
		}
	}
	cout << "\t";
	for(uint64_t i = 0; i <= dis1; i++)
	{
		D[0][i] = 0;
		if(i < 10 && i != 0)
		{
			cout << "0" << i << "|";
		}else if( i != 0)
		{
			cout << i << "|";
		}
		/*Fill the backtrace with default values*/
		if( i == 0)
		{
			bt[0][i].pointer= NULL;
			bt[0][i].value = 'e';
		}else
		{
			bt[0][i].pointer = &bt[0][i-1];
			bt[0][i].value = 'l';
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
			ins = D[i][j - 1];
			del = D[i - 1][j];
			mis   = D[i - 1][j - 1];
			match = D[i - 1][j - 1] + 1;
			if(string1[j-1] == string2[i-1])
			{
				if(match >= ins)
				{
					if(match >= del)
					{
						D[i][j] = match;
						bt[i][j].pointer = &bt[i - 1][j - 1];
						bt[i][j].value = 'd'; // diagonal
					}else 
					{
						D[i][j] = del;
						bt[i][j].pointer = &bt[i - 1][j];
						bt[i][j].value = 'u'; //up
					}
				}
				else if(ins >= del)
				{
					D[i][j] = ins;
					bt[i][j].pointer = &bt[i][j - 1];
					bt[i][j].value = 'l';//left
				}
				else
				{
					D[i][j] = del;
					bt[i][j].pointer = &bt[i - 1][j];
					bt[i][j].value = 'u';//up
				}
			}else 
			{
				if(mis >= ins)
				{
					if(mis >= del)
					{
						D[i][j] = mis;
						bt[i][j].pointer = &bt[i - 1][j - 1];
						bt[i][j].value = 'D';	 // diagonal					
						//cout << "Success " << mis << "\t" << D[i][j]<< "\t" << i<< "\t" << j << "\n";
					}else 
					{
						D[i][j] = del;
						bt[i][j].pointer = &bt[i - 1][j];
						bt[i][j].value = 'u';//up
					}
				}
				else if(ins >= del)
				{
					D[i][j] = ins;
					bt[i][j].pointer = &bt[i][j - 1];
					bt[i][j].value = 'l';
				}
				else
				{
					D[i][j] = del;		
					bt[i][j].pointer = &bt[i - 1][j];
					bt[i][j].value = 'u';//up
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
	/*GO BACK USING BACKTRACE*/
	// display back trace //
	cout << "\n\n";
	for(int i = 0; i < dis1 + 1; i ++)
	{
		for(int j = 0; j < dis2 + 1; j ++)
		{
			cout << bt[i][j].value << "|";
		}
		cout << "\n";
	}
	backtrack * p = bt[dis1][dis2].pointer;
	uint64_t points = 0;
	while(p != NULL)
	{
		if(p->value == 'd')
		{
			points ++;
		}
		p->value = 'X';
		p = p->pointer;	
	}
	
	cout << "\n\n";
	for(int i = 0; i < dis1 + 1; i ++)
	{
		for(int j = 0; j < dis2 + 1; j ++)
		{
			cout << bt[i][j].value << "|";
		}
		cout << "\n";
	}
	
	return points;//D[dis1][dis2];
}

int64_t max(int64_t a, int64_t b)
{
	return (a > b) ? a : b;
}