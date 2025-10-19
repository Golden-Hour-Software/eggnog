#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "GlobalDefinitions.h"
#include "GlobalFunctions.h"

std::string ver = std::to_string(MaV) + "." + std::to_string(MiV);

std::string EggnogVersion() {
    return ver;
}

fs::path ChangeDirFix(const std::string ascmd) {
    if (ascmd.substr(0, 3) == "cd ") {
        fs::current_path(ascmd.substr(3)); // Get where we're supposed to be
        currentPathcd = fs::current_path();
        return currentPathcd; // required, else the current path won't display correctly
    }
    else {
        // if we aren't cd'ing and we ran another command..
        return currentPath;
    }

}
