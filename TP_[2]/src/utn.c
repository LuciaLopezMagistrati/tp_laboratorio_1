/*
 * utn.c
 *
 *  Created on: 15 oct. 2021
 *      Author: luclopez
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


static int myGets ( char * cadena, int longitud);
static int getInt ( int * pResultado);
static int esNumerica ( char * cadena, int limite);
static int getFloat ( float * pResultado);
static int esFlotante ( char * cadena, int limite);
static int esNombre(char* cadena,int longitud);
static int getNombre(char* pResultado,int longitud);
static int getString(char* cadena, int longitud);


static int getConfirmacion(char* pResultado, int longitud);
static int esConfirmacion(char* cadena,int longitud);
static int getString(char* cadena, int longitud);





int utn_getNumeroEntero( int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

    int retorno = -1;
    int bufferInt;

    if(pResultado != NULL && mensaje != NULL &&  mensajeError != NULL && minimo <= maximo && reintentos >=0)
    {

        do
        {
            printf("%s", mensaje);
            if(getInt(&bufferInt) == 0 &&
                    bufferInt >= minimo &&
                    bufferInt <= maximo
              )

            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }

        }
        while(reintentos >= 0);

    }

    return retorno;
}





static int getInt ( int * pResultado)
{
    int retorno=-1;
    char buffer[64];
    if (pResultado != NULL &&
            myGets(buffer, sizeof (buffer))==0 &&
            esNumerica(buffer, sizeof (buffer)))
    {
        *pResultado = atoi (buffer);
        retorno = 0;
    }
    return retorno;
}


static int myGets ( char * cadena, int longitud)
{
    int retorno = -1;
    char bufferString [4096];


    if (cadena != NULL && longitud >0)
    {
        fflush (stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge

        if(fgets(bufferString, sizeof(bufferString),stdin) != NULL)
        {
            if (bufferString[ strnlen (bufferString, sizeof(bufferString))-1] == '\n')
            {
                bufferString[ strnlen (bufferString, sizeof(bufferString))-1] = '\0';
            }
            if (strnlen(bufferString, sizeof(bufferString)) <= longitud)
            {
                strncpy(cadena,bufferString,longitud);
                retorno=0;
            }
        }
    }

    return retorno;
}



static int esNumerica ( char * cadena, int limite)
{
    int i=0;
    int retorno = 1;

    for(i=0; i<limite && cadena[i] != '\0'; i++)
    {
        if (i==0 && (cadena[i] == '+' || cadena[i] == '-'))
        {
            continue;
        }
        if (cadena[i] < '0' || cadena[i] > '9' )
        {
            retorno = 0;
            break ;
        }
    }

    return retorno;
}






int utn_getNumeroFlotante( float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{

    int retorno = -1;
    float bufferFloat;

    if(pResultado != NULL && mensaje != NULL &&  mensajeError != NULL && minimo <= maximo && reintentos >=0)
    {

        do
        {
            printf("%s", mensaje);
            if(getFloat(&bufferFloat) == 0 &&
                    bufferFloat >= minimo &&
                    bufferFloat <= maximo
              )

            {
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }

        }
        while(reintentos >= 0);

    }

    return retorno;
}




static int getFloat ( float * pResultado)
{
    int retorno=-1;
    char buffer[64];
    if (pResultado != NULL &&
            myGets(buffer, sizeof (buffer))==0 &&
            esFlotante(buffer, sizeof (buffer)))
    {
        *pResultado = atof (buffer);
        retorno = 0;
    }
    return retorno;
}


static int esFlotante ( char * cadena, int limite)
{
    int i=0;
    int retorno = 1;
    int contadorPuntos=0;

    if(cadena != NULL && strlen(cadena)>0)
    {
        for(i=0; i<limite && cadena[i] != '\0'; i++)
        {
            if (i==0 && (cadena[i] == '+' || cadena[i] == '-' ))
            {
                continue;
            }
            if (cadena[i] < '0' || cadena[i] > '9' )
            {
                if(cadena[i] == '.' && contadorPuntos==0)
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno = 0;
                    break ;
                }

            }
        }

    }

return retorno;
}



static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}


static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getNombre(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}



static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}




static int getConfirmacion(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    		esConfirmacion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}


static int esConfirmacion(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != 'S' && cadena[i] != 'N'  && cadena[i] != 's' && cadena[i]  != 'n')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int utn_getConfirmacion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getConfirmacion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

