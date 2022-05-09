#include "bleep.hpp"


/* bleep
 *    Purpose: to replace all instances of a word in a string with BLEEP
 * Parameters: word - the word to be replaced, text - the string to be modified
 *    Returns: None
 *    Effects: Modifies the string text
 */
void bleep(std::string word, std::string &text, std::ostream &out) {
    bool match, begin_word;
    size_t tsize = text.size();
    size_t i = 0, j = 0, k = 0;
    /* loop through filestring */
    for (;i < tsize; i++) {
        /* check if we are at the beginning of a word */
        if (is_begin_word(i, text) and text.at(i) == word.at(0)) {
            match = false;
            /* check if word is in text */
            for (j = i, k = 0; k <= word.size(); j++, k++) {
                try {
                     if (k == word.size() and !is_alpha(text.at(j))) {
                        match = true;
                        break;
                    } else if (k < word.size() and text.at(j) != word.at(k)) {
                        break;
                    }
                } catch (std::out_of_range) {
                    
                    break;
                }
            }

            /* if the word is found, replace it with BLEEP */
            if (match) {
                bleep_range(i, word.size() + i, text, out);
            } else {
                copy_range(i, j - 1, text, out);
            }
            i += k - 1;
        } else {
            out << text.at(i);
        }

    } 
}


/* copy_range
 *    Purpose: to copy a range of characters from a string to an output stream
 * Parameters: start - the start index of the range, end - the end index of the
 *             range, text - the string to be copied, out - the output stream
 *   Returns: None
 *  Effects: Writes to the output stream
*/
void copy_range(size_t start, size_t end, std::string &text, std::ostream &out) {
    for (size_t i = start; i <= end; i++) {
        try {
            out << text.at(i);
        } catch (std::out_of_range &e) {
            std::cerr << "end of string reached." << std::endl;
        }
       
    }
}


/* bleep_range
 *    Purpose: to replace all instances characters in a range with BLEEP
 * Parameters: start - the start index of the range, end - the end index of the
 *             range, text - the string to be modified
 *    Returns: None
 *    Effects: Modifies the string text
 *      Notes: This function is used by bleep to replace a word with BLEEP
 *             It is not intended to be called directly
 */ 
void bleep_range(size_t start, size_t end, std::string &text, std::ostream &out) {
    try {
        for (size_t i = start; i < end; i++) {
            out << BLEEP;
        }
    } catch (std::out_of_range &e) {
        std::cerr << "end of string reached." << std::endl;
    }
}


/* is_begin_word
 *    Purpose: checks if the current character is the first character of the
 *             word
 * Parameters: char c
 *    Returns: bool
 */
bool is_begin_word(int i, std::string text) {
    if ((i == 0 or !is_alpha(text[i-1])) and is_alpha(text[i])) {
        return true;
    } else {  
        return false;
    }
}


/* is_alpha
 *    Purpose: checks if a character is an alphabetic character
 * Parameters: char c
 *    Returns: true if c is an alphabetic character, false otherwise
 */ 
bool is_alpha(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
