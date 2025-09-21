#pragma once
// Allows you to change directories
#include "BuiltInCommands.h"


inline void cd(const PARAMETERS& param)
{
    if (param.empty()) { std::cout << "\ncd: Parameters are empty!\n\n"; return; }
    
    fs::path updatedPath;

    if (fs::path(param[0]).is_absolute()) {
        updatedPath = fs::path(param[0]);
    }
    else {
        updatedPath = currentDir / param[0];
    }

    updatedPath = updatedPath.lexically_normal();

    if (fs::exists(updatedPath) && fs::is_directory(updatedPath)) {
        currentDir = updatedPath;
    }
    else {
        std::cout << "cd: no such directory: " << param[0] << "\n";
    }

}