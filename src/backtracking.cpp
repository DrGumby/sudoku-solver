#include "backtracking.hpp"

Backtracking::Backtracking(Sudoku *game) : m_man(game), m_sudoku(game) {
}

std::pair<int32_t, int32_t> Backtracking::find_next_empty() {
    for (int32_t i = 0; i < m_sudoku->get_rows(); i++) {
        for (int32_t j = 0; j < m_sudoku->get_columns(); j++) {
            if (m_sudoku->get_value(i, j) == 0) {
                return std::make_pair(i,j);
            }
        }
    }
    return std::make_pair(-1,-1);
}

bool Backtracking::backtrack() {
    std::pair<int32_t, int32_t> matrix_idx;

    matrix_idx = find_next_empty();
    if (matrix_idx == std::pair{-1, -1})
        return true;

    for (uint8_t i = 1; i <= 9; i ++) {
        if (m_man.is_correct_field(matrix_idx.first, matrix_idx.second, i)) {
            m_sudoku->set_value(matrix_idx.first, matrix_idx.second, i);
            if (backtrack())
                return true;
            
            m_sudoku->set_value(matrix_idx.first, matrix_idx.second, 0);
        }
    }
    return false;
}

