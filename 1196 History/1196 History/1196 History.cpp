#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int* array, int size, int value)
{
	int count = 0;
	int first = 0,         // First array element       
		last = size - 1,       // Last array element       
		middle,                // Mid point of search       
		position = -1;         // Position of search value   
	bool found = false;        // Flag   
	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point      
		if (array[middle] == value)      // If value is found at mid      
		{
			found = true;
			position = middle;
			count += 1;
		}
		else if (array[middle] > value)  // If value is in lower half         
			last = middle - 1;
		else
			first = middle + 1;          // If value is in upper half   
	}
	return count;
}

void hoarasort(int* a, int first, int last)
{

	int i = first, j = last;
	int tmp, x = a[(first + last) / 2];

	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;

		if (i <= j)
		{
			if (i < j)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < last)
		hoarasort(a, i, last);
	if (first < j)
		hoarasort(a, first, j);
}

int main() {
	int counter = 0;
	int n, k;
	int i;
	cin >> n; 
	int* a = new int[n];
	for (i = 0; i < n; i++)
		cin >> a[i]; //bublesort; sort() 
	
	cin >> k;
	int* b = new int[k];
	for (i = 0; i < k; i++)
		cin >> b[i];
	hoarasort(a, 0, n);
	hoarasort(b, 0, k);
	//бинарный поиск 
	for (i = 0; i < n; i++) {
		counter += binarySearch(b, k, a[i]);
	}
	cout << counter;
	return 0;
}

