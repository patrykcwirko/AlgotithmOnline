#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Algorythms
{

	public:
		void loadInstanceFromFile(const char* filename, int& k, int& n, int*& requests);
		void randomInstance(int n, int*& requests);
};

