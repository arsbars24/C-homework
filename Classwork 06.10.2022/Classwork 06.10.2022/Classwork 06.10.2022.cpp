#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	// n - количество элементов массива
	int* a = new int[n];// создали статистический массив
	//(int* a) --> a является указателем на память (адрес с интовыми ячейками))
	// *(a+2) = a[2]
	// а выделяется в stack`е, *а это ячейка памяти
	// new выделяет место в память
	input_array(a, n);
	print_array(a, n);
	revers_array(a, n);
	print_array(a, n);
	return 0;
}

void input_array(int* a, int n){
	for (int i = 0; i < n; i++) {
		cin >> *(a + i); a[i];
		//* cout
	}
}

void reverse array(int* a, int n{
	for (int i = 0; i < n / 2; i++) {
		int num = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = num;
}
	})
