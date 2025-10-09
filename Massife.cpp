#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<int> massif_1;
    vector<int> massif_2;
    string line1, line2;

    cout << "Введите символы через пробел для массива 1: ";
    getline(std::cin, line1);
    stringstream ss1(line1);
    int num;
    while (ss1 >> num) {
        massif_1.push_back(num);
    }
    cout << "Введите символы через пробел для массива 2: ";
    getline(std::cin, line2);
    stringstream ss2(line2);
    while (ss2 >> num) {
        massif_2.push_back(num);
    }

    int k = 0;
    for (int i : massif_1) {
        if (i != 0 && i != 1) {
            k++;
        }
    }
    if (k > 0) {
        cout << "В массиве 1 присутствуют плохие символы" << endl;
    }
    else {
        cout << "В массиве 1 отсутствуют плохие символы" << endl;
    }
    k = 0;
    for (int i : massif_2) {
        if (i != 0 && i != 1) {
            k++;
        }
    }
    if (k > 0) {
        cout << "В массиве 2 присутствуют плохие символы" << endl;
    }
    else {
        cout << "В массиве 2 отсутствуют плохие символы" << endl;
    }

    
    cout << "Массив 1: ";
    for (int i : massif_1) {
        std::cout << i << " ";
    }



}