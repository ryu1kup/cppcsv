# csv2map

a brief csv reader in C++

## usage

```
#include "csv2map.h"

int main(){
    auto csv = csv2map::read_csv("test.csv");

    for (auto [header, row] : csv) {
        // processing
    }
}
```

## functions

csv2map provides `std::map<std::string, std::vector<std::string>>` object from a csv file.
`csv_t` is an alias to this complicated STL container.

Here is the functions given by csv2map.

### csv2map::read_csv

```
csv_t csv2map::read_csv(const std::string &fname, const char delimiter=',', const bool skip_header=false, const int nrow=-1);
```
read a csv file and return `csv_t` object, which type name is an ailas to `std::map<std::string, std::vector<std::string>>`.
The key `std::string` is the header and which value `std::vector,std::string>` is the csv column.

|   | arguments      | type   | description                                    |
| - | -------------- | ------ | ---------------------------------------------- |
| 1 | fname          | string | input csv filename                             |
| 2 | delimiter      | char   | record delimiter                               |
| 3 | skip_header    | bool   | boolean controlling if you skip header or not  |
| 4 | nrow           | int    | number of lines to be read                     |

### csv2map::each_to

```
template<typename T>
std::vector<T> each_to(const std::vector<std::string> &v, const T fillna=0);
```

return `std::vector` object with casting each element to the template argument type.

|   | arguments      | type           | description                 |
| - | -------------- | -------------- | --------------------------- |
| 1 | v              | vector<string> | input string vector         |
| 2 | fillna         | T              | value to fill missing data  |

### csv2map::len

```
size_t len(const std::map<std::string, std::vector<std::string>> &csv)
```

return the column length.

|   | arguments      | type           | description                 |
| - | -------------- | -------------- | --------------------------- |
| 1 | v              | csv_t          | the csv                     |
