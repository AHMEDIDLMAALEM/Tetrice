
#include<iostream>
#include<conio.h>
#include<thread>
#include<Windows.h>
#include "Menu.h"
#include <chrono>
#include<fstream>
#include "Plateau.h"
using namespace std;
#include <string>

typedef enum {
	ni,
	tetriste,
	tepatrice,
	tecontent,
	tavalide,
	Bonus
}party_type;

typedef enum {
	none,
	decallage_red,
	decallage_green,
	decallage_yellow,
	decallage_blue,
	decallage_cercle,
	decallage_rhombus,
	decallage_square,
	decallage_triangle,
	insertion_gauche,
	insertion_droite,
}action;
 


class Party
{
private:
	static int min_depth;
	static int max_score;
	static unordered_map<string,int> isCaseCalculated;
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
	bool time_using_cursor = false;
	party_type Type = ni;
	//for saving 
	int saving_time=120;
public:

	Plateau get_game_pieces();

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

		
		switch (typ)
		{
		case 1:
			Tetriste(true);
			break;
		case 2:
			std::cout << Tepatrice(true);
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
	Party(int choice);
	
	


	int Tepatrice(bool render_at_first = false);

	int Tecontent(bool render_at_first = false);
	
	

	static std::string best_action;
	//create from a clone 
	Party(Party* origin, action effect);

	
	Party(int choice, std::chrono::seconds dur);
	int get_score();
	
	Plateau get_next_pieces();
	string action_toString(action a);
	bool backTrack_State(Party *,action,string ,int);
	void backtracking_bestAction();
	void pause_menu(bool , bool );
	void save_game();

	string StatetoString(action); 
	void chose_decallage();
	void debug_copy(shape_node** tab, int size, shape_node** res);
	void decallage_gauche(int choice);
	void merge(shape_node* arr[], int left, int mid, int right);

	shape_node** mergeSort(shape_node* arr[], int left, int right);
	
	shape_node** create_gpi();
	shape_node** create_spi(int index);
	shape_node** create_cpi(int index);
	int Tetriste(bool render_at_first = false);
	void render_colorsANDshapes();
	int Bonus(bool render_at_first = false);
	void player_action(bool , bool , bool );
	// next : L C
	void init_scene(int , bool, bool , bool render_at_first = false);
	
	
	void handle_time();


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
				outFile << data; // �criture des donn�es dans le fichier
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
		 Menu m(options, 2,28,8);
		 int choice = m.get_choice();
		 switch (choice) {

		 case 1:
			 exited = true;

			 std::cout << "Restart the game" << std::endl;
			break;
		 case 2:
			 exit(-1);
			 
			 
		 default:
			 break;
		 }



	}


	 //~Party() {
		// /*string type;
		// switch ((int)Type) {
		// case 1:
		//	 type = "Tetrice";
		//	 break;
		// case 2:
		//	 type = "Tepatrice";
		//	 break;
		// case 3:
		//	 type = "Tecontent";
		//	 break;
		// case 4:
		//	 type = "Tevalide";
		//	 break;

		// }*/
		// std::cout << "im here" << std::endl;

		// // Ouverture du fichier JSON en mode �criture
		// std::ofstream fichier("Best10Scores.txt", std::ios::app); // Ouvre le fichier en mode ajout
		// if (fichier.is_open()) {
		//	 string data = to_string(score) + '\n' /*+ type+'\n'*/;
		//	 fichier << data; // �crit le contenu � la fin du fichier
		//	 fichier.close(); // Ferme le fichier
		// }
		// else {
		//	 std::cerr << "Erreur lors de l'ouverture du fichier Best10Scores." << std::endl;
		// }

	 //}

	 void saveScores() {
		 int nb_entiers = 0;
		 int entiers[10];

		std::ifstream fichier("Best10Scores.txt"); // Ouvre le fichier en mode lecture
		 if (!fichier.is_open()) {
			 std::cerr << "Erreur lors de l'ouverture du fichier best score." << std::endl;
			 ; // Retourne -1 en cas d'erreur
		 }
		 else {
			 

			 int entier;
			 // Lire chaque entier du fichier tant que nous ne d�passons pas la taille maximale du tableau
			 while (fichier >> entier && nb_entiers < 10) {
				 entiers[nb_entiers++] = entier; // Stocker l'entier dans le tableau
				 
			 }
			 fichier.close(); // Ferme le fichier

			 trierEntiers(entiers, nb_entiers);
		 }

		 


		 std::ofstream File("Best10Scores.txt", std::ios::trunc); // Ouvre le fichier en mode ajout
		 if (File.is_open()) {
			 if (nb_entiers == 10) {
				 for (int i = 0; i < nb_entiers; i++) {
					 if (score > entiers[i]) {
						 entiers[9] = score;
						 break;
					 }
				 }
			 }
			 else {

				 entiers[nb_entiers++] = score;

			 }
			 
			 


			 for (int i = 0; i < nb_entiers; i++) {
				 //string data = to_string(score) + '\n' /*+ type+'\n'*/;
				 File << to_string(entiers[i]) + '\n'; // �crit le contenu � la fin du fichier
			 }
			 File.close();
		 }

		 else {
			 std::cerr << "Erreur lors de l'ouverture du fichier Best10Scores." << std::endl;
		 }


			 
		 

	 }


	 static void trierEntiers(int entiers[], int nb_entiers) {
		 for (int i = 0; i < nb_entiers - 1; ++i) {
			 for (int j = 0; j < nb_entiers - i - 1; ++j) {
				 if (entiers[j] < entiers[j + 1]) {
					 // �change les �l�ments entiers[j] et entiers[j + 1]
					 int temp = entiers[j];
					 entiers[j] = entiers[j + 1];
					 entiers[j + 1] = temp;
				 }
			 }
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