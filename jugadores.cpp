#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>


using namespace std;

//=================[Funciones]=====================
bool _esNumero(string cadena){
    bool esNumero = true;
    for(int i=0; i < cadena.length(); i++ ){
        if(!isdigit(cadena[i])){
            esNumero = false;
            break;
        }
    }
    return esNumero;
}
int _validarEntero(string cadena){
    while(!_esNumero(cadena)){
        cout<<"Valor no permitido"<<endl;
        cout<<"--> "; cin>> cadena; 
    }
    int num = stoi(cadena, nullptr);
    return num;
}
int _validarOpcion(string opcion, int opciones){
	int opcionValida;
	int intOpcion;

	while(true){
		//Comprobar si es un digito
		if(!_esNumero(opcion)){
			cout<<"El valor no es numerico"<<endl;
			cout<<"--> "; cin>>opcion;
			continue;
		//Comprobar si la opcion es valida
		}else{
			intOpcion = stoi(opcion, nullptr);//Convetir char a entero
			if(intOpcion < 1 || intOpcion > opciones){
				cout<<"Opcion Invalida"<<endl;
				cout<<"--> ";cin>>opcion;
				continue;
			}else{
				opcionValida = intOpcion;
				break;
			}
		}
	}
	return opcionValida;
}

class jugadores {
    protected:
    public:
//============================= jugadores=========================

    void datos();
    void mostrardatos();
    void mostrar_resultados();
    void agregar_jugadores();
	void modificar_jugadores();
	void eliminar_jugadores();
	void actualizar_jugadores(string);

//============================= Club=========================
    void clubes();

};

//0000000000000000000000000000000000

void jugadores::datos(){
    system("cls");

	jugadores::mostrardatos();
	jugadores::mostrar_resultados();

	string op; int intOP;
	cout<<endl<<"====================================================="<<endl;
	cout<<"{1} Agregar jugador"<<endl;
	cout<<"{2} Modificar jugador"<<endl;
	cout<<"{3} Eliminar jugador"<<endl;
	cout<<"{4} Salir"<<endl;
	cout<<"<3 ";cin>>op;

	intOP = _validarOpcion(op,4);

    switch (intOP){
		case 1: jugadores::agregar_jugadores(); break;
		case 2: jugadores::modificar_jugadores(); break;
		case 3: jugadores::eliminar_jugadores(); break;
		case 4: jugadores::actualizar_jugadores("sumar"); 
        
		default:
			cout<<"Opcion Invalida"<<endl;
			cout<<"--> "; cin>>op; 
		
	}
};

void jugadores::mostrardatos(){
	system("cls");

	string op; int intOP;
	cout<<endl<<"====================================================="<<endl;
	cout<<"[1] Ingresar jugador"<<endl;
	cout<<"[2] Modificar datos del jugador "<<endl;
	cout<<"[3] Eliminar jugador "<<endl;
	cout<<"[4] Salir"<<endl;
	cout<<"--> ";cin>>op;

	intOP = _validarOpcion(op,4);

    switch (intOP){
		case 1: Emp::agregarAlPedido(); break;
		case 2: Emp::modificarPedido(); break;
		case 3: Emp::eliminarDelPedido(); break;
		case 4: Emp::cobrar(); break;
		case 5: Emp::actualizarInventario("sumar"); Emp::vaciarPedido(); exit(1);  break;
		default:
			cout<<"Opcion Invalida"<<endl;
			cout<<"--> "; cin>>op; 
		break;
	}
}