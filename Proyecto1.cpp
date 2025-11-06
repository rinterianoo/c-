/*
================================================================================
PROYECTO: SISTEMA DE GESTIÓN DE ESTUDIANTES Y CURSOS
Descripción: Sistema para administrar carreras, cursos, estudiantes y catedráticos
Autor: Universidad Mariano Gálvez
Fecha: 2025
================================================================================

CASOS DE USO:
1. Inicio de Sesión: El usuario debe autenticarse antes de acceder al sistema
2. Ingreso de Carreras: Permite registrar nuevas carreras con sus datos completos
3. Ingreso de Cursos: Permite registrar cursos asociados a carreras
4. Ingreso de Estudiantes: Permite registrar estudiantes y asignarlos a carreras
5. Ingreso de Catedráticos: Permite registrar catedráticos y asignarlos a cursos
6. Reporte de Carreras: Muestra listado de todas las carreras registradas
7. Reporte de Cursos: Muestra listado de todos los cursos registrados
8. Reporte de Estudiantes: Muestra listado de todos los estudiantes registrados
9. Reporte de Catedráticos: Muestra listado de todos los catedráticos registrados
10. Consulta de Carrera: Busca y muestra información de una carrera específica
11. Consulta de Estudiante: Busca y muestra información de un estudiante específico

================================================================================
*/

#include<iostream>
#include <windows.h>
#include <wincon.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<string>

using namespace std;

void gotoxy(int x,int y){ 
	//unsigned char bom[] = {0xEF, 0xBB, 0xBF}; 
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
 }
 
//Declaraci�n de Variables Globales

struct datoscarrera
{
	int codcarrera;
	char nomcarrera[30];
	char jornadacarrera[30];
	char campuscarrera[30];
	int inscripcioncarrera;
	int mensualidadcarrera;
} carrera;

struct datoscurso
{
	int codcurso;
	int codcarrera;
	char catedratico [40];
	int carnet;
	char semestre[30];
} curso;

struct	datosestudiante
{
	int carnet;
	int codcarrera;
	char nombreestudiante[30];
} estudiante;

struct datoscatedratico
{
	int idcatedratico;
	int codcurso;
	char nombrecatedratico[30];
} catedratico;

FILE *F;
FILE *Fcarrera; //archivo - variable global
FILE *Fcurso; //archivo - variable global
FILE *Festudiante; //archivo - variable global
FILE *Fcatedratico; //archivo - variable global

// Definici�n de variables

int mi, mj, mt=0;

void ingresocarreras();
void ingresocursos();
void ingresoestudiantes();
void ingresocatedraticos();
void reportecarreras();
void reportecursos();
void reporteestudiantes();
void reportecatedraticos();
void consultacarrera();
void consultaestudiante();
bool validarusuario();

// Función para validar usuario y contraseña
bool validarusuario()
{
	string usuario, password;
	int intentos = 0;
	
	system("cls");
	gotoxy(35,8); cout<<"================================";
	gotoxy(35,9); cout<<"    INICIO DE SESION";
	gotoxy(35,10); cout<<"================================";
	
	do
	{
		gotoxy(30,12); cout<<"Usuario: ";
		gotoxy(40,12); cin>>usuario;
		gotoxy(30,13); cout<<"Password: ";
		gotoxy(40,13); cin>>password;
		
		// Validación simple (puedes mejorarla con archivo de usuarios)
		if(usuario == "admin" && password == "1234")
		{
			gotoxy(30,15); cout<<"¡Acceso concedido!";
			Sleep(1500);
			return true;
		}
		else
		{
			intentos++;
			gotoxy(30,15); cout<<"¡Usuario o password incorrectos!";
			gotoxy(30,16); cout<<"Intentos restantes: " << (3-intentos);
			Sleep(2000);
			
			if(intentos < 3)
			{
				gotoxy(30,12); cout<<"                                   ";
				gotoxy(30,13); cout<<"                                   ";
				gotoxy(30,15); cout<<"                                   ";
				gotoxy(30,16); cout<<"                                   ";
			}
		}
	} while(intentos < 3);
	
	gotoxy(30,18); cout<<"Número máximo de intentos alcanzado.";
	Sleep(2000);
	return false;
}

