// GlobalDefinitions.h
// Last modified by Golden Hour Software on October 19, 2025
#include <string>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

extern const char* wEggnog;

extern std::string license;

extern std::string scmd;

extern int MiV;
extern int MaV;

extern bool IsCustomCommandRun;

extern fs::path currentPath;

extern fs::path currentPathcd;
