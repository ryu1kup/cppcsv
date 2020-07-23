#ifndef TOYPOODLE_H
#define TOYPOODLE_H

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

namespace toypoodle {
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

    std::map<std::string, std::vector<std::string>> read_csv(const std::string &fname, const char delimiter=',', const bool skip_header=false){
        std::map<std::string, std::vector<std::string>> csv {};
        std::vector<std::string> headers {};
        unsigned int nrow = 0;
        unsigned int readcnt = 0;
        std::ifstream ifs(fname);
        std::string record = "";
        while (ifs >> record) {
            std::vector<std::string> elements = split(record);
            if (readcnt == 0) {
                nrow = elements.size();
                if (skip_header) {
                    for (unsigned int irow = 0; irow < nrow; ++irow) {
                        headers.emplace_back("Unnamed: " + std::to_string(irow));
                        csv[headers[irow]] = {elements[irow]};
                    }
                } else {
                    for (unsigned int irow = 0; irow < nrow; ++irow) {
                        headers.emplace_back(elements[irow] == "" ? "Unnamed: " + std::to_string(irow) : elements[irow]);
                        csv[headers[irow]] = {};
                    }
                }
            } else {
                for (unsigned int irow = 0; irow < nrow; ++irow) {
                    csv[headers[irow]].emplace_back(elements[irow]);
                }
            }
            readcnt += 1;
        }
        return csv;
    }

    template<typename T>
    std::vector<T> each_to(const std::vector<std::string> &v) {
        std::vector<T> u {};
        for (const auto& s : v) {
            std::istringstream reader(s);
            T tmp = 0;
            reader >> tmp;
            u.emplace_back(tmp);
        }
        return u;
    }
}

#endif
