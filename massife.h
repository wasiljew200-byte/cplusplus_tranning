#pragma once
#include <vector>
#include <string>

using namespace std;

class Massife {
    vector<int> massif;

    public:
        Massife();
        Massife(const vector<int> input_massif);
        void print_massif(int k);
        void create_new_massif();
        void check_massif(int k1);
        Massife conjunction_massif(const Massife other);
        vector<int> get_massif();
};
