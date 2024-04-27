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

		

		void tetrice_draw(int x, int y);

		void show_scores();
		void setConsoleBufferSize(int width, int height);
		void setConsoleWindowSize(int width, int height);
		
		size_t trouverOccurrence(const std::string& chaine, const std::string& mot, int occurrence);
		void setConsoleBackgroundColor(int color);
		string* extractFileName();

		int countLines(const std::string& filename);

		string chooseNameFile();

		

};

