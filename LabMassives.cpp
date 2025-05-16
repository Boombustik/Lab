#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int ROWS = 5;
const int COLS = 5;

int main() {
    setlocale(LC_ALL, "ukr");
    srand(time(0));

    int matrix[ROWS][COLS];

    // Заповнення матриці випадковими числами (-10 до 10)
    cout << "Матриця:\n";
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 21 - 10;
            cout << matrix[i][j] << '\t';
        }
        cout << '\n';
    }

    // 1. Сума всіх елементів
    int totalSum = 0;
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            totalSum += matrix[i][j];

    cout << "\nСума всіх елементів матриці: " << totalSum << endl;

    // 2. Сума елементів у стовпцях, які мають хоча б один від’ємний елемент
    int conditionalSum = 0;
    for (int j = 0; j < COLS; ++j) {
        bool hasNegative = false;
        for (int i = 0; i < ROWS; ++i) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (hasNegative) {
            for (int i = 0; i < ROWS; ++i)
                conditionalSum += matrix[i][j];
        }
    }

    cout << "Сума елементів у стовпцях з хоча б одним від’ємним елементом: " << conditionalSum << endl;

    return 0;
}
