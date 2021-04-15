#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

namespace compile_check {
bool does_compile(const std::string &programString) {
        auto file = std::tmpfile();
}
// std::unique_ptr<std::FILE> file;
}; // namespace compile_check