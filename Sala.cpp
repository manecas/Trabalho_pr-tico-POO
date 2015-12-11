#include "Sala.h"

//Sala geral
Sala::Sala() {

}

Sala::~Sala(){

}

//Sala propulsor

void Reparar() {

}

void Danificar() {

}

void Sala::UsaOxigenio(){
	oxigenio--;
}

bool Sala::TemOxigenio() const{

	return (oxigenio > 0);
}
