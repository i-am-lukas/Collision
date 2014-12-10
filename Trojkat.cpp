#include "KsztaltyPodstawowe.h"

/////////////////////////////////////////////// KLASA TROJKAT ///////////////////////

Trojkat::Trojkat(double x1, double y1, double x2, double y2, double x3, double y3, string identyfikator){
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

	this->vektorPunktow[0] = round(pomocniczyX*cos(rad) - pomocniczyY*sin(rad));
	this->vektorPunktow[1] = round(pomocniczyX*sin(rad) + pomocniczyY*cos(rad));

	pomocniczyX = this->vektorPunktow[2];
	pomocniczyY = this->vektorPunktow[3];

	this->vektorPunktow[2] = round(pomocniczyX*cos(rad) - pomocniczyY*sin(rad));
	this->vektorPunktow[3] = round(pomocniczyX*sin(rad) + pomocniczyY*cos(rad));

	pomocniczyX = this->vektorPunktow[4];
	pomocniczyY = this->vektorPunktow[5];

	this->vektorPunktow[4] = round(pomocniczyX*cos(rad) - pomocniczyY*sin(rad));
	this->vektorPunktow[5] = round(pomocniczyX*sin(rad) + pomocniczyY*cos(rad));
}

void Trojkat::PrintMe(){
	cout << "Trojkat: " << "A(" << this->vektorPunktow[0] << "," << this->vektorPunktow[1] << "); B(" << this->vektorPunktow[2] << "," << this->vektorPunktow[3] << "); C(" << this->vektorPunktow[4] << "," << this->vektorPunktow[5] << ")" << endl;
}

bool Trojkat::czyKoliduje(Prostokat &kwadrat){

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

