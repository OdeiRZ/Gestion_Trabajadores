#include <stdio.h>      
#include <stdlib.h>
#include <conio.h>
#include <string.h>       
#include <ctype.h>
#include <time.h>
                 
//////////////////////////////////////////////////////////
														//
#define FICHERO_trabajadores "Trabajadores.dat" 		//
                                                        //
typedef struct {                                        //
	char 	dni[10];                               		//
	char 	nombre[25];                                 //
	char 	f_nacimiento[11];                           //	
	char 	telefono[10];		                    	//
	long 	cod_categoria;                            	//
}	tipo_trabajadores;                                 	//* Definicion de estructuras,
	tipo_trabajadores registro_trabajadores;           	//* variables tipo registro,
														//* y funciones de 'trabajadores'
typedef struct {                                        //
	long 	num_registros;                              //
	char 	blancos[sizeof(registro_trabajadores)-4];   //
}	primer_registro_trabajadores;                       //
	primer_registro_trabajadores registro0_trabajadores;//
														//
void altas_trabajadores(char []);                       //
void listados_trabajadores(void);                     	//
void consultas_trabajadores(void);                    	//
void modificaciones_trabajadores(void);               	//
void bajas_trabajadores(void);                        	//
void ordenacion_trabajadores(void);                   	//
														//
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
														//
#define FICHERO_categorias "Categorias.dat"             //
														//
typedef struct {                                        //
	long 	cod_categoria;                        		//
	char 	nombre[25];                                 //
	float	precio_hora;                            	//
}	tipo_categorias;                                 	//* Definicion de estructuras,
	tipo_categorias registro_categorias;           		//* variables tipo registro,
														//* y funciones de 'categorias'
typedef struct {                                        //
	long 	num_registros;                              //
	char 	blancos[sizeof(registro_categorias)-4];    	//
}	primer_registro_categorias;                        	//
	primer_registro_categorias registro0_categorias;  	//
														//
void altas_categorias(void);                        	//
void listados_categorias(void);                     	//
void consultas_categorias(void);                    	//
void modificaciones_categorias(void);               	//
void bajas_categorias(void);                        	//
void ordenacion_categorias(void);                       //
														//
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
														//
#define FICHERO_fichas "Fichas.dat"                     //
														//
typedef struct {                                        //
	long 	cod_ficha;									//
	char 	dni[10];                               		//
	char 	fecha[11];                                  //
	char 	h_inicio[6];                            	//
	char 	h_final[6];		                            //
	int 	tiempo;                                     //
	long 	cod_obra;                            		//
}	tipo_fichas;                                 		//* Definicion de estructuras,
	tipo_fichas registro_fichas;           				//* variables tipo registro,
														//* y funciones de 'fichas'
typedef struct {                                        //
	long 	num_registros;                              //
	char 	blancos[sizeof(registro_fichas)-4];    		//
}	primer_registro_fichas;                        		//
	primer_registro_fichas registro0_fichas;  			//
														//
void altas_fichas(void);                        		//
void listados_fichas(void);                     		//
void consultas_fichas(void);                    		//
void modificaciones_fichas(void);               		//
void bajas_fichas(void);                        		//
void ordenacion_fichas(void);                        	//
														//
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
														//
#define FICHERO_obras "Obras.dat"                       //
														//
typedef struct {                                        //
	long 	cod_obra;									//
	char 	f_inicio[11];   							//
	char 	f_final[11];								//
	char 	estado[20];     							//
	char 	dni[10];       								//
}	tipo_obras;                                 		//* Definicion de estructuras,
	tipo_obras registro_obras;           				//* variables tipo registro,
														//* y funciones de 'obras'
typedef struct {                                      	//
	long 	num_registros;                              //               
	char 	blancos[sizeof(registro_obras)-4];    		//
}	primer_registro_obras;                        		//
	primer_registro_obras registro0_obras;  			//
														//
void altas_obras(void);                        			//
void listados_obras(void);                     			//
void consultas_obras(void);                    			//
void modificaciones_obras(void);               			//
void bajas_obras(void);                        			//
void ordenacion_obras(void);                        	//
														//
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
														//
void menu_admin(void);									//
void obtener_fecha(char []);                            //
void creacion_ficheros(void);                           //
 														//
//////////////////////////////////////////////////////////

