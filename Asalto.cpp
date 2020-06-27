#include "Asalto.h"

Asalto::Asalto(int hpts_vida,int hpts_fuerza,int pVelocidad,int pFuerzaXtra) : Soldado(hpts_vida, hpts_fuerza)
{
	velocidad = pVelocidad;
	fuerza_extra = pFuerzaXtra;
}

int Asalto::atacar(bool victima){
	if(victima)//si es true ataca a soldado de asalto
		return pts_fuerza * 10;
	else//en caso de ser falso ataca a un soporte
		return (pts_fuerza * (10 + (velocidad * 2)));
	
}


void Asalto::defensa(int pts_ataque,bool atacante){
	if(atacante)//si es true defiende de un soldado de asalto
		pts_vida -= pts_ataque;
	else
		pts_vida = (pts_vida - (pts_fuerza/fuerza_extra));
	
}

size_t Asalto::getSize(){
	return sizeof(Asalto);
}

int Asalto::getVelocidad(){
	return velocidad;
}

int Asalto::getFuerzaXtra(){
	return fuerza_extra;
}


Asalto::~Asalto()
{
}
