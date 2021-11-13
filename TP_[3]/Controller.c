#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "Parser.h"
#include "Controller.h"
#include "id.h"



int controller_loadFromTextInit(LinkedList* pArrayListEmployee, int* maxId)
{
    int retorno = 0;
    char confirmacionString[2];
    char confirmacionChar;
    char path[20];
    char extension []= ".csv";
    FILE* f = NULL;
    int len;


    utn_getDescripcion(path,20, "\nIngrese el path (la extension .csv se agrega automaticamente): \n","Error. Path invalido.\n",3);
    strcat(path,extension);

    f = fopen(path, "r");

    if( f == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }
    else
    {
        len = ll_len(pArrayListEmployee) > 0;

        if(len >0)
        {
            utn_getChar(confirmacionString,2,
                        "\nYa hay datos cargados en el listado, si procede los datos seran eliminados. Confirma [S-N]: ",
                        "\nError, ingrese S para confirmar, N para cancelar.", 3);

            confirmacionChar = confirmacionString[0];
            confirmacionChar = toupper(confirmacionChar);
        }
    }

    if(f != NULL && (confirmacionChar == 'S' ||  ll_len(pArrayListEmployee) == 0))
    {
        ll_clear(pArrayListEmployee);
        controller_loadFromText(path, pArrayListEmployee);
        buscarMayorId(pArrayListEmployee,maxId);
        guardarId((*maxId));
        retorno = 1;

    }

    return retorno;
}



int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    FILE* pFile;

    pFile = fopen(path, "r");

    if (pFile != NULL && pArrayListEmployee!= NULL)
    {
        parser_EmployeeFromText(pFile, pArrayListEmployee);
        fclose(pFile);
        retorno = 1;
    }

    return retorno;

}



int controller_loadFromBinaryInit(LinkedList* pArrayListEmployee, int* maxId)
{
    int retorno = 0;
    char confirmacionString[2];
    char confirmacionChar;
    char path[20];
    char extension []= ".bin";
    FILE* f = NULL;
    int len;


    utn_getDescripcion(path,20, "\nIngrese el path (la extension .bin se agrega automaticamente): \n","Error. Path invalido.\n",3);
    strcat(path,extension);

    f = fopen(path, "rb");

    if( f == NULL)
    {
        printf("\nNo se pudo abrir el archivo\n");
    }
    else
    {
        len = ll_len(pArrayListEmployee) > 0;

        if(len >0)
        {
            utn_getChar(confirmacionString,2,
                        "\nYa hay datos cargados en el listado, si procede los datos seran eliminados. Confirma [S-N]: ",
                        "\nError, ingrese S para confirmar, N para cancelar.", 3);

            confirmacionChar = confirmacionString[0];
            confirmacionChar = toupper(confirmacionChar);
        }
    }

    if(f != NULL && (confirmacionChar == 'S' ||  ll_len(pArrayListEmployee) == 0))
    {
        ll_clear(pArrayListEmployee);
        controller_loadFromBinary(path, pArrayListEmployee);
        buscarMayorId(pArrayListEmployee,maxId);
        guardarId((*maxId));

    }

    return retorno;
}



