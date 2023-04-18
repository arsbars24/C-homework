#include <iostream>
#include <vector>
using namespace std;

class SquareMatrix {
private:
    vector<vector<double>> data;
    int size;

public:
    
    SquareMatrix(int size) : size(size) {
        data.resize(size);
        for (int i = 0; i < size; i++) {
            data[i].resize(size);
        }
    }

    int getSize() const {
        return size;
    }

    double get(int i, int j) const {
        return data[i][j];
    }

    void set(int i, int j, double value) {
        data[i][j] = value;
    }

    void reduceToDiagonal() {
        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (i == j || j == k) {
                        continue;
                    }
                    double factor = data[i][k] / data[k][k];
                    data[i][j] -= factor * data[k][j];
                }
            }
        }
    }
    SquareMatrix operator*(SquareMatrix data2) {
        for (size_t i = 0; i < data2.getSize(); i++) {
            for (size_t j = 0; j < data2.getSize(); j++) {
                for (size_t k = 0; k < data2.getSize(); k++) {
                    data[i][j] += data[i][k] * data2[k][j];
                }
            }
        }
    }
};                      // узнать про ошибку в data2[k][j]
                        // конструктор копирования 
int main() {
    SquareMatrix mat(3);

    mat.set(0, 0, 2.0); // заполняем матрицу
    mat.set(0, 1, 1.0);
    mat.set(0, 2, 3.0);
    mat.set(1, 0, 4.0);
    mat.set(1, 1, 5.0);
    mat.set(1, 2, 6.0);
    mat.set(2, 0, 7.0);
    mat.set(2, 1, 8.0);
    mat.set(2, 2, 9.0);

    cout << "Original matrix:" << endl;
    for (int i = 0; i < mat.getSize(); i++) {
        for (int j = 0; j < mat.getSize(); j++) {
            cout << mat.get(i, j) << " ";
        }
        cout << endl;
    }

    mat.reduceToDiagonal();

   cout << "Reduced to diagonal matrix:" << endl;
    for (int i = 0; i < mat.getSize(); i++) {
        for (int j = 0; j < mat.getSize(); j++) {
           cout << mat.get(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
};

// нарисовать планетарная модель и нарисовать граф, 1145