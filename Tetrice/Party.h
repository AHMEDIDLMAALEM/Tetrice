
#include<iostream>
#include<conio.h>
#include<thread>
#include<Windows.h>
#include "Menu.h"
#include <chrono>
#include<fstream>
#include "Plateau.h"
using namespace std;
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
	party_type Type = ni;
public:
	static std::string best_action;
	//create from a clone 
	Party(Party* origin, action effect);

	Party(int choice);
	Party(int choice, std::chrono::seconds dur);
	int get_score();
	Plateau get_game_pieces();
	Plateau get_next_pieces();
	string action_toString(action a);
	bool backTrack_State(Party *,action,string ,int);
	void backtracking_bestAction();
	void pause_menu(bool , bool );
	void save_game();
	int Tecontent();
	int Tepatrice();
	string StatetoString(action);
	void chose_decallage();
	void debug_copy(shape_node** tab, int size, shape_node** res);
	void decallage_gauche(int choice);
	void merge(shape_node* arr[], int left, int mid, int right);

	shape_node** mergeSort(shape_node* arr[], int left, int right);
	
	shape_node** create_gpi();
	shape_node** create_spi(int index);
	shape_node** create_cpi(int index);
	int Tetriste();
	void render_colorsANDshapes();

	void player_action(bool , bool , bool );
	// next : L C
	void init_scene(int size, bool ai, bool score);
	
	
	void handle_time();

	static void initializeMap() {
		isCaseCalculated.clear(); // Clear any previous values
		// Perform other initialization if necessary
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