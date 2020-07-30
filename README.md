# cppcsv

a brief csv reader in C++

## usage

```
#include "csv.hpp"

int main(){
    auto df = csv::read_csv("test.csv");

    auto A = df.get_column<int>("A");
    for (const auto& a : A) {
        // process for each element of the column A
    }
}
```

### csv::read_csv

declaration

```
data_frame csv::read_csv(const std::string &fname, const char delimiter=',', const bool skip_header=false, const int nrow=-1);
```
read a csv file and return `data_frame` object, which class is just a brief wrapper of `std::map<std::string, std::vector<std::string>>`.
The key `std::string` is the header and which value `std::vector,std::string>` is the csv column.

|   | arguments      | type   | description                                    |
| - | -------------- | ------ | ---------------------------------------------- |
| 1 | fname          | string | input csv filename                             |
| 2 | delimiter      | char   | record delimiter                               |
| 3 | skip_header    | bool   | boolean controlling if you skip header or not  |
| 4 | nrow           | int    | number of lines to be read                     |

### csv::data_frame::get_column

declaration

```
template<typename T>
std::vector<T> get_column(const std::string header, const T fillna=0);
```

return `std::vector<T>` object with casting each element to the template argument type.

|   | arguments | type   | description                |
| - | --------- | ------ | ---------------------------|
| 1 | header    | string | header name                |
| 2 | fillna    | T      | value to fill missing data |

### csv::data_frame::size

declaration

```
size_t size();
```

return the column length.
