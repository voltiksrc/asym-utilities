#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

using std::string;
using std::vector;
namespace fs = std::filesystem;

bool make_dir(const fs::path& path) {
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

    bool failed = false;
    bool parents = false;

    for (int i = 1; i < argc; ++i) {
        if (string(argv[i]) == "-p") {
            parents = true;
            continue;
        }
        try {
            bool result;

            if (parents) {
                result = make_directories(argv[i]);
            } else {
                result = make_dir(argv[i]);
            }

            if (!result && !parents) {
                std::cerr << "Directory already exists: "
                          << argv[i] << '\n';
                failed = true;
            }

        } catch (const fs::filesystem_error& error) {
            std::cerr << "Failed to create directory: "
                      << error.what() << '\n';
            failed = true;
        }
    }

    return failed ? 1 : 0;
}

