#include "rule.hpp"

namespace LSYS {

Rule::Rule() :
    symbol(""),
    rule("")
{}
Rule::Rule(
    std::string symbol,
    std::string rule
) : 
    symbol(symbol),
    rule(rule)
{}
Rule::~Rule() {}


}