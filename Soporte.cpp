#include "Soporte.h"

Soporte::Soporte(int hpts_vida,int hpts_fuerza,int pBlindaje,int pCamuflaje) : Soldado(hpts_vida, hpts_fuerza)
{
	blindaje = pBlindaje;
	camuflaje = pCamuflaje;
}


int Soporte::atacar(bool victima){
	if(victima)//si es true ataca a soldado de asalto
		return pts_fuerza * (15 + camuflaje);
	else
		return pts_fuerza * 10;
}


void Soporte::defensa(int pts_ataque,bool atacante){
	if(atacante)//si es true defiende de un soldado de asalto
		pts_vida = pts_vida - (pts_ataque/(blindaje * 2));
	else
		pts_vida-= pts_ataque;
	
}

size_t Soporte::getSize(){
	return sizeof(Soporte);
}


int Soporte::getBlindaje(){
	return blindaje;
}


int Soporte::getCamuflaje(){
	return camuflaje;
}

Soporte::~Soporte()
{
}
