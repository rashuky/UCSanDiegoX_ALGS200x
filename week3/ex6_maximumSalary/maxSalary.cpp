#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::fstream;

class salary
{
	vector <int> numbers;
	long n;
	public:
		salary(long size): numbers(size,0)
		{
			fstream input;
			input.open("3_6_largest_number.in");
			input >> n;
			for(long i = 0; i < n; i++)
			{
				input >> numbers[i];
			}
			input.close();
		}
		maximize()
		{
			
		}
		display()
		{
			for(long i = 0; i < numbers.size(); i++)
			{
				cout << numbers[i] << "\n";
			}
			bubleSort();
			cout << "\nshould be sorted\n";
			for(long i = 0; i < numbers.size(); i++)
			{
				cout << numbers[i];
			}
		}
	private:
		bubleSort()
		{
			int onceAgain = 1;
			while(onceAgain)
			{
				onceAgain = 0;
				for(int i = 0; i < numbers.size()-1; i++)
				{
					int digits1[3] = { 0, 0, 0 }; 
					splitNumber(numbers[i], digits1);					
					int digits2[3] = { 0, 0, 0 }; 
					splitNumber(numbers[i + 1], digits2);
					if(digits2[0] > digits1[0])
					{
						cout <<"Swap: " << numbers[i + 1] << "\t" << numbers[i] <<"\n";
						swap(&numbers[i + 1],&numbers[i]);
						cout <<"Res: " << numbers[i + 1] << "\t" << numbers[i] <<"\n";
						onceAgain = 1;
					}else if(digits2[0] == digits1[0])
					{
						if(digits2[1] > digits1[1])
						{
							cout <<"Swap: " << numbers[i + 1] << "\t" << numbers[i] <<"\n";
							swap(&numbers[i + 1],&numbers[i]);
							cout <<"Res: " << numbers[i + 1] << "\t" << numbers[i] <<"\n";
							onceAgain = 1;
						}else if(digits2[1] == digits1[1])
						{
							if(digits2[2] > digits1[2])
							{
								cout <<"Swap: " << numbers[i + 1] << "\t" << numbers[i] <<"\n";
								swap(&numbers[i + 1],&numbers[i]);
								cout <<"Res: " << numbers[i + 1] << "\t" << numbers[i] <<"\n";
								onceAgain = 1;
							}
						}
					}
				}
			}			
		}
		int * splitNumber(int number, int * digits)
		{
			if(number/100)
			{
				digits[0] = number / 100;
				digits[1] = (number % 100)/10;
				digits[2] = number % 100; 
			}else if((number % 100)/10)
			{
				digits[0] = (number % 100)/10;
				digits[1] = number % 10;
//When you have 2 digit number, simulate last digit as the firs digit. (ex 78(7) & 784=> 78784 not 78478, but 78(7) & 789 => 78978 not 78789)
				digits[2] = number;				
			}else
			{
				digits[0] = number;
//See the comment above. The same goes for 1 digit nummber agains 2 digi and 3 digit.
				digits[1] = number;				
				digits[2] = number;				
			}
			return digits;
		}
		swap(int * number1, int * number2)
		{
			int tmp;
			tmp = *number2;
			*number2 = *number1;
			*number1 = tmp;
		}

};

int main()
{
	long n = 0;
	fstream input;
	input.open("3_6_largest_number.in");
	input >> n;
	input.close();
	salary sal = salary(n);
	sal.display();
	return 0; 
}
