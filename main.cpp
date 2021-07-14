#include "basicas.cpp"

#define MAXCOD 8
#define MAXSEXO 2

struct Alumno
{
  char codigo[MAXCOD];
  char nombre[LIM];
  int edad;
  int sexo; //campo categorizado
  float prom;
};

char TSexo[MAXSEXO][LIM]={"Masculino", "Femenino"};

//operaciones basicas de ALumno
void iniciaAlumno(Alumno &A)
{
 A.codigo[0]=NULL;
 A.nombre[0]=NULL;
 A.edad=0;
 A.sexo=0;
 A.prom=0.0;
}

void leeAlumno(Alumno &A)
{
 do{
    printf("\n Ingrese codigo (7 caracteres): ");
    fflush(stdin);
    gets(A.codigo);
 }while(!(strlen(A.codigo)==MAXCOD-1));

 printf("\nIngrese nombre: ");
 gets(A.nombre);

 A.edad=leeEntero("\n Ingrese edad: ", 15, 40);
 A.sexo=validaTabla("\n Ingrese sexo: ", TSexo, MAXSEXO);
 A.prom=leeReal("\n Ingrese promedio: ", 0.0, 20.0);
}

void mostrarAlumno(Alumno &A)
{
 printf("\n Codigo: %s",A.codigo);
 printf("\n Nombre: %s",A.nombre);
 printf("\n Edad: %d",A.edad);
 printf("\n Sexo: %s",TSexo[A.sexo-1]);
 printf("\n Promedio: %.2f",A.prom);
}

struct listaAlumnos
{
  Alumno *pA;
  int N;
};

//Operaciones basicas listaALumnos

void iniciaListaAlumno(listaAlumnos &LA)
{
	LA.pA= new Alumno [MAX];
   LA.N=0;
}
void inserta(listaAlumnos &LA, Alumno &A){

  if(LA.N<MAX){
     LA.pA[LA.N]=A;
     LA.N++;
  }
  else{
      printf("\n No hay espacio.....");
  }


}
void leerListaAlumno(listaAlumnos &LA)
{
  Alumno A;

  do{
  iniciaAlumno(A);
  leeAlumno(A);
  inserta(LA,A);
 }while(continuar("\n Desea continuar (S/N): ")=='S');

}
void mostrarListaAlumno(listaAlumnos &LA)
{
	if(LA.N>0)
   {
   	for(int i=0;i<LA.N;i++){
      	printf("\n\nAlumno Nro[%d]",i+1);
      	mostrarAlumno(LA.pA[i]);
      }
   }else
   	printf("\nNo hay Datos");
   getch();
}

void liberarListaAlumnos(listaAlumnos &LA)
{
 delete [] LA.pA;
}

//Reportes

//Promedio edad del Salon
void promedioEdad(listaAlumnos &LA)
{
 int suma=0;
 float prom;

 if(LA.N>0)
 {
  for(int i=0; i<LA.N; i++)
  	suma+=LA.pA[i].edad;

  prom=(float)suma/LA.N;

  printf("\n El promedio de edad es: %.2f", prom);

 }
 else
 	printf("\n No hay datos");
 getch();
}

//Alumno con Mayor promedio
void mayorPromedio(listaAlumnos &LA)
{
 float mayor=0.0;

 if(LA.N>0)
 {
  for(int i=0; i<LA.N; i++)
  	if(LA.pA[i].prom > mayor)
   	mayor = LA.pA[i].prom;

  printf("\n El mayor promedio es: %.2f y corresponde a:", mayor);

  for(int i=0; i<LA.N; i++)
  	if(LA.pA[i].prom == mayor)
     printf("\nNombre: %s", LA.pA[i].nombre);

 }
 else
 	printf("\n No hay datos");
 getch();
}


//Alumno con Menor promedio
void menorPromedio(listaAlumnos &LA)
{
 float menor=20.0;

 if(LA.N>0)
 {
  for(int i=0; i<LA.N; i++)
  	if(LA.pA[i].prom < menor)
   	menor = LA.pA[i].prom;

  printf("\n El menor promedio es: %.2f y corresponde a:", menor);

  for(int i=0; i<LA.N; i++)
  	if(LA.pA[i].prom == menor)
     printf("\nNombre: %s", LA.pA[i].nombre);

 }
 else
 	printf("\n No hay datos");
 getch();
}

//Ordenar por nombre ascendente
void OrdenarAsc(listaAlumnos &LA)
{
  Alumno aux;

  if(LA.N>0)
 {
  for(int i=0; i<LA.N-1; i++)
    for(int j=i+1; j<LA.N; j++)
      if(strcmp(LA.pA[i].nombre, LA.pA[j].nombre) > 0)
      	{
          aux = LA.pA[i];
          LA.pA[i] = LA.pA[j];
          LA.pA[j] = aux;
         }
   printf("\n Lista ordenada ascendente por nombre \n");
   mostrarListaAlumno(LA);

 }
 else
 	printf("\n No hay datos");
 getch();


}

//Ordenar por nombre descendente
void OrdenarDesc(listaAlumnos &LA)
{
  Alumno aux;

  if(LA.N>0)
 {
  for(int i=0; i<LA.N-1; i++)
    for(int j=i+1; j<LA.N; j++)
      if(strcmp(LA.pA[i].nombre, LA.pA[j].nombre) < 0)
      	{
          aux = LA.pA[i];
          LA.pA[i] = LA.pA[j];
          LA.pA[j] = aux;
         }
   printf("\n Lista ordenada descendente por nombre \n");
   mostrarListaAlumno(LA);

 }
 else
 	printf("\n No hay datos");
 getch();
}

void menu(listaAlumnos &LA)
{
  int opc;
  do{
     //clrscr();
     printf("\n\n\n *** MENU PRINCIPAL ***\n");
     printf("\n 1. Lectura");
     printf("\n 2. Mostrar");
     printf("\n 3. Promedio edad del Salon");
     printf("\n 4. Alumno con Mayor promedio");
     printf("\n 5. Alumno con Menor promedio");
     printf("\n 6. Ordenar por nombre ascendente");
     printf("\n 7. Ordenar por nombre descendente");
     printf("\n 8. Salir");
     opc=leeEntero("\n Ingrese opcion: ", 1, 8);
     switch(opc)
     {
       case 1: leerListaAlumno(LA); break;
       case 2: mostrarListaAlumno(LA); break;
       case 3: promedioEdad(LA); break;
       case 4: mayorPromedio(LA); break;
       case 5: menorPromedio(LA); break;
       case 6: OrdenarAsc(LA); break;
       case 7: OrdenarDesc(LA); break;
       case 8: liberarListaAlumnos(LA); break;
     }
  }while(opc!=8);

}

int main()
{
 listaAlumnos LA;

 iniciaListaAlumno(LA);
 menu(LA);
 return 1;
}
