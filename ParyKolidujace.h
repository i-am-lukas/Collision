
#include "Obiekt.h"

class ParyKolidujace{
private:
	Obiekt *pierwszyObiekt;
	Obiekt *drugiObiekt;
public:
	ParyKolidujace(Obiekt &, Obiekt &);
	~ParyKolidujace();
	Obiekt* getPierwszy();
	Obiekt* getDrugi();
	void pokazPare();
};