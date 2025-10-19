// Cmd.cpp
// Last modified by Golden Hour Software on October 19, 2025
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "GlobalCommands.h"
#include "GlobalDefinitions.h"
#include "GlobalFunctions.h"
#include "Logger.h"

std::string cdErr = "An error occurred while running cd, check the logfile for more information.\nThe logfile is located at /home/[User name]/ on Linux and C:\\Users\\[User name] on Windows.\n";

int CC_Checker()
{
    if (scmd == "exit") exit(0);
    if (scmd == "eggnog_help") cmd_help();
    return 0;

    // yeah the modern code style for me is to put everything possible in seperate functions /joke
}

// The main function for the actual command prompt
int secmd()
{
    // DoNotOutputStart = true;
    while (true) {

        std::cout << currentPath << "> "; 
        std::getline(std::cin, scmd); // To allow the user to input commands.

        loggerUpdate(scmd); 
        CC_Checker();

        if (!IsCustomCommandRun) {

            int sp = system(scmd.c_str()); // needed cause system() uses const char *, and not std::string! FUCK THIS I DONT THINK ITS A GOOD IDEA TO USE C++ SYSTEM() AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA IM SWITCHING
            if (sp != 0) {
                std::cout << "bad command!\n"; // kind of a showoff, but we can detect if Windows commands fail. and this is pointless.
            }
        }
        IsCustomCommandRun = false; // Reset the flag that declares we ran a eggnog built-in command. BUT WHY DO WE DO THIS IN SECMD AAA-
        if (scmd.substr(0, 3) == "cd ") {
            try {
                currentPath = ChangeDirFix(scmd);
            }
            catch (const fs::filesystem_error& e) {
                loggerUpdate(std::string("Uh oh! std::filesystem error while cding: ") + e.what());
                std::cerr << cdErr;
            }
            catch (const std::exception& e) {
                loggerUpdate(std::string("Uh oh! Exception while cding: ") + e.what());
                std::cerr << cdErr;
            }
            catch (...) {
                loggerUpdate(std::string("Unknown exception while cding! Cannot explain error in the logfiles.."));
                std::cerr << cdErr;
            } // Windows cd is broken without this code.
        }
    }
    return 0;

}
