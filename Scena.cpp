#include "Scena.h"

Scena::Scena(){

}

Scena::~Scena(){
}

int Scena::dodajObiekt(string nazwa){
	Obiekt obiekt = Obiekt(nazwa);
	this->wektorObiektow.push_back(obiekt);
	return obiekt.getID();
}

Obiekt* Scena::dajObiektPrzezID(int identyfikator){
	for (int i = 0; i < this->wektorObiektow.size(); i++){
		if (this->wektorObiektow[i].getID() == identyfikator){
			return &(this->wektorObiektow[i]);
		}
	}
	return nullptr;
}

void Scena::czyscScene(){
	this->wektorObiektow.clear();
}

void Scena::pokazKolizjeObiektow(){
	this->wektorPar.clear();
	for (int i = 0; i < this->wektorObiektow.size(); i++){
		for (int j = i + 1; j < this->wektorObiektow.size(); j++){
			if (this->wektorObiektow[i].czyKoliduje(this->wektorObiektow[j])){
				ParyKolidujace para = ParyKolidujace(this->wektorObiektow[i], this->wektorObiektow[j]);
				para.pokazPare();
				this->wektorObiektow[i].pokazKolizje();
			}
		}
	}
}

void Scena::stworzWektorKolizji(){
	this->wektorPar.clear();
	for (int i = 0; i < this->wektorObiektow.size(); i++){
		for (int j = i + 1; j < this->wektorObiektow.size(); j++){
			if (this->wektorObiektow[i].czyKoliduje(this->wektorObiektow[j])){
				ParyKolidujace para = ParyKolidujace(this->wektorObiektow[i], this->wektorObiektow[j]);
				this->wektorPar.push_back(para);
			}
		}
	}
}

void Scena::sprawdzKolizje(int id1, int id2){
	Obiekt *pierwszyObiekt;
	Obiekt *drugiObiekt;
	pierwszyObiekt=dajObiektPrzezID(id1);
	drugiObiekt = dajObiektPrzezID(id2);

	if (pierwszyObiekt->czyKoliduje(*drugiObiekt)){
		cout << "OBIEKT: " + pierwszyObiekt->getNazwa() + " ORAZ " + drugiObiekt->getNazwa() + " KOLIDUJA!" << endl;
		pierwszyObiekt->pokazKolizje();
	}

	else{
		cout << "OBIEKT: " + pierwszyObiekt->getNazwa() + " ORAZ " + drugiObiekt->getNazwa() + " NIE KOLIDUJA!" << endl;
	}
}

void Scena::pokazPary(){
	for (int i = 0; i < this->wektorPar.size(); i++){
		this->wektorPar[i].pokazPare();
	}
}
