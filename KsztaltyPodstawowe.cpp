#include "KsztaltyPodstawowe.h"



/////////////////////////////////////////////// KLASA KOLO ///////////////////////

Kolo::Kolo(double wspX, double wspY, double promien){
	this->promien = promien;
	this->x = wspX;
	this->y = wspY;
}

Kolo::~Kolo(){

}

bool Kolo::czyKoliduje(Kolo &drugieKolo){
	double odleglosc = obliczOdleglosc(this->x, this->y, drugieKolo.x, drugieKolo.y);
	double suma = this->promien + drugieKolo.promien;
	if (odleglosc > suma){
		return false;
	}
	else{
		return true;
	}
}

void Kolo::PrintMe(){
	cout << "Kolo: " << "Sr(" << x << "," << y << "), Promien: " << promien << endl;
}

void Kolo::przesun(double wektorX, double wektorY){
	this->x = this->x + wektorX;
	this->y = this->y + wektorY;
}
// x'=xcos& - ysin&; y'=xsin& + ycos& 
void Kolo::obroc(double stopnie){
	double rad = (stopnie*3.14159265 / 180);
	double pomocniczyX = this->x;
	double pomocniczyY = this->y;

	this->x = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->y = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);
}

bool Kolo::czyKoliduje(Trojkat &trojkat){
	double wiekszy = 0;
	double mniejszy = 0;
	if (trojkat.x2 - trojkat.x1 == 0){
		wiekszy = fmax(trojkat.y1, trojkat.y2);
		mniejszy = fmin(trojkat.y1, trojkat.y2);
		if (czyKolidujePIONOWA(mniejszy, wiekszy, trojkat.x1, this->x, this->y, this->promien)){
			return true;
		}
	}
	else{
		double wspA1 = obliczWspA(trojkat.x1, trojkat.y1, trojkat.x2, trojkat.y2);
		double wspB1 = trojkat.y1 - wspA1*trojkat.x1;
		wiekszy = fmax(trojkat.x1, trojkat.x2);
		mniejszy = fmin(trojkat.x1, trojkat.x2);
		cout << "Wspolczynnik dla x1,y1,x2,y2: " << trojkat.x1 << ", " << trojkat.y1 << ", " << trojkat.x2 << ", " << trojkat.y2 << endl;
		cout << "Wspolczynnik A: " << wspA1 << endl;
		cout << "Wspolczynnik B: " << wspB1 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA1, wspB1, this->x, this->y, this->promien)){
			return true;
		}
	}
	if (trojkat.x3 - trojkat.x1 == 0){
		wiekszy = fmax(trojkat.y1, trojkat.y3);
		mniejszy = fmin(trojkat.y1, trojkat.y3);
		if (czyKolidujePIONOWA(mniejszy, wiekszy, trojkat.x1, this->x, this->y, this->promien)){
			return true;
		}
	}
	else{
		double wspA2 = obliczWspA(trojkat.x1, trojkat.y1, trojkat.x3, trojkat.y3);
		double wspB2 = trojkat.y1 - wspA2*trojkat.x1;
		wiekszy = fmax(trojkat.x1, trojkat.x3);
		mniejszy = fmin(trojkat.x1, trojkat.x3);
		cout << "Wspolczynnik dla x1,y1,x3,y3: " << trojkat.x1 << ", " << trojkat.y1 << ", " << trojkat.x3 << ", " << trojkat.y3 << endl;
		cout << "Wspolczynnik A: " << wspA2 << endl;
		cout << "Wspolczynnik B: " << wspB2 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA2, wspB2, this->x, this->y, this->promien)){
			return true;
		}
	}

	if (trojkat.x2 - trojkat.x3 == 0){
		wiekszy = fmax(trojkat.y2, trojkat.y3);
		mniejszy = fmin(trojkat.y2, trojkat.y3);
		if (czyKolidujePIONOWA(mniejszy, wiekszy, trojkat.x2, this->x, this->y, this->promien)){
			return true;
		}
	}
	else{
		double wspA3 = obliczWspA(trojkat.x2, trojkat.y2, trojkat.x3, trojkat.y3);
		double wspB3 = trojkat.y2 - wspA3*trojkat.x2;
		wiekszy = fmax(trojkat.x2, trojkat.x3);
		mniejszy = fmin(trojkat.x2, trojkat.x3);
		cout << "Wspolczynnik dla x2,y2,x3,y3: " << trojkat.x2 << ", " << trojkat.y2 << ", " << trojkat.x3 << ", " << trojkat.y3 << endl;
		cout << "Wspolczynnik A: " << wspA3 << endl;
		cout << "Wspolczynnik B: " << wspB3 << endl;
		if (czyKolidujeZ(mniejszy, wiekszy, wspA3, wspB3, this->x, this->y, this->promien)){
			return true;
		}
	}
	return false;
}

