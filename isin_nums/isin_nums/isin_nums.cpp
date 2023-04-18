// map, ключ номер вершины, значение имя
// создаём вектор в который закидываем списки смежных вершин

#include <iostream>
#include <map>
#include <vector>
#include <string>

struct list {
	 // создание списка надо сделать + прописать как и что идёт
};

int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	vector <list(int)> vec;  // в вектор будем присылать списки 
	map <string, int> mp;
	int n; string s;
	cin >> n;
	for (int i = 0; i < n * 3; i++) {
		cin >> s;
		mp.insert(make_pair(s, i));
	}
	map <string, int> :: iterator it = mp.begin();
	cout << "А вот все отсортированно: " << endl;
	for (int i = 0; it != mp.end(); it++, i++) {  // выводим их
		cout << i << ") Ключ " << it->first << ", значение " << it->second << endl;
	}

}