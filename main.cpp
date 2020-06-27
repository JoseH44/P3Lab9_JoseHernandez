#include <iostream>
using namespace std;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include "Soldado.h"
#include "Asalto.h"
#include "Soporte.h"

#include <stdlib.h>
#include <time.h>

#include <typeinfo>

#include <fstream>
using std::ofstream;
using std::ifstream;




int simulacion(vector<Soldado*>,vector<Soldado*>);


int main(int argc, char** argv) {
	vector<Soldado*> equipo1;
	vector<Soldado*> equipo2;
	Soldado* soldadoGeneral = NULL;
	
	
	int opcion = 0;
	int subMenu,tipoSol,posicionSoldado;
	
	
	
	cout<<"------BIENVENIDO------"<<endl<<endl;
	while(opcion!=7){
		cout<<"1.Crear Soldado"<<endl<<"2.Eliminar Soldado"<<endl<<"3.Listar Soldados"<<endl
			<<"4.Guardar Solados"<<endl<<"5.Cargar Soldados"<<endl<<"6.Simulacion"<<endl
			<<"7.Salir"<<endl<<"Ingrese La Opcion:";
		
		cin >> opcion;
		
		switch(opcion){
			case 1:{
				int ptsVida,ptsFuerza,velocidad;
				int fuerzaExtra,blindaje,camuflaje;
				cout<<endl<<"1.Crear en Equipo#1"<<endl<<"2.Crear en Equipo#2"<<endl<<"Elija la Opcion:";
				cin >> subMenu;
				if(subMenu == 1){
					cout<<endl<<"1.Soldado de Asalto"<<endl<<"2.Soldado de Soporte"<<endl<<"Elija la Opcion:";
					cin>>tipoSol;
					if(tipoSol == 1){
						
						cout<<endl<<"Ingrese los Puntos de Vida del Soldado(Asalto):";
						cin>>ptsVida;
						cout<<endl<<"Ingrese los Puntos de Fuerza del Soldado(Asalto):";
						cin>>ptsFuerza;
						cout<<endl<<"Ingrese la Velocidad del Soldado(Asalto):";
						cin>>velocidad;
						cout<<endl<<"Ingrese la Fuerza Extra del Soldado(Asalto):";
						cin>>fuerzaExtra;
						cout<<endl<<"DATOS->"<<ptsVida<<ptsFuerza<<velocidad<<fuerzaExtra<<endl;
						
						soldadoGeneral = new Asalto(ptsVida,ptsFuerza,velocidad,fuerzaExtra);
						equipo1.push_back(soldadoGeneral);
						soldadoGeneral = NULL;
					}else if(tipoSol==2){
						
						cout<<endl<<"Ingrese los Puntos de Vida del Soldado(Soporte):";
						cin>>ptsVida;
						cout<<endl<<"Ingrese los Puntos de Fuerza del Soldado(Soporte):";
						cin>>ptsFuerza;
						cout<<endl<<"Ingrese el Blindaje del Soldado(Soporte):";
						cin>>blindaje;
						cout<<endl<<"Ingrese el Camuflaje del Soldado(Soporte):";
						cin>>camuflaje;
						soldadoGeneral = new Soporte(ptsVida,ptsFuerza,blindaje,camuflaje);
						equipo1.push_back(soldadoGeneral);
						soldadoGeneral = NULL;
					}
				}else if(subMenu == 2){
					cout<<endl<<"1.Soldado de Asalto"<<endl<<"2.Soldado de Soporte"<<endl<<"Elija la Opcion:";
					cin>>tipoSol;
					if(tipoSol == 1){
						
						cout<<endl<<"Ingrese los Puntos de Vida del Soldado(Asalto):";
						cin>>ptsVida;
						cout<<endl<<"Ingrese los Puntos de Fuerza del Soldado(Asalto):";
						cin>>ptsFuerza;
						cout<<endl<<"Ingrese la Velocidad del Soldado(Asalto):";
						cin>>velocidad;
						cout<<endl<<"Ingrese la Fuerza Extra del Soldado(Asalto):";
						cin>>fuerzaExtra;
						soldadoGeneral = new Asalto(ptsVida,ptsFuerza,velocidad,fuerzaExtra);
						equipo2.push_back(soldadoGeneral);
						soldadoGeneral = NULL;
					}else if(tipoSol==2){
						
						cout<<endl<<"Ingrese los Puntos de Vida del Soldado(Soporte):";
						cin>>ptsVida;
						cout<<endl<<"Ingrese los Puntos de Fuerza del Soldado(Soporte):";
						cin>>ptsFuerza;
						cout<<endl<<"Ingrese el Blindaje del Soldado(Soporte):";
						cin>>blindaje;
						cout<<endl<<"Ingrese el Camuflaje del Soldado(Soporte):";
						cin>>camuflaje;
						soldadoGeneral = new Soporte(ptsVida,ptsFuerza,blindaje,camuflaje);
						equipo2.push_back(soldadoGeneral);
						soldadoGeneral = NULL;
					}
				}//else if del equipo
				break;
			}
			case 2:{
				cout<<endl<<"1.Eliminar en Equipo#1"<<endl<<"2.Eliminar en Equipo#2"<<endl<<"Elija la Opcion:";
				cin >> subMenu;
				if(subMenu == 1){
					cout<<endl<<"Ingrese la Posicion del Soldado a Eliminar:";
					cin>>posicionSoldado;
					delete equipo1[posicionSoldado];
					equipo1.erase(equipo1.begin()+posicionSoldado);
					cout<<endl<<"-Soldado Eliminado-"<<endl;
				}else if(subMenu == 2){
					cout<<endl<<"Ingrese la Posicion del Soldado a Eliminar:";
					cin>>posicionSoldado;
					delete equipo2[posicionSoldado];
					equipo1.erase(equipo2.begin()+posicionSoldado);
					cout<<endl<<"-Soldado Eliminado-"<<endl;
				}//else if del equipo
				break;
			}
			case 3:{
				cout<<endl<<"1.Listar Equipo#1"<<endl<<"2.Listar Equipo#2"<<endl<<"Elija la Opcion:";
				cin >> subMenu;
				cout<<endl;
				if(subMenu == 1){
					for(int i = 0;i<equipo1.size();i++){
						Soldado* soldado = equipo1[i];
						cout<<i<<endl<<"-Puntos de Vida:"<<soldado->getPtsVida()<<endl<<"-Puntos de Fuerza:"<<soldado->getPtsFuerza()<<endl;
						if(Asalto* asalto = dynamic_cast<Asalto*>(soldado)){
							cout<<"-Velocidad:"<<asalto->getVelocidad()<<endl<<"-Fuerza Extra:"<<asalto->getFuerzaXtra()<<endl;
						}
						if(Soporte* soporte = dynamic_cast<Soporte*>(soldado)){
							cout<<"-Blindaje:"<<soporte->getBlindaje()<<endl<<"-Camuflaje:"<<soporte->getCamuflaje()<<endl;
						}
						
					}
					cout<<endl;
				}else if(subMenu == 2){
					for(int i = 0;i<equipo2.size();i++){
						Soldado* soldado = equipo2[i];
						cout<<i<<endl<<"-Puntos de Vida:"<<soldado->getPtsVida()<<endl<<"-Puntos de Fuerza:"<<soldado->getPtsFuerza()<<endl;
						if(Asalto* asalto = dynamic_cast<Asalto*>(soldado)){
							cout<<"-Velocidad:"<<asalto->getVelocidad()<<endl<<"-Fuerza Extra:"<<asalto->getFuerzaXtra()<<endl;
						}
						if(Soporte* soporte = dynamic_cast<Soporte*>(soldado)){
							cout<<"-Blindaje:"<<soporte->getBlindaje()<<endl<<"-Camuflaje:"<<soporte->getCamuflaje()<<endl;
						}
						
					}
					cout<<endl;
				}
				break;
			}
			
			case 4:{
				cout<<endl<<"1.Guardar Equipo#1"<<endl<<"2.Guardar Equipo#2"<<endl<<"Elija la Opcion:";
				cin >> subMenu;
				Soldado* padre = NULL;
				size_t tempSize=0;
				if(subMenu == 1){
					ofstream file1("equipo1.bin",ios::binary|ios::trunc);
					if(!file1.is_open()){
						//nada
					}else{
						for(int i = 0;i<equipo1.size();i++){
							padre = equipo1[i];
							tempSize = padre->getSize();
							file1.write((char*)&tempSize,sizeof(size_t));
							file1.write( (char*) padre,tempSize);
						}
					}
					file1.close();
					
				}else if(subMenu == 2){
					ofstream file2("equipo2.bin",ios::binary|ios::trunc);
					if(!file2.is_open()){
						//nada
					}else{
						for(int i = 0;i<equipo2.size();i++){
							padre = equipo2[i];
							tempSize = padre->getSize();
							file2.write((char*)&tempSize,sizeof(size_t));
							file2.write( (char*) padre,tempSize);
						}
					}
					file2.close();
				}
				break;
			}
			
			case 5:{
				cout<<endl<<"1.Cargar Equipo#1"<<endl<<"2.Cargar Equipo#2"<<endl<<"Elija la Opcion:";
				cin >> subMenu;
				size_t tempSize=0;
				Soldado* padre1 = NULL;
				
				if(subMenu == 1){
					ifstream file("equipo1.bin",ios::binary);
					while(file.read((char*)&tempSize, sizeof(size_t))){
						padre1 = (Soldado*) malloc(tempSize);
						file.read((char*)padre1,tempSize);
						equipo1.push_back(padre1);
					}
					
					file.close();
				}else if(subMenu == 2){
					ifstream f_ile("equipo2.bin",ios::binary);
					
					while(f_ile.read((char*)&tempSize, sizeof(size_t))){
						padre1 = (Soldado*) malloc(tempSize);
						f_ile.read((char*)padre1,tempSize);
						equipo2.push_back(padre1);
					}
					
					f_ile.close();
				}
				break;
			}
			
			case 6:{
				if(simulacion(equipo1,equipo2) == 0)
					cout << "-Simulacion Terminada-";
				break;
			}
			
			case 7:{
				cout<<endl<<"----VUELVA PRONTO----";
				break;
			}
			
			
			
		}//fin del case principal
	}//fin del while principal
	
	for(int i = 0;i<equipo1.size();i++){
		delete equipo1[i];
	}
	for(int i = 0;i<equipo2.size();i++){
		delete equipo2[i];
	}
	equipo1.clear();
	equipo2.clear();
	
	delete soldadoGeneral;
	
	return 0;
}

