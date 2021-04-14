#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <queue>
#include "d_req.h"

#define MAX_REQUEST_NUMBER 10000

using namespace std;

class Algorythms
{
	private:
		int FindDate(vector<d_req> tmp, int ider);
		bool SearchQuery(queue<int> tmp, int value);

	public:
		void loadInstanceFromFile(const char* filename, int& k, int& n, int*& requests);
		void randomInstance(int n, int*& requests);
		int opt(int k, int n, int* requests);
		int fifo(int k, int n, int* requests);
		int lru(int k, int n, int* requests);
		int lfu(int k, int n, int* requests);
		int rnd(int k, int n, int* requests);
};

