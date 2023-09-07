#include "operations.h"

namespace op::func
{
    void increment(int& currentCell)
    {
        ++currentCell;
    }

    void decrement(int& currentCell)
    {
        --currentCell;
    }

    void plus(Tape& tape, const int& currentCell)
    {
        ++tape[currentCell];
    }

    void minus(Tape& tape, const int& currentCell)
    {
        --tape[currentCell];
    }

    void output(const Tape& tape, const int& currentCell)
    {
        putchar(tape[currentCell]);
    }

    void input(Tape& tape, const int& currentCell)
    {
        tape[currentCell] = getchar();
    }

    void loopBegin(const Tape& tape, const int& currentCell, LTable& loopTable, int& pointer)
    {
        if (!tape[currentCell])
            pointer = loopTable[pointer];
    }

    void loopEnd(const Tape& tape, const int& currentCell, LTable& loopTable, int& pointer)
    {
        if (tape[currentCell])
            pointer = loopTable[pointer];
    }
}
