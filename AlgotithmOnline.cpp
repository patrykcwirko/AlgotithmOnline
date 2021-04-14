// AlgotithmOnline.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Algorythms.h"

using namespace std;

int main()
{
	int  k, n;
	int* requests = NULL;
	Algorythms alg;
	float fifo[2], opt[2], lfu[2], lru[2], rnd[2];
	float _fifo, _opt, _lfu, _lru, _rnd;

	cout << "Instancja z pliku:" << endl << endl;

	alg.loadInstanceFromFile("online_instance.txt", k, n, requests);

	cout << "Rozmiar pamieci: " << k << endl;
	cout << "Liczba zgloszen: " << n << endl;
	cout << "Zgloszenia:" << endl;

	for (int i = 0; i < n; ++i)
		cout << "  " << requests[i];

	cout << endl;

	opt[0] = alg.opt(k, n, requests);
	fifo[0] = alg.fifo(k, n, requests);
	lfu[0] = alg.lfu(k, n, requests);
	lru[0] = alg.lru(k, n, requests);
	rnd[0] = alg.rnd(k, n, requests);

	cout << "OPT: " << opt[0] << endl;
	cout << "FIFO: " << fifo[0] << endl;
	cout << "LFU: " << lfu[0] << endl;
	cout << "LRU: " << lru[0] << endl;
	cout << "RND: " << rnd[0] << endl;

	cout << "Instancja losowa:" << endl << endl;

	n = 20;
	alg.randomInstance(n, requests);

	cout << "Rozmiar pamieci: " << k << endl;
	cout << "Liczba zgloszen: " << n << endl;
	cout << "Zgloszenia:" << endl;

	for (int i = 0; i < n; ++i)
		cout << "  " << requests[i];

	cout << endl << endl;

	opt[0] = alg.opt(k, n, requests);
	fifo[0] = alg.fifo(k, n, requests);
	lfu[0] = alg.lfu(k, n, requests);
	lru[0] = alg.lru(k, n, requests);
	rnd[0] = alg.rnd(k, n, requests);

	cout << "OPT: " << opt[0] << endl;
	cout << "FIFO: " << fifo[0] << endl;
	cout << "LFU: " << lfu[0] << endl;
	cout << "LRU: " << lru[0] << endl;
	cout << "RND: " << rnd[0] << endl << endl;

	if (fifo[0] > fifo[1])
		_fifo = fifo[0]/opt[0];
	else
		_fifo = fifo[1]/opt[1];


	if (lfu[0] > lfu[1])
		_lfu = lfu[0] / opt[0];
	else
		_lfu = lfu[1] / opt[1];

	if (lru[0] > lru[1])
		_lru = lru[0] / opt[0];
	else
		_lru = lru[1] / opt[1];

	if (rnd[0] > rnd[1])
		_rnd = rnd[0] / opt[0];
	else
		_rnd = rnd[1] / opt[1];

	cout << "Max r:" << endl;
	cout << "FIFO: " << _fifo << endl;
	cout << "LRU: " << _lru <<  endl;
	cout << "LFU: " << _lfu << endl;
	cout << "RND: " << _rnd << endl;


	return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
