#include <iostream>
#include <stdint.h>
#include <fstream>

using std::cin;
using std::cout;
using std::fstream;

int partitionTable(int n, int w[]);
int findPartiion (int arr[], int n);
//utilPrint(int n, int m, int w[][]);
int main(void)
{
	fstream input; 
	input.open("6_2_souvenirs.in");
	int n = 0;
	for(int i = 0; i< 11; i ++)
	{
		input >> n;
		//cout << "\n" << n << "\n";
		int w[n];
		for(int j = 0; j < n; j++)
		{
			input >> w[j];
			//cout << w[j] << " ";
		}
		cout << partitionTable(n, w);
		//cout << "\n --------------------------------------";
	}
	return 0;
}

/*utilPrint(int n, int m, int table[][])
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cout << w[i][j] << " ";
		}
		cout << "\n";
	}
}*/
// Returns true if arr[] can be partitioned in two subsets of
// equal sum, otherwise false
int findPartiion (int arr[], int n)
{
    int sum = 0;
    int i, j;
   
    // Caculcate sun of all elements
    for (i = 0; i < n; i++)
      sum += arr[i];
     
    if (sum%2 != 0)  
       return 0;
   
    bool part[sum/2+1][n+1];
     
    // initialize top row as true
    for (i = 0; i <= n; i++)
      part[0][i] = 1;
       
    // initialize leftmost column, except part[0][0], as 0
    for (i = 1; i <= sum/2; i++)
      part[i][0] = 0;     
      
     // Fill the partition table in botton up manner 
     for (i = 1; i <= sum/2; i++)  
     {
       for (j = 1; j <= n; j++)  
       {
         part[i][j] = part[i][j-1];
         if (i >= arr[j-1])
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
       }        
     }    
      
    // uncomment this part to print table 
     /*for (i = 0; i <= sum/2; i++)  
     {
       for (j = 0; j <= n; j++)  
          printf ("%4d", part[i][j]);
       printf("\n");
    }*/
      
     return part[sum/2][n];
}    

int partitionTable(int n, int w[])
{
	int sum = 0;
	/*calculate the sum of all elements*/
	for(int i = 0; i < n; i++)
	{
		sum = sum + w[i];
	}
	/*Check if the sum can be divided by 3*/
	if(sum%3 != 0)
		return 0;
	/*Build up partition table, from bottom to up*/
	int table[sum/3 + 1][n + 1];
	for(int i = 0; i <= sum / 3; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			if(i == 0)
				table[i][j] = 1;
			else if(j == 0 && i > 0)
				table[i][j] = 0;
			else if(i >= w[j-1])
				table[i][j] = table[i - w[j-1]][j-1];
			else
				table[i][j] = table[i][j-1];
		}
	}
	//utilPrint(n + 1, (sum / 3) + 1, table);
	/*cout << "\n";
	for(int i = 0; i <= sum / 3; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}*/
	/*Jeżeli sie nie da to konczymy :-P*/
	if(!(table[sum/3][n]))
		return 0;
	/*Take the last row and take all elements up to first 0*/
	int i = n;
	while(table[sum / 3][i] == 1)
	{
		i--;
	}
	int newEl[n-i-1]; //nie możemy wziąć wszystkich elementów ostatni z nich wchodzi juz do poprzedniego kanpsacka
	/*move all elements from the last row until first 0 to new array*/
	//cout << "\n";
	for(int j = 0; j < n; j++)
	{
		newEl[j] = w[n-j-1];
		//cout << newEl[j] << " ";
	}		
	//cout << "\n";
	/*Sprawdz czy te elementy ktore zostały dają się podzielic na pół*/
	return findPartiion(newEl, n-i-1);
	//return table[sum/3][n];
}