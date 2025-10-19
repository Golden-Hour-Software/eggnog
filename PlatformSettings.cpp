// PlatformSettings.cpp
// Last modified by Golden Hour Software on October 19, 2025
#include <string>

std::string PlatformSlashF() {
    #ifdef _WIN32
        return "\\";
    #else
        return "/";
    #endif
}



std::string platformSlash = PlatformSlashF();
