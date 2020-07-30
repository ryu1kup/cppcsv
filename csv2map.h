#ifndef CSV2MAP_H
#define CSV2MAP_H

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

namespace csv2map {
    using csv_t = std::map<std::string, std::vector<std::string>>;

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

    csv_t read_csv(const std::string &fname, const char delimiter=',', const bool skip_header=false, const int nrow=-1){
        csv_t csv {};
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
        return csv;
    }

    size_t len(const csv_t& csv){
        return csv.begin()->second.size();
    }

    template<typename T>
        std::vector<T> get_column(const std::vector<std::string> &v, const T fillna=0) {
            std::vector<T> u {};
            for (const auto& s : v) {
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
}

#endif
