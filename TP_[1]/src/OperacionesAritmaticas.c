/*
 * OperacionesAritmaticas.c
 *
 *  Created on: 23 sep. 2021
 *      Author: luclopez
 */

#include <stdio.h>
#include <stdlib.h>



int sumarFloat(float* pResultado, float num1, float num2){

	int retorno = 1;

		if(pResultado != NULL){
			*pResultado = num1 + num2;
			retorno = 0;

		}

	return retorno;
}


int restarFloat(float* pResultado, float num1, float num2){

	int retorno = 1;

		if(pResultado != NULL){
			*pResultado = num1 - num2;
			retorno = 0;

		}

	return retorno;
}



int multiplicarFloat(float* pResultado, float num1, float num2){

	int retorno = 1;

		if(pResultado != NULL){
			 *pResultado = num1 * num2;
			retorno = 0;
			}

		if(*pResultado == -0){
			*pResultado = 0;
		}

	return retorno;
}




int dividirFloat(float* pResultado, float num1, float num2){

	int retorno = 1;

		if(pResultado != NULL && num2 != 0){
			*pResultado = num1 / num2;
			retorno = 0;
			}

		if(*pResultado == -0){
			*pResultado = 0;
			}

	return retorno;
}


int factorizar(int num){

    int fact = 0;

		if (num >= 0 && num < 13) {
			fact = 1;
			for(int i = 2; i <= num; i++){
				fact = fact*i;
			}
		}

    return fact;
}

