#include <filesystem>
#include <string>
#include <iostream>

using std::string;

namespace fs = std::filesystem;

bool mkdir(int argc, char* argv[]) {
     if (argc < 2) {
         std::cerr<<"Please enter a directory to create.\n";
         return 1;
     }

     string directory = argv[1];

     if (fs::create_directory(directory) != 0) {
         std::cerr<<"Failed to create directory.\n";
         return 1;
    }
    
    return false;
}
