#include "PosixColors.h"

const std::string POSIX_BLACK = "\033[1;30m";
const std::string POSIX_RED = "\033[1;31m";
const std::string POSIX_GREEN = "\033[1;32m";
const std::string POSIX_YELLOW = "\033[1;33m";
const std::string POSIX_BLUE = "\033[1;34m";
const std::string POSIX_MAGENTA = "\033[1;35m";
const std::string POSIX_CYAN = "\033[1;36m";
const std::string POSIX_WHITE = "\033[1;37m";

const std::string POSIX_RESET = "\033[0m";
const std::string POSIX_TITLE_PREFIX = "\033]0;";
const std::string POSIX_TITLE_SUFFIX = "\007";

std::string posixclr(const std::string& text, const std::string& color) {
    return color + text + POSIX_RESET;
}