#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED


/** \brief Parsea los datos los datos de los empleados desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna (0) si hubo error [puntero nulo] - (1) exito.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


/** \brief Parsea los datos los datos de los empleados desde el archivo .bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna (0) si hubo error [puntero nulo] - (1) exito.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


/**
 * \brief Parsea los datos de los empleados al archivo .csv(modo texto).
 * \param pFile FILE* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (1) EXITO (0) ERROR - Si el puntero a LikedList es NULL o la ruta es invalida.
 *
 *
 */
int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee);


/**
 * \brief Parsea los datos de los empleados al archivo .bin (modo binario).
 * \param pFile FILE* puntero al archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (1) EXITO (0) ERROR - Si el puntero a LikedList es NULL o la ruta es invalida.
 *
 *
 */
int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif // PARSER_H_INCLUDED
