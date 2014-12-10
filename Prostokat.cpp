#include "KsztaltyPodstawowe.h"

/////////////////////////////////////////////// KLASA KWADRAT ///////////////////////

Prostokat::Prostokat(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, string identyfikator){
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

Prostokat::~Prostokat(){

}

double Prostokat::getWsp(int i){
	return this->vektorPunktow[i];
}

void Prostokat::przesun(double wektorX, double wektorY){
	this->vektorPunktow[0] = this->vektorPunktow[0] + wektorX;
	this->vektorPunktow[1] = this->vektorPunktow[1] + wektorY;
	this->vektorPunktow[2] = this->vektorPunktow[2] + wektorX;
	this->vektorPunktow[3] = this->vektorPunktow[3] + wektorY;
	this->vektorPunktow[4] = this->vektorPunktow[4] + wektorX;
	this->vektorPunktow[5] = this->vektorPunktow[5] + wektorY;
	this->vektorPunktow[6] = this->vektorPunktow[6] + wektorX;
	this->vektorPunktow[7] = this->vektorPunktow[7] + wektorY;
}

vector<double> Prostokat::getVec(){
	return this->vektorPunktow;
}

string Prostokat::getIdentyfikator(){
	return this->identyfikator;
}

bool Prostokat::czyKoliduje(Trojkat &trojkat){

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

bool Prostokat::czyKoliduje(Kolo &kolo){
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
		//cout << "Wspolczynnik dla x1,y1  |  x4,y4: " << getWsp(0) << ", " << getWsp(1) << "   |   " << getWsp(6) << ", " << getWsp(7) << endl;
		//cout << "Wspolczynnik A: " << wspA2 << endl;
		//cout << "Wspolczynnik B: " << wspB2 << endl;
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
		//cout << "Wspolczynnik dla x2,y2  |  x3,y3: " << getWsp(2) << ", " << getWsp(3) << "   |   " << getWsp(4) << ", " << getWsp(5) << endl;
		//cout << "Wspolczynnik A: " << wspA3 << endl;
		//cout << "Wspolczynnik B: " << wspB3 << endl;
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
		//cout << "Wspolczynnik dla x1,y1  |  x4,y4: " << getWsp(4) << ", " << getWsp(5) << "   |   " << getWsp(6) << ", " << getWsp(7) << endl;
		//cout << "Wspolczynnik A: " << wspA4 << endl;
		//cout << "Wspolczynnik B: " << wspB4 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA4, wspB4, kolo.getWsp(0), kolo.getWsp(1), kolo.getWsp(2))){
			return true;
		}
	}
	return false;
}

bool Prostokat::czyKoliduje(Prostokat &drugiProstokat){

	vector<double> pomocniczy = this->vektorPunktow;
	pomocniczy.push_back(pomocniczy[0]);
	pomocniczy.push_back(pomocniczy[1]);
	vector<double> _pomocniczy = drugiProstokat.vektorPunktow;
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

void Prostokat::obroc(double stopnie){
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

	pomocniczyX = this->vektorPunktow[6];
	pomocniczyY = this->vektorPunktow[7];

	this->vektorPunktow[6] = round(pomocniczyX*cos(rad) - pomocniczyY*sin(rad));
	this->vektorPunktow[7] = round(pomocniczyX*sin(rad) + pomocniczyY*cos(rad));
}

void Prostokat::PrintMe(){
	cout << "Prostokat: " << "A(" << this->vektorPunktow[0] << "," << this->vektorPunktow[1] << "); B(" << this->vektorPunktow[2] << "," << this->vektorPunktow[3] << "); C(" << this->vektorPunktow[4] << "," << this->vektorPunktow[5] << "); D(" << this->vektorPunktow[6] << "," << this->vektorPunktow[7] << ")" << endl;
}
