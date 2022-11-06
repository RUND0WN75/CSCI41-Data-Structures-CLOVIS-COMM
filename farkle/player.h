//PARTNER'S WORK
//PLAYER CLASS
#pragma once
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

class Player {
	private:
		unsigned int score;
		unsigned int money;
		string name; //PARTNER'S WORK
	public:
		Player();
		unsigned int get_score();
		unsigned int get_money();
		string get_name();
		void set_name(string s);
		//MY WORK
		void set_score(unsigned int new_score);
		void set_money(int gold);
};
