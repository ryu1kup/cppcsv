#include "csv.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    auto df = csv::read_csv("test.csv");

    const auto strA = df["A"];
    const auto atA = df.at("A");
    const auto A = df.get_column<string>("A");
    cout << df.size() << endl;;
}
