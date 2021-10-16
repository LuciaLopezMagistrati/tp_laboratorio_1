/*
 * utn.h
 *
 *  Created on:
 *      Author: luclopez
 */

#ifndef UTN_H_
#define UTN_H_

/**
 * \brief Request to user to enter a number (integer)
 * \param int *pNumber, pointer to the space where the value obtained will be saved
 * \param char *message, input message
 * \param char *errorMessage, error message
 * \param int min, minimum value allowed
 * \param int max, maximum value allowed
 * \param int retries, number of retries allowed
 * \return (-1) ERROR (0) SUCCESS
 */
int utn_getNumeroEntero( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Request to user to enter a number (float)
 * \param int *pNumber, pointer to the space where the value obtained will be saved
 * \param char *message, input message
 * \param char *errorMessage, error message
 * \param int min, minimum value allowed
 * \param int max, maximum value allowed
 * \param int retries, number of retries allowed
 * \return (-1) ERROR (0) SUCCESS
 */
int utn_getNumeroFlotante( float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


/**
 * \brief Request to user to enter a string (only letters)
 * \param int *pNumber, pointer to the space where the value obtained will be saved
 * \param int Array length
 * \param char *message, input message
 * \param char *errorMessage, error message
 * \param int retries, number of retries allowed
 * \return (-1) ERROR (0) SUCCESS
 */
int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


#endif /* UTN_H_ */
