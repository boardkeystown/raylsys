#include "rules_json.hpp"

namespace LSYS {

void to_json(nlohmann::json &j, const Rule &r) {
    j["symbol"] = r.symbol;
    j["rule"] = r.rule;
}
void from_json(const nlohmann::json &j, Rule &r) {
    r.symbol = j.value("symbol","");
    r.rule = j.value("rule","");
}

void to_json(nlohmann::json &j, const Ruleset &rs) {
    j["axiom"] = rs.axiom;
    j["angle"] = rs.angle;
    j["length"] = rs.length;
    j["iterations"] = rs.iterations;
    j["rules"] = nlohmann::json::array({});
    for (auto rule : rs.rules) {
        nlohmann::json temp;
        to_json(temp,rule);
        j["rules"].push_back(temp);
    }
}
void from_json(const nlohmann::json &j, Ruleset &rs) {
    rs.axiom = j.value("axiom",std::string({""}));
    rs.angle = j.value("angle",static_cast<float>(0.f));
    rs.length = j.value("length",std::array<float,2>({0.f,0.f}));
    rs.iterations = j.value("iterations",std::size_t(0));
    std::vector<Rule> temp;
    if (j.contains("rules") && j["rules"].is_array()) {
        for (const auto &item : j["rules"]) {
            temp.push_back(item.get<Rule>());
        }
    }
    rs.rules = std::move(temp);
}

}
