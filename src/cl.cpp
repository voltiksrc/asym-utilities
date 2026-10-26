// cl is basically a small alternative which sucks, to GNU ls 
#include <iostream>
#include <filesystem>
#include <string>

using std::string;

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
    bool show_hidden = false;

    if (argc > 1) {
        string arg1 = argv[1];

        if (arg1 == "-a") {
            show_hidden = true;
        }
    } 

    for (const auto& file : fs::directory_iterator(".")) {

        auto name = file.path().filename().string();

        if (!show_hidden && name.starts_with(".")) {
            continue;
        }
        std::cout << name << "  "; 
    }

    std::cout << '\n';
    return 0;
}
