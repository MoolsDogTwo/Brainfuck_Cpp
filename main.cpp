#include "include.h"
#include "syntax.h"
#include "operations.h"
#include "etc.h" // Printing & checking

std::string loadProgram(Path& path, File& file)
{
    if (fs::exists(path))
    {
        if (path.extension() == ".bf")
        {
            std::clog << std::format("'{}' file opened successfully!\n",
                                     path.generic_string());
            std::stringstream read{};
            read << file.rdbuf();
            return read.str();
        }
        else
        {
            std::cerr << std::format("'{}' is not a valid Brainfuck program.",
                                     path.generic_string());
            return "null";
        }
    }
    std::cerr << std::format("'{}' file does not exist.",
                             path.generic_string());
    return "null";
}

void handleCases(Tape& tape, Program program, int& currentCell,
                        int& pointer, LTable& loopTable)
{
    switch (program[pointer])
    {
        case op::increment:
            op::func::increment(currentCell);
            break;

        case op::decrement:
            op::func::decrement(currentCell);
            break;

        case op::plus: op::func::plus(tape, currentCell);
            break;

        case op::minus:
            op::func::minus(tape, currentCell);
            break;

        case op::output:
            op::func::output(tape, currentCell);
            break;

        case op::input:
            op::func::input(tape, currentCell);
            break;
        case op::loopBegin:
            op::func::loopBegin(tape, currentCell, loopTable, pointer);
            break;

        case op::loopEnd:
            op::func::loopEnd(tape, currentCell, loopTable, pointer);
            break;

        default:
            break;
    }
}

void getLoops(std::string_view program, LStack& loopStack, LTable& loopTable)
{
    for (int i{}; i < program.length(); ++i)
    {
        if (program[i] == op::loopBegin)
        {
            loopStack.push(i);
        }
        else if (program[i] == op::loopEnd)
        {
            u8 loopBeginIndex{ loopStack.top() };
            loopStack.pop();
            loopTable[loopBeginIndex] = i;
            loopTable[i] = loopBeginIndex;
        }
    }
}

void interpreter(std::string_view program)
{
    Tape tape{ 0 };
    size_t programSize{ program.size() };
    int pointer{};
    int currentCell{};

    LStack loopStack{};
    LTable loopTable{};

    getLoops(program, loopStack, loopTable);

    while (pointer < programSize)
    {
        handleCases(tape, program, currentCell, pointer, loopTable);
        ++pointer;
    }
}


int main(int argc, const char** argv)
{
    if (!checkArgs(argc))
        return 1;

    Path filePath{ argv[1] };
    File file{ filePath };
    std::string program{ loadProgram(filePath, file) };
    if (program == "null")
        return 1;
    interpreter(program);
    return 0;
}
