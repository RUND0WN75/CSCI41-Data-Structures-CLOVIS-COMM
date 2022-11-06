//IMPLEMENTING THE TABLE CLASS
#include <iostream>
#include <vector>
#include <cassert>
#include "table.h"
using namespace std;

//If a player's score is higher than the wager, declare that player the winner.

Table::Table() {}

unsigned int Table::get_wager() {
	return wager;
}

unsigned int Table::get_turnScore() {
	return turnScore;
}

void Table::set_wager(unsigned int new_wager) {
	//PARTNER'S WORK
	wager += new_wager;
}

void Table::set_turnScore(vector<int> scores) {
int ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0;
    for (int i = 0; i < scores.size(); i++) {
        if (scores.at(i) == 1) ones++;
        if (scores.at(i) == 2) twos++;
        if (scores.at(i) == 3) threes++;
        if (scores.at(i) == 4) fours++;
        if (scores.at(i) == 5) fives++;
        if (scores.at(i) == 6) sixes++;
    }
    
    if ((ones == 1) && (twos == 1) && (threes == 1) && (fours == 1) && (fives == 1) && (sixes == 1)) turnScore += 1500;

    if ((ones == 3) && (twos == 3)) turnScore += 2500;
    if ((ones == 3) && (threes == 3)) turnScore += 2500;
    if ((ones == 3) && (fours == 3)) turnScore += 2500;
    if ((ones == 3) && (fives == 3)) turnScore += 2500;
    if ((ones == 3) && (sixes == 3)) turnScore += 2500;

    if ((twos == 3) && (threes == 3)) turnScore += 2500;
    if ((twos == 3) && (fours == 3)) turnScore += 2500;
    if ((twos == 3) && (fives == 3)) turnScore += 2500;
    if ((twos == 3) && (sixes == 3)) turnScore += 2500;

    if ((threes == 3) && (fours == 3)) turnScore += 2500;
    if ((threes == 3) && (fives == 3)) turnScore += 2500;
    if ((threes == 3) && (sixes == 3)) turnScore += 2500;

    if ((fours == 3) && (fives == 3)) turnScore += 2500;
    if ((fours == 3) && (sixes == 3)) turnScore += 2500;

    if ((fives == 3) && (sixes == 3)) turnScore += 2500;

    if ((ones == 4) && (twos == 2)) turnScore += 1500;
    if ((ones == 4) && (threes == 2)) turnScore += 1500;
    if ((ones == 4) && (fours == 2)) turnScore += 1500;
    if ((ones == 4) && (fives == 2)) turnScore += 1500;
    if ((ones == 4) && (sixes == 2)) turnScore += 1500;

    if ((twos == 4) && (threes == 2)) turnScore += 1500;
    if ((twos == 4) && (fours == 2)) turnScore += 1500;
    if ((twos == 4) && (fives == 2)) turnScore += 1500;
    if ((twos == 4) && (sixes == 2)) turnScore += 1500;

    if ((threes == 4) && (fours == 2)) turnScore += 1500;
    if ((threes == 4) && (fives == 2)) turnScore += 1500;
    if ((threes == 4) && (sixes == 2)) turnScore += 1500;

    if ((fours == 4) && (fives == 2)) turnScore += 1500;
    if ((fours == 4) && (sixes == 2)) turnScore += 1500;

    if ((fives == 4) && (sixes == 2)) turnScore += 1500;

    if ((ones == 2) && (twos == 2) && (threes == 2)) turnScore += 1500;
    if ((ones == 2) && (twos == 2) && (fours == 2)) turnScore += 1500;
    if ((ones == 2) && (twos == 2) && (fives == 2)) turnScore += 1500;
    if ((ones == 2) && (twos == 2) && (sixes == 2)) turnScore += 1500;

    if ((twos == 2) && (threes == 2) && (fours == 2)) turnScore += 1500;
    if ((twos == 2) && (threes == 2) && (fives == 2)) turnScore += 1500;
    if ((twos == 2) && (threes == 2) && (sixes == 2)) turnScore += 1500;

    if ((threes == 2) && (fours == 2) && (fives == 2)) turnScore += 1500;
    if ((threes == 2) && (fours == 2) && (sixes == 2)) turnScore += 1500;

    if ((fours == 2) && (fives == 2) && (sixes == 2)) turnScore += 1500;

    if (ones == 6) turnScore += 3000;
    if (twos == 6) turnScore += 3000;
    if (threes == 6) turnScore += 3000;
    if (fours == 6) turnScore += 3000;
    if (fives == 6) turnScore += 3000;
    if (sixes == 6) turnScore += 3000;
    if (ones == 5) turnScore += 2000;
    if (twos == 5) turnScore += 2000;
    if (threes == 5) turnScore += 2000;
    if (fours == 5) turnScore += 2000;
    if (fives == 5) turnScore += 2000;
    if (sixes == 5) turnScore += 2000;
    if (ones == 4) turnScore += 1000;
    if (twos == 4) turnScore += 1000;
    if (threes == 4) turnScore += 1000;
    if (fours == 4) turnScore += 1000;
    if (fives == 4) turnScore += 1000;
    if (sixes == 4) turnScore += 1000;
    if (ones == 3) turnScore += 300;
    if (twos == 3) turnScore += 200;
    if (threes == 3) turnScore += 300;
    if (fours == 3) turnScore += 400;
    if (fives == 3) turnScore += 500;
    if (sixes == 3) turnScore += 600;

    if (ones == 1 && ones != 2) turnScore = 100;
    if (ones == 2 && ones != 1) turnScore = 200;
    if (fives == 1) turnScore = 50;
    if (fives == 2) turnScore = 100;
}

void Table::set_turnScoreZero() {turnScore = 0;}
