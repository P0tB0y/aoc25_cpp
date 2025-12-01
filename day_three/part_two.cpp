#include <filesystem>
#include <fstream>
#include <print>

auto main(int argc, char** argv) -> int {
    auto path{std::filesystem::current_path()};
    auto input_file_name{std::string_view{"input.txt"}};
    if (argc == 1) {
        std::println("Missing CLI argument\nLooking for '{}' in current working dir", input_file_name);
        path /= input_file_name;
    }
    if (argc == 2) {
        path /= argv[1];
    }

    auto file{std::ifstream{path}};
    if (!file.is_open()) {
        std::println("File could not be opened. Usage: ./{} {}", argv[0], input_file_name);
        return -1;
    }
}
