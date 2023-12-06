#include<iostream>
#include<fstream>
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
    
    default:
        break;
    }
}

void registrar_pc(){

	FILE *file;
	PC nuevo, lista[50];
	char r;

	if (((file = fopen("Archivo Datos.txt","a+b"))==NULL))
	{
		cout<<"No se logró abrir el archivo";
		exit(0);
	}

	int encontro=1,i,ultimo,res;
	
	rewind(file); //mueve el puntero del archivo al principio del archivo
	
	i=0;
	while(!feof(file)){                                  //CON ESTE WHILE, SE VA A RECORRER TODO EL ARCHIVO, USAMOS LA FUNCION FEOF PARA RECORRER, LA CUAL RETORNA UN VALOR DISTINTO A CERO SI Y SOLO SI EL INDICADOR A LLEGADO AL FINAL DEL ARCHIVO
		if(fread(&nuevo, sizeof(PC), 1, file)){			//LA FUNCION FREAD, DEVUELVE EL NUMERO DE ELEMENTOS LEIDOS EN EL ARCHIVO, POR LO TANTO ESTE NUMERO NOS SIRVE PARA INDICARLE AL ARRAY CUANTAS POSICIONES TENDR�
			lista[i]=nuevo;                             //TODA LA INFORMACION ALMACENADA EN NUEVO SE LA GUARDARA EN EL ARRAY LISTA..
			i++;                                        //.. ESTO SE LO HACE PARA LUEGO COMPARAR
		}                                               
	}
	res=i;
	
	fflush(stdin);
	cout<<"Ingrese el nombre del PC: "<<endl;
	
	
	do{
		gets(nuevo.nombre);
		ultimo = res-1;
		encontro = 1;
		i=0;
		while (i<=ultimo && encontro==1){
			if (strcmp(lista[i].nombre,nuevo.nombre)==0)
			{
				encontro=0;
				i++;
			}
		}
		if (i<=ultimo){
		cout<<"Esta PC ya esta registrada.";
		}
		else{
			cout<<"                                               ";
		}
		
		
	} while (i<=ultimo);
	

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
		cout<<"Registrar Nuevo Cliente? Si[s] / No [n]: "; 
		r=getch();
	}while(r!='S' && r!='s' && r!='N' && r!='n');

	if (r=='s' || r=='S') { 

		//AQUI SE GUARDAN LOS DATOS EN EL ARCHIVO DE TEXTO LLAMADO ARCHIVO DATOS, LA FUNCION FPRINTF GUARDA INFORMACION EN LAS VARIABLES                                                          
		fprintf(file, "\n %s %s %s %s %s %s\n", nuevo.nombre, nuevo.procesador, nuevo.ram, nuevo.rom, nuevo.fuente_p, nuevo.placa_b);            
		cout<<"Cliente Registrado.";

	system("pause");
	fclose(file);
	menu();
	}

}