
#include "Obiekt.h"

int Obiekt::hashKod = 1000;

Obiekt::Obiekt(string nazwa){
	this->id = this->hashKod;
	this->hashKod++;
	this->nazwa = nazwa;
}

Obiekt::~Obiekt(){

}

string Obiekt::getNazwa(){
	return this->nazwa;
}

int Obiekt::getID(){
	return this->id;
}

void Obiekt::dodajKsztaltPodstawowy(Kolo &kolo){
	this->wektorKol.push_back(kolo);
}

void Obiekt::dodajKsztaltPodstawowy(Trojkat &trojkat){
	this->wektorTrojkatow.push_back(trojkat);
}

void Obiekt::dodajKsztaltPodstawowy(Prostokat &kwadrat){
	this->wektorProstokatow.push_back(kwadrat);
}

void Obiekt::obroc(double stopnie){
	for (int i = 0; i < this->wektorKol.size(); i++){
		this->wektorKol[i].obroc(stopnie);
	}
	for (int i = 0; i < this->wektorTrojkatow.size(); i++){
		this->wektorTrojkatow[i].obroc(stopnie);
	}
	for (int i = 0; i < this->wektorProstokatow.size(); i++){
		this->wektorProstokatow[i].obroc(stopnie);
	}
}

void Obiekt::przesun(double naX, double naY){
	for (int i = 0; i < this->wektorKol.size(); i++){
		this->wektorKol[i].przesun(naX,naY);
	}
	for (int i = 0; i < this->wektorTrojkatow.size(); i++){
		this->wektorTrojkatow[i].przesun(naX, naY);
	}
	for (int i = 0; i < this->wektorProstokatow.size(); i++){
		this->wektorProstokatow[i].przesun(naX, naY);
	}
}

void Obiekt::pokazWspPkt(){
	for (int i = 0; i < this->wektorKol.size(); i++){
		this->wektorKol[i].PrintMe();
	}
	for (int i = 0; i < this->wektorTrojkatow.size(); i++){
		this->wektorTrojkatow[i].PrintMe();
	}
	for (int i = 0; i < this->wektorProstokatow.size(); i++){
		this->wektorProstokatow[i].PrintMe();
	}
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
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisKolo).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramKolo).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorProstokatow.size(); j++){
			Prostokat *paramProstokat = &obiekt.wektorProstokatow[j];

			if ((*thisKolo).czyKoliduje(*paramProstokat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisKolo).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramProstokat).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorTrojkatow.size(); j++){
			Trojkat *paramTrojkat = &obiekt.wektorTrojkatow[j];

			if ((*thisKolo).czyKoliduje(*paramTrojkat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisKolo).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramTrojkat).getIdentyfikator());
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
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisTrojkat).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramKolo).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorProstokatow.size(); j++){
			Prostokat *paramProstokat = &obiekt.wektorProstokatow[j];

			if ((*thisTrojkat).czyKoliduje(*paramProstokat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisTrojkat).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramProstokat).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorTrojkatow.size(); j++){
			Trojkat *paramTrojkat = &obiekt.wektorTrojkatow[j];

			if ((*thisTrojkat).czyKoliduje(*paramTrojkat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisTrojkat).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramTrojkat).getIdentyfikator());
			}

		}
	}

	// Sprawdzam dla kwadratow
	for (int i = 0; i < this->wektorProstokatow.size(); i++){
		Prostokat *thisProstokat = &this->wektorProstokatow[i];

		for (int j = 0; j < obiekt.wektorKol.size(); j++){

			Kolo *paramKolo = &obiekt.wektorKol[j];

			if ((*thisProstokat).czyKoliduje(*paramKolo)){
				czyKoliduje = true;
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisProstokat).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramKolo).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorProstokatow.size(); j++){
			Prostokat *paramProstokat = &obiekt.wektorProstokatow[j];

			if ((*thisProstokat).czyKoliduje(*paramProstokat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisProstokat).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramProstokat).getIdentyfikator());
			}

		}
		for (int j = 0; j < obiekt.wektorTrojkatow.size(); j++){
			Trojkat *paramTrojkat = &obiekt.wektorTrojkatow[j];

			if ((*thisProstokat).czyKoliduje(*paramTrojkat)){
				czyKoliduje = true;
				this->wektorKolizji.push_back(this->getNazwa() + "." + (*thisProstokat).getIdentyfikator() + " koliduje z -> " + obiekt.getNazwa() + "." + (*paramTrojkat).getIdentyfikator());
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
			cout << "   >" + this->wektorKolizji[i] << ";" << endl;
		}
		cout << endl << endl;
	}
}