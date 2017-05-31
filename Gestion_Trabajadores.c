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

	do{
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
			do{                                                        //nos aseguramos que el tamaño de DNI es correcto
				if(sw) {
					gotoxy(8,3);
					printf("                 ");
				}
				gotoxy(8,3);gets(dni);
				sw=1;
			}while(strlen(dni)!=9);
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
		do{                                                          	//nos aseguramos que el tamaño de la fecha no excede del maximo
        	if(sw) {
				gotoxy(42,3);
				printf("             ");
			}
			gotoxy(42,3);gets(registro_trabajadores.f_nacimiento);
			sw=1;
		}while(strlen(registro_trabajadores.f_nacimiento)!=10);

		sw=0;
		do{                                                         	//nos aseguramos que el tamaño del telefono es el correcto
        	if(sw) {
				gotoxy(55,3);
				printf("             ");
			}
			 gotoxy(55,3);gets(registro_trabajadores.telefono);
			 sw=1;
		}while(strlen(registro_trabajadores.telefono)!=9);

		sw=0;
		do{                                                          	//nos aseguramos que la categoria es un digito
        	if(sw) {
				gotoxy(71,3);
				printf("        ");
			}
			gotoxy(71,3);gets(aux_cod_categoria);
			sw=0;
			for(i=0;i<strlen(aux_cod_categoria);i++)
				if(!isdigit(aux_cod_categoria[i]))                      //comprobacion caracter a caracter
					sw=1;
		}while(sw);
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
	}while(getchar()=='s');

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

void altas_fichas() {
	FILE *canal,*canal2;
	int i,sw,h1,h2,m1,m2,sw_fecha;
	char aux_cod_obra[10],eleccion,aux[2];
	long N_fichas,N_aux,desplazamiento;
                             
	do{
		clrscr();fflush(stdin);sw_fecha=0;
		canal=fopen(FICHERO_fichas,"r+b");
		fseek(canal,0L,0);
		fread(&registro0_fichas,sizeof(registro0_fichas),1,canal);
		N_fichas=registro0_fichas.num_registros;
		N_fichas++;

		printf("¿Desea usar la fecha de Sistema? (s/n): ");
		if(getchar()=='s')
			sw_fecha=1;
         
		clrscr();fflush(stdin);
		gotoxy(1,1);printf("Ficha");
		gotoxy(8,1);printf("DNI");
		gotoxy(20,1);printf("Fecha");
		gotoxy(32,1);printf("H.Inicio");
		gotoxy(44,1);printf("H.Final");
		gotoxy(56,1);printf("Obra");
		gotoxy(3,3);printf("%ld",N_fichas);registro_fichas.cod_ficha=N_fichas;
		if(sw_fecha){
			obtener_fecha(registro_fichas.fecha);
			gotoxy(20,3);printf("%s",registro_fichas.fecha);
		}

		sw=0;
		do{                                                             //nos aseguramos que el tamaño de dni no excede del maximo
        	if(sw){
				gotoxy(8,3);
				printf("             ");
			}
			gotoxy(8,3);gets(registro_fichas.dni);
			sw=1;
		}while(strlen(registro_fichas.dni)!=9);

		sw=0;
		canal2=fopen(FICHERO_trabajadores,"r+b");                                   
		fseek(canal2,0L,0);
		fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
		N_aux=registro0_trabajadores.num_registros;

		for(i=1;i<=N_aux;i++){   										//comprobamos si el codigo existe secuencialmente
			desplazamiento=i*sizeof(registro_trabajadores);
			fseek(canal2,desplazamiento,0);
			fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);

			if(strcmp(registro_trabajadores.dni,registro_fichas.dni)==0) {
				sw=1;
				break;
			}
		}
		if(!sw){
			printf("\n\nTrabajador no encontrado");
			printf("\n¿Desea dar de Alta al Trabajador? (s/n) ");
			scanf("%c",&eleccion);fflush(stdin);
			if(eleccion=='s')
				altas_trabajadores(registro_fichas.dni);
			fclose(canal2);fclose(canal);break;
		}

		if(!sw_fecha){
			sw=0;
			do{                                                           //nos aseguramos que el tamaño de la fehca no excede del maximo
	        	if(sw) {
					gotoxy(20,3);
					printf("             ");
				}
				gotoxy(20,3);gets(registro_fichas.fecha);
				sw=1;
			}while(strlen(registro_fichas.fecha)!=10);
		}
      
		sw=0;
		do{                                                               //nos aseguramos que la hora final no excede del maximo
        	if(sw){
				gotoxy(33,3);
				printf("             ");
			}
			gotoxy(33,3);gets(registro_fichas.h_inicio);
			sw=1;
		}while(strlen(registro_fichas.h_inicio)!=5 && strlen(registro_fichas.h_inicio)!=0);

		sw=0;
		do{                                                               //nos aseguramos que la hora inicial excede del maximo
        	if(sw){
				gotoxy(45,3);
				printf("             ");
			}
			gotoxy(45,3);gets(registro_fichas.h_final);
			sw=1;
		}while(strlen(registro_fichas.h_final)!=5 && strlen(registro_fichas.h_final)!=0);

		if(strlen(registro_fichas.h_inicio)>0 && strlen(registro_fichas.h_final)>0){
			aux[0]=registro_fichas.h_inicio[0];
			aux[1]=registro_fichas.h_inicio[1];
			aux[2]='\0';
			h1=atoi(aux);
			aux[0]=registro_fichas.h_inicio[3];
			aux[1]=registro_fichas.h_inicio[4];
			aux[2]='\0';
			m1=atoi(aux);
			aux[0]=registro_fichas.h_final[0];
			aux[1]=registro_fichas.h_final[1];
			aux[2]='\0';
			h2=atoi(aux);
			aux[0]=registro_fichas.h_final[3];
			aux[1]=registro_fichas.h_final[4];
			aux[2]='\0';
			m2=atoi(aux);

			if(h2==0)
		     	h2=24;

			if(h1>h2)
		     	registro_fichas.tiempo=(24-h1+h2)*60+(m1-m2);
			else
		     	if(m1>m2)
					registro_fichas.tiempo=(h2-h1-1)*60+(m1-m2-60);
		     	else
					registro_fichas.tiempo=(h2-h1-1)*60+(m2-m1+60);
		}else
			registro_fichas.tiempo=0;

		sw=0;
		do{                                                               	//nos aseguramos que la obra es un digito
        	if(sw){
				gotoxy(57,3);
				printf("        ");
			}
			gotoxy(57,3);gets(aux_cod_obra);
			sw=0;
			for(i=0;i<strlen(aux_cod_obra);i++)
				if(!isdigit(aux_cod_obra[i]))                             	//comprobacion caracter a caracter
					sw=1;
		}while(sw);
		registro_fichas.cod_obra=atol(aux_cod_obra);

		sw=0;fclose(canal2);											  	//podriamos listar nombre categoria y codigo para poder introducirlo
		canal2=fopen(FICHERO_obras,"r+b");                                	//dando por hecho que las categorias no son muchas y entran en pantalla
		fseek(canal2,0L,0);
		fread(&registro0_obras,sizeof(registro0_obras),1,canal2);
		N_aux=registro0_obras.num_registros;

		for(i=1;i<=N_aux;i++) {  											//comprobamos si el codigo existe secuencialmente
			desplazamiento=i*sizeof(registro_obras);
			fseek(canal2,desplazamiento,0);
			fread(&registro_obras,sizeof(registro_obras),1,canal2);

			if(registro_obras.cod_obra==registro_fichas.cod_obra) {                 
				desplazamiento=N_fichas*sizeof(registro_fichas);
				fseek(canal,desplazamiento,0);
				fwrite(&registro_fichas,sizeof(registro_fichas),1,canal);

				desplazamiento=0L*sizeof(registro0_fichas);
				fseek(canal,desplazamiento,0);
				registro0_fichas.num_registros=N_fichas;
				for(i=0;i<sizeof(registro0_fichas)-4;i++)
					registro0_fichas.blancos[i]=' ';
				fwrite(&registro0_fichas,sizeof(registro0_fichas),1,canal);

				sw=1;break;
			}
		}
		if(!sw) {
			printf("\n\nObra no encontrada");
			printf("\n¿Desea dar de Alta una nueva Obra? (s/n) ");
			scanf("%c",&eleccion);fflush(stdin);
			if(eleccion=='s')
				altas_obras();
		}
		fclose(canal2);fclose(canal);fflush(stdin);
		printf("\n¿Quiere seguir dando de alta Fichas? (s/n): ");
	}while(getchar()=='s');
}

void altas_obras() {
	FILE *canal,*canal2;
	int i,sw;
	char eleccion;
	long N_obras,N_aux,desplazamiento;

	do{
		sw=0;clrscr();fflush(stdin);
		canal=fopen(FICHERO_obras,"r+b");
		fseek(canal,0L,0);
		fread(&registro0_obras,sizeof(registro0_obras),1,canal);
		N_obras=registro0_obras.num_registros;
		N_obras++;
      
		gotoxy(1,1);printf("Ficha");
		gotoxy(8,1);printf("F.Inicio");
		gotoxy(21,1);printf("F.Final");
		gotoxy(34,1);printf("Estado");
		gotoxy(54,1);printf("Capataz");
		gotoxy(3,3);printf("%ld",N_obras);registro_obras.cod_obra=N_obras;

		do{                                                                    	  	//nos aseguramos que el tamaño de la fecha es correcto
        	if(sw) {
				gotoxy(8,3);
				printf("           ");
			}
			gotoxy(8,3);gets(registro_obras.f_inicio);
			sw=1;
		}while(strlen(registro_obras.f_inicio)!=10);

		sw=0;
		do{                                                                    	  	//nos aseguramos que el tamaño de la fecha es correcto
        	if(sw) {
				gotoxy(21,3);
				printf("           ");
			}
			gotoxy(21,3);gets(registro_obras.f_final);
			sw=1;
		}while(strlen(registro_obras.f_final)!=10);

		gotoxy(34,3);gets(registro_obras.estado);
      
		sw=0;
		do{                                                                    	  	//nos aseguramos que el tamaño del dni es correcto
        	if(sw) {
				gotoxy(54,3);
				printf("           ");
			}
			gotoxy(54,3);gets(registro_obras.dni);
			sw=1;
		}while(strlen(registro_obras.dni)!=9);

		sw=0;
		canal2=fopen(FICHERO_trabajadores,"r+b");
		fseek(canal2,0L,0);
		fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
		N_aux=registro0_trabajadores.num_registros;

		for(i=1;i<=N_aux;i++) {  													//comprobamos si el codigo existe secuencialmente
			desplazamiento=i*sizeof(registro_trabajadores);
			fseek(canal2,desplazamiento,0);
			fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);

			if(strcmp(registro_trabajadores.dni,registro_obras.dni)==0) {
				desplazamiento=N_obras*sizeof(registro_obras);
				fseek(canal,desplazamiento,0);
				fwrite(&registro_obras,sizeof(registro_obras),1,canal);

				desplazamiento=0L*sizeof(registro0_obras);
				fseek(canal,desplazamiento,0);
				registro0_obras.num_registros=N_obras;
				for(i=0;i<sizeof(registro0_obras)-4;i++)
					registro0_obras.blancos[i]=' ';
				fwrite(&registro0_obras,sizeof(registro0_obras),1,canal);

				sw=1;break;
			}
		}
		if(!sw){
			printf("\n\nCapataz no encontrado");
			printf("\n¿Desea dar de Alta al Trabajador? (s/n) ");
			scanf("%c",&eleccion);fflush(stdin);
			if(eleccion=='s')
				altas_trabajadores(registro_obras.dni);
		}		
		fclose(canal2);fclose(canal);fflush(stdin);
		printf("\n¿Quiere seguir dando de alta Obras? (s/n): ");
	}while(getchar()=='s');
}

void listados_trabajadores() {
	FILE *canal;
	int i,j=1;
	long N,desplazamiento;

	clrscr();
	canal=fopen(FICHERO_trabajadores,"rb");
	fseek(canal,0L,0);
	fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal);
	N=registro0_trabajadores.num_registros;

	if(N>=1){
		gotoxy(1,1);printf("Ficha");
		gotoxy(8,1);printf("DNI");
		gotoxy(20,1);printf("Nombre");
		gotoxy(42,1);printf("F.Nacim.");
		gotoxy(55,1);printf("Telefono");
		gotoxy(67,1);printf("Categoria");

		for(i=1;i<=N;i++){
			desplazamiento=i*sizeof(registro_trabajadores);
			fseek(canal,desplazamiento,0);
			fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);
			if(j%21==0){  																			  //tabulador de registros en pantalla
				printf("\n\nPulse una tecla para continuar..");
				getch();clrscr();j=1;
				gotoxy(1,1);printf("Ficha");
				gotoxy(8,1);printf("DNI");
				gotoxy(20,1);printf("Nombre");
				gotoxy(42,1);printf("F.Nacim.");
				gotoxy(55,1);printf("Telefono");
				gotoxy(67,1);printf("Categoria");
			}
			gotoxy(3,j+2);printf("%d",i);
			gotoxy(8,j+2);printf("%s",registro_trabajadores.dni);
			gotoxy(20,j+2);printf("%s",registro_trabajadores.nombre);
			gotoxy(42,j+2);printf("%s",registro_trabajadores.f_nacimiento);
			gotoxy(55,j+2);printf("%s",registro_trabajadores.telefono);
			gotoxy(70,j+2);printf("%ld",registro_trabajadores.cod_categoria);
			j++;
		}
   }else
		printf("El fichero '%s' esta vacio",FICHERO_trabajadores);
	printf("\n\nPulse una tecla para continuar..");getch();
	fclose(canal);
}

