#include "Soldado.h"

Soldado::Soldado(string pNombre,int Ppts_vida,int Ppts_fuerza)
{
	nombre = pNombre;
	pts_vida = Ppts_vida;
	pts_fuerza = pts_fuerza;
}


string Soldado::getNombre(){
	return nombre;
}

int Soldado::getPtsVida(){
	return pts_vida;
}

void Soldado::setPtsVida(int newVida){
	pts_vida = newVida;
}

int Soldado::getPtsFuerza(){
	return pts_vida;
}

void Soldado::setPtsFuerza(int newFuerza){
	pts_fuerza = newFuerza;
}

Soldado::~Soldado()
{
}
