#include "Game.h"
#define S 0xDB    // Represents a solid block (█)
#define L 0xB0    // Represents a light shade (░)
#define M 0xB2   // Represents a medium shade (▒)
#define LT 0xC9   // Represents the bottom left corner (╔)
#define H 0xCD      // Represents a horizontal line (═)
#define LB 0xC8       // Represents the top left corner (╚)
#define RB 0xBC      // Represents the top right corner (╝)
#define RT 0xBB   // Represents the bottom right corner (╗)
#define V 0xBA        // Represents a vertical line (║)

Game::Game() {
	setConsoleWindowSize(600 ,400);
	system("cls");
	tetrice_draw(10, 5);
	//setConsoleBackgroundColor(BACKGROUND_BLUE);
	Menu::gotoxy(14, 12, ' ');
	std::cout << "Welcome to game press any key to continue ...";
	_getch();
	while (playing)
	{
		show_start_menu();
		// gui 
		// function
	}
}
void Game::tetrice_draw(int x, int y) {
	Menu::gotoxy(x, y,' ');
	cout << "\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xBB \xDB\xDB\xBB \xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\n";
	Menu::gotoxy(x, y + 1, ' ');
	cout << "\xC8\xCD\xCD\xDB\xDB\xC9\xCD\xCD\xBC\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xCD\xDB\xDB\xC9\xCD\xCD\xBC\xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xBA\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC\xDB\xDB\xC9\xCD\xCD\xCD\xCD\xBC\n";
	Menu::gotoxy(x, y + 2, ' ');
	cout << "   \xDB\xDB\xBA   \xDB\xDB\xDB\xDB\xDB\xBB     \xDB\xDB\xBA   \xDB\xDB\xDB\xDB\xDB\xDB\xC9\xBC\xDB\xDB\xBA\xDB\xDB\xBA     \xDB\xDB\xDB\xDB\xDB\xBB  \n";
	Menu::gotoxy(x, y + 3, ' ');
	cout << "   \xDB\xDB\xBA   \xDB\xDB\xC9\xCD\xCD\xBC     \xDB\xDB\xBA   \xDB\xDB\xC9\xCD\xCD\xDB\xDB\xBB\xDB\xDB\xBA\xDB\xDB\xBA     \xDB\xDB\xC9\xCD\xCD\xBC  \n";
	Menu::gotoxy(x, y + 4, ' ');
	cout << "   \xDB\xDB\xBA   \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB   \xDB\xDB\xBA   \xDB\xDB\xBA  \xDB\xDB\xBA\xDB\xDB\xBA\xC8\xDB\xDB\xDB\xDB\xDB\xDB\xBB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xBB\n";
	Menu::gotoxy(x, y + 5, ' ');
	cout << "   \xC8\xCD\xBC   \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC   \xC8\xCD\xBC   \xC8\xCD\xBC  \xC8\xCD\xBC\xC8\xCD\xBC \xC8\xCD\xCD\xCD\xCD\xCD\xBC\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n";
}
void Game::setConsoleWindowSize(int width, int height) {
	
	HWND console = GetConsoleWindow();
	RECT rect;
	GetWindowRect(console, &rect);
	MoveWindow(console, rect.left, rect.top, width, height, TRUE);
	//

	
}

