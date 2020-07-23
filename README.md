# toypoodle

a brief csv reader in C++

## usage

```
#include "toypoodle.h"

int main(){
    auto csv = toypoodle::read_csv("test.csv");

    for (auto [header, row] : csv) {
        // processing
    }
}
```

## functions

Here is the functions given by toypoodle.

### toypoodle::read_csv

```
std::map<std::string, std::vector<std::string>> toypoodle::read_csv(const std::string &fname, const char delimiter=',', const bool skip_header=false);
```
read a csv file and return `std::map` object, which key is the header and which value is the csv row as `std::vector`.

### toypoodle::each_to

```
template<typename T>
std::vector<T> each_to(const std::vector<std::string> &v);
```

return `std::vector` object with casting each element to the template argument type.
