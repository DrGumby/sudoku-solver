#pragma once
#include "manipulator.hpp"
#include "sudoku.hpp"
#include <stack>

struct bt_elem {
    int32_t row;
    int32_t col;
    int8_t val;
    bool checked;
};

class Backtracking {

public:
    Backtracking(Sudoku *game);
    //~Backtracking();
    bool backtrack();
public:
    Manipulator m_man;
    Sudoku *m_sudoku;
    std::pair<int32_t, int32_t> find_next_empty();

};