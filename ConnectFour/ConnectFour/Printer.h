#pragma once
#include "ConnectFour.h"

class Printer
{
	
public:
	//print() get a reference to a ConnectFourGrid so the object won't be copied when the function is called
	template < typename T >
	static void print(std::vector<std::vector<T>>& grid);
};


template<typename T>
void Printer::print(std::vector<std::vector<T>>& grid)
{
	std::cout << std::endl << std::endl << std::endl;
	std::cout << " 0 1 2 3 4 5 6 " << std::endl;
	//A vector in C++ has a size() function instead of an array which length can not be determined at runtime
	for (int iRow = 0; iRow < (int)grid.size(); iRow++) {
		for (int iCol = 0; iCol < (int)grid[iRow].size(); iCol++) {
			std::cout << "|";
			if (grid[iRow][iCol] != nullptr)
				//Never use something like this! Your code crashes if T has no member 'symbol'
				std::cout << grid[iRow][iCol]->symbol;
			else
				std::cout << " ";
		}
		std::cout << "|" << std::endl;
		std::cout << std::string(grid[0].size() * 2  , '_') << std::endl;
	}
}
