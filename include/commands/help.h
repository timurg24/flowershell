#pragma once
// Displays help information about the program

#include "BuiltInCommands.h"


inline void help(const PARAMETERS& param)
{
	std::cout << "Listing avaliable commands:" << "\n\n";
    for (const auto& [key, value] : commandMap) {
        std::cout << "\t" << key << "\n";
    }
	std::cout << "\n";
}