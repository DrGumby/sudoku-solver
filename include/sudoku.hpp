/**
 * @file sudoku.hpp
 * @author Kamil Vojanec (xvojan00@stud.fit.vutbr.cz)
 * @brief Header file for sudoku game board
 * @version 0.1
 * @date 2019-08-10
 * 
 */

#pragma once
#include <iostream>
#include <vector>

class Sudoku
{
    public:
        /**
         * @brief Construct a new Sudoku object with empty data. Size is 9x9
         */
        Sudoku();
        /**
         * @brief Construct a new Sudoku object with given size
         * 
         * @param size Size of the board. Eg. 4x4, 9x9 etc.
         */
        Sudoku(uint8_t size);
        /**
         * @brief Construct a new Sudoku object with data
         * 
         * @param init_config Configuration string. See README.md for format
         */
        Sudoku(std::string init_config);
        /**
         * @brief Destroy the Sudoku object
         */
        //~Sudoku();

        /**
         * @brief Prints formatted Sudoku board
         */
        void print_format() const;

        /**
         * @brief Prints Sudoku board as string in the same format as the constructor accepts. See README.md for format
         */
        std::string get_raw() const;

       
        /**
         * @brief Updates the board according to configuration string. Unacceptable changes will result in error
         * 
         * @param config Configuration string. See README.md for format
         * @return uint32_t Return code
         */
        uint32_t update_board(std::string config);

        /**
         * @brief Get the columns object
         * 
         * @return  uint8_t 
         */
        uint8_t get_columns() const {return m_columns;};

        /**
         * @brief Get the rows object
         * 
         * @return  uint8_t 
         */
        uint8_t get_rows() const {return m_rows;};

        /**
         * @brief Set the value object
         * 
         * @param row Row to be inserted
         * @param col Column to be inserted
         * @param val Value to be inserted
         */
        void set_value(uint8_t row, uint8_t col, uint8_t val);

        /**
         * @brief Get the value object
         * 
         * @param row Row of searched field
         * @param col Column of searched field
         * @return uint8_t Value of field
         */
        uint8_t get_value(uint8_t row, uint8_t col) const;

    private:
        uint8_t m_columns;
        uint8_t m_rows;
        std::vector<uint8_t> m_board;
        uint32_t parse_string(std::string str);
};

