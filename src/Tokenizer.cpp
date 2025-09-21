#include "Tokenizer.h"

TokenLine TokenizeString(std::string input)
{
    input += '\n';
    std::string acc;
    TokenLine result;

    bool isParam = false;

    for (char c : input) {
        if (c == ' ' || c == '\n') {
            if (!isParam) { // Acc is a function 
                result.command = acc;
                acc = "";
                isParam = true;
            }
            else { // Acc is a parameter
                result.values.push_back(acc);
                acc.clear();
            }
        }
        else {
            acc += c;
        }
    }

    return result;
}

void PrintTokenLine(TokenLine line)
{
    std::cout << "[Command: " << line.command << "]\n";
    for (std::string value : line.values) {
        std::cout << "[Command" << value << "]\n";
    }
}
