// PosixColors.h
// Last modified by Golden Hour Software on October 19, 2025
#pragma once
#include <string>

extern const std::string POSIX_BLACK;
extern const std::string POSIX_RED;
extern const std::string POSIX_GREEN;
extern const std::string POSIX_YELLOW;
extern const std::string POSIX_BLUE;
extern const std::string POSIX_MAGENTA;
extern const std::string POSIX_CYAN;
extern const std::string POSIX_WHITE;

extern const std::string POSIX_RESET;
extern const std::string POSIX_TITLE_PREFIX;
extern const std::string POSIX_TITLE_SUFFIX;


std::string posixclr(const std::string& text, const std::string& color);
