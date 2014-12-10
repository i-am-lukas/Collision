#include "Detekcja Zderzen.h"

void sprawdzKolizje(Obiekt &pierwszyObiekt, Obiekt &drugiObiekt){
	cout << ">Sprawdzenie kolizji " + to_string(pierwszyObiekt.getID()) + " z " + to_string(drugiObiekt.getID()) << endl;
	if (pierwszyObiekt.czyKoliduje(drugiObiekt)){
		cout << ">Wykryto kolizje" << endl;
		pierwszyObiekt.pokazKolizje();
	}
	else{
		cout << ">Brak kolizji" << endl;
	}
}


// dla podanych 4 pktow, wyliczam rownania prostych i wyliczam czy pkt wspolne spelniaja warunki
bool kolizja(double Px1, double Py1, double Px2, double Py2, double Dx1, double Dy1, double Dx2, double Dy2){
	double A1 = 0;
	double B1 = 0;
	double C1 = 0;
	double A2 = 0;
	double B2 = 0;
	double C2 = 0;
	double W = 0;
	double Wx = 0;
	double Wy = 0;
	double wynikX = 0;
	double wynikY = 0;
	double xMax1 = 0, xMin1 = 0, yMax1 = 0, yMin1 = 0, xMax2 = 0, xMin2 = 0, yMax2 = 0, yMin2 = 0;
	xMax1 = fmax(Px1, Px2);
	xMin1 = fmin(Px1, Px2);
	yMax1 = fmax(Py1, Py2);
	yMin1 = fmin(Py1, Py2);
	xMax2 = fmax(Dx1, Dx2);
	xMin2 = fmin(Dx1, Dx2);
	yMax2 = fmax(Dy1, Dy2);
	yMin2 = fmin(Dy1, Dy2);

	if (Px2 - Px1 == 0){
		A1 = 1;
		B1 = 0;
		C1 = -Px1;
	}
	else{
		A1 = -((Py2 - Py1) / (Px2 - Px1));
		B1 = 1;
		C1 = -(Py1 - ((Py2 - Py1) / (Px2 - Px1))*Px1);
	}
	if (Dx2 - Dx1 == 0){
		A2 = 1;
		B2 = 0;
		C2 = -Dx1;
	}
	else{
		A2 = -((Dy2 - Dy1) / (Dx2 - Dx1));
		B2 = 1;
		C2 = -(Dy1 - ((Dy2 - Dy1) / (Dx2 - Dx1))*Dx1);
	}

	W = A1*B2 - A2*B1;
	Wx = B1*C2 - B2*C1;
	Wy = C1*A2 - C2*A1;

	if (W != 0){
		wynikX = Wx / W;
		wynikY = Wy / W;
		if //((fmin(Px1, Px2) <= Dx1 && Dx1 <= fmax(Px1, Px2)) || (fmin(Px1, Px2) <= Dx2 && Dx2 <= fmax(Px1, Px2)) || (fmin(Dx1, Dx2) <= Px1 && Px1 <= fmax(Dx1, Dx2)) || (fmin(Dx1, Dx2) <= Px2 && Px2 <= fmax(Dx1, Dx2))){
			(((wynikX >= xMin1 && wynikX <= xMax1) && (wynikX >= xMin2 && wynikX <= xMax2)) && ((wynikY >= yMin1 && wynikY <= yMax1) && (wynikY >= yMin2 && wynikY <= yMax2))){
			//cout << "Wyliczony punkt przeciecia: P(" << wynikX << ", " << wynikY << ");" << endl;
			return true;
		}
		else{
			return false;
		}
	}
	else if (Wx == 0 && Wy == 0){
		if (((xMin2 >= xMin1 && xMin2 <= xMax1) && (yMin2 >= yMin1 && yMin2 <= yMax1)) || ((xMax2 >= xMin1 && xMax2 <= xMax1) && (yMax2 >= yMin1 && yMax2 <= yMax1))){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		return false;
	}


}

// oblicza odleglosci od danych dwoch punktow
double obliczOdleglosc(double x1, double y1, double x2, double y2){
	double odleglosc = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return odleglosc;
}

// podaj parametry dwoch punktow i zwroc wspolczynnik A
double obliczWspA(double x1, double y1, double x2, double y2){
	double wspA = (y2 - y1) / (x2 - x1);
	return wspA;
}

// podaj parametry dwoch punktow i zwroc wspolczynnik B
double obliczWspB(double x1, double y1, double x2, double y2){
	double wspA = obliczWspA(x1, y1, x2, y2);
	double wspB = y1 - wspA*x1;
	return wspB;
}

// wylicza xsy wspolne dla dwoch prostych --- sprawdzic warunki np. gdy a1 i a2 sa takie same to znaczy ze nie ma pkt wspolnych, a jesli a1=a2 i b1=b2 to nieskonczenie wiele
double wyliczPktWspolne(double a1, double b1, double a2, double b2){
	double wspX = ((b2 - b1) / (a1 - a2));
	return wspX;
}

// sprawdz czy okrag koliduje z danym bokiem.. podaje zakres figury, wspolczynniki prostej, dane okregu
bool czyKolidujeZ(double xMin, double xMax, double wspolczynnikA, double wspolczynnikB, double srodekX, double srodekY, double promien){
	double delta = (2 * srodekX - (2 * wspolczynnikA)*(wspolczynnikB - srodekY))*(2 * srodekX - (2 * wspolczynnikA)*(wspolczynnikB - srodekY)) - 4 * (1 + wspolczynnikA*wspolczynnikA)*(srodekX*srodekX + (wspolczynnikB - srodekY)*(wspolczynnikB - srodekY) - promien*promien);
	double x1 = 0;
	double x2 = 0;
	//cout << "Zakres figury: (" << xMin << ", " << xMax <<")"<< endl;
	if (delta == 0){
		x1 = (2 * srodekX - 2 * wspolczynnikA*(wspolczynnikB - srodekY)) / (2 * (1 + wspolczynnikA*wspolczynnikA));
		//cout << "Delta = 0 : Jeden pierwiastek : " << x1 << endl;
		if ((x1 <= xMax) && (x1 >= xMin)){
			return true;
		}
		else{
			return false;
		}
	}
	else if (delta > 0){
		x1 = ((2 * srodekX - 2 * wspolczynnikA*(wspolczynnikB - srodekY)) - sqrt(delta)) / (2 * (1 + wspolczynnikA*wspolczynnikA));
		x2 = ((2 * srodekX - 2 * wspolczynnikA*(wspolczynnikB - srodekY)) + sqrt(delta)) / (2 * (1 + wspolczynnikA*wspolczynnikA));
		//cout << "Delta > 0 : Pierwszy : " << x1 << " Drugi: "<<x2<<endl;
		if (((x1 <= xMax) && (x1 >= xMin)) || ((x2 <= xMax) && (x2 >= xMin))){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		//cout << "Delta < 0" << endl;
		return false;
	}
}

// przypadek w ktorym sprawdzam kolizje kola z prosta, gdy ta prosta bedzie pionowa
bool czyKolidujePIONOWA(double xMin, double xMax, double rownaniePionowej, double srodekX, double srodekY, double promien){
	double delta = ((-2)*srodekY)*((-2)*srodekY) - 4 * (srodekY*srodekY - promien*promien + rownaniePionowej*rownaniePionowej - 2 * rownaniePionowej*srodekX + srodekX*srodekX);
	double x1 = 0;
	double x2 = 0;
	//cout << "Zakres figury: (" << xMin << ", " << xMax <<")"<< endl;
	if (delta == 0){
		x1 = srodekY;
		//cout << "Delta = 0 : Jeden pierwiastek : " << x1 << endl;
		if ((x1 <= xMax) && (x1 >= xMin)){
			return true;
		}
		else{
			return false;
		}
	}
	else if (delta > 0){
		x1 = ((2 * srodekY) - sqrt(delta)) / 2;
		x2 = ((2 * srodekY) + sqrt(delta)) / 2;
		//cout << "Delta > 0 : Pierwszy : " << x1 << " Drugi: " << x2 << endl;
		if (((x1 <= xMax) && (x1 >= xMin)) || ((x2 <= xMax) && (x2 >= xMin))){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		//cout << "Delta < 0" << endl;
		return false;
	}
}


int main()
{
	/*
	Prostokat kwadrat1 = Prostokat(1, -1, 5, -1, 5, 3, 1, 3);
	Prostokat kwadrat2 = Prostokat(-1, 0, 1, 0, 1, 2, -1, 2);
	Prostokat kwadrat3 = Prostokat(-1, -1, 1, -1, 1, -3, -1, -3);
	Prostokat kwadrat4 = Prostokat(0, 2, 2, 2, 2, 4, 0, 4);
	Prostokat kwadrat5 = Prostokat(2, 0, 4, 0, 4, 2, 2, 2);
	Prostokat kwadrat6 = Prostokat(2,-2,5,-2,5,-3,2,-3);

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

	Prostokat kwadrat1 = Prostokat(-1, -1, 1, -1, 1, 1, -1, 1, "Prostokat Srodkowy");
	
	Kolo kolo1 = Kolo(2, 0, 1, "Kolo Wschodnie");

	Trojkat trojkat1 = Trojkat(-2, 0, -1, -1, -1, 1, "Trojkat Zachodni");

	Scena scena;
	int i_object_first_id;
	i_object_first_id = scena.dodajObiekt("TEST1");

	Obiekt *pc_obj_0;
	pc_obj_0 = scena.dajObiektPrzezID(i_object_first_id);

	pc_obj_0->dodajKsztaltPodstawowy(kwadrat1);
	pc_obj_0->dodajKsztaltPodstawowy(kolo1);
	pc_obj_0->dodajKsztaltPodstawowy(trojkat1);

	pc_obj_0->pokazWspPkt();
	pc_obj_0->przesun(20, 10);
	cout << endl<<"    >PO PRZESUNIECIU O WEKTOR [ 20, 10 ]: " << endl;
	pc_obj_0->pokazWspPkt();
	pc_obj_0->obroc(180);
	cout << endl<<"    >PO OBROCIE O 180ST." << endl;
	pc_obj_0->pokazWspPkt();
	pc_obj_0->obroc(180);
	pc_obj_0->przesun(-20, -10);
	cout << endl<<"    >POWROT DO POCZATKU: " << endl;
	pc_obj_0->pokazWspPkt();
	scena.czyscScene();
	cout << endl << endl;
	
	

	// OBIEKT SAMOCHOD
	Prostokat prostokatGlowny = Prostokat(4,3,13,3,13,5,4,5, "Prostokat Glowny");
	Prostokat prostokatGorny = Prostokat(5,5,10,5,10,7,5,7,"Prostokat Gorny");

	Kolo koloLewe = Kolo(6,2,1, "Kolo Lewe");
	Kolo koloPrawe = Kolo(11,2,1, "Kolo Prawe");

	Trojkat trojkatDach = Trojkat(5,7,10,7,6,8, "Trojkat Dach");
	Trojkat trojkatPrzod = Trojkat(13,3,14,3,13,5,"Trojkat Przod");

	// OBIEKT LOD
	Prostokat prostokatSrodkowy = Prostokat(1,1,6,1,6,7,1,7, "Prostokat Srodkowy");
	Prostokat prostokatDolny = Prostokat(3,-2,4,-2,4,1,3,1, "Prostokat Dolny");

	Trojkat trojkatLewy = Trojkat(1,7,3.5,7,1,9, "Trojkat Lewy");
	Trojkat trojkatPrawy = Trojkat(3.5,7,6,7,6,9, "Trojkat Prawy");

	// OBIEKT BALWAN
	Kolo koloMax = Kolo(-4,-1,2, "Kolo Max");
	Kolo koloSrodkowe = Kolo(-4,2.5,1.5, "Kolo Srodkowe");
	Kolo koloMin = Kolo(-4,5,1, "Kolo Min");

	Trojkat trojkatCzapka = Trojkat(-5,6,-3,6,-4,7, "Trojkat Gorny");

	// OBIEKT PIONEK
	Prostokat PIONEKprostokat = Prostokat(-3,-4,1,-4,1,-2,-3,-2, "Prostokat");

	Kolo PIONEKkolo = Kolo(-4,-3,1, "Kolo Srodkowe");

	Trojkat PIONEKtrojkat = Trojkat(-7,-3,-5,-5,-5,-1, "Trojkat Lewy");

	// OBIEKT WIATRAK
	Kolo WIATRAKkolo = Kolo(1,-2,5, "Kolo Centralne");

	Prostokat WIATRAKprostokatWsh = Prostokat(5,1,6,0,9,3,8,4, "Prostokat Pol-Wsch");
	Prostokat WIATRAKprostokatZach = Prostokat(-3,1,-2,2,-6,4,-5,5, "Prostokat Pol-Zach");
	Prostokat WIATRAKprostokatPolWsh = Prostokat(6,-4,9,-7,8,-8,5,-5, "Prostokat DOLNYWSCHODNI");
	Prostokat WIATRAKprostokatPolZach = Prostokat(-2,-6,-1,-7,-4,-10,-5,-9, "Prostokat DOLNYZACHODNI");



	int i_object_third_id, i_object_4th_id, i_object_5th_id, i_object_6th_id, i_object_7th_id;

	i_object_third_id = scena.dodajObiekt("SAMOCHOD");
	i_object_4th_id = scena.dodajObiekt("LOD");
	i_object_5th_id = scena.dodajObiekt("BALWAN");
	i_object_6th_id = scena.dodajObiekt("PIONEK");
	i_object_7th_id = scena.dodajObiekt("WIATRAK");

	Obiekt *pc_obj_2, *pc_obj_3, *pc_obj_4, *pc_obj_5, *pc_obj_6;

	pc_obj_2 = scena.dajObiektPrzezID(i_object_third_id);
	pc_obj_3 = scena.dajObiektPrzezID(i_object_4th_id);
	pc_obj_4 = scena.dajObiektPrzezID(i_object_5th_id);
	pc_obj_5 = scena.dajObiektPrzezID(i_object_6th_id);
	pc_obj_6 = scena.dajObiektPrzezID(i_object_7th_id);

	pc_obj_2->dodajKsztaltPodstawowy(prostokatGlowny);
	pc_obj_2->dodajKsztaltPodstawowy(prostokatGorny);
	pc_obj_2->dodajKsztaltPodstawowy(koloLewe);
	pc_obj_2->dodajKsztaltPodstawowy(koloPrawe);
	pc_obj_2->dodajKsztaltPodstawowy(trojkatDach);
	pc_obj_2->dodajKsztaltPodstawowy(trojkatPrzod);

	pc_obj_3->dodajKsztaltPodstawowy(prostokatSrodkowy);
	pc_obj_3->dodajKsztaltPodstawowy(prostokatDolny);
	pc_obj_3->dodajKsztaltPodstawowy(trojkatLewy);
	pc_obj_3->dodajKsztaltPodstawowy(trojkatPrawy);

	pc_obj_4->dodajKsztaltPodstawowy(koloMax);
	pc_obj_4->dodajKsztaltPodstawowy(koloSrodkowe);
	pc_obj_4->dodajKsztaltPodstawowy(koloMin);
	pc_obj_4->dodajKsztaltPodstawowy(trojkatCzapka);

	pc_obj_5->dodajKsztaltPodstawowy(PIONEKprostokat);
	pc_obj_5->dodajKsztaltPodstawowy(PIONEKkolo);
	pc_obj_5->dodajKsztaltPodstawowy(PIONEKtrojkat);

	pc_obj_6->dodajKsztaltPodstawowy(WIATRAKkolo);
	pc_obj_6->dodajKsztaltPodstawowy(WIATRAKprostokatWsh);
	pc_obj_6->dodajKsztaltPodstawowy(WIATRAKprostokatZach);
	pc_obj_6->dodajKsztaltPodstawowy(WIATRAKprostokatPolWsh);
	pc_obj_6->dodajKsztaltPodstawowy(WIATRAKprostokatPolZach);

	cout << endl << "###############################################" << endl<<endl;
	cout << ">Sprawdzenie kolizji obiektow: BALWAN I PIONEK"<<endl;
	scena.sprawdzKolizje(i_object_5th_id, i_object_6th_id);
	cout << ">Sprawdzenie kolizji obiektow: BALWAN I LOD" << endl;
	scena.sprawdzKolizje(i_object_5th_id, i_object_4th_id);

	cout << endl<<endl<<"######################################" << endl;
	cout << "KOLIZJE OBIEKTOW:" << endl << endl;
	scena.pokazKolizjeObiektow();


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

	Prostokat kwadrat1 = Prostokat(0, 0, 10, 0, 10, 10, 0, 10);
	Prostokat kwadrat2 = Prostokat(3, -10, 10, -10, 10, 10, 3, 10);
	Prostokat kwadrat3 = Prostokat(-1,-1,1,-1,1,1,-1,1);
	Prostokat kwadrat4 = Prostokat(3,3,6,3,6,6,3,6);


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

