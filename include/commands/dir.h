#pragma once
// Recreates the Windows `dir` or GNU `ls`
#include "BuiltInCommands.h"


inline void dir(const PARAMETERS& param)
{
	std::cout << "Listing Directory for: " << currentDir.string() << "\n\n";
	for (const auto& entry : fs::directory_iterator(currentDir)) {
		std::cout << "\t" << entry.path().filename().string() << "\n";
	}
	std::cout << "\n";
}