/*
 * ArrayEmployee.h
 *
 *  Created on:
 *      Author: luclopez
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NAME_LEN 51
#define LAST_NAME_LEN 51

typedef struct
{
    int id;
    char name[NAME_LEN];
    char lastName[LAST_NAME_LEN];
    float salary;
    int sector;
    int isEmpty;
}Employee;



/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initEmployees(Employee* list, int len);


/** \brief Validate if exists any active hire ( isEmpty == 0)
*
* \param list Employee*
* \param len int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
 int isData(Employee* list, int len);


/**
 * \brief To search first available index in array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (index) if Ok
 *
 */
int getEmptyIndex(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief Manage hiring process from getting data to add employee record
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param int * pId pointer to the address of 'Id'
 * \param int retries Number of reties allowed
 * \param float lowest limit for wage amount
 * \param float higgest limit for wage amount
 * \param int sectorFrom from sector (lowest number)
 * \param int sectorTo to sector (higgest number)
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int hireEmployee(Employee* list, int len, int *pId, int retries, float minSalary, float maxSalary, int sectorFrom, int sectorTo);


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);


 /** \brief Print the content of  an employee
 *
 * \param list Employee*
 * \param int i Employee list index
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
int printEmployee(Employee* list, int i);


/** \brief Manage updating process from getting data to modify employee record (name, last name, salary or sector)
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param int retries Number of reties allowed
 * \param int sectorFrom from sector (lowest number)
 * \param int sectorTo to sector (higgest number)
 * \param int lowest limit for Id
 * \param int higgest limit for Id
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int updateEmployeeById(Employee* list, int len, int retries, int sectorFrom, int sectorTo, int minId, int maxId);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);


/** \brief Manage termination process from getting data to the execution of termination
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param int lowest limit for Id
 * \param int higgest limit for Id
 * \param int retries Number of retries allowed
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int terminateEmployeeById(Employee* list, int len, int minId, int maxId, int retries);


/** \brief Calculate the sum of wages, its average and quantity of employees
 *          over average wage
 * \param list Employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int calculateSalaryAverage(Employee* list, int length);


/** \brief Sort the elements in the array of employees, the argument order
* indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(Employee* list, int length);

/** \brief To report the list active employees by order criteria indicated by user and salary calculations
 *
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param int retries Number of reties allowed
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int reportEmployees(Employee * list, int len, int retries);


#endif /* ARRAYEMPLOYEES_H_ */
