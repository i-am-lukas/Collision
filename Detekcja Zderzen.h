#include "Scena.h"


void sprawdzKolizje(Obiekt &pierwszyObiekt, Obiekt &drugiObiekt);

bool kolizja(double Px1, double Py1, double Px2, double Py2, double Dx1, double Dy1, double Dx2, double Dy2);

double obliczOdleglosc(double x1, double y1, double x2, double y2);

double obliczWspA(double x1, double y1, double x2, double y2);

double obliczWspB(double x1, double y1, double x2, double y2);

double wyliczPktWspolne(double a1, double b1, double a2, double b2);

bool czyKolidujeZ(double xMin, double xMax, double wspolczynnikA, double wspolczynnikB, double srodekX, double srodekY, double promien);

bool czyKolidujePIONOWA(double xMin, double xMax, double rownaniePionowej, double srodekX, double srodekY, double promien);