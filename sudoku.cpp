#include "sudoku.h"

#include <iostream>

Sudoku::Sudoku( std::array<std::array<int,9>,9> _map)
{
    map = _map;
}

bool Sudoku::verify()
{
    if(verifyRows() && verifyCols() && verifyBoxes())
    {
        return true;
    }

    return false;
}

bool Sudoku::verifyRow(int row)
{
    int test[9] = {0};
    for(int col = 0; col < 9; col++)
    {
        test[map[row][col]-1]++;
    }

    for(int i = 0; i < 9; i++)
    {
        if(test[i] != 1)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::verifyRows()
{
    for(int row = 0; row < 9; row++)
    {
        if(!verifyRow(row))
        {
            std::cout << "Row " << row << " is invalid!" << std::endl;
            return false;
        }
    }
    return true;
}

bool Sudoku::verifyCol(int col)
{
    int test[9] = {0};
    for(int row = 0; row < 9; row++)
    {
        test[map[row][col]-1]++;
    }

    for(int i = 0; i < 9; i++)
    {
        if(test[i] != 1)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::verifyCols()
{
    for(int col = 0; col < 9; col++)
    {
        if(!verifyCol(col))
        {
            std::cout << "Column " << col << " is invalid!" << std::endl;
            return false;
        }
    }
    return true;
}

bool Sudoku::verifyBox(int m, int n)
{
    int test[9] = {0};
    for(int row = m*3; row < (m*3)+3; row++)
    {
        for(int col = n*3; col < (n*3)+3; col++)
        {
            test[map[row][col]-1]++;
        }
    }

    for(int i = 0; i < 9; i++)
    {
        if(test[i] != 1)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::verifyBoxes()
{
    for(int m = 0; m < 3; m++)
    {
        for(int n = 0; n < 3; n++)
        {
            if(!verifyBox(m,n))
            {
                std::cout << "Box [" << m << "][" << n << "] is invalid!" << std::endl;
                return false;
            }
        }
    }
    return true;
}

void Sudoku::print()
{
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            std::cout << map[row][col];
        }
        std::cout << std::endl;
    }
}
