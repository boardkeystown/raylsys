#include "openFileDialog.hpp"
#include <nfd.hpp>
namespace Utils::Dialog {
std::string OpenFileDialog() {
    std::string filePath{""};
    // initialize NFD
    NFD::Guard nfdGuard;
    // auto-freeing memory
    NFD::UniquePath outPath;
    // prepare filters for the dialog
    nfdfilteritem_t filterItem[1] = {
        {"ruleset json","json"}
    };
    // show the dialog
    nfdresult_t result = NFD::OpenDialog(outPath, filterItem, 1);
    if (result == NFD_OKAY) {
        //std::cout << "Success!" << std::endl << outPath.get() << std::endl;
        filePath = outPath.get();
    } else if (result == NFD_CANCEL) {
        //std::cout << "User pressed cancel." << std::endl;
        filePath = "";
    } else {
        //std::cout << "Error: " << NFD::GetError() << std::endl;
        filePath = "";
    }
    return filePath;
}
} //namespace Utils::Dialog