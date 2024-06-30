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

bool FileManager::file_exist(const std::string &file_name) {
    std::ifstream check_file(file_name);
    if (!check_file.good()) {
        check_file.close();
        return false;
    }
    check_file.close();
    return true;
}