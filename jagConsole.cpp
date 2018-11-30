#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

int main()
{
	// Text to teal
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,3);

	std::string version_number = "DEV-BUILD 0.1.0"; // Version number

	// Prints out the raw text ignoring all the escape characters.
	std::cout << R"(
      _ _      _____                      _      
     | (_)    / ____|                    | |     
   __| |_ ___| |     ___  _ __  ___  ___ | | ___ 
  / _` | / __| |    / _ \| '_ \/ __|/ _ \| |/ _ \
 | (_| | \__ \ |___| (_) | | | \__ \ (_) | |  __/
  \__,_|_|___/\_____\___/|_| |_|___/\___/|_|\___|
                                                 )" << std::endl << std::endl;

	printf("Version %s\n", version_number.c_str());

	std::string userInput = "";
	bool cont = true;
	std::string ui;

	SetConsoleTextAttribute(hConsole, 15);

	while (cont) {
		commands:
		if (userInput == "") {
			std::cout << std::endl << "> ";
		}
		ui = _getche();
		if (ui == "\r") {
			std::cout << std::endl;
			if (userInput == "version") {
				printf("%s\n", version_number.c_str());
				userInput = "";
				goto commands;
			}
			else if (userInput == "exit") {
				SetConsoleTextAttribute(hConsole, 12);
				exit(0);
			}
			else {
				std::cout << "Please enter a valid command.\n";
				userInput = "";
				continue;
			}
			break;
		}
		else {
			userInput.append(ui);
		}
	}	

}
