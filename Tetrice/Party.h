#pragma once
#include<iostream>
#include<conio.h>
#include<thread>
#include<Windows.h>
#include "Menu.h"
#include <chrono>
#include "Plateau.h"
#include <string>
#include <fstream>
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
	//for saving 
	int saving_time=120;
public:
	Plateau get_game_pieces() {
		return game_pieces;
	}

	Party(int s, int time , int typ , Plateau P , Plateau next , Plateau HS[4], Plateau HC[4]) {
		score = s;
		saving_time = time;
		//party_time = std::chrono::seconds(time);
		Type = (party_type)typ;
		game_pieces = P;
		next_pieces = next;

		for (int i = 0; i < 4; i++) {
			shapes_heads[i] = HS[i];
			colors_heads[i] = HC[i];
		}

		init_scene(0, false, false, true);
		switch (typ)
		{
		case 1:
			Tetriste(true);
			break;
		case 2:
			std::cout << "Tepatrice";
			break;
		case 3:
			Tecontent(true);
			break;
		case 4:
			std::cout << "Tavalide";
			break;
		case 5:
			std::cout << "Bonus";
		default:
			break;
		}


	}
	Party(int choice) {
		system("cls");
		switch (choice)
		{
		case 1:
			Tetriste(false);
			break;
		case 2:
			std::cout << "Tepatrice";
			break;
		case 3:
			Tecontent(false);
			break;
		case 4:
			std::cout << "Tavalide";
			break;
		case 5:
			std::cout << "Bonus";
		default:
			break;
		}
		_getch();
	}
	//Party(int choice,std::chrono::seconds dur) {
	//	this->party_time = dur;
	//	system("cls");
	//	
	//	switch (choice)
	//	{
	//	case 1:
	//		Tetriste(false);
	//		break;
	//	case 2:
	//		std::cout << "Tepatrice";
	//		break;
	//	case 3:
	//		std::cout << "Tecontent";
	//		break;
	//	case 4:
	//		std::cout << "Tavalide";
	//		break;
	//	case 5:
	//		std::cout << "Bonus";
	//	default:
	//		break;
	//	}
	//	_getch();
	//}
	
	void pause_menu(bool ai =false,bool score = false) {
		std::string options[] = {"Continue","Save Game","Exit"};
		Menu m(options, 3);
		int choice = m.get_choice();
		switch (choice)
		{
		case 1:
			paused = false;
			system("cls");
			init_scene(0, ai, score , false);
			Menu::gotoxy(2, 2, ' ');
			//Menu::gotoxy(5, 5, "DEBUGGING: after afficher goto");
			game_pieces.afficher(false);
			
			break;
		case 2:
			save_game();
			break;
		case 3:
			paused = true;
			exited = true;
		default:
			break;
		}
	}
	void save_game() {
		std::string file_name;
		system("cls");
		std::cout << "\nWhat would you like to call your game: ";
		std::cin >> file_name;
		file_name += ".json";
				
		{
			// Ouverture du fichier JSON en mode écriture
			std::ofstream file(file_name);

			// Vérification que le fichier a bien été ouvert
			if (file.is_open()) {
				std::string Json;
				Json = "{\n\t\"Party\":{\n\t\t\"Type\":"+to_string((int)Type) + ",\n\t\t\"Timer\":" + to_string(saving_time) + ",\n\t\t\"score\":" + to_string(score) + ",\n\t\t\"Next\""+next_pieces.PlateauToJson()+",\n\t\t\"Plateau\"";
				Json += game_pieces.PlateauToJson() + ',';
				string shapes[4] = { "\"Cercle\"","\"Rhombus\"","\"Square\"","\"Triangle\"" };
				Json += "\n\t\t\t\"ShapesHeads\":[\n";
				for (int i = 0; i < 4; i++) {
					Json += "\t\t\t\t{\t\t\t\t\n\t\t\t\t" + shapes[i] + shapes_heads[i].ShapesToJson() + ",\n";
				}
				Json.pop_back();
				Json.pop_back();
				Json += "\n\t\t\t],";



				Json += "\n\t\t\t\"colorHeads\":[\n";
				string color[4] = { "\"Red\"","\"Green\"","\"Yellow\"","\"Blue\"" };
				for (int i = 0; i < 4; i++) {
					Json +="\t\t\t\t{\t\t\t\t\n\t\t\t\t" + color[i] + colors_heads[i].ColorsToJson() + ",\n";
				}
				Json.pop_back();
				Json.pop_back();
				Json += "\n\t\t\t]\n\t}\n}";
				file << Json;

				std::cout << "Game Was Saved" << std::endl;

				// Fermeture du fichier
				file.close(); 
			}
			else {
				std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
			}



		}
	
		saveNameFile(file_name);

		

		afterSaveGame();
	}





	int Tecontent(bool render_at_first) {
		this->Type = tecontent;
		//std::cout << "\nDEBUGGING: start";
		/*
			***tag : Wonderful Code .SOF.
			usual std::thread(func_name); didn't work
		*/
		init_scene(1,false,true , render_at_first);
		std::thread thread_object(&Party::handle_time, this);

		while (!exited)
		{
			while (!paused) {
				////////////////////////////////////////////////
				///    handle player input and upadates      ///
				///////////////////////////////////////////////
				player_action(false,true,true);

				//evaluate plate and delete triplets

				//update list and score delete triplets and all 


				// and show it on the screen



				////////////////////////////////////////////
				///    Render game pieces in scene      ///
				///////////////////////////////////////////
				while (using_cursor) {}
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
				while (using_cursor) {}
				using_cursor = true;
				Menu::gotoxy(0, 0, "                  ");
				Menu::gotoxy(0, 0, " ");
				next_pieces.afficher(true);
				using_cursor = false;

				/////////////////////////////////////////////////////
				///      render the colors and shapes lists       ///
				/////////////////////////////////////////////////////
				render_colorsANDshapes();

				
			}

		}

		thread_object.join();
		std::cout << "\nDEBUGGING: tetris exit";
		_getch();
		return -1;
	}
	void chose_decallage() {
		Menu::gotoxy(0, 4, "Chose a color or a shape :\n");
		// print options 
		Menu::gotoxy(0, 5, ' ');
		cout << "\033[31m"<<"RED   "<< "\033[0m"<< "\033[32m"<<" GREEN "<< "\033[0m"<< "\033[33m"<<" YELLOW" << "\033[0m" << "\033[34m"<<" BLUE  " << "\033[0m"<<" CERCLE"<<" RHOMBU"<<" SQUARE"<<" TRIANGLE";

		char in = 'a';
		int choice = 0;
		Menu::gotoxy(0, 5, '>');
		do
		{
			in = _getch();
			if (in == 77 && choice < 7) {
				Menu::gotoxy(choice*7, 5, ' ');
				Menu::gotoxy(++choice * 7, 5, '>');
			}
			else if(in == 75 && choice > 0)
			{
				Menu::gotoxy(choice * 7, 5, ' ');
				Menu::gotoxy(--choice * 7, 5, '>');
			}

		} while (in != 'e');
		//Just check
		/*Menu::gotoxy(0, 12, "choice=");
		std::cout << choice;*/
		Menu::gotoxy(0, 4, "                                            \n                                                                           ");
		/*
		note to saad :
		switch based on choice :
		0 => decallage rouge;
		1 => decallage vert;
		2 => decallage jaune;
		3 => decallage blue;
		4 => decallage cercle;
		5 => decallage losange;
		6 => decallage carre ;
		7 => decallage triangle;
		
		*/

		switch (choice)
		{
		case (int)Red-1:
			this->game_pieces.decalage_colors(Red, shapes_heads, colors_heads);
			break;
		case (int)Green-1:
			this->game_pieces.decalage_colors(Green, shapes_heads, colors_heads);
			break;
		case (int)Yellow-1:
			this->game_pieces.decalage_colors(Yellow, shapes_heads, colors_heads);
			break;
		case (int)Blue-1:
			this->game_pieces.decalage_colors(Blue, shapes_heads, colors_heads);
			break;
		
		case (int)Cercle+3:
			this->game_pieces.decalage_shapes(Cercle, shapes_heads, colors_heads);
			break;
		case (int)Rhombus+3:
			this->game_pieces.decalage_shapes(Rhombus, shapes_heads, colors_heads);
			break;
		case (int)Square+3:
			this->game_pieces.decalage_shapes(Square, shapes_heads, colors_heads);
			break;
		case (int)Triangle+3:
			this->game_pieces.decalage_shapes(Triangle, shapes_heads, colors_heads);
			break;
		default:
			break;
		}
		
	}
	int Tetriste(bool render_at_first) {
		this->Type = tetriste;
		//std::cout << "\nDEBUGGING: start";
		/*
			***tag : Wonderful Code .SOF.
			usual std::thread(func_name); didn't work 
		*/
		init_scene(1, false, false , render_at_first);
		std::thread thread_object(&Party::handle_time,this);
		
		while (!exited)
		{
			while (!paused) {
				////////////////////////////////////////////////
				///    handle player input and upadates      ///
				///////////////////////////////////////////////
				player_action(false,false,false);

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
				render_colorsANDshapes();
				
				
			}

		}
		
		thread_object.join();
		std::cout << "\nDEBUGGING: tetris exit";
		_getch();
		return -1;
	}
	void render_colorsANDshapes() {
		Menu::gotoxy(0, 3 + 6, "                                    ");
		Menu::gotoxy(0, 4 + 6, "                                    ");
		Menu::gotoxy(0, 5 + 6, "                                    ");
		Menu::gotoxy(0, 6 + 6, "                                    ");
		Menu::gotoxy(0, 7 + 6, "                                    ");
		Menu::gotoxy(0, 8 + 6, "                                    ");
		Menu::gotoxy(0, 9 + 6, "                                    ");
		Menu::gotoxy(0, 16, "                                    ");
		Menu::gotoxy(0, 17, "                                    ");
		Menu::gotoxy(0, 18, "                                    ");
		Menu::gotoxy(0, 9, "____________colors___________\n");
		for (int i = 0; i < 4; i++)
		{

			shape_node* tmp = colors_heads[i].get_head();
			shape_node* tail = colors_heads[i].get_tail();
			do
			{
				if (tmp)
				{
					tmp->get_piece().afficher();
					tmp = tmp->get_next_color();
				}

			} while (tmp != colors_heads[i].get_head());
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

			} while (tmp != shapes_heads[i].get_head());
			cout << endl;
		}
	}

	void player_action(bool ai = false,bool dec = false,bool score = false) {
		int index_c = (int)(next_pieces.get_tail()->get_piece().get_color() - 1);
		int index_sh = (int)(next_pieces.get_tail()->get_piece().get_shape() - 1);

		// add while to enter either g or d and ignore the other inputs 
		char choice = 'a';
		do {
			using_cursor = true;
			choice = _getch();
			switch (choice)
			{
			case 'p': 
				paused = true;
				pause_menu(ai,score);
				break;
			case 'd':
				if (!dec)
				{
					chose_decallage();
				}
				break;
			default:
				break;
			}
			using_cursor = false;	
		} while (choice != 75 && choice != 77 );
		switch (choice)
		{
		case 75:
			//add right next_piece to game pieces 
			this->game_pieces.inserer_left(next_pieces.get_tail()->get_piece());
			// add it to the left of color and shape plates
			this->colors_heads[index_c].inserer_left_colors(&this->game_pieces, next_pieces.get_tail()->get_piece());
			this->shapes_heads[index_sh].inserer_left_shapes(&this->game_pieces, next_pieces.get_tail()->get_piece());
			this->score += this->game_pieces.supprimer3_left(&colors_heads, &shapes_heads);
			break;
		case 77:
			//add right next_piece to game pieces 
			this->game_pieces.inserer_right(next_pieces.get_tail()->get_piece());
			// add it to the right of color and shape plates
			this->colors_heads[index_c].inserer_right_colors(&this->game_pieces, next_pieces.get_tail()->get_piece());
			this->shapes_heads[index_sh].inserer_right_shapes(&this->game_pieces, next_pieces.get_tail()->get_piece());
			this->score += this->game_pieces.supprimer3_right(&(this->colors_heads), &(this->shapes_heads));

			break;
			
		}
		this->next_pieces.set_size(next_pieces.get_size() - 1);
		shape_node* prv = next_pieces.get_head();
		while (prv->get_next() != next_pieces.get_tail()) {
			prv = prv->get_next();
		}
		next_pieces.set_tail(prv);
		delete prv->get_next();
	}
	// next : L C
	void init_scene(int size,bool ai ,bool score , bool render_at_first ) {
		system("cls");
		if (render_at_first) {

			while (using_cursor) {}
			using_cursor = true;
			// erase old game pieces from console and show new state
			Menu::gotoxy(2, 2, "                                          ");
			Menu::gotoxy(2, 2, ' ');
			//Menu::gotoxy(5, 5, "DEBUGGING: after afficher goto");
			game_pieces.afficher(false);

			//Menu::gotoxy(5, 6, "DEBUGGING: after afficher fasle");
			using_cursor = false;
		}

		Menu::gotoxy(Menu::timer_x, Menu::timer_y, "                                                    ");
		
		Menu::gotoxy(0, Menu::timer_y - 1, ' ');
		cout << "Time :";
		if (score)
		{
		Menu::gotoxy(14, Menu::timer_y - 1, ' ');
		cout << "Score : " << this->score;
		}
		//generated the waiting quee
		if (!render_at_first) {
			for (int i = 0; i < size; i++)
			{
				this->next_pieces.inserer_left(piece(4, 4));
			}
		}
		//this->next_elements = new shape_node[i];
		Menu::gotoxy(0, 0, ' ');
		this->next_pieces.afficher(true);
	}
	
	
	void handle_time() {
		//start game & timer
		//std::chrono::seconds time_elapsed = std::chrono::seconds(0);
		std::chrono::system_clock::time_point old;
		int time = saving_time;
		while (!exited) {
			old = std::chrono::system_clock::now();

			while (!paused)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				
				Menu::gotoxy(Menu::timer_x, Menu::timer_y-1, "     ");
				Menu::gotoxy(Menu::timer_x, Menu::timer_y-1,' ');
				cout << --time;
				saving_time--;
				//saving_time = time;
				if (this->Type != tetriste && this->Type != tepatrice)
				{
					Menu::gotoxy(14, Menu::timer_y - 1, ' ');
					cout << "Score : " << this->score;
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
			/*pause_menu();*/


		}
		//end game & timer
	}


	void saveNameFile(std::string filename) {
		std::ifstream file("savedPartiesNames.txt");
		if (file.is_open()) {
			std::string data;
			std::string line;
			while (getline(file, line)) {
				data += line + "\n"; // Ajout du saut de ligne
			}
			file.close();

			int pos = data.find(filename);
			if (pos == std::string::npos) {
				std::ofstream outFile("savedPartiesNames.txt", std::ios::app); // Ouverture en mode ajout
				data = filename + "\n"; // Ajout du saut de ligne
				outFile << data; // Écriture des données dans le fichier
				outFile.close();
			}
		}
		else {
			std::ofstream newFile("savedPartiesNames.txt");
			newFile.close();
			saveNameFile(filename);
		}
	}

	 void afterSaveGame() {
		 string options[2] = {"Restart","Exit"};
		 Menu m(options, 2);
		 int choice = m.get_choice();

		 switch (choice) {
		 case 1:
			 std::cout << "Restart the game" << std::endl;
			break;
		 case 2:
			 exited = true;
			 break;
		 default:
			 break;
		 }


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