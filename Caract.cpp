#include "Sala.h"
#include "Unidades.h"
#include "Caract.h"

Respira::Respira() : Unidades()
{
}

void Respira::Respirar(Sala & sala){
	if (sala.TemOxigenio()) {
		sala.UsaOxigenio();
	}
	else {
		Unidades::PerdeVida();
	}
}