main ()
{
	// Validar usuario antes de iniciar el sistema
	if(!validarusuario())
	{
		return 0;
	}
	
	crear();
	system("color 8A");
	int mopcion;
	
	int mcodigousuario, mencontro;
	mencontro=0;
	do
	{
		system("cls");
		gotoxy(35,6); cout<<"============================= ";
	    gotoxy(35,7); cout<<"    MENU PRINCIPAL";
	    gotoxy(35,8); cout<<"==============================";
	    gotoxy(30,10); cout<<"INGRESO DE CARRERAS.....1 ";
	    gotoxy(30,11); cout<<"INGRESO DE CURSO........2 ";
	    gotoxy(30,12); cout<<"INGRESO DE ESTUDIANTES..3 ";
   	    gotoxy(30,13); cout<<"INGRESO DE CATEDRATICOS.4 ";
	    gotoxy(30,14); cout<<"REPORTE DE CARRERAS.....5 ";
	    gotoxy(30,15); cout<<"REPORTE DE CURSOS.......6 ";	    
		gotoxy(30,16); cout<<"REPORTE DE ESTUDIANTES..7 ";
		gotoxy(30,17); cout<<"REPORTE DE CATEDRATICOS.8 ";
		gotoxy(30,18); cout<<"CONSULTA DE CARRERA.....9 ";
		gotoxy(30,19); cout<<"CONSULTA DE ESTUDIANTE..10";
		gotoxy(30,20); cout<<"SALIR...................11"; 
	    gotoxy(30,21); cout<<"OPCION ===============> ";	   
	    cin>>mopcion;
	    
	    switch (mopcion)
		{
	     	case 1: 
			 if (mopcion==1)
			 {
			 	ingresocarreras();
			 	break;
			 }
	     	case 2: 
			 if (mopcion==2)
			 {
			 	ingresocursos();
			 	break;
			 }
	     	case 3: 
			 if (mopcion==3)
			 {
			 	ingresoestudiantes();
			 	break;
			 }	
	     	case 4: 
			 if (mopcion==4)
			 {
			 	ingresocatedraticos();
			 	break;
			 }
	     	case 5: 
	     		reportecarreras();
		    	break;
		    case 6: 
		    	reportecursos();
				break;
        	case 7: 
        		reporteestudiantes();
		    	break;
		    case 8: 
		    	reportecatedraticos();
		    	break;
		    case 9:
		    	consultacarrera();
		    	break;
		    case 10:
		    	consultaestudiante();
		    	break;
		}
	}while (mopcion!=11);
}

void crear()
{
	Fcarrera = fopen("c:\\carrera.txt", "r");
	if(!Fcarrera)
	{
		Fcarrera = fopen("c:\\carrera.txt", "w");
		printf("\nArchivo carrera.txt creado!");
	}
	else
	{
		printf("\nEl fichero carrera.txt ya existe!");
	}
	fclose (Fcarrera);
	
	Fcurso = fopen("c:\\curso.txt", "r");
	if(!Fcurso) 
	{
		Fcurso = fopen("c:\\curso.txt", "w");
		printf("\nArchivo curso.txt creado!");
	}
	else
	{
		printf("\nEl fichero curso.txt ya existe!");
	}
	fclose (Fcurso);
	
	Festudiante = fopen("c:\\estudiante.txt", "r");
	if(!Festudiante)
	{
		Festudiante = fopen("c:\\estudiante.txt", "w");
		printf("\nArchivo estudiante.txt creado!");
	}
	else
	{
		printf("\nEl fichero estudiante.txt ya existe!");
	}
	fclose (Festudiante);
	
	Fcatedratico = fopen("c:\\catedratico.txt", "r");
	if(!Fcatedratico)
	{
		Fcatedratico = fopen("c:\\catedratico.txt", "w");
		printf("\nArchivo catedratico.txt creado!");
	}
	else
	{
		printf("\nEl fichero catedratico.txt ya existe!");
	}
	fclose (Fcatedratico);
	
	Sleep(2000);
	return;
}