int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    int retorno = 0;

    FILE* pFile;

    pFile = fopen(path, "rb");

    if (pFile != NULL)
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        fclose(pFile);
        retorno = 1;
    }

    return retorno;

}



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    int len;
    Employee *pEmployee;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[128];


    if(pArrayListEmployee == NULL)
    {
        printf("\nNo hay empleados para listar.\n");
    }
    else
    {
        len = ll_len(pArrayListEmployee);
        printf("\n\n           ***Listado de empleados***       \n\n");
        printf(" ID    Nombre                                             Horas trabajadas   Sueldo\n");


        for(int i=0; i<len; i++)
        {
            pEmployee = ll_get(pArrayListEmployee, i);
            employee_getId(pEmployee, &id);
            employee_getNombre(pEmployee, nombre);
            employee_getSueldo(pEmployee, &sueldo);
            employee_getHorasTrabajadas(pEmployee, &horasTrabajadas);
            printf(" %-5d %-50s %-3d                $%-d \n", id, nombre, horasTrabajadas,sueldo);
        }

        printf("\n\n");
        retorno = 1;
    }

    return retorno;
}



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee *pEmployee;
    pEmployee = employee_new();

    int retorno = 0;
    int id;
    int horasTrab;
    int sueldo;
    char nombre[128];

    if( pArrayListEmployee != NULL && pEmployee != NULL &&
            !utn_getNombre(nombre, 128, "\nIngrese el nombre: ", "\nNombre invalido. ",3)  &&
            !utn_getNumeroEntero(&sueldo, "Ingrese el sueldo: ", "Error.", 10000, 500000, 3) &&
            !utn_getNumeroEntero(&horasTrab,"Ingrese las horas trabajadas: ", "Error.\n",0,500,3))

    {
        obtenerId(&id);
        employee_setId(pEmployee, id);
        employee_setNombre(pEmployee, nombre);
        employee_setSueldo(pEmployee, sueldo);
        employee_setHorasTrabajadas(pEmployee, horasTrab);
        ll_add(pArrayListEmployee, pEmployee);
        actualizarId(id);
        retorno = 1;
    }

    return retorno;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* pEmployee;
    int idEmpl;
    int maxId;
    int index;
    char confirmacionString[2];
    char confirmacionChar;
    int opcion;
    char auxNombre[128];
    int auxHoras;
    int auxSueldo;

    if(pArrayListEmployee != NULL)
    {
        obtenerId(&maxId);
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumeroEntero(&idEmpl, "Ingrese el ID a modificar: ", "Error. Id incorrecto.\n",1, maxId,3);
        index = buscarEmpleadoPorId(pArrayListEmployee, idEmpl);



        if(index == -1)
        {
            printf("\nEl valor ingresado como id no esta registrado en el sistema\n");
        }
        else
        {
            pEmployee = (Employee*) ll_get(pArrayListEmployee, index);

            if ( pEmployee != NULL &&

                    printf("\n\n    Empleado seleccionado: \n") &&
                    controller_imprimirUnEmpleado(pArrayListEmployee, index) &&

                    !utn_getChar(confirmacionString,2,"\nConfirma el empleado a modificar[S-N]: ",
                                 "\nError, ingrese S para confirmar, N para cancelar.", 3) &&
                    (confirmacionChar = confirmacionString[0]) &&
                    (confirmacionChar = toupper(confirmacionChar)) &&
                    (confirmacionChar == 'S') &&

                    !utn_getNumeroEntero(&opcion,
                                         "\nMenu de modificaciones\n\n"
                                         "1. Modificar nombre.\n"
                                         "2. Modificar horas trabajadas.\n"
                                         "3. Modificar sueldo.\n"
                                         "4. Salir\n\n"
                                         "Seleccione una opcion: ",
                                         "\nError opcion invalida. Seleccione una opcion del ",1,4,3))

            {
                switch(opcion)
                {
                case 1: // Nombre
                    if(!utn_getNombre(auxNombre, 128,
                                      "\nIngrese el nuevo nombre: ",
                                      "\nNombre invalido. ",3))
                    {
                        employee_setNombre(pEmployee,auxNombre);
                        retorno = 1;
                    }
                    else
                    {
                        printf("No se pudo modificar el nombre");
                    }
                    break;

                case 2: // Horas
                    if(!utn_getNumeroEntero(&auxHoras,
                                            "Ingrese las nuevas horas trabajadas: ",
                                            "Error.\n",0,200,3))
                    {
                        employee_setHorasTrabajadas(pEmployee,auxHoras);
                        retorno = 1;
                    }
                    else
                    {
                        printf("No se pudo modificar las horas");
                    }
                    break;

                case 3: // Sueldo
                    if(!utn_getNumeroEntero(&auxSueldo,
                                            "Ingrese el sueldo: ",
                                            "Error.", 50000, 500000, 3))
                    {
                        employee_setSueldo(pEmployee,auxSueldo);
                        retorno = 1;
                    }
                    else
                    {
                        printf("No se pudo modificar las horas");
                    }
                    break;

                case 4:
                    printf("Ha seleccionado salir\n");
                    break;

                }

            }
        }

    }

    return retorno;
}



int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    Employee* pEmployee;
    int idEmpl;
    int maxId;
    int index;
    char confirmacionString[2];
    char confirmacionChar;


    if(pArrayListEmployee != NULL)
    {
        obtenerId(&maxId);
        controller_ListEmployee(pArrayListEmployee);
        utn_getNumeroEntero(&idEmpl, "Ingrese el ID a dar de baja: ", "Error. Id incorrecto.\n",1, maxId,3);
        index = buscarEmpleadoPorId(pArrayListEmployee, idEmpl);



        if(index == -1)
        {
            printf("El valor ingresado en id no esta registrado en el sistema.");
        }
        else
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee, index);

            if( pEmployee!= NULL &&
                    printf("\n\n    Empleado seleccionado: \n") &&
                    controller_imprimirUnEmpleado(pArrayListEmployee, index) &&
                    !utn_getChar(confirmacionString,2,"\nConfirma el empleado a dar de baja[S-N]: ", "\nError, ingrese S para confirmar, N para cancelar.", 3))
            {
                confirmacionChar = confirmacionString[0];
                confirmacionChar = toupper(confirmacionChar);

                if(confirmacionChar == 'S')
                {

                    ll_remove(pArrayListEmployee,index);
                    employee_delete(pEmployee);
                    retorno = 1;
                }
                else if (confirmacionChar == 'N')
                {
                    printf("\nBaja cancelada por usuario.");
                }
            }
        }

    }

    return retorno;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    int orden = 1;
    int opcion;

    if ((pArrayListEmployee != NULL) &&
            (!utn_getNumeroEntero(&opcion, "\n\n Menu de criterios: \n"
                                  "\n1.Ordenar por Nombre "
                                  "\n2.Ordenar por Horas trabajadas "
                                  "\n3.Ordenar por Sueldo "
                                  "\n4.Ordenar por Id"
                                  "\nIngrese una opcion: ",
                                  "Error, elija una opcion valida\n", 1, 4, 3)) &&
            (!utn_getNumeroEntero(&orden, "\n\n Menu de orden: \n"
                                  "\n0.Descendente "
                                  "\n1.Ascendente "
                                  "\nIngrese una opcion: ",
                                  "Error, elija una opcion valida\n", 0, 1, 3)))

        {
            switch (opcion)
            {

            case 1:
                ll_sort(pArrayListEmployee, employee_OrdenarPorNombre,orden);
                controller_ListEmployee(pArrayListEmployee);
                retorno = 1;
                break;

            case 2:
                ll_sort(pArrayListEmployee, employee_OrdenarPorHoras,orden);
                controller_ListEmployee(pArrayListEmployee);
                retorno = 1;
                break;

            case 3:
                ll_sort(pArrayListEmployee, employee_OrdenarPorsueldo,orden);
                controller_ListEmployee(pArrayListEmployee);
                retorno = 1;
                break;

            case 4:
                ll_sort(pArrayListEmployee, employee_OrdenarPorId,orden);
                controller_ListEmployee(pArrayListEmployee);
                retorno = 1;
                break;
            }

        }
    else
        {
            printf("\n\nSe acabaron sus reintentos, vuelva a ingresar\n");
        }

    return retorno;

}



