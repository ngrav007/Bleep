#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "bleep.hpp"


int main(int argc, char *argv[]) {
    /* check for correct number of arguments */
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << "file bleep_word" << std::endl;
        return EXIT_FAILURE;
    } 

    /* open file and get filename */
    std::string word = argv[2];
    std::string filename = argv[1];
    std::string basename = filename.substr(0, filename.find_last_of("."));
    std::string outfile = basename + "_bleeped.out";
    std::ifstream in(filename);
    std::ofstream out(outfile);
    std::stringstream ss;

    /* read file into stringstream */
    std::string text;
    if (!in) {
        std::cerr << "Could not open file " << argv[1] << std::endl;
        return EXIT_FAILURE;
    } else {
        ss << in.rdbuf();
        text = ss.str();
        in.close();
    }

    /* bleep the word */
    bleep(word, text, out);

    out.close();

    return EXIT_SUCCESS;
}