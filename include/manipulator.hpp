#pragma once

#include "sudoku.hpp"

class Manipulator {

public:
    /**
     * @brief Construct a new Manipulator object
     * 
     * @param game Reference to sudoku object
     */
    Manipulator(Sudoku *game);
    //~Manipulator();

    bool is_correct_state() const;
    bool is_correct_field(std::size_t row, std::size_t col, uint8_t val = 0) const;
    bool is_full() const;


private:
    Sudoku *m_sudoku;

};