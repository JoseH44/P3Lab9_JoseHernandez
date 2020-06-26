#ifndef SOPORTE_H
#define SOPORTE_H

#include "Soldado.h"

class Soporte : public Soldado
{
	protected:
		int blindaje;
		int camuflaje;
	public:
		Soporte(string,int,int,int,int);
		int atacar(bool);
		void defensa(int,bool);
		size_t getSize();
		int getBlindaje();
		int getCamuflaje();
		~Soporte();
	
};

#endif
