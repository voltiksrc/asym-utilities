#include <fstream>
#include <iostream>
#include <string>

using std::string;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Please enter a file to open.\n";
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        string filename = argv[i];
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file!\n";
            return 1;
        }

        string line;

        while (std::getline(file, line)) {
            std::cout << line << '\n';
        }
    }
    return 0;
}
