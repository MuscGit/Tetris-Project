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
	//pPos: Horizontal position (in blocks) of block on the board
	return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)))) + (pPos * BLOCK_SIZE);
};

int Board::GetYPosInPixels(int pPos) {
	//pPos: Horizontal position (in blocks) of block on the board
	return  ((mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pPos * BLOCK_SIZE);
};

bool Board::IsFreeBlock(int pX, int pY) {
	if (mBoard[pX][pY] == POS_FREE)
		return true;
	else
		return false;
};

bool Board::IsPossibleMovement(int pX, int pY, int pPiece, int pRotation) {
	/*Checks if movement of piece is possible or not. The method compares all blocks of a piece with the blocks already stored in the board with the board limits. 
	Comparison done by iterating through piece matrix and compare with appropraite 5x5 area in the board. If collision it returns false.
	*/


	};

void Board::StorePiece(int pX, int pY, int pPiece, int pRotation) {
	/*
	pX: Horizontal position in blocks
	pY: Vertical position in blocks
	pPiece: Piece to draw
	pRotation: 1 of 4 possible rotations
	*/
	for (int i1 = pX, i2 = 0; i1 < pX + PIECE_BLOCKS; i1++, i2++) {
		for (int j1 = pY, j2 = 0; j1 < pY + PIECE_BLOCKS; j1++, j2++) {
				if (mPieces->GetBlockType(pPiece, pRotation, j2, i2) != 0)
					mBoard[i1][j1] = POS_FILLED;
		}
	}

};

void Board::DeletePossibleLines() {
	//Delete all lines that should be removed.

	for (int j = 0; j < BOARD_HEIGHT; j++) {
		int i = 0;
		while (i < BOARD_WIDTH) {
			if (mBoard[i][j] != POS_FILLED) break;
			i++;
		}
		if (i == BOARD_WIDTH) DeleteLine(j);
	}
};


//If this method is used often instead we can add a new arraywhich checks whether there is any block in that row as a member variable. This can then be used in delete line.
bool Board::IsGameOver() {
	for (int i = 0; i < BOARD_WIDTH; i++) {
		if (mBoard[i][0] = POS_FILLED)
			return true;
	}

	return false;
};