//Ingreso de Datos para Carreras
void ingresocarreras()
{
	int mcodcarrera, mencontro, ma;
	string mopcion1;
	
	system("color 8A");
	do
	{
		system("cls");
	    gotoxy(20,11); cout<<"Codigo Carrera...........";
	    gotoxy(20,12); cout<<"Nombre...................";	    
	    gotoxy(20,13); cout<<"Jornada..................";	    
	    gotoxy(20,14); cout<<"Campus...................";
	    gotoxy(20,15); cout<<"Inscripcion..............";
	    gotoxy(20,16); cout<<"Mensualidad..............";
				    
		gotoxy(50,11); cin>>mcodcarrera;
		cin.ignore(1,'\n'); 

		mencontro=0;
        F=fopen("c:\\carrera.txt","r+"); 
	    fread(&carrera, sizeof(struct datoscarrera), 1, F);			    
	    while(!feof(F))
		{
			if (carrera.codcarrera==mcodcarrera)
			{
			 	gotoxy(50,12); cout<<carrera.nomcarrera;
			 	gotoxy(50,13); cout<<carrera.jornadacarrera;
			 	gotoxy(50,14); cout<<carrera.campuscarrera;
			 	gotoxy(50,15); cout<<carrera.inscripcioncarrera;
			 	gotoxy(50,16); cout<<carrera.mensualidadcarrera;
			 	mencontro=1;
			 	break;
			}
		
			fread(&carrera, sizeof(struct datoscarrera), 1, F);	
	    } 

	    if (mencontro==0)
	    {
		 	gotoxy(50,12); cin.getline(carrera.nomcarrera, 30);
		 	gotoxy(50,13); cin.getline(carrera.jornadacarrera, 30);
		 	gotoxy(50,14); cin.getline(carrera.campuscarrera, 30);	 
			gotoxy(50,15); cin>>carrera.inscripcioncarrera;
			gotoxy(50,16); cin>>carrera.mensualidadcarrera;
			carrera.codcarrera=mcodcarrera;
		
            fwrite(&carrera, sizeof(struct datoscarrera), 1, F);		
			if(ferror(F))
			{ cout<<"Error de escritura en archivo Carreras"<<endl; 
			exit(1);}			

	   }
        fclose(F);    
	 	gotoxy(30,19); cout<<("Desea Continuar.....S/N");
	 	gotoxy(50,19); cin>>mopcion1;
    }  while (mopcion1!="N");
    fclose(F);
};

//Ingreso de Datos para Cursos
void ingresocursos()
{
	int mcodcurso, mencontro, ma;
	string mopcion1;
	
	system("color 8A");
	do
	{
		system("cls");
	    gotoxy(20,11); cout<<"Codigo Curso..........";
	    gotoxy(20,12); cout<<"Codigo Carrera........";	    
	    gotoxy(20,13); cout<<"Catedratico...........";	    
	    gotoxy(20,14); cout<<"Carnet................";
	    gotoxy(20,15); cout<<"Semestre..............";

				    
		gotoxy(50,11); cin>>mcodcurso;
		cin.ignore(1,'\n'); 

		mencontro=0;
        F=fopen("c:\\curso.txt","r+"); 
	    fread(&curso, sizeof(struct datoscurso), 1, F);			    
	    while(!feof(F))
		{
			if (curso.codcurso==mcodcurso)
			{
			 	gotoxy(50,11); cout<<curso.codcurso;
			 	gotoxy(50,12); cout<<curso.codcarrera;
			 	gotoxy(50,13); cout<<curso.catedratico;
			 	gotoxy(50,14); cout<<curso.carnet;
			 	gotoxy(50,15); cout<<curso.semestre;
			 	mencontro=1;
			 	break;
			}
		
			fread(&curso, sizeof(struct datoscurso), 1, F);	
	    } 

	    if (mencontro==0)
	    {
		 	gotoxy(50,12); cin>>curso.codcarrera;
		 	cin.ignore(1,'\n'); 
		 	gotoxy(50,13); cin.getline(curso.catedratico, 40);	 
			gotoxy(50,14); cin>>curso.carnet;
			cin.ignore(1,'\n'); 
			gotoxy(50,15); cin.getline(curso.semestre, 30);
			curso.codcurso=mcodcurso;
			
            fwrite(&curso, sizeof(struct datoscurso), 1, F);		
			if(ferror(F))
			{ cout<<"Error de escritura en archivo Cursos"<<endl; 
			exit(1);}			

	   }
        fclose(F);    
	 	gotoxy(30,19); cout<<("Desea Continuar.....S/N");
	 	gotoxy(50,19); cin>>mopcion1;
    }  while (mopcion1!="N");
    fclose(F);
};

