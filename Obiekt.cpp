
#include "Obiekt.h"

Obiekt::Obiekt(string identyfikator){
	this->identyfikator = identyfikator;
}

Obiekt::~Obiekt(){

}

string Obiekt::getIdentyfikator(){
	return this->identyfikator;
}

void Obiekt::dodajKsztaltPodstawowy(Kolo &kolo){
	this->wektorKol.push_back(kolo);
}

void Obiekt::dodajKsztaltPodstawowy(Trojkat &trojkat){
	this->wektorTrojkatow.push_back(trojkat);
}

void Obiekt::dodajKsztaltPodstawowy(Kwadrat &kwadrat){
	this->wektorKwadratow.push_back(kwadrat);
}

bool Obiekt::czyKoliduje(Obiekt &obiekt){
	bool czyKoliduje = false;
	this->wektorKolizji.clear();

	for (int i = 0; i < this->wektorKol.size(); i++){
		Kolo *thisKolo = &this->wektorKol[i];
		
		for (int j = 0; j < obiekt.wektorKol.size(); j++){
			
			Kolo *paramKolo = &obiekt.wektorKol[j];

			if ((*thisKolo).czyKoliduje(*paramKolo)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisKolo).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramKolo).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorKwadratow.size(); j++){
			Kwadrat *paramKwadrat = &obiekt.wektorKwadratow[j];

			if ((*thisKolo).czyKoliduje(*paramKwadrat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisKolo).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramKwadrat).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorTrojkatow.size(); j++){
			Trojkat *paramTrojkat = &obiekt.wektorTrojkatow[j];

			if ((*thisKolo).czyKoliduje(*paramTrojkat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisKolo).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramTrojkat).getIdentyfikator());
			}

		}
	}

	// SPRAWDZAM TROJKATY PIERWSZEGO
	for (int i = 0; i < this->wektorTrojkatow.size(); i++){
		Trojkat *thisTrojkat = &this->wektorTrojkatow[i];

		for (int j = 0; j < obiekt.wektorKol.size(); j++){

			Kolo *paramKolo = &obiekt.wektorKol[j];

			if ((*thisTrojkat).czyKoliduje(*paramKolo)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisTrojkat).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramKolo).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorKwadratow.size(); j++){
			Kwadrat *paramKwadrat = &obiekt.wektorKwadratow[j];

			if ((*thisTrojkat).czyKoliduje(*paramKwadrat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisTrojkat).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramKwadrat).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorTrojkatow.size(); j++){
			Trojkat *paramTrojkat = &obiekt.wektorTrojkatow[j];

			if ((*thisTrojkat).czyKoliduje(*paramTrojkat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisTrojkat).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramTrojkat).getIdentyfikator());
			}

		}
	}

	// Sprawdzam dla kwadratow
	for (int i = 0; i < this->wektorKwadratow.size(); i++){
		Kwadrat *thisKwadrat = &this->wektorKwadratow[i];

		for (int j = 0; j < obiekt.wektorKol.size(); j++){

			Kolo *paramKolo = &obiekt.wektorKol[j];

			if ((*thisKwadrat).czyKoliduje(*paramKolo)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisKwadrat).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramKolo).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorKwadratow.size(); j++){
			Kwadrat *paramKwadrat = &obiekt.wektorKwadratow[j];

			if ((*thisKwadrat).czyKoliduje(*paramKwadrat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisKwadrat).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramKwadrat).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorTrojkatow.size(); j++){
			Trojkat *paramTrojkat = &obiekt.wektorTrojkatow[j];

			if ((*thisKwadrat).czyKoliduje(*paramTrojkat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back("Ksztalt " + (this->getIdentyfikator()) + "." + (*thisKwadrat).getIdentyfikator() + " koliduje z ksztaltem -> " + obiekt.getIdentyfikator() + "." + (*paramTrojkat).getIdentyfikator());
			}

		}
	}
	return czyKoliduje;
}

void Obiekt::pokazKolizje(){
	if (this->wektorKolizji.empty()){
		cout << "Wektor kolizji jest pusty. " << endl;
	}
	else{
		cout << "Nastepujace pary koliduja: " << endl;
		for (int i = 0; i < this->wektorKolizji.size(); i++){
			cout << ">"+this->wektorKolizji[i] << ";" << endl;
		}
	}
}