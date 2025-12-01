#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>
#include <ranges>

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
        using enum Rotation::Direction;

        switch (rot.direction) {
            using enum Rotation::Direction;
        case Left: m_current_number -= rot.count; break;
        case Right: m_current_number += rot.count; break;
        }

        m_current_number = (m_current_number + 100) % 100;

        if (m_current_number == 0) {
            m_zero_count++;
        }
    }

    auto zero_count() -> int { return m_zero_count; }

  private:
    int m_zero_count{0};
    int m_current_number{50};
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

    auto lock{Lock{}};

    for (const auto& rotation : std::views::istream<Rotation>(file)) {
        lock.rotate(rotation);
    }

    std::println("output: {}", lock.zero_count());
}
