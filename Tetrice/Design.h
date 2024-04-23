#pragma once
#include "Plateau.h"
#include "piece.h"
#include <raylib.h>
class Design
{
private:
	float screenWidth = 1300.0f;
	float screenHeight = 700.0f;
	float rotation;
	bool paused = false;
	Font font;
	Plateau* nextFivePiece = new Plateau();
	Plateau game_pieces;
	Plateau colors_heads[4];
	Plateau shapes_heads[4];
public:
	Design();
	static float spaceLeft;
	static float spaceRight;
	void menu();
	void render();
	void drawPlateau(Plateau*);
	void drawNextPlateau(Plateau*);
	void drawPiece(piece p);
	void supprimer_left_sample(Plateau*);
	void merge(shape_node* arr[], int left, int mid, int right);
	void debug_copy(shape_node** tab, int size, shape_node** res);
	void decallage_gauche(int choice, int&);
	void userInput(int, int, int&);
	void scene(int timeRemaining);

	shape_node** create_gpi();
	shape_node** create_spi(int index);
	shape_node** create_cpi(int index);
	shape_node** mergeSort(shape_node* arr[], int left, int right);


	~Design();

};