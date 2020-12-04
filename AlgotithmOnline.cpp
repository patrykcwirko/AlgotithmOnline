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

	cout << "Instancja z pliku:" << endl << endl;

	alg.loadInstanceFromFile("online_instance.txt", k, n, requests);

	cout << "Rozmiar pamieci: " << k << endl;
	cout << "Liczba zgloszen: " << n << endl;
	cout << "Zgloszenia:" << endl;

	for (int i = 0; i < n; ++i)
		cout << "  " << requests[i];

	cout << endl << endl;

	cout << "test" << endl;
	cout << alg.opt(k, n, requests) << endl;

	cout << "Instancja losowa:" << endl << endl;

	n = 20;
	alg.randomInstance(n, requests);

	cout << "Zgloszenia:" << endl;

	for (int i = 0; i < n; ++i)
		cout << "  " << requests[i];

	cout << endl << endl;

	cout << "test" << endl;
	cout << alg.opt(k, n, requests) << endl;

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
