#include "readjson.hpp"

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include "rules_json.hpp"

namespace LSYS {

Ruleset readJson(std::string file) {
    Ruleset ruleset;
    nlohmann::json json;
    std::ifstream file_stream;
    file_stream.open(file.c_str());
    if (!file_stream.is_open()) {
        std::cout << "filed to open file\n";
    }
    try {
        json = nlohmann::json::parse(file_stream);
        file_stream.close();
        ruleset = json.get<Ruleset>();
    } catch (const nlohmann::json::type_error &e) {
        std::cout << "failed to read json\n"
                  << e.what()
                  << "\n";
        file_stream.close();
    }
    return ruleset;
}


}