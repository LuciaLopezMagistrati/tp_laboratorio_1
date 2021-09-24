/*
 * EntradaDatos.c
 *
 *  Created on: 23 sep. 2021
 *      Author: luclopez
 */

#include <stdio.h>
#include <stdlib.h>


int obtenerNumeroFloat( float* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	float num;
	int resultadoScanf;


		do
		{
			printf("%s", mensaje);
			resultadoScanf = scanf( "%f" ,&num);
			fflush(stdin);

			if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && resultadoScanf == 1)
			{
				* pResultado = num;
				retorno = 1;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
				reintentos--;
			}

		} while(reintentos>=1);

		return retorno;

}


int mostrarMenu(int retornoPrimerOperando, int retornoSegundoOperando, float primerOperando, float segundoOperando) {

    int opcion;

    system("cls");
    printf("Menu de opciones\n\n");
    printf("1. Ingresar primer operando\n");
    printf("2. Ingresar segundo operando\n");
    printf("3. Calcular todas las operaciones\n");
    printf("4. Informar resultados\n");
    printf("5. Salir\n\n");

    if(retornoPrimerOperando == 1){

        printf("El primer operando ingresado (A) es %.2f\n", primerOperando);

    }

    if(retornoSegundoOperando == 1){

        printf("El segundo operando ingresado (B) es %.2f\n", segundoOperando);

    }

    printf("\nIndique opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}


int determinarEntero(int* pEntero, float numFloat){
    int retorno = 1;
    int numAEntero;

		numAEntero = numFloat;

		if (numFloat - numAEntero == 0){

			*pEntero = numAEntero;
			retorno = 0;

		}

    return retorno;
}
