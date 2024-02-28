#pragma once
#include <array>
#include <string>
#include "lines/linesmgr.hpp"
namespace LSYS {

void followRules(
    LINES::LinesMgr &lineMgr, 
    const std::string &rules,
    const std::array<float,2> length,
    const float angle
);


} // namespace LSYS