void listados_categorias() {
	FILE *canal;
	int i,j=1;
	long N,desplazamiento;

	clrscr();
	canal=fopen(FICHERO_categorias,"rb");
	fseek(canal,0L,0);
	fread(&registro0_categorias,sizeof(registro0_categorias),1,canal);
	N=registro0_categorias.num_registros;

	if(N>=1){
		gotoxy(1,1);printf("Ficha");
		gotoxy(8,1);printf("Nombre");
		gotoxy(30,1);printf("Precio/Hora");
      
		for(i=1;i<=N;i++) {
			desplazamiento=i*sizeof(registro_categorias);
			fseek(canal,desplazamiento,0);
			fread(&registro_categorias,sizeof(registro_categorias),1,canal);
			if(j%21==0) { 																			  //tabulador de registros en pantalla
				printf("\n\nPulse una tecla para continuar..");
				getch();clrscr();j=1;
				gotoxy(1,1);printf("Ficha");
				gotoxy(8,1);printf("Nombre");
				gotoxy(30,1);printf("Precio/Hora");
			}
			gotoxy(3,j+2);printf("%ld",registro_categorias.cod_categoria);
			gotoxy(8,j+2);printf("%s",registro_categorias.nombre);
			gotoxy(30,j+2);printf("%.2f",registro_categorias.precio_hora);
			j++;
		}
   }else
		printf("El FICHERO_categorias '%s' esta vacio",FICHERO_categorias);
	printf("\n\nPulse una tecla para continuar..");getch();
	fclose(canal);
}

void listados_fichas() {
	FILE *canal;
	int i,j=1;
	long N,desplazamiento;

	clrscr();
	canal=fopen(FICHERO_fichas,"rb");
	fseek(canal,0L,0);
	fread(&registro0_fichas,sizeof(registro0_fichas),1,canal);
	N=registro0_fichas.num_registros;

	if(N>=1) {
		gotoxy(1,1);printf("Ficha");
		gotoxy(12,1);printf("DNI");
		gotoxy(20,1);printf("Fecha");
		gotoxy(32,1);printf("H.Inicio");
		gotoxy(48,1);printf("H.Final");
		gotoxy(65,1);printf("Tiempo");
		gotoxy(72,1);printf("Obra");

		for(i=1;i<=N;i++) {
			desplazamiento=i*sizeof(registro_fichas);
			fseek(canal,desplazamiento,0);
			fread(&registro_fichas,sizeof(registro_fichas),1,canal);
			if(j%21==0) {  																			  //tabulador de registros en pantalla
				printf("\n\nPulse una tecla para continuar..");
				getch();clrscr();j=1;
				gotoxy(1,1);printf("Ficha");
				gotoxy(12,1);printf("DNI");
				gotoxy(20,1);printf("Fecha");
				gotoxy(32,1);printf("H.Inicio");
				gotoxy(48,1);printf("H.Final");
				gotoxy(65,1);printf("Tiempo");
				gotoxy(72,1);printf("Obra");
			}
			gotoxy(3,j+2);printf("%ld",registro_fichas.cod_ficha);
			gotoxy(8,j+2);printf("%s",registro_fichas.dni);
			gotoxy(20,j+2);printf("%s",registro_fichas.fecha);
			gotoxy(32,j+2);
			if(strcmp(registro_fichas.h_inicio,"")!=0)
				printf("%s",registro_fichas.h_inicio);
			else
				printf("  *");
			gotoxy(48,j+2);
			if(strcmp(registro_fichas.h_final,"")!=0)
				printf("%s",registro_fichas.h_final);
			else
				printf("  *");
			gotoxy(66,j+2);printf("%d",registro_fichas.tiempo);
			gotoxy(73,j+2);printf("%ld",registro_fichas.cod_obra);
			j++;
		}
   } else
		printf("El fichero '%s' esta vacio",FICHERO_fichas);
	printf("\n\nPulse una tecla para continuar..");getch();
	fclose(canal);
}

void listados_obras() {
	FILE *canal;
	int i,j=1;
	long N,desplazamiento;

	clrscr();
	canal=fopen(FICHERO_obras,"rb");
	fseek(canal,0L,0);
	fread(&registro0_obras,sizeof(registro0_obras),1,canal);
	N=registro0_obras.num_registros;

	if(N>=1) {
		gotoxy(1,1);printf("Ficha");
		gotoxy(8,1);printf("F.Inicio");
		gotoxy(21,1);printf("F.Final");
		gotoxy(34,1);printf("Estado");
		gotoxy(54,1);printf("Capataz");

		for(i=1;i<=N;i++) {
			desplazamiento=i*sizeof(registro_obras);
			fseek(canal,desplazamiento,0);
			fread(&registro_obras,sizeof(registro_obras),1,canal);
			if(j%21==0) {  																			  //tabulador de registros en pantalla
				printf("\n\nPulse una tecla para continuar..");
				getch();clrscr();j=1;
				gotoxy(1,1);printf("Ficha");
				gotoxy(8,1);printf("F.Inicio");
				gotoxy(21,1);printf("F.Final");
				gotoxy(34,1);printf("Estado");
				gotoxy(54,1);printf("Capataz");
			}
			gotoxy(3,j+2);printf("%ld",registro_obras.cod_obra);
			gotoxy(8,j+2);printf("%s",registro_obras.f_inicio);
			gotoxy(21,j+2);printf("%s",registro_obras.f_final);
			gotoxy(34,j+2);printf("%s",registro_obras.estado);
			gotoxy(54,j+2);printf("%s",registro_obras.dni);
			j++;
		}
	}else
		printf("El fichero '%s' esta vacio",FICHERO_obras);
	printf("\n\nPulse una tecla para continuar..");getch();
	fclose(canal);
}

void consultas_trabajadores() {
	FILE *canal;
	int seleccion=1,sw,i,j;
	long N,desplazamiento,cen,der,izq,categoria;
	char dni_trabajador[10],nom_trabajador[25];

	canal=fopen(FICHERO_trabajadores,"rb");
	fseek(canal,0L,0);
	fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal);
 	N=registro0_trabajadores.num_registros;

	if(N>=1) {
		while(seleccion!=0){
			clrscr();
			printf("\n\n\n\n\n\n\n\t\t\t\tConsultas de Trabajador\n\n");
			printf("\t\t\t\t1. DNI\n");
			printf("\t\t\t\t2. Nombre\n");
			printf("\t\t\t\t3. Categoria\n");
			printf("\t\t\t\t0. Volver\n\n");
			printf("\t\t\t\tOpcion => ");
			scanf("%d",&seleccion);fflush(stdin);
			switch(seleccion) {
				case 1 : {
					do{
						clrscr();
						printf("Introduce DNI a Consultar ('Fin'=Salir) => ");
						gets(dni_trabajador);fflush(stdin);clrscr();

						if(strncmp(dni_trabajador,"Fin",strlen(dni_trabajador))!=0) {
							sw=0;izq=1;der=N;
							do{
								cen=(izq+der)/2;
								desplazamiento=cen*sizeof(registro_trabajadores);
								fseek(canal,desplazamiento,0);
								fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

								if(strncmp(dni_trabajador,registro_trabajadores.dni,strlen(dni_trabajador))==0 || izq>=der) {
									sw=1;
									if(strncmp(dni_trabajador,registro_trabajadores.dni,strlen(dni_trabajador))==0) {
										gotoxy(1,1);printf("Ficha");
										gotoxy(8,1);printf("DNI");
										gotoxy(20,1);printf("Nombre");
										gotoxy(42,1);printf("F.Nacim.");
										gotoxy(55,1);printf("Telefono");
										gotoxy(67,1);printf("Categoria");
										gotoxy(3,3);printf("%ld",cen);
										gotoxy(8,3);printf("%s",registro_trabajadores.dni);
										gotoxy(20,3);printf("%s",registro_trabajadores.nombre);
										gotoxy(42,3);printf("%s",registro_trabajadores.f_nacimiento);
										gotoxy(55,3);printf("%s",registro_trabajadores.telefono);
										gotoxy(70,3);printf("%ld",registro_trabajadores.cod_categoria);
									} else
										printf("DNI de Trabajador no encontrado");
									printf("\n\nPulse una tecla para continuar..");
									getch();
								} else {
									if(strncmp(dni_trabajador,registro_trabajadores.dni,strlen(dni_trabajador))<0)
										der=cen-1;
									else
										izq=cen+1;
								}
							}while(!sw);
						}
					}while(strncmp(dni_trabajador,"Fin",strlen(dni_trabajador))!=0);
				}	break;
				case 2 : {
					do{
						clrscr();
						printf("Introduce Nombre a Consultar ('Fin'=Salir) => ");
						gets(nom_trabajador);fflush(stdin);clrscr();

						if(strncmp(nom_trabajador,"Fin",strlen(nom_trabajador))!=0) {
							sw=0;j=1;
							canal=fopen(FICHERO_trabajadores,"rb");
							for(i=1;i<=N;i++) {
								desplazamiento=i*sizeof(registro_trabajadores);
								fseek(canal,desplazamiento,0);
								fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

								if(strncmp(nom_trabajador,registro_trabajadores.nombre,strlen(nom_trabajador))==0) {
									if(j%21==0) { 										  //tabulador de registros en pantalla
										gotoxy(1,1);printf("Ficha");
										gotoxy(8,1);printf("DNI");
										gotoxy(20,1);printf("Nombre");
										gotoxy(42,1);printf("F.Nacim.");
										gotoxy(55,1);printf("Telefono");
										gotoxy(67,1);printf("Categoria");
										gotoxy(1,j+1);printf("\n\nPulse una tecla para continuar..");
										getch();clrscr();j=1;
									}
									gotoxy(3,j+2);printf("%d",i);
									gotoxy(8,j+2);printf("%s",registro_trabajadores.dni);
									gotoxy(20,j+2);printf("%s",registro_trabajadores.nombre);
									gotoxy(42,j+2);printf("%s",registro_trabajadores.f_nacimiento);
									gotoxy(55,j+2);printf("%s",registro_trabajadores.telefono);
									gotoxy(70,j+2);printf("%ld",registro_trabajadores.cod_categoria);
									sw=1;j++;
								}
							}
							if(sw) {
								gotoxy(1,1);printf("Ficha");
								gotoxy(8,1);printf("DNI");
								gotoxy(20,1);printf("Nombre");
								gotoxy(42,1);printf("F.Nacim.");
								gotoxy(55,1);printf("Telefono");
								gotoxy(67,1);printf("Categoria");
							} else
								printf("Nombre no encontrado");
							gotoxy(1,j+3);printf("Pulse una tecla para continuar..");
							getch();fclose(canal);
						}
					}while(strncmp(nom_trabajador,"Fin",strlen(nom_trabajador))!=0);
				}	break;
				case 3 : {
					do{
						clrscr();
						printf("Introduce Categoria a Consultar ('0'=Salir) => ");
						scanf("%ld",&categoria);fflush(stdin);clrscr();

						if(categoria!=0) {
							sw=0;j=1;
							canal=fopen(FICHERO_trabajadores,"rb");
							for(i=1;i<=N;i++) {
								desplazamiento=i*sizeof(registro_trabajadores);
								fseek(canal,desplazamiento,0);
								fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

								if(categoria==registro_trabajadores.cod_categoria) {
									if(j%21==0) {  										  //tabulador de registros en pantalla
										gotoxy(1,1);printf("Ficha");
										gotoxy(8,1);printf("DNI");
										gotoxy(20,1);printf("Nombre");
										gotoxy(42,1);printf("F.Nacim.");
										gotoxy(55,1);printf("Telefono");
										gotoxy(67,1);printf("Categoria");
										gotoxy(1,j+1);printf("\n\nPulse una tecla para continuar..");
										getch();clrscr();j=1;
									}
									gotoxy(3,j+2);printf("%d",i);
									gotoxy(8,j+2);printf("%s",registro_trabajadores.dni);
									gotoxy(20,j+2);printf("%s",registro_trabajadores.nombre);
									gotoxy(42,j+2);printf("%s",registro_trabajadores.f_nacimiento);
									gotoxy(55,j+2);printf("%s",registro_trabajadores.telefono);
									gotoxy(70,j+2);printf("%ld",registro_trabajadores.cod_categoria);
									sw=1;j++;
								}
							}
							if(sw) {
								gotoxy(1,1);printf("Ficha");
								gotoxy(8,1);printf("DNI");
								gotoxy(20,1);printf("Nombre");
								gotoxy(42,1);printf("F.Nacim.");
								gotoxy(55,1);printf("Telefono");
								gotoxy(67,1);printf("Categoria");
							} else
								printf("Categoria no encontrada");
							gotoxy(1,j+3);printf("Pulse una tecla para continuar..");getch();
							fclose(canal);
						}
					}while(categoria!=0);
				}	break;
				case 0 : 	break;
				default: 	printf("\n\t\t\t\tElija entre 0 - 3");	getch();
			}
		}
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_trabajadores);
		getch();
	}
	fclose(canal);                                    
}

