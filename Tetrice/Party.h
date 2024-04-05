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
			std::cout << "T�patrice";
			break;
		case 3:
			std::cout << "T�content";
			break;
		case 4:
			std::cout << "Tavalid�";
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
			std::cout << "T�patrice";
			break;
		case 3:
			std::cout << "T�content";
			break;
		case 4:
			std::cout << "Tavalid�";
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
		std::thread thread_object(&Party::handle_time,this);
		int lig = 2;
		
		while (!exited)
		{
			while (!paused) {
				////////////////////////////////////////////////
				///    handle player input and upadates      ///
				///////////////////////////////////////////////
				player_action();

				//evaluate plate and delete triplets
		
				//update list and score delete triplets and all 
				 
				
				// and show it on the screen
				


				////////////////////////////////////////////
				///    Render game pieces in scene      ///
				///////////////////////////////////////////
				while (using_cursor){}
				using_cursor = true;
				// erase old game pieces from console and show new state
				Menu::gotoxy(2, 2, "                                          ");
				Menu::gotoxy(2, 2, ' ');
				//Menu::gotoxy(5, 5, "DEBUGGING: after afficher goto");
				game_pieces.afficher(false);
				//Menu::gotoxy(5, 6, "DEBUGGING: after afficher fasle");
				using_cursor = false;



				
				 
				
				/////////////////////////////////////////////////////
				///    Render and update  next pieces in scene    ///
				/////////////////////////////////////////////////////
				this->next_pieces.inserer_left(piece(4, 4));
				while (using_cursor){}
				using_cursor = true;
				Menu::gotoxy(0, 0, "                  ");
				Menu::gotoxy(0, 0, " ");
				next_pieces.afficher(true);
				using_cursor = false;




				/////////////////////////////////////////////////////
				///      render the colors and shapes lists       ///
				/////////////////////////////////////////////////////
		
				/*Menu::gotoxy(3, 3, "                                    ");
				Menu::gotoxy(3, 4, "                                    ");
				Menu::gotoxy(3, 5, "                                    ");
				Menu::gotoxy(3, 6, "                                    ");
				Menu::gotoxy(3, 7, "                                    ");
				Menu::gotoxy(3, 8, "                                    ");
				Menu::gotoxy(3, 9, "                                    ");
				Menu::gotoxy(3, 10, "                                    ");
				Menu::gotoxy(3, 3, "____________colors___________\n");
				for (int i = 0; i < 4; i++)
				{
					
					shape_node * tmp = colors_heads[i].get_head();
					shape_node* tail = colors_heads[i].get_tail();
					do
					{
						if (tmp)
						{
							tmp->get_piece().afficher();
							tmp = tmp->get_next_color();
						}
						
					} while (tmp != tail);
					cout << endl;
				}
				cout << "______________sahpes____________\n";
				for (int i = 0; i < 4; i++)
				{
					shape_node* tmp = shapes_heads[i].get_head();
					do
					{
						if (tmp)
						{
							tmp->get_piece().afficher();
							tmp = tmp->get_next_shape();
						}

					} while (tmp != shapes_heads[i].get_tail());
					cout << endl;
				}*/
			}

		}
		
		thread_object.join();
		std::cout << "\nDEBUGGING: tetris exit";
		_getch();
		return -1;
	}

	void player_action() {
		int index_c = (int)(next_pieces.get_tail()->get_piece().get_color() - 1);
		int index_sh = (int)(next_pieces.get_tail()->get_piece().get_shape() - 1);

		// add while to enter either g or d and ignore the other inputs 
		char choice;
		do {
			if (using_cursor)
			{
				while(using_cursor){}
				
			}
			else
			{
				using_cursor = true;
				choice = _getch();
				using_cursor = false;
			}
			
			
		} while (choice != 75 && choice != 77 && choice != 'p' && choice != 'd');
		switch (choice)
		{
		case 77:
			//add right next_piece to game pieces 
			this->game_pieces.inserer_left(next_pieces.get_tail()->get_piece());
			// add it to the left of color and shape plates
			this->colors_heads[index_c].inserer_left_colors(&this->game_pieces, next_pieces.get_tail()->get_piece());
			this->shapes_heads[index_sh].inserer_left_shapes(&this->game_pieces, next_pieces.get_tail()->get_piece());
			break;
		case 75:
			//add right next_piece to game pieces 
			piece tmp_p = next_pieces.get_tail()->get_piece();
			this->game_pieces.inserer_right(tmp_p);
			// add it to the right of color and shape plates
			this->colors_heads[index_c].inserer_right_colors(&this->game_pieces, next_pieces.get_tail()->get_piece());
			this->shapes_heads[index_sh].inserer_right_shapes(&this->game_pieces, next_pieces.get_tail()->get_piece());

			break;
		}
		this->next_pieces.supprimer_right();
	}
	// next : L C
	void init_scene(int size,bool ai = false) {
		system("cls");
		Menu::gotoxy(Menu::timer_x, Menu::timer_y, "                                                    ");
		
		Menu::gotoxy(0, Menu::timer_y - 1, ' ');
		cout << "Time :";
		Menu::gotoxy(14, Menu::timer_y - 1, ' ');
		cout << "Score : 0000";
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
				char in = 'c';
				while (using_cursor)
				{

				}
				using_cursor = true;
				in = _getch();
				using_cursor = false;
				
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

	void handle_time() {
		//start game & timer
		//std::chrono::seconds time_elapsed = std::chrono::seconds(0);
		std::chrono::system_clock::time_point old;
		int time = 120;
		while (!exited) {
			old = std::chrono::system_clock::now();

			while (!paused)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				
				Menu::gotoxy(Menu::timer_x, Menu::timer_y-1, "     ");
				Menu::gotoxy(Menu::timer_x, Menu::timer_y-1,' ');
				cout << --time;
				
				
			}
			auto time_elapsed = std::chrono::system_clock::now() - old;
			auto time_rest = this->party_time - time_elapsed;
			this->party_time = std::chrono::duration_cast<std::chrono::seconds>(time_rest);
			//party_time = std::chrono::seconds(std::chrono::duration_cast<std::chrono::seconds > (party_time).count() - std::chrono::duration_cast<std::chrono::seconds>(this->party_time).count());
			//std::cout << "\nDEBUGGING: time elapsed since pause or start  : " << std::chrono::duration_cast<std::chrono::seconds>(time_elapsed).count();
			//std::cout << "\nDEBUGGING: time left calculated  out of 2mins  : " << std::chrono::duration_cast<std::chrono::seconds>(time_rest).count();
			//std::cout << "\nDEBUGGING: time left affected  out of 2mins  : " << std::chrono::duration_cast<std::chrono::seconds>(time_rest).count();
			//_getch();
			/*pause_menu();*/


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