#include "Algorythms.h"


// zaladuj instancje z pliku
//
// filename - sciezka do pliku
// k - tu zapisz liczbe stron w pamieci szybkiej
// n - tu zapisz liczbe zgloszen
// requests - tu zapisz tablice zgloszen
void Algorythms::loadInstanceFromFile(const char* filename, int& k, int& n, int*& requests)
{
	ifstream ifs(filename);

	string line;

	{
		getline(ifs, line);
		stringstream ss;
		ss << line;
		ss >> k;
	}

	{
		getline(ifs, line);
		stringstream ss;
		ss << line;
		ss >> n;
	}

	requests = new int[n];

	for (int i = 0; i < n; ++i)
	{
		int val;
		getline(ifs, line);
		stringstream ss;
		ss << line;
		ss >> val;
		requests[i] = val;
	}
}

// wylosuj instancje o podanych parametrach
//
// n - liczba zgloszen do wygenerowania
// requests - tu zapisz tablice zgloszen (moze byc NULL)
void Algorythms::randomInstance(int n, int*& requests)
{
	srand(time(NULL));

	requests = new int[n];

	for (int i = 0; i < n; ++i)
		requests[i] = rand() % n *2;
}

int Algorythms::opt(int k, int n, int* requests)
{
	vector<d_opt> d_opt_count;
	d_opt tmp;

	tmp.date = requests[0];
	tmp.request = 1;
	bool again = false;
	d_opt_count.push_back(tmp);
	int max = 0, maxIndex = 0, sum = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < d_opt_count.size(); j++) 
		{
			if (requests[i] == d_opt_count[j].date)
			{
				d_opt_count[j].request += 1;
				again = true;
			}
		}
		if (!again)
		{
			tmp.date = requests[i];
			d_opt_count.push_back(tmp);
		}
		again = false;
	}

	for (int i = 0; i < 4; i++)
	{
		max = 0;
		for (int j = 0; j < d_opt_count.size(); j++)
		{
			if (max < d_opt_count[j].request)
			{
				max = d_opt_count[j].request;
				maxIndex = j;
			}
		}
		d_opt_count.erase(d_opt_count.begin() + maxIndex);
	}

	for (int j = 0; j < d_opt_count.size(); j++)
	{
		sum += d_opt_count[j].request;
	}

	return sum;
}

int Algorythms::fifo(int& k, int& n, int*& requests)
{
	return 0;
}

int Algorythms::lru(int& k, int& n, int*& requests)
{
	return 0;
}

int Algorythms::lfu(int& k, int& n, int*& requests)
{
	return 0;
}

int Algorythms::rnd(int& k, int& n, int*& requests)
{
	return 0;
}
