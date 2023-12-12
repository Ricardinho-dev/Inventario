#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

class PC{ 
	public:
		char nombre[30];
    	char fuente_p[30];
		char procesador[30];
		char ram[30];
		char rom[30];
		char placa_b[30];
	public:
			void ingreso();
			void actualizar();
			void eliminar();
			void buscar();

};

void menu();
void registrar_pc();
void consulta();
void ver_todos();

int main(){
	menu();
    return 0;
}

void menu()
{
	int opcion;
    system("cls");
    
	do{
	cout<<"============================\n";
	cout<<"     SISTEMA DE INVENTARIO   \n";
	cout<<"============================\n\n\n";
	cout<<"MENU PRINCIPAL\n";
	cout<<"--------------\n\n";
	cout<<"1. Registrar un PC"<<endl;
	cout<<"2. Ver registro de un PC"<<endl;
	cout<<"3. Actualizar datos de un PC"<<endl;
	cout<<"4. Eliminar registro de un PC"<<endl;
	cout<<"5. Ver Todos los PC registrados"<<endl;
	cout<<"6. Salir del Programa"<<endl;
    cout<<"\nIngrese una opcion: ";
	cin>>opcion;
	}while (opcion<0 && opcion>=6);

    switch (opcion)
    {
    case 1:
        registrar_pc();
        break;
    case 2:
		consulta();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		ver_todos(); 
		break;
	case 6:
		break;
    default:
        break;
    }
}

void registrar_pc(){

	FILE *bin, *texto;
	PC nuevo, comparar;
	char r;

	system("cls");

	if (((bin = fopen("Archivo Binario","a+b"))==NULL) ||((texto = fopen("Archivo Datos","a+b"))==NULL))
	{
		cout<<"No se logró abrir el archivo"<<endl;
		system("pause");
	}
	
	rewind(bin); //mueve el puntero del archivo al principio del archivo
	fflush(stdin);

	cout<<"Ingrese el nombre del PC: "<<endl;
	gets(nuevo.nombre);

	fread(&comparar, sizeof(PC), 1, bin);
	
	while (!feof(bin))
	{
		if(strcmp(nuevo.nombre, comparar.nombre) == 0){
		cout<<"Esta PC ya esta registrada. Ingrese nuevamente: "<<endl;
		gets(nuevo.nombre);}
		
		fread(&comparar, sizeof(PC), 1, bin);
	}
	
	
	cout<<"\nA continuacion ingrese los datos de los componentes"<<endl;

	cout<<"\nProcesador "<<endl;
	gets(nuevo.procesador);
	cout<<"Marca: "<<endl;
	cout<<"Modelo: "<<endl;

	cout<<"\nUnidad de almacenamiento "<<endl;
	gets(nuevo.rom);
	cout<<"Marca: "<<endl;
	cout<<"Capacidad: "<<endl;

	cout<<"\nRAM: "<<endl;
	gets(nuevo.ram);
	cout<<"Marca: "<<endl;
	cout<<"Capacidad: "<<endl;

	cout<<"\nFuente de poder "<<endl;
	gets(nuevo.fuente_p);
	cout<<"Marca: "<<endl;
	cout<<"Vatios: "<<endl;

	cout<<"\nPlaca Base "<<endl;
	gets(nuevo.placa_b);
	cout<<"Marca: "<<endl;
	cout<<"Modelo: "<<endl;

	do{
		cout<<"Registrar Nuevo Cliente? Si[s] / No [n]: \n"; 
		r=getch();
	}while(r!='S' && r!='s' && r!='N' && r!='n');

	if (r=='s' || r=='S') { 

		//AQUI SE GUARDAN LOS DATOS EN EL ARCHIVO LLAMADO ARCHIVO BINARIO , LA FUNCI�N FWRITE PERMITE GUARDAR INFORMACI�N CONTENIDA EN LAS VARIABLES A UN ARCHIVO DESTINO
		fwrite(&nuevo, sizeof(PC), 1, bin);

		//AQUI SE GUARDAN LOS DATOS EN EL ARCHIVO DE TEXTO LLAMADO ARCHIVO DATOS, LA FUNCION FPRINTF GUARDA INFORMACION EN LAS VARIABLES                                                          
		fprintf(texto, "%s \n", nuevo.nombre);
		fprintf(texto, "%s %s %s %s %s\n", nuevo.procesador, nuevo.ram, nuevo.rom, nuevo.fuente_p, nuevo.placa_b);            
		cout<<"Cliente Registrado.";
	}
	else
	{
		cout<<"Cliente NO Registrado.";
	}
	

	system("pause");
	fclose(bin);
	fclose(texto);
	menu();
}

void consulta(){

	FILE *bin;
	PC consulta, computadora;
	int aux=1;

	system("cls");

	if ((bin=fopen("Archivo Binario", "a+b"))==NULL)
	{
		cout<<"No se logro abrir el archivo.";
		
	}

	cout<<"Ingrese el nombre del PC que desee ver: ";
	fflush(stdin);
	gets(consulta.nombre);
	
	fread(&computadora, sizeof(PC), 1, bin);
	
	while (!feof(bin))
	{
		if(strcmp(consulta.nombre, computadora.nombre) == 0){
		
		cout<<"\n--------------"<<endl;
		printf("%s\n", computadora.nombre);
		cout<<"--------------"<<endl;
		
		printf("%s\n %s\n %s\n %s\n %s\n\n", computadora.procesador, computadora.rom,
				computadora.ram, computadora.fuente_p, computadora.placa_b);
		aux--;
		}
		fread(&computadora, sizeof(PC), 1, bin);
	}
	
	if(aux==1){ 
			cout<<"\n\n\n----------------------------------------------------------------------------------"<<endl;
			cout<<"El PC no esta registrado. "; 
			system("pause");
			exit(0);
		}

	system("pause");
	fclose(bin);
	menu();
}

void ver_todos(){

	FILE *bin;
	PC computadora;

	system("cls");

	if(((bin = fopen("Archivo Binario","r+b"))==NULL)){
		cout<<"No se logró abrir el archivo."<<endl;
		system("pause");
		exit(0);}

	fread(&computadora, sizeof(PC), 1, bin);
	
	
	while (!feof(bin))
	{
		cout<<"\n--------------"<<endl;
		printf("%s\n", computadora.nombre);
		cout<<"--------------"<<endl;
		
		printf("%s\n %s\n %s\n %s\n %s\n", computadora.procesador, computadora.rom,
				computadora.ram, computadora.fuente_p, computadora.placa_b);
        
		fread(&computadora, sizeof(PC), 1, bin);
	}

	system("pause");
	fclose(bin);
	menu();
}