// GlobalDefinitions.cpp
// Last modified by Golden Hour Software on October 19, 2025
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>


extern const char* wEggnog;

// GNU license.. why the fuck am i storing it like this, THIS IS STINKING BULLSHIT
std::string license = "This program is free software: you can redistribute it and/or modify it under the terms of the \nGNU General Public License as published by the Free Software Foundation, either version 3 of the License,\nor (at your option) any later version. This program is distributed in the hope that it will be useful,\nbut WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see https://www.gnu.org/licenses/.\n\n";

std::string scmd; // Define the command variable to use for input...

int MiV = 1;
int MaV = 1;

// Core definitions
namespace fs = std::filesystem;
// bool DoNotOutputStart = false;
bool IsCustomCommandRun = false;
fs::path currentPath = fs::current_path();

fs::path currentPathcd;
