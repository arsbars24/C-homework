#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main() {
	list<int> numbers;
	int number;

	do {
		cin >> number;
		numbers.push_back(number);
	} while (number != 0);

	copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
	return 1;
}