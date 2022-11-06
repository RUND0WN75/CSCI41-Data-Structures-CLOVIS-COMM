#include "game.h"
using namespace std;

//extern Player one;
//extern Player two;

Game::Game() {
}

void Game::start(Player &one, Player &two, Die &d1, Die &d2, Table &t) {
	//Table t;
	string one_name;
	string two_name;
	string one_die;
	string two_die;
	unsigned int one_money;
	unsigned int two_money;
	unsigned int wager1;
	unsigned int wager2;

	//Getting player one info
	cout << "Enter a name for player one: \n";
	cin >> one_name;
	one.set_name(one_name);
	cout << "Enter starting money for player one: \n";
	cin >> one_money;
	one.set_money(one_money);
	cout << "How much do you want to wager " << one.get_name() << "?" << endl;
	while (true) {
		cin >> wager1;
		if (wager1 > one_money) {
			cout << "You cannot wager more than you have." << endl;
		}
		else if (wager1 == one_money) break;
		else break;
	}
	t.set_wager(wager1);

	//Getting player two info
	cout << "Enter a name for player two: \n";
	cin >> two_name;
	two.set_name(two_name);
	cout << "Enter starting money for player two: \n";
	cin >> two_money;
	two.set_money(two_money);
	cout << "How much do you want to wager " << two.get_name() << "?" << endl;
	while (true) {
		cin >> wager2;
		if (wager2 > two_money) {
			cout << "You cannot wager more than you have." << endl;
		}
		else if (wager2 == two_money) break;
		else break;
	}
	t.set_wager(wager2);

	//Asking players what die they want to use
	cout << "What die does " << one.get_name() << " wish to use?" << endl;
	d1.displayDieChoices();
	d1.setDie(d1);
	cout << "What die does " << two.get_name() << " wish to use?" << endl;
	d2.displayDieChoices();
	d2.setDie(d2);
}

void Game::play(Player& one, Player& two, Die &d1, Die &d2, Table &t) {
	//Table t;
	vector<int> tempScoresOne;
	vector<int> tempScoresTwo;
	vector<int> remainingDieOne;
	vector<int> remainingDieTwo;
	string s;
	//Die d({ .5,.1,.1,.1,.1,.1 }, 6);
	bool turn = true;
	if (turn) {
		cout << "It is " << one.get_name() << "'s turn." << endl;
		for (int i = 0; i < 6; i++) { //Display the dice values
			d1.roll();
			//cout << i << ") " << d1.get_roll() << endl;
			remainingDieOne.push_back(d1.get_roll());
		}
		
		for (int i = 0; i < remainingDieOne.size(); i++) {
			cout << i << ") " << remainingDieOne.at(i) << endl;
		}

		while (true) {	
			cin >> s;
			if (s == "E" || s == "e") {
				turn = false;
				break;
			}

			if (s == "F" || s == "f") break;

			else {
				//if (!cin) cout << "BAD INPUT" << endl;
				int i = stoi(s);
				//Maybe call function here to see if any die is able to be picked
				tempScoresOne.push_back(remainingDieOne.at(i));
				remainingDieOne.erase(remainingDieOne.begin() + i);
				cout << "You have chosen: " << endl;
				for (int x : tempScoresOne) {
					cout << x << endl;
				}

				cout << "Remaining: " << endl;
				for (int i = 0; i < remainingDieOne.size(); i++) {
					cout << i << ") " << remainingDieOne.at(i) << endl;
				}

				t.set_turnScore(tempScoresOne);


				cerr << "t.score: " << t.get_turnScore() << endl;
				cerr << "one score in play(): " << one.get_score() << endl;
			}

			cerr << "t.score outside loop: " << t.get_turnScore() << endl;

		}
		one.set_score(t.get_turnScore());
		t.set_turnScoreZero();
	}

	if (!turn) {
		cout << "It is " << two.get_name() << "'s turn." << endl;
		for (int i = 0; i < 6; i++) { //Display the dice values
			d2.roll();
			//cout << i << ") " << d2.get_roll() << endl;
			remainingDieTwo.push_back(d2.get_roll());
		}

		for (int i = 0; i < remainingDieTwo.size(); i++) {
			cout << i << ") " << remainingDieTwo.at(i) << endl;
		}

		while (true) {
			cin >> s;
			if (s == "E" || s == "e") break;
			if (s == "F" || s == "f") {
				for (int i = 0; i < remainingDieTwo.size(); i++) {
					d1.roll();
					cout << i << ")" << d1.get_roll() << endl;
					remainingDieTwo.push_back(d1.get_roll());
				}
			}
			else {
				//if (!cin) cout << "BAD INPUT" << endl;
				int i = stoi(s);
				//Maybe call function here to see if any die is able to be picked
				tempScoresTwo.push_back(remainingDieTwo.at(i));
				remainingDieTwo.erase(remainingDieTwo.begin() + i);
				cout << "You have chosen: " << endl;
				for (int x : tempScoresTwo) {
					cout << x << endl;
				}

				cout << "Remaining: " << endl;
				for (int i = 0; i < remainingDieTwo.size(); i++) {
					cout << i << ") " << remainingDieTwo.at(i) << endl;
				}

				t.set_turnScore(tempScoresTwo);


				cerr << "t.score: " << t.get_turnScore() << endl;
				cerr << "two score in play(): " << two.get_score() << endl;
			}

			cerr << "t.score outside loop: " << t.get_turnScore() << endl;

		}
		two.set_score(t.get_turnScore());
		t.set_turnScoreZero();
	}
}


