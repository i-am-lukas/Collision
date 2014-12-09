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

	this->vektorPunktow[0] = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->vektorPunktow[1] = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);
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

bool Kolo::czyKoliduje(Kwadrat &kwadrat){
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

/////////////////////////////////////////////// KLASA TROJKAT ///////////////////////

Trojkat::Trojkat(double x1, double y1, double x2, double y2, double x3, double y3,string identyfikator){
	this->vektorPunktow.push_back(x1);
	this->vektorPunktow.push_back(y1);
	this->vektorPunktow.push_back(x2);
	this->vektorPunktow.push_back(y2);
	this->vektorPunktow.push_back(x3);
	this->vektorPunktow.push_back(y3);
	this->identyfikator = identyfikator;
}

Trojkat::~Trojkat(){

}

double Trojkat::getWsp(int i){
	return this->vektorPunktow[i];
}

string Trojkat::getIdentyfikator(){
	return this->identyfikator;
}

void Trojkat::przesun(double wektorX, double wektorY){
	this->vektorPunktow[0] = this->vektorPunktow[0] + wektorX;
	this->vektorPunktow[1] = this->vektorPunktow[1] + wektorY;
	this->vektorPunktow[2] = this->vektorPunktow[2] + wektorX;
	this->vektorPunktow[3] = this->vektorPunktow[3] + wektorY;
	this->vektorPunktow[4] = this->vektorPunktow[4] + wektorX;
	this->vektorPunktow[5] = this->vektorPunktow[5] + wektorY;
}

vector<double> Trojkat::getVec(){
	return this->vektorPunktow;
}

void Trojkat::obroc(double stopnie){
	double rad = (stopnie*3.14159265 / 180);
	double pomocniczyX = this->vektorPunktow[0];
	double pomocniczyY = this->vektorPunktow[1];

	this->vektorPunktow[0] = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->vektorPunktow[1] = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->vektorPunktow[2];
	pomocniczyY = this->vektorPunktow[3];

	this->vektorPunktow[2] = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->vektorPunktow[3] = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->vektorPunktow[4];
	pomocniczyY = this->vektorPunktow[5];

	this->vektorPunktow[4] = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->vektorPunktow[5] = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);
}

void Trojkat::PrintMe(){
	cout << "Trojkat: " << "A(" << this->vektorPunktow[0] << "," << this->vektorPunktow[1] << "); B(" << this->vektorPunktow[2] << "," << this->vektorPunktow[3] << "); C(" << this->vektorPunktow[4] << "," << this->vektorPunktow[5] << ")" << endl;
}

bool Trojkat::czyKoliduje(Kwadrat &kwadrat){

	vector<double> pomocniczy = this->vektorPunktow;
	pomocniczy.push_back(pomocniczy[0]);
	pomocniczy.push_back(pomocniczy[1]);
	vector<double> _pomocniczy = kwadrat.getVec();
	_pomocniczy.push_back(_pomocniczy[0]);
	_pomocniczy.push_back(_pomocniczy[1]);
	double x1, y1, x2, y2;
	double _x1, _y1, _x2, _y2;
	for (int i = 0; i < 6; i = i + 2){
		x1 = pomocniczy[i]; y1 = pomocniczy[i + 1]; x2 = pomocniczy[i + 2]; y2 = pomocniczy[i + 3];
		for (int j = 0; j < 8; j = j + 2){
			_x1 = _pomocniczy[j]; _y1 = _pomocniczy[j + 1]; _x2 = _pomocniczy[j + 2]; _y2 = _pomocniczy[j + 3];

			if (kolizja(x1, y1, x2, y2, _x1, _y1, _x2, _y2)){
				//cout << x1 << ", " << y1 << " | " << x2 << ", " << y2 << " | " << _x1 << ", " << _y1 << " | " << _x2 << ", " << _y2 << endl;
				return true;
			}
		}
	}
	return false;
}

