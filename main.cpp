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

/*int num_random;//numero random de la llave
				srand(time(NULL));
				
				num_random = 1 + rand()% (16-1);*/



int main(int argc, char** argv) {
	vector<Soldado*> equipo1;
	vector<Soldado*> equipo2;
	Soldado* soldadoGeneral = NULL;
	
	
	int opcion = 0;
	int subMenu,tipoSol,posicionSoldado;
	string nombre;
	int ptsVida,ptsFuerza,velocidad,fuerzaExtra,blindaje,camuflaje;
	
	cout<<"------BIENVENIDO------"<<endl<<endl;
	while(opcion!=7){
		cout<<"1.Crear Soldado"<<endl<<"2.Eliminar Soldado"<<endl<<"3.Listar Soldados"<<endl
			<<"4.Guardar Solados"<<endl<<"5.Cargar Soldados"<<endl<<"6.Simulacion"<<endl
			<<"7.Salir"<<endl<<"Ingrese La Opcion:";
		
		cin >> opcion;
		
		switch(opcion){
			case 1:{
				
				cout<<endl<<"1.Crear en Equipo#1"<<endl<<"2.Crear en Equipo#2"<<endl<<"Elija la Opcion:";
				cin >> subMenu;
				if(subMenu == 1){
					cout<<endl<<"1.Soldado de Asalto"<<endl<<"2.Soldado de Soporte"<<endl<<"Elija la Opcion:";
					cin>>tipoSol;
					if(tipoSol == 1){
						cout<<endl<<"Ingrese el Nombre del Soldado(Asalto):";
						cin>>nombre;
						cout<<endl<<"Ingrese los Puntos de Vida del Soldado(Asalto):";
						cin>>ptsVida;
						cout<<endl<<"Ingrese los Puntos de Fuerza del Soldado(Asalto):";
						cin>>ptsFuerza;
						cout<<endl<<"Ingrese la Velocidad del Soldado(Asalto):";
						cin>>velocidad;
						cout<<endl<<"Ingrese la Fuerza Extra del Soldado(Asalto):";
						cin>>fuerzaExtra;
						soldadoGeneral = new Asalto(nombre,ptsVida,ptsFuerza,velocidad,fuerzaExtra);
						equipo1.push_back(soldadoGeneral);
						soldadoGeneral = NULL;
					}else if(tipoSol==2){
						cout<<endl<<"Ingrese el Nombre del Soldado(Soporte):";
						cin>>nombre;
						cout<<endl<<"Ingrese los Puntos de Vida del Soldado(Soporte):";
						cin>>ptsVida;
						cout<<endl<<"Ingrese los Puntos de Fuerza del Soldado(Soporte):";
						cin>>ptsFuerza;
						cout<<endl<<"Ingrese el Blindaje del Soldado(Soporte):";
						cin>>blindaje;
						cout<<endl<<"Ingrese el Camuflaje del Soldado(Soporte):";
						cin>>camuflaje;
						soldadoGeneral = new Soporte(nombre,ptsVida,ptsFuerza,blindaje,camuflaje);
						equipo1.push_back(soldadoGeneral);
						soldadoGeneral = NULL;
					}
				}else if(subMenu == 2){
					cout<<endl<<"1.Soldado de Asalto"<<endl<<"2.Soldado de Soporte"<<endl<<"Elija la Opcion:";
					cin>>tipoSol;
					if(tipoSol == 1){
						cout<<endl<<"Ingrese el Nombre del Soldado(Asalto):";
						getline(cin,nombre);
						cout<<endl<<"Ingrese los Puntos de Vida del Soldado(Asalto):";
						cin>>ptsVida;
						cout<<endl<<"Ingrese los Puntos de Fuerza del Soldado(Asalto):";
						cin>>ptsFuerza;
						cout<<endl<<"Ingrese la Velocidad del Soldado(Asalto):";
						cin>>velocidad;
						cout<<endl<<"Ingrese la Fuerza Extra del Soldado(Asalto):";
						cin>>fuerzaExtra;
						soldadoGeneral = new Asalto(nombre,ptsVida,ptsFuerza,velocidad,fuerzaExtra);
						equipo2.push_back(soldadoGeneral);
						soldadoGeneral = NULL;
					}else if(tipoSol==2){
						cout<<endl<<"Ingrese el Nombre del Soldado(Soporte):";
						getline(cin,nombre);
						cout<<endl<<"Ingrese los Puntos de Vida del Soldado(Soporte):";
						cin>>ptsVida;
						cout<<endl<<"Ingrese los Puntos de Fuerza del Soldado(Soporte):";
						cin>>ptsFuerza;
						cout<<endl<<"Ingrese el Blindaje del Soldado(Soporte):";
						cin>>blindaje;
						cout<<endl<<"Ingrese el Camuflaje del Soldado(Soporte):";
						cin>>camuflaje;
						soldadoGeneral = new Soporte(nombre,ptsVida,ptsFuerza,blindaje,camuflaje);
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
					cout<<endl<<"Ingrese la Posicion del Soldado a Eliminar:"<<endl;
					cin>>posicionSoldado;
					delete equipo1[posicionSoldado];
					equipo1.erase(equipo1.begin()+posicionSoldado);
					cout<<endl<<"-Soldado Eliminado-"<<endl;
				}else if(subMenu == 2){
					cout<<endl<<"Ingrese la Posicion del Soldado a Eliminar:"<<endl;
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
						cout<<i<<endl<<"-Nombre:"<<soldado->getNombre()<<endl<<"-Puntos de Vida:"<<soldado->getPtsVida()<<endl;
						if(Asalto* asalto = dynamic_cast<Asalto*>(soldado)){
							cout<<"-Velocidad:"<<asalto->getVelocidad()<<endl<<"-Fuerza Extra:"<<asalto->getFuerzaXtra()<<endl;
						}
						if(Soporte* soporte = dynamic_cast<Soporte*>(soldado)){
							cout<<"-Blindaje:"<<soporte->getBlindaje()<<endl<<"-Camuflaje:"<<soporte->getCamuflaje()<<endl;
						}
						
					}
				}else if(subMenu == 2){
					for(int i = 0;i<equipo2.size();i++){
						Soldado* soldado = equipo2[i];
						cout<<i<<endl<<"-Nombre:"<<soldado->getNombre()<<endl<<"-Puntos de Vida:"<<soldado->getPtsVida()<<endl;
						if(Asalto* asalto = dynamic_cast<Asalto*>(soldado)){
							cout<<"-Velocidad:"<<asalto->getVelocidad()<<endl<<"-Fuerza Extra:"<<asalto->getFuerzaXtra()<<endl;
						}
						if(Soporte* soporte = dynamic_cast<Soporte*>(soldado)){
							cout<<"-Blindaje:"<<soporte->getBlindaje()<<endl<<"-Camuflaje:"<<soporte->getCamuflaje()<<endl;
						}
						
					}
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
				if(subMenu == 1){
					
				}else if(subMenu == 2){
					
				}
				break;
			}
			
			case 6:{
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
