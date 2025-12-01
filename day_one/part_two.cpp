#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>

struct Rotation {
    enum class Direction { Left, Right };

    Direction direction{Direction::Left};
    int count{0};

    friend auto operator>>(std::istream& is, Rotation& rot) -> std::istream& {
        auto input{char()};
        auto number{0};
        is >> input >> number;

        if (input == 'R') {
            rot.direction = Rotation::Direction::Right;
        } else {
            rot.direction = Rotation::Direction::Left;
        }
        rot.count = number;

        return is;
    }
};

class Lock {
  public:
    auto rotate(const Rotation& rot) {
        auto step{rot.count};

        if (step > 100) {
            zero_count += (step / 100);
            step %= 100;
        }

        bool is_zero{current_number == 0};

        switch (rot.direction) {
            using enum Rotation::Direction;
        case Left: current_number -= step; break;
        case Right: current_number += step; break;
        }
        if ((!is_zero && current_number < 0) || current_number > 100) {
            zero_count++;
        }

        current_number %= 100;
        if (current_number < 0) {
            current_number += 100;
        }

        if (current_number == 0) {
            zero_count++;
        }
    }

    int zero_count{0};
    int current_number{50};
};

auto main(int argc, char** argv) -> int {
    auto path{std::filesystem::current_path()};
    if (argc == 1) {
        auto input_file_name{std::string_view{"input.txt"}};
        std::println("Missing CLI argument\nLooking for '{}' in current working dir", input_file_name);
        path /= input_file_name;
    }
    if (argc == 2) {
        path /= argv[1];
    }

    auto file{std::ifstream{path}};
    if (!file.is_open()) {
        std::println("File could not be opened. Usage: ./{} input.txt", argv[0]);
        return -1;
    }

    auto rotation{Rotation{}};
    auto lock{Lock{}};

    while (file >> rotation) {
        lock.rotate(rotation);
    }

    std::println("output: {}", lock.zero_count);
}
