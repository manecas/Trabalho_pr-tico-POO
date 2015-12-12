#include <iostream>

#include "sala.h"

bool Sala::TemOxigenio() const
{
	return (oxigenio > 0);
}

void Sala::UsaOxigenio()
{
	oxigenio--;
}
