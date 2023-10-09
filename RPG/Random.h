#pragma once

#include <iostream>
#include "time.h"
#include "stdlib.h"

using namespace std;

class Random {

public:

	static int getRandom(int min, int max) {

		if (max == 0) {

			return 0;
		}
		else {

			return  rand() % max - min + 1 + min;
		}
	}
};
