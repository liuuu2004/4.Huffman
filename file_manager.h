/**
 * File Manager, Makes File R/W Easier
*/

#ifndef FILE_MANAGER_H_
#define FILE_MANAGER_H_

#include <string>

class FileManager {
public:
    /**
     * @brief read file from the given file_path and return its contents
     * @param file_path :file to read from
     * @return content of the file
    */
    std::string read_file(const std::string &file_path);

    /**
     * @brief write string to file
     * @param file_path :file to be written into
     * @param s :string to be written into the file
    */
    void write_file(const std::string &file_path, const std::string &s);
};


#endif