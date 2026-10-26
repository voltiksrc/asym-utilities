#include <filesystem>
#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::string;

namespace fs = std::filesystem;

bool make_directory(const fs::path& path) {
    return fs::create_directory(path);
}

bool make_directories(const fs::path& paths) {
    return fs::create_directories(paths);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please enter a directory to create.\n";
        return 1;
    }

    string directory = argv[1];

    try {
        bool result = make_directory(directory);

        if (!result) {
            std::cerr << "Directory already exists.\n";
            return 1;
        }

    } catch (const fs::filesystem_error& error) {
        std::cerr << "Failed to create directory: "
                  << error.what() << '\n';
        return 1;
    }

  for (int i = 1; i < argc; ++i) { 
        try {
            bool result = make_directories(directories);

            if (!result) {
                std::cerr<<"One of these directories already exist.\n";
                return 1;
            }

        } catch (const fs::filesystem_error& error) {
            std::cerr<<"Failed to create directory: "<<error.what()<<'\n';
            return 1;
        }
    }

    return 0;
}
