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

int64_t lcs(uint64_t string1[], uint64_t dis1, uint64_t string2[], uint64_t dis2);
int64_t max(int64_t a, int64_t b);
main()
{
	fstream input;
	input.open("5_4_lcs2.in");
	uint64_t seq2[100];
	uint64_t seq1[100];
	uint64_t l1;
	uint64_t l2;
	int i = 0;
	input >> l1;
	cout << "\n" << l1 << "\n";
	for(int i = 0 ; i < l1; i++)
	{
		input >> seq1[i];
		cout << seq1[i];
	}
	cout << "\n" << l1 << "\n";
	input >> l2;
	for(int i = 0 ; i < l2; i++)
	{
		input >> seq2[i];
		cout << seq2[i];
	}
	input.close();
	cout << lcs(seq1, l1, seq2, l2);
	
	return 0;
}

int64_t lcs(uint64_t X[], uint64_t m, uint64_t Y[], uint64_t n)
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
 }

int64_t max(int64_t a, int64_t b)
{
	return (a > b) ? a : b;
}