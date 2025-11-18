#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class MassifeException : public runtime_error{
    public:
        MassifeException(const string& message) : runtime_error(message) {
        };
};
class InvalidValueException : public MassifeException {
    public:
        InvalidValueException(const string& message) : MassifeException(message) {
    };
};


class Massife {
    vector<int> massif;

    public:
        Massife();
        Massife(vector<int> input_massif);
        Massife(Massife& other) = default;
        ~Massife() = default;
        void print_massif(int k);
        void create_new_massif();
        void check_massif(int k1);
        Massife conjunction_massif(Massife other);
        vector<int> get_massif();
    private:
        void validate_massif();
};
