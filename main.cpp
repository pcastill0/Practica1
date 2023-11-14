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

struct Enemy {
	std::string name;
	int hp = 100;
	int maxHp = 100;
	int potions = 0;
	int bombs = 0;
	bool swords = 0;
};

void Intro(Player& player);
void Status(Player player);
void Help();
void Navigation(Player& player);
bool findNearby(Player player, char obj, std::string objString);
void findBoss(Player player);
void Combat(Player& player);
void PickupItem(Player& player,std::string);


int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}

	Player player;
	while (true){

		if (currentScene == INTRO) {
			Intro(player);
		} else if (currentScene == NAVIGATION) {
			Navigation(player);
		} else if (currentScene == COMBAT) {
			Combat(player);
		} else if (currentScene == STATUS) {
			Status(player);
		}

		system("pause");

	}

}

void Intro(Player& player) {
	system("cls");
	currentScene = INTRO;
	std::cout << "- - - - - - - - - - - - - H E R O S  Q U E S T - - - - - - - - - - - - -\n";
	std::cout << "lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM\n\n";
	std::cout << "Use the HELP command to show the options\n";
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
	std::cout << "Name: ";
	std::getline(std::cin, player.name);
	std::cout << "Lorem ipsum " << player.name << "\n";

	currentScene = NAVIGATION;
}

void Navigation(Player& player) {
	system("cls");

	//Comprobar espacios libres
	bool north = false, south = false, east = false, west = false;

	std::cout << "[" << player.name << "] at ["
		<< player.position[0] << ", " << player.position[1] << "]\n";

	std::cout << "You can go: ";

	if (map[player.position[0] - 1][player.position[1]] != '#') {
		north = true;
		std::cout << "[North]";
	}

	if (map[player.position[0] + 1][player.position[1]] != '#') {
		south = true;
		std::cout << "[South]";
	}

	if (map[player.position[0]][player.position[1] + 1] != '#') {
		east = true;
		std::cout << "[East]";
	}

	if (map[player.position[0]][player.position[1] - 1] != '#') {
		west = true;
		std::cout << "[West]";
	}

	//Buscar dragon
	findBoss(player);

	//Buscar objetos y enemigos cercanos
	bool potion = false, sword = false, bomb = false, key = false;

	potion = findNearby(player, 'P', " potion");
	bomb = findNearby(player, 'B', " bomb");
	findNearby(player, 'L', " locked door");
	key = findNearby(player, 'K', " key");
	sword = findNearby(player, 'S', " sword");

	findNearby(player, 'G', " goblin");
	findNearby(player, 'O', "n orc");
	findNearby(player, 'T', " troll");

	//Escoger accion
	std::cout << "\nChoose your action\n>";
	std::string comm;
	std::getline(std::cin, comm);

	if (comm == "go north" && north) {
		player.position[0]--;
	}
	else if (comm == "go south" && south) {
		player.position[0]++;
	}
	else if (comm == "go east" && east) {
		player.position[1]++;
	}
	else if (comm == "go west" && west) {
		player.position[1]--;
	}
	else if (comm == "pick potion" && potion) {
		PickupItem(player, "potion");
	}
	else if (comm == "pick sword" && sword) {
		PickupItem(player, "potion");
	}
	else if (comm == "pick bomb" && bomb) {
		PickupItem(player, "bomb");
	}
	else if (comm == "pick key" && key) {
		PickupItem(player, "key");
	}
	else if (comm == "use potion") {

	}
	else if (comm == "use key") {

	}
	else if (comm == "status") {
		Status(player);
	}
	else if (comm == "help") {
		Help();
	}

	//TO-DO Comprobar enemigo en mi posicion
	if (map[player.position[0]][player.position[1]] == 'G' || 
		map[player.position[0]][player.position[1]] == 'O' || 
		map[player.position[0]][player.position[1]] == 'T' ||
		map[player.position[0]][player.position[1]] == 'J') {
		currentScene = COMBAT;
	}
}

void findBoss(Player player) {
	int dragonPosition[2];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j] == 'J') {
				dragonPosition[0] = i;
				dragonPosition[1] = j;
			}
		}
	}

	std::cout << "\nThere is a evil prescense at ";

	if (dragonPosition[1] < player.position[1]) {
		std::cout << "north";
	}

	if (dragonPosition[1] > player.position[1]) {
		std::cout << "south";
	}

	if (dragonPosition[0] < player.position[0]) {
		std::cout << "west";
	}

	if (dragonPosition[0] > player.position[0]) {
		std::cout << "east";
	}
	std::cout << "\n";
}

bool findNearby(Player player, char obj, std::string objString) {
	if (map[player.position[0] - 1][player.position[1]] == obj) {
		std::cout << "There is a" << objString << " at North\n";
	}

	if (map[player.position[0] + 1][player.position[1]] == obj) {
		std::cout << "There is a" << objString << " at South\n";
	}

	if (map[player.position[0]][player.position[1] + 1] == obj) {
		std::cout << "There is a" << objString << " at East\n";
	}

	if (map[player.position[0]][player.position[1] - 1] == obj) {
		std::cout << "There is a" << objString << " at West\n";
	}

	if (obj == 'P' || obj == 'S' || obj == 'B' || obj == 'K') {
		if (map[player.position[0]][player.position[1]] == obj) {
			std::cout << "There is a" << objString << " on the floor\n";
			return true;
		}
	}
	return false;
}

void PickupItem(Player& player, std::string obj) {
	std::cout << player.name << " have picked a ";
	if (obj == "potion") {
		player.potions++;
		std::cout << obj << "\n";
		map[player.position[0]][player.position[1]] = '.';
	}
	else if (obj == "sword") {
		player.swords = true;
		std::cout << obj << "\n";
		map[player.position[0]][player.position[1]] = '.';
	}
	else if (obj == "bomb") {
		player.bombs++;
		std::cout << obj << "\n";
		map[player.position[0]][player.position[1]] = '.';
	}
	else if (obj == "key") {
		player.keys = true;
		std::cout << obj << "\n";
		map[player.position[0]][player.position[1]] = '.';
	}
}

void Help() {

}

void Combat(Player& player) {
	do
	{
		//Escoger accion
		std::cout << "\nChoose your action\n>";
		std::string comm;
		std::getline(std::cin, comm);

		std::cout << "you are in combat";
		if (comm == "use potion") {

		}
		else if (comm == "use sword") {

		}
		else if (comm == "use bomb") {

		}
	} while (player.hp > 0);
	
}


void Status(Player player) {
	system("cls");
	std::cout << "------------ PLAYER ------------\n";
	std::cout << player.name << "\n";
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