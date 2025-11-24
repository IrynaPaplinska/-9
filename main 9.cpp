#include <iostream>
#include <string>
using namespace std;

// Оголошення структури Train
struct Train {
    string destination;  // пункт призначення
    int number;          // номер потягу
    float time;          // час відправлення (наприклад 18.30)
};

int main() {
    const int N = 8;
    Train trains[N];

    // --- Введення даних ---
    cout << "Введіть дані про 8 потягів:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "\nПотяг №" << i+1 << endl;
        cout << "Пункт призначення: ";
        cin >> trains[i].destination;
        cout << "Номер потягу: ";
        cin >> trains[i].number;
        cout << "Час відправлення (наприклад 18.30): ";
        cin >> trains[i].time;
    }

    // --- Сортування за часом відправлення ---
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (trains[i].time > trains[j].time) {
                swap(trains[i], trains[j]);
            }
        }
    }

    // --- Пошук потягів за пунктом призначення ---
    string city;
    cout << "\nВведіть назву міста для пошуку: ";
    cin >> city;

    bool found = false;
    cout << "\nПотяги, що прямують до " << city << ":" << endl;

    for (int i = 0; i < N; i++) {
        if (trains[i].destination == city) {
            cout << "Потяг №" << trains[i].number
                 << "  | час: " << trains[i].time << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Потягiв до цього міста немає." << endl;
    }

    return 0;
}
