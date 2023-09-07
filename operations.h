#ifndef BRAINFUCK_OPERATIONS_H
#define BRAINFUCK_OPERATIONS_H

#include "include.h"

namespace op::func
{
    void increment(int& currentCell);
    void decrement(int& currentCell);
    void plus(Tape& tape, const int& currentCell);
    void minus(Tape& tape, const int& currentCell);
    void output(const Tape& tape, const int& currentCell);
    void input(Tape& tape, const int& currentCell);
    void loopBegin(const Tape& tape, const int& currentCell, LTable& loopTable, int& pointer);
    void loopEnd(const Tape& tape, const int& currentCell, LTable& loopTable, int& pointer);
}

#endif
