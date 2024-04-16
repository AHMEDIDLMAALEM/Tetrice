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
			// gui 
			// function
			}
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
			std::string options[] = { "Tetriste","Tepatrice","Tecontent","Tavalide","Bonus"};

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
			/*Menu::gotoxy(1, 0, ' ');
			std::cout << ">" << std::endl;
			_getch();*/
			std::cout << "this is a load games,we should be able to chose a record" << std::endl;

			
			string filename=chooseNameFile();
						

			// Ouvrir le fichier JSON
			ifstream file(filename);

			// Vérifier si le fichier est ouvert correctement
			if (!file.is_open()) {
				cerr << "Erreur: Impossible d'ouvrir le fichier." << endl;
				return;
			}

			// Lire le contenu du fichier dans une chaîne
			string json_data;
			string line;
			while (getline(file, line)) {
				json_data += line;
			}

			// Fermer le fichier après la lecture
			file.close();

			// Parsing des données JSON
			Plateau game, Next, HS[4], HC[4];


			size_t pos = json_data.find("\"Type\":");
			int Type = stoi(json_data.substr(pos + 7, json_data.find(',', pos) - pos - 7));

			pos = json_data.find("\"Timer\":");
			int party_time = stoi(json_data.substr(pos + 8, json_data.find(',', pos) - pos - 8));

			pos = json_data.find("\"score\":");
			int score = stoi(json_data.substr(pos + 8, json_data.find(',', pos) - pos - 8));

			
			pos = trouverOccurrence(json_data, "\"size\":", 1);
			int size_next_pieces = stoi(json_data.substr(pos + 7, json_data.find(',', pos) - pos - 7));
			pos = json_data.find("\"Pieces\":");
			pos = json_data.find('[', pos);
			size_t end_pos = json_data.find(']', pos);
			string pieces_data = json_data.substr(pos, end_pos - pos + 1);

			// lire next
			pos = pieces_data.find("{");
			int index = 0;
			for (int i = 0; i < size_next_pieces ; i++) { // Assurer de ne pas dépasser la taille maximale
				piece piece;
				size_t end_piece_pos = pieces_data.find('}', pos);
				string piece_data = pieces_data.substr(pos, end_piece_pos - pos + 1);

				size_t shape_pos = piece_data.find("\"shape\":");
				piece.set_shape((shape)stoi(piece_data.substr(shape_pos + 8, piece_data.find(',', shape_pos) - shape_pos - 8)));

				size_t color_pos = piece_data.find("\"color\":");
				piece.set_color((shape_color)stoi(piece_data.substr(color_pos + 8, piece_data.find('}', color_pos) - color_pos - 8)));
				Next.inserer_left(piece);
				

				pos = pieces_data.find("{", end_piece_pos);
			}





			// Extraction des données pour "Plateau"
			pos = json_data.find("\"Plateau\":");
			pos = trouverOccurrence(json_data, "\"size\":", 2);
			int size_plateau_pieces = stoi(json_data.substr(pos + 7, json_data.find(',', pos) - pos - 7));
			pos = json_data.find("\"Pieces\":", pos);
			pos = json_data.find('[', pos);
			end_pos = json_data.find(']', pos);
			pieces_data = json_data.substr(pos, end_pos - pos + 1);

			std::cout << pos << end_pos << std::endl;

			// Parsing des pièces pour "Plateau"
			pos = pieces_data.find("{");
			for (int i = 0; i < size_plateau_pieces; i++) {
				piece piece;
				size_t end_piece_pos = pieces_data.find('}', pos);
				string piece_data = pieces_data.substr(pos, end_piece_pos - pos + 1);

				size_t shape_pos = piece_data.find("\"shape\":");
				int index_s = stoi(piece_data.substr(shape_pos + 8, piece_data.find(',', shape_pos) - shape_pos - 8));
				piece.set_shape((shape)index_s);

				size_t color_pos = piece_data.find("\"color\":");
				int index_c = stoi(piece_data.substr(color_pos + 8, piece_data.find('}', color_pos) - color_pos - 8));

				piece.set_color((shape_color)index_c);

				game.inserer_right(piece);
				HS[index_s-1].inserer_right_shapes(&game, piece);
				HC[index_c-1].inserer_right_colors(&game, piece);

				pos = pieces_data.find("{", end_piece_pos);
			}




			
			Party p(score , party_time ,Type , game ,Next , HS  , HC) ;

			
		}

		



		void show_scores() {
			system("cls");
			std::cout <<std::endl<< "this is a show game scores,we should be able to show best 10 scores";
			_getch();
		}
		
		size_t trouverOccurrence(const std::string& chaine, const std::string& mot, int occurrence) {
			size_t pos = chaine.find(mot); // Trouver la première occurrence du mot
			int compteur = 1; // Initialiser le compteur d'occurrence

			while (pos != std::string::npos && compteur < occurrence) {
				// Trouver la prochaine occurrence du mot à partir de la dernière position trouvée
				pos = chaine.find(mot, pos + 1);
				compteur++; // Incrémenter le compteur
			}

			return pos; // Retourner la position de l'occurrence recherchée
		}

		string* extractFileName() {
			const int sizeFile = countLines("savedPartiesNames.txt");
			string* nameFile=nullptr;
			if (sizeFile == 0)
				std::cout << "There's no file to upload";
			else if (sizeFile < 0)
				std::cout << "There's a problem we can't open any file ";
			else {


				std::ifstream file("savedPartiesNames.txt");
				if (!file.is_open()) {
					std::cerr << "Erreur lors de l'ouverture du fichier pour lire le tableau." << std::endl;
				}
				else {
					string c;
					int i = 0;
					if (sizeFile >= 0) {
						nameFile = new std::string[sizeFile];
					}
					
					for (int i = 0; i < sizeFile; i++) {
						std::getline(file, nameFile[i]);
					}
					file.close();
				}
			}

			


			return nameFile;
		}

		int countLines(const std::string& filename) {
			std::ifstream file(filename);
			if (!file.is_open()) {
				std::cerr << "Erreur lors de l'ouverture du fichier pour connaitre le nombre de ligne ." << std::endl;
				return -1; // En cas d'erreur d'ouverture, retourne -1
			}

			int lines = 0;
			std::string line;
			while (std::getline(file, line)) {
				++lines;
			}
			file.close();
			return lines;
		}

		string chooseNameFile() {
			string* nameFiles = extractFileName();
			int index = countLines("savedPartiesNames.txt");
			Menu m(nameFiles, index);
			int i = m.get_choice() - 1;
			return nameFiles[i];
			
			
		}

		

};

