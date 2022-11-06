#pragma once
#include "player.h"
#include "table.h"
#include <iostream>
#include <cstdlib>
#include <string>

struct Game {
	Game();
	void start (Player &one, Player &two, Die& d1, Die& d2, Table &t);
	void play (Player &one, Player &two, Die &d1, Die &d2, Table &t);
};

