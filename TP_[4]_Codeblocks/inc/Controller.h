

/** \brief Obtiene el path para cargar los datos desde archivo .csv y en caso que existan
 *          datos se confirma si se sobrescriben. Luego de cargar los datos actualiza
 *              el mayor Id.
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \param int* maxId puntero a id.
 * \return (0) ERROR y (1) EXITO
 *
 */
int controller_loadFromTextInit(LinkedList* pArrayListEmployee, int* maxId);


/**
 * \brief Carga los datos de los empleados desde el archivo que recibe como parametro (modo texto).
 * \param path char* ruta del archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (0) ERROR - Si el puntero a LikedList es NULL o la ruta es invalida, (1) EXITO
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);


/** \brief Obtiene el path para cargar los datos desde archivo .bin y en caso que existan
 *          datos se confirma si se sobrescriben. Luego de cargar los datos actualiza
 *              el mayor Id.
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \param int* maxId puntero a id.
 * \return (0) ERROR y (1) EXITO
 *
 */
int controller_loadFromBinaryInit(LinkedList* pArrayListEmployee, int* maxId);


/**
 * \brief Carga los datos de los empleados desde el archivo que recibe como parametro (modo binario).
 * \param path char* ruta del archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (0) ERROR - Si el puntero a LikedList es NULL o la ruta es invalida, (1) EXITO
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);


/**
 * \brief Gestiona el alta solicitando los datos al usuario y agregandolo al array
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (0) ERROR / (1) EXITO
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int Return (0) ERROR / (1) EXITO
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);


/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (0) error - (1) exito
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);


/** \brief Imprime los datos de un empleado
 *
 * \param puntero al array de empleados
 * \param indice del empleado a imprimir
 * \return retorno (0) ERROR - Si el puntero a LikedList es NULL o el indice es invalido
 *				   (1) EXITO
 *
 */
int controller_imprimirUnEmpleado(LinkedList* pArrayListEmployee, int index);


/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int (0) error - (1) exito
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);


/** \brief Obtiene el path para guardar los datos a un archivo .csv y en caso que existan
 *          datos se confirma si se sobrescriben.
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return (0) ERROR y (1) EXITO
 *
 */
int controller_saveAsText_Init(LinkedList* pArrayListEmployee);


/**
 * \brief Guarda los datos de los empleados desde el archivo que recibe como parametro (modo texto).
 * \param path char* ruta del archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (1) EXITO - (0) ERROR
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);


/** \brief Obtiene el path para guardar los datos a un archivo .bin y en caso que existan
 *          datos se confirma si se sobrescriben.
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return (0) ERROR y (1) EXITO
 *
 */
int controller_saveAsBinary_Init(LinkedList* pArrayListEmployee);


/**
 * \brief Guarda los datos de los empleados desde el archivo que recibe como parametro (modo binario).
 * \param path char* ruta del archivo a cargar
 * \param pArrayListEmployee LinkedList* puntero al array de empleados
 * \return int Return (1) EXITO - (0) ERROR
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


