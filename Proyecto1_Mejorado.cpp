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
	HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
 }
 
//Declaración de Variables Globales

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

// Definición de variables
int mi, mj, mt=0;

// Declaración de funciones
void crear();
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

/*
================================================================================
FUNCIÓN: crear()
PROPÓSITO: Crear los archivos de texto donde se guardarán los datos
RUTA DE ARCHIVOS: C:\ (raíz del disco C)
================================================================================
Los archivos se crean en:
- C:\carrera.txt      -> Guarda información de carreras
- C:\curso.txt        -> Guarda información de cursos
- C:\estudiante.txt   -> Guarda información de estudiantes
- C:\catedratico.txt  -> Guarda información de catedráticos

NOTA: Para cambiar la ruta, modifica "c:\\" por la ruta deseada
Ejemplos de otras rutas:
- "D:\\MisArchivos\\carrera.txt"  -> Guardaría en D:\MisArchivos\
- ".\\carrera.txt"                 -> Guardaría en la carpeta del programa
================================================================================
*/
void crear()
{
	// ===== CREACIÓN DE ARCHIVO DE CARRERAS =====
	// Intenta abrir el archivo en modo lectura ("r") para verificar si existe
	Fcarrera = fopen("c:\\carrera.txt", "r");
	
	// Si fopen retorna NULL, significa que el archivo NO existe
	if(!Fcarrera)
	{
		// Crear el archivo en modo escritura ("w")
		Fcarrera = fopen("c:\\carrera.txt", "w");
		printf("\nArchivo carrera.txt creado en C:\\carrera.txt");
	}
	else
	{
		// Si el archivo ya existe, solo muestra mensaje
		printf("\nEl fichero carrera.txt ya existe en C:\\carrera.txt");
	}
	// Cerrar el archivo para liberar recursos
	fclose (Fcarrera);
	
	// ===== CREACIÓN DE ARCHIVO DE CURSOS =====
	Fcurso = fopen("c:\\curso.txt", "r");
	if(!Fcurso) 
	{
		Fcurso = fopen("c:\\curso.txt", "w");
		printf("\nArchivo curso.txt creado en C:\\curso.txt");
	}
	else
	{
		printf("\nEl fichero curso.txt ya existe en C:\\curso.txt");
	}
	fclose (Fcurso);
	
	// ===== CREACIÓN DE ARCHIVO DE ESTUDIANTES =====
	Festudiante = fopen("c:\\estudiante.txt", "r");
	if(!Festudiante)
	{
		Festudiante = fopen("c:\\estudiante.txt", "w");
		printf("\nArchivo estudiante.txt creado en C:\\estudiante.txt");
	}
	else
	{
		printf("\nEl fichero estudiante.txt ya existe en C:\\estudiante.txt");
	}
	fclose (Festudiante);
	
	// ===== CREACIÓN DE ARCHIVO DE CATEDRÁTICOS =====
	Fcatedratico = fopen("c:\\catedratico.txt", "r");
	if(!Fcatedratico)
	{
		Fcatedratico = fopen("c:\\catedratico.txt", "w");
		printf("\nArchivo catedratico.txt creado en C:\\catedratico.txt");
	}
	else
	{
		printf("\nEl fichero catedratico.txt ya existe en C:\\catedratico.txt");
	}
	fclose (Fcatedratico);
	
	// Pausa de 2 segundos (2000 milisegundos) para que el usuario pueda leer los mensajes
	Sleep(2000);
	return;
}

// ========================== FUNCIONES DE INGRESO ==========================

