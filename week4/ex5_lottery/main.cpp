#include "main.h"

main()
{
	fstream input;
	input.open("4_5_lottery.in");
	cout << "zyj";
	int64_t s = 0, p = 0;
	cout << "zyj";
	input >> s;
	cout << "zyj0";
	input >> p;
	cout << "zyj";
	int64_t seq[s][s];
	int64_t points[p];
	
	for (int i = 0; i < s; i++)
	{
		cout << "Zyje0\n";
		input >> seq[i][0];
		input >> seq[i][1];
	}
	cout << "Zyje1\n";
	for (int i = 0; i < p; i++)
	{
		input >> points[i];
	}
	cout << "Zyje2\n";	
	display(*seq,s);
	display(points,p);
	
	return 0;
}