void consultas_categorias() {
	FILE *canal;
	int seleccion=1,sw,j;
	long N,desplazamiento,i;
	char nom_categoria[25];

	canal=fopen(FICHERO_categorias,"rb");
	fseek(canal,0L,0);
	fread(&registro0_categorias,sizeof(registro0_categorias),1,canal);
 	N=registro0_categorias.num_registros;

	if(N>=1) {
		while(seleccion!=0) {
			clrscr();
			printf("\n\n\n\n\n\n\n\t\t\t\tConsultas de Categorias\n\n");
			printf("\t\t\t\t1. Nombre\n");
			printf("\t\t\t\t0. Volver\n\n");
			printf("\t\t\t\tOpcion => ");
			scanf("%d",&seleccion);fflush(stdin);
			switch(seleccion) {
				case 1 : {
					do{
						clrscr();
						printf("Introduce Nombre a Consultar ('Fin'=Salir) => ");
						gets(nom_categoria);fflush(stdin);clrscr();

						if(strncmp(nom_categoria,"Fin",strlen(nom_categoria))!=0) {
							sw=0;j=1;
							canal=fopen(FICHERO_categorias,"rb");
							for(i=1;i<=N;i++) {
								desplazamiento=i*sizeof(registro_categorias);
								fseek(canal,desplazamiento,0);
								fread(&registro_categorias,sizeof(registro_categorias),1,canal);

								if(strncmp(nom_categoria,registro_categorias.nombre,strlen(nom_categoria))==0) {
									if(j%21==0) { 										  //tabulador de registros en pantalla
										gotoxy(1,1);printf("Ficha");
										gotoxy(8,1);printf("Nombre");
										gotoxy(32,1);printf("Precio/Hora");
										gotoxy(1,j+1);printf("\n\nPulse una tecla para continuar..");
										getch();clrscr();j=1;
									}
									gotoxy(3,j+2);printf("%ld",registro_categorias.cod_categoria);
									gotoxy(8,j+2);printf("%s",registro_categorias.nombre);
									gotoxy(32,j+2);printf("%.2f",registro_categorias.precio_hora);
									sw=1;j++;
								}
							}
							if(sw) {
								gotoxy(1,1);printf("Ficha");
								gotoxy(8,1);printf("Nombre");
								gotoxy(32,1);printf("Precio/Hora");
							}
							else
								printf("Nombre de Categoria no encontrada");
							gotoxy(1,j+3);printf("Pulse una tecla para continuar..");getch();
							fclose(canal);
						}
					}while(strncmp(nom_categoria,"Fin",strlen(nom_categoria))!=0);
				}	break;
				case 0 : 	break;
				default: 	printf("\n\t\t\t\tElija entre 0 - 1");	getch();
			}
		}
	}
	else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_trabajadores);
		getch();
	}
	fclose(canal);
}

void consultas_fichas() {
	FILE *canal,*canal2;
	int seleccion=1,sw,i,j,a,a_f,k;
	long N_fichas,N_aux,desplazamiento,obra,categoria;
	float total_min,total_obra;
	char dni[10],aux[4];

	canal=fopen(FICHERO_fichas,"rb");
	fseek(canal,0L,0);
	fread(&registro0_fichas,sizeof(registro0_fichas),1,canal);
 	N_fichas=registro0_fichas.num_registros;

	if(N_fichas>=1) {
		while(seleccion!=0) {
			clrscr();
			printf("\n\n\n\n\n\n\n\t\t\t\tConsultas de Fichas\n\n");
			printf("\t\t\t\t1. Año\n");
			printf("\t\t\t\t2. Obra\n");
			printf("\t\t\t\t3. Trabajador\n");
			printf("\t\t\t\t0. Volver\n\n");
			printf("\t\t\t\tOpcion => ");
			scanf("%d",&seleccion);fflush(stdin);
			switch(seleccion) {
				case 1 : {
					do{
						clrscr();
						printf("Introduce Año a Consultar ('0'=Salir) => ");
						scanf("%d",&a);fflush(stdin);clrscr();

						if(a!=0) {
							sw=0;j=1;total_min=0,total_obra=0;;
							canal=fopen(FICHERO_fichas,"rb");
							for(i=1;i<=N_fichas;i++) {
								desplazamiento=i*sizeof(registro_fichas);
								fseek(canal,desplazamiento,0);
								fread(&registro_fichas,sizeof(registro_fichas),1,canal);

								aux[0]=registro_fichas.fecha[6];
								aux[1]=registro_fichas.fecha[7];
								aux[2]=registro_fichas.fecha[8];
								aux[3]=registro_fichas.fecha[9];
								aux[4]='\0';      a_f=atoi(aux);               //Extracion de año

								if(a==a_f) {
									if(j%17==0) { 										  //tabulador de registros en pantalla
										gotoxy(1,1);printf("Ficha");
										gotoxy(12,1);printf("DNI");
										gotoxy(20,1);printf("Fecha");
										gotoxy(32,1);printf("H.Inicio");
										gotoxy(48,1);printf("H.Final");
										gotoxy(65,1);printf("Tiempo");
										gotoxy(72,1);printf("Obra");
										gotoxy(1,j+1);printf("\n\nPulse una tecla para continuar..");
										getch();clrscr();j=1;
									}
									gotoxy(3,j+2);printf("%ld",registro_fichas.cod_ficha);
									gotoxy(8,j+2);printf("%s",registro_fichas.dni);
									gotoxy(20,j+2);printf("%s",registro_fichas.fecha);
									gotoxy(32,j+2);
									if(strcmp(registro_fichas.h_inicio,"")!=0)
										printf("%s",registro_fichas.h_inicio);
									else
										printf("  *");
									gotoxy(48,j+2);
									if(strcmp(registro_fichas.h_final,"")!=0)
										printf("%s",registro_fichas.h_final);
									else
										printf("  *");
									gotoxy(66,j+2);printf("%d",registro_fichas.tiempo);
									gotoxy(73,j+2);printf("%ld",registro_fichas.cod_obra);
									strcpy(dni,registro_fichas.dni);
									sw=1;j++;total_min+=registro_fichas.tiempo;

									canal2=fopen(FICHERO_trabajadores,"rb");
									fseek(canal2,0L,0);
									fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
									N_aux=registro0_trabajadores.num_registros;

									for(k=1;k<=N_aux;k++) {
										desplazamiento=k*sizeof(registro_trabajadores);
										fseek(canal2,desplazamiento,0);
										fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);

										if(strcmp(registro_trabajadores.dni,dni)==0) {
											categoria=registro_trabajadores.cod_categoria;
											fclose(canal2);
											canal2=fopen(FICHERO_categorias,"rb");
											fseek(canal2,0L,0);          
											fread(&registro0_categorias,sizeof(registro0_categorias),1,canal2);
											N_aux=registro0_categorias.num_registros;

											for(k=1;k<=N_aux;k++) {
												desplazamiento=k*sizeof(registro_categorias);
												fseek(canal2,desplazamiento,0);
												fread(&registro_categorias,sizeof(registro_categorias),1,canal2);

												if(registro_categorias.cod_categoria==categoria) {
													total_obra+=registro_fichas.tiempo/60*registro_categorias.precio_hora;
													break;
												}
											}
											break;
										}
									}
									fclose(canal2);
								}
							}
							if(sw) {
								gotoxy(1,1);printf("Ficha");
								gotoxy(12,1);printf("DNI");
								gotoxy(20,1);printf("Fecha");
								gotoxy(32,1);printf("H.Inicio");
								gotoxy(48,1);printf("H.Final");
								gotoxy(65,1);printf("Tiempo");
								gotoxy(72,1);printf("Obra");
								gotoxy(65,j+2);printf("_____");
								gotoxy(57,j+4);printf("Total => %.0f (%.1fh)",total_min,total_min/60);
								gotoxy(65,j+5);printf("_____");
								gotoxy(57,j+7);printf("Euros => %.1f (Año)",total_obra);
							} else
								printf("Año de Ficha no encontrado");
							gotoxy(1,j+3);printf("Pulse una tecla para continuar..");
							getch();fclose(canal);
						}
					}while(a!=0);
				}	break;
				case 2 : {
					do{
						clrscr();
						printf("Introduce Nº de Obra a Consultar ('0'=Salir) => ");
						scanf("%ld",&obra);fflush(stdin);clrscr();

						if(obra!=0) {
							sw=0;j=1;total_min=0,total_obra=0;;
							canal=fopen(FICHERO_fichas,"rb");
							for(i=1;i<=N_fichas;i++) {
								desplazamiento=i*sizeof(registro_fichas);
								fseek(canal,desplazamiento,0);
								fread(&registro_fichas,sizeof(registro_fichas),1,canal);

								if(obra==registro_fichas.cod_obra) {
									if(j%17==0) {  										  //tabulador de registros en pantalla
										gotoxy(1,1);printf("Ficha");
										gotoxy(12,1);printf("DNI");
										gotoxy(20,1);printf("Fecha");
										gotoxy(32,1);printf("H.Inicio");
										gotoxy(48,1);printf("H.Final");
										gotoxy(65,1);printf("Tiempo");
										gotoxy(72,1);printf("Obra");
										gotoxy(1,j+1);printf("\n\nPulse una tecla para continuar..");
										getch();clrscr();j=1;
									}
									gotoxy(3,j+2);printf("%ld",registro_fichas.cod_ficha);
									gotoxy(8,j+2);printf("%s",registro_fichas.dni);
									gotoxy(20,j+2);printf("%s",registro_fichas.fecha);
									gotoxy(32,j+2);
									if(strcmp(registro_fichas.h_inicio,"")!=0)
										printf("%s",registro_fichas.h_inicio);
									else
										printf("  *");
									gotoxy(48,j+2);
									if(strcmp(registro_fichas.h_final,"")!=0)
										printf("%s",registro_fichas.h_final);
									else
										printf("  *");
									gotoxy(66,j+2);printf("%d",registro_fichas.tiempo);
									gotoxy(73,j+2);printf("%ld",registro_fichas.cod_obra);
									strcpy(dni,registro_fichas.dni);
									sw=1;j++;total_min+=registro_fichas.tiempo;

									canal2=fopen(FICHERO_trabajadores,"rb");
									fseek(canal2,0L,0);
									fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
									N_aux=registro0_trabajadores.num_registros;

									for(k=1;k<=N_aux;k++) {
										desplazamiento=k*sizeof(registro_trabajadores);
										fseek(canal2,desplazamiento,0);
										fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);

										if(strcmp(registro_trabajadores.dni,dni)==0) {
											categoria=registro_trabajadores.cod_categoria;
											fclose(canal2);
											canal2=fopen(FICHERO_categorias,"rb");
											fseek(canal2,0L,0);          
											fread(&registro0_categorias,sizeof(registro0_categorias),1,canal2);
											N_aux=registro0_categorias.num_registros;

											for(k=1;k<=N_aux;k++) {
												desplazamiento=k*sizeof(registro_categorias);
												fseek(canal2,desplazamiento,0);
												fread(&registro_categorias,sizeof(registro_categorias),1,canal2);

												if(registro_categorias.cod_categoria==categoria) {
													total_obra+=registro_fichas.tiempo/60*registro_categorias.precio_hora;
													break;
												}
											}
											break;
										}
									}
									fclose(canal2);
								}
							}
							if(sw) {
								gotoxy(1,1);printf("Ficha");
								gotoxy(12,1);printf("DNI");
								gotoxy(20,1);printf("Fecha");
								gotoxy(32,1);printf("H.Inicio");
								gotoxy(48,1);printf("H.Final");
								gotoxy(65,1);printf("Tiempo");
								gotoxy(72,1);printf("Obra");
								gotoxy(65,j+2);printf("_____");
								gotoxy(57,j+4);printf("Total => %.0f (%.1fh)",total_min,total_min/60);
								gotoxy(65,j+5);printf("_____");
								gotoxy(57,j+7);printf("Euros => %.1f (Obra)",total_obra);
							} else
								printf("No hay Registros para esta Obra");
							gotoxy(1,j+3);printf("Pulse una tecla para continuar..");getch();
							fclose(canal);
						}
					}while(obra!=0);
				}	break;
				case 3 : {
					do{
						clrscr();
						printf("Introduce DNI a Consultar ('Fin'=Salir) => ");
						gets(dni);fflush(stdin);clrscr();

						if(strncmp(dni,"Fin",strlen(dni))!=0) {
							sw=0;j=1;total_min=0;
							canal=fopen(FICHERO_fichas,"rb");
							for(i=1;i<=N_fichas;i++) {
								desplazamiento=i*sizeof(registro_fichas);
								fseek(canal,desplazamiento,0);
								fread(&registro_fichas,sizeof(registro_fichas),1,canal);

								if(strncmp(dni,registro_fichas.dni,strlen(dni))==0) {
									if(j%17==0) { 										  //tabulador de registros en pantalla
										gotoxy(1,1);printf("Ficha");
										gotoxy(12,1);printf("DNI");
										gotoxy(20,1);printf("Fecha");
										gotoxy(32,1);printf("H.Inicio");
										gotoxy(48,1);printf("H.Final");
										gotoxy(65,1);printf("Tiempo");
										gotoxy(72,1);printf("Obra");
										gotoxy(1,j+1);printf("\n\nPulse una tecla para continuar..");
										getch();clrscr();j=1;
									}
									gotoxy(3,j+2);printf("%ld",registro_fichas.cod_ficha);
									gotoxy(8,j+2);printf("%s",registro_fichas.dni);
									gotoxy(20,j+2);printf("%s",registro_fichas.fecha);
									gotoxy(32,j+2);
									if(strcmp(registro_fichas.h_inicio,"")!=0)
										printf("%s",registro_fichas.h_inicio);
									else
										printf("  *");
									gotoxy(48,j+2);
									if(strcmp(registro_fichas.h_final,"")!=0)
										printf("%s",registro_fichas.h_final);
									else
										printf("  *");
									gotoxy(66,j+2);printf("%d",registro_fichas.tiempo);
									gotoxy(73,j+2);printf("%ld",registro_fichas.cod_obra);
									strcpy(dni,registro_fichas.dni);
									sw=1;j++;total_min+=registro_fichas.tiempo;
								}
							}
							if(sw) {
								gotoxy(1,1);printf("Ficha");
								gotoxy(12,1);printf("DNI");
								gotoxy(20,1);printf("Fecha");
								gotoxy(32,1);printf("H.Inicio");
								gotoxy(48,1);printf("H.Final");
								gotoxy(65,1);printf("Tiempo");
								gotoxy(72,1);printf("Obra");

								canal2=fopen(FICHERO_trabajadores,"rb");
								fseek(canal2,0L,0);
								fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
								N_aux=registro0_trabajadores.num_registros;

								for(k=1;k<=N_aux;k++) {
									desplazamiento=k*sizeof(registro_trabajadores);
									fseek(canal2,desplazamiento,0);
									fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);
						
									if(strcmp(registro_trabajadores.dni,dni)==0) {
										categoria=registro_trabajadores.cod_categoria;
										canal2=fopen(FICHERO_categorias,"rb");
										fseek(canal2,0L,0);
										fread(&registro0_categorias,sizeof(registro0_categorias),1,canal2);
										N_aux=registro0_categorias.num_registros;

										for(k=1;k<=N_aux;k++) {
											desplazamiento=k*sizeof(registro_categorias);
											fseek(canal2,desplazamiento,0);
											fread(&registro_categorias,sizeof(registro_categorias),1,canal2);

											if(registro_categorias.cod_categoria==categoria) {
												gotoxy(65,j+2);printf("_____");
												gotoxy(57,j+4);printf("Total => %.0f (%.1fh)",total_min,total_min/60);
												gotoxy(65,j+5);printf("_____");
												gotoxy(57,j+7);printf("Euros => %.1f (%.0fE/h)",total_min/60*registro_categorias.precio_hora,registro_categorias.precio_hora);
												break;
											}
										}
										break;
									}
								}
								fclose(canal2);
							} else
								printf("DNI no encontrado");
							gotoxy(1,j+3);printf("Pulse una tecla para continuar..");
							getch();fclose(canal);
						}
					}while(strncmp(dni,"Fin",strlen(dni))!=0);
				}	break;
				case 0 : 	break;
				default: 	printf("\n\t\t\t\tElija entre 0 - 3");	getch();
			}
	   }
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_trabajadores);
		getch();
	}
	fclose(canal);
}

