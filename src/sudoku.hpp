/**
 * @file sudoku.hpp
 * @author Kamil Vojanec (xvojan00@stud.fit.vutbr.cz)
 * @brief Header file for sudoku game board
 * @version 0.1
 * @date 2019-08-10
 * 
 */

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
        void print_raw() const;

       
        /**
         * @brief Updates the board according to configuration string. Unacceptable changes will result in error
         * 
         * @param config Configuration string. See README.md for format
         * @return uint32_t Return code
         */
        uint32_t update_board(std::string config);

        /**
         * @brief Overload the array subscript operator for rows
         * 
         * @param row Row of an array
         * @return uint8_t* Pointer to returned row
         */
        std::vector<uint8_t> operator[](std::size_t row);
        const std::vector<uint8_t> operator[](std::size_t row) const;

    private:
        uint8_t m_columns;
        uint8_t m_rows;
        std::vector<uint8_t> m_board;
        uint32_t parse_string(std::string str);
};

