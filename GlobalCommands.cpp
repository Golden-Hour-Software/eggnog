#include <iostream>
#include <string>
#include <filesystem>
#include "GlobalCommands.h"
#include "GlobalDefinitions.h"

int ValidCmdNum = 4;

std::vector<std::string> SystmCmdList_Eggnog { "help_eggnog", "exit" };

std::vector<std::string> HelpDescList_Eggnog { "Gives you an eggnog command list.", "Exits eggnog." };

std::string Generic_Bad = "This command has not been implemented yet.";


int cmd_help()
{
	IsCustomCommandRun = true;
	for (int i = 0; i < ValidCmdNum; i++) {
		std::cout << SystmCmdList_Eggnog[i] << ": " << HelpDescList_Eggnog[i] << "\n";
	}
	return 0;
}