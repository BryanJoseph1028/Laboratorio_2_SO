#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

sem_t semaforo;
struct Persona {
char nombre[20];
char apellidos[20];
char fechan[20];
char dpi[30];
char telefono[20];
char direccion[30];
char departamento[20];
char municipio[20];
};


void* proceso(void* arg){
    sem_wait(&semaforo);
    printf("%s procesando....\n",(char*)arg);
    sleep(3);
    sem_post(&semaforo);
    sleep(4);
}

int main()
{
	sem_init(&semaforo,0,1);
struct Persona persona[30];
	FILE *fichero;
	char texto[100];

	fichero = fopen("regristros.csv","w");
	if (fichero == NULL) {
		printf( "No se puede crear el fichero.\n" );
		exit( 1 );
	}

		fputs("\n", fichero);
		printf("escribiendo....\n");
		fgets(persona->nombre,20,fichero);
		fgets(persona->apellidos,20,fichero);
		fgets(persona->direccion,20,fichero);
		fgets(persona->telefono,20,fichero);
		fgets(persona->dpi,20,fichero);
		fgets(persona->fechan,20,fichero);
		fgets(persona->municipio,20,fichero);
		fgets(persona->departamento,20,fichero);
	

	if (fclose(fichero)!=0)
		printf( "Problemas al cerrar el fichero\n" );

	fichero = fopen("regristros.csv","r");
	if (fichero == NULL) {
		printf( "No se puede crear el fichero.\n" );
		exit( 1 );
	}
	printf( "Contenido del fichero:\n" );
	fgets(texto,100,fichero);
	fgets(persona->nombre,20,fichero);
	fgets(persona->apellidos,20,fichero);
	fgets(persona->fechan,20,fichero);
	fgets(persona->dpi,20,fichero);
	fgets(persona->telefono,20,fichero);
	fgets(persona->municipio,20,fichero);
	fgets(persona->departamento,20,fichero);
	
	while (feof(fichero) == 0) {
		
		printf( "%s",texto );
		fgets(texto,100,fichero);
	}
	if (fclose(fichero)!=0)
		printf( "Problemas al cerrar el fichero\n" );
	
pthread_t proceso1;
pthread_t proceso2;	
pthread_t proceso3;	
pthread_t proceso4;	
pthread_t proceso5;	
pthread_create(&proceso1, NULL, proceso, "p1");
pthread_create(&proceso2, NULL, proceso, "p2");
pthread_create(&proceso3, NULL, proceso, "p3");
pthread_create(&proceso4, NULL, proceso, "p4");
pthread_create(&proceso5, NULL, proceso, "p5");

pthread_join(proceso1, NULL);
pthread_join(proceso2, NULL);
pthread_join(proceso3, NULL);
pthread_join(proceso4, NULL);
pthread_join(proceso5, NULL);
return 0;	
}