// Board.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Board.h"


// This is an example of an exported variable
BOARD_API int nBoard=0;

// This is an example of an exported function.
BOARD_API int fnBoard(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see Board.h for the class definition
CBoard::CBoard()
{
    return;
}
