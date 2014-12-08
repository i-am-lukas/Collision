#include <math.h>
#include <iostream>
#include <string>

using namespace std;

class Trojkat;
class Kwadrat;

class Kolo{

public:
	double x;
	double y;
	double promien;

	Kolo(double = 0, double = 0, double = 0);
	~Kolo();
	void PrintMe();
	void przesun(double = 0, double = 0);
	void obroc(double = 0);
	bool czyKoliduje(Kolo &);
	bool czyKoliduje(Trojkat &);
	//bool czyKoliduje(Kwadrat &);
};

class Trojkat{

public:
	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;

	Trojkat(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0);
	~Trojkat();
	void PrintMe();
	void przesun(double = 0, double = 0);
	void obroc(double = 0);
	//bool czyKoliduje(Kolo &);
	//bool czyKoliduje(Trojkat &);
	//bool czyKoliduje(Kwadrat &);
};

class Kwadrat{

public:
	double x1;
	double y1;
	double x2;
	double y2;
	double x3;
	double y3;
	double x4;
	double y4;

	Kwadrat(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double =0, double =0);
	~Kwadrat();
	void PrintMe();
	void przesun(double=0, double=0);
	void obroc(double = 0);
	//bool czyKoliduje(Kolo &);
	//bool czyKoliduje(Trojkat &);
	//bool czyKoliduje(Kwadrat &);
};


double obliczOdleglosc(double, double, double, double);
double obliczWspB(double x1, double y1, double x2, double y2);
double wyliczPktWspolne(double a1, double b1, double a2, double b2);
double obliczWspA(double x1, double y1, double x2, double y2);
bool czyKolidujeZ(double xMin, double xMax, double wspolczynnikA, double wspolczynnikB, double srodekX, double srodekY, double promien);
bool czyKolidujePIONOWA(double xMin, double xMax, double rownaniePionowej, double srodekX, double srodekY, double promien);