void Game::setConsoleBufferSize(int width, int height) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD bufferSize = { width, height };
	SetConsoleScreenBufferSize(hConsole, bufferSize);
}
void Game::setConsoleBackgroundColor(int color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	WORD attributes = consoleInfo.wAttributes;
	attributes &= 0xFFF0; // clear background color
	attributes |= color;
	SetConsoleTextAttribute(hConsole, attributes);
}
void Game::show_start_menu() {

	std::string options[] = { "New Game","Load a Game","Best Scores","Exit" };

	Menu m(options, 4,28,8);
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

	Menu m(options, 5,28,7);
	Party party(m.get_choice());

}
void Game::new_game() {
	system("cls");
	std::cout << std::endl << "this is a new game,we should be able to chose the difficulty";
	_getch();
}
void Game::load_games() {
	system("cls");
	


	string filename = chooseNameFile();


	// Ouvrir le fichier JSON
	ifstream file(filename);

	// V�rifier si le fichier est ouvert correctement
	if (!file.is_open()) {
		cerr << "Erreur: Impossible d'ouvrir le fichier." << endl;
		return;
	}

	// Lire le contenu du fichier dans une cha�ne
	string json_data;
	string line;
	while (getline(file, line)) {
		json_data += line;
	}

	// Fermer le fichier apr�s la lecture
	file.close();

	// Parsing des donn�es JSON
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
	for (int i = 0; i < size_next_pieces; i++) { // Assurer de ne pas d�passer la taille maximale
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





	// Extraction des donn�es pour "Plateau"
	pos = json_data.find("\"Plateau\":");
	pos = trouverOccurrence(json_data, "\"size\":", 2);
	int size_plateau_pieces = stoi(json_data.substr(pos + 7, json_data.find(',', pos) - pos - 7));
	pos = json_data.find("\"Pieces\":", pos);
	pos = json_data.find('[', pos);
	end_pos = json_data.find(']', pos);
	pieces_data = json_data.substr(pos, end_pos - pos + 1);

	std::cout << pos << end_pos << std::endl;

	// Parsing des pi�ces pour "Plateau"
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
		HS[index_s - 1].inserer_right_shapes(&game, piece);
		HC[index_c - 1].inserer_right_colors(&game, piece);

		pos = pieces_data.find("{", end_piece_pos);
	}





	Party p(score, party_time, Type, game, Next, HS, HC);


}
void Game::show_scores() {
	system("cls");
	std::cout << std::endl << "this is a show game scores,we should be able to show best 10 scores" << std::endl << std::endl;

	int nb_entiers = 0;
	int entiers[10];

	std::ifstream fichier("Best10Scores.txt"); // Ouvre le fichier en mode lecture
	if (!fichier.is_open()) {
		std::cerr << "Erreur lors de l'ouverture du fichier best score." << std::endl;
		; // Retourne -1 en cas d'erreur
	}
	else {
		int entier;
		if (!(fichier >> entier))
			std::cout << "File is empty" << std::endl;

		else {

			// Lire chaque entier du fichier tant que nous ne d�passons pas la taille maximale du tableau
			while (fichier >> entier && nb_entiers < 10) {
				entiers[nb_entiers++] = entier; // Stocker l'entier dans le tableau

			}
			fichier.close(); // Ferme le fichier

			Party::trierEntiers(entiers, nb_entiers);
			for (int i = 0; i < nb_entiers; i++) {
			std:cout << i + 1 << '_' << entiers[i] << std::endl;
			}
		}

	}

	_getch();
}

size_t Game::trouverOccurrence(const std::string& chaine, const std::string& mot, int occurrence) {
	size_t pos = chaine.find(mot); // Trouver la premi�re occurrence du mot
	int compteur = 1; // Initialiser le compteur d'occurrence

	while (pos != std::string::npos && compteur < occurrence) {
		// Trouver la prochaine occurrence du mot � partir de la derni�re position trouv�e
		pos = chaine.find(mot, pos + 1);
		compteur++; // Incr�menter le compteur
	}

	return pos; // Retourner la position de l'occurrence recherch�e
}
string* Game::extractFileName() {
	const int sizeFile = countLines("savedPartiesNames.txt");
	string* nameFile = nullptr;
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
int Game::countLines(const std::string& filename) {
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
string Game::chooseNameFile() {
	string* nameFiles = extractFileName();
	int index = countLines("savedPartiesNames.txt");
	Menu m(nameFiles, index,26,5);
	int i = m.get_choice() - 1;
	return nameFiles[i];


}