/*
================================================================================
FUNCIÓN: ingresocarreras()
PROPÓSITO: Ingresar o consultar carreras en el sistema
ARCHIVO UTILIZADO: C:\carrera.txt
MODO DE APERTURA: "r+" (lectura y escritura)
================================================================================
FLUJO:
1. Solicita código de carrera
2. Busca si el código ya existe en el archivo
3. Si existe: muestra los datos y NO permite modificar
4. Si NO existe: permite ingresar una nueva carrera
5. Pregunta si desea continuar ingresando más carreras
================================================================================
*/
void ingresocarreras()
{
	// Variables locales
	int mcodcarrera;    // Código de la carrera ingresado por el usuario
	int mencontro;      // Bandera: 1 si encuentra la carrera, 0 si no existe
	int ma;             // Variable auxiliar (no usada en esta versión)
	string mopcion1;    // Opción para continuar (S) o salir (N)
	
	system("color 8A");  // Establecer color de consola (fondo gris, texto verde)
	
	do  // Bucle para permitir múltiples ingresos
	{
		system("cls");  // Limpiar pantalla
		
		// ===== MOSTRAR ETIQUETAS EN PANTALLA =====
		gotoxy(20,11); cout<<"Codigo Carrera...........";
	    gotoxy(20,12); cout<<"Nombre...................";	    
	    gotoxy(20,13); cout<<"Jornada..................";	    
	    gotoxy(20,14); cout<<"Campus...................";
	    gotoxy(20,15); cout<<"Inscripcion..............";
	    gotoxy(20,16); cout<<"Mensualidad..............";
				    
		// ===== LEER CÓDIGO DE CARRERA =====
		gotoxy(50,11); cin>>mcodcarrera;
		cin.ignore(1,'\n');  // Limpiar buffer para evitar problemas con getline()

		// ===== BUSCAR SI EL CÓDIGO YA EXISTE =====
		mencontro=0;  // Inicializar bandera en 0 (no encontrado)
		
		// Abrir archivo en modo "r+" (lectura y escritura)
		// RUTA: C:\carrera.txt
        F=fopen("c:\\carrera.txt","r+"); 
        
        // Leer el primer registro del archivo
        // Leer el primer registro del archivo
	    fread(&carrera, sizeof(struct datoscarrera), 1, F);			    
	    
	    // ===== RECORRER TODO EL ARCHIVO BUSCANDO EL CÓDIGO =====
	    while(!feof(F))  // Mientras no sea fin de archivo
		{
			// Si el código leído coincide con el ingresado
			if (carrera.codcarrera==mcodcarrera)
			{
				// ===== CÓDIGO ENCONTRADO: MOSTRAR DATOS =====
			 	gotoxy(50,12); cout<<carrera.nomcarrera;
			 	gotoxy(50,13); cout<<carrera.jornadacarrera;
			 	gotoxy(50,14); cout<<carrera.campuscarrera;
			 	gotoxy(50,15); cout<<carrera.inscripcioncarrera;
			 	gotoxy(50,16); cout<<carrera.mensualidadcarrera;
			 	mencontro=1;  // Marcar como encontrado
			 	break;        // Salir del bucle
			}
		
			// Leer siguiente registro
			fread(&carrera, sizeof(struct datoscarrera), 1, F);	
	    } 

		// ===== SI NO SE ENCONTRÓ, PERMITIR INGRESO NUEVO =====
	    if (mencontro==0)
	    {
		 	// Solicitar datos de la nueva carrera
		 	gotoxy(50,12); cin.getline(carrera.nomcarrera, 30);
		 	gotoxy(50,13); cin.getline(carrera.jornadacarrera, 30);
		 	gotoxy(50,14); cin.getline(carrera.campuscarrera, 30);	 
			gotoxy(50,15); cin>>carrera.inscripcioncarrera;
			gotoxy(50,16); cin>>carrera.mensualidadcarrera;
			
			// Asignar el código ingresado a la estructura
			carrera.codcarrera=mcodcarrera;
		
			// ===== GUARDAR EN EL ARCHIVO =====
			// fwrite escribe la estructura completa en el archivo
            fwrite(&carrera, sizeof(struct datoscarrera), 1, F);		
            
            // Verificar si hubo error al escribir
			if(ferror(F))
			{ 
				cout<<"Error de escritura en archivo C:\\carrera.txt"<<endl; 
				exit(1);  // Terminar programa si hay error crítico
			}			

	   }
        fclose(F);  // Cerrar archivo
        
        // ===== PREGUNTAR SI DESEA CONTINUAR =====
	 	gotoxy(30,19); cout<<("Desea Continuar.....S/N");
	 	gotoxy(50,19); cin>>mopcion1;
	 	
    }  while (mopcion1!="N");  // Repetir mientras no ingrese "N"
    
    fclose(F);  // Asegurar cierre del archivo
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
			{ cout<<"Error de escritura en archivo Estudiantes"<<endl; 
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
			{ cout<<"Error de escritura en archivo Catedraticos"<<endl; 
			exit(1);}			

	   }
        fclose(F);    
	 	gotoxy(30,19); cout<<("Desea Continuar.....S/N");
	 	gotoxy(50,19); cin>>mopcion1;
    }  while (mopcion1!="N");
    fclose(F);
};

// ========================== FUNCIONES DE REPORTE ==========================

