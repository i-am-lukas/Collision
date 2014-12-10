#include "ParyKolidujace.h"

ParyKolidujace::ParyKolidujace(Obiekt &pierwszyObiekt, Obiekt &drugiObiekt){
	this->pierwszyObiekt = &pierwszyObiekt;
	this->drugiObiekt = &drugiObiekt;
}

ParyKolidujace::~ParyKolidujace(){

}

void ParyKolidujace::pokazPare(){
	cout << "> " + pierwszyObiekt->getNazwa() + " <> " + drugiObiekt->getNazwa() << endl;
}

Obiekt* ParyKolidujace::getPierwszy(){
	return this->pierwszyObiekt;
}
Obiekt* ParyKolidujace::getDrugi(){
	return this->drugiObiekt;
}