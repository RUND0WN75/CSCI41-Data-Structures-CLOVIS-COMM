//TABLE CLASS FOR HOLDING SIX DICE, WAGER UP FOR WINNING, SCORE FOR CURRENT TURN
#pragma once
#include <cstdlib>
#include <vector>
#include <cassert>
#include <iostream>
#include "player.h"
#include "die.h"
using std::vector;
//using std::cout;
using std::endl;

class Table {
	private:
		int wager = 0; //Wager = amount of money the user is winning up to.
		unsigned int turnScore; //turn = number of points accumulated 
		vector<int> dice; //Six dice.
	public:
		Table();
		//Table(unsigned int new_wager, unsigned int new_score, vector<int> new_dice) {}
		unsigned int get_wager();
		unsigned int get_turnScore();
		void set_wager(unsigned int wager);
		void set_turnScore(vector<int> scores);
		//PARTNER'S WORK
		void set_turnScoreZero();
};
