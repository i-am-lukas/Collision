#include "Obiekt.h"
//#include "KsztaltyPodstawowe.h"

void sprawdzKolizje(Obiekt &pierwszyObiekt, Obiekt &drugiObiekt){
	cout << ">Sprawdzenie kolizji" + pierwszyObiekt.getIdentyfikator() + " z " + drugiObiekt.getIdentyfikator() + ". 1 - tak/ 0 - nie." << endl;
	if (pierwszyObiekt.czyKoliduje(drugiObiekt)){
		cout << ">Wykryto kolizje" << endl;
		pierwszyObiekt.pokazKolizje();
	}
	else{
		cout << ">Brak kolizji" << endl;
	}
}


int main()
{
	/*
	Kwadrat kwadrat1 = Kwadrat(1, -1, 5, -1, 5, 3, 1, 3);
	Kwadrat kwadrat2 = Kwadrat(-1, 0, 1, 0, 1, 2, -1, 2);
	Kwadrat kwadrat3 = Kwadrat(-1, -1, 1, -1, 1, -3, -1, -3);
	Kwadrat kwadrat4 = Kwadrat(0, 2, 2, 2, 2, 4, 0, 4);
	Kwadrat kwadrat5 = Kwadrat(2, 0, 4, 0, 4, 2, 2, 2);
	Kwadrat kwadrat6 = Kwadrat(2,-2,5,-2,5,-3,2,-3);

	cout << kwadrat1.czyKoliduje(kwadrat2) << "TAK" << endl;
	cout << kwadrat1.czyKoliduje(kwadrat3) << "TAK" << endl;
	cout << kwadrat1.czyKoliduje(kwadrat4) << "TAK" << endl;
	cout << kwadrat1.czyKoliduje(kwadrat5) << "TAK do poprawy" << endl;
	cout << kwadrat2.czyKoliduje(kwadrat5) << "NIE" << endl;
	cout << kwadrat3.czyKoliduje(kwadrat2) << "NIE" << endl;
	cout << kwadrat6.czyKoliduje(kwadrat3) << "NIE" << endl;
	cout << kwadrat6.czyKoliduje(kwadrat1) << "NIE" << endl;
	cout << kwadrat6.czyKoliduje(kwadrat4) << "NIE" << endl;
	cout << kwadrat6.czyKoliduje(kwadrat2) << "NIE" << endl;

	Trojkat trojkat1 = Trojkat(-2, -1, 2, -1, -2, 3);
	Trojkat trojkat3 = Trojkat(-4,-2,-2,-2,-2,1);
	Trojkat trojkat2 = Trojkat(-2,-2,0,-2,-1,-4);

	cout << trojkat1.czyKoliduje(trojkat2) << "nie" << endl;
	cout << trojkat1.czyKoliduje(trojkat3) << "tak" << endl;
	cout << trojkat2.czyKoliduje(trojkat3) << "tak" << endl;

	cout << endl << endl;
	cout << kwadrat1.czyKoliduje(trojkat1) << "tak" << endl;
	cout << kwadrat1.czyKoliduje(trojkat2) << "nie" << endl;
	cout << kwadrat1.czyKoliduje(trojkat3) << "nie" << endl;
	cout << kwadrat2.czyKoliduje(trojkat1) << "tak" << endl;
	cout << kwadrat2.czyKoliduje(trojkat2) << "nie" << endl;
	cout << kwadrat3.czyKoliduje(trojkat2) << "tak" << endl;

	
	cout << endl << endl;
	cout << kolizja(-2, 1, 2, 1, 1, 2, 5, 2) << " nie" << endl;
	cout << kolizja(-2, 1, 2, 1, -1, -2, -1, 3) << " tak" << endl;
	cout << kolizja(-2, 1, 2, 1, -2, -2, 3, 3) << " tak" << endl;
	cout << kolizja(-2, 1, 2, 1, 3, 1, 4, 1) << " nie" << endl;
	cout << kolizja(-2, 1, 2, 1, -4, -1, -2, 1) << " tak" << endl;
	cout << kolizja(0, 0, 0, 1, 0, 0, 0, 10) << " tak" << endl;
	cout << kolizja(0, 0, 0, 1, 0, 1, 0, 10) << " tak" << endl;
	cout << kolizja(3, 0, 4, 1, 4, 1, 5, 2) << " tak" << endl;
	cout << kolizja(0,0,0,2,1,0,3,0) << " nie" << endl;

	*/

	Kwadrat kwadrat1 = Kwadrat(-1, -1, 1, -1, 1, 1, -1, 1, "Kwadrat Srodkowy");
	Kwadrat kwadrat2 = Kwadrat(-2,-2,0,-2,0,0,-2,0);
	Kwadrat kwadrat3 = Kwadrat(2, 0, 4, 0, 4, -2, 2, -2);

	Kolo kolo1= Kolo(2,0,1,"Kolo Wschodnie");
	Kolo kolo2 = Kolo(1, -1, 1);
	Kolo kolo3 = Kolo(1, -1, 1);

	Trojkat trojkat1 = Trojkat(-2, 0, -1, -1, -1, 1, "Trojkat Zachodni");
	Trojkat trojkat2 = Trojkat(-3,-1,-2,-2,-2,0);
	Trojkat trojkat3 = Trojkat(-3, -1, -2, -2, -2, 0);

	Obiekt pierwszyObiekt = Obiekt("NORTH");
	Obiekt drugiObiekt = Obiekt("SOUTH");

	pierwszyObiekt.dodajKsztaltPodstawowy(kwadrat1);
	pierwszyObiekt.dodajKsztaltPodstawowy(kolo1);
	pierwszyObiekt.dodajKsztaltPodstawowy(trojkat1);
	drugiObiekt.dodajKsztaltPodstawowy(kwadrat2);
	drugiObiekt.dodajKsztaltPodstawowy(kolo2);
	drugiObiekt.dodajKsztaltPodstawowy(trojkat2);

	sprawdzKolizje(pierwszyObiekt, drugiObiekt);
	

	/* //TESTOWANIE PRZESUNIECIA I OBROTU
	(kwadrat1).PrintMe();
	(kwadrat1).przesun(10,10);
	(kwadrat1).PrintMe();
	(kwadrat1).obroc(180);
	(kwadrat1).PrintMe();

	(kolo1).PrintMe();
	(kolo1).przesun(10, 10); // Przesuniecie o wektor = [10,10]
	(kolo1).PrintMe();
	(kolo1).obroc(180); // obrot o 180st.
	(kolo1).PrintMe();

	(trojkat7).PrintMe();
	(trojkat7).przesun(10, 10); // Przesuniecie o wektor = [10,10]
	(trojkat7).PrintMe();
	(trojkat7).obroc(180); // obrot o 180st.
	(trojkat7).PrintMe();
	*/
	/* //TESTOWANIE KOLIZJI

	// kolizja dwoch prostych
	cout << kolizja(-2, 1, 2, 1, 1, 2, 5, 2) << " Powinien wyjsc brak kolizji" << endl;
	cout << kolizja(-2, 1, 2, 1, -1, -2, -1, 3) << " Powinna wyjsc kolizja" << endl;
	cout << kolizja(-2, 1, 2, 1, -2, -2, 3, 3) << " Powinna wyjsc kolizja" << endl;
	cout << kolizja(-2, 1, 2, 1, 3, 1, 4, 1) << " Powinien wyjsc brak kolizji" << endl;
	cout << kolizja(-2, 1, 2, 1, -4, -1, -2, 1) << " Powinna wyjsc kolizja" << endl;
	cout << kolizja(0, 0, 0, 1, 0, 0, 0, 10) << " Powinna wyjsc kolizja" << endl;
	cout << kolizja(0, 0, 0, 1, 0, 1, 0, 10) << " Powinna wyjsc kolizja" << endl;
	cout << kolizja(3, 0, 4, 1, 4, 1, 5, 2) << " Powinna wyjsc kolizja" << endl;


	// //////////////////////////////////////////////////////////////////////////////////////////////////dane testowe 

	Kolo kolo1 = Kolo(0.0, 0.0, 3);
	Kolo kolo2 = Kolo(-2, 3, 3);

	Trojkat trojkat1 = Trojkat(3, 3, 3, -3, 6, 3);
	Trojkat trojkat2 = Trojkat(-6,4,-1,-1,-6,1);
	Trojkat trojkat3 = Trojkat(-2,3,-2,-3,-5,-3);
	Trojkat trojkat4 = Trojkat(0,7,0,3,2,8);
	Trojkat trojkat5 = Trojkat(-1,3,-4,7,-1,7);
	Trojkat trojkat6 = Trojkat(-4,-6,3,-6,0,-2);
	Trojkat trojkat7 = Trojkat(0,0,0,2,2,0);

	Kwadrat kwadrat1 = Kwadrat(0, 0, 10, 0, 10, 10, 0, 10);
	Kwadrat kwadrat2 = Kwadrat(3, -10, 10, -10, 10, 10, 3, 10);
	Kwadrat kwadrat3 = Kwadrat(-1,-1,1,-1,1,1,-1,1);
	Kwadrat kwadrat4 = Kwadrat(3,3,6,3,6,6,3,6);


	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	// kolo - kwadrat
	cout << (kolo1).czyKoliduje(kwadrat1) << " kolizja"<<endl;
	cout << (kolo1).czyKoliduje(kwadrat2) << " kolizja"<<endl;
	cout << (kolo1).czyKoliduje(kwadrat3) << " kolizja"<<endl;
	cout << (kolo1).czyKoliduje(kwadrat4) << endl;

	cout << (kolo2).czyKoliduje(kwadrat1) << " kolizja"<<endl;
	cout << (kolo2).czyKoliduje(kwadrat2) << endl;
	cout << (kolo2).czyKoliduje(kwadrat3) << " kolizja"<<endl;
	cout << (kolo2).czyKoliduje(kwadrat4) << endl;

	// kolo - trojkat
	cout << (kolo1).czyKoliduje(trojkat1) << " kolizja"<<endl;
	cout << (kolo1).czyKoliduje(trojkat2) << " kolizja"<<endl;
	cout << (kolo1).czyKoliduje(trojkat3) << " kolizja"<<endl;
	cout << (kolo1).czyKoliduje(trojkat4) << " kolizja"<<endl;
	cout << (kolo1).czyKoliduje(trojkat5) << endl;
	cout << (kolo1).czyKoliduje(trojkat6) << " kolizja"<<endl;
	cout << (kolo1).czyKoliduje(trojkat7) << " kolizja"<<endl;

	cout << (kolo2).czyKoliduje(trojkat1) << endl;
	cout << (kolo2).czyKoliduje(trojkat2) << " kolizja"<<endl;
	cout << (kolo2).czyKoliduje(trojkat3) << " kolizja"<<endl;
	cout << (kolo2).czyKoliduje(trojkat4) << " kolizja"<<endl;
	cout << (kolo2).czyKoliduje(trojkat5) << " kolizja"<<endl;
	cout << (kolo2).czyKoliduje(trojkat6) << endl;
	cout << (kolo2).czyKoliduje(trojkat7) << " kolizja"<<endl;


	// trojkat - kolo
	cout << (trojkat1).czyKoliduje(kolo1) << " kolizja"<<endl;
	cout << (trojkat2).czyKoliduje(kolo1) << " kolizja"<<endl;
	cout << (trojkat3).czyKoliduje(kolo1) << " kolizja"<<endl;
	cout << (trojkat4).czyKoliduje(kolo1) << " kolizja"<<endl;
	cout << (trojkat5).czyKoliduje(kolo1) << endl;
	cout << (trojkat6).czyKoliduje(kolo1) << " kolizja"<<endl;
	cout << (trojkat7).czyKoliduje(kolo1) << " kolizja"<<endl;

	cout << (trojkat1).czyKoliduje(kolo2) << endl;
	cout << (trojkat2).czyKoliduje(kolo2) << " kolizja"<<endl;
	cout << (trojkat3).czyKoliduje(kolo2) << " kolizja"<<endl;
	cout << (trojkat4).czyKoliduje(kolo2) << " kolizja"<<endl;
	cout << (trojkat5).czyKoliduje(kolo2) << " kolizja"<<endl;
	cout << (trojkat6).czyKoliduje(kolo2) << endl;
	cout << (trojkat7).czyKoliduje(kolo2) << " kolizja"<<endl;

	// kwadrat - kolo
	cout << (kwadrat1).czyKoliduje(kolo1) << " kolizja"<<endl;
	cout << (kwadrat2).czyKoliduje(kolo1) << " kolizja"<<endl;
	cout << (kwadrat3).czyKoliduje(kolo1) << " kolizja"<<endl;
	cout << (kwadrat4).czyKoliduje(kolo1) << endl;

	cout << (kwadrat1).czyKoliduje(kolo2) << " kolizja"<<endl;
	cout << (kwadrat2).czyKoliduje(kolo2) << endl;
	cout << (kwadrat3).czyKoliduje(kolo2) << " kolizja"<<endl;
	cout << (kwadrat4).czyKoliduje(kolo2) << endl;

	*/

	/*
	cout << "Sprawdzam poprawnosc wyliczania wspolczynnikow: " << endl;
	cout << "Wspolczynnik A dla (1,4) oraz (2,6): "<<obliczWspA(1, 4, 2, 6) << endl;
	cout << "Wspolczynnik B dla (1,4) oraz (2,6): " << obliczWspB(1, 4, 2, 6) << endl;

	cout << "Wspolny X dla y = x + 0 oraz y = -x + 0: " << wyliczPktWspolne(1, 0, -1, 0) << endl;
	cout << "Wspolny X dla y = x - 1 oraz y = 0.5x + 0: " << wyliczPktWspolne(1, -1, 0.5, 0) << endl;
	*/

	system("pause");
	return 0;
}

