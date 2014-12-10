#include "KsztaltyPodstawowe.h"


/////////////////////////////////////////////// KLASA KOLO ///////////////////////

Kolo::Kolo(double wspX, double wspY, double promien, string identyfikator){
	this->vektorPunktow.push_back(wspX);
	this->vektorPunktow.push_back(wspY);
	this->vektorPunktow.push_back(promien);
	this->identyfikator = identyfikator;
}

Kolo::~Kolo(){

}

bool Kolo::czyKoliduje(Kolo &drugieKolo){
	double odleglosc = obliczOdleglosc(this->vektorPunktow[0], this->vektorPunktow[1], drugieKolo.vektorPunktow[0], drugieKolo.vektorPunktow[1]);
	double suma = this->vektorPunktow[2] + drugieKolo.vektorPunktow[2];
	if (odleglosc > suma){
		return false;
	}
	else{
		return true;
	}
}

void Kolo::PrintMe(){
	cout << "Kolo: " << "Sr(" << this->vektorPunktow[0] << "," << this->vektorPunktow[1] << "), Promien: " << this->vektorPunktow[2] << endl;
}

double Kolo::getWsp(int i){
	return this->vektorPunktow[i];
}

string Kolo::getIdentyfikator(){
	return this->identyfikator;
}

void Kolo::przesun(double wektorX, double wektorY){
	this->vektorPunktow[0] = this->vektorPunktow[0] + wektorX;
	this->vektorPunktow[1] = this->vektorPunktow[1] + wektorY;
}

void Kolo::obroc(double stopnie){
	double rad = (stopnie*3.14159265 / 180);
	double pomocniczyX = this->vektorPunktow[0];
	double pomocniczyY = this->vektorPunktow[1];

	this->vektorPunktow[0] = round(pomocniczyX*cos(rad) - pomocniczyY*sin(rad));
	this->vektorPunktow[1] = round(pomocniczyX*sin(rad) + pomocniczyY*cos(rad));
}

