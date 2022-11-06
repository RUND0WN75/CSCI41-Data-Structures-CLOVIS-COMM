#include "die.h"
#include <cassert>
using namespace std;

Die::Die() : SIDES(6), last_roll(0) {
	for (unsigned int i = 0; i < SIDES; i++)
		weight.push_back(1.0/SIDES);
}

Die::Die(const vector<double> new_weights, const int new_sides) : SIDES(new_sides), last_roll(0) {
	assert(new_sides >= 4);
	assert(new_weights.size() == SIDES);
	double sum = 0;
	for (unsigned int i = 0; i < SIDES; i++) {
		assert(new_weights[i] >= 0 && new_weights[i] <= 1);
		sum += new_weights[i];
		weight.push_back(new_weights[i]);
	}
	assert(sum > .99 && sum < 1.01);
}

int Die::get_roll() {
	assert(last_roll >= 1 && last_roll <= SIDES);
	return last_roll;
}

void Die::roll() {
	//TODO: Implement weight system
	vector<int> nums;
	int count = 0;
	for (int i = 0; i < SIDES; i++) {
	int count = weight.at(i) * 10;
		while (count > 0) {
			nums.push_back(i+1);
			count--;
		}
	}
	int selection = rand() % nums.size();
	last_roll = rand() % SIDES + 1;
}
void Die::setDie(Die d) {
	string s;
	//getline(cin, s);
	cin >> s;
	if (s == "Normal") Die d();
	if (s == "Alfonse's") Die d({ 0.4689, 0.0452, 0.0508, 0.0678, 0.1017, 0.2655 }, 6);
	if (s == "Even") Die d({ 0.0968, 0.1935, 0.0323, 0.129, 0.2258, 0.3514 }, 6); 
	if (s == "Odd") Die d({ 0.2933, 0.08, 0.2133, 0.0667, 0.2933, 0.0533 }, 6);
	if (s == "Misfortune") Die d({ 0.10, 0.12, 0.26, 0.12, 0.32, 0.08 }, 6);
	if (s == "Commonest") Die d({ 0.36, 0.16, 0.14, 0.08, 0.10, 0.16 }, 6);
}

void Die::displayDieChoices() {
	cout << "Normal\n";
	cout << "Alfonse's\n";
	cout << "Even\n";
	cout << "Odd\n";
	cout << "Misfortune\n";
	cout << "Commonest\n";
}

