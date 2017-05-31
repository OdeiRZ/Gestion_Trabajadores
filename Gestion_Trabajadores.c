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
