#include <string>

std::string PlatformSlashF() {
    #ifdef _WIN32
        return "\\";
    #else
        return "/";
    #endif
}


std::string platformSlash = PlatformSlashF();