bool Kolo::czyKoliduje(Trojkat &trojkat){
	if ((pow(trojkat.getWsp(0) - this->vektorPunktow[0], 2) + pow(trojkat.getWsp(1) - this->vektorPunktow[1], 2) <= this->vektorPunktow[2]) ||
		(pow(trojkat.getWsp(2) - this->vektorPunktow[0], 2) + pow(trojkat.getWsp(3) - this->vektorPunktow[1], 2) <= this->vektorPunktow[2]) ||
		(pow(trojkat.getWsp(4) - this->vektorPunktow[0], 2) + pow(trojkat.getWsp(5) - this->vektorPunktow[1], 2) <= this->vektorPunktow[2])) {
		return true;
	} // Sprawdzenie kazdego wierzcholka. czy nie zawiera sie w kole?
	double wiekszy = 0;
	double mniejszy = 0;
	if (trojkat.getWsp(2) - trojkat.getWsp(0) == 0){
		wiekszy = fmax(trojkat.getWsp(1), trojkat.getWsp(3));
		mniejszy = fmin(trojkat.getWsp(1), trojkat.getWsp(3));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, trojkat.getWsp(0), this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	else{
		double wspA1 = obliczWspA(trojkat.getWsp(0), trojkat.getWsp(1), trojkat.getWsp(2), trojkat.getWsp(3));
		double wspB1 = trojkat.getWsp(1) - wspA1*trojkat.getWsp(0);
		wiekszy = fmax(trojkat.getWsp(0), trojkat.getWsp(2));
		mniejszy = fmin(trojkat.getWsp(0), trojkat.getWsp(2));
		//cout << "Wspolczynnik dla x1,y1  |  x2,y2: " << trojkat.getWsp(0) << ", " << trojkat.getWsp(1) << "   |   " << trojkat.getWsp(2) << ", " << trojkat.getWsp(3) << endl;
		//cout << "Wspolczynnik A: " << wspA1 << endl;
		//cout << "Wspolczynnik B: " << wspB1 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA1, wspB1, this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	if (trojkat.getWsp(4) - trojkat.getWsp(0) == 0){
		wiekszy = fmax(trojkat.getWsp(1), trojkat.getWsp(5));
		mniejszy = fmin(trojkat.getWsp(1), trojkat.getWsp(5));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, trojkat.getWsp(0), this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	else{
		double wspA2 = obliczWspA(trojkat.getWsp(0), trojkat.getWsp(1), trojkat.getWsp(4), trojkat.getWsp(5));
		double wspB2 = trojkat.getWsp(1) - wspA2*trojkat.getWsp(0);
		wiekszy = fmax(trojkat.getWsp(0), trojkat.getWsp(4));
		mniejszy = fmin(trojkat.getWsp(0), trojkat.getWsp(4));
		//cout << "Wspolczynnik dla x1,y1  |  x3,y3: " << trojkat.getWsp(0) << ", " << trojkat.getWsp(1) << "   |   " << trojkat.getWsp(4) << ", " << trojkat.getWsp(5) << endl;
		//cout << "Wspolczynnik A: " << wspA2 << endl;
		//cout << "Wspolczynnik B: " << wspB2 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA2, wspB2, this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}

	if (trojkat.getWsp(2) - trojkat.getWsp(4) == 0){
		wiekszy = fmax(trojkat.getWsp(3), trojkat.getWsp(5));
		mniejszy = fmin(trojkat.getWsp(3), trojkat.getWsp(5));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, trojkat.getWsp(2), this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	else{
		double wspA3 = obliczWspA(trojkat.getWsp(2), trojkat.getWsp(3), trojkat.getWsp(4), trojkat.getWsp(5));
		double wspB3 = trojkat.getWsp(3) - wspA3*trojkat.getWsp(2);
		wiekszy = fmax(trojkat.getWsp(2), trojkat.getWsp(4));
		mniejszy = fmin(trojkat.getWsp(2), trojkat.getWsp(4));
		//cout << "Wspolczynnik dla x2,y2  |  x3,y3: " << trojkat.getWsp(2) << ", " << trojkat.getWsp(3) << "   |   " << trojkat.getWsp(4) << ", " << trojkat.getWsp(5) << endl;
		//cout << "Wspolczynnik A: " << wspA3 << endl;
		//cout << "Wspolczynnik B: " << wspB3 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA3, wspB3, this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	return false;
}

bool Kolo::czyKoliduje(Prostokat &kwadrat){
	if ((pow(kwadrat.getWsp(0) - this->vektorPunktow[0], 2) + pow(kwadrat.getWsp(1) - this->vektorPunktow[1], 2) <= this->vektorPunktow[2]) ||
		(pow(kwadrat.getWsp(2) - this->vektorPunktow[0], 2) + pow(kwadrat.getWsp(3) - this->vektorPunktow[1], 2) <= this->vektorPunktow[2]) ||
		(pow(kwadrat.getWsp(4) - this->vektorPunktow[0], 2) + pow(kwadrat.getWsp(5) - this->vektorPunktow[1], 2) <= this->vektorPunktow[2]) ||
		(pow(kwadrat.getWsp(6) - this->vektorPunktow[0], 2) + pow(kwadrat.getWsp(7) - this->vektorPunktow[1], 2) <= this->vektorPunktow[2])){
		return true;
	} // Sprawdzenie kazdego wierzcholka. czy nie zawiera sie w kole?
	double wiekszy = 0;
	double mniejszy = 0;
	if (kwadrat.getWsp(2) - kwadrat.getWsp(0) == 0){
		wiekszy = fmax(kwadrat.getWsp(1), kwadrat.getWsp(3));
		mniejszy = fmin(kwadrat.getWsp(1), kwadrat.getWsp(3));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, kwadrat.getWsp(0), this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	else{
		double wspA1 = obliczWspA(kwadrat.getWsp(0), kwadrat.getWsp(1), kwadrat.getWsp(2), kwadrat.getWsp(3));
		double wspB1 = kwadrat.getWsp(1) - wspA1*kwadrat.getWsp(0);
		wiekszy = fmax(kwadrat.getWsp(0), kwadrat.getWsp(2));
		mniejszy = fmin(kwadrat.getWsp(0), kwadrat.getWsp(2));
		//cout << "Wspolczynnik dla x1,y1  |  x2,y2: " << kwadrat.getWsp(0) << ", " << kwadrat.getWsp(1) << "   |   " << kwadrat.getWsp(2) << ", " << kwadrat.getWsp(3) << endl;
		//cout << "Wspolczynnik A: " << wspA1 << endl;
		//cout << "Wspolczynnik B: " << wspB1 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA1, wspB1, this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	if (kwadrat.getWsp(6) - kwadrat.getWsp(0) == 0){
		wiekszy = fmax(kwadrat.getWsp(1), kwadrat.getWsp(7));
		mniejszy = fmin(kwadrat.getWsp(1), kwadrat.getWsp(7));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, kwadrat.getWsp(0), this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	else{
		double wspA2 = obliczWspA(kwadrat.getWsp(0), kwadrat.getWsp(1), kwadrat.getWsp(6), kwadrat.getWsp(7));
		double wspB2 = kwadrat.getWsp(1) - wspA2*kwadrat.getWsp(0);
		wiekszy = fmax(kwadrat.getWsp(0), kwadrat.getWsp(6));
		mniejszy = fmin(kwadrat.getWsp(0), kwadrat.getWsp(6));
		//cout << "Wspolczynnik dla x1,y1  |  x4,y4: " << kwadrat.getWsp(0) << ", " << kwadrat.getWsp(1) << "   |   " << kwadrat.getWsp(6) << ", " << kwadrat.getWsp(7) << endl;
		//cout << "Wspolczynnik A: " << wspA2 << endl;
		//cout << "Wspolczynnik B: " << wspB2 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA2, wspB2, this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}

	if (kwadrat.getWsp(2) - kwadrat.getWsp(4) == 0){
		wiekszy = fmax(kwadrat.getWsp(3), kwadrat.getWsp(5));
		mniejszy = fmin(kwadrat.getWsp(3), kwadrat.getWsp(5));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, kwadrat.getWsp(2), this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	else{
		double wspA3 = obliczWspA(kwadrat.getWsp(2), kwadrat.getWsp(3), kwadrat.getWsp(4), kwadrat.getWsp(5));
		double wspB3 = kwadrat.getWsp(3) - wspA3*kwadrat.getWsp(2);
		wiekszy = fmax(kwadrat.getWsp(2), kwadrat.getWsp(4));
		mniejszy = fmin(kwadrat.getWsp(2), kwadrat.getWsp(4));
		//cout << "Wspolczynnik dla x2,y2  |  x3,y3: " << kwadrat.getWsp(2) << ", " << kwadrat.getWsp(3) << "   |   " << kwadrat.getWsp(4) << ", " << kwadrat.getWsp(5) << endl;
		//cout << "Wspolczynnik A: " << wspA3 << endl;
		//cout << "Wspolczynnik B: " << wspB3 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA3, wspB3, this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}

	if (kwadrat.getWsp(4) - kwadrat.getWsp(6) == 0){
		wiekszy = fmax(kwadrat.getWsp(5), kwadrat.getWsp(7));
		mniejszy = fmin(kwadrat.getWsp(5), kwadrat.getWsp(7));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, kwadrat.getWsp(4), this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	else{
		double wspA4 = obliczWspA(kwadrat.getWsp(4), kwadrat.getWsp(5), kwadrat.getWsp(6), kwadrat.getWsp(7));
		double wspB4 = kwadrat.getWsp(5) - wspA4*kwadrat.getWsp(4);
		wiekszy = fmax(kwadrat.getWsp(4), kwadrat.getWsp(6));
		mniejszy = fmin(kwadrat.getWsp(4), kwadrat.getWsp(6));
		//cout << "Wspolczynnik dla x1,y1  |  x4,y4: " << kwadrat.getWsp(4) << ", " << kwadrat.getWsp(5) << "   |   " << kwadrat.getWsp(6) << ", " << kwadrat.getWsp(7) << endl;
		//cout << "Wspolczynnik A: " << wspA4 << endl;
		//cout << "Wspolczynnik B: " << wspB4 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA4, wspB4, this->vektorPunktow[0], this->vektorPunktow[1], this->vektorPunktow[2])){
			return true;
		}
	}
	return false;
}
