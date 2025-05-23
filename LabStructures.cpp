#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

struct Student {
    string surname;
    int number;
    bool hasScholarship;
    float averageMark;
};

void printStudent(const Student& s) {
    cout << "Прізвище: " << s.surname
         << ", Номер: " << s.number
         << ", Стипендія: " << (s.hasScholarship ? "так" : "ні")
         << ", Середній бал: " << s.averageMark << endl;
}

bool compareByMarkDescending(const Student& a, const Student& b) {
    return a.averageMark > b.averageMark;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість студентів: ";
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; ++i) {
        cout << "\nСтудент #" << (i + 1) << endl;
        cout << "Прізвище: ";
        cin >> students[i].surname;
        cout << "Порядковий номер: ";
        cin >> students[i].number;
        cout << "Отримує стипендію (1 - так, 0 - ні): ";
        cin >> students[i].hasScholarship;
        cout << "Середній бал: ";
        cin >> students[i].averageMark;
    }

    cout << "\n--- Повний список студентів ---\n";
    for (const auto& s : students) {
        printStudent(s);
    }

    sort(students.begin(), students.end(), compareByMarkDescending);

    cout << "\n--- Студенти у порядку спадання середнього бала ---\n";
    for (const auto& s : students) {
        printStudent(s);
    }

    return 0;
}
