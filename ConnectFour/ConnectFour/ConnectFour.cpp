// ConnectFour.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "ConnectFour.h"
#include "Printer.h"
//conio.h is a windows library (used for getch())
#include <conio.h>
//Used for Sleep()
#include <Windows.h>

ConnectFour::ConnectFour()
{
}

//Suppresses the warning 4150 only for the destructor
#pragma warning(push)
#pragma warning( disable : 4150)
ConnectFour::~ConnectFour()
{
	for (int iCol = 0; iCol < COLUMN_SIZE; iCol++) {
		for (int iRow = 0; iRow < ROW_SIZE; iRow++) {
			if (m_grid[iRow][iCol] != nullptr)
				delete m_grid[iRow][iCol];
		}
	}
}
#pragma warning(pop)

void ConnectFour::makeMove(int column)
{
	//if the column is full return
	if (m_grid[0][column] != nullptr)
		return;

	for (int iRow = 0; iRow < ROW_SIZE; iRow++) {
		if (m_grid[iRow][column] != nullptr) {
			iRow--;
			m_grid[iRow][column] = &m_player[m_onTurn];
			m_isFinished = hasWon(column, iRow);
			break;
		}

		if (iRow == ROW_SIZE - 1) {
			m_grid[iRow][column] = &m_player[m_onTurn];
			m_isFinished = hasWon(column, iRow);
		}
	}

	if (!m_isFinished) {
		if (m_onTurn == e_playerOne)
			m_onTurn = e_playerTwo;
		else
			m_onTurn = e_playerOne;
	}
}

bool ConnectFour::hasWon(int col, int row)
{
	return checkHorizontal(col, row) || checkVertical(col, row) || checkDiagonalRL(col, row) || checkDiagonalLR(col, row);
}

void ConnectFour::newGame()
{
	//Initialite the Grid with nullptr because no player set a stone yet
	for (int iCol = 0; iCol < COLUMN_SIZE; iCol++) {
		for (int iRow = 0; iRow < ROW_SIZE; iRow++) {
			m_grid[iRow][iCol] = nullptr;
		}
	}

	m_player[e_playerOne] = player();
	m_player[e_playerOne].id = e_playerOne;
	m_player[e_playerTwo] = player();
	m_player[e_playerTwo].id = e_playerTwo;

	std::cout << "Enter a name for player one:" << std::endl;
	std::cin >> m_player[e_playerOne].name;
	m_player[e_playerOne].symbol = 'X';
	std::cout << std::endl << "Enter a name for player two:" << std::endl;
	std::cin >> m_player[e_playerTwo].name;
	m_player[e_playerTwo].symbol = 'O';

	m_onTurn = e_playerOne;
}

ConnectFour::currentPlayer ConnectFour::onTurn()
{
	return m_onTurn;
}

void ConnectFour::print()
{
	Printer::print(m_grid);
}

std::string ConnectFour::getPlayerName(currentPlayer e_player)
{
	return m_player[e_player].name;
}

bool ConnectFour::checkHorizontal(int col, int row)
{
	int stones = 1;
	int curPlayer = m_grid[row][col]->id;

	for (int iPos = col - 1; iPos >= 0; iPos--) {
		if (m_grid[row][iPos] != nullptr && m_grid[row][iPos]->id == curPlayer)
			stones++;
		else
			break;
	}
	for (int iPos = col + 1; iPos < (int)m_grid[row].size(); iPos++) {
		if (m_grid[row][iPos] != nullptr && m_grid[row][iPos]->id == curPlayer)
			stones++;
		else
			break;
	}

	if (stones == 4)
		return true;
	else
		return false;
}

bool ConnectFour::checkVertical(int col, int row)
{
	int stones = 1;
	int curPlayer = m_grid[row][col]->id;

	for (int iPos = row - 1; iPos >= 0; iPos--) {
		if (m_grid[iPos][col] != nullptr && m_grid[iPos][col]->id == curPlayer)
			stones++;
		else
			break;
	}
	for (int iPos = row + 1; iPos < (int)m_grid.size(); iPos++) {
		if (m_grid[iPos][col] != nullptr && m_grid[iPos][col]->id == curPlayer)
			stones++;
		else
			break;
	}

	if (stones == 4)
		return true;
	else
		return false;
}