void consultas_obras() {
	FILE *canal;
	int seleccion=1,sw,i,j,a,a_i,a_f;
	long N,desplazamiento;
	char dni[10],aux[4];

	canal=fopen(FICHERO_obras,"rb");
	fseek(canal,0L,0);
	fread(&registro0_obras,sizeof(registro0_obras),1,canal);
 	N=registro0_obras.num_registros;

	if(N>=1) {
		while(seleccion!=0) {
			clrscr();
			printf("\n\n\n\n\n\n\n\t\t\t\tConsultas de Obras\n\n");
			printf("\t\t\t\t1. Año\n");
			printf("\t\t\t\t2. Capataz\n");
			printf("\t\t\t\t0. Volver\n\n");
			printf("\t\t\t\tOpcion => ");
			scanf("%d",&seleccion);fflush(stdin);
			switch(seleccion) {
				case 1 : {
					do{
						clrscr();
						printf("Introduce Año de Obra a Consultar ('0'=Salir) => ");
						scanf("%d",&a);fflush(stdin);clrscr();

						if(a!=0) {
							sw=0;j=1;
							canal=fopen(FICHERO_obras,"rb");
							for(i=1;i<=N;i++) {
								desplazamiento=i*sizeof(registro_obras);
								fseek(canal,desplazamiento,0);
								fread(&registro_obras,sizeof(registro_obras),1,canal);

								aux[0]=registro_obras.f_inicio[6];
								aux[1]=registro_obras.f_inicio[7];
								aux[2]=registro_obras.f_inicio[8];
								aux[3]=registro_obras.f_inicio[9];
								aux[4]='\0';        a_i=atoi(aux);             //Extracion de año inicial

								aux[0]=registro_obras.f_final[6];
								aux[1]=registro_obras.f_final[7];
								aux[2]=registro_obras.f_final[8];
								aux[3]=registro_obras.f_final[9];
								aux[4]='\0';       a_f=atoi(aux);              //Extracion de año final

								if(a>=a_i && a<=a_f) {
									if(j%21==0) { 										  //tabulador de registros en pantalla
										gotoxy(1,1);printf("Ficha");
										gotoxy(8,1);printf("F.Inicio");
										gotoxy(21,1);printf("F.Final");
										gotoxy(34,1);printf("Estado");
										gotoxy(54,1);printf("Capataz");
										gotoxy(1,j+1);printf("\n\nPulse una tecla para continuar..");
										getch();clrscr();j=1;
									}
									gotoxy(3,j+2);printf("%ld",registro_obras.cod_obra);
									gotoxy(8,j+2);printf("%s",registro_obras.f_inicio);
									gotoxy(21,j+2);printf("%s",registro_obras.f_final);
									gotoxy(34,j+2);printf("%s",registro_obras.estado);
									gotoxy(54,j+2);printf("%s",registro_obras.dni);
									sw=1;j++;
								}
							}
							if(sw) {
								gotoxy(1,1);printf("Ficha");
								gotoxy(8,1);printf("F.Inicio");
								gotoxy(21,1);printf("F.Final");
								gotoxy(34,1);printf("Estado");
								gotoxy(54,1);printf("Capataz");
							} else
								printf("Año de Obra no encontrado en Rango");
							gotoxy(1,j+3);printf("Pulse una tecla para continuar..");
							getch();fclose(canal);
						}
					}while(a!=0);
				}	break;
				case 2 : {
					do{
						clrscr();
						printf("Introduce DNI de Capataz a Consultar ('Fin'=Salir) => ");
						gets(dni);fflush(stdin);clrscr();

						if(strncmp(dni,"Fin",strlen(dni))!=0) {
							sw=0;j=1;
							canal=fopen(FICHERO_obras,"rb");
							for(i=1;i<=N;i++)
							{
								desplazamiento=i*sizeof(registro_obras);
								fseek(canal,desplazamiento,0);
								fread(&registro_obras,sizeof(registro_obras),1,canal);

								if(strncmp(dni,registro_obras.dni,strlen(dni))==0) {
									if(j%21==0) { 										  //tabulador de registros en pantalla
										gotoxy(1,1);printf("Ficha");
										gotoxy(8,1);printf("F.Inicio");
										gotoxy(21,1);printf("F.Final");
										gotoxy(34,1);printf("Estado");
										gotoxy(54,1);printf("Capataz");
										gotoxy(1,j+1);printf("\n\nPulse una tecla para continuar..");
										getch();clrscr();j=1;
									}
									gotoxy(3,j+2);printf("%ld",registro_obras.cod_obra);
									gotoxy(8,j+2);printf("%s",registro_obras.f_inicio);
									gotoxy(21,j+2);printf("%s",registro_obras.f_final);
									gotoxy(34,j+2);printf("%s",registro_obras.estado);
									gotoxy(54,j+2);printf("%s",registro_obras.dni);
									sw=1;j++;
								}
							}
							if(sw) {
								gotoxy(1,1);printf("Ficha");
								gotoxy(8,1);printf("F.Inicio");
								gotoxy(21,1);printf("F.Final");
								gotoxy(34,1);printf("Estado");
								gotoxy(54,1);printf("Capataz");
							} else
								printf("Capataz no encontrado");
							gotoxy(1,j+3);printf("Pulse una tecla para continuar..");
							getch();fclose(canal);
						}
					}while(strncmp(dni,"Fin",strlen(dni))!=0);
				} break;
				case 0 : 	break;
				default: 	printf("\n\t\t\t\tElija entre 0 - 2");	getch();
			}
		}
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_trabajadores);
		getch();
	}
	fclose(canal);                                    
}

