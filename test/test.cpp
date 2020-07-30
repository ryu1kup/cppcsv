#include "csv2map.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    auto csv = csv2map::read_csv("test.csv");
    auto A = csv["A"];
    for (auto x : A) {
        cout << x << endl;
    }
    cout << csv2map::len(csv) << endl;;
}
