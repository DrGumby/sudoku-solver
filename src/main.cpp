#include <iostream>
#include "sudoku.hpp"

int main() {
    std::cout << "Hello Easy C++ project!" << std::endl;

    Sudoku board("11__1/22__2/3__11/55555/66666");
    board.print_format();

    std::cout << static_cast<int>(board[1][0]) << std::endl;
}