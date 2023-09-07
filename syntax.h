#ifndef BRAINFUCK_SYNTAX_H
#define BRAINFUCK_SYNTAX_H

namespace op
{
    inline constexpr char increment{ '>' };
    inline constexpr char decrement{ '<' };
    inline constexpr char plus{ '+' };
    inline constexpr char minus{ '-' };
    inline constexpr char output{ '.' };
    inline constexpr char input{ ',' };
    inline constexpr char loopBegin{ '[' };
    inline constexpr char loopEnd{ ']' };
}

#endif