int main() {
	char pass[5];
	int seleccion=1,seleccion2,i;
	creacion_ficheros();

	while(seleccion!=0) {
		clrscr();seleccion2=1;
		gotoxy(68,1);printf("Log: Usuario");
		printf("\n\n\n\n\n\n\t\t\t\tMenu Usuario\n\n");
		printf("\t\t\t\t1. Gestion de Fichas\n");
		printf("\t\t\t\t2. Menu Administrador\n");
		printf("\t\t\t\t0. Salir\n\n");
		printf("\t\t\t\tOpcion => ");
		scanf("%d",&seleccion);fflush(stdin);
		switch(seleccion) {
			case 1 : {
				while(seleccion2!=0) {
					clrscr();
					gotoxy(68,1);printf("Log: Usuario");
					printf("\n\n\n\n\n\n\t\t\t\tGestion de Fichas\n\n");
					printf("\t\t\t\t1. Altas\n");
					printf("\t\t\t\t2. Listado\n");
					printf("\t\t\t\t3. Consultas\n");
					printf("\t\t\t\t4. Modificaciones\n");
					printf("\t\t\t\t5. Bajas\n");
					printf("\t\t\t\t0. Volver\n\n");
					printf("\t\t\t\tOpcion => ");
					scanf("%d",&seleccion2);fflush(stdin);
					switch(seleccion2) {
						case 1 : altas_fichas();						break;
						case 2 : listados_fichas();     				break;
						case 3 : consultas_fichas();     				break;
						case 4 : modificaciones_fichas();				break;
						case 5 : bajas_fichas();     					break;
						case 0 : printf("\n\t\t\t\tAdios");   			break;
						default: printf("\n\t\t\t\tElija entre 0 - 5");	getch();
					}
				}
			}	break;
			case 2 : {
				printf("\n\t\t\t\tClave => ");
				for(i=0;i<5;i++) {
					pass[i]=getch();
					printf("*");
				}
				if(strncmp(pass,"admin",5)==0) {
					menu_admin();
					return 0;
				}
			}	break;
			case 0 : printf("\n\t\t\t\tAdios");   						break;
			default: printf("\n\t\t\t\tElija entre 0 - 2");				getch();
		}
	}
	return 0;
}

void menu_admin() {
	int seleccion=1,seleccion2;
	creacion_ficheros();
                           
	while(seleccion!=0) {
		clrscr();seleccion2=1;
		gotoxy(68,1);printf("Log: Admin");
		printf("\n\n\n\n\n\n\t\t\t\tMenu Administrador\n\n");
		printf("\t\t\t\t1. Gestion de Trabajadores\n");
		printf("\t\t\t\t2. Gestion de Categorias\n");
		printf("\t\t\t\t3. Gestion de Fichas\n");
		printf("\t\t\t\t4. Gestion de Obras\n");
		printf("\t\t\t\t0. Salir\n\n");
		printf("\t\t\t\tOpcion => ");
		scanf("%d",&seleccion);fflush(stdin);
		switch(seleccion) {
			case 1 : {
				while(seleccion2!=0) {
					clrscr();
					gotoxy(68,1);printf("Log: Admin");
					printf("\n\n\n\n\n\n\t\t\t\tGestion de Trabajadores\n\n");
					printf("\t\t\t\t1. Altas\n");
					printf("\t\t\t\t2. Listado\n");
					printf("\t\t\t\t3. Consultas\n");
					printf("\t\t\t\t4. Modificaciones\n");
					printf("\t\t\t\t5. Bajas\n");
					printf("\t\t\t\t0. Volver\n\n");
					printf("\t\t\t\tOpcion => ");
					scanf("%d",&seleccion2);fflush(stdin);
					switch(seleccion2) {
						case 1 : altas_trabajadores("");				break;
						case 2 : listados_trabajadores();     			break;
						case 3 : consultas_trabajadores();     			break;
						case 4 : modificaciones_trabajadores();			break;
						case 5 : bajas_trabajadores();     				break;
						case 0 : printf("\n\t\t\t\tAdios");   			break;
						default: printf("\n\t\t\t\tElija entre 0 - 5");	getch();
					}
				}
			}	break;
			case 2 : {
				while(seleccion2!=0) {
					clrscr();
					gotoxy(68,1);printf("Log: Admin");
					printf("\n\n\n\n\n\n\t\t\t\tGestion de Categorias\n\n");
					printf("\t\t\t\t1. Altas\n");
					printf("\t\t\t\t2. Listado\n");
					printf("\t\t\t\t3. Consultas\n");
					printf("\t\t\t\t4. Modificaciones\n");
					printf("\t\t\t\t5. Bajas\n");
					printf("\t\t\t\t0. Volver\n\n");
					printf("\t\t\t\tOpcion => ");
					scanf("%d",&seleccion2);fflush(stdin);
					switch(seleccion2) {
						case 1 : altas_categorias();					break;
						case 2 : listados_categorias();     			break;
						case 3 : consultas_categorias();     			break;
						case 4 : modificaciones_categorias();			break;
						case 5 : bajas_categorias();     				break;
						case 0 : printf("\n\t\t\t\tAdios");   			break;
						default: printf("\n\t\t\t\tElija entre 0 - 5");	getch();
					}
				}
			}	break;
			case 3 : {
				while(seleccion2!=0) {
					clrscr();
					gotoxy(68,1);printf("Log: Admin");
					printf("\n\n\n\n\n\n\t\t\t\tGestion de Fichas\n\n");
					printf("\t\t\t\t1. Altas\n");
					printf("\t\t\t\t2. Listado\n");
					printf("\t\t\t\t3. Consultas\n");
					printf("\t\t\t\t4. Modificaciones\n");
					printf("\t\t\t\t5. Bajas\n");
					printf("\t\t\t\t0. Volver\n\n");
					printf("\t\t\t\tOpcion => ");
					scanf("%d",&seleccion2);fflush(stdin);
					switch(seleccion2) {
						case 1 : altas_fichas();						break;
						case 2 : listados_fichas();     				break;
						case 3 : consultas_fichas();     				break;
						case 4 : modificaciones_fichas();				break;
						case 5 : bajas_fichas();     					break;
						case 0 : printf("\n\t\t\t\tAdios");   			break;
						default: printf("\n\t\t\t\tElija entre 0 - 5");	getch();
					}
				}
			}	break;
			case 4 : {
				while(seleccion2!=0) {
					clrscr();
					gotoxy(70,1);printf("Log: Admin");
					printf("\n\n\n\n\n\n\t\t\t\tGestion de Obras\n\n");
					printf("\t\t\t\t1. Altas\n");
					printf("\t\t\t\t2. Listado\n");
					printf("\t\t\t\t3. Consultas\n");
					printf("\t\t\t\t4. Modificaciones\n");
					printf("\t\t\t\t5. Bajas\n");
					printf("\t\t\t\t0. Volver\n\n");
					printf("\t\t\t\tOpcion => ");
					scanf("%d",&seleccion2);fflush(stdin);
					switch(seleccion2) {
						case 1 : altas_obras();							break;
						case 2 : listados_obras();     					break;
						case 3 : consultas_obras();     				break;
						case 4 : modificaciones_obras();				break;
						case 5 : bajas_obras();     					break;
						case 0 : printf("\n\t\t\t\tAdios");   			break;
						default: printf("\n\t\t\t\tElija entre 0 - 5");	getch();
					}
				}
			}	break;                  
			case 0 : printf("\n\t\t\t\tAdios");   						break;
			default: printf("\n\t\t\t\tElija entre 0 - 4");				getch();
		}
	}
}

