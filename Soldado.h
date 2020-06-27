#ifndef SOLDADO_H
#define SOLDADO_H

#include <string>
using std::string;

class Soldado
{
	protected:
		
		int pts_vida;
		int pts_fuerza;
	public:
		Soldado(int,int);
		virtual int atacar(bool)=0;
		virtual void defensa(int,bool)=0;
		virtual size_t getSize()=0;
		
		
		//setter y getter de pts vida
		int getPtsVida();
		void setPtsVida(int);
		//getter y setter de pts fuerza
		int getPtsFuerza();
		void setPtsFuerza(int);
		~Soldado();
	
};

#endif
