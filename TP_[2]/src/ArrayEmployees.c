/*
 * ArrayEmployee.c
 *
 *  Created on:
 *      Author: luclopez
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include"ArrayEmployees.h"
#include"utn.h"




int initEmployees(Employee* list, int len)
{
    int result = -1;

    if(list !=NULL && len > 0)
    {
        result = 0;

        for(int i = 0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
    }

    return result;
}



int getEmptyIndex(Employee* list, int len)
{
    int result = -1;

    if(list !=NULL && len > 0)
    {

        for(int i = 0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                result = i;
                break;
            }
        }
    }

    return result;
}



int hireEmployee(Employee* list, int len, int *pId, int retries, float minSalary, float maxSalary, int sectorFrom, int sectorTo)
{
    int result= -1;
    Employee auxList;
    int id;

    if(list!=NULL && len>0 && pId!=NULL && minSalary <= maxSalary &&
            !utn_getNombre(auxList.name, NAME_LEN, "\nIngrese el nombre: ", "\nNombre invalido. ",retries)  &&
            !utn_getNombre(auxList.lastName, LAST_NAME_LEN, "Ingrese el apellido: ", "\nApellido invalido. ",retries)  &&
            !utn_getNumeroFlotante(&auxList.salary,"Ingrese el salario (35000 - 999999]: ","\nSalario invalido. ",minSalary,maxSalary,retries) &&
            !utn_getNumeroEntero(&auxList.sector, "Ingrese el sector [1-5]: ","\nError. Sector invalido. ", sectorFrom, sectorTo, retries) )

    {
        result = 0;
        id = *pId;
        strlwr(auxList.name);
        auxList.name[0] = toupper(auxList.name[0]);
        strlwr(auxList.lastName);
        auxList.lastName[0] = toupper(auxList.lastName[0]);

        if(!addEmployee(list,len,id,auxList.name,auxList.lastName,auxList.salary,auxList.sector))
        {
            printf("\nAlta - OK\n\n");
            (*pId)++;
        }
        else
        {
            printf("\nError en el alta\n\n");
        }

    }

    return result;
}



int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int result = -1;
    int index;

    index = getEmptyIndex(list,len);

    if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>=0 && sector>0 && index>=0)
    {

        list[index].id = id;
        strncpy(list[index].name, name,NAME_LEN);
        strncpy(list[index].lastName,lastName,NAME_LEN);
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].isEmpty = 0;
        result = 0;
    }
    return result;
}



int findEmployeeById(Employee* list, int len,int id)
{
    int result = -1;

    if(list != NULL && len >0)

    {
        for(int i = 0; i<=len; i++)
        {
            if(list[i].id == id)
            {
                result = i;
                break;
            }
        }
    }

    return result;
}




int printEmployee(Employee* list, int i)
{

    int result = -1;

    if(list != NULL )
    {
        result = 0;

        printf("\n--------------------------------------------------------------------------\n");
        printf("   ID  Nombre                  Apellido              Sueldo       Sector  \n");
        printf("--------------------------------------------------------------------------\n");

        {

            printf(" %4d  %-15s         %-15s       %-9.2f       %-2d\n",
                   list[i].id,
                   list[i].name,
                   list[i].lastName,
                   list[i].salary,
                   list[i].sector);
        }

    }

    return result;
}



int removeEmployee(Employee* list, int len, int id)
{
    int result = -1;

    if(list != NULL && len >0)

    {
        for(int i = 0; i<len; i++)
        {
            if(list[i].id == id && list[i].isEmpty != 1)
            {

                result = 0;
                list[i].isEmpty = 1;
                break;
            }
        }
    }

    return result;
}




int terminateEmployeeById(Employee* list, int len, int minId, int maxId, int retries)
{
    int num;
    int result = -1;
    int index;

    printEmployees(list,len);
    if(!utn_getNumeroEntero(&num, "\nIngrese ID a dar de baja: ", "Error, ingrese un ID valido.\n", minId, maxId, retries))
    {

        index = findEmployeeById(list, len, num);
        if( index == -1)
        {
            printf("\nID invalido\n");
        }
        else
        {
                if(!removeEmployee(list, len, num))
                {
                    result = 0;
                    printf("\nBaja realizada correctamente \n");
                }
                else
                {
                    printf("\nError en la baja\n\n");
                }
            }

    }

    return result;
}






int updateEmployeeById(Employee* list, int len, int retries, int sectorFrom, int sectorTo, int minId, int maxId)
{
    int num;
    int result = -1;
    int index;
    int opcion;

    printEmployees(list,len);

    if(list != NULL && len > 0 && minId <= maxId &&
            !utn_getNumeroEntero(&num, "\nIngrese ID a modificar: ", "Error, ingrese un ID valido: \n", minId, maxId, retries))
    {

        index = findEmployeeById(list, len, num);

        if( index == -1)
        {
            printf("\nNumero de ID invalido\n\n");
        }
        else
        {
            result = 0;

            {
                do
                {
                    if(!utn_getNumeroEntero(&opcion, "\nMenu de modificaciones\n\n"
                                            "1. Cambiar nombre\n"
                                            "2. Cambiar apellido\n"
                                            "3. Cambiar salario\n"
                                            "4. Cambiar sector\n"
                                            "5. Salir\n\n"
                                            "Seleccione una opcion: ",
                                            "\nError opcion invalida. Seleccione una opcion del ",1,5,retries))
                    {
                        switch(opcion)
                        {
                        case 1:
                            if(!utn_getNombre(list[index].name, NAME_LEN,
                                              "\nIngrese el nombre: ",
                                              "\nNombre invalido\n",retries))
                            {
                                printf("Nombre modificado correctamente\n\n");
                            }
                            break;
                        case 2:
                            if(!utn_getNombre(list[index].lastName, LAST_NAME_LEN,
                                              "\nIngrese el apellido: ",
                                              "\nApelido invalido\n",retries))
                            {
                                printf("Apellido modificado correctamente\n\n");
                            }
                            break;
                        case 3:

                            if(!utn_getNumeroFlotante(&list[index].salary,
                                                      "\nIngrese el nuevo salario (maximo 30% superior al actual): ",
                                                      "\nSalario invalido\n",
                                                      list[index].salary+1,list[index].salary*1.3,retries))
                            {
                                printf("Salario modificado correctamente\n\n");
                            }
                            break;
                        case 4:
                            if(!utn_getNumeroEntero(&list[index].sector,
                                                    "\nIngrese el sector: ",
                                                    "\nSector invalido\n",
                                                    sectorFrom, sectorTo, retries))
                            {
                                printf("Sector modificado correctamente\n\n");
                            }
                            break;
                        }
                    }
                }
                while(opcion != 5);

        }


    }
    }

    return result;
}










int calculateSalaryAverage(Employee* list, int length)
{
    int result = -1;
    float accumSalary = 0.0;
    int count = 0;
    int flag = 1;
    float salaryAverage;
    int countEmp =0;

    if (list != NULL && length > 0)
    {
        result = 0;
        for(int i =0; i<length ; i++)
        {
            if(list[i].isEmpty == 0)
            {
                accumSalary= accumSalary + list[i].salary;
                count++;
                flag = 0;
            }
        }

        if(!flag)
        {
            salaryAverage =   accumSalary / count;
            printf("\n\nEl total de los salarios es %.2f\n", accumSalary);
            printf("El promedio de los salarios es %.2f\n", salaryAverage);

            for(int i =0; i<length ; i++)
            {
                if(!list[i].isEmpty && list[i].salary > salaryAverage)
                {
                    countEmp++;
                }
            }
            printf("La cantidad de empleados que superan el salario promedio es: %d\n\n",countEmp);

        }
        else
        {
            printf("\nNo hay personas para realizar calculos sobre salarios\n\n");
        }

    }

    return result;

}



int printEmployees(Employee* list, int length)
{
    int result = -1;
    int flag = 1;

    if(list != NULL && length > 0)
    {
        printf("                     **Lista de Empleados  **\n");
        printf("--------------------------------------------------------------------------\n");
        printf("   ID  Nombre                  Apellido              Sueldo       Sector  \n");
        printf("--------------------------------------------------------------------------\n");

        for(int i =0; i<length ; i++)
        {
            if(!list[i].isEmpty)
            {

                printf(" %4d  %-15s         %-15s       %-9.2f       %-2d \n",
                       list[i].id,
                       list[i].name,
                       list[i].lastName,
                       list[i].salary,
                       list[i].sector);
                flag = 0;
            }
        }

        if(flag)
        {
            printf("\nNo hay personas para mostrar\n");
        }

        result = 0;
    }

    return result;
}




int sortEmployees(Employee* list, int len, int order)
{
    int result = -1;
    int flagSwap;
    Employee auxList;
    int newLen;


    if(list!= NULL && len > 0 && (order == 0 || order ==1))
    {
        newLen = len -1;

        do
        {
            flagSwap = 0;

            for(int i=0; i < newLen; i++)
            {
                if(
                    ((strncmp(list[i].lastName, list[i+1].lastName, LAST_NAME_LEN) > 0 && order ==1) ||
                     (strncmp(list[i].lastName, list[i+1].lastName,LAST_NAME_LEN) < 0 && order ==0)) ||
                    ((strncmp(list[i].lastName, list[i+1].lastName, LAST_NAME_LEN) == 0) &&
                     ((list[i].sector > list[i+1].sector && order ==1) ||
                      (list[i].sector < list[i+1].sector && order ==0))))
                {
                    flagSwap = 1;
                    auxList = list[i];
                    list[i] = list[i+1];
                    list[i+1] = auxList;
                }
            }

            newLen--;
        }
        while(flagSwap);

        result = 1;
    }

    return result;
}




int reportEmployees(Employee * list, int len, int retries)
{
    int result = -1;
    int opcion;

    if(list != NULL && len >0 )
    {
        if(!utn_getNumeroEntero(&opcion, "\nIndicar criterio de orden del listado:\n\n"
                                "0. Descendente\n"
                                "1. Ascendente\n\n"
                                "Seleccione una opcion: ",
                                "\nError opcion invalida. Seleccione una opcion del ",0,2,retries))
            sortEmployees(list, len,opcion);
        printEmployees(list, len);
        calculateSalaryAverage(list, len);

        result = 0;
    }

    return result;
}



int isData(Employee* list, int len)
{
    int i;
    int result = 0;

    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                result = 1;
                break;
            }
        }
    }
    return result;
}