//Ingreso de Datos para Estudiantes
void ingresoestudiantes()
{
	int mcarnet, mencontro, ma;
	string mopcion1;
	
	system("color 8A");
	do
	{
		system("cls");
	    gotoxy(20,11); cout<<"Carnet................";
	    gotoxy(20,12); cout<<"Codigo Carrera........";	    
	    gotoxy(20,13); cout<<"Nombre Estudiante.....";	    
				    
		gotoxy(50,11); cin>>mcarnet;
		cin.ignore(1,'\n'); 

		mencontro=0;
        F=fopen("c:\\estudiante.txt","r+"); 
	    fread(&estudiante, sizeof(struct datosestudiante), 1, F);			    
	    while(!feof(F))
		{
			if (estudiante.carnet==mcarnet)
			{
			 	gotoxy(50,12); cout<<estudiante.codcarrera;
			 	gotoxy(50,13); cout<<estudiante.nombreestudiante;
			 	mencontro=1;
			 	break;
			}
		
			fread(&estudiante, sizeof(struct datosestudiante), 1, F);	
	    } 

	    if (mencontro==0)
	    {
		 	gotoxy(50,12); cin>>estudiante.codcarrera;
		 	cin.ignore(1,'\n'); 
			gotoxy(50,13); cin.getline(estudiante.nombreestudiante, 30);
			estudiante.carnet=mcarnet;
			
            fwrite(&estudiante, sizeof(struct datosestudiante), 1, F);		
			if(ferror(F))
			{ cout<<"Error de escritura en archivo Carreras"<<endl; 
			exit(1);}			

	   }
        fclose(F);    
	 	gotoxy(30,19); cout<<("Desea Continuar.....S/N");
	 	gotoxy(50,19); cin>>mopcion1;
    }  while (mopcion1!="N");
    fclose(F);
};

//Ingreso de Datos para Catedratico
void ingresocatedraticos()
{
	int midcatedratico, mencontro, ma;
	string mopcion1;
	
	system("color 8A");
	do
	{
		system("cls");
	    gotoxy(20,11); cout<<"ID Catedratico.........";
	    gotoxy(20,12); cout<<"Codigo Curso...........";	    
	    gotoxy(20,13); cout<<"Nombre Catedratico.....";	    
				    
		gotoxy(50,11); cin>>midcatedratico;
		cin.ignore(1,'\n'); 

		mencontro=0;
        F=fopen("c:\\catedratico.txt","r+"); 
	    fread(&catedratico, sizeof(struct datoscatedratico), 1, F);			    
	    while(!feof(F))
		{
			if (catedratico.idcatedratico==midcatedratico)
			{
			 	gotoxy(50,12); cout<<catedratico.codcurso;
			 	gotoxy(50,13); cout<<catedratico.nombrecatedratico;
			 	mencontro=1;
			 	break;
			}
		
			fread(&catedratico, sizeof(struct datoscatedratico), 1, F);	
	    } 

	    if (mencontro==0)
	    {
		 	gotoxy(50,12); cin>>catedratico.codcurso;
		 	cin.ignore(1,'\n'); 
			gotoxy(50,13); cin.getline(catedratico.nombrecatedratico, 40);
			catedratico.idcatedratico=midcatedratico;
			
            fwrite(&catedratico, sizeof(struct datoscatedratico), 1, F);		
			if(ferror(F))
			{ cout<<"Error de escritura en archivo Carreras"<<endl; 
			exit(1);}			

	   }
        fclose(F);    
	 	gotoxy(30,19); cout<<("Desea Continuar.....S/N");
	 	gotoxy(50,19); cin>>mopcion1;
    }  while (mopcion1!="N");
    fclose(F);
};
