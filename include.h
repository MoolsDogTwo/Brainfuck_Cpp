#ifndef BRAINFUCK_INCLUDE_H
#define BRAINFUCK_INCLUDE_H

#include <iostream>
#include <string>
#include <stack>
#include <array>
#include <cstdint>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <format>
#include <unordered_map>

namespace fs = std::filesystem;
using File = std::fstream;
using Path = const fs::path;
using Program = std::string_view;
using u8 = std::uint8_t;
using LStack = std::stack<u8>;
using LTable = std::unordered_map<u8, u8>;

inline constexpr int tapeSize{ 30000 };
using Tape = std::array<u8, tapeSize>;

#endif
