#include "KsztaltyPodstawowe.h"

class Obiekt{

private:
	vector<Kolo> wektorKol;
	vector<Kwadrat> wektorKwadratow;
	vector<Trojkat> wektorTrojkatow;
	vector<string> wektorKolizji;
	string identyfikator;
public:
	Obiekt(string);
	~Obiekt();
	string getIdentyfikator();
	void dodajKsztaltPodstawowy(Kolo &);
	void dodajKsztaltPodstawowy(Trojkat &);
	void dodajKsztaltPodstawowy(Kwadrat &);
	void pokazKolizje();
	bool czyKoliduje(Obiekt &);
};