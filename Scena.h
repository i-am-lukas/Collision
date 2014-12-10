
#include "ParyKolidujace.h"

class Scena{
private:
	vector<Obiekt> wektorObiektow;
	vector<ParyKolidujace> wektorPar;
public:
	Scena();
	~Scena();
	int dodajObiekt(string);
	Obiekt* dajObiektPrzezID(int);
	void sprawdzKolizje(int, int);
	void pokazKolizjeObiektow();
	void pokazPary();
	void czyscScene();
	void stworzWektorKolizji();
};