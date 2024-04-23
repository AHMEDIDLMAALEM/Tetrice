#include "Game.h"


Game::Game() {
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
void Game::show_start_menu() {

	std::string options[] = { "New Game","Load a Game","Best Scores","Exit" };

	Menu m(options, 4);
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



}
void Game::show_difficulty_menu() {
	std::string options[] = { "Tetriste","Tepatrice","Tecontent","Tavalide","Bonus" };

	Menu m(options, 5);
	Party party(m.get_choice());

}
void Game::new_game() {
	system("cls");
	std::cout << std::endl << "this is a new game,we should be able to chose the difficulty";
	_getch();
}
void Game::load_games() {
	system("cls");
	std::cout << std::endl << "this is a load games,we should be able to chose a record";
	_getch();
}
void Game::show_scores() {
	system("cls");
	std::cout << std::endl << "this is a show game scores,we should be able to show best 10 scores";
	_getch();
}