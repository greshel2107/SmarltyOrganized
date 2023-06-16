#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> 

using namespace std;
class Admin{
	public:
        //UI
        void UIAdmin();
        void partidos();
        void jugadores();

		//Crear Nuevo Usuario
        void crearUsuario();
        bool usuarioRepetido(string);

        //jugadores
		void mostrardatos();
		void agregar_jugadores();
		void modificar_jugadores();
		void eliminar_jugadores();

		// clubes 
		void mostrar_datos_club();
		void agregar_club();
		void modificar_club();
		void eliminar_club();
};
void Admin::UIAdmin(){
    string op; int intOP;
    system("cls");
    cout<<"==============[Administrador]=============="<<endl<<endl;
	cout<<"[1] Administrar jugadores"<<endl;
	cout<<"[2] Administrar clubes"<<endl;
	cout<<"[3] Crear Usuario"<<endl;
	cout<<"[4] Salir"<<endl;
	cout<<"--> ";cin>>op;

    intOP = validarOpcion(op,4);

    switch (intOP){
		case 1: Admin::UIStock(); break;
		case 2: Admin::UIMenu(); break;
		case 3: Admin::crearUsuario(); break;
		case 4: exit(1) ; break;
		default:
			cout<<"Opcion Invalida"<<endl;
			cout<<"--> "; cin>>op; 
		break;
    };
}
//===============[Crear Usuario]================
void Admin::crearUsuario(){
	ofstream archivo;
	string usuario, clave, repetirClave, permisos;
	char op;
	
	archivo.open("Usuariosgre.txt",ios::out|ios::app);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}

    system("cls");
	cout<<"==============[Crear Cuenta]=============="<<endl<<endl;
	cout<<"Ingrese Usuario: "; cin>>usuario;
	cout<<"Ingrese Clave: "; cin>>clave; 
	cout<<"Confirmar Clave: "; cin>>repetirClave;
	
    //Validar usuario
	while(!Admin::usuarioRepetido(usuario)){
		cout<<endl<<"Usuario ya existente, ingrese otro: ";
		cin >> usuario;	
	}
	//Verificar claves
	while(clave != repetirClave){
		cout<<endl<<"!Las claves no coinciden"<<endl;
		cout<<"Ingrese Clave: "; cin>>clave;
		cout<<"Confirmar Clave: "; cin>>repetirClave;
	}
	
    cout<<"Asigne permisos: [1] Jugador| [2] Entrenadores"<<endl;
	cout<<"--> "; cin>>op;
	//Verificar si el valor es numerico
    while(!isdigit(op)){
		cout<<"El valor no es numerico"<<endl; 
        cout<<"--> "; cin>>op;
	}
	switch(op){
		case '1': permisos = "JU"; break;
		case '2': permisos = "ADM"; break;
		default: 
            cout<<"Opcion Invalida"<<endl; 
            cout<<"--> "; cin>>op;
        break;
	}
	//Cargar al archivo
	archivo<<usuario<<" "<<clave<<" "<<permisos<<endl;
	cout<<endl<<"Usuario creado exitosamente"<<endl;
	
	system("pause");
    Admin::UIAdmin();
	archivo.close();
}
bool Admin::usuarioRepetido(string campoSeleccionado ){
	ifstream leerArchivo;
	string campo[3];
	leerArchivo.open("Usuariosgre.txt", ios::in);
	
	leerArchivo >> campo[0];//usuario
	while(!leerArchivo.eof()){
		leerArchivo >> campo[1];//clave
		leerArchivo >> campo[2];//permisos
		if(campo[0] == campoSeleccionado){
			leerArchivo.close();
			return false;
		}
		leerArchivo >> campo[0];//usuario siguiente
	}
	leerArchivo.close();
	return true;
}