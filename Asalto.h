#ifndef ASALTO_H
#define ASALTO_H

#include "Soldado.h"

class Asalto : public Soldado
{
	protected:
		int velocidad;
		int fuerza_extra;
	public:
		Asalto(int,int,int,int);
		int atacar(bool);
		void defensa(int,bool);
		int getVelocidad();
		int getFuerzaXtra();
		size_t getSize();
		~Asalto();
	
};

#endif
