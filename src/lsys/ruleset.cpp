#include "ruleset.hpp"
#include "rule.hpp"

namespace LSYS {

Ruleset::Ruleset() :
    axiom(""),
    angle(0.f),
    length({0.f,0.f}),
    iterations(0),
    rules({})
{}
Ruleset::Ruleset(
        std::string axiom,
        float angle,
        std::array<float,2> length,
        std::size_t iterations,
        std::vector<Rule> rules
) :
    axiom(axiom),
    angle(angle),
    length(length),
    iterations(iterations),
    rules(rules)
{}
Ruleset::~Ruleset() {}

}