// cl is basically a small alternative which sucks, to GNU ls
#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>

using std::string;
using std::vector;

namespace fs = std::filesystem;

int main(int argc, char *argv[]) {
    bool show_hidden = false;
    bool use_color = isatty(STDOUT_FILENO);

    if (argc > 1) {
        string arg1 = argv[1];

        if (arg1 == "-a") {
            show_hidden = true;
        }
    }

    vector<string> files;

    // Collect filenames
    for (const auto &entry : fs::directory_iterator(".")) {
        auto name = entry.path().filename().string();

        if (!show_hidden && name.starts_with(".")) {
            continue;
        }

        files.push_back(name);
    }

    // Sort once
    std::sort(files.begin(), files.end());

    // Print filenames
    for (const auto &file : files) {
        fs::path path = fs::path(".") / file;

        if (use_color) {
            if (fs::is_symlink(path)) {
                std::cout << "\033[36m";
            } else if (fs::is_directory(path)) {
                std::cout << "\033[34m";
            } else if (fs::is_regular_file(path)) {
                auto perms = fs::status(path).permissions();
                auto executable = fs::perms::owner_exec |
                                  fs::perms::group_exec |
                                  fs::perms::others_exec;

                if ((perms & executable) != fs::perms::none) {
                    std::cout << "\033[32m";
                }
            }
        }

        std::cout << file;

        if (use_color) {
            std::cout << "\033[0m";
        }

        std::cout << "  ";
    }

    std::cout << '\n';
    return 0;
}

