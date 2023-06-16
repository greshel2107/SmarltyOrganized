 #include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "adminGre.cpp"
#include "jugadores.cpp"

using namespace std;

class Usuario : public Admin, public jugadores{ 
	protected:
		string usuario, clave, permisos;	
	public:
		//Setters
		void setUsuario(string);
		void setClave(string);
		void setPermisos(string);
		//Getters
		string getUsuario();
		string getClave();
		string getPermisos();
		//Metodos
		bool validarUsuario();
		void acceder();
};
//=================[Usuario]===================
void Usuario::setUsuario(string nuevoUsuario){
	usuario = nuevoUsuario;
}
string Usuario::getUsuario(){
	return usuario;
}
//==================[Clave]====================
void Usuario::setClave(string nuevaClave){
	clave = nuevaClave;
}
string Usuario::getClave(){
	return clave;
}
//================[Permisos]===================
void Usuario::setPermisos(string nuevoPermisos){
	permisos = nuevoPermisos;
}
string Usuario::getPermisos(){
	return permisos;
}
//==============[Iniciar Sesion]===============
bool Usuario::validarUsuario(){	
	ifstream archivo;
	string aux[3];
	bool existe = false;
	
	archivo.open("Usuariosgre.txt", ios::in);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	//Recorrer archivo Usuarios
	archivo >> aux[0];//usuario
	while(!archivo.eof()){
		archivo >> aux[1];//clave
		archivo >> aux[2];//permisos

		if(aux[0] == usuario && aux[1] == clave ){
			Usuario::setPermisos(aux[2]);
			Usuario::acceder();
			existe = true;
			return true;
		}
		archivo >> aux[0];//usuario siguiente
	}
	//No se encontro el usuario
	if(existe == false){
		cout<<"!!!Usuario o Clave incorrectos!!!"<<endl;
		system("pause");
		return false;
	}
	archivo.close();
}
void Usuario::acceder(){
	string sesion = Usuario::getPermisos();
	
	if( sesion == "ADM"){
		cout<<endl<<"Sesion Iniciada como Administrador"<<endl;
		system("pause");
		Admin::UIAdmin();
	}else{
		cout<<endl<<"Sesion Iniciada como Jugador"<<endl;
		system("pause");
		jugadores::datos();
	}
}