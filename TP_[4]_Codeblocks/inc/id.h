#ifndef ID_H_INCLUDED
#define ID_H_INCLUDED

/** \brief Busca el mayor valor y lo guarda en puntero a id
 *
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \param int* puntero a Id
 * \return (0) Error y (1) Exito
 *
 */

int buscarMayorId(LinkedList* pArrayListEmployee, int* pId);


/** \brief Guarda el id en el archivo 'ultimoID.txt
 *
 * \param int id
 * \return (0) Error y (1) Exito
 *
 */
int guardarId(int id);


/** \brief Obtiene el ultimo id guardado desde archivo (ultimoID.txt).
 *
 * \param puntero a id para poder grabar el valor
 *
 * \return Retorna 0 en caso de error, 1 en caso de exito.
 *
 */
int obtenerId(int* id);


/** \brief Actualiza el ultimo id en archivo (ultimoID.txt).
 *
 * \param id a incrementar
 *
 * \return Retorna 0 en caso de error, 1 en caso de exito.
 *
 */
int actualizarId(int id);


/**
 * \brief Busca un empleado por id
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \param id int id buscado
 * \return int Return Indice encontrado(-1) ERROR - Si el puntero a
 *         LikedList es NULL,o id invalido o empleado no encontrado
 */
int buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int id);

#endif // ID_H_INCLUDED
