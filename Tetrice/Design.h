#pragma once
#include "raylib.h"
#include "Plateau.h"
#include "piece.h"
class Design
{
private:
	int screenWidth;
	int screenHeight;
	float rotation;
public:
	Design();
	void render(Plateau*);
	void drawPlateau(Plateau*);
	void drawPiece(piece p);
	~Design();

};
