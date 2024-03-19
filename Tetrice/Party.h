#pragma once
#include<iostream>
#include<conio.h>
#include<thread>
#include<Windows.h>
#include "Menu.h"
#include <chrono>
#include "Plateau.h"
typedef enum {
	ni,
	tetriste,
	tepatrice,
	tecontent,
	tavalide,
	Bonus
}party_type;



class Party
{
private:
	Plateau game_pieces ;
	Plateau next_pieces ;
	Plateau colors_heads[4];
	Plateau shapes_heads[4];

	int score = 0;
	std::chrono::seconds party_time = std::chrono::seconds(120);
	int i = 0;
	bool paused = false;
	bool exited = false;
	std::string player;
	bool using_cursor = false;
	party_type Type = ni;
public:
	Party(int choice) {
		system("cls");
		switch (choice)
		{
		case 1:
			Tetriste();
			break;
		case 2:
			std::cout << "Tépatrice";
			break;
		case 3:
			std::cout << "Técontent";
			break;
		case 4:
			std::cout << "Tavalidé";
			break;
		case 5:
			std::cout << "Bonus";
		default:
			break;
		}
		_getch();
	}
	Party(int choice,std::chrono::seconds dur) {
		this->party_time = dur;
		system("cls");
		switch (choice)
		{
		case 1:
			Tetriste();
			break;
		case 2:
			std::cout << "Tépatrice";
			break;
		case 3:
			std::cout << "Técontent";
			break;
		case 4:
			std::cout << "Tavalidé";
			break;
		case 5:
			std::cout << "Bonus";
		default:
			break;
		}
		_getch();
	}
	
	void pause_menu() {
		std::string options[] = {"Continue","Save Game","Exit"};
		Menu m(options, 3);
		int choice = m.get_choice();
		switch (choice)
		{
		case 1:
			paused = false;
			break;
		case 2:
			save_game();
			break;
		case 3:
			exited = true;
		default:
			break;
		}
	}
	void save_game() {
		
		std::cout << "\nDEBUGGING: Game was saved";
		exited = true;
		
		_getch();
	}
	int Tetriste() {
		this->Type = tetriste;
		//std::cout << "\nDEBUGGING: start";
		/*
			***tag : Wonderful Code .SOF.
			usual std::thread(func_name); didn't work 
		*/
		init_scene(1);
		std::thread thread_object(&Party::handle_input,this);
		int lig = 2;
		
		while (!exited)
		{
			while (!paused) {
				//player input 
				switch (_getch())
				{
				case 'g':
					//add right next_piece to game pieces 
					this->game_pieces.inserer_left(next_pieces.get_tail()->get_piece());
					// add it to the left of color and shape plates
					break;
				case 'd':
					//add right next_piece to game pieces 
					this->game_pieces.inserer_right(next_pieces.get_tail()->get_piece());
					// add it to the right of color and shape plates
					break;
				}
				this->next_pieces.supprimer_right();
				/*Menu::gotoxy(lig, ++lig, ' ');
				this->next_pieces.afficher(false);
				cout << " .. ";
				this->game_pieces.afficher(false);*/


				
				//update list and score delete triplets and all 
				 
				
				// and show it on the screen
				// wait for cursor 
				while (using_cursor){}
				using_cursor = true;
				// erase old game pieces from console and show new state
				Menu::gotoxy(2, 2, "                                    ");
				Menu::gotoxy(2, 2, ' ');
				//Menu::gotoxy(5, 5, "DEBUGGING: after afficher goto");
				game_pieces.afficher(false);
				//Menu::gotoxy(5, 6, "DEBUGGING: after afficher fasle");
				using_cursor = false;
				
				 
				
				// generatea  random node with random colors and shapes
				/*piece* next_piece = new piece(4, 4);*/
				this->next_pieces.inserer_left(piece(4, 4));
				while (using_cursor){}
				using_cursor = true;
				Menu::gotoxy(0, 0, "                  ");
				Menu::gotoxy(0, 0, " ");
				next_pieces.afficher(true);
				using_cursor = false;
			}

		}
		
		thread_object.join();
		std::cout << "\nDEBUGGING: tetris exit";
		_getch();
		return -1;
	}
	// next : L C
	void init_scene(int size,bool ai = false) {
		system("cls");
		//generated the waiting quee
		for (int i = 0; i <size; i++)
		{
			this->next_pieces.inserer_left(piece(4, 4));
		}
		//this->next_elements = new shape_node[i];
		Menu::gotoxy(0, 0, ' ');
		this->next_pieces.afficher(true);
	}
	
	void handle_input() {
		//start game & timer
		//std::chrono::seconds time_elapsed = std::chrono::seconds(0);
		std::chrono::system_clock::time_point old;
		while (!exited) {
			old = std::chrono::system_clock::now();
			
			while (!paused)
			{
				char in = _getch();
				if (in == 'p' || in == 'P')
				{
					this->paused = true;
				}
			}
			auto time_elapsed = std::chrono::system_clock::now() - old;
			auto time_rest = this->party_time - time_elapsed;
			this->party_time = std::chrono::duration_cast<std::chrono::seconds>(time_rest);
			//party_time = std::chrono::seconds(std::chrono::duration_cast<std::chrono::seconds > (party_time).count() - std::chrono::duration_cast<std::chrono::seconds>(this->party_time).count());
			//std::cout << "\nDEBUGGING: time elapsed since pause or start  : " << std::chrono::duration_cast<std::chrono::seconds>(time_elapsed).count();
			//std::cout << "\nDEBUGGING: time left calculated  out of 2mins  : " << std::chrono::duration_cast<std::chrono::seconds>(time_rest).count();
			//std::cout << "\nDEBUGGING: time left affected  out of 2mins  : " << std::chrono::duration_cast<std::chrono::seconds>(time_rest).count();
			//_getch();
			pause_menu();


		}
		//end game & timer
	}

};
/*
auto start = std::chrono::steady_clock().now();
		std::this_thread::sleep_for(std::chrono::seconds(5));
		auto end_duration = std::chrono::steady_clock().now() - start;  //clock point - clock point = duration ;
		std::cout <<"\nduration : " << end_duration.count();
*/


		//std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
/*
	durations stores a time
	std::chrono::seconds _seconds = std::chrono::seconds(5);
	std::chrono::seconds _days = std::chrono::hours(48);
	std::chrono::seconds _seconds1 = seconds(_days);
//okay to assign bigg to litlle but not the opposite unless with casting duration_cast<hours>(_seconds);


*/


////playing for example
				//if (!(i % 10))
				//	system("cls");
				//std::cout << "*";
				//std::this_thread::sleep_for(std::chrono::seconds(1));
				//i++;