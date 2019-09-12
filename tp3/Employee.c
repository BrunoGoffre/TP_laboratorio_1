#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "string.h"
#include "Goffredo.h"


/** \brief establece la id al empleado
 *
 * \param puntero a estructura empleado
 * \param id a asignar
 * \return entero 1 si se ejecuto correctamente 0 si no.
 */

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;

    if ( this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief consigue la id del empleado que se le pasa y la devuelve por el puntero a entero.
 *
 * \param puntero a empleado
 * \param puntero a entero
 * \return 1 si todo salio bien 0 si no.
 *
 */

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;

    if ( this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief establece el nombre del empleado
 *
 * \param puntero a empleado
 * \param puntero a char
 * \return 1 si todo salio bien 0 si no
 *
 */

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && strlen(nombre) >= 3 && nombre != NULL)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }

    return todoOk;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && strlen(nombre) >= 3 && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if ( this != NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if ( this != NULL && horasTrabajadas > 0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;

    if ( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;

    if ( this != NULL && sueldo > 0)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

Employee* employee_new()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    if (this != NULL)
    {
        employee_setId(this, 0);
        employee_setNombre(this, " ");
        employee_setHorasTrabajadas(this, 0);
        employee_setSueldo(this,0);
        /*this->id = 0;
        strcpy(this->nombre, " ");
        this->horasTrabajadas = 0;
        this->sueldo = 0;*/
    }
    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this;

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        this = employee_new();
        if(this != NULL)
        {
            if (!employee_setId(this, atoi(idStr))||
                    (!employee_setNombre(this, nombreStr)||
                     (!employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr))||
                      (!employee_setSueldo(this, atoi(sueldoStr))))))
            {
                free(this);
                this = NULL;
            }
        }
    }
    return this;
}

