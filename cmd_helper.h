/**
 * Data Manager, EXE CALL FUNCTIONS HERE
*/


#ifndef CMD_HELPER_H_
#define CMD_HELPER_H_

#include "data_manager.h"
#include "file_manager.h"

#include <string>
#include <unordered_map>
#include <iostream>

class CMDHelper {
public:
    void run();

private:
    /**
     * @brief show helper
    */
    void show_helper();
    /**
     * @brief command: -ec  compress file_before and store to file_after
     *
     * store all characters in a file as a string ->
     * build a map from char to string with the string and a Huffman Tree ->
     * turn encoded map to a vector of char and wrote to file_after
     * 
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
     *
     *   original characters, 0x-original characters, compressed characters, frequencies, percentage
     *   i.e.
     *   a  0x81  0010  2166  5.2676%
     *
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

    int total_bit_cnt;

    std::unordered_map<char, std::string> encoded_map;
};

#endif