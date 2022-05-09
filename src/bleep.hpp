#ifndef _BLEEP_H_
#define _BLEEP_H_

#include <string>
#include <iostream>
#define BLEEP '*'

bool is_alpha(char c);
bool is_begin_word(int i, std::string text);
void bleep(std::string word, std::string &text, std::ostream &out);
void bleep_range(size_t start, size_t end, std::string &text, std::ostream &out);
void copy_range(size_t start, size_t end, std::string &text, std::ostream &out);

#endif