#include "etc.h"
#include <iostream>

/* This is just a bunch of stuff that I threw out of the main file.
 * They're just basically just auxiliary functions.*/

void printTape(Tape& tape, int size)
{
    if (size < 1)
        std::cerr << "Error in printTape(), Inappropriate size supplied.\n";
    else if (size > 30000)
        std::cerr << "Error in printTape(), Cannot print above tape size.\n";

    for (int i{}; i < size; ++i)
        std::cout << static_cast<int>(tape[i]) << ' ';
    std::cout << '\n';
}

bool checkArgs(int argc)
{
    if (argc > 2)
    {
        std::cerr << "Err: Cannot operate on more than 1 file.\n";
        return false;
    }
    else if (argc < 2)
    {
        std::cerr << "Err: No file provided.\n";
        return false;
    }
    return true;
}
