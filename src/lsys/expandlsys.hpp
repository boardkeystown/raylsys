#pragma once
#include <string>
#include <vector>

namespace LSYS {

struct Rule;

std::string expandlsys(
    std::size_t iterations,
    std::string axiom,
    const std::vector<Rule> &rules
);


}