int controller_saveAsText_Init(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char confirmacionString[2];
    char confirmacionChar;
    char path[20];
    char extension []= ".csv";
    FILE* f = NULL;

    utn_getDescripcion(path,20, "\nIngrese el path (la extension .csv se agrega automaticamente): \n","Error. Path invalido.\n",3);
    strcat(path,extension);

    f = fopen(path, "r");

    if( f != NULL)
        {
            utn_getChar(confirmacionString,2,
                        "\nYa exite ese path, si procede los datos seran eliminados. Confirma [S-N]: ",
                        "\nError, ingrese S para confirmar, N para cancelar.", 3);

            confirmacionChar = confirmacionString[0];
            confirmacionChar = toupper(confirmacionChar);
        }

    if( confirmacionChar == 'S' || f == NULL)
        {
            controller_saveAsText(path, pArrayListEmployee);
            retorno = 1;
        }

    return retorno;
}



int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");

		if (pFile != NULL)
		{
			parser_EmployeeToText(pFile, pArrayListEmployee);
			fclose(pFile);
			retorno = 1;
		}
	}
	return retorno;
}



int controller_saveAsBinary_Init(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char confirmacionString[2];
    char confirmacionChar;
    char path[20];
    char extension []= ".bin";
    FILE* f = NULL;

    utn_getDescripcion(path,20, "\nIngrese el path (la extension .bin se agrega automaticamente): \n","Error. Path invalido.\n",3);
    strcat(path,extension);

    f = fopen(path, "rb");

    if( f != NULL)
        {
            utn_getChar(confirmacionString,2,
                        "\nYa exite ese path, si procede los datos seran eliminados. Confirma [S-N]: ",
                        "\nError, ingrese S para confirmar, N para cancelar.", 3);

            confirmacionChar = confirmacionString[0];
            confirmacionChar = toupper(confirmacionChar);
        }

    if( confirmacionChar == 'S' || f == NULL)
        {
            controller_saveAsBinary(path, pArrayListEmployee);
            retorno = 1;
        }

    return retorno;
}



int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE *pFile;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile != NULL)
		{
			parser_EmployeeToBinary(pFile, pArrayListEmployee);
			fclose(pFile);
			retorno = 1;
		}
	}
	return retorno;
}





/** \brief Imprime los datos de un empleado
 *
 * \param puntero al array de empleados
 * \param indice del empleado a imprimir
 * \return retorno (0) ERROR - Si el puntero a LikedList es NULL o el indice es invalido
 *				   (1) EXITO
 *
 */

int controller_imprimirUnEmpleado(LinkedList* pArrayListEmployee, int index)
{
    int retorno = 0;
    Employee aux;
    Employee* pEmployee;

    if(pArrayListEmployee != NULL && index >= 0)
    {
        pEmployee = (Employee*)ll_get(pArrayListEmployee,index);
        if(	pEmployee != NULL &&
                employee_getId(pEmployee, &aux.id) &&
                employee_getNombre(pEmployee, aux.nombre) &&
                employee_getHorasTrabajadas(pEmployee, &aux.horasTrabajadas) &&
                employee_getSueldo(pEmployee, &aux.sueldo))
        {
            printf("\n ID    Nombre                                        Horas trabajadas   Sueldo");
            printf("\n %-5d %-50s %-3d                $%-d \n",
                   aux.id,
                   aux.nombre,
                   aux.horasTrabajadas,
                   aux.sueldo);
            retorno = 1;
        }
    }
    return retorno;
}
