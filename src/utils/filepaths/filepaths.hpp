#pragma once
#include <string>
namespace Utils::FilePaths {

std::string get_parent_path(
    std::string path
);
std::string join_path(
    std::string path,
    std::string other
);

} //namespace Utils::FilePaths