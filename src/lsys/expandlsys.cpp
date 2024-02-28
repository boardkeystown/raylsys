#include "expandlsys.hpp"

#include "rule.hpp"

namespace LSYS {


std::string process_string(
    std::string old_string,
    const std::vector<Rule> &rules
);

std::string substitute_rule(
    std::string symbol,
    const std::vector<Rule> &rules
);

std::string expandlsys(
    std::size_t iterations,
    std::string axiom,
    const std::vector<Rule> &rules
) {
    std::string result = axiom;
    for (std::size_t _=0; _<iterations; ++_) {
        result = process_string(result,rules);
    }
    return result;
}


std::string process_string(
    std::string old_string,
    const std::vector<Rule> &rules
) {
    std::string new_string{""};
    for (auto symbol : old_string) {
        new_string = new_string + substitute_rule(std::string({symbol}),rules);
    }
    return new_string;
}

std::string substitute_rule(
    std::string symbol,
    const std::vector<Rule> &rules
) {
    std::string result = symbol;
    for (const auto &rule : rules) {
        if (symbol==rule.symbol) {
            result = rule.rule;
            break;
        }
    }
    return result;
}




}