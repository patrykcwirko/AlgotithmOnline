#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "d_opt.h"

using namespace std;

class Algorythms
{

	public:
		void loadInstanceFromFile(const char* filename, int& k, int& n, int*& requests);
		void randomInstance(int n, int*& requests);
		int opt(int k, int n, int* requests);
		int fifo(int& k, int& n, int*& requests);
		int lru(int& k, int& n, int*& requests);
		int lfu(int& k, int& n, int*& requests);
		int rnd(int& k, int& n, int*& requests);
};

