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

int Game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{
	return 0;
};

void Game::DrawBoard()
{
};

void Game::DrawScene()
{
};