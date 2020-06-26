#include "Asalto.h"

Asalto::Asalto(string hnombre,int hpts_vida,int hpts_fuerza) : Soldado(hnombre,hpts_vida, hpts_fuerza)
{
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


Asalto::~Asalto()
{
}
