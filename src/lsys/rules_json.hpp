#pragma once

#include <nlohmann/json.hpp>

#include "rule.hpp"
#include "ruleset.hpp"

namespace LSYS {

void to_json(nlohmann::json &j, const Rule &r);
void from_json(const nlohmann::json &j, Rule &r);

void to_json(nlohmann::json &j, const Ruleset &rs);
void from_json(const nlohmann::json &j, Ruleset &rs);


}
