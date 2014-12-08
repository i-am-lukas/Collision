
#include "KsztaltyPodstawowe.h"



int main()
{
	Kolo *kolo1 = new Kolo(0.0, 0.0, 10.0);
	Trojkat *trojkat = new Trojkat(-10, -10, 10, -10, 0, 100);
	//(*trojkat).PrintMe();
	//Kwadrat *kwadrat = new Kwadrat(-10, 10, 10, 10, -10, -10, 10, -10);
	//(*kwadrat).PrintMe();

	//(*kolo1).PrintMe();
	//(*trojkat).PrintMe();
	//cout << kolo1->czyKoliduje(*trojkat) << endl;
	
	/*
	cout << endl;
	cout << "Detekcja zderzen! " << endl;
	cout << "Sprawdzam poprawnosc wyliczania wspolczynnikow: " << endl;
	cout << "Wspolczynnik A dla (1,4) oraz (2,6): "<<obliczWspA(1, 4, 2, 6) << endl;
	cout << "Wspolczynnik B dla (1,4) oraz (2,6): " << obliczWspB(1, 4, 2, 6) << endl;

	cout << "Wspolny X dla y = x + 0 oraz y = -x + 0: " << wyliczPktWspolne(1, 0, -1, 0) << endl;
	cout << "Wspolny X dla y = x - 1 oraz y = 0.5x + 0: " << wyliczPktWspolne(1, -1, 0.5, 0) << endl;
	*/

	delete kolo1;
	delete trojkat;
	system("pause");
	return 0;
}

