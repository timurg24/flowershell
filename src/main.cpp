// FlowerShell.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Tokenizer.h"
#include "Interpreter.h"

int main()
{
	std::cout << "****************\nFlowerShell\nVersion 1.0.0\n****************\n";
	std::string input;
	RegisterCommands();
	for (;;) {
		std::cout << ">> ";
		std::getline(std::cin, input);
		TokenLine line = TokenizeString(input);
		InterpretTokenLine(line);
	}
}