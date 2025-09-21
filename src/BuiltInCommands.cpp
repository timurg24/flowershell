#include "BuiltInCommands.h"

// Include all the commands
#include "commands/echo.h"
#include "commands/dir.h"
#include "commands/help.h"
#include "commands/cd.h"
#include "commands/run.h"

std::unordered_map< std::string, COMMAND > commandMap;
fs::path currentDir;

void RegisterCommands() {
	// Get current location
	currentDir = fs::current_path();

	commandMap["echo"] = echo;
	commandMap["dir"] = dir;
	commandMap["help"] = help;
	commandMap["cd"] = cd;
	commandMap["run"] = run;
}