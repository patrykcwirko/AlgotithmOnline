#include "Algorythms.h"



int Algorythms::FindDate(vector<d_req> tmp, int ider)
{
	for (size_t i = 0; i < tmp.size(); ++i) {
		if (tmp[i].date == ider)
			return i;
	}
}

bool Algorythms::SearchQuery(queue<int> tmp, int value)
{
	while (!tmp.empty())
	{
		if (tmp.front() == value)
			return true;
		tmp.pop();
	} 
	return false;
}

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
	vector<d_req> d_opt_count;
	vector<int> memory;
	d_req tmp;

	tmp.date = requests[0];
	tmp.request = 1;
	bool again = false;
	d_opt_count.push_back(tmp);
	int min = MAX_REQUEST_NUMBER, minIndex = 0, sum = 0;

	//utworzenie listy danych i ile razy dana jest wywo³ywana
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

	//wpisanie do pamiêci szybkiej pierwszych k stron
	for (int i = 0; i < k; i++)
	{
		memory.push_back( requests[i] );
		d_opt_count[i].request -= 1;
		sum += 1;
	}

	//przegladanie tablicy zadan. W przypadku nowej strony ktorej nie ma w pamieci usuwa siê ta, ktora bedzie miec najmniej wywolan
	for (int j = k; j < n; j++)
	{
		for (int i = 0; i < memory.size(); i++)
		{
			if (requests[j] == memory[i]) 
			{	
				again = true;
				d_opt_count[FindDate(d_opt_count, requests[j])].request -= 1;
			}
		}
		if (!again)
		{ // sprawdzenie ktora strona w pamieci ma najmniej wywolan
			for (int l = 0; l < memory.size() ; l++)
			{
				if (min > memory[l])
				{
					min = memory[l];
					minIndex = l;
				}
			}
			memory[minIndex] = requests[j];
			d_opt_count[FindDate(d_opt_count, requests[j])].request -= 1;
			sum += 1;
		}
		again = false;
	}

	return sum;
}

int Algorythms::fifo(int k, int n, int* requests)
{
	queue<int> memory;
	bool again = false;
	int sum = 0;

	//wpisanie do pamiêci szybkiej pierwszych k stron
	for (int i = 0; i < k; i++)
	{
		memory.push(requests[i]);
		sum += 1;
	}

	for (int i = k; i < n; i++)
	{
		again = SearchQuery(memory, requests[i]);
		
		if (!again)
		{
			memory.pop();
			memory.push(requests[i]);
			sum += 1;
		}
	}

	return sum;
}

int Algorythms::lru(int k, int n, int* requests)
{
	vector<d_req> memory;
	d_req tmp;

	bool again = false;
	int min = 0, minIndex = 0, sum = 0;

	tmp.request = 0;
	//wpisanie do pamiêci szybkiej pierwszych k stron
	for (int i = 0; i < k; i++)
	{
		tmp.date = requests[i];
		memory.push_back(tmp); 
		sum += 1;
	}

	//przegladanie tablicy zadan. W przypadku nowej strony ktorej nie ma w pamieci usuwa siê ta, ktora bedzie miec najmniej wywolan
	for (int j = k; j < n; j++)
	{
		for (int i = 0; i < memory.size(); i++)
		{
			if (requests[j] == memory[i].date)
			{
				again = true;
				memory[i].request = 0;
			}
			else
			{
				memory[i].request += 1;
			}
		}
		if (!again)
		{
			for (int l = 0; l < memory.size(); l++)
			{
				if (min < memory[l].request)
				{
					min = memory[l].request;
					minIndex = l;
				}
			}
			memory[minIndex].date = requests[j];
			sum += 1;
		}
		again = false;
	}

	return sum;
}

int Algorythms::lfu(int k, int n, int* requests)
{
	vector<d_req> memory;
	d_req tmp;

	bool again = false;
	int min = 0, minIndex = 0, sum = 0;

	tmp.request = 0;
	//wpisanie do pamiêci szybkiej pierwszych k stron
	for (int i = 0; i < k; i++)
	{
		tmp.date = requests[i];
		memory.push_back(tmp);
		sum += 1;
	}

	//przegladanie tablicy zadan. W przypadku nowej strony ktorej nie ma w pamieci usuwa siê ta, ktora bedzie miec najmniej wywolan
	for (int j = k; j < n; j++)
	{
		for (int i = 0; i < memory.size(); i++)
		{
			if (requests[j] == memory[i].date)
			{
				again = true;
				memory[i].request += 1;
			}
		}
		if (!again)
		{
			for (int l = 0; l < memory.size(); l++)
			{
				if (min < memory[l].request)
				{
					min = memory[l].request;
					minIndex = l;
				}
			}
			memory[minIndex].date = requests[j];
			sum += 1;
		}
		again = false;
	}

	return sum;
}

int Algorythms::rnd(int k, int n, int* requests)
{
	vector<int> memory;
	d_req tmp;

	bool again = false;
	int min = 0, Index = 0, sum = 0;

	tmp.request = 0;
	//wpisanie do pamiêci szybkiej pierwszych k stron
	for (int i = 0; i < k; i++)
	{
		memory.push_back(requests[i]);
		sum += 1;
	}

	//przegladanie tablicy zadan. W przypadku nowej strony ktorej nie ma w pamieci usuwa siê ta, ktora bedzie miec najmniej wywolan
	for (int j = k; j < n; j++)
	{
		for (int i = 0; i < memory.size(); i++)
		{
			if (requests[j] == memory[i])
			{
				again = true;
			}
		}
		if (!again)
		{
			Index = rand() % k;
			memory[Index] = requests[j];
			sum += 1;
		}
		again = false;
	}

	return sum;
}
