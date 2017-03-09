#pragma once
#include "Grid.h"

#define COLUMN_SIZE 7
#define ROW_SIZE 6

struct player {
	//structs can have their own constructor and destructor
	player() {}
	~player() {}

	operator std::string() {
		return symbol + "";
	}

	int id;
	std::string name;
	char symbol;
};

class ConnectFour : public grid::Grid<player*, COLUMN_SIZE, ROW_SIZE> {
	enum currentPlayer {
		e_playerOne = 0, e_playerTwo = 1
	};

public:
	typedef const std::vector<std::vector<player*>>& ConnectFourGrid;

	ConnectFour();
	~ConnectFour();

	void makeMove(int column);
	//Functions can be implemented in the header file but they shouldn't.
	//The compiler copys and compiles this function in every other file which includes this header file
	//It contains an implicit 'inline' keyword
	bool isFinished() { return m_isFinished; }
	bool hasWon(int col, int row);
	void newGame();
	currentPlayer onTurn();
	void print();
	std::string getPlayerName(currentPlayer e_player);

private:
	currentPlayer m_onTurn;
	ConnectFour::player m_player[2];
	bool m_isFinished = false;

	bool checkHorizontal(int col, int row);
	bool checkVertical(int col, int row);
	bool checkDiagonalRL(int col, int row);
	bool checkDiagonalLR(int col, int row);
};
