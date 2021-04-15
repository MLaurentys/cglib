
#include "../cglib/include/game_concept.hpp"
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

namespace fs = std::filesystem;

bool does_compile(const std::string &programString) {
        auto file = std::tmpfile();
        // std::fputs(programString, file);
        std::fputs("Hello, world", file);
        std::rewind(file);
        char buf[6];
        std::fgets(buf, sizeof buf, file);
        std::cout << buf << '\n';

        // Linux-specific method to display the tmpfile name
        std::cout << fs::read_symlink(fs::path("/proc/self/fd") /
                                      std::to_string(fileno(file)))
                  << '\n';
        return true;
}

TEST(Concept, PrimitiveTypes) { does_compile("int main() {return 0;}"); }