void altas_trabajadores(char cod[]) {									//revisar opcion creacion trabajador desde codigo
	FILE *canal,*canal2;
	int i,sw;
	char eleccion,dni[10],aux_cod_categoria[10];
	long N_trabajadores,N_aux,desplazamiento;

	do {
		sw=0;clrscr();fflush(stdin);
		canal=fopen(FICHERO_trabajadores,"r+b");
		fseek(canal,0L,0);
		fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal);
		N_trabajadores=registro0_trabajadores.num_registros;
		N_trabajadores++;

		gotoxy(1,1);printf("Ficha");
		gotoxy(8,1);printf("DNI");
		gotoxy(20,1);printf("Nombre");
		gotoxy(42,1);printf("F.Nacim.");
		gotoxy(55,1);printf("Telefono");
		gotoxy(67,1);printf("Categoria");
		gotoxy(3,3);printf("%ld",N_trabajadores);
		if(strcmp(cod,"")==0) { 										//Comprobador de tipo de insercion enlazada
			do {                                                        //nos aseguramos que el tamaño de DNI es correcto
				if(sw) {
					gotoxy(8,3);
					printf("                 ");
				}
				gotoxy(8,3);gets(dni);
				sw=1;
			} while(strlen(dni)!=9);
			sw=0;
			if(N_trabajadores>1) {
				for(i=1;i<=N_trabajadores;i++) { 						//comprobamos existencia de dni repetido secuencialmente
					desplazamiento=i*sizeof(registro_trabajadores);
					fseek(canal,desplazamiento,0);
					fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);
					
					if(strcmp(registro_trabajadores.dni,dni)==0) {
						sw=1;
						break;
					}
				}
				if(sw) {
					printf("\n  El DNI introducido ya existe");
					getch();fclose(canal);break;
				}
			}
			strcpy(registro_trabajadores.dni,dni);
		} else {
			gotoxy(8,3);printf("%s",cod);
			strcpy(registro_trabajadores.dni,cod);
		}

		gotoxy(20,3);gets(registro_trabajadores.nombre);

		sw=0;
		do {                                                          	//nos aseguramos que el tamaño de la fecha no excede del maximo
        	if(sw) {
				gotoxy(42,3);
				printf("             ");
			}
			gotoxy(42,3);gets(registro_trabajadores.f_nacimiento);
			sw=1;
		} while(strlen(registro_trabajadores.f_nacimiento)!=10);

		sw=0;
		do {                                                         	//nos aseguramos que el tamaño del telefono es el correcto
        	if(sw) {
				gotoxy(55,3);
				printf("             ");
			}
			 gotoxy(55,3);gets(registro_trabajadores.telefono);
			 sw=1;
		} while(strlen(registro_trabajadores.telefono)!=9);

		sw=0;
		do {                                                          	//nos aseguramos que la categoria es un digito
        	if(sw) {
				gotoxy(71,3);
				printf("        ");
			}
			gotoxy(71,3);gets(aux_cod_categoria);
			sw=0;
			for(i=0;i<strlen(aux_cod_categoria);i++)
				if(!isdigit(aux_cod_categoria[i]))                      //comprobacion caracter a caracter
					sw=1;
		} while(sw);
		registro_trabajadores.cod_categoria=atol(aux_cod_categoria);

		sw=0;															//podriamos listar nombre categoria y codigo para poder introducirlo
		canal2=fopen(FICHERO_categorias,"r+b");                         //dando por hecho que las categorias no son muchas y entran en pantalla
		fseek(canal2,0L,0);
		fread(&registro0_categorias,sizeof(registro0_categorias),1,canal2);
		N_aux=registro0_categorias.num_registros;

		for(i=1;i<=N_aux;i++) {   										//comprobamos si el codigo existe secuencialmente
			desplazamiento=i*sizeof(registro_categorias);
			fseek(canal2,desplazamiento,0);
			fread(&registro_categorias,sizeof(registro_categorias),1,canal2);

			if(registro_categorias.cod_categoria==registro_trabajadores.cod_categoria) {                                     
				desplazamiento=N_trabajadores*sizeof(registro_trabajadores);
				fseek(canal,desplazamiento,0);
				fwrite(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

				desplazamiento=0L*sizeof(registro0_trabajadores);
				fseek(canal,desplazamiento,0);
				registro0_trabajadores.num_registros=N_trabajadores;
				for(i=0;i<sizeof(registro_trabajadores)-4;i++)
					registro0_trabajadores.blancos[i]=' ';
				fwrite(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal);

				sw=1;break;
			}
		}
		if(!sw) {
			printf("\n\nCategoria no encontrada");
			printf("\n¿Desea dar de Alta una nueva Categoria? (s/n) ");
         scanf("%c",&eleccion);fflush(stdin);
         if(eleccion=='s')
				altas_categorias();
		}		
		fclose(canal2);fclose(canal);
		cod="";fflush(stdin);
		printf("\n¿Quiere seguir dando de alta Trabajadores? (s/n): ");
	} while(getchar()=='s');

	if(N_trabajadores>1)
		ordenacion_trabajadores();
}

