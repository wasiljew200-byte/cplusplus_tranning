#include "massife.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

Massife::Massife() {
    massif = vector<int> (8, 0);
}

Massife::Massife(vector<int> input_massif) {
    if (input_massif.size() < 8) {
        massif = input_massif;
         while (massif.size() != 8) {
             massif.insert(massif.begin(), 0);
         }
     }
     else  {
        massif = input_massif;
     }
     validate_massif();
}

void Massife::create_new_massif() {
    cout << "Введите символы через пробел для массива: ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    string word;
    int num;
    massif.clear();
    while (ss >> word) {
        stringstream converter(word);
        if (!(converter >> num)) {
            throw InvalidValueException("Массив содержит буквы");
        }
        char r;
        if (converter >> r) {
            throw InvalidValueException("Массив содержит смешанные символы");
        }
        massif.push_back(num);
    }
    if (massif.empty()) {
        throw InvalidValueException("Массив должен содержать хотя бы одно значение");
    }
    if (massif.size() < 8) {
        while (massif.size() != 8) {
            massif.insert(massif.begin(), 0);
        }
    }
    validate_massif();
}

void Massife::print_massif(int k) {
    cout << "Массив " << k << ": ";
    for (int i : massif) {
        cout << i << " ";
    }
    cout << endl;
}

Massife Massife::conjunction_massif(Massife other) {
    vector<int> result_massif;
    for (int i = 0; i < massif.size(); ++i) {
        if (massif[i] == other.massif[i]) {
            result_massif.push_back(massif[i]);
        } else {
            result_massif.push_back(0);
        }
    }
    return Massife(result_massif);
}

void Massife::check_massif(int k1) {
    int k = 0;
    for (int i : massif) {
        if (i != 0 && i != 1) {
            k++;
        }
    }
    if (k > 0) {
        cout << "В массиве " << k1 << " присутствуют плохие символы" << endl;
    }
    else {
        cout << "В массиве " << k1 << " отсутствуют плохие символы" << endl;
    }
}

vector<int> Massife::get_massif() {
    return massif;
}

void Massife::validate_massif() {
    for (int k : massif) {
        if (k != 0 && k != 1) {
            throw InvalidValueException("В массиве обнаружено недопустимые символы");
        }
    }
}