bool Trojkat::czyKoliduje(Kolo &kolo){
	if ((pow(this->getWsp(0) - kolo.getWsp(0), 2) + pow(this->getWsp(1) - kolo.getWsp(1), 2) <= kolo.getWsp(2)) ||
		(pow(this->getWsp(2) - kolo.getWsp(0), 2) + pow(this->getWsp(3) - kolo.getWsp(1), 2) <= kolo.getWsp(2)) ||
		(pow(this->getWsp(4) - kolo.getWsp(0), 2) + pow(this->getWsp(5) - kolo.getWsp(1), 2) <= kolo.getWsp(2))) {
		return true;
	} // Sprawdzenie kazdego wierzcholka. czy nie zawiera sie w kole?
	double wiekszy = 0;
	double mniejszy = 0;
	if (this->getWsp(2) - this->getWsp(0) == 0){
		wiekszy = fmax(this->getWsp(1), this->getWsp(3));
		mniejszy = fmin(this->getWsp(1), this->getWsp(3));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, this->getWsp(0), kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	else{
		double wspA1 = obliczWspA(this->getWsp(0), this->getWsp(1), this->getWsp(2), this->getWsp(3));
		double wspB1 = this->getWsp(1) - wspA1*this->getWsp(0);
		wiekszy = fmax(this->getWsp(0), this->getWsp(2));
		mniejszy = fmin(this->getWsp(0), this->getWsp(2));
		//cout << "Wspolczynnik dla x1,y1  |  x2,y2: " << this->getWsp(0) << ", " << this->getWsp(1) << "   |   " << this->getWsp(2) << ", " << this->getWsp(3) << endl;
		//cout << "Wspolczynnik A: " << wspA1 << endl;
		//cout << "Wspolczynnik B: " << wspB1 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA1, wspB1, kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	if (this->getWsp(4) - this->getWsp(0) == 0){
		wiekszy = fmax(this->getWsp(1), this->getWsp(5));
		mniejszy = fmin(this->getWsp(1), this->getWsp(5));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, this->getWsp(0), kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	else{
		double wspA2 = obliczWspA(this->getWsp(0), this->getWsp(1), this->getWsp(4), this->getWsp(5));
		double wspB2 = this->getWsp(1) - wspA2*this->getWsp(0);
		wiekszy = fmax(this->getWsp(0), this->getWsp(4));
		mniejszy = fmin(this->getWsp(0), this->getWsp(4));
		//cout << "Wspolczynnik dla x1,y1  |  x3,y3: " << this->getWsp(0) << ", " << this->getWsp(1) << "   |   " << this->getWsp(4) << ", " << this->getWsp(5) << endl;
		//cout << "Wspolczynnik A: " << wspA2 << endl;
		//cout << "Wspolczynnik B: " << wspB2 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA2, wspB2, kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}

	if (this->getWsp(2) - this->getWsp(4) == 0){
		wiekszy = fmax(this->getWsp(3), this->getWsp(5));
		mniejszy = fmin(this->getWsp(3), this->getWsp(5));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, this->getWsp(2), kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	else{
		double wspA3 = obliczWspA(this->getWsp(2), this->getWsp(3), this->getWsp(4), this->getWsp(5));
		double wspB3 = this->getWsp(3) - wspA3*this->getWsp(2);
		wiekszy = fmax(this->getWsp(2), this->getWsp(4));
		mniejszy = fmin(this->getWsp(2), this->getWsp(4));
		//cout << "Wspolczynnik dla x2,y2  |  x3,y3: " << this->getWsp(2) << ", " << this->getWsp(3) << "   |   " << this->getWsp(4) << ", " << this->getWsp(5) << endl;
		//cout << "Wspolczynnik A: " << wspA3 << endl;
		//cout << "Wspolczynnik B: " << wspB3 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA3, wspB3, kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	return false;
}

bool Trojkat::czyKoliduje(Trojkat &drugiTrojkat){

	vector<double> pomocniczy = this->vektorPunktow;
	pomocniczy.push_back(pomocniczy[0]);
	pomocniczy.push_back(pomocniczy[1]);
	vector<double> _pomocniczy = drugiTrojkat.vektorPunktow;
	_pomocniczy.push_back(_pomocniczy[0]);
	_pomocniczy.push_back(_pomocniczy[1]);
	double x1, y1, x2, y2;
	double _x1, _y1, _x2, _y2;
	for (int i = 0; i < 6; i = i + 2){
		x1 = pomocniczy[i]; y1 = pomocniczy[i + 1]; x2 = pomocniczy[i + 2]; y2 = pomocniczy[i + 3];
		for (int j = 0; j < 6; j = j + 2){
			_x1 = _pomocniczy[j]; _y1 = _pomocniczy[j + 1]; _x2 = _pomocniczy[j + 2]; _y2 = _pomocniczy[j + 3];

			if (kolizja(x1, y1, x2, y2, _x1, _y1, _x2, _y2)){
				//cout << x1 << ", " << y1 << " " << x2 << ", " << y2 << " " << _x1 << ", " << _y1 << " " << _x2 << ", " << _y2 << endl;
				//cout << i << " " << j << endl;
				return true;
			}
		}
	}
	return false;
}

/////////////////////////////////////////////// KLASA KWADRAT ///////////////////////

Kwadrat::Kwadrat(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, string identyfikator){
	this->vektorPunktow.push_back(x1);
	this->vektorPunktow.push_back(y1);
	this->vektorPunktow.push_back(x2);
	this->vektorPunktow.push_back(y2);
	this->vektorPunktow.push_back(x3);
	this->vektorPunktow.push_back(y3);
	this->vektorPunktow.push_back(x4);
	this->vektorPunktow.push_back(y4);
	this->identyfikator = identyfikator;
}

Kwadrat::~Kwadrat(){

}

double Kwadrat::getWsp(int i){
	return this->vektorPunktow[i];
}

void Kwadrat::przesun(double wektorX, double wektorY){
	this->vektorPunktow[0] = this->vektorPunktow[0] + wektorX;
	this->vektorPunktow[1] = this->vektorPunktow[1] + wektorY;
	this->vektorPunktow[2] = this->vektorPunktow[2] + wektorX;
	this->vektorPunktow[3] = this->vektorPunktow[3] + wektorY;
	this->vektorPunktow[4] = this->vektorPunktow[4] + wektorX;
	this->vektorPunktow[5] = this->vektorPunktow[5] + wektorY;
	this->vektorPunktow[6] = this->vektorPunktow[6] + wektorX;
	this->vektorPunktow[7] = this->vektorPunktow[7] + wektorY;
}

vector<double> Kwadrat::getVec(){
	return this->vektorPunktow;
}

string Kwadrat::getIdentyfikator(){
	return this->identyfikator;
}

bool Kwadrat::czyKoliduje(Trojkat &trojkat){

	vector<double> pomocniczy = this->vektorPunktow;
	pomocniczy.push_back(pomocniczy[0]);
	pomocniczy.push_back(pomocniczy[1]);
	vector<double> _pomocniczy = trojkat.getVec();
	_pomocniczy.push_back(_pomocniczy[0]);
	_pomocniczy.push_back(_pomocniczy[1]);
	double x1, y1, x2, y2;
	double _x1, _y1, _x2, _y2;
	for (int i = 0; i < 8; i = i + 2){
		x1 = pomocniczy[i]; y1 = pomocniczy[i + 1]; x2 = pomocniczy[i + 2]; y2 = pomocniczy[i + 3];
		for (int j = 0; j < 6; j = j + 2){
			_x1 = _pomocniczy[j]; _y1 = _pomocniczy[j + 1]; _x2 = _pomocniczy[j + 2]; _y2 = _pomocniczy[j + 3];

			if (kolizja(x1, y1, x2, y2, _x1, _y1, _x2, _y2)){
				//cout << x1 << ", " << y1 << " " << x2 << ", " << y2 << " " << _x1 << ", " << _y1 << " " << _x2 << ", " << _y2 << endl;
				//cout << i << " " << j << endl;
				return true;
			}
		}
	}
	return false;
}

bool Kwadrat::czyKoliduje(Kolo &kolo){
	if ((pow(getWsp(0) - kolo.getWsp(0), 2) + pow(getWsp(1) - kolo.getWsp(1), 2) <= kolo.getWsp(2)) ||
		(pow(getWsp(2) - kolo.getWsp(0), 2) + pow(getWsp(3) - kolo.getWsp(1), 2) <= kolo.getWsp(2)) ||
		(pow(getWsp(4) - kolo.getWsp(0), 2) + pow(getWsp(5) - kolo.getWsp(1), 2) <= kolo.getWsp(2)) ||
		(pow(getWsp(6) - kolo.getWsp(0), 2) + pow(getWsp(7) - kolo.getWsp(1), 2) <= kolo.getWsp(2))){
		return true;
	} // Sprawdzenie kazdego wierzcholka. czy nie zawiera sie w kole?
	double wiekszy = 0;
	double mniejszy = 0;
	if (getWsp(2) - getWsp(0) == 0){
		wiekszy = fmax(getWsp(1), getWsp(3));
		mniejszy = fmin(getWsp(1), getWsp(3));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, getWsp(0), kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	else{
		double wspA1 = obliczWspA(getWsp(0), getWsp(1), getWsp(2), getWsp(3));
		double wspB1 = getWsp(1) - wspA1*getWsp(0);
		wiekszy = fmax(getWsp(0), getWsp(2));
		mniejszy = fmin(getWsp(0), getWsp(2));
		//cout << "Wspolczynnik dla x1,y1  |  x2,y2: " << getWsp(0) << ", " << getWsp(1) << "   |   " << getWsp(2) << ", " << getWsp(3) << endl;
		//cout << "Wspolczynnik A: " << wspA1 << endl;
		//cout << "Wspolczynnik B: " << wspB1 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA1, wspB1, kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	if (getWsp(6) - getWsp(0) == 0){
		wiekszy = fmax(getWsp(1), getWsp(7));
		mniejszy = fmin(getWsp(1), getWsp(7));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, getWsp(0), kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	else{
		double wspA2 = obliczWspA(getWsp(0), getWsp(1), getWsp(6), getWsp(7));
		double wspB2 = getWsp(1) - wspA2*getWsp(0);
		wiekszy = fmax(getWsp(0), getWsp(6));
		mniejszy = fmin(getWsp(0), getWsp(6));
		cout << "Wspolczynnik dla x1,y1  |  x4,y4: " << getWsp(0) << ", " << getWsp(1) << "   |   " << getWsp(6) << ", " << getWsp(7) << endl;
		cout << "Wspolczynnik A: " << wspA2 << endl;
		cout << "Wspolczynnik B: " << wspB2 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA2, wspB2, kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}

	if (getWsp(2) - getWsp(4) == 0){
		wiekszy = fmax(getWsp(3), getWsp(5));
		mniejszy = fmin(getWsp(3), getWsp(5));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, getWsp(2), kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	else{
		double wspA3 = obliczWspA(getWsp(2), getWsp(3), getWsp(4), getWsp(5));
		double wspB3 = getWsp(3) - wspA3*getWsp(2);
		wiekszy = fmax(getWsp(2), getWsp(4));
		mniejszy = fmin(getWsp(2), getWsp(4));
		cout << "Wspolczynnik dla x2,y2  |  x3,y3: " << getWsp(2) << ", " << getWsp(3) << "   |   " << getWsp(4) << ", " << getWsp(5) << endl;
		cout << "Wspolczynnik A: " << wspA3 << endl;
		cout << "Wspolczynnik B: " << wspB3 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA3, wspB3, kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}

	if (getWsp(4) - getWsp(6) == 0){
		wiekszy = fmax(getWsp(5), getWsp(7));
		mniejszy = fmin(getWsp(5), getWsp(7));
		if (czyKolidujePIONOWA(mniejszy, wiekszy, getWsp(4), kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	else{
		double wspA4 = obliczWspA(getWsp(4), getWsp(5), getWsp(6), getWsp(7));
		double wspB4 = getWsp(5) - wspA4*getWsp(4);
		wiekszy = fmax(getWsp(4), getWsp(6));
		mniejszy = fmin(getWsp(4), getWsp(6));
		cout << "Wspolczynnik dla x1,y1  |  x4,y4: " << getWsp(4) << ", " << getWsp(5) << "   |   " << getWsp(6) << ", " << getWsp(7) << endl;
		cout << "Wspolczynnik A: " << wspA4 << endl;
		cout << "Wspolczynnik B: " << wspB4 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA4, wspB4, kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	return false;
}

bool Kwadrat::czyKoliduje(Kwadrat &drugiKwadrat){

	vector<double> pomocniczy = this->vektorPunktow;
	pomocniczy.push_back(pomocniczy[0]);
	pomocniczy.push_back(pomocniczy[1]);
	vector<double> _pomocniczy = drugiKwadrat.vektorPunktow;
	_pomocniczy.push_back(_pomocniczy[0]);
	_pomocniczy.push_back(_pomocniczy[1]);
	double x1, y1, x2, y2, x3, y3;
	double _x1, _y1, _x2, _y2, _x3, _y3;
	for (int i = 0; i < 8; i = i + 2){
		x1 = pomocniczy[i]; y1 = pomocniczy[i + 1]; x2 = pomocniczy[i + 2]; y2 = pomocniczy[i + 3];
		for (int j = 0; j < 8; j = j + 2){
			_x1 = _pomocniczy[j]; _y1 = _pomocniczy[j + 1]; _x2 = _pomocniczy[j + 2]; _y2 = _pomocniczy[j + 3];

			if (kolizja(x1, y1, x2, y2, _x1, _y1, _x2, _y2)){
				//cout << "(" << x1 << ", " << y1 << ") ; (" << x2 << ", " << y2 << ") ; (" << _x1 << ", " << _y1 << ") ; (" << _x2 << ", " << _y2 << ")" << endl;
				return true;
			}

		}

	}


	return false;

}

void Kwadrat::obroc(double stopnie){
	double rad = (stopnie*3.14159265 / 180);
	double pomocniczyX = this->vektorPunktow[0];
	double pomocniczyY = this->vektorPunktow[1];

	this->vektorPunktow[0] = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->vektorPunktow[1] = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->vektorPunktow[2];
	pomocniczyY = this->vektorPunktow[3];

	this->vektorPunktow[2] = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->vektorPunktow[3] = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->vektorPunktow[4];
	pomocniczyY = this->vektorPunktow[5];

	this->vektorPunktow[4] = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->vektorPunktow[5] = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->vektorPunktow[6];
	pomocniczyY = this->vektorPunktow[7];

	this->vektorPunktow[6] = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->vektorPunktow[7] = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);
}

void Kwadrat::PrintMe(){
	cout << "Kwadrat: " << "A(" << this->vektorPunktow[0] << "," << this->vektorPunktow[1] << "); B(" << this->vektorPunktow[2] << "," << this->vektorPunktow[3] << "); C(" << this->vektorPunktow[4] << "," << this->vektorPunktow[5] << "); D(" << this->vektorPunktow[6] << "," << this->vektorPunktow[7] << ")" << endl;
}

/////////////////////////////////////////////// FUNKCJE GLOBALNE ///////////////////////

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
	else if (Wx == 0 && Wy==0){
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
		x1 = ((2*srodekY)-sqrt(delta))/2;
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