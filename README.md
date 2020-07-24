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
std::map<std::string, std::vector<std::string>> toypoodle::read_csv(const std::string &fname, const char delimiter=',', const bool skip_header=false, const int nrow=-1);
```
read a csv file and return `std::map` object, which key is the header and which value is the csv row as `std::vector`.

|   | arguments      | type   | description                                    |
| - | -------------- | ------ | ---------------------------------------------- |
| 1 | fname          | string | input csv filename                             |
| 2 | delimiter      | char   | record delimiter                               |
| 3 | skip_header    | bool   | boolean controlling if you skip header or not  |
| 4 | nrow           | int    | number of lines to be read                     |

### toypoodle::each_to

```
template<typename T>
std::vector<T> each_to(const std::vector<std::string> &v, const T fillna=0);
```

return `std::vector` object with casting each element to the template argument type.

|   | arguments      | type           | description                 |
| - | -------------- | -------------- | --------------------------- |
| 1 | v              | vector<string> | input string vector         |
| 2 | fillna         | T              | value to fill missing data  |
