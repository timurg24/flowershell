#pragma once
#include <iostream>
#include <vector>
#include <string>


struct TokenLine {
	std::string command;
	std::vector<std::string> values;
};

TokenLine TokenizeString(std::string input);
void PrintTokenLine(TokenLine line);