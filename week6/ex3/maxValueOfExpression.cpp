//max(5 − 8 + 7 × 4 − 8 + 9) = ?

#include <iostream>
#include <stdio.h>

// 1 - "+"
// 2 - "-"
// 3 - "*"

using std::cout;
using std::cin;

int op[] = {1, 1, 2, 2, 2, 3, 1, 1, 2, 3, 3};
int val[] ={7, 6, 3, 2, 7, 4, 2, 4, 2, 9, 6, 8};
int n = 12;

void minAndMax(int m[][12], int M[][12], int i, int j);
int operation(int k, int v1, int v2);
int min(int v1, int v2);
int max(int v1, int v2);
void display(int m[][12]);
void initWithZero(int m[][12]);

int main()
{
	int m[n][12];
	int M[n][12];
	int j = 0;
	// Init with zeros
	initWithZero(m);
	initWithZero(M);
	// Display
	display(m);
	cout << "\n";
	display(M);
	// init diagonal
	for(int i = 0; i < n; i ++)
	{
		m[i][i] = val[i];
		M[i][i] = val[i];
	}
	// display
	display(m);
	cout << "\n";
	display(M);
	cout << "\nLets get it started \n\n";
	for(int s = 1; s < n; s++)
	{
		for(int i = 0; i < n - s; i++)
		{
			j = i + s;
			cout << "s= " << s<< " i= " << i << " j = " << j << "\n";
			minAndMax(m, M, i, j);	
			display(m);
			cout << "\n\n";
			display(M);
			cout << "\n\n";
		}			
	}
	display(m);
	cout << "\n\n";
	display(M);
	return 0;
}


void minAndMax(int m[][12], int M[][12], int i, int j)
{
	int minV =  2147483647;
	int maxV = -2147483648;
	int a = 0, b = 0, c = 0, d = 0;
	for(int k = i; k < j; k++)
	{
		cout << "wartosci: "<< M[i][k] << " " << m[i][k] << " " << M[k+1][j] << " " << m[k+1][j] 
			 << "\t[" << i << "]" << "[" << k << "]" << "\t[" << k + 1 << "]" << "[" << j << "] \t operacja: ";
		switch(op[k])
		{
			case(1): cout << "+ \n";
			break;
			case(2): cout << "- \n";
			break;
			case(3): cout << "* \n";
			break;
			default: cout << "ERROR";
			break;
		}
		a = operation(k, M[i][k], M[k+1][j]);
		b = operation(k, M[i][k], m[k+1][j]);
		c = operation(k, m[i][k], M[k+1][j]);
		d = operation(k, m[i][k], m[k+1][j]);
		cout << "liczby " << a << " "<< b << " "<< c << " "<< d << "\n"; 
		minV = min(min(min(min(a,b),c),d),minV);
		maxV = max(max(max(max(a,b),c),d),maxV);
		cout << "wynik:" << minV << " " << maxV << "\n\n";
	}
	m[i][j] = minV;
	M[i][j] = maxV;
}

int operation(int k, int v1, int v2)
{
	switch (op[k])
	{
		case 1:
			return v1 + v2;
		break;
		case 2:
			return v1 - v2;
		break;
		case 3:
			return v1 * v2;
		break;
		default:
			cout << "\n ERROR \n";
			return 0;
		break;
	}
}

int min(int v1, int v2)
{
	if(v1 < v2)
		return v1;
	else 
		return v2; 
}
int max(int v1, int v2)
{
	if(v1 < v2)
		return v2;
	else 
		return v1;	
}

void display(int m[][12])
{
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			if(m[i][j] < -1000)
			{
				cout << m[i][j] << " ";
			}else if(m[i][j] < -100)
			{
				cout << "0" << m[i][j] << " ";
			}else if(m[i][j] < -10)
			{
				cout << m[i][j] << "0";
			}else if(m[i][j] < 0)
			{
				cout << m[i][j] << "00";
			}else if(m[i][j] < 10)
			{
				cout << "0000" << m[i][j] << " ";
			}else if (m[i][j] < 100)
			{
				cout << "000" << m[i][j] << " ";				
			}else if (m[i][j] < 1000)
			{
				cout << "0" << m[i][j] << " ";
			}
		}
		cout << "\n";
	}
}

void initWithZero(int m[][12])
{
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			m[i][j] = 0;
		}
	}
}