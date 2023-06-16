#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string usuario, clave;
	Usuario user;
	
	do{
		system("cls");
		cout<<"===================[Iniciar Sesion]==================="<<endl<<endl;
		cout<<"Ingrese nombre de usuario: ";cin >> usuario;
		cout<<"Ingrese su clave: ";cin >> clave;
		user.setUsuario(usuario);
		user.setClave(clave);
	}while(!user.validarUsuario());
	return 0;
} 