#include "lottery.h"

main()
{
	/*Ładowanie danych z pliku*/
	fstream input;
	input.open("4_5_lottery.txt");
	int64_t s = 0, p = 0;
	input >> s;
	input >> p;

	int64_t seq[s][2];
	int64_t points[p];
	for (int i = 0; i < s; i++)
	{
		input >> seq[i][0];
		input >> seq[i][1];
	}
	for (int i = 0; i < p; i++)
	{
		input >> points[i];
	}
	/*
	 * DEBUG
	 */
	//display(seq,s);		//Wyświetlnie załadowanych danych w celu weryfikacji poprawności załadowania
	//cout << "\nPosortowane\n";
	/*
	 *
	 */
	 /*Posortowanie przedziałów względem początku przedziału*/
	randomized_quick_sort(seq,0,s);
	int64_t l = 0; 		// ilość przedziałów których punkt początkowy jest mniejszy od szukanej wartości
	int64_t r = 0; 		// ilość przedziałów których punkt koncowy jest mniejszy od szukanej wartości
	int64_t score = 0; 	// zdobyte punkty
	int64_t overallScore = 0;
	//cout << naive(seq, s, points, p);
	//display(seq,s);		//Wyświetlenie posortowanych danych w celu weryfikacji poprawności sortowania
	//dataCorrectness(seq,s);
	for(int64_t i = 0; i < p; i++)
	{
		/*Odzukanie wszystkich przedziałów których pkt. początkowy jest mnieszy niz wylosowana liczba- potencjialnie w tym przedziale ta liczba będzie się zawierać*/
		l = searchSmaller(seq,s,points[i]);
		/*
		 * DEBUG
		 */
		//cout << "Punkt szukany: " <<points[i] << " Odnaleziony " << l << "\n";
		//display(seq,l+1);		//Wyświetlenie wszystkich przedziałów + 1 których pkt. początkowy jest mniejsz od szukanej liczby, w celu weryfikacji poprawnosci
		// randomized_quick_sort_SecondRow(seq,0,l);		//DEBUG ponowne sortowanie tym razem wzg. konca tylko w celach weryfikacji czy rzeczywiscie dobre przedziały zostały wybrane
		//display(seq,l);
		//dataCorrectness(seq,l);
		/*
		 *
		 */
		randomized_quick_sort_SecondRow(seq,0,l);
		r = binarySearchGreater(seq, l, points[i]);
		score = l-r; 
		overallScore += score;
		//cout << l << " " << r << " " << l - r << " " << score;
		//randomized_quick_sort(seq,0,l);
		//dataCorrectness(seq,s);
	}
	cout << overallScore << "\t" << naive(seq, s, points, p);
	return 0;
}

void display(int64_t a[], int n)
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "\n ";
	}
	cout << "\n";
}

void display(int64_t a[][2], int n)
{
	cout << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << a[i][0] << "\t" << a[i][1] << "\t" << i << "\n";
	}
	cout << "\n";
}
void dataCorrectness(int64_t a[][2], int n)
{
	for(int i = 0; i < n-1; i++)
	{
		if(a[i][0] > a[i][1] || a[i+1][0] < a[i][0])
		{
			cout << "\nERRORw miejscu: " << i <<" \n";
			break;
		}
	}
}

/*Function that search all of the elements which are smaller then given point (Item)*/
int64_t searchSmaller(int64_t a[][2], int64_t n, int64_t Item)
{
	int64_t m = n/2, l = 0, h = n-1;
	int64_t pos = 0;
	while(l <= h)
	{
		if(l == h)
		{
			if(a[l][0] <= Item)
			{
				pos = l;
			}
			break;
		}
		m = l + (h-l)/2;
		if(a[m][0] <= Item)
		{
			pos = m;
			l = m + 1;
		}else
		{
			h = m;
		}
	}
	return m;
}

/*Function that search all of the elements which are greater then given point (Item)*/
int64_t searchGreater(int64_t a[][2], int64_t n, int64_t Item)
{
	int64_t cnt = 0;
	for(int64_t i = 0; i < n; i++)
	{
		if(a[i][1] >= Item)
			cnt ++;
	}
	return cnt;
}

/*Binary search */
int64_t binarySearchGreater(int64_t a[][2], int64_t n, int64_t Item)
{
	int64_t pos = 0;
	int64_t m = n/2, l = 0, h = n-1;
	while(l <= h)
	{
		if(l == h)
		{
			if(a[l][1] >= Item)
			{
				pos = l;
			}
			break;
		}
		m = l + (h-l)/2;
		if(a[m][1] >= Item)
		{
			pos = m;
			h = m;
		}else
		{
			l = m + 1;
		}
	}
	return pos;
}

int64_t naive(int64_t seq[][2], int64_t s, int64_t points[], int64_t p)
{
	int score = 0;
	for(int64_t i = 0; i < p; i++)
	{
		for(int64_t j = 0; j < s; j++)
		{
			if(points[i] <= seq[j][1] && points[i] >= seq[j][0])
				score ++;
			/*else
				score --;*/
		}
	}
	return score;
}