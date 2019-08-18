#include "manipulator.hpp"
#include <math.h>

Manipulator::Manipulator(Sudoku *game) {
    if (game == nullptr) {
        throw "NULL";
    }
    m_sudoku = game;
}

bool Manipulator::is_correct_field(std::size_t row, std::size_t col, uint8_t val) const {
    std::size_t fld;
    std::size_t square_x;
    std::size_t square_y;

    
    // If element at given coordinates is zero, we do not need to continue
    if ((val == 0) && (m_sudoku->get_value(row, col) == 0)){
        return true;
    }

    // Check row
    for (fld = 0; fld < m_sudoku->get_columns(); fld++) {
        if(fld == col) continue;
        // If val is not set, use the sudoku board
        if (val == 0){
            if (m_sudoku->get_value(row, fld) == 0) continue;
            if (m_sudoku->get_value(row, fld) == m_sudoku->get_value(row, col)) {
                return false;
            }
        }
        else {
            if (m_sudoku->get_value(row, fld) == 0) continue;
            if (m_sudoku->get_value(row, fld) == val) {
                return false;
            }
        }
    }

    // Check column
    for (fld = 0; fld < m_sudoku->get_rows(); fld++) {
        if (fld == row) continue;
        // Check if val is set
        if (val == 0) {
            if (m_sudoku->get_value(fld, col) == 0) continue;
            if (m_sudoku->get_value(fld, col) == m_sudoku->get_value(row, col)) {
                return false;
            }
        }
        else {
            if (m_sudoku->get_value(fld, col) == 0) continue;
            if (m_sudoku->get_value(fld, col) == val) {
                return false;
            }
        }
    }

    // Create little squares 3x3
    square_x = (col / 3) * 3;
    square_y = (row / 3) * 3; 
    for (std::size_t i = square_x; i < square_x+3; i++) {
        for (std::size_t j = square_y; j < square_y+3; j++) {
            if (j == row && i == col) continue;
            if (val == 0) {
                if (m_sudoku->get_value(j, i) == 0) continue;
                if (m_sudoku->get_value(j, i) == m_sudoku->get_value(row, col)) {
                    return false;
                }
            } else {
                if (m_sudoku->get_value(j, i) == 0) continue;
                if (m_sudoku->get_value(j, i) == val) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool Manipulator::is_correct_state() const {
    for (std::size_t row = 0; row < m_sudoku->get_rows(); row ++) {
        for (std::size_t col = 0; col < m_sudoku->get_columns(); col++) {
            if (!is_correct_field(row, col)){
                return false;
            }
        }
    }
    return true;
}

bool Manipulator::is_full() const {
    for (std::size_t i = 0; i < m_sudoku->get_rows(); i++) {
        for (std::size_t j = 0; j < m_sudoku->get_columns(); j++) {
            if (m_sudoku->get_value(i, j) == 0) {
                return false;
            }
        }
    }
    return true;
}