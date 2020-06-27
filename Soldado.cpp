#include "Soldado.h"

Soldado::Soldado(int Ppts_vida,int Ppts_fuerza)
{
	
	pts_vida = Ppts_vida;
	pts_fuerza = Ppts_fuerza;
}




int Soldado::getPtsVida(){
	return pts_vida;
}

void Soldado::setPtsVida(int newVida){
	pts_vida = newVida;
}

int Soldado::getPtsFuerza(){
	return pts_fuerza;
}

void Soldado::setPtsFuerza(int newFuerza){
	pts_fuerza = newFuerza;
}

Soldado::~Soldado()
{
}
