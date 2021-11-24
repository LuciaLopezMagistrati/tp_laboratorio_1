/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"

int main(void)
{
    //startTesting(1);  // ll_newLinkedList
    //startTesting(2);  // ll_len
    //startTesting(3);  // getNode - test_getNode
    //startTesting(4);  // addNode - test_addNode
    //startTesting(5);  // ll_add
    //startTesting(6);  // ll_get
    //startTesting(7);  // ll_set
    //startTesting(8);  // ll_remove
    //startTesting(9);  // ll_clear
    //startTesting(10); // ll_deleteLinkedList
    //startTesting(11); // ll_indexOf
    //startTesting(12); // ll_isEmpty
    //startTesting(13); // ll_push
    //startTesting(14); // ll_pop
    //startTesting(15); // ll_contains
    //startTesting(16); // ll_containsAll
    //startTesting(17); // ll_subList
    //startTesting(18); // ll_clone
    //startTesting(19); // ll_sort



    printf("\nFuncion ll_newLinkedList --> Se crea una LinkedList de empleados.\n");
    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("\nFuncion ll_len --> La cantidad de empleados en la lista de empleados es: %d\n", ll_len(listaEmpleados));

    printf("\nSe cargan empleados por archivos\n");
    controller_loadFromText("data.csv", listaEmpleados);

    printf("\nFuncion ll_isEmpty --> Se valida la cargar de empleados en la lista\n");
    if(!ll_isEmpty(listaEmpleados))
        {
            controller_ListEmployee(listaEmpleados);
        }


    printf("\nFuncion ll_add --> Se agrega un elemento en la lista\n");

    Employee* pEmpleado;
    pEmpleado = employee_new( );
    ll_add(listaEmpleados,pEmpleado);

    controller_ListEmployee(listaEmpleados);


    printf("\nFuncion ll_set --> Se sobrescriben los datos del elemento agregado.\nPara esto, tambien se utiliza ll_get y ll_indexOf\n");

    int index =ll_indexOf(listaEmpleados, pEmpleado);

    char nombre2[]= "Prueba";
    Employee* pEmpleado2;
    pEmpleado2 = employee_new( );
    employee_setId(pEmpleado2, 11);
    employee_setNombre(pEmpleado2, nombre2);
    employee_setHorasTrabajadas(pEmpleado2, 50);
    employee_setSueldo(pEmpleado2, 90000);
    employee_delete(pEmpleado);

    ll_set(listaEmpleados, index, pEmpleado2);

    if(ll_get(listaEmpleados, index) == pEmpleado2)
        {
            printf("\nEl elemento se sobrescribio:");
        }
    controller_ListEmployee(listaEmpleados);

    printf("\nFuncion ll_pop --> Se da de baja\n");
    Employee* pElemento = ll_pop(listaEmpleados,6);

    printf("Luego de la baja");
    controller_ListEmployee(listaEmpleados);

    printf("\nFuncion ll_push --> Se reversa la baja\n");
    ll_push(listaEmpleados, 6, pElemento);
    printf("\nFuncion: ll_contains - Luego del reverso de la baja, verifico si está dentro de la lista\n");
    if(ll_contains(listaEmpleados, pElemento))
        {
            printf("Reverso de baja exitosa\n");
        }


    printf("\nFuncion: ll_clone - Se clona la lista de empleados\n");
    LinkedList* listaEmpleadosCopy;
    listaEmpleadosCopy = ll_clone(listaEmpleados);
    if(!ll_isEmpty(listaEmpleadosCopy))
    {
        controller_ListEmployee(listaEmpleadosCopy);
    }

    printf("Funcion: ll_containsAll - Se valida que la lista de empleados y la lista clonada sean iguales\n");
    if(ll_containsAll(listaEmpleados,listaEmpleadosCopy))
    {
        printf("Por lo tanto las listas son iguales.\n");
    }

    printf("\nFuncion: ll_sort - Ordeno la lista de empleados por id\n");
    ll_sort(listaEmpleados, employee_OrdenarPorId,0);
    controller_ListEmployee(listaEmpleados);

    printf("\nFuncion: ll_subList - Creo una sublista con los ultimos 5 ingresos\n");
    LinkedList* listaEmpleadosSub;
    listaEmpleadosSub = ll_subList(listaEmpleados,0,4);
    controller_ListEmployee(listaEmpleadosSub);


    printf("\nFuncion ll_remove --> Se elimina el ultimo elemento de la lista\n");
    index =ll_indexOf(listaEmpleados, pEmpleado2);
    employee_delete(pEmpleado2);
    ll_remove(listaEmpleados,index);
    controller_ListEmployee(listaEmpleados);


    printf("\nFuncion ll_clean\n");
    ll_clear(listaEmpleados);

    printf("\nFuncion ll_delete\n");
    ll_deleteLinkedList(listaEmpleados);
    ll_deleteLinkedList(listaEmpleadosCopy);
    ll_deleteLinkedList(listaEmpleadosSub);



    return 0;
}

































