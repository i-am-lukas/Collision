
#include "KsztaltyPodstawowe.h"



int main()
{
	Kolo *kolo1 = new Kolo(0.0, 0.0, 3);
	Kolo *kolo2 = new Kolo(-2, 3, 3);
	Trojkat *trojkat1 = new Trojkat(3, 3, 3, -3, 6, 3);
	Trojkat *trojkat2 = new Trojkat(-6,4,-1,-1,-6,1);
	Trojkat *trojkat3 = new Trojkat(-2,3,-2,-3,-5,-3);
	Trojkat *trojkat4 = new Trojkat(0,7,0,3,2,8);
	Trojkat *trojkat5 = new Trojkat(-1,3,-4,7,-1,7);
	Trojkat *trojkat6 = new Trojkat(-4,-6,3,-6,0,-2);
	Trojkat *trojkat7 = new Trojkat(0,0,0,2,2,0);

	/* //TESTOWANIE PRZESUNIECIA I OBROTU
	(*kolo1).PrintMe();
	(*kolo1).przesun(10, 10); // Przesuniecie o wektor = [10,10]
	(*kolo1).PrintMe();
	(*kolo1).obroc(180); // obrot o 180st.
	(*kolo1).PrintMe();

	(*trojkat7).PrintMe();
	(*trojkat7).przesun(10, 10); // Przesuniecie o wektor = [10,10]
	(*trojkat7).PrintMe();
	(*trojkat7).obroc(180); // obrot o 180st.
	(*trojkat7).PrintMe();
	*/
	/* //TESTOWANIE KOLIZJI
	cout << (*kolo1).czyKoliduje(*trojkat1) << endl;
	cout << (*kolo1).czyKoliduje(*trojkat2) << endl;
	cout << (*kolo1).czyKoliduje(*trojkat3) << endl;
	cout << (*kolo1).czyKoliduje(*trojkat4) << endl;
	cout << (*kolo1).czyKoliduje(*trojkat5) << endl;
	cout << (*kolo1).czyKoliduje(*trojkat6) << endl;
	cout << (*kolo1).czyKoliduje(*trojkat7) << endl;

	cout << (*kolo2).czyKoliduje(*trojkat1) << endl;
	cout << (*kolo2).czyKoliduje(*trojkat2) << endl;
	cout << (*kolo2).czyKoliduje(*trojkat3) << endl;
	cout << (*kolo2).czyKoliduje(*trojkat4) << endl;
	cout << (*kolo2).czyKoliduje(*trojkat5) << endl;
	cout << (*kolo2).czyKoliduje(*trojkat6) << endl;
	cout << (*kolo2).czyKoliduje(*trojkat7) << endl << endl;
	*/

	/*
	cout << "Sprawdzam poprawnosc wyliczania wspolczynnikow: " << endl;
	cout << "Wspolczynnik A dla (1,4) oraz (2,6): "<<obliczWspA(1, 4, 2, 6) << endl;
	cout << "Wspolczynnik B dla (1,4) oraz (2,6): " << obliczWspB(1, 4, 2, 6) << endl;

	cout << "Wspolny X dla y = x + 0 oraz y = -x + 0: " << wyliczPktWspolne(1, 0, -1, 0) << endl;
	cout << "Wspolny X dla y = x - 1 oraz y = 0.5x + 0: " << wyliczPktWspolne(1, -1, 0.5, 0) << endl;
	*/

	delete kolo1;
	delete kolo2;
	delete trojkat1;
	delete trojkat2;
	delete trojkat3;
	delete trojkat4;
	delete trojkat5;
	delete trojkat6;
	delete trojkat7;

	system("pause");
	return 0;
}