void modificaciones_trabajadores() {
	FILE *canal,*canal2;
	long N_trabajadores,N_aux,desplazamiento,cen,der,izq,cod;
	char dni[10],dni_antiguo[10],eleccion;
	int seleccion=1,sw,sw2,i;

	canal=fopen(FICHERO_trabajadores,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_trabajadores, sizeof(registro0_trabajadores),1,canal);
 	N_trabajadores=registro0_trabajadores.num_registros;

	if(N_trabajadores>=1) {
		do{
			clrscr();
			printf("Introduce DNI de Trabajador a Modificar ('Fin'=Salir) => ");
			gets(dni);fflush(stdin);clrscr();

			if(strncmp(dni,"Fin",strlen(dni))!=0) {
				sw=0;izq=1;der=N_trabajadores;
				do{
					cen=(izq+der)/2;
				  	desplazamiento=cen*sizeof(registro_trabajadores);
					fseek(canal,desplazamiento,0);
					fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

					if(strncmp(dni,registro_trabajadores.dni,strlen(dni))==0 || izq>=der) {
						sw=1;
					 	if(strncmp(dni,registro_trabajadores.dni,strlen(dni))==0) {
							gotoxy(1,1);printf("Ficha");
							gotoxy(8,1);printf("DNI");
							gotoxy(20,1);printf("Nombre");
							gotoxy(42,1);printf("F.Nacim.");
							gotoxy(55,1);printf("Telefono");
							gotoxy(67,1);printf("Categoria");
							gotoxy(3,3);printf("%ld",cen);
							gotoxy(8,3);printf("%s",registro_trabajadores.dni);
							gotoxy(20,3);printf("%s",registro_trabajadores.nombre);
							gotoxy(42,3);printf("%s",registro_trabajadores.f_nacimiento);
							gotoxy(55,3);printf("%s",registro_trabajadores.telefono);
							gotoxy(70,3);printf("%ld",registro_trabajadores.cod_categoria);

							printf("\n\n¿Desea Modificar el Registro? (s/n): ");
							scanf("%c",&eleccion);fflush(stdin);
							if(eleccion=='s') {
								do{
									sw2=0;clrscr();
									gotoxy(1,1);printf("Ficha");
									gotoxy(8,1);printf("DNI");
									gotoxy(20,1);printf("Nombre");
									gotoxy(42,1);printf("F.Nacim.");
									gotoxy(55,1);printf("Telefono");
									gotoxy(67,1);printf("Categoria");
									gotoxy(3,3);printf("%ld",cen);
									gotoxy(8,3);printf("%s",registro_trabajadores.dni);
									gotoxy(20,3);printf("%s",registro_trabajadores.nombre);
									gotoxy(42,3);printf("%s",registro_trabajadores.f_nacimiento);
									gotoxy(55,3);printf("%s",registro_trabajadores.telefono);
									gotoxy(70,3);printf("%ld",registro_trabajadores.cod_categoria);

									printf("\n\n1. Modificar DNI\n");
									printf("2. Modificar Nombre\n");
									printf("3. Modificar F.Nacim.\n");
									printf("4. Modificar Telefono\n");
									printf("5. Modificar Categoria\n");
									printf("0. Volver\n\n");
									printf("Opcion => ");
									scanf("%d",&seleccion);fflush(stdin);
									switch(seleccion) {
										case 1 : {
											do{              							  //nos aseguramos que el tamaño de DNI es correcto
												if(sw2)
													printf("Error. Tamaño incorrecto\n");
												printf("\nInserte nuevo DNI => ");
												gets(dni);
												fflush(stdin);sw2=1;
											}while(strlen(dni)!=9);

											sw2=0;strcpy(dni_antiguo,registro_trabajadores.dni);
											canal2=fopen(FICHERO_trabajadores,"rb");
											for(i=1;i<=N_trabajadores;i++) {  	  //comprobamos si el dni existe secuencialmente
												desplazamiento=i*sizeof(registro_trabajadores);
												fseek(canal2,desplazamiento,0);
												fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);

												if(strcmp(dni_antiguo,dni)==0) {
													sw2=1;
													break;
												}
											}
											if(sw2) {
												printf("\nError. DNI duplicado");
												getch();break;
											} else {
												strcpy(registro_trabajadores.dni,dni);
												sw=2;                              //comprobador de modificacion de clave de articulo
											}

											fclose(canal2);sw2=0;
											canal2=fopen(FICHERO_obras,"r+b");
											fseek(canal2,0L,0);
											fread(&registro0_obras,sizeof(registro0_obras),1,canal2);
											N_aux=registro0_obras.num_registros;
											for(i=1;i<=N_aux;i++) {  	  			  //comprobamos si existen capataces con el mismo dni para actualizarlo
												desplazamiento=i*sizeof(registro_obras);
												fseek(canal2,desplazamiento,0);
												fread(&registro_obras,sizeof(registro_obras),1,canal2);

												if(strcmp(registro_obras.dni,dni_antiguo)==0) {
													strcpy(registro_obras.dni,dni);
													desplazamiento=i*sizeof(registro_obras);
													fseek(canal2,desplazamiento,0);
													fwrite(&registro_obras,sizeof(registro_obras),1,canal2);
													sw2=1;
												}
											}
											if(sw2) {
												printf("\nDNI de Capataz (Obras) Actualizado");
												getch();
											}

											fclose(canal2);sw2=0;
											canal2=fopen(FICHERO_fichas,"r+b");
											fseek(canal2,0L,0);
											fread(&registro0_fichas,sizeof(registro0_fichas),1,canal2);
											N_aux=registro0_fichas.num_registros;
											for(i=1;i<=N_aux;i++) {  	  			  //comprobamos si existen fichas con el mismo dni para actualizarlas
												desplazamiento=i*sizeof(registro_fichas);
												fseek(canal2,desplazamiento,0);
												fread(&registro_fichas,sizeof(registro_fichas),1,canal2);

												if(strcmp(registro_fichas.dni,dni_antiguo)==0) {
													strcpy(registro_fichas.dni,dni);
													desplazamiento=i*sizeof(registro_fichas);
													fseek(canal2,desplazamiento,0);
													fwrite(&registro_fichas,sizeof(registro_fichas),1,canal2);
													sw2=1;
												}
											}
											if(sw2) {
												printf("\nDNI de Trabajador (Fichas) Actualizado");
												getch();
											}
											fclose(canal2);
										} 	break;
										case 2 : {
											fflush(stdin);
											printf("\nInserte nuevo Nombre => ");
											gets(registro_trabajadores.nombre);
											sw=3;
										}	break;
										case 3 : {
                                    		do{                                	  //nos aseguramos que el tamaño es correcto
												if(sw2)
													printf("Error. Formato incorrecto (dd/mm/aaaa)\n");
												printf("\nInserte nueva F.Nacim. => ");
												gets(registro_trabajadores.f_nacimiento);
												fflush(stdin);sw2=1;
											}while(strlen(registro_trabajadores.f_nacimiento)!=10);
												sw=3;
										}	break;
										case 4 : {
                                    		do{                                	  //nos aseguramos que el tamaño es correcto
												if(sw2)
													printf("Error. Tamaño incorrecto\n");
												printf("\nInserte nuevo Telefono => ");
												gets(registro_trabajadores.telefono);
												fflush(stdin);sw2=1;
											}while(strlen(registro_trabajadores.telefono)!=9);
											sw=3;
										}	break;
										case 5 : {
											printf("\nInserte nueva Categoria => ");
											scanf("%ld",&cod);

											canal2=fopen(FICHERO_categorias,"rb");
											fseek(canal2,0L,0);
											fread(&registro0_categorias,sizeof(registro0_categorias),1,canal2);
											N_aux=registro0_categorias.num_registros;

											for(i=1;i<=N_aux;i++) {   				  //comprobamos si el dni existe secuencialmente
												desplazamiento=i*sizeof(registro_categorias);
												fseek(canal2,desplazamiento,0);
												fread(&registro_categorias,sizeof(registro_categorias),1,canal2);

												if(registro_categorias.cod_categoria==cod) {
													registro_trabajadores.cod_categoria=cod;
													sw2=1;sw=3;break;
												}
											}
											if(!sw2) {
												printf("\nCodigo de Categoria no encontrado");
												getch();
											}
											fclose(canal2);
										}	break;
										case 0 : {
	                           				if(sw>=2) {
												desplazamiento=cen*sizeof(registro_trabajadores);
												fseek(canal,desplazamiento,0);
												fwrite(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);
												printf("\nRegistro Modificado correctamente");
												printf("\n\nPulse una tecla para continuar..");
												getch();
											}
										}	break;
										default: 	printf("\nElija entre 0 - 5");	getch();
									}
								}while(seleccion!=0);
							}
						} else {
							printf("DNI de Trabajador no encontrado");
							printf("\n\nPulse una tecla para continuar..");
							getch();
						}
					} else {
						if(strncmp(dni,registro_trabajadores.dni,strlen(dni))<0)
							der=cen-1;
						else
							izq=cen+1;
					}
				}while(!sw);
			}
		}while(strncmp(dni,"Fin",strlen(dni))!=0);
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_trabajadores);
		getch();
	}
	fclose(canal);

	if(sw==2)           															//si modificamos dni realizamos ordenacion
		ordenacion_trabajadores();
}

void modificaciones_categorias() {
	FILE *canal;
	long N,desplazamiento,cen,der,izq,categoria;
	char eleccion;
	int seleccion=1,sw;

	canal=fopen(FICHERO_categorias,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_categorias, sizeof(registro0_categorias),1,canal);
 	N=registro0_categorias.num_registros;

	if(N>=1) {
		do{
			clrscr();
			printf("Introduce Nº de Categoria a Modificar ('0'=Salir) => ");
			scanf("%ld",&categoria);fflush(stdin);clrscr();

			if(categoria!=0) {
				sw=0;izq=1;der=N;
				do{
					cen=(izq+der)/2;
				  	desplazamiento=cen*sizeof(registro_categorias);
					fseek(canal,desplazamiento,0);
					fread(&registro_categorias,sizeof(registro_categorias),1,canal);

					if(categoria==registro_categorias.cod_categoria || izq>=der) {
						sw=1;
					 	if(categoria==registro_categorias.cod_categoria) {
							gotoxy(1,1);printf("Ficha");
							gotoxy(8,1);printf("Nombre");
							gotoxy(30,1);printf("Precio/Hora");
							gotoxy(3,3);printf("%ld",registro_categorias.cod_categoria);
							gotoxy(8,3);printf("%s",registro_categorias.nombre);
							gotoxy(30,3);printf("%.2f",registro_categorias.precio_hora);

							printf("\n\n¿Desea Modificar el Registro? (s/n): ");
							scanf("%c",&eleccion);fflush(stdin);
							if(eleccion=='s') {
								do{
									clrscr();
									gotoxy(1,1);printf("Ficha");
									gotoxy(8,1);printf("Nombre");
									gotoxy(30,1);printf("Precio/Hora");
									gotoxy(3,3);printf("%ld",registro_categorias.cod_categoria);
									gotoxy(8,3);printf("%s",registro_categorias.nombre);
									gotoxy(30,3);printf("%.2f",registro_categorias.precio_hora);

									printf("\n\n1. Modificar Nombre\n");
									printf("2. Modificar Precio/Hora\n");
									printf("0. Volver\n\n");
									printf("Opcion => ");
									scanf("%d",&seleccion);fflush(stdin);
									switch(seleccion) {
										case 1 : {
											fflush(stdin);
											printf("\nInserte nuevo Nombre => ");
											gets(registro_categorias.nombre);
											sw=2;
										}	break;
										case 2 : {
											fflush(stdin);
											printf("\nInserte nuevo Precio/Hora => ");
											scanf("%f",&registro_categorias.precio_hora);
											sw=2;
										}	break;
										case 0 : {
	                           				if(sw>1) {
												desplazamiento=cen*sizeof(registro_categorias);
												fseek(canal,desplazamiento,0);
												fwrite(&registro_categorias,sizeof(registro_categorias),1,canal);
												printf("\nRegistro Modificado correctamente");
												printf("\n\nPulse una tecla para continuar..");
												getch();
											}
										}	break;
										default: 	printf("\nElija entre 0 - 2");	getch();
									}
								}while(seleccion!=0);
							}
						} else {
							printf("Categoria no encontrada");
							printf("\n\nPulse una tecla para continuar..");
							getch();
						}
					} else {
						if(categoria<registro_categorias.cod_categoria)
							der=cen-1;
						else
							izq=cen+1;
					}
				}while(!sw);
			}
		}while(categoria!=0);
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_categorias);
		getch();
	}
	fclose(canal);
}

