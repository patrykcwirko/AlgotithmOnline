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
		requests[i] = rand() % n + 4;
}
