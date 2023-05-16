#include <iostream>
using namespace std;

//гармонические ряды 1 + 1/2 + 1/3 + ..... + 1/n-1 

//int main() {
//	int n;
//	cin >> n;
//	int* a = new int[n];
//	for (int i = 1; i < n; i++) {
//		int e;
//		cin >> e; //сортировка вставками
//		for (int j = 0; j < i; j++) {
//
//		}
//	}
//	//поиск элемента в отсортированном массиве
//}



// y = 2 - x [0, 2];
double Func(double x){
	return 2 - x;
}
double intey(double(*Func)(double), double a, double b) {
	int n = 1e+4;
	double h = (b - a) / n;
	double sum = (Func(a) + Func(b)) / 2; //интеграл
	for (int i = 1; i < n - 1; i++) {
		sum += Func(a + h);
		a += h;
	}
	return sum * h / 2;
}

double F(double x) {
	return x * x * x - 3 * x * x + 12 * x;
}
double findAnsw(double(*f)(double), double a, double b) { // поиск корня
	double c;
	double e = 0.1e-15;
	while (b - a > e) {
		c = (b + a) / 2;
		if (f(a) * f(c) < 0)
			b = c;
		else
			a = c;
	}
	return (a + b) / 2;
}
// перегрузка функции

//очередь на зачёт тимус