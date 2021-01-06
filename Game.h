#ifndef _GAME_
#define _GAME_

#include <stdlib.h>
#include "Board.h"
#include "Pieces.h"
#include <time.h>
#include "IO.h"

#define WAIT_TIME 700 //number of millisecs that piece remains before going one block down

class Game {

public:
	Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight);

	void DrawScene();
	void CreateNewPiece();

	int mPosX, mPosY;				//Position of Piece that is falling down
	int mPiece, mRotation;			//Kind and Rotation that is falling down

private:
	int mScreenHeight;				//Screen Height in Pixels
	int mNextPosX, mNextPosY;		//Position of the Next Piece
	int mNextPiece, mNextRotation;	//Type and Rotation of Next Piece

	Board* mBoard;
	Pieces* mPieces;
	IO* mIO;

	int GetRand(int pA, int pB);
	void InitGame();
	void DrawPiece(int pX, int pY, int pPiece, int pRotation);
	void DrawBoard();
};

#endif _GAME_
