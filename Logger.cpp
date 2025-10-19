#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "GlobalDefinitions.h"
#include <random>
#include "Logger.h"
#include "PlatformSettings.h"


int LoggerRand;
std::string logfileName;

#ifdef _WIN32
    std::string logWorkDir = std::getenv("USERPROFILE"); 
#else
    std::string logWorkDir = std::getenv("HOME");        
#endif

int rander() {
    std::random_device rd;                       
    std::mt19937 gen(rd());                      
    std::uniform_int_distribution<> distr(0, 999999); 

    int rand = distr(gen);

    return rand;
}

int loggerUpdate(std::string LogfileEntry) {

    std::ofstream logFile(logfileName, std::ios::app);
    if (!logFile.is_open()) {
        std::cout << "\nCannot write to log file!\n" << std::endl;
        return 1;
    }

    logFile << LogfileEntry << std::endl;

    logFile.close();

    return 0;
}


std::string CurrentDate() {
    time_t now_c = time(nullptr);
    char buf[100];

    #ifdef _WIN32
        ctime_s(buf, sizeof(buf), &now_c);
    #else
        ctime_r(&now_c, buf);
    #endif

    buf[strcspn(buf, "\n")] = '\0';
    return std::string(buf);
}

int loggerInit() {
    LoggerRand = rander();
    logfileName = std::string(logWorkDir) + platformSlash + ".egglogs" + platformSlash + "eggnog-" + std::to_string(LoggerRand) + ".log";
    std::cout << "Logfile location: " << logfileName << std::endl;
    loggerUpdate("-- EGGNOG LOGFILE " + CurrentDate() + " --");
    return 0;
}
