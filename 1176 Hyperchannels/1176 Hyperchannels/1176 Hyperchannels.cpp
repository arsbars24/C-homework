#include <iostream>
using namespace std;

struct stack {
	int array[5000];
	int count;
	// данные закончились
	// методы
	stack() {};
	stack(int c) {
		count = c;
	}
	bool empty() {
		return count == 0;
	}
	void push(int e){
		array[count++] = e;
	}
	int pop() {
		return array[count--];
	}
	int top() {
		return array[count];
	}
};

int main() {
	int n; //ft is first top; n for matrix
	int ft;
	cin >> n >> ft;
	int** matrix = new int* [n + 1];
	for (int i = 1; i < n; i++) matrix[i] = new int[n + 1];
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			cin >> matrix[i][j];
	stack ws(0); // working stack;
	stack rs(0); // result stack
	ws.push(ft);
	while (!ws.empty()) {
		bool flag = true;
		for (int i = 1; i <= n && i != ft; i++) {
			if (matrix[ft] == 0) {
				ws.push(i);
				flag == false;
				matrix[ft][i] = 1;
				ft = i;
				break;
			}
		}
		if (flag) {
			rs.push(ws.pop());
		}

	}
	int a = rs.pop();

	while (!rs.empty()) {
		int b = rs.pop();
		cout << a << ' ' << b << endl;
		a = b;
	}

}