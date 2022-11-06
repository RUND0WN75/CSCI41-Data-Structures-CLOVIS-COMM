//ALL PARTNER'S WORK
#include "player.h" 
#include "die.h"
using namespace std;
/*
Player::Player(string new_name, unsigned int new_money) : name(new_name), money(new_money) {
}
*/

Player::Player() {

}

void Player::set_money(int gold) {
	money =+ gold;
}

void Player::set_name(string s) {
	name = s;
}

void Player::set_score(unsigned int new_score) {
	score += new_score;
}

string Player::get_name() {
	return name;
}

unsigned int Player::get_money() {
	return money;
}

unsigned int Player::get_score() {
	return score;
}
