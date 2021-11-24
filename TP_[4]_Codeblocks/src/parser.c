#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "../inc/Employee.h"
#include "../inc/Parser.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee *pEmployee;

	char auxID[100];
	char auxNombre[250];
	char auxHorasTrabajadas[100];
	char auxSueldo[100];

	int retorno = 0;


	if (pFile != NULL && pArrayListEmployee != NULL)
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxNombre, auxHorasTrabajadas,auxSueldo); // lectura cabecera

            do
            {
                fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxID, auxNombre, auxHorasTrabajadas,auxSueldo);
                pEmployee = employee_newParametros(auxID, auxNombre, auxHorasTrabajadas,auxSueldo);

                if (pEmployee != NULL)
                    {
                        ll_add(pArrayListEmployee, pEmployee);
                        retorno = 1;
                    }
            }while(!feof(pFile));
        }

    return retorno;
}



int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    Employee* pEmployee;

    if (pFile != NULL && pArrayListEmployee != NULL)
        {
            do
            {
                pEmployee = employee_new();

                if (pEmployee != NULL && fread(pEmployee,sizeof(Employee),1,pFile)==1)
                    {
                        ll_add(pArrayListEmployee, pEmployee);
                        retorno = 1;
                    }
                else {
                        employee_delete(pEmployee);
                        break;
                    }
            } while (!feof(pFile));

            retorno = 1;
        }

    return retorno;
}



int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee *pEmployee;
    char nombre[128];
    int ID;
    int horas;
    int sueldo;
	int len;


	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		fprintf(pFile, "ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");

		for (int i = 0; i < len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if (pEmployee != NULL &&
				employee_getId(pEmployee, &ID) &&
				employee_getNombre(pEmployee, nombre) &&
				employee_getSueldo(pEmployee, &sueldo) &&
				employee_getHorasTrabajadas(pEmployee, &horas))
			{
				fprintf(pFile, "%d,%s,%d,%d\n", ID, nombre, horas, sueldo);
			}
		}
		retorno = 1;
	}
	return retorno;
}



int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* pEmployee;
	int len;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		for (int i = 0; i < len; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee, i);

			if (pEmployee != NULL)
			{
				fwrite(pEmployee, sizeof(Employee), 1, pFile);
			}
		}
		retorno = 1;
	}
	return retorno;
}