void mostrarEmpleado(Employee* emp)
{
    printf("%-10d %-15s %-20d %-10d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
}

int mostrarEmpleados(LinkedList* this)
{
    int contador = 0;
    if (this != NULL)
    {
        printf("\n\n ID      Nombre      Horas trabajadas        Sueldo \n");
        printf(" --    ------        ----- ----------        ------ \n\n");
        for(int i = 0; i < ll_len(this); i++)
        {
            mostrarEmpleado((Employee*) ll_get(this,i));
            contador++;
        }
        printf("\n\n");

    }
    return contador;
}

int ordenarPorSueldo(void* emp1, void* emp2)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if (emp1 != NULL && emp2 != NULL)
    {

        p1 = (Employee*) emp1; // se le pone adelante el employee porque viene como puntero void
        p2 = (Employee*) emp2;

        if(p1->sueldo > p2->sueldo)
        {
            retorno = 1;
        }
        else if (p1->sueldo < p2->sueldo)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int ordenarPorHorasTrabajadas(void* emp1, void* emp2)
{

    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if (emp1 != NULL && emp2 != NULL)
    {

        p1 = (Employee*) emp1; // se le pone adelante el employee porque viene como puntero void
        p2 = (Employee*) emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas)
        {
            retorno = 1;
        }
        else if (p1->horasTrabajadas < p2->horasTrabajadas)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int ordenarPorNombre(void* emp1, void* emp2)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if (emp1 != NULL && emp2 != NULL)
    {

        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(strcmp(p1->nombre, p2->nombre) > 0)
        {
            retorno = 1;
        }
        else if (strcmp(p1->nombre, p2->nombre) < 0)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int ordenarPorId(void* emp1, void* emp2)
{
    int retorno = 0;
    Employee* p1;
    Employee* p2;

    if (emp1 != NULL && emp2 != NULL)
    {

        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;

        if(p1->id > p2->id)
        {
            retorno = 1;
        }
        else if (p1->id < p2->id)
        {
            retorno = -1;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}

int altaEmpleado(LinkedList* this)
{

    int todoOk = 0;
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];


    Employee* nuevoEmpleado = employee_new();

    if(nuevoEmpleado != NULL)
    {
        if(getStringNumeros("Ingrese ID: ", auxId) != 1)
        {
            printf("Error.\n");
        }
        else if (getStringLetras("Ingrese Nombre: ", auxNombre) != 1)
        {
            printf("Error.\n");
        }
        else if(getStringNumeros("Ingrese cantidad de horas trabajadas: ", auxHorasTrabajadas) != 1)
        {
            printf("Error.\n");
        }
        else if(getStringNumeros("Ingrese Sueldo: ", auxSueldo) != 1)
        {
            printf("Error.\n");
        }
        else
        {
            employee_setId(nuevoEmpleado, atoi(auxId));
            employee_setNombre(nuevoEmpleado, auxNombre);
            employee_setHorasTrabajadas(nuevoEmpleado, atoi(auxHorasTrabajadas));
            employee_setSueldo(nuevoEmpleado, atoi(auxSueldo));

            ll_add(this, nuevoEmpleado);

            printf("\nEmpleados agregado con exito.\n\n");

            todoOk = 1;
        }
    }

    return todoOk;
}

int modificarEmpleado(LinkedList* this)
{


    int todoOk = 0;
    Employee* empleado;
    char auxId[50];
    char auxNombre[50];
    char auxHorasTrabajadas[50];
    char auxSueldo[50];
    char respuesta;

    if(getStringNumeros("Ingres ID: ", auxId) == 1)
    {
        empleado = buscarPorId(this, ll_len(this),atoi(auxId));

        if ( empleado != NULL)
        {
            do
            {
                int opcion;
                switch(opcion = menuModificaciones("Nombre","Horas Trabajadas", "Sueldo", "Volver"))
                {
                case 1:
                    if (getStringLetras("Ingrese Nombre: ", auxNombre) == 1)
                    {
                        employee_setNombre(empleado, auxNombre);
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    system("pause");
                    break;
                case 2:
                    if(getStringNumeros("Ingrese cantidad de horas trabajadas: ", auxHorasTrabajadas) == 1)
                    {
                        employee_setHorasTrabajadas(empleado, atoi(auxHorasTrabajadas));
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    system("pause");
                    break;
                case 3:
                    if(getStringNumeros("Ingrese sueldo: ", auxSueldo) == 1)
                    {
                        employee_setSueldo(empleado, atoi(auxSueldo));
                    }
                    else
                    {
                        printf("Error.\n");
                    }
                    system("pause");
                    break;
                case 4:
                    respuesta = 's';
                    break;
                default:
                    printf("-%d- Esa opcion no es valida\n", opcion);
                    system("pause");
                    break;
                }
            }
            while(respuesta != 's');

            todoOk = 1;
        }

    }

    return todoOk;
}

Employee* buscarPorId (LinkedList* this, int tam, int id)
{
    Employee* empleado;

    for(int i = 0; i < tam; i++)
    {
        empleado = (Employee*) ll_get(this,i);
        if (empleado != NULL && empleado->id == id)
            return empleado;
    }
    empleado = NULL;

    return empleado;
}

int bajaEmpleado (LinkedList* this)
{
    Employee* auxEmp;
    int auxReturn = 0;
    int index;
    int id;
    char auxId[50];

    if(this != NULL)
    {
        if (getStringNumeros("Ingrese ID: ", auxId) == 1)
        {
            id = atoi(auxId);
            auxEmp = buscarPorId(this, ll_len(this),id);

            if (auxEmp != NULL)
            {
                index = ll_indexOf(this, auxEmp);
                ll_remove(this, index);
                auxReturn = 1;
            }
            else
            {
                auxReturn = -1;
            }
        }
        else
        {
            printf("Ingrese solo numeros.\n");
        }
    }

    return auxReturn;
}

int ordenarEmpleados(LinkedList* this)
{
    int resultado = 0;
    int option;
    int i;

    do
    {
        switch(option = menuModificaciones2("ID", "Nombre", "Horas Trabajadas","Sueldo", "Volver"))
        {
        case 1:
            printf("\n\n----Ordenes----\n");
            i = getInt("1.Ordenamiento ascendente.\n2.Ordenamiento descendentes.\n");
            if (i == 1)
            {
                ll_sort(this,ordenarPorId,0);
            }else if (i == 2)
            {
                ll_sort(this, ordenarPorId,1);
            }

            break;
        case 2:
            printf("\n\n----Ordenes----\n");
            i = getInt("1.Ordenamiento ascendente.\n2.Ordenamiento descendentes.\n");
            if (i == 1)
            {
                ll_sort(this,ordenarPorNombre,0);
            }else if (i == 2)
            {
                ll_sort(this, ordenarPorNombre,1);
            }
            break;
        case 3:
            printf("\n\n----Ordenes----\n");
            i = getInt("1.Ordenamiento ascendente.\n2.Ordenamiento descendentes.\n");
            if (i == 1)
            {
                ll_sort(this,ordenarPorHorasTrabajadas,0);
            }else if (i == 2)
            {
                ll_sort(this, ordenarPorHorasTrabajadas,1);
            }
            break;
        case 4:
            printf("\n\n----Ordenes----\n");
            i = getInt("1.Ordenamiento ascendente.\n2.Ordenamiento descendentes.\n");
            if (i == 1)
            {
                ll_sort(this,ordenarPorSueldo,0);
            }else if (i == 2)
            {
                ll_sort(this, ordenarPorSueldo,1);
            }
            break;
        case 5:

            break;
        default:
            printf("-- %d -- Opcion invalida.\n\n", option);
            system("pause");
            break;
        }
    }
    while (option != 5);

return resultado;
}




