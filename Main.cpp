// Note to self: Make sure all this code works on windows 7+ and linux
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "GlobalCommands.h"
#include "GlobalDefinitions.h"
#include "GlobalFunctions.h"
#include "Cmd.h"
#include "Logger.h"
#include "PosixColors.h"

#ifdef _WIN32
#include <windows.h>
void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
#endif

const char* wEggnog = "eggnog";

int main() {
    #ifdef _WIN32
        enableANSI();
    #endif
    // i hate how i coded this entire function

    // SetConsoleTitleA(wEggnog);

    std::cout << posixclr(license, POSIX_BLUE); // we don't waste memory as the license is loaded into memory even if not used... so use it!


    // the if definitions were from an eggnog's early development that would execute main() after commands.

    // if (!DoNotOutputStart) {
    std::cout << "\neggnog beta v" << EggnogVersion() << "\n";
    std::cout << "Built on " << __DATE__ << ", " << __TIME__ << "\n";
    std::cout << "system command prompt\n";
    std::cout << "\nBy Golden Hour Software\n";
    // }

    loggerInit();
    secmd();
    return 0;
}