void modificaciones_fichas() {
	FILE *canal,*canal2;
	long N_fichas,N_aux,desplazamiento,cen,der,izq,cod;
	char eleccion,dni[10],aux[2];
	int seleccion=1,sw,sw2,i,h1,h2,m1,m2;

	canal=fopen(FICHERO_fichas,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_fichas, sizeof(registro0_fichas),1,canal);
 	N_fichas=registro0_fichas.num_registros;

	if(N_fichas>=1) {
		do{
			clrscr();
			printf("Introduce Codigo de Ficha a Modificar ('0'=Salir) => ");
			scanf("%ld",&cod);fflush(stdin);clrscr();

			if(cod!=0) {
				sw=0;izq=1;der=N_fichas;
				do{
					cen=(izq+der)/2;
					desplazamiento=cen*sizeof(registro_fichas);
					fseek(canal,desplazamiento,0);
					fread(&registro_fichas,sizeof(registro_fichas),1,canal);

					if(cod==registro_fichas.cod_ficha || izq>=der) {
						sw=1;
						if(cod==registro_fichas.cod_ficha)
						{
							gotoxy(1,1);printf("Ficha");
							gotoxy(8,1);printf("DNI");
							gotoxy(20,1);printf("Fecha");
							gotoxy(32,1);printf("H.Inicio");
							gotoxy(48,1);printf("H.Final");
							gotoxy(65,1);printf("Tiempo");
							gotoxy(72,1);printf("Obra");
							gotoxy(3,3);printf("%ld",registro_fichas.cod_ficha);
							gotoxy(8,3);printf("%s",registro_fichas.dni);
							gotoxy(20,3);printf("%s",registro_fichas.fecha);
							gotoxy(32,3);printf("%s",registro_fichas.h_inicio);
							gotoxy(48,3);printf("%s",registro_fichas.h_final);
							gotoxy(66,3);printf("%d",registro_fichas.tiempo);
							gotoxy(73,3);printf("%ld",registro_fichas.cod_obra);

							printf("\n\n¿Desea Modificar el Registro? (s/n): ");
							scanf("%c",&eleccion);fflush(stdin);
							if(eleccion=='s') {
								do{
									clrscr();sw2=0;
									gotoxy(1,1);printf("Ficha");
									gotoxy(8,1);printf("DNI");
									gotoxy(20,1);printf("Fecha");
									gotoxy(32,1);printf("H.Inicio");
									gotoxy(48,1);printf("H.Final");
									gotoxy(65,1);printf("Tiempo");
									gotoxy(72,1);printf("Obra");
									gotoxy(3,3);printf("%ld",registro_fichas.cod_ficha);
									gotoxy(8,3);printf("%s",registro_fichas.dni);
									gotoxy(20,3);printf("%s",registro_fichas.fecha);
									gotoxy(32,3);
									if(strcmp(registro_fichas.h_inicio,"")!=0)
										printf("%s",registro_fichas.h_inicio);
									else
										printf("  *");
									gotoxy(48,3);
									if(strcmp(registro_fichas.h_final,"")!=0)
										printf("%s",registro_fichas.h_final);
									else
										printf("  *");
									gotoxy(66,3);printf("%d",registro_fichas.tiempo);
									gotoxy(73,3);printf("%ld",registro_fichas.cod_obra);

									printf("\n\n1. Modificar DNI\n");
									printf("2. Modificar Fecha\n");
									printf("3. Modificar H.Inicio\n");
									printf("4. Modificar H.Final\n");
									printf("5. Modificar Obra\n");
									printf("0. Volver\n\n");
									printf("Opcion => ");
									scanf("%d",&seleccion);fflush(stdin);
									switch(seleccion) {
										case 1 : {
											do{              							  //nos aseguramos que el tamaño de DNI es correcto
												if(sw2)
													printf("Error. Tamaño incorrecto\n");
												printf("\nInserte nuevo DNI => ");
												gets(dni);
												fflush(stdin);sw2=1;
											}while(strlen(dni)!=9);

											sw2=0;
											canal2=fopen(FICHERO_trabajadores,"rb");
											fseek(canal2,0L,0);
											fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
											N_aux=registro0_trabajadores.num_registros;
											for(i=1;i<=N_aux;i++) {   	  			  //comprobamos si el dni existe secuencialmente
												desplazamiento=i*sizeof(registro_trabajadores);
												fseek(canal2,desplazamiento,0);
												fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);

												if(strcmp(registro_trabajadores.dni,dni)==0) {
													strcpy(registro_fichas.dni,dni);
													printf("\nDNI de Fichas Actualizado");
													getch();sw=2;sw2=1;break;
												}
											}
											if(!sw2) {
												printf("\nError. El DNI no existe");
												getch();
											}
											fclose(canal2);
										}	break;
										case 2 : {
                                    		do{                                	  //nos aseguramos que el tamaño es correcto
												if(sw2)
													printf("Error. Formato incorrecto (dd/mm/aaaa)\n");
												printf("\nInserte nueva Fecha => ");
												gets(registro_fichas.fecha);
												fflush(stdin);sw2=1;
											}while(strlen(registro_trabajadores.f_nacimiento)!=10);
											sw=2;
										}	break;
										case 3 : {
                                    		do{                                	  //nos aseguramos que la hora inicial no excede del maximo
												if(sw2)
													printf("Error. Formato incorrecto (hh:mm)\n");
												printf("\nInserte nueva H.Inicio => ");
												gets(registro_fichas.h_inicio);
												fflush(stdin);sw2=1;
											}while(strlen(registro_fichas.h_inicio)!=5 && strlen(registro_fichas.h_inicio)!=0);
											sw=2;
										}	break;
										case 4 : {
                                    		do{                                	  //nos aseguramos que la hora final no excede del maximo
												if(sw2)
													printf("Error. Formato incorrecto (hh:mm)\n");
												printf("\nInserte nueva H.Final => ");
												gets(registro_fichas.h_final);
												fflush(stdin);sw2=1;
											}while(strlen(registro_fichas.h_final)!=5 && strlen(registro_fichas.h_final)!=0);
											sw=2;
										}	break;
										case 5 : {
											fflush(stdin);
											printf("\nInserte nueva Obra => ");
											scanf("%ld",&cod);

											sw2=0;
											canal2=fopen(FICHERO_obras,"r+b");
											fseek(canal2,0L,0);
											fread(&registro0_obras,sizeof(registro0_obras),1,canal2);
											N_aux=registro0_obras.num_registros;
											for(i=1;i<=N_aux;i++) {  	  			  //comprobamos si existen capataces con el mismo dni para actualizarlo
												desplazamiento=i*sizeof(registro_obras);
												fseek(canal2,desplazamiento,0);
												fread(&registro_obras,sizeof(registro_obras),1,canal2);

												if(registro_obras.cod_obra==cod) {
													registro_fichas.cod_obra=cod;
													sw=2;sw2=1;break;
												}
											}
											if(!sw2) {
												printf("\nError. Codigo de Obra no encontrado");
												getch();
											}
											fclose(canal2);
										}	break;
										case 0 : {
	                           				if(sw>1) {
												if(strlen(registro_fichas.h_inicio)>0 && strlen(registro_fichas.h_final)>0) {
													aux[0]=registro_fichas.h_inicio[0];
													aux[1]=registro_fichas.h_inicio[1];
													aux[2]='\0';          h1=atoi(aux);
													aux[0]=registro_fichas.h_inicio[3];
													aux[1]=registro_fichas.h_inicio[4];
													aux[2]='\0';          m1=atoi(aux);
													aux[0]=registro_fichas.h_final[0];
													aux[1]=registro_fichas.h_final[1];
													aux[2]='\0';   	   h2=atoi(aux);
													aux[0]=registro_fichas.h_final[3];
													aux[1]=registro_fichas.h_final[4];
													aux[2]='\0';         m2=atoi(aux);

													if(h2==0)
														h2=24;

													if(h1>h2)
														registro_fichas.tiempo=(24-h1+h2)*60+(m1-m2);
													else
														if(m1>m2)
															registro_fichas.tiempo=(h2-h1-1)*60+(m1-m2-60);
														else
															registro_fichas.tiempo=(h2-h1-1)*60+(m2-m1+60);
												}
												desplazamiento=cen*sizeof(registro_fichas);
												fseek(canal,desplazamiento,0);
												fwrite(&registro_fichas,sizeof(registro_fichas),1,canal);
												printf("\nRegistro Modificado correctamente");
												printf("\n\nPulse una tecla para continuar..");
												getch();
											}
										}	break;
										default: 	printf("\nElija entre 0 - 5");	getch();
									}
								}while(seleccion!=0);
							}
						} else {
							printf("Codigo de Ficha no encontrado");
							printf("\n\nPulse una tecla para continuar..");
							getch();
						}
					} else {
						if(cod<registro_fichas.cod_ficha)
							der=cen-1;
						else
							izq=cen+1;
					}
				}while(!sw);
			}
		}while(cod!=0);
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_fichas);
		getch();
	}
	fclose(canal);
}

void modificaciones_obras() {
	FILE *canal,*canal2;
	long N_obras,N_aux,desplazamiento,cen,der,izq,cod;
	char eleccion,dni[10];
	int seleccion=1,sw,sw2,i;

	canal=fopen(FICHERO_obras,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_obras, sizeof(registro0_obras),1,canal);
 	N_obras=registro0_obras.num_registros;

	if(N_obras>=1) {
		do{
			clrscr();
			printf("Introduce Codigo de Obra a Modificar ('0'=Salir) => ");
			scanf("%ld",&cod);fflush(stdin);clrscr();

			if(cod!=0) {
				sw=0;izq=1;der=N_obras;
				do{
					cen=(izq+der)/2;
				  	desplazamiento=cen*sizeof(registro_obras);
					fseek(canal,desplazamiento,0);
					fread(&registro_obras,sizeof(registro_obras),1,canal);

					if(cod==registro_obras.cod_obra || izq>=der) {
						sw=1;
						if(cod==registro_obras.cod_obra) {
							gotoxy(1,1);printf("Ficha");
							gotoxy(8,1);printf("F.Inicio");
							gotoxy(21,1);printf("F.Final");
							gotoxy(34,1);printf("Estado");
							gotoxy(54,1);printf("Capataz");
							gotoxy(3,3);printf("%ld",registro_obras.cod_obra);
							gotoxy(8,3);printf("%s",registro_obras.f_inicio);
							gotoxy(21,3);printf("%s",registro_obras.f_final);
							gotoxy(34,3);printf("%s",registro_obras.estado);
							gotoxy(54,3);printf("%s",registro_obras.dni);

							printf("\n\n¿Desea Modificar el Registro? (s/n): ");
							scanf("%c",&eleccion);fflush(stdin);
							if(eleccion=='s') {
								do{
									clrscr();sw2=0;
									gotoxy(1,1);printf("Ficha");
									gotoxy(8,1);printf("F.Inicio");
									gotoxy(21,1);printf("F.Final");
									gotoxy(34,1);printf("Estado");
									gotoxy(54,1);printf("Capataz");
									gotoxy(3,3);printf("%ld",registro_obras.cod_obra);
									gotoxy(8,3);printf("%s",registro_obras.f_inicio);
									gotoxy(21,3);printf("%s",registro_obras.f_final);
									gotoxy(34,3);printf("%s",registro_obras.estado);
									gotoxy(54,3);printf("%s",registro_obras.dni);

									printf("\n\n1. Modificar F.Inicio\n");
									printf("2. Modificar F.Final\n");
									printf("3. Modificar Estado\n");
									printf("4. Modificar Capataz\n");
									printf("0. Volver\n\n");
									printf("Opcion => ");
									scanf("%d",&seleccion);fflush(stdin);
									switch(seleccion) {
										case 1 : {
                                    		do{                                	  //nos aseguramos que el tamaño de la fecha es correcto
												if(sw2)
													printf("Error. Formato incorrecto (dd/mm/aaaa)\n");
												printf("\nInserte nueva F.Inicio => ");
												gets(registro_obras.f_inicio);
												fflush(stdin);sw2=1;
											}while(strlen(registro_obras.f_inicio)!=10);
											sw=2;
										}	break;
										case 2 : {
                                    		do{                                	  //nos aseguramos que el tamaño de la fecha es correcto
												if(sw2)
													printf("Error. Formato incorrecto (dd/mm/aaaa)\n");
												printf("\nInserte nueva F.Final => ");
												gets(registro_obras.f_final);
												fflush(stdin);sw2=1;
											}while(strlen(registro_obras.f_final)!=10);
											sw=2;
										}	break;
										case 3 : {
											fflush(stdin);
											printf("\nInserte nuevo Estado => ");
											gets(registro_obras.estado);
		                                    sw=2;
										}	break;
										case 4 : {
											do{              							  //nos aseguramos que el tamaño de DNI es correcto
												if(sw2)
													printf("Error. Tamaño incorrecto\n");
												printf("\nInserte nuevo Capataz => ");
												gets(dni);
												fflush(stdin);sw2=1;
											}while(strlen(dni)!=9);

											sw2=0;
											canal2=fopen(FICHERO_trabajadores,"rb");
											fseek(canal2,0L,0);
											fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
											N_aux=registro0_trabajadores.num_registros;

											for(i=1;i<=N_aux;i++) {  				  //comprobamos si el dni existe secuencialmente
												desplazamiento=i*sizeof(registro_trabajadores);
												fseek(canal2,desplazamiento,0);
												fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);
								 
												if(strcmp(registro_trabajadores.dni,dni)==0) {
													strcpy(registro_obras.dni,dni);
													sw2=1;sw=2;break;
												}
											}
											if(!sw2) {
												printf("\nDNI de Capataz no encontrado");
												getch();
											}
											fclose(canal2);
										}	break;
										case 0 : {
	                           				if(sw>1) {
												desplazamiento=cen*sizeof(registro_obras);
												fseek(canal,desplazamiento,0);
												fwrite(&registro_obras,sizeof(registro_obras),1,canal);
												printf("\nRegistro Modificado correctamente");
												printf("\n\nPulse una tecla para continuar..");
												getch();
	                                       }
										}	break;
										default: 	printf("\nElija entre 0 - 4");	getch();
									}
								}while(seleccion!=0);
							}
						} else {
							printf("Codigo de Obra no encontrado");
							printf("\n\nPulse una tecla para continuar..");
							getch();
						}
					} else {
						if(cod<registro_obras.cod_obra)
							der=cen-1;
						else
							izq=cen+1;
					}
				}while(!sw);
			}
		}while(cod!=0);
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_obras);
		getch();
	}
	fclose(canal);
}

