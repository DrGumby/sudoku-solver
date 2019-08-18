/**
 * @file sudoku.cpp
 * @author Kamil Vojanec (xvojan00@stud.fit.vutbr.cz)
 * @brief Implemetation of general sudoku game board
 * @version 0.1
 * @date 2019-08-10
 */

#include "sudoku.hpp"
#include <algorithm>
#include <string>

Sudoku::Sudoku() : m_board(9*9, 0) {
    // Initialize variables
    m_columns = 9;
    m_rows    = 9;
}

Sudoku::Sudoku(uint8_t size) : m_board(size*size, 0) {
    // Initialize variables
    m_columns = size;
    m_rows    = size;
}

std::size_t get_row_length(std::string str) {
    return str.find('/');
}

uint32_t Sudoku::parse_string(std::string str) {
    std::size_t row_length;
    std::size_t row = 0;
    std::size_t col = 0;

    // Remove whitespace from string 
    str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end());
    
    // Find the width of board
    row_length = get_row_length(str);
    if (row_length != 6 && row_length != 9) {
        throw "Unsuppoerted";
    }
    // Set both variables because the board bust be a square
    m_columns = row_length;
    m_rows    = row_length;

    // Loop through the string and parse it
    for (auto &&i : str) {
        
        if (i == '/') {
            // Check if all rows are the same length
            if (col != row_length) {
                throw "Invalid length";
            }
            row++;
            col = 0;
        }
        // Check the char is bethween 1 and size
        if (i >= '1' && i <= static_cast<int64_t>(row_length)+'0') {
            m_board.at(row * row_length + col) = i - '0';
            col++;
        }
        
        // Finally, check for empty fields
        if (i == '_') {
            m_board.at(row * row_length + col) = 0;
            col++;
        }
    }

    // Check if board has the same number of rows and columns
    if (row != row_length-1) {
        throw "Invalid rows and columns";
    }

    return 0;
}

// Initialize the vector and then parse string into it
Sudoku::Sudoku(std::string init_config) : m_board(get_row_length(init_config)*get_row_length(init_config), 0) {
    parse_string(init_config);
}

std::string Sudoku::get_raw() const {
    // Initialize empty string
    std::string str{};

    // Loop throuth all elements in vector
    for (uint32_t i = 0; i < m_board.size(); i++) {
        // Check end of line
        if (i % m_columns == 0 && i != 0) {
            str += "/";
        }

        // Check missing value
        if (m_board.at(i) == 0) {
            str += "_";
        }
        else if (m_board.at(i) > 0) {
            str += m_board.at(i)+'0';
        }
    }
    return str;
}

// Prints horizontal border based on the specified number of fields for numbers
std::string get_border_horizontal(std::size_t fields) {
    std::string str{};
    // Each field is 4 characters long
    for (uint32_t i = 0; i < fields*4; i++) {
        if ((i % 4) == 0) {
            str += '+';
        }
        else {
            str += '-';
        }
    }
    // Append the last '+' character and return
    str += '+';
    return str;
}

void Sudoku::print_format() const {
    /* The format is as follows

    +---+---+---+---+
    | 1 | 2 | 3 | 4 |
    +---+---+---+---+
    ...
    */
    std::string border = get_border_horizontal(m_rows);

    for (uint32_t i = 0; i < m_board.size(); i++) {
        if((i % m_columns) == 0) {
            if (i != 0) {
                std::cout << "|" << std::endl;
            }
            std::cout << border << std::endl;
        }
        std::cout << "| " << static_cast<int>(m_board.at(i)) << " ";
    }
    std::cout << "|" << std::endl;
    std::cout << border << std::endl;
}

void Sudoku::set_value(uint8_t row, uint8_t col, uint8_t val) {
    m_board.at(row*m_columns+col) = val;
}

uint8_t Sudoku::get_value(uint8_t row, uint8_t col) const {
    return m_board.at(row*m_columns+col);
}

uint32_t Sudoku::update_board(std::string config) {
    std::size_t row_length;

    row_length = get_row_length(config);
    if (row_length != m_columns) {
        throw "INVALID LENGTH";
    }

    parse_string(config);
    return 0;
}