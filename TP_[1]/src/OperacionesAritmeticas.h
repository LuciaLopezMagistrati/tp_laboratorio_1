/*
 * OperacionesAritmeticas.h
 *
 *  Created on: 23 sep. 2021
 *      Author: luclopez
 */

#ifndef OPERACIONESARITMETICAS_H_
#define OPERACIONESARITMETICAS_H_


/// \fn int sumarFloat(float*, float, float)
/// \brief Sumar dos numeros flotantes
/// \param pResultado : Graba el resultado de la suma de los dos numeros flotantes;
/// \param num1 : Primer numero a sumar;
/// \param num2 : Segundo numero a sumar;
/// \return : [1] error: la suma no se realiz� - [0] �xito: la suma se realiz�.
///
int sumarFloat(float* pResultado, float num1, float num2);


/// \fn int restarFloat(float*, float, float)
/// \brief  Restar dos numeros flotantes
/// \param pResultado : Graba el resultado de la resta de los dos numeros flotantes;
/// \param num1 : Primer numero a restar;
/// \param num2 : Segundo numero a restar;
/// \return [1] error: la resta no se realiz� - [0] �xito: la resta se realiz�.
///
int restarFloat(float* pResultado, float num1, float num2);

/// \fn int multiplicarFloat(float*, float, float)
/// \brief Multiplicar dos numeros flotantes
/// \param pResultado : Graba el resultado de la multiplicaci�n de los dos numeros flotantes;
/// \param num1 : Primer numero a multiplicar;
/// \param num2 : Segundo numero a multiplicar;
/// \return [1] error: la multiplicaci�n no se realiz� - [0] �xito: la multiplicaci�n se realiz�.
///
int multiplicarFloat(float* pResultado, float num1, float num2);


/// \fn int dividirFloat(float*, float, float)
/// \brief Dividir dos numeros flotantes
/// \param pResultado : Graba el resultado de la divisi�n de los dos numeros flotantes;
/// \param num1 : Primer numero a dividir;
/// \param num2 : Segundo numero a dividir;
/// \return [1] error: la divisi�n no se realiz� - [0] �xito: la divisi�n se realiz�.
///
int dividirFloat(float* pResultado, float num1, float num2);


/// \fn int factorizar(int)
/// \brief Realizar la factorizacion de un numero entero positivo entre 0 y 12.
/// \param num : Numero entero a factoriza
/// \return [0] error: no se factorizo el numero - [distinto de cero] �xito: se factorizo el numero.
///
int factorizar(int num);

#endif /* OPERACIONESARITMETICAS_H_ */