void bajas_trabajadores() {
	FILE *canal,*canal2;
	long N_trabajadores,N_aux,desplazamiento,cen,der,izq;
	char dni[10],eleccion;
	int sw,sw2,i;

	canal=fopen(FICHERO_trabajadores,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_trabajadores, sizeof(registro0_trabajadores),1,canal);
 	N_trabajadores=registro0_trabajadores.num_registros;

	if(N_trabajadores>=1) {
		do{
			clrscr();
			canal=fopen(FICHERO_trabajadores,"r+b");
			printf("Introduce el DNI del Trabajador a dar de Baja (Salir='Fin') => ");
			gets(dni);fflush(stdin);clrscr();

			if(strncmp(dni,"Fin",strlen(dni))!=0) {
				sw=0;izq=1;der=N_trabajadores;
				do{
					cen=(izq+der)/2;
				  	desplazamiento=cen*sizeof(registro_trabajadores);
					fseek(canal,desplazamiento,0);
					fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

					if(strncmp(dni,registro_trabajadores.dni,strlen(dni))==0 || izq>=der) {
						sw=1;
						if(strncmp(dni,registro_trabajadores.dni,strlen(dni))==0) {
							gotoxy(1,1);printf("Ficha");
							gotoxy(8,1);printf("DNI");
							gotoxy(20,1);printf("Nombre");
							gotoxy(42,1);printf("F.Nacim.");
							gotoxy(55,1);printf("Telefono");
							gotoxy(67,1);printf("Categoria");
							gotoxy(3,3);printf("%ld",cen);
							gotoxy(8,3);printf("%s",registro_trabajadores.dni);
							gotoxy(20,3);printf("%s",registro_trabajadores.nombre);
							gotoxy(42,3);printf("%s",registro_trabajadores.f_nacimiento);
							gotoxy(55,3);printf("%s",registro_trabajadores.telefono);
							gotoxy(70,3);printf("%ld",registro_trabajadores.cod_categoria);

							printf("\n\n¿Desea dar de Baja el Registro? (s/n): ");
							scanf("%c",&eleccion);fflush(stdin);
							if(eleccion=='s') {
								sw2=0;
								canal2=fopen(FICHERO_fichas,"rb");
								fseek(canal2,0L,0);
								fread(&registro0_fichas,sizeof(registro0_fichas),1,canal2);
								N_aux=registro0_fichas.num_registros;

								for(i=1;i<=N_aux;i++) {  				  						  //comprobamos si el trabajador tiene fichas asociadas
									desplazamiento=i*sizeof(registro_fichas);
									fseek(canal2,desplazamiento,0);
									fread(&registro_fichas,sizeof(registro_fichas),1,canal2);

									if(strcmp(registro_fichas.dni,registro_trabajadores.dni)==0) {
										printf("\nError. DNI existente en Fichero Fichas");
										getch();sw2=1;break;
									}
								}
								fclose(canal2);

								if(sw2)
									break;

								sw2=0;
								canal2=fopen(FICHERO_obras,"rb");
								fseek(canal2,0L,0);
								fread(&registro0_obras,sizeof(registro0_obras),1,canal2);
								N_aux=registro0_obras.num_registros;

								for(i=1;i<=N_aux;i++) {  				  						  //comprobamos si el trabajador es capataz de obra
									desplazamiento=i*sizeof(registro_obras);
									fseek(canal2,desplazamiento,0);
									fread(&registro_obras,sizeof(registro_obras),1,canal2);

									if(strcmp(registro_obras.dni,registro_trabajadores.dni)==0) {
										printf("\nError. DNI existente en Fichero Obras");
										getch();sw2=1;break;
									}
								}
								fclose(canal2);

								if(sw2)
									break;

								desplazamiento=N_trabajadores*sizeof(registro_trabajadores);
								fseek(canal,desplazamiento,0);
								fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

								desplazamiento=cen*sizeof(registro_trabajadores);
								fseek(canal,desplazamiento,0);
								fwrite(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

								N_trabajadores--;
								fseek(canal,0L,0);
								registro0_trabajadores.num_registros=N_trabajadores;
								for(i=0;i<sizeof(registro_trabajadores)-4;i++)
									registro0_trabajadores.blancos[i]=' ';
								fwrite(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal);
								fclose(canal);

								printf("\nRegistro dado de Baja correctamente");
								printf("\n\nPulse una tecla para continuar..");getch();

								if(N_trabajadores>1)           								  //si eliminamos trabajador y existe mas de uno realizamos ordenacion
									ordenacion_trabajadores();
							}
						} else {
							printf("DNI de Trabajador no encontrado");
							printf("\n\nPulse una tecla para continuar..");
							getch();
						}
					} else {
						if(strncmp(dni,registro_trabajadores.dni,strlen(dni))<0)
							der=cen-1;
						else
							izq=cen+1;
					}
				}while(!sw);
			}
		}while(strncmp(dni,"Fin",strlen(dni))!=0);
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_trabajadores);
		getch();
	}
	fclose(canal);
}

void bajas_categorias() {
	FILE *canal,*canal2;
	long N_categorias,N_aux,desplazamiento,cen,der,izq,categoria,i;
	char eleccion;
	int sw,sw2;

	canal=fopen(FICHERO_categorias,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_categorias, sizeof(registro0_categorias),1,canal);
 	N_categorias=registro0_categorias.num_registros;

	if(N_categorias>=1) {
		do{
			clrscr();
			canal=fopen(FICHERO_categorias,"r+b");
			printf("Introduce Codigo de Categoria a dar de Baja (Salir='0') => ");
			scanf("%ld",&categoria);fflush(stdin);clrscr();

			if(categoria!=0) {
				sw=0;izq=1;der=N_categorias;
				do{         
					cen=(izq+der)/2;
				  	desplazamiento=cen*sizeof(registro_categorias);
					fseek(canal,desplazamiento,0);
					fread(&registro_categorias,sizeof(registro_categorias),1,canal);

					if(categoria==registro_categorias.cod_categoria || izq>=der) {
					sw=1;
						if(categoria==registro_categorias.cod_categoria) {
							gotoxy(1,1);printf("Ficha");
							gotoxy(8,1);printf("Nombre");
							gotoxy(30,1);printf("Precio/Hora");
							gotoxy(3,3);printf("%ld",registro_categorias.cod_categoria);
							gotoxy(8,3);printf("%s",registro_categorias.nombre);
							gotoxy(30,3);printf("%.2f",registro_categorias.precio_hora);

							printf("\n\n¿Desea dar de Baja el Registro? (s/n): ");
							scanf("%c",&eleccion);fflush(stdin);
							if(eleccion=='s') {
								sw2=0;
								canal2=fopen(FICHERO_trabajadores,"rb");
								fseek(canal2,0L,0);
								fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
								N_aux=registro0_trabajadores.num_registros;

								for(i=1;i<=N_aux;i++) {  				  						  //comprobamos si la categoria existe en fichero trabajadores
									desplazamiento=i*sizeof(registro_trabajadores);
									fseek(canal2,desplazamiento,0);
									fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);

									if(registro_trabajadores.cod_categoria==categoria) {
										printf("\nError. Categoria existente en Fichero Trabajadores");
										getch();sw2=1;break;
									}
								}
								fclose(canal2);
                        
								if(!sw2) {
									desplazamiento=N_categorias*sizeof(registro_categorias);
									fseek(canal,desplazamiento,0);
									fread(&registro_categorias,sizeof(registro_categorias),1,canal);

									desplazamiento=cen*sizeof(registro_categorias);
									fseek(canal,desplazamiento,0);
									fwrite(&registro_categorias,sizeof(registro_categorias),1,canal);

									N_categorias--;
									fseek(canal,0L,0);
									registro0_categorias.num_registros=N_categorias;
									for(i=0;i<sizeof(registro_categorias)-4;i++)
										registro0_categorias.blancos[i]=' ';
									fwrite(&registro0_categorias,sizeof(registro0_categorias),1,canal);

									for(i=cen;i<=N_categorias;i++) {   	  					  //reducimos en 1 codigos de Categorias
										desplazamiento=i*sizeof(registro_categorias);
										fseek(canal,desplazamiento,0);
										fread(&registro_categorias,sizeof(registro_categorias),1,canal);
										registro_categorias.cod_categoria--;
										desplazamiento=i*sizeof(registro_categorias);
										fseek(canal,desplazamiento,0);
										fwrite(&registro_categorias,sizeof(registro_categorias),1,canal);
									}
									fclose(canal);

									canal2=fopen(FICHERO_trabajadores,"r+b");
									fseek(canal2,0L,0);
									fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal2);
									N_aux=registro0_trabajadores.num_registros;

									for(i=1;i<=N_aux;i++) {    	  						  	  	  //reducimos en 1 categorias en Trabajadores (registros asociados)
										desplazamiento=i*sizeof(registro_trabajadores);
										fseek(canal2,desplazamiento,0);
										fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);

										if(registro_trabajadores.cod_categoria>=cen) {
											registro_trabajadores.cod_categoria--;
											desplazamiento=i*sizeof(registro_trabajadores);
											fseek(canal2,desplazamiento,0);
											fwrite(&registro_trabajadores,sizeof(registro_trabajadores),1,canal2);
										}		
									}
									fclose(canal2);
									printf("\nRegistro dado de Baja correctamente");
									printf("\n\nPulse una tecla para continuar..");getch();
							   
									if(N_categorias>1)      					    			  //si eliminamos categoria y existe mas de una realizamos ordenacion
										ordenacion_categorias();
								}
							}
						} else {
							printf("Categoria no encontrada");
							printf("\n\nPulse una tecla para continuar..");
							getch();
						}
					} else {
						if(categoria<registro_categorias.cod_categoria)
							der=cen-1;
						else
							izq=cen+1;
					}
				}while(!sw);
			}
		}while(categoria!=0);
	} else {
	  	clrscr();
	  	printf("El fichero '%s' esta vacio",FICHERO_categorias);
		getch();
	}
	fclose(canal);
}

void bajas_fichas() {
	FILE *canal,*canal2;
	long N_fichas,desplazamiento,cen,der,izq,ficha,i;
	char eleccion;
	int sw;

	canal=fopen(FICHERO_fichas,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_fichas,sizeof(registro0_fichas),1,canal);
 	N_fichas=registro0_fichas.num_registros;

	if(N_fichas>=1) {
		do{
			clrscr();
			printf("Introduce Codigo de Ficha a dar de Baja (Salir='0') => ");
			scanf("%ld",&ficha);fflush(stdin);clrscr();

			if(ficha!=0) {
				sw=0;izq=1;der=N_fichas;
				do{              				
					cen=(izq+der)/2;                                                     
				  	desplazamiento=cen*sizeof(registro_fichas);
					fseek(canal,desplazamiento,0);
					fread(&registro_fichas,sizeof(registro_fichas),1,canal);

					if(ficha==registro_fichas.cod_ficha || izq>=der) {
						sw=1;
						if(ficha==registro_fichas.cod_ficha) {
							gotoxy(1,1);printf("Ficha");
							gotoxy(8,1);printf("DNI");
							gotoxy(20,1);printf("Fecha");
							gotoxy(32,1);printf("H.Inicio");
							gotoxy(44,1);printf("H.Final");
							gotoxy(56,1);printf("Obra");
							gotoxy(3,3);printf("%ld",registro_fichas.cod_ficha);
							gotoxy(8,3);printf("%s",registro_fichas.dni);
							gotoxy(20,3);printf("%s",registro_fichas.fecha);
							gotoxy(32,3);
							if(strcmp(registro_fichas.h_inicio,"")!=0)
								printf("%s",registro_fichas.h_inicio);
							else
								printf("  *");
							gotoxy(48,3);
							if(strcmp(registro_fichas.h_final,"")!=0)
								printf("%s",registro_fichas.h_final);
							else
								printf("  *");
							gotoxy(66,3);printf("%d",registro_fichas.tiempo);
							gotoxy(57,3);printf("%ld",registro_fichas.cod_obra);

							printf("\n\n¿Desea dar de Baja el Registro? (s/n): ");
							scanf("%c",&eleccion);fflush(stdin);
							if(eleccion=='s') {
								desplazamiento=N_fichas*sizeof(registro_fichas);
								fseek(canal,desplazamiento,0);
								fread(&registro_fichas,sizeof(registro_fichas),1,canal);

								desplazamiento=cen*sizeof(registro_fichas);
								fseek(canal,desplazamiento,0);
								fwrite(&registro_fichas,sizeof(registro_fichas),1,canal);

								N_fichas--;
								fseek(canal,0L,0);
								registro0_fichas.num_registros=N_fichas;
								for(i=0;i<sizeof(registro_fichas)-4;i++)
									registro0_fichas.blancos[i]=' ';
								fwrite(&registro0_fichas,sizeof(registro0_fichas),1,canal);

								canal2=fopen(FICHERO_fichas,"r+b");
								for(i=cen;i<=N_fichas;i++)  {   	  						  	  //reducimos en 1 codigos de Obras
									desplazamiento=i*sizeof(registro_fichas);
									fseek(canal2,desplazamiento,0);
									fread(&registro_fichas,sizeof(registro_fichas),1,canal2);
									registro_fichas.cod_ficha--;
									desplazamiento=i*sizeof(registro_fichas);
									fseek(canal2,desplazamiento,0);
									fwrite(&registro_fichas,sizeof(registro_fichas),1,canal2);
								}
								fclose(canal2);
								printf("\nRegistro dado de Baja correctamente");
								printf("\n\nPulse una tecla para continuar..");getch();
                        
								if(N_fichas>1)      												  //si eliminamos ficha y existe mas de una realizamos ordenacion
									ordenacion_fichas();
							}
						} else {
							printf("Codigo de Ficha no encontrado");
							printf("\n\nPulse una tecla para continuar..");
							getch();
						}
					} else {
						if(ficha<registro_fichas.cod_ficha)
							der=cen-1;
						else
							izq=cen+1;
					}
				}while(!sw);
			}
		}while(ficha!=0);
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_fichas);
		getch();
	}
	fclose(canal);
}

