/**
 * @file sudoku.hpp
 * @author Kamil Vojanec (xvojan00@stud.fit.vutbr.cz)
 * @brief Header file for sudoku game board
 * @version 0.1
 * @date 2019-08-10
 * 
 */

#include <iostream>

class Sudoku
{
    public:
        /**
         * @brief Construct a new Sudoku object with empty data
         */
        Sudoku();
        /**
         * @brief Construct a new Sudoku object with data
         * 
         * @param init_config Configuration string. See README.md for format
         */
        Sudoku(std::string init_config);
        /**
         * @brief Destroy the Sudoku object
         */
        ~Sudoku();

        /**
         * @brief Prints formatted Sudoku board
         */
        void print_format() const;

        /**
         * @brief Prints Sudoku board as string in the same format as the constructor accepts. See README.md for format
         */
        void print_raw() const;

        /**
         * @brief Set the field to given value
         * 
         * @param row Row coordinate of the field
         * @param col Column coordinate of the field
         * @param val Value to set the field (1 - 9)
         * @return uint32_t Return code
         */
        uint32_t update_field(uint8_t row, uint8_t col, uint8_t val);

        /**
         * @brief Updates the board according to configuration string. Unacceptable changes will result in error
         * 
         * @param config Configuration string. See README.md for format
         * @return uint32_t Return code
         */
        uint32_t update_board(std::string config);

        /**
         * @brief Get the value at field
         * 
         * @param row Row coordinate of field
         * @param col Column coordinate of field
         * @return uint8_t value at field
         */
        uint8_t get_field(uint8_t row, uint8_t col) const;

};