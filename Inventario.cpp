#include<iostream>
#include<conio.h>
using namespace std;

void menu(int);
void registrar_pc();

int main(){


    return 0;
}

void menu(int opcion)
{
    system("cls");
    
	cout<<"\t\t\t\t\t   ============================\n";
	cout<<"\t\t\t\t\t       SISTEMA DE INVENTARIO   \n";
	cout<<"\t\t\t\t\t   ============================\n\n\n";
	cout<<"MENU PRINCIPAL\n";
	cout<<"--------------\n\n";
	cout<<"1. Registrar un PC"<<endl;
	cout<<"2. Ver registro de un PC"<<endl;
	cout<<"3. Buscar PC"<<endl ;
	cout<<"6. Ver Todos los PC registrados"<<endl;
	cout<<"7. Salir del Programa"<<endl;
    cout<<"\nIngrese una opcion: ";

    switch (opcion)
    {
    case 1:
        registrar_pc();
        break;
    
    default:
        break;
    }
}

void registrar_pc()
{
	cout<<"Ingrese el nombre del PC: "<<endl;

	cout<<"\nProcesador: "<<endl;
	cout<<"Marca: "<<endl;
	cout<<"Modelo: "<<endl;

	cout<<"\nUnidad de almacenamiento: "<<endl;
	cout<<"\nMarca: "<<endl;
	cout<<"Capacidad: "<<endl;

	cout<<"\nRAM: "<<endl;
	cout<<"\nMarca: "<<endl;
	cout<<"Capacidad: "<<endl;

	cout<<"\nFuente de poder: "<<endl;
	cout<<"\nMarca: "<<endl;
	cout<<"Vatios: "<<endl;

	cout<<"\nPlaca Base: "<<endl;
	cout<<"\nMarca: "<<endl;
	cout<<"Modelo: "endl;
}