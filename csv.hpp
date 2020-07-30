#ifndef CSV_HPP
#define CSV_HPP

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

namespace csv {
    using header_type = std::string;
    using column_type = std::vector<std::string>;
    using csv_type = std::map<header_type, column_type>;

    class data_frame {
        public:
            using size_type = std::size_t;

            data_frame(const csv_type& csv) :
                csv(csv),
                ncolumn(csv.size()),
                nrow(csv.begin()->second.size()) {}

            column_type& operator[](const header_type& header) {return csv.at(header);}

            column_type& at(const header_type& header) {return csv.at(header);}

            template <typename T>
                std::vector<T> get_column(const header_type& header, const T fillna=0){
                    std::vector<T> u {};
                    for (const auto& s : csv[header]) {
                        if (s == "") {
                            u.emplace_back(fillna);
                        } else {
                            std::istringstream reader(s);
                            T tmp = 0;
                            reader >> tmp;
                            u.emplace_back(tmp);
                        }
                    }
                    return u;
                }

            size_type size() const {return nrow;}

        private:
            csv_type csv;
            size_type ncolumn;
            size_type nrow;
    };

    std::vector<std::string> split(const std::string &s, const char delimiter=','){
        std::vector<std::string> items {};
        std::string token = "";
        for (const char &c : s) {
            if (c == delimiter) {
                items.emplace_back(token);
                token.clear();
            } else {
                token += c;
            }
        }
        items.emplace_back(token);
        return items;
    }

    data_frame read_csv(const std::string &fname, const char delimiter=',', const bool skip_header=false, const int nrow=-1){
        csv_type csv {};
        std::vector<std::string> headers {};
        int ncolumn = 0;
        int readcnt = 0;
        std::ifstream ifs(fname);
        std::string record = "";
        while (ifs >> record) {
            std::vector<std::string> elements = split(record, delimiter);
            if (readcnt == 0) {
                ncolumn = elements.size();
                if (skip_header) {
                    for (int irow = 0; irow < ncolumn; ++irow) {
                        headers.emplace_back("Unnamed: " + std::to_string(irow));
                        csv[headers[irow]] = {elements[irow]};
                    }
                } else {
                    for (int irow = 0; irow < ncolumn; ++irow) {
                        headers.emplace_back(elements[irow] == "" ? "Unnamed: " + std::to_string(irow) : elements[irow]);
                        csv[headers[irow]] = {};
                    }
                }
            } else {
                for (int irow = 0; irow < ncolumn; ++irow) {
                    csv[headers[irow]].emplace_back(elements[irow]);
                }
            }
            if (readcnt == nrow) {
                if (skip_header) {
                    for (int irow = 0; irow < ncolumn; ++irow) {
                        csv[headers[irow]].pop_back();
                    }
                    break;
                } else {
                    break;
                }
            }
            readcnt += 1;
        }
        return data_frame(csv);
    }
}

#endif
