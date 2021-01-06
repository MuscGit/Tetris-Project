#include "Game.h"
#include <windows.h>


Game::Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight) 	: mBoard{ pBoard }, mPieces{ pPieces }, mIO{ pIO }, mScreenHeight{ pScreenHeight }
{
	//This is problematic since two pointers are pointing to same object

	InitGame();
};

int Game::GetRand(int pA, int pB)
{
	return (rand() % (pB - pA + 1)) + pA; // Better to use <random> since this operation is not uniformly random + it assumes that pB<RAND_MAX
};

void Game::InitGame()
{
	//This method selects the first and next piece randomly. The next piece isshown to player and sets the position of the two pieces in blocks

		//Initialise random number generator
	srand((unsigned int)time(NULL));

	//First Piece
	mPiece = GetRand(0, 6);
	mRotation = GetRand(0, 3);
	mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
	mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

	//Second Piece
	mNextPiece = GetRand(0, 6);
	mNextRotation = GetRand(0, 3);
	mNextPosX = BOARD_WIDTH + 5;
	mNextPosY = 5;
};

void Game::CreateNewPiece()
{
	//New First Piece
	mPiece = mNextPiece;
	mRotation = mNextRotation;
	mPosX = mNextPosX;
	mPosY = mNextPosY;

	//Next Piece
	mNextPiece = GetRand(0, 6);
	mNextRotation = GetRand(0, 3);
};

void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{
	color mColor; //color of Block
	
	//obtain position on screen of block we want to draw.
	int mPixelsX = mBoard->GetXPosInPixels(pX);
	int mPixelsY = mBoard->GetYPosInPixels(pY);

	for (int i = 0; i < PIECE_BLOCKS; i++) {
		for (int j = 0; j < PIECE_BLOCKS; j++) {
			switch (mPieces->GetBlockType(pPiece, pRotation, pX, pY)) {
			case 1: mColor = GREEN; break;
			case 2: mColor = BLUE; break;
			}
			
			if (mPieces->GetBlockType(pPiece, pRotation, pX, pY) != 0)
				mIO->DrawRectangle(mPixelsX + i * BLOCK_SIZE, mPixelsY + j * BLOCK_SIZE,
					(mPixelsX + i * BLOCK_SIZE) + BLOCK_SIZE - 1, (mPixelsY + i * BLOCK_SIZE) + BLOCK_SIZE - 1, mColor);
		}
	}

};

void Game::DrawBoard()
{
	// Calculate the limits of the board in pixels  
	int mX1 = BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2)) - 1;
	int mX2 = BOARD_POSITION + (BLOCK_SIZE * (BOARD_WIDTH / 2));
	int mY = mScreenHeight - (BLOCK_SIZE * BOARD_HEIGHT);

	//Check vertical margin is not too small

	//Rectangles that delimit the Board
	mIO->DrawRectangle(mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);

	mIO->DrawRectangle(mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

	// Check that the horizontal margin is not to small


	//Draw the blocks that are already on board.
	mX1 += 1;
	for (int i = 0; i < BOARD_WIDTH; i++) {
		for (int j = 0; j < BOARD_HEIGHT; j++) {
			//This can be made faster if we store a variable that tells us which block is max block in board
			if (!mBoard->IsFreeBlock(i, j)) {
				if (!mBoard->IsFreeBlock(i, j))
					mIO->DrawRectangle(mX1 + i * BLOCK_SIZE,
						mY + j * BLOCK_SIZE,
						(mX1 + i * BLOCK_SIZE) + BLOCK_SIZE - 1,
						(mY + j * BLOCK_SIZE) + BLOCK_SIZE - 1,
						RED);
			}
		}
	}
};

void Game::DrawScene()
{
	DrawBoard();
	DrawPiece(mPosX, mPosY, mPiece, mRotation);
	DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
};