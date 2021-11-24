#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief Solicita espacio en memoria para un nuevo empleado e incializa los valores
 *
 * \param No aplica
 * \return Retorna puntero de tipo Employee* si obtuvo lugar o NULL en caso contrario
 *
 */
Employee* employee_new();


/** \brief Solicita espacio en memoria para un nuevo empleado y le asigna los valores que recibe por parametro
 *
 * \param Id a asignar
 * \param Nombre a asignar
 * \param Horas trabajadas a asignar
 * \param Sueldo a asignar
 * \return Retorna puntero de tipo Employee* si obtuvo lugar o NULL en caso contrario
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);


/**
 * \brief Libera espacio de memoria de un empleado (free)
 * \param this Employee* puntero a empleado
 * \return void
 */
void employee_delete(Employee* this);


/**
 * \brief Carga el id en el campo del empleado
 * \param  puntero a empleado
 * \param id a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a Employee* es NULL o si el id no es valido
 *
 */
int employee_setId(Employee* this,int id);


/**
 * \brief Obtiene el id
 * \param  puntero a empleado
 * \param  puntero al espacio donde guarda el id obtenido
 * \return (1) EXITO - (0) ERROR - Si el puntero a Employee* es NULL o si e puntero al id es NULL
 *
 */
int employee_getId(Employee* this,int* id);


/**
 * \brief Carga el nombre del empleado
 * \param  puntero a empleado
 * \param puntero al nombre a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a Employee* es NULL o si e puntero al nombre es NULL
 *
 */
int employee_setNombre(Employee* this,char* nombre);


/**
 * \brief Obtiene el nombre del empleado
 * \param  puntero a empleado
 * \param puntero al nombre a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a Employee* es NULL o si e puntero al nombre es NULL
 *
 */
int employee_getNombre(Employee* this,char* nombre);


/**
 * \brief Carga las horas trabajadas del empleado
 * \param  puntero a empleado
 * \param horas trabajadas a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a Employee* es NULL o si e puntero al nombre es NULL
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/**
 * \brief Obtiene las horas trabajadas del empleado
 * \param  puntero a empleado
 * \param puntero horas trabajadas
 * \return (1) EXITO - (0) ERROR - Si el puntero a Employee* es NULL o si e puntero al nombre es NULL
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


/**
 * \brief Carga el sueldo del empleado
 * \param  puntero a empleado
 * \param sueldo a cargar
 * \return (1) EXITO - (0) ERROR - Si el puntero a Employee* es NULL o si e puntero al nombre es NULL
 *
 */
int employee_setSueldo(Employee* this,int sueldo);


/**
 * \brief Obtiene el sueldo del empleado
 * \param  puntero a empleado
 * \param puntero a sueldo
 * \return (1) EXITO - (0) ERROR - Si el puntero a Employee* es NULL o si e puntero al nombre es NULL
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);


/**
 * \brief Compara los nombres de dos empleados
 * \param void* puntero al primer empleado a comparar
 * \param void* puntero al segundo empleado a comparar
 * \return int Return
 * 					  (-1) Si el nombre del primer empleado es menor al segundo
 * 					   (1) Si el nombre del primer empleado es mayor al segundo
 * 					   (0) Si los nombres son iguales
 */
int employee_OrdenarPorNombre(void *nombreUno, void *nombreDos);


/**
 * \brief Compara los horas trabajadas de dos empleados
 * \param void* puntero al primer empleado a comparar
 * \param void* puntero al segundo empleado a comparar
 * \return int Return
 * 					  (-1) Si las horas del primer trabajador es menor a las del segundo
 * 					   (1) Si las horas del primer trabajador es mayor a las del segundo
 * 					   (0) Si los nombres son iguales
 */
int employee_OrdenarPorHoras(void *horas_Uno, void *horas_Dos);


/**
 * \brief Compara los sueldos de dos empleados
 * \param void* puntero al primer empleado a comparar
 * \param void* puntero al segundo empleado a comparar
 * \return int Return
 * 					  (-1) Si el sueldo del primer trabajador es menor a las del segundo
 * 					   (1) Si el sueldo del primer trabajador es mayor a las del segundo
 * 					   (0) Si los nombres son iguales
 */
int employee_OrdenarPorsueldo(void *sueldo_Uno, void *sueldo_Dos);


/**
 * \brief Compara los ids de dos empleados
 * \param void* puntero al primer empleado a comparar
 * \param void* puntero al segundo empleado a comparar
 * \return int Return
 * 					  (-1) Si el id del primer trabajador es menor al del segundo
 * 					   (1) Si el id del primer trabajador es mayor al del segundo
 * 					   (0) Si los nombres son iguales
 */
int employee_OrdenarPorId(void *id_Uno, void *id_Dos);

#endif // employee_H_INCLUDED
