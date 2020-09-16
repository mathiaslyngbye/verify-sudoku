#ifndef SUDOKU_H
#define SUDOKU_H

#include <array>

class Sudoku
{
public:
    Sudoku( std::array<std::array<int,9>,9> );
    bool verify();
    void print();
private:
    bool verifyRow(int);
    bool verifyRows();
    bool verifyCol(int);
    bool verifyCols();
    bool verifyBox(int, int);
    bool verifyBoxes();
    std::array<std::array<int,9>,9> map;
};

#endif // SUDOKU_H
