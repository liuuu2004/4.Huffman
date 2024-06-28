#include "file_manager.h"
#include <fstream>
#include <sstream>

std::string FileManager::read_file(const std::string &file_path) {
    std::ifstream file(file_path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
}

void FileManager::write_file(const std::string &file_path, const std::string &s) {
    std::ofstream file(file_path);
    file << s;
    file.close();
}