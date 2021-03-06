#include <math.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Trojkat;
class Prostokat;

class Kolo{

private:
	vector<double> vektorPunktow;
	string identyfikator;
public:
	Kolo(double = 0, double = 0, double = 0, string = "Kolo");
	~Kolo();
	double getWsp(int i);
	string getIdentyfikator();
	void PrintMe();
	void przesun(double = 0, double = 0);
	void obroc(double = 0);
	bool czyKoliduje(Kolo &);
	bool czyKoliduje(Trojkat &);
	bool czyKoliduje(Prostokat &);
};

class Trojkat{

private:
	vector<double> vektorPunktow;
	string identyfikator;
public:
	Trojkat(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, string = "Trojkat");
	~Trojkat();
	double getWsp(int i);
	string getIdentyfikator();
	vector<double> getVec();
	void PrintMe();
	void przesun(double = 0, double = 0);
	void obroc(double = 0);
	bool czyKoliduje(Kolo &);
	bool czyKoliduje(Trojkat &);
	bool czyKoliduje(Prostokat &);
};

class Prostokat{

private:
	vector<double> vektorPunktow;
	string identyfikator;
public:
	Prostokat(double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, double = 0, string = "Prostokat");
	~Prostokat();
	double getWsp(int i);
	vector<double> getVec();
	string getIdentyfikator();
	void PrintMe();
	void przesun(double = 0, double = 0);
	void obroc(double = 0);
	bool czyKoliduje(Kolo &);
	bool czyKoliduje(Trojkat &);
	bool czyKoliduje(Prostokat &);
};

double obliczOdleglosc(double, double, double, double);
double obliczWspB(double x1, double y1, double x2, double y2);
double wyliczPktWspolne(double a1, double b1, double a2, double b2);
double obliczWspA(double x1, double y1, double x2, double y2);
bool czyKolidujeZ(double xMin, double xMax, double wspolczynnikA, double wspolczynnikB, double srodekX, double srodekY, double promien);
bool czyKolidujePIONOWA(double xMin, double xMax, double rownaniePionowej, double srodekX, double srodekY, double promien);
bool kolizja(double Px1, double Py1, double Px2, double Py2, double Dx1, double Dy1, double Dx2, double Dy2);