bool ConnectFour::checkDiagonalRL(int col, int row)
{
	int stones = 1;
	int curPlayer = m_grid[row][col]->id;

	int iCol = col + 1, iRow = row - 1;

	while (iCol < (int)m_grid[0].size() && iRow >= 0) {
		if (m_grid[iRow][iCol] != nullptr && m_grid[iRow][iCol]->id == curPlayer)
			stones++;
		else
			break;
		iCol++;
		iRow--;
	}

	iCol = col - 1;
	iRow = row + 1;

	while (iCol >= 0 && iRow < (int)m_grid.size()) {
		if (m_grid[iRow][iCol] != nullptr && m_grid[iRow][iCol]->id == curPlayer)
			stones++;
		else
			break;
		iCol--;
		iRow++;
	}

	if (stones == 4)
		return true;
	else
		return false;
}

bool ConnectFour::checkDiagonalLR(int col, int row)
{
	int stones = 1;
	int curPlayer = m_grid[row][col]->id;

	int iCol = col - 1, iRow = row - 1;

	while (iCol >= 0 && iRow >= 0) {
		if (m_grid[iRow][iCol] != nullptr && m_grid[iRow][iCol]->id == curPlayer)
			stones++;
		else
			break;
		iCol--;
		iRow--;
	}

	iCol = col + 1;
	iRow = row + 1;

	while (iCol < (int)m_grid[0].size() && iRow < (int)m_grid.size()) {
		if (m_grid[iRow][iCol] != nullptr && m_grid[iRow][iCol]->id == curPlayer)
			stones++;
		else
			break;
		iCol++;
		iRow++;
	}

	if (stones == 4)
		return true;
	else
		return false;
}

int main()
{
	std::cout << "Welcome to ConnectFour what do you wish to do?" << std::endl;
	std::cout << "[s] Start a new game\n[q] quit" << std::endl;
	char choice = _getch();
	
	while (choice != 's' && choice != 'q') {
		std::cout << "Sorry '" << choice << "' is not a valid option please try again..." << std::endl << std::endl;
		choice = _getch();
	}
	
	switch (choice) {
	case 's': std::cout << "You started a new game!" << std::endl; break;
	case 'q': return 0;
	//(optional) default catches all cases which are not covered by the 'case' above
	default: break;
	}

	ConnectFour* connectFour = new ConnectFour();
	
	//-> is neccassry because connectFour is a pointer and has to be dereferenced before we can access the object
	connectFour->newGame();

	std::cout << std::endl << "Be prepared! The game starts in..." << std::endl;
	for (int iCount = 5; iCount > 0; iCount--) {
		Sleep(600);
		std::cout << iCount << std::endl;
	}

	int column;
	while (!connectFour->isFinished()) {
		//cls is the windows command to clear the screen of a command prompt
		system("cls");

		connectFour->print();
		std::cout << std::endl << "Press [7] to quit [8] to start a new game" << std::endl;
		std::cout << "Player " << static_cast<int>(connectFour->onTurn() + 1);
		std::cout << " (" << connectFour->getPlayerName(connectFour->onTurn()) << ")" << " is on turn. ";
		std::cout << std::endl << "Please choose a column..." << std::endl;
		std::cin >> column;

		while (std::cin.fail() || column < 0 || column > 8) {
			std::cout << "Not a valid number! Try again..." << std::endl;
			//For only one statement after an if there are no brackets needed
			if(std::cin.fail())
				std::cin.clear();
			std::cin.ignore();
			std::cin >> column;
		}

		if (column == 7) {
			connectFour->newGame();
			continue;
		}
		if (column == 8) {
			return 0;
		}

		connectFour->makeMove(column);
	}

	system("cls");
	connectFour->print();

	std::cout << std::endl << "Congratulations " << connectFour->getPlayerName(connectFour->onTurn()) << " you won!" << std::endl;

	system("pause");
	
	return 0;
}