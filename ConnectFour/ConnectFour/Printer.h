#pragma once
#include "ConnectFour.h"

class Printer
{
	
public:
	//print() get a reference to a ConnectFourGrid so the object won't be copied when the function is called
	static void print(ConnectFour::ConnectFourGrid grid);
};

void Printer::print(ConnectFour::ConnectFourGrid grid)
{
	std::cout << std::endl << std::endl << std::endl;
	std::cout << " 0 1 2 3 4 5 6 " << std::endl;
	//A vector in C++ has a size() function instead of an array which length can not be determined at runtime
	for (int iRow = 0; iRow < (int)grid.size(); iRow++) {
		for (int iCol = 0; iCol < (int)grid[iRow].size(); iCol++) {
			std::cout << "|";
			if (grid[iRow][iCol] != nullptr)
				std::cout << grid[iRow][iCol]->symbol;
			else
				std::cout << " ";
		}
		std::cout << "|" << std::endl;
		std::cout << std::string(grid[0].size() * 2  , '_') << std::endl;
	}
}
