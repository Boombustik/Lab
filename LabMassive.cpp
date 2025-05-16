#include <iostream>
using namespace std;

// Функція перевірки, чи є число простим
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return false;
    return true;
}

int main() {
    const int n = 30;
    int a[n], sum = 0;

    // Заповнення масиву (можна змінити на rand або cin)
    cout << "Уведіть 30 цілих чисел:\n";
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    // Обчислення суми елементів з простими індексами
    for (int i = 0; i < n; i++) {
        if (isPrime(i)) {
            sum += a[i];
        }
    }

    cout << "Сума елементів з простими індексами: " << sum << endl;

    return 0;
}
