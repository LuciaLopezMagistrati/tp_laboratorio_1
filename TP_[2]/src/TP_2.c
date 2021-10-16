/*
 ============================================================================
 Name        : TP_2.c
 Author      : Lucia Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Práctico 2 - Programacion 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include"ArrayEmployees.h"
#include"utn.h"

#define QTY_EMPLOYEES 1000
#define MAX_HIRE_WAGE 999999
#define MIN_HIRE_WAGE 35000
#define QTY_RETRIES 2
#define FROM_SECTOR 1
#define TO_SECTOR 5
#define MIN_ID 1


int main(void) {

	setbuf(stdout,NULL);

    Employee arrayList[QTY_EMPLOYEES];

    int opcion;
    int pId = MIN_ID;



    initEmployees(arrayList, QTY_EMPLOYEES);

    do
    {

        if(!utn_getNumeroEntero(&opcion,"Menu de acciones\n\n"
                                "1. Altas\n"
                                "2. Modificar\n"
                                "3. Baja\n"
                                "4. Informar\n"
                                "5. Salir\n\n"
                                "Seleccione una opcion: ",
                                "\nError opcion invalida. Seleccione una opcion del ",1,5,QTY_RETRIES))
        {
            switch(opcion)
            {
            case 1:
                hireEmployee(arrayList, QTY_EMPLOYEES, &pId, QTY_RETRIES, MIN_HIRE_WAGE, MAX_HIRE_WAGE, FROM_SECTOR, TO_SECTOR);
                break;

            case 2:
                if(isData(arrayList, QTY_EMPLOYEES))
                {
                    updateEmployeeById(arrayList, QTY_EMPLOYEES, QTY_RETRIES, FROM_SECTOR, TO_SECTOR, MIN_ID, pId);
                }
                else
                {
                    printf("\nPara modificar  es necesario registrar el alta previamente.\n\n");
                }
                break;

            case 3:
                if(isData(arrayList, QTY_EMPLOYEES))
                {
                    terminateEmployeeById(arrayList, QTY_EMPLOYEES, MIN_ID, pId,QTY_RETRIES);
                }
                else
                {
                    printf("\nPara dar de baja es necesario registrar el alta previamente.\n\n");
                }
                break;

            case 4:
                if(isData(arrayList, QTY_EMPLOYEES))
                {
                    reportEmployees(arrayList, QTY_EMPLOYEES,QTY_RETRIES);
                }
                else
                {
                    printf("\nPara ejecutar un informe es necesario registrar al menos un alta previamente.\n\n");
                }
                break;
            }
        }

    }
    while(opcion != 5);

	return EXIT_SUCCESS;
}
