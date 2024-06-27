/**
 * Data Manager, EXE CALL FUNCTIONS HERE
*/


#ifndef DATA_MANAGER_H_
#define DATA_MANAGER_H_

#include "file_manager.h"
#include "huffman_tree.h"

#include <string>
#include <unordered_map>

class DataManager {
public:
    /**
     * @brief command: -ec  compress file_before and store to file_after
     * @param file_before :original file
     * @param file_after :file after compression
    */
    void compress(const std::string &file_before, const std::string &file_after);

    /**
     * @brief command: -dc  decompress file_after and store to file_output
     * @param file_after :file after compression, to be decompressed here
      *@param file_output :file after decompression
    */
    void decompress(const std::string &file_after, const std::string &file_output);

    /**
     * @brief command: -a  analyze information before and after compression in decrease order
     *      original characters, 0x-original characters, compressed characters, frequencies, percentage
     *      i.e.
     *      a  0x81  0010  2166  5.2676%
     * @param file_before :original file
     * @param file_after :file after compression
    */
    void analyze_dec(const std::string &file_before, const std::string &file_after);

    /**
     * @brief command: -ra  analyze information before and after compression in increase order
     *      original characters, 0x-original characters, compressed characters, frequencies, percentage
     *      i.e.
     *      a  0x81  0010  2166  5.2676%
     * @param file_before :original file
     * @param file_after :file after compression
    */
    void analyze_inc(const std::string &file_before, const std::string &file_after);

    /**
     * @brief command: -ls  print file contents to the cmd
     * @param file_before :original file
     * @param file_after :file after compression
    */
    void show_both(const std::string &file_before, const std::string &file_after);

    /**
     * @brief command: -pf  show performance
     * @param file_before :original file
     * @param file_after :file after compression
    */
    void performance(const std::string &file_before, const std::string &file_after);

private:
    int encode()
};

#endif