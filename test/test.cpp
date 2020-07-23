#include "toypoodle.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    auto csv = toypoodle::read_csv("test.csv");

    for (const auto &[header, row] : csv) {
        cout << header << " ----------" << endl;
        for (const auto &x: row) {
            cout << x << endl;
        }
    }

    auto A = toypoodle::each_to<double>(csv["A"]);
    cout << "A (casted as double) --------" << endl;
    for (const auto a : A) {
        cout << a << endl;
    }
}
