#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "id.h"


int buscarMayorId(LinkedList* pArrayListEmployee, int* pId)
{
    int retorno = 0;
    Employee* auxEmp = NULL;
    int mayor;

    if(pArrayListEmployee != NULL)
    {

        for(int i=0; i< ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
            if(i==0 || auxEmp->id > mayor)
            {
                mayor = auxEmp->id;
            }
        }
        *pId = mayor+1;

        retorno = 1;
    }

    return retorno;
}



int guardarId(int id)
{

    int retorno = 0;
    FILE* pFile;
    pFile = fopen("ultimoID.txt","w");

    if(pFile!=NULL)
    {
        fprintf(pFile,"%d\n",id);
        fclose(pFile);

        retorno = 1;
    }

    return retorno;
}



int obtenerId(int* id)
{
    int retorno = 0;
    *id = 1;
    int newID;

    FILE* pFile;
    pFile = fopen("ultimoID.txt","r");

    if(pFile!=NULL)
    {
        fscanf(pFile, "%d\n", &newID);
        *id = newID;
        fclose(pFile);

        retorno = 1;
    }


    return retorno;
}



int actualizarId(int id)
{
    int nextID = ++id;

    int retorno = 0;
    FILE* pFile;
    pFile = fopen("ultimoID.txt","w");

    if(pFile!=NULL)
    {
        fprintf(pFile,"%d\n",nextID);
        fclose(pFile);

        retorno = 1;
    }

    return retorno;
}


int buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    int auxId;
    int len;
    Employee* pEmployee;

    if (pArrayListEmployee != NULL && id > 0)
    {
        len = ll_len(pArrayListEmployee);

        for (int i = 0; i < len; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee,i);

            if (pEmployee != NULL && employee_getId(pEmployee, &auxId) == 1 && auxId == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
