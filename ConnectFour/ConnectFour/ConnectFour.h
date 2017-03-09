#pragma once
#include "Grid.h"

//Forward declaration:
//It is neccessarry because we want to inherit from Grid 
//and use the player struct as template argument but it is not defined yet
struct player;

class ConnectFour : public grid::Grid<player*, 7, 6> {
	enum currentPlayer {
		e_playerOne = 0, e_playerTwo = 1
	};

public:
	struct player {
		std::string name;
	};

	typedef grid::Grid<player*, 7, 6> ConnectFourGrid;

	ConnectFour();
	~ConnectFour();

	void makeMove(int column);
	bool hasWon(int col, int row);

	void newGame();

private:
	player m_onTurn;
	player m_player[2];
};