//funcion de simulacion
int simulacion(vector<Soldado*> equipo1,vector<Soldado*> equipo2){
	bool turno = true;
	int situacion = 0;
	int ataque;
	int randomAtacante,randomDefensor;//numeros random para el atacando y defensor
	srand(time(NULL));
	
	int size_equipo1 = equipo1.size();
	int size_equipo2 = equipo2.size();
	Soldado* atacante = NULL;
	Soldado* defensor = NULL;
	while(situacion!=1){
		
		if(turno){
			
			randomAtacante = 0 + rand()%((size_equipo1+1) - 1);
			atacante = equipo1[randomAtacante];
			randomDefensor = 0 + rand()%((size_equipo2+1) - 1);
			defensor = equipo2[randomDefensor];
			if(Asalto* asalto = dynamic_cast<Asalto*>(atacante)){
				if(Asalto* asalto_n = dynamic_cast<Asalto*>(defensor)){
					ataque = asalto->atacar(true);
					asalto_n->defensa(ataque,true);
					if(asalto_n->getPtsVida() <= 0){
						delete equipo2[randomDefensor];
						equipo2.erase(equipo2.begin()+randomDefensor);
					}
				}
				
				if(Soporte* soporte_n = dynamic_cast<Soporte*>(defensor)){
					ataque = asalto->atacar(false);
					soporte_n->defensa(ataque,true);
					if(soporte_n->getPtsVida() <= 0){
						delete equipo2[randomDefensor];
						equipo2.erase(equipo2.begin()+randomDefensor);
					}
				}
			}
			
			if(Soporte* soporte = dynamic_cast<Soporte*>(atacante)){
				if(Asalto* asalto_n = dynamic_cast<Asalto*>(defensor)){
					ataque = soporte->atacar(true);//ataque
					asalto_n->defensa(ataque,true);//defensa
					if(asalto_n->getPtsVida() <= 0){
						delete equipo2[randomDefensor];
						equipo2.erase(equipo2.begin()+randomDefensor);
					}
				}
				
				if(Soporte* soporte_n = dynamic_cast<Soporte*>(defensor)){
					ataque = soporte->atacar(false);
					soporte_n->defensa(ataque,true);
					if(soporte_n->getPtsVida() <= 0){
						delete equipo2[randomDefensor];
						equipo2.erase(equipo2.begin()+randomDefensor);
					}
				}
			}
			
			
			//validacion de tamaño
			if(equipo2.size() == 0)
				situacion = 1;
			else
				turno = false;
			cout<<endl<<"---EQUIPO#1 ES EL VENCEDOR---";
			
			
		}else{//turno del equipo 2
			randomAtacante = 0 + rand()%((size_equipo2+1) - 1);
			atacante = equipo2[randomAtacante];
			randomDefensor = 0 + rand()%((size_equipo1+1) - 1);
			defensor = equipo1[randomDefensor];
			//si el atacante es soldado de asalto
			if(Asalto* asalto = dynamic_cast<Asalto*>(atacante)){
				if(Asalto* asalto_n = dynamic_cast<Asalto*>(defensor)){
					ataque = asalto->atacar(true);
					asalto_n->defensa(ataque,true);
					if(asalto_n->getPtsVida() <= 0){
						delete equipo1[randomDefensor];
						equipo1.erase(equipo1.begin()+randomDefensor);
					}
				}
				
				if(Soporte* soporte_n = dynamic_cast<Soporte*>(defensor)){
					ataque = asalto->atacar(false);
					soporte_n->defensa(ataque,true);
					if(soporte_n->getPtsVida() <= 0){
						delete equipo1[randomDefensor];
						equipo1.erase(equipo1.begin()+randomDefensor);
					}
				}
			}
			//si el atacante es soldado de soporte
			if(Soporte* soporte = dynamic_cast<Soporte*>(atacante)){
				if(Asalto* asalto_n = dynamic_cast<Asalto*>(defensor)){
					ataque = soporte->atacar(true);//ataque
					asalto_n->defensa(ataque,true);//defensa
					if(asalto_n->getPtsVida() <= 0){
						delete equipo1[randomDefensor];
						equipo1.erase(equipo1.begin()+randomDefensor);
					}
				}
				
				if(Soporte* soporte_n = dynamic_cast<Soporte*>(defensor)){
					ataque = soporte->atacar(false);
					soporte_n->defensa(ataque,true);
					if(soporte_n->getPtsVida() <= 0){
						delete equipo1[randomDefensor];
						equipo1.erase(equipo1.begin()+randomDefensor);
					}
				}
			}
			
			if(equipo1.size() == 0)
				situacion = 1;
			else
				turno = true;
			cout<<endl<<"---EQUIPO#2 ES EL VENCEDOR---";
		}
	}//fin del while
	
	return 0;
	
	
}
