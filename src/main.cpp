#include <iostream>
#include "sudoku.hpp"
#include "manipulator.hpp"
#include "backtracking.hpp"

int main() {

    Sudoku board("9___6___3/1_5_932_6/_4__5___9/8_____471/__487____/7_26_1__8/2________/5___32_94/_87_1635_");


    Manipulator man(&board);


    Backtracking bt(&board);
    bt.backtrack();
    board.print_format();
}