/////////////////////////////////////////////// KLASA TROJKAT ///////////////////////

Trojkat::Trojkat(double x1, double y1, double x2, double y2, double x3, double y3){
	this->x1 = x1;
	this->x2 = x2;
	this->x3 = x3;
	this->y1 = y1;
	this->y2 = y2;
	this->y3 = y3;
}

Trojkat::~Trojkat(){

}

void Trojkat::przesun(double wektorX, double wektorY){
	this->x1 = this->x1 + wektorX;
	this->y1 = this->y1 + wektorY;
	this->x2 = this->x2 + wektorX;
	this->y2 = this->y2 + wektorY;
	this->x3 = this->x3 + wektorX;
	this->y3 = this->y3 + wektorY;
}

void Trojkat::obroc(double stopnie){
	double rad = (stopnie*3.14159265 / 180);
	double pomocniczyX = this->x1;
	double pomocniczyY = this->y1;

	this->x1 = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->y1 = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->x2;
	pomocniczyY = this->y2;

	this->x2 = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->y2 = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->x3;
	pomocniczyY = this->y3;

	this->x3 = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->y3 = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);
}

void Trojkat::PrintMe(){
	cout << "Trojkat: " << "A(" << x1 << "," << y1 << "); B(" << x2 << "," << y2 << "); C(" << x3 << "," << y3 << ")" << endl;
}

/////////////////////////////////////////////// KLASA KWADRAT ///////////////////////

Kwadrat::Kwadrat(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
	this->x3 = x3;
	this->y3 = y3;
	this->x4 = x4;
	this->y4 = y4;
}

Kwadrat::~Kwadrat(){

}

void Kwadrat::przesun(double wektorX, double wektorY){
	this->x1 = this->x1 + wektorX;
	this->y1 = this->y1 + wektorY;
	this->x2 = this->x2 + wektorX;
	this->y2 = this->y2 + wektorY;
	this->x3 = this->x3 + wektorX;
	this->y3 = this->y3 + wektorY;
	this->x4 = this->x4 + wektorX;
	this->y4 = this->y4 + wektorY;
}

void Kwadrat::obroc(double stopnie){
	double rad = (stopnie*3.14159265 / 180);
	double pomocniczyX = this->x1;
	double pomocniczyY = this->y1;

	this->x1 = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->y1 = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->x2;
	pomocniczyY = this->y2;

	this->x2 = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->y2 = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->x3;
	pomocniczyY = this->y3;

	this->x3 = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->y3 = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);

	pomocniczyX = this->x4;
	pomocniczyY = this->y4;

	this->x4 = pomocniczyX*cos(rad) - pomocniczyY*sin(rad);
	this->y4 = pomocniczyX*sin(rad) + pomocniczyY*cos(rad);
}

void Kwadrat::PrintMe(){
	cout << "Kwadrat: " << "A(" << x1 << "," << y1 << "); B(" << x2 << "," << y2 << "); C(" << x3 << "," << y3 << "); D(" << x4 << "," << y4 << ")" << endl;
}
/////////////////////////////////////////////// FUNKCJE GLOBALNE ///////////////////////

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
	cout << "Zakres figury: " << xMin << ", " << xMax << endl;
	if (delta == 0){
		x1 = (2 * srodekX - 2 * wspolczynnikA*(wspolczynnikB - srodekY)) / (2 * (1 + wspolczynnikA*wspolczynnikA));
		cout << "Delta = 0 : Jeden pierwiastek : " << x1 << endl;
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
		cout << "Delta > 0 : Pierwszy : " << x1 << " Drugi: "<<x2<<endl;
		if (((x1 <= xMax) && (x1 >= xMin)) || ((x2 <= xMax) && (x2 >= xMin))){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		cout << "Delta < 0" << endl;
		return false;
	}
}

bool czyKolidujePIONOWA(double xMin, double xMax, double rownaniePionowej, double srodekX, double srodekY, double promien){
	double delta = ((-2)*srodekY)*((-2)*srodekY) - 4 * (srodekY*srodekY - promien*promien + rownaniePionowej*rownaniePionowej - 2 * rownaniePionowej*srodekX + srodekX*srodekX);
	double x1 = 0;
	double x2 = 0;
	cout << "Zakres figury: " << xMin << ", " << xMax << endl;
	if (delta == 0){
		x1 = srodekY;
		cout << "Delta = 0 : Jeden pierwiastek : " << x1 << endl;
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
		cout << "Delta > 0 : Pierwszy : " << x1 << " Drugi: " << x2 << endl;
		if (((x1 <= xMax) && (x1 >= xMin)) || ((x2 <= xMax) && (x2 >= xMin))){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		cout << "Delta < 0" << endl;
		return false;
	}
}