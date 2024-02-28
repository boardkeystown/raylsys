#include "FilePaths.hpp"
#include <filesystem>
#include <algorithm>
namespace Utils::FilePaths {

std::string get_parent_path(
    std::string path
) {
    std::string result{""};
    std::filesystem::path fsPath(path);
    result = fsPath.parent_path().string();
    return result;
}
std::string join_path(
    std::string path,
    std::string other
) {
    std::string result{""};
    std::filesystem::path fsPath(path);
    std::filesystem::path otherPath(other);
    result = (fsPath / otherPath).string();
    std::replace(result.begin(),result.end(),'/','\\');
    return result;
}
} //namespace Utils::FilePaths