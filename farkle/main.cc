//Walkup and Vargas
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "die.h"
#include "player.h"
#include "game.h"
//#include "scoreboard.h"
#include "table.h"
//#include "/public/colors.h"
using namespace std;

/*
void bad_input() {
	cout << "BAD INPUT!!\n";
	exit(EXIT_FAILURE);
}

vector<int> money;
vector<string> player {2};
*/
int main() {
	srand(time(0));
	//PARTNER'S WORK
	Game game;
	Table t;
	Player one;
	Player two;
	Die d1;
	Die d2;
	game.start(one, two, d1, d2, t);
	while (true) {
		if (one.get_score() > 2000) { 
			cout << one.get_name() << " has won the game!" << endl;
			one.set_money(t.get_wager());
		}
		else if (two.get_score() > 2000) {
			cout << two.get_name() << " has won the game!" << endl;
			two.set_money(t.get_wager());
		}
		else {
			game.play(one, two, d1, d2, t);
			cerr << "one score in main(): " << one.get_score() << endl;
			cerr << "two score in main(): " << two.get_score() << endl;
		}
	}
}
	
	//MY WORK 
	/*
	cout << "Enter the number of points to play with. Value must be between \(1000 to 10000)\n";
	while (cin) {
		//Inputting points
		int points = 0;
		cin >> points;
		if (!cin || points < 1000 || points > 10000) bad_input();

		//Inputting names
		string player1, player2;
		int player1_money = 0, player2_money = 0;
		cout << "Enter player 1's name:\n"; //Input whatever the user wants
		cin >> player1; 
		player.push_back(player1);
		cout << "Enter player 1's starter money. Value must be between \(1 to 1000)\n"; //Needs to be an int
		cin >> player1_money;
		if (!cin || player1_money < 1 ||player1_money > 1000) bad_input();
		money.push_back(player1_money);
		cout << "Does " << player1 << " want to play with weighted dice? \(Y or N)\n";
		char x;
		cin >> x;
		if (x == 'Y') {
			cout << "Loading weighted dice system...\n";
			//Insert code for the weighted dice system
			//Allow the player to pick the dice
			//Reiterate to player 2
			Die d({.5,.1,.1,.1,.1,.1},6);
			Die d2;
			d.roll();
			d2.roll();
			cout << d.get_roll() << endl;
			cout << d2.get_roll() << endl;
		}

		else if (x == 'N') continue;
		else bad_input();
	}
*/