void bajas_obras() {
	FILE *canal,*canal2;
	long N_obras,N_aux,desplazamiento,cen,der,izq,obra,i;
	char eleccion;
	int sw,sw2;

	canal=fopen(FICHERO_obras,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_obras,sizeof(registro0_obras),1,canal);
 	N_obras=registro0_obras.num_registros;

	if(N_obras>=1) {
	   do{
			clrscr();
			canal=fopen(FICHERO_obras,"r+b");
			printf("Introduce Codigo de Obra a dar de Baja (Salir='0') => ");
			scanf("%ld",&obra);fflush(stdin);clrscr();

			if(obra!=0) {
				sw=0;izq=1;der=N_obras;
				do{
					cen=(izq+der)/2;
				  	desplazamiento=cen*sizeof(registro_obras);
					fseek(canal,desplazamiento,0);
					fread(&registro_obras,sizeof(registro_obras),1,canal);

					if(obra==registro_obras.cod_obra || izq>=der) {
						sw=1;
						if(obra==registro_obras.cod_obra) {
							gotoxy(1,1);printf("Ficha");
							gotoxy(8,1);printf("F.Inicio");
							gotoxy(21,1);printf("F.Final");
							gotoxy(34,1);printf("Estado");
							gotoxy(54,1);printf("Capataz");
							gotoxy(3,3);printf("%ld",registro_obras.cod_obra);
							gotoxy(8,3);printf("%s",registro_obras.f_inicio);
							gotoxy(21,3);printf("%s",registro_obras.f_final);
							gotoxy(34,3);printf("%s",registro_obras.estado);
							gotoxy(55,3);printf("%s",registro_obras.dni);

							printf("\n\n¿Desea dar de Baja el Registro? (s/n): ");
							scanf("%c",&eleccion);fflush(stdin);
							if(eleccion=='s') {
								sw2=0;
								canal2=fopen(FICHERO_fichas,"rb");
								fseek(canal2,0L,0);
								fread(&registro0_fichas,sizeof(registro0_fichas),1,canal2);
								N_aux=registro0_fichas.num_registros;

								for(i=1;i<=N_aux;i++) {  				  						  //comprobamos si la categoria existe en fichero trabajadores
									desplazamiento=i*sizeof(registro_fichas);
									fseek(canal2,desplazamiento,0);
									fread(&registro_fichas,sizeof(registro_fichas),1,canal2);

									if(registro_fichas.cod_obra==obra) {
										printf("\nError. Obra existente en Fichero Fichas");
										getch();sw2=1;break;
									}
								}
								fclose(canal2);
                        
								if(!sw2) {
									desplazamiento=N_obras*sizeof(registro_obras);
									fseek(canal,desplazamiento,0);
									fread(&registro_obras,sizeof(registro_obras),1,canal);

									desplazamiento=cen*sizeof(registro_obras);
									fseek(canal,desplazamiento,0);
									fwrite(&registro_obras,sizeof(registro_obras),1,canal);

									N_obras--;
									fseek(canal,0L,0);
									registro0_obras.num_registros=N_obras;
									for(i=0;i<sizeof(registro_obras)-4;i++)
										registro0_obras.blancos[i]=' ';
									fwrite(&registro0_obras,sizeof(registro0_obras),1,canal);

									for(i=cen;i<=N_obras;i++) {    	  						  	  //reducimos en 1 codigos de Obras
										desplazamiento=i*sizeof(registro_obras);
										fseek(canal,desplazamiento,0);
										fread(&registro_obras,sizeof(registro_obras),1,canal);
										registro_obras.cod_obra--;
										desplazamiento=i*sizeof(registro_obras);
										fseek(canal,desplazamiento,0);
										fwrite(&registro_obras,sizeof(registro_obras),1,canal);
									}
									fclose(canal);
                           
									canal2=fopen(FICHERO_fichas,"r+b");
									fseek(canal2,0L,0);
									fread(&registro0_fichas,sizeof(registro0_fichas),1,canal2);
									N_aux=registro0_fichas.num_registros;

									for(i=1;i<=N_aux;i++) {   	  						  	  	  //reducimos en 1 obras en Fichas (registros asociados)
										desplazamiento=i*sizeof(registro_fichas);
										fseek(canal2,desplazamiento,0);
										fread(&registro_fichas,sizeof(registro_fichas),1,canal2);

										if(registro_fichas.cod_obra>=cen) {
											registro_fichas.cod_obra--;
											desplazamiento=i*sizeof(registro_fichas);
											fseek(canal2,desplazamiento,0);
											fwrite(&registro_fichas,sizeof(registro_fichas),1,canal2);
										}
									}
									fclose(canal2);
									printf("\nRegistro dado de Baja correctamente");
									printf("\n\nPulse una tecla para continuar..");getch();

									if(N_obras>1)   							  		  			  //si eliminamos obra y existe mas de una realizamos ordenacion
										ordenacion_obras();
								}
							}
						} else {
							printf("Codigo de Obra no encontrado");
							printf("\n\nPulse una tecla para continuar..");
							getch();
						}
					} else {
						if(obra<registro_obras.cod_obra)
							der=cen-1;
						else
							izq=cen+1;
					}
				}while(!sw);
			}
		}while(obra!=0);
	} else {
		clrscr();
		printf("El fichero '%s' esta vacio",FICHERO_obras);
		getch();
	}
	fclose(canal);
}

void ordenacion_trabajadores() {                         								  //metodo shell de ordenacion
	FILE *canal;
	tipo_trabajadores registro2;
	long N,desplazamiento,i,d;
	int sw;

	canal=fopen(FICHERO_trabajadores,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal);
	N=registro0_trabajadores.num_registros;

	d=N;
	while(d!=1) {
		d=d/2;
	 	sw=1;
		while(sw) {
			sw=0;
			for(i=1;i<=N-d;i++) {
				desplazamiento=i*sizeof(registro_trabajadores);
				fseek(canal,desplazamiento,0);
				fread(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);

				desplazamiento=(i+d)*sizeof(registro2);
				fseek(canal,desplazamiento,0);
				fread(&registro2,sizeof(registro2),1,canal);

				if(strcmp(registro2.dni,registro_trabajadores.dni)<0) {
					desplazamiento=i*sizeof(registro2);
					fseek(canal,desplazamiento,0);
					fwrite(&registro2,sizeof(registro2),1,canal);

					desplazamiento=(i+d)*sizeof(registro_trabajadores);
					fseek(canal,desplazamiento,0);
					fwrite(&registro_trabajadores,sizeof(registro_trabajadores),1,canal);
					sw=1;
			  	}
			}
	 	}
	}
   fclose(canal);
}

void ordenacion_categorias() {                        									  //metodo shell de ordenacion
	FILE *canal;
	tipo_categorias registro2;
	long N,desplazamiento,i,d;
	int sw;

	canal=fopen(FICHERO_categorias,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_categorias,sizeof(registro0_categorias),1,canal);
	N=registro0_categorias.num_registros;

	d=N;
	while(d!=1) {
		d=d/2;
	 	sw=1;
		while(sw) {
			sw=0;
			for(i=1;i<=N-d;i++) {
				desplazamiento=i*sizeof(registro_categorias);
				fseek(canal,desplazamiento,0);
				fread(&registro_categorias,sizeof(registro_categorias),1,canal);

				desplazamiento=(i+d)*sizeof(registro2);
				fseek(canal,desplazamiento,0);
				fread(&registro2,sizeof(registro2),1,canal);

				if(registro2.cod_categoria<registro_categorias.cod_categoria) {
					desplazamiento=i*sizeof(registro2);
					fseek(canal,desplazamiento,0);
					fwrite(&registro2,sizeof(registro2),1,canal);

					desplazamiento=(i+d)*sizeof(registro_categorias);
					fseek(canal,desplazamiento,0);
					fwrite(&registro_categorias,sizeof(registro_categorias),1,canal);
					sw=1;
			  	}
			}
	 	}
	}
   fclose(canal);
}

void ordenacion_fichas() {                         										  //metodo shell de ordenacion
	FILE *canal;
	tipo_fichas registro2;
	long N,desplazamiento,i,d;
	int sw;

	canal=fopen(FICHERO_fichas,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_fichas,sizeof(registro0_fichas),1,canal);
	N=registro0_fichas.num_registros;

	d=N;
	while(d!=1) {
		d=d/2;
	 	sw=1;
		while(sw) {
			sw=0;
			for(i=1;i<=N-d;i++) {
				desplazamiento=i*sizeof(registro_fichas);
				fseek(canal,desplazamiento,0);
				fread(&registro_fichas,sizeof(registro_fichas),1,canal);

				desplazamiento=(i+d)*sizeof(registro2);
				fseek(canal,desplazamiento,0);
				fread(&registro2,sizeof(registro2),1,canal);

				if(registro2.cod_ficha<registro_fichas.cod_ficha) {
					desplazamiento=i*sizeof(registro2);
					fseek(canal,desplazamiento,0);
					fwrite(&registro2,sizeof(registro2),1,canal);
               
					desplazamiento=(i+d)*sizeof(registro_fichas);
					fseek(canal,desplazamiento,0);
					fwrite(&registro_fichas,sizeof(registro_fichas),1,canal);
					sw=1;
			  	}
			}
	 	}
	}
   fclose(canal);
}

void ordenacion_obras() {                         										  //metodo shell de ordenacion
	FILE *canal;
	tipo_obras registro2;
	long N,desplazamiento,i,d;
	int sw;

	canal=fopen(FICHERO_obras,"r+b");
	fseek(canal,0L,0);
	fread(&registro0_obras,sizeof(registro0_obras),1,canal);
	N=registro0_obras.num_registros;

	d=N;
	while(d!=1) {
		d=d/2;
	 	sw=1;
		while(sw) {
			sw=0;
			for(i=1;i<=N-d;i++) {
				desplazamiento=i*sizeof(registro_obras);
				fseek(canal,desplazamiento,0);
				fread(&registro_obras,sizeof(registro_obras),1,canal);

				desplazamiento=(i+d)*sizeof(registro2);
				fseek(canal,desplazamiento,0);
				fread(&registro2,sizeof(registro2),1,canal);

				if(registro2.cod_obra<registro_obras.cod_obra) {
					desplazamiento=i*sizeof(registro2);
					fseek(canal,desplazamiento,0);
					fwrite(&registro2,sizeof(registro2),1,canal);

					desplazamiento=(i+d)*sizeof(registro_obras);
					fseek(canal,desplazamiento,0);
					fwrite(&registro_obras,sizeof(registro_obras),1,canal);
					sw=1;
			  	}
			}
	 	}
	}
   fclose(canal);
}

void creacion_ficheros() {
	int i;
	FILE *canal;                

	canal=fopen(FICHERO_trabajadores,"rb");
	if(canal==NULL) {
		printf("No existe el fichero '%s', por lo que se creara uno nuevo..\n",FICHERO_trabajadores);
		fclose(canal);
		canal=fopen(FICHERO_trabajadores,"a+b");
		fseek(canal,0L,0);
		registro0_trabajadores.num_registros=0L;
		for(i=0;i<sizeof(registro_trabajadores)-4;i++)
			registro0_trabajadores.blancos[i]=' ';
		fwrite(&registro0_trabajadores,sizeof(registro0_trabajadores),1,canal);getch();
	}
	fclose(canal);

	canal=fopen(FICHERO_categorias,"rb");
	if(canal==NULL) {
		printf("No existe el fichero '%s', por lo que se creara uno nuevo..\n",FICHERO_categorias);
		fclose(canal);
		canal=fopen(FICHERO_categorias,"a+b");
		fseek(canal,0L,0);
		registro0_categorias.num_registros=0L;
		for(i=0;i<sizeof(registro_categorias)-4;i++)
			registro0_categorias.blancos[i]=' ';
		fwrite(&registro0_categorias,sizeof(registro0_categorias),1,canal);getch();
	}
	fclose(canal);

	canal=fopen(FICHERO_fichas,"rb");
	if(canal==NULL) {
		printf("No existe el fichero '%s', por lo que se creara uno nuevo..\n",FICHERO_fichas);
		fclose(canal);
		canal=fopen(FICHERO_fichas,"a+b");
		fseek(canal,0L,0);
		registro0_fichas.num_registros=0L;
		for(i=0;i<sizeof(registro_fichas)-4;i++)
			registro0_fichas.blancos[i]=' ';
		fwrite(&registro0_fichas,sizeof(registro0_fichas),1,canal);getch();
	}
	fclose(canal);

	canal=fopen(FICHERO_obras,"rb");
	if(canal==NULL) {
		printf("No existe el fichero '%s', por lo que se creara uno nuevo..\n",FICHERO_obras);
		fclose(canal);
		canal=fopen(FICHERO_obras,"a+b");
		fseek(canal,0L,0);
		registro0_obras.num_registros=0L;
		for(i=0;i<sizeof(registro_obras)-4;i++)
			registro0_obras.blancos[i]=' ';
		fwrite(&registro0_obras,sizeof(registro0_obras),1,canal);getch();
	}
	fclose(canal);
}
