#ifndef ASALTO_H
#define ASALTO_H

#include "Soldado.h"

class Asalto : public Soldado
{
	protected:
		int velocidad;
		int fuerza_extra;
	public:
		Asalto(string,int,int);
		int atacar(bool);
		void defensa(int,bool);
		~Asalto();
	
};

#endif
