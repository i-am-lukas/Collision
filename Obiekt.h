#include "KsztaltyPodstawowe.h"

class Obiekt{
private:
	vector<Kolo> wektorKol;
	vector<Prostokat> wektorProstokatow;
	vector<Trojkat> wektorTrojkatow;
	vector<string> wektorKolizji;
	int id;
	static int hashKod;
	string nazwa;
public:
	Obiekt(string="obiekt");
	~Obiekt();
	int getID();
	string getNazwa();
	void dodajKsztaltPodstawowy(Kolo &);
	void dodajKsztaltPodstawowy(Trojkat &);
	void dodajKsztaltPodstawowy(Prostokat &);
	void pokazKolizje();
	bool czyKoliduje(Obiekt &);
	void obroc(double);
	void przesun(double, double);
	void pokazWspPkt();
};