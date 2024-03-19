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
		Game() {
			system("cls");
			std::cout << "Welcome to game press any key to continue ...";
			_getch();
			while (playing)
			{
			show_start_menu();
			//gui 
			//fonction
			}
		}
		void grapghic_u_i() {
			

		}
		void show_start_menu() {
			
			std::string options[] = { "New Game","Load a Game","Best Scores","Exit"};
			
			Menu m(options,4);
			int choice = m.get_choice();
			switch (choice)
			{
			case 1:
				show_difficulty_menu();
				break;
			case 2:
				load_games();
				break;
			case 3:
				show_scores();
				break;
			case 4:
				playing = false;
			default:
				break;
			}
			/*system("cls");
			std::cout << " a. New Game .\n b. Load a Game.\n c. Best Scores.\n e. Exit.";
			*/


		}
		
		void show_difficulty_menu() {
			std::string options[] = { "Tétriste","Tépatrice","Técontent","Tavalidé","Bonus"};

			Menu m(options, 5);
			Party party(m.get_choice());
			
		}
		void new_game() {
			system("cls");
			std::cout <<std::endl<< "this is a new game,we should be able to chose the difficulty";
			_getch();
		}
		void load_games() {
			system("cls");
			std::cout <<std::endl<< "this is a load games,we should be able to chose a record";
			_getch();
		}
		void show_scores() {
			system("cls");
			std::cout <<std::endl<< "this is a show game scores,we should be able to show best 10 scores";
			_getch();
		}
		



};

