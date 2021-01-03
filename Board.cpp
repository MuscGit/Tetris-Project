// Includes:
#include "Board.h"

Board::Board(Pieces* pPieces, int pScreenHeight) : mPieces{ pPieces }, mScreenHeight{ pScreenHeight } {
};

void Board::InitBoard() {
	for (int i = 0; i < BOARD_WIDTH; i++)
		for (int j = 1; j < BOARD_HEIGHT; j++)
			mBoard[i][j] = POS_FREE;
};

void Board::DeleteLine(int pY) {
	//This can be improved by not going through all of board
	
	for (int j = pY; j > 0; j--)
		for (int i = 0; i < BOARD_WIDTH; i++)
			mBoard[i][j] = mBoard[i][j - 1];
};

int Board::GetXPosInPixels(int pPos) {
};

int Board::GetYPosInPixels(int pPos) {
};

bool Board::IsFreeBlock(int pX, int pY) {
	if (mBoard[pX][pY] == POS_FREE)
		return true;
	else
		return false;
};

bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation) {
};

void Board::StorePiece(int pX, int pY, int pPiece, int pRotation) {

};

void Board::DeletePossibleLines() {
};


//If this method is used often instead we can add a new arraywhich checks whether there is any block in that row as a member variable. This can then be used in delete line.
bool Board::IsGameOver() {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		if (mBoard[i][0] = POS_FILLED)
			return true;
	}

	return false;
};