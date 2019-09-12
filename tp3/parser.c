#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    Employee* auxEmp;
    int cant;
    int isOk = 0;
    char buffer[4][50];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        while( !feof(pFile))
        {
            cant =  fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if(cant < 4)
            {
                if( feof(pFile))
                {
                    isOk = 1;
                    break;
                }else
                {
                    break;
                }
            }

            auxEmp = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

            if (auxEmp != NULL)
            {
                ll_add(pArrayListEmployee, auxEmp);
            }
        }
    }
    return isOk;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxEmp = NULL;
    int cant;
    int isOk = 0;

    if (pFile != NULL && pArrayListEmployee != NULL)
    {
        while( !feof(pFile))
        {
            auxEmp = employee_new();
            if (auxEmp != NULL)
            {
                cant = fread(auxEmp , sizeof(Employee), 1, pFile);

                if(cant != 1)
                {
                    if (!feof(pFile))
                    {
                        printf("Error al cargar datos\n");
                    }
                    else
                    {
                        isOk = 1;
                        break;
                    }
                }
                else
                {
                    ll_add(pArrayListEmployee, auxEmp);
                }
            }
        }
    }
    return isOk;
}
