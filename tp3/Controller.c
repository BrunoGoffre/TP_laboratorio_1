#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int resultado;
    FILE* f = fopen(path, "r");

    if (f != NULL && pArrayListEmployee != NULL)
    {
       resultado = parser_EmployeeFromText(f, pArrayListEmployee);

       if (resultado != 1 )
       {
           printf("Problemas para leer el archivo.\n");
       }else
       {
           printf("\n\nCarga Exitosa.\n\n");
       }
    }

    fclose(f);


    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int resultado;
    FILE* f = fopen(path, "rb");

    if (f != NULL && pArrayListEmployee != NULL)
    {
       resultado = parser_EmployeeFromBinary(f, pArrayListEmployee);
       if (resultado != 1 )
       {
           printf("Problemas para leer el archivo.\n");
       }else
       {
           printf("\n\nCarga Exitosa.\n\n");
       }
    }

    fclose(f);

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    if (altaEmpleado(pArrayListEmployee) != 1)
    {
        printf("No se pudo dar de alta.\n\n");
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int resultado = modificarEmpleado(pArrayListEmployee);
    if ( resultado == 0)
    {
        printf("ID inexistente\n\n");
    }
    else
    {
        printf("Moficacion Exitosa\n");
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int resultado = bajaEmpleado(pArrayListEmployee);

    if ( resultado == 0)
    {
        printf("No se pudo dar de baja.\n\n");
    }
    else if (resultado == -1)
    {
        printf("ID inexistente\n");
    }
    else
    {
        printf("Baja exitosa\n");
    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if (mostrarEmpleados(pArrayListEmployee) == 0)
        {
            printf("\nNo hay empleados para mostrar.\n\n");
        }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    ordenarEmpleados(pArrayListEmployee);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int auxReturn = 0;
    int cant = 0;
    Employee* auxEmp = NULL;
    FILE* f = fopen(path, "w");

    if (f != NULL && pArrayListEmployee != NULL)
    {
        fprintf(f,"%s, %s, %s, %s\n", "ID", "Nombre", "HorasTrabajadas", "Sueldo");
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            if ((auxEmp = ll_get(pArrayListEmployee, i)) != NULL)
            {
               fprintf(f,"%d,%s,%d,%d\n", auxEmp->id,
                                           auxEmp->nombre,
                                            auxEmp->horasTrabajadas,
                                             auxEmp->sueldo);
                cant++;
            }
        }
        if(cant == ll_len(pArrayListEmployee))
        {
            printf("Archivo guardado con exito\n");
            auxReturn = 1;
        }else
        {
            printf("Hubo problemas para guardar algunos datos\n");
        }
    }else
    {
        printf("\nProblemas para guardar el archivo.\n");
    }
 fclose(f);
    return auxReturn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int auxReturn = 0;
    int cant = 0;
    Employee* auxEmp = NULL;
    FILE* f = fopen(path, "wb");

    if (f != NULL && pArrayListEmployee != NULL && ll_len(pArrayListEmployee) > 0)
    {
        //fwrite(auxEmp, (sizeof(char)*4) , 1 ,f);
        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmp =(Employee*) ll_get(pArrayListEmployee, i);
            if (auxEmp != NULL)
            {
              fwrite(auxEmp, sizeof(Employee), 1 ,f);
               cant++;
            }
        }
        fclose(f);
        if(cant == ll_len(pArrayListEmployee))
        {
            printf("Archivo guardado con exito\n");
            auxReturn = 1;
        }else
        {
            printf("Hubo problemas para guardar algunos datos\n");
        }
    }else
    {
        printf("\nProblemas para guardar el archivo.\n");
    }

    return auxReturn;

    return 1;
}

