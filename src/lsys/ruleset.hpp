#pragma once
#include <string>
#include <array>
#include <vector>

namespace LSYS {
    
struct Rule;

struct Ruleset {
    std::string axiom;
    float angle;
    std::array<float,2> length;
    std::size_t iterations;
    std::vector<Rule> rules;
    Ruleset();
    Ruleset(
            std::string axiom,
            float angle,
            std::array<float,2> length,
            std::size_t iterations,
            std::vector<Rule> rules
    );
    ~Ruleset();
};

}