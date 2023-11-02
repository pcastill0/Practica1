#include<iostream>
#include<string>
#include<vector>


char map[10][10] = {
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
	std::string name;
	int hp = 100;
	int potions = 0;
	int bombs = 0;
	int sowrds = 0;
	int keys = 0;
};

bool inCombat = false;

void Intro(Player player&) {
	std::cout << "- - - - - - - - - - - - - H E R O S  Q U E S T - - - - - - - - - - - - -\n";
	std::cout << "lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM lOREM IPSUM\n\n";
	std::cout << "Use the HELP command to show the options\n";
	std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
	std::cout << "Name: ";
	std::cin >> player.name;
	std::cout << "Lorem ipsum" << player.name <<"\n";
}

void Navigation() {

}

void Combat() {

}

void PickupItem() {

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

		Intro(player);

		while (player.hp > 0){
			if (!inCombat) {
				Navigation();
			}
		}

	}

}