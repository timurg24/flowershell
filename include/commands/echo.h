#pragma once
// Recreates the GNU echo program
#include "BuiltInCommands.h"

inline void echo(const PARAMETERS& param)
{
	for (std::string i : param) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}