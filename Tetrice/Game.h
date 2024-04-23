#pragma once
#include <iostream>
#include <conio.h>
#include<chrono>
#include<thread>
#include<Windows.h>
#include "Menu.h"
#include "Party.h"

class Game
{
private:
	bool playing = true;

public:
	Game();
	void show_start_menu();

	void show_difficulty_menu();
	void new_game();
	void load_games();
	void show_scores();




};