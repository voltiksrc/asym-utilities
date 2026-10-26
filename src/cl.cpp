// This is basically an inspiration of GNU ls but with less features
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    for (const auto& file : fs::directory_iterator(".")) {
        std::cout << file.path().filename().string() << '\n';
    }

    return 0;
}
