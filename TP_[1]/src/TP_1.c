/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Lucia Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Pr?ctico 1 - Programacion 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "EntradaDatos.h"
#include "OperacionesAritmeticas.h"



int main(void) {

		setbuf(stdout,NULL);

		char seguir = 's';
	    int flag = 0;
	    float pPrimerOperando;
	    float pSegundoOperando;
	    int retornoPrimerOperando;
	    int retornoSegundoOperando;
	    float pSuma;
	    float pResta;
	    float pMulticacion;
	    float pDivision;
	    int retornoDivision;
	    int pFactorial1;
	    int pFactorial2;
	    int pEntero;


	    do{

	        switch(mostrarMenu(retornoPrimerOperando, retornoSegundoOperando,pPrimerOperando, pSegundoOperando)){

	            case 1:

	                retornoPrimerOperando = obtenerNumeroFloat(&pPrimerOperando, "Ingrese un numero: ", "Error.", 3);

	                break;

	            case 2:

	                retornoSegundoOperando = obtenerNumeroFloat(&pSegundoOperando, "Ingrese un numero: ", "Error.", 3);

	                break;

	            case 3:

	                if(retornoPrimerOperando == 1 && retornoSegundoOperando == 1){

	                    sumarFloat(&pSuma, pPrimerOperando,pSegundoOperando);

	                    restarFloat(&pResta, pPrimerOperando,pSegundoOperando);

	                    multiplicarFloat(&pMulticacion, pPrimerOperando,pSegundoOperando);

	                    retornoDivision = dividirFloat(&pDivision, pPrimerOperando,pSegundoOperando);

						if (determinarEntero(&pEntero, pPrimerOperando) ==0){

						pFactorial1 = factorizar(pEntero);

						} else {

							pFactorial1 = 0;}

						if (determinarEntero(&pEntero, pSegundoOperando) ==0){

						pFactorial2 = factorizar(pEntero);

						}
						else {
							pFactorial2 = 0;}

						flag = 1;

	                    }
	                else {

	                    printf("Para calcular las operaciones es necesario ingresar ambos operandos\n");

	                }

	                break;

	            case 4:

	                if(flag == 1){

	                    printf("a) El resultado de A = %.2f + B = %.2f es: %.2f\n", pPrimerOperando, pSegundoOperando, pSuma);

	                    printf("b) El resultado de A = %.2f - B = %.2f es: %.2f\n", pPrimerOperando, pSegundoOperando, pResta);

	                    if(retornoDivision == 0){

	                    printf("c) El resultado de A = %.2f / B = %.2f es: %.2f\n", pPrimerOperando, pSegundoOperando, pDivision);

	                    } else{

							printf("c) El resultado de A = %.2f / B = %.2f no se pudo calcular\n", pPrimerOperando, pSegundoOperando);

						}

	                    printf("d) El resultado de A = %.2f * B = %.2f es: %.2f\n", pPrimerOperando, pSegundoOperando, pMulticacion);

	                    if (pFactorial1 != 0 && pFactorial2 != 0){

	                    printf("e) El factorial de A = %.2f  es: %d y el factorial de B = %.2f  es: %d\n", pPrimerOperando, pFactorial1, pSegundoOperando, pFactorial2);

	                    } else if (pFactorial1 == 0 && pFactorial2 != 0){

	                    	printf("e) El factorial de A = %.2f no se pudo calcular y el factorial de B = %.2f  es: %d\n", pPrimerOperando, pSegundoOperando, pFactorial2);

	                    	} else {
	                                    if(pFactorial1 != 0 && pFactorial2 == 0){

	                                    	printf("e) El factorial de A = %.2f es: %d y el factorial de B = %.2f no se pudo calcular\n", pPrimerOperando, pFactorial1, pSegundoOperando);
	                                    }
	                                    else{

	                                        printf("e) El factorial de A = %.2f y de B = %.2f no se pudieron calcular\n", pPrimerOperando, pSegundoOperando);
	                                    }
	                            }

	                    flag = 0;}


	                else{

	                    printf("Para informar los resultados, se deben ingresar ambos operandos y calcular las operaciones\n");

	                	}
	                break;

	            case 5:

	                seguir = 'n';

	                printf("?Quiere cancelar la salida?\n");

	                fflush(stdin);

	                scanf("%c", &seguir);

	                break;

	            default:

	                printf("Opcion invalida \n");

	        }

	        system("pause");

	    }while(seguir == 's');


	return EXIT_SUCCESS;
}






