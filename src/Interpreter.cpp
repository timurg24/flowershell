#include "Interpreter.h"

bool InterpretTokenLine(TokenLine line)
{
    bool success = false;
    for (const auto& [key, value] : commandMap) {
        if (line.command == key) {
            commandMap[line.command](line.values);
            success = true;
        }
        else continue;
    }
    
    if(!success) {
        std::cout << "\nError Detected:\n\"" << line.command << "\" is not a recognized command\n\n";
    }

    return success;
}
