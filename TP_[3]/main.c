#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"
#include "Parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#define QTY_RETRIES 3


int main()
{
    setbuf(stdout,NULL);

    int option = 0;
    int nextId = 1;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {

        if(!utn_getNumeroEntero(&option,"\nMenu de acciones\n\n"
                                " 1. Cargar los datos de los empleados desde el archivo .csv (modo texto).\n"
                                " 2. Cargar los datos de los empleados desde el archivo .bin (modo binario).\n"
                                " 3. Alta de empleado\n"
                                " 4. Modificar datos de empleado\n"
                                " 5. Baja de empleado\n"
                                " 6. Listar empleados\n"
                                " 7. Ordenar empleados\n"
                                " 8. Guardar los datos de los empleados en el archivo .csv (modo texto).\n"
                                " 9. Guardar los datos de los empleados en el archivo .bin (modo binario).\n"
                                "10. Salir\n\n"
                                "Seleccione una opcion: ",
                                "\nError opcion invalida. Seleccione una opcion del ",1,10,QTY_RETRIES))

        switch(option)
            {
                case 1: // Cargar csv
                    if(controller_loadFromTextInit(listaEmpleados, &nextId))
                        {
                            printf("\nCarga de datos desde archivo .csv exitosa\n");
                        }
                    else
                        {
                            printf("\nError en la carga de datos desde archivo .csv\n");
                        }
                    break;

                case 2: // Cargar bin
                    if(controller_loadFromBinaryInit(listaEmpleados, &nextId))
                        {
                            printf("\nCarga de datos desde archivo .bin exitosa\n");
                        }
                    else
                        {
                            printf("\nError en la carga de datos desde archivo .bin\n");
                        }
                    break;

                case 3: // Alta de empleado
                     controller_addEmployee(listaEmpleados);
                     break;

                case 4: // Modificar datos de empleado
                    if(ll_isEmpty(listaEmpleados)==0)
                        {
                            if(controller_editEmployee(listaEmpleados))
                                {
                                    printf("\nModificación realizada con exito.\n");
                                }
                            else
                                {
                                printf("\nNo se pudo realizar la modificación.\n");
                                }
                        }
                    else
                        {
                            printf("\nPara realizar una modificacion se requiere que exista al menos un empleado (por archivo o alta manual).\n");
                        }

                    break;

                case 5: //Baja de empleado
                    if(ll_isEmpty(listaEmpleados)==0)
                        {
                            if(controller_removeEmployee(listaEmpleados))
                                {
                                    printf("\nBaja realizada con exito.\n");
                                }
                            else
                                {
                                printf("\nNo se pudo realizar la baja.\n");
                                }
                        }
                    else
                        {
                            printf("\nPara realizar una baja se requiere que exista al menos un empleado (por archivo o alta manual).\n");
                        }
					break;

                case 6: // Listar empleados
                    if(ll_isEmpty(listaEmpleados)==0)
                        {
                            controller_ListEmployee(listaEmpleados);
                        }
					else
                        {
                            printf("\nPara listar se requiere que exista al menos un empleado (por archivo o alta manual).\n");
                        }
                    break;

                case 7: // Ordenar empleados
                    if(ll_isEmpty(listaEmpleados)==0)
                        {
                            controller_sortEmployee(listaEmpleados);
                        }
                    else
                        {
                            printf("\nPara realizar el ordenamiento se requiere que exista empleados (por archivo o alta manual).\n");
                        }

                     break;

                case 8: // Guardar csv
                   if(ll_isEmpty(listaEmpleados)==0)
                        {
                            if(controller_saveAsText_Init(listaEmpleados))
                                {
                                    printf("\nDatos guardados con exito.\n");
                                }
                            else
                                {
                                printf("\nNo se pudo guardar los datos.\n");
                                }
                        }
                    else
                        {
                            printf("\nPara guardar datos se requiere que exista al menos un empleado (por archivo o alta manual).\n");
                        }
                    break;

                case 9: //  Guardar bin
                     if(ll_isEmpty(listaEmpleados)==0)
                        {
                            if(controller_saveAsBinary_Init(listaEmpleados))
                                {
                                    printf("\nDatos guardados con exito.\n");
                                }
                            else
                                {
                                printf("\nNo se pudo guardar los datos.\n");
                                }
                        }
                    else
                        {
                            printf("\nPara guardar datos se requiere que exista al menos un empleado (por archivo o alta manual).\n");
                        }
                    break;
                     break;

                case 10: // Salir
                     ll_clear(listaEmpleados);
					 ll_deleteLinkedList(listaEmpleados);
					 remove("ultimoID.txt");
                     break;
            }
    }
    while(option != 10);

    return 0;
}