//Reporte de Carreras
void reportecarreras()
{
	system("cls");
	system("color 8A");
	
	gotoxy(25,5); cout<<"==================================================";
	gotoxy(25,6); cout<<"           REPORTE DE CARRERAS";
	gotoxy(25,7); cout<<"==================================================";
	
	int linea = 9;
	gotoxy(10,linea); cout<<"Codigo";
	gotoxy(20,linea); cout<<"Nombre Carrera";
	gotoxy(45,linea); cout<<"Jornada";
	gotoxy(60,linea); cout<<"Campus";
	gotoxy(75,linea); cout<<"Inscripcion";
	gotoxy(90,linea); cout<<"Mensualidad";
	linea++;
	gotoxy(10,linea); cout<<"------";
	gotoxy(20,linea); cout<<"--------------------";
	gotoxy(45,linea); cout<<"----------";
	gotoxy(60,linea); cout<<"----------";
	gotoxy(75,linea); cout<<"-----------";
	gotoxy(90,linea); cout<<"-----------";
	linea++;
	
	F=fopen("c:\\carrera.txt","r");
	if(F==NULL)
	{
		gotoxy(30,15); cout<<"No se pudo abrir el archivo de carreras";
		getch();
		return;
	}
	
	fread(&carrera, sizeof(struct datoscarrera), 1, F);
	
	while(!feof(F))
	{
		gotoxy(10,linea); cout<<carrera.codcarrera;
		gotoxy(20,linea); cout<<carrera.nomcarrera;
		gotoxy(45,linea); cout<<carrera.jornadacarrera;
		gotoxy(60,linea); cout<<carrera.campuscarrera;
		gotoxy(75,linea); cout<<"Q."<<carrera.inscripcioncarrera;
		gotoxy(90,linea); cout<<"Q."<<carrera.mensualidadcarrera;
		linea++;
		
		fread(&carrera, sizeof(struct datoscarrera), 1, F);
	}
	
	fclose(F);
	
	gotoxy(30,linea+2); cout<<"Presione cualquier tecla para continuar...";
	getch();
}

//Reporte de Cursos
void reportecursos()
{
	system("cls");
	system("color 8A");
	
	gotoxy(25,5); cout<<"==================================================";
	gotoxy(25,6); cout<<"           REPORTE DE CURSOS";
	gotoxy(25,7); cout<<"==================================================";
	
	int linea = 9;
	gotoxy(10,linea); cout<<"Cod.Curso";
	gotoxy(25,linea); cout<<"Cod.Carrera";
	gotoxy(40,linea); cout<<"Catedratico";
	gotoxy(70,linea); cout<<"Carnet";
	gotoxy(85,linea); cout<<"Semestre";
	linea++;
	gotoxy(10,linea); cout<<"---------";
	gotoxy(25,linea); cout<<"-----------";
	gotoxy(40,linea); cout<<"-------------------------";
	gotoxy(70,linea); cout<<"----------";
	gotoxy(85,linea); cout<<"---------------";
	linea++;
	
	F=fopen("c:\\curso.txt","r");
	if(F==NULL)
	{
		gotoxy(30,15); cout<<"No se pudo abrir el archivo de cursos";
		getch();
		return;
	}
	
	fread(&curso, sizeof(struct datoscurso), 1, F);
	
	while(!feof(F))
	{
		gotoxy(10,linea); cout<<curso.codcurso;
		gotoxy(25,linea); cout<<curso.codcarrera;
		gotoxy(40,linea); cout<<curso.catedratico;
		gotoxy(70,linea); cout<<curso.carnet;
		gotoxy(85,linea); cout<<curso.semestre;
		linea++;
		
		fread(&curso, sizeof(struct datoscurso), 1, F);
	}
	
	fclose(F);
	
	gotoxy(30,linea+2); cout<<"Presione cualquier tecla para continuar...";
	getch();
}

//Reporte de Estudiantes
void reporteestudiantes()
{
	system("cls");
	system("color 8A");
	
	gotoxy(25,5); cout<<"==================================================";
	gotoxy(25,6); cout<<"           REPORTE DE ESTUDIANTES";
	gotoxy(25,7); cout<<"==================================================";
	
	int linea = 9;
	gotoxy(20,linea); cout<<"Carnet";
	gotoxy(40,linea); cout<<"Cod.Carrera";
	gotoxy(60,linea); cout<<"Nombre Estudiante";
	linea++;
	gotoxy(20,linea); cout<<"----------";
	gotoxy(40,linea); cout<<"-----------";
	gotoxy(60,linea); cout<<"-----------------------------";
	linea++;
	
	F=fopen("c:\\estudiante.txt","r");
	if(F==NULL)
	{
		gotoxy(30,15); cout<<"No se pudo abrir el archivo de estudiantes";
		getch();
		return;
	}
	
	fread(&estudiante, sizeof(struct datosestudiante), 1, F);
	
	while(!feof(F))
	{
		gotoxy(20,linea); cout<<estudiante.carnet;
		gotoxy(40,linea); cout<<estudiante.codcarrera;
		gotoxy(60,linea); cout<<estudiante.nombreestudiante;
		linea++;
		
		fread(&estudiante, sizeof(struct datosestudiante), 1, F);
	}
	
	fclose(F);
	
	gotoxy(30,linea+2); cout<<"Presione cualquier tecla para continuar...";
	getch();
}

