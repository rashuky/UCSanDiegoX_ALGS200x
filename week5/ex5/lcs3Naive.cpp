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

int64_t lcs(uint8_t X[], uint64_t m, uint8_t Y[], uint64_t n, uint8_t Z[], uint64_t o);
uint64_t max(uint64_t a, uint64_t b);
main()
{
	fstream input;
	input.open("5_5_lcs3.in");
	uint8_t seq3[100];
	uint8_t seq2[100];
	uint8_t seq1[100];
	uint64_t l1 = 0;
	uint64_t l2 = 0;
	uint64_t l3 = 0;
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
	input >> l3;
	for(int i = 0 ; i < l3; i++)
	{
		input >> seq3[i];
		cout << seq3[i] << " ";
	}
	input.close();
	cout << lcs(seq1, l1, seq2, l2, seq3, 100);
	
	return 0;
}

int64_t lcs(uint8_t X[], uint64_t m, uint8_t Y[], uint64_t n, uint8_t Z[], uint64_t o)
{
    int L[m+1][n+1][o+1];
 
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            for (int k=0; k<=o; k++)
            {
                if (i == 0 || j == 0|| k == 0)
                    L[i][j][k] = 0;
 
                else if (X[i-1] == Y[j-1] && X[i-1]==Z[k-1])
                    L[i][j][k] = L[i-1][j-1][k-1] + 1;
 
                else
                    L[i][j][k] = max((max(L[i-1][j][k],L[i][j-1][k])),L[i][j][k-1]);
            }
        }
    }
 
    return L[m][n][o];
}

uint64_t max(uint64_t a, uint64_t b)
{
	return (a > b) ? a : b;
}