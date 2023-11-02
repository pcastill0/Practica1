#include<iostream>
#include<string>
#include<vector>

#define MAP_SIZE 10

enum Scene {INTRO, NAVIGATION, COMBAT, STATUS};
Scene currentScene = INTRO;

char map[MAP_SIZE][MAP_SIZE] = {
{'#','#','#','#','#','#','#','#','#','#'},
{'#','@','.','P','.','P','.','.','.','#'},
{'#','#','#','G','#','S','#','#','M','#'},
{'#','.','.','.','#','#','#','#','#','#'},
{'#','.','T','.','#','J','#','.','B','#'},
{'#','.','.','.','#','L','#','.','.','#'},
{'#','#','.','#','#','.','#','T','T','#'},
{'#','P','G','.','.','O','#','.','.','#'},
{'#','.','.','.','.','K','.','.','B','#'},
{'#','#','#','#','#','#','#','#','#','#'}};

struct Player {
	int position[2] = {1,1};
	std::string name;
	int hp = 100;
	int maxHp = 100;
	int potions = 0;
	int bombs = 0;
	bool swords = 0;
	bool keys = 0;
};

void Intro(Player & player) {
	system("cls");
	currentScene = INTRO;
	std::cout << "- - - - - - - - - - - - - H E R O S  Q U E S T - - - - - - - - - - - - -\n";
	std::cout << "lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM\n\n";
	std::cout << "Use the HELP command to show the options\n";
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
	std::cout << "Name: ";
	std::cin >> player.name;
	std::cout << "Lorem ipsum " << player.name <<"\n";

	currentScene = NAVIGATION;
}

void Navigation(Player player) {
	system("cls");
	bool north = false, south = false, east = false, west = false;
	int x, y;
	std::cout << "[" << player.name << "] at [" 
		<< player.position[0] <<", " << player.position[1]<<"]\n";

	std::cout << "You can go: ";

	if (map[player.position[0]][player.position[1] - 1] != '#') {
		north = true;
		std::cout << "[North]";
	}

	if (map[player.position[0]][player.position[1] + 1] != '#') {
		south = true;
		std::cout << "[South]";

	}

	if (map[player.position[0]+1] [player.position[1]] != '#') {
		east = true;
		std::cout << "[East]";

	}

	if (map[player.position[0] -1][player.position[1]] != '#') {
		west = true;
		std::cout << "[West]";

	}

	std::cout << "\nWhat will you do?";

	std::cin >> x;
	std::cin >> y;

}

void Combat() {
	system("cls");

}

void PickupItem() {

}

void Status(Player player) {
	system("cls");
	std::cout << "------------ PLAYER ------------\n";
	std::cout << player.name <<"\n";
	std::cout << "-------------------------------\n";
	std::cout << "HP: " << player.hp << "/" << player.maxHp << "\n";
	std::cout << "-----------INVENTORY-----------\n";
	std::cout << "Potion: " << player.potions << "\n";
	std::cout << "Bomb: " << player.bombs << "\n";
	std::cout << "Sword: " << player.swords << "\n";
	std::cout << "Key: " << player.keys << "\n";
	std::cout << "--------------------------------\n";
	currentScene = NAVIGATION;
}

int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}

	while (true){
		Player player;

		if (currentScene == INTRO) {
			Intro(player);
		} else if (currentScene == NAVIGATION) {
			Navigation(player);
		} else if (currentScene == COMBAT) {
			Combat();
		} else if (currentScene == STATUS) {
			Status(player);
		}

		system("pause");

	}

}