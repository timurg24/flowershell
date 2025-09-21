#pragma once

#include <iostream>
#include <string>
#include <vector>

#include <functional>
#include <unordered_map>

#include <filesystem>

namespace fs = std::filesystem;

using PARAMETERS	= std::vector<std::string>;
using COMMAND		= std::function<void(const PARAMETERS&)>;


// BUILT IN COMMANDS
void echo(const PARAMETERS& param);

// GLOBAL VARIABLES
extern std::unordered_map< std::string, COMMAND > commandMap;
extern fs::path currentDir;


// REGISTER COMMANDS
void RegisterCommands();


