#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Massif {
    private:
        vector<int> massif;
        vector<int> massif_1;
        vector<int> massif_2;
    public:

        vector<int> create_new_massif() {
            cout << "Введите символы через пробел для массива: ";
            string line;
            getline(cin, line);
            stringstream ss(line);
            int num;
            vector<int> massif = {};
            while (ss >> num) {
                massif.push_back(num);
            }

            if (massif.size() < 8) {
                while (massif.size() != 8) {
                    massif.insert(massif.begin(), 0);
                }
            }

            return massif;
        }

        void print_massif(vector<int> massif, int k){
            cout << "Массив " << k << ": ";
            for (int i : massif) {
                cout << i << " ";
            }
            cout << endl;
        }

        vector<int> conjunction_massif(vector<int> massif_1, vector<int> massif_2){
            vector<int> massif_3 = {};
            for (int i = 0; i < massif_1.size(); ++i) {
                if (massif_1[i] == massif_2[i]) {
                    massif_3.push_back(massif_1[i]);
                }
                else {
                    massif_3.push_back(0);
                }
            }
            return massif_3;
        }

        void check_massif(vector<int> massif, int k1){
            int k = 0;
            for (int i : massif) {
                if (i != 0 && i != 1) {
                    k++;
                }
            }
            if (k > 0) {
                cout << "В массиве" << k1 << "присутствуют плохие символы" << endl;
            }
            else {
                cout << "В массиве" << k1 << "отсутствуют плохие символы" << endl;
            }
        }
};


int main() {
    Massif massif_1;
    massif_1.create_new_massif();
    massif_1.print_massif();
}