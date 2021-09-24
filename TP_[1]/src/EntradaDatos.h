/*
 * EntradaDatos.h
 *
 *  Created on: 23 sep. 2021
 *      Author: luclopez
 */

#ifndef ENTRADADATOS_H_
#define ENTRADADATOS_H_




/// \fn int obtenerNumeroFloat(float*, char*, char*, int)
/// \brief Permite ingresar un numero flotante y lo retorna
/// \param pResultado : Graba el resultado, es decir, el numero ingresado (tipo float)
/// \param mensaje : El mensaje a mostrar para solicitar el ingreso del numero
/// \param mensajeError : El mensaje de error a mostrar en caso de ingresar un valor no numerico
/// \param reintentos : La cantidad de veces que se permitirá reintentar ingresar el valor numerico
/// \return [1] Si pudo obtener el numero ingresado (float) - [-1] Sino pudo obtenerlo.
///
int obtenerNumeroFloat( float* pResultado, char* mensaje, char* mensajeError, int reintentos);


/// \fn int mostrarMenu(int, int, float, float)
/// \brief Permite mostrar el menu de opciones de una calculadora, retorna la opción seleccionada y muestra los operandos en caso de haber sido cargados.
/// \param retornoPrimerOperando : Indica si se ingreso el primer operando (valor = 1)
/// \param retornoSegundoOperando : Indica si se ingreso el primer operando (valor = 1)
/// \param primerOperando : Valor del primer operando
/// \param segundoOperando : Valor del primer operando
/// \return Retorna la opcion ingresada.
///
int mostrarMenu(int retornoPrimerOperando, int retornoSegundoOperando, float primerOperando, float segundoOperando);



/// \fn int determinarEntero(int*, float)
/// \brief Determina si un numero flotante es entero (no tiene parte fraccionaria)
/// \param pEntero : Graba el entero
/// \param numFloat : Numero flotante a determinar si es entero o tiene parte fraccionaria.
/// \return [1] error: la determinacion no se realizó - [0] éxito: la determinacion se realizó.
///
int determinarEntero(int* pEntero, float numFloat);

#endif /* ENTRADADATOS_H_ */
