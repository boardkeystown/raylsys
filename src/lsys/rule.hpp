#pragma once
#include <string>

namespace LSYS {
struct Rule {
    std::string symbol;
    std::string rule;
    Rule();
    Rule(
        std::string symbol,
        std::string rule
    );
    ~Rule();
};

}