//Reporte de Catedráticos
void reportecatedraticos()
{
	system("cls");
	system("color 8A");
	
	gotoxy(25,5); cout<<"==================================================";
	gotoxy(25,6); cout<<"           REPORTE DE CATEDRATICOS";
	gotoxy(25,7); cout<<"==================================================";
	
	int linea = 9;
	gotoxy(25,linea); cout<<"ID Catedratico";
	gotoxy(45,linea); cout<<"Cod.Curso";
	gotoxy(65,linea); cout<<"Nombre Catedratico";
	linea++;
	gotoxy(25,linea); cout<<"--------------";
	gotoxy(45,linea); cout<<"---------";
	gotoxy(65,linea); cout<<"-----------------------------";
	linea++;
	
	F=fopen("c:\\catedratico.txt","r");
	if(F==NULL)
	{
		gotoxy(30,15); cout<<"No se pudo abrir el archivo de catedraticos";
		getch();
		return;
	}
	
	fread(&catedratico, sizeof(struct datoscatedratico), 1, F);
	
	while(!feof(F))
	{
		gotoxy(25,linea); cout<<catedratico.idcatedratico;
		gotoxy(45,linea); cout<<catedratico.codcurso;
		gotoxy(65,linea); cout<<catedratico.nombrecatedratico;
		linea++;
		
		fread(&catedratico, sizeof(struct datoscatedratico), 1, F);
	}
	
	fclose(F);
	
	gotoxy(30,linea+2); cout<<"Presione cualquier tecla para continuar...";
	getch();
}

// ========================== FUNCIONES DE CONSULTA ==========================

//Consulta de Carrera por Código
void consultacarrera()
{
	int mcodcarrera, mencontro;
	system("cls");
	system("color 8A");
	
	gotoxy(25,5); cout<<"==================================================";
	gotoxy(25,6); cout<<"           CONSULTA DE CARRERA";
	gotoxy(25,7); cout<<"==================================================";
	
	gotoxy(25,10); cout<<"Ingrese Codigo de Carrera: ";
	gotoxy(55,10); cin>>mcodcarrera;
	
	F=fopen("c:\\carrera.txt","r");
	if(F==NULL)
	{
		gotoxy(25,15); cout<<"No se pudo abrir el archivo de carreras";
		getch();
		return;
	}
	
	mencontro = 0;
	fread(&carrera, sizeof(struct datoscarrera), 1, F);
	
	while(!feof(F))
	{
		if(carrera.codcarrera == mcodcarrera)
		{
			gotoxy(25,13); cout<<"Codigo Carrera: "<<carrera.codcarrera;
			gotoxy(25,14); cout<<"Nombre........: "<<carrera.nomcarrera;
			gotoxy(25,15); cout<<"Jornada.......: "<<carrera.jornadacarrera;
			gotoxy(25,16); cout<<"Campus........: "<<carrera.campuscarrera;
			gotoxy(25,17); cout<<"Inscripcion...: Q."<<carrera.inscripcioncarrera;
			gotoxy(25,18); cout<<"Mensualidad...: Q."<<carrera.mensualidadcarrera;
			mencontro = 1;
			break;
		}
		fread(&carrera, sizeof(struct datoscarrera), 1, F);
	}
	
	if(mencontro == 0)
	{
		gotoxy(25,13); cout<<"¡Carrera no encontrada!";
	}
	
	fclose(F);
	
	gotoxy(25,21); cout<<"Presione cualquier tecla para continuar...";
	getch();
}

//Consulta de Estudiante por Carnet
void consultaestudiante()
{
	int mcarnet, mencontro;
	system("cls");
	system("color 8A");
	
	gotoxy(25,5); cout<<"==================================================";
	gotoxy(25,6); cout<<"           CONSULTA DE ESTUDIANTE";
	gotoxy(25,7); cout<<"==================================================";
	
	gotoxy(25,10); cout<<"Ingrese Carnet del Estudiante: ";
	gotoxy(58,10); cin>>mcarnet;
	
	F=fopen("c:\\estudiante.txt","r");
	if(F==NULL)
	{
		gotoxy(25,15); cout<<"No se pudo abrir el archivo de estudiantes";
		getch();
		return;
	}
	
	mencontro = 0;
	fread(&estudiante, sizeof(struct datosestudiante), 1, F);
	
	while(!feof(F))
	{
		if(estudiante.carnet == mcarnet)
		{
			gotoxy(25,13); cout<<"Carnet.........: "<<estudiante.carnet;
			gotoxy(25,14); cout<<"Codigo Carrera.: "<<estudiante.codcarrera;
			gotoxy(25,15); cout<<"Nombre.........: "<<estudiante.nombreestudiante;
			mencontro = 1;
			break;
		}
		fread(&estudiante, sizeof(struct datosestudiante), 1, F);
	}
	
	if(mencontro == 0)
	{
		gotoxy(25,13); cout<<"¡Estudiante no encontrado!";
	}
	
	fclose(F);
	
	gotoxy(25,18); cout<<"Presione cualquier tecla para continuar...";
	getch();
}