void altas_categorias() {
	FILE *canal;
	int i;
	long N,desplazamiento;       										//discrepancia de tipos debido a uso de int y long

	canal=fopen(FICHERO_categorias,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_categorias,sizeof(registro0_categorias),1,canal);
	N=registro0_categorias.num_registros;

	do{
		N++;fflush(stdin);clrscr();
		gotoxy(1,1);printf("Ficha");
		gotoxy(8,1);printf("Nombre");
		gotoxy(32,1);printf("Precio/Hora");
		gotoxy(3,3);printf("%ld",N);registro_categorias.cod_categoria=N;
		gotoxy(8,3);gets(registro_categorias.nombre);
		gotoxy(37,3);scanf("%f",&registro_categorias.precio_hora);fflush(stdin);

		desplazamiento=N*sizeof(registro_categorias);
		fseek(canal,desplazamiento,0);
		fwrite(&registro_categorias,sizeof(registro_categorias),1,canal);
		printf("\n¿Quiere seguir dando de alta Categorias? (s/n): ");
	}while(getchar()=='s');

	desplazamiento=0L*sizeof(registro0_categorias);
	fseek(canal,desplazamiento,0);
	registro0_categorias.num_registros=N;
	for(i=0;i<sizeof(registro_categorias)-4;i++)
		registro0_categorias.blancos[i]=' ';
	fwrite(&registro0_categorias,sizeof(registro0_categorias),1,canal);
	fclose(canal);
}