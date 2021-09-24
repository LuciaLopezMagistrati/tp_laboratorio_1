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
/// \return : [1] error: la suma no se realizó - [0] éxito: la suma se realizó.
///
int sumarFloat(float* pResultado, float num1, float num2);


/// \fn int restarFloat(float*, float, float)
/// \brief  Restar dos numeros flotantes
/// \param pResultado : Graba el resultado de la resta de los dos numeros flotantes;
/// \param num1 : Primer numero a restar;
/// \param num2 : Segundo numero a restar;
/// \return [1] error: la resta no se realizó - [0] éxito: la resta se realizó.
///
int restarFloat(float* pResultado, float num1, float num2);

/// \fn int multiplicarFloat(float*, float, float)
/// \brief Multiplicar dos numeros flotantes
/// \param pResultado : Graba el resultado de la multiplicación de los dos numeros flotantes;
/// \param num1 : Primer numero a multiplicar;
/// \param num2 : Segundo numero a multiplicar;
/// \return [1] error: la multiplicación no se realizó - [0] éxito: la multiplicación se realizó.
///
int multiplicarFloat(float* pResultado, float num1, float num2);


/// \fn int dividirFloat(float*, float, float)
/// \brief Dividir dos numeros flotantes
/// \param pResultado : Graba el resultado de la división de los dos numeros flotantes;
/// \param num1 : Primer numero a dividir;
/// \param num2 : Segundo numero a dividir;
/// \return [1] error: la división no se realizó - [0] éxito: la división se realizó.
///
int dividirFloat(float* pResultado, float num1, float num2);


/// \fn int factorizar(int)
/// \brief Realizar la factorizacion de un numero entero positivo entre 0 y 12.
/// \param num : Numero entero a factoriza
/// \return [0] error: no se factorizo el numero - [distinto de cero] éxito: se factorizo el numero.
///
int factorizar(int num);

#endif /* OPERACIONESARITMETICAS_H_ */
