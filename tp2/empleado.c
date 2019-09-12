#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Goffredo.h"
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre [51];
    char apellido[51];
    float salario;
    int sector;
    int estado;

} eEmpleado;

void inicializarEmpleados(eEmpleado empleados[], int tamEmp)
{

    for(int i=0; i < tamEmp; i++)
    {
        empleados[i].estado = 0;
    }
}

int buscarVacio (eEmpleado empleados[], int tamEmp)
{
    int indice = -1;

    for (int i = 0; i < tamEmp; i++)
    {
        if (empleados[i].estado == 0)
        {
            indice = i;
            break;
        }

    }
    return indice;
}

void altaEmpleados (eEmpleado empleados[], int tamEmp, int *id, int *flag)
{
    int indice;
    char auxSalario[256];
    char auxSector[256];

    *id = *id + 1;

    indice = buscarVacio(empleados, tamEmp);

    if( indice == -1)
    {
        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        if (getStringLetras("Ingrese nombre: ", empleados[indice].nombre) == 0)
        {
            printf("No se pudo cargar el nombre. Ingrese solo letras.\n");

        }
        else if (getStringLetras("Ingrese apellido: ", empleados[indice].apellido) == 0)
        {
            printf("No se pudo cargar el apellido. Ingrese solo letras.\n");
        }
        else if (getStringNumeros("Ingrese sueldo: ", auxSalario) == 0)
        {
            printf("No se pudo cargar el salario, ingrese solo numeros.\n");
        }
        else if (getStringNumeros("Ingrese numero de sector: ", auxSector) == 0)
        {
            printf("No se pudo cargar el sueldo, Ingrese solo numeros.\n");
        }
        else
        {
            empleados[indice].salario = atof(auxSalario);
            empleados[indice].sector = atoi(auxSector);

            empleados[indice].id = *id;

            empleados[indice].estado = 1;

            *flag += 1;

            printf("\nAlta empleado exitosa!!!\n\n");
        }

    }
}


void listarEmpleado(eEmpleado empleado)
{
    printf("%-10d %-10s   %-10s  %.3f       %-10d \n\n",empleado.id ,empleado.apellido, empleado.nombre, empleado.salario, empleado.sector);
}

void listarEmpleados (eEmpleado empleados[], int tamEmp)
{
    printf("\n");
    printf("Legajo     Apellido    Nombre      Salario     Sector\n");
    printf("------     --------    ------      -------     ------\n\n");
    for (int i = 0; i < tamEmp; i++)
    {
        if (empleados[i].estado == 1)
        {
            listarEmpleado(empleados[i]);
        }

    }
}

void ordenarAlfabeticamenteEmpleados(eEmpleado empleados[], int tamEmp)
{
    eEmpleado auxEmpleado;

    for (int i = 0; i < tamEmp-1; i++)
    {
        for (int j = i+1; j < tamEmp; j++)
        {
            if (strcmp(empleados[i].apellido, empleados[j].apellido) > 0)
            {
                auxEmpleado = empleados[i];
                empleados[i] = empleados[j];
                empleados[j] = auxEmpleado;
            }
        }
    }
}

float promedioSalariosEmpleados (eEmpleado empleados[], int tamEmp)
{
    int contadorPromedio = 0;
    float acumulador = 0;
    float promedio;

    for (int i = 0; i < tamEmp; i++)
    {
        if (empleados[i].estado == 1)
        {
            acumulador += empleados[i].salario;
            contadorPromedio++;
        }
    }

    promedio = (acumulador / contadorPromedio);

    printf("\nEl promedio de sueldos es: %.3f\n", promedio);

    return promedio;
}

void empleadosMejorPagos (eEmpleado empleados[], int tamEmp, float sueldoPromedio)
{
    int contadorSueldosAltos = 0;

    for (int i = 0; i < tamEmp; i++)
    {
        if (empleados[i].estado == 1 && empleados[i].salario > sueldoPromedio)
        {
            contadorSueldosAltos++;
        }
    }

    printf("\nLa cantidad de empleados pagados sobre el promedio es: %d\n\n", contadorSueldosAltos);
}

int buscarEmpleado(eEmpleado empleados[], int tamEmp, int legajo)
{

    int indice = -1;

    for(int i=0; i < tamEmp; i++)
    {
        if(empleados[i].estado == 1 && empleados[i].id == legajo)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void modificarEmpleado (eEmpleado empleados[], int tamEmp)
{
    int legajo;
    int indice;
    char auxSalario[256];
    char auxSector[256];
    char auxLegajo[256];

    if (getStringNumeros("Ingrese legajo que desea modificar: ", auxLegajo) == 0)
    {
        indice = -1;
    }
    else
    {
         legajo = atoi(auxLegajo);
         indice = buscarEmpleado(empleados, tamEmp, legajo);
    }


    if (indice == -1)
    {
        printf("\nEl legajo ingresado no existe.\n\n");
    }
    else
    {
        if (getStringLetras("Ingrese nombre: ", empleados[indice].nombre) == 0)
        {
            printf("No se pudo cargar el nombre. Ingrese solo letras.\n");

        }
        else if (getStringLetras("Ingrese apellido: ", empleados[indice].apellido) == 0)
        {
            printf("No se pudo cargar el apellido. Ingrese solo letras.\n");
        }
        else if (getStringNumeros("Ingrese sueldo: ", auxSalario) == 0)
        {
            printf("No se pudo cargar el salario, ingrese solo numeros.\n");
        }
        else if (getStringNumeros("Ingrese numero de sector: ", auxSector) == 0)
        {
            printf("No se pudo cargar el sueldo, Ingrese solo numeros.\n");
        }
        else
        {
            empleados[indice].salario = atof(auxSalario);
            empleados[indice].sector = atof(auxSector);
            printf("\nEmpleado modificado con exito\n");
        }
    }
}


void bajaEmpleado(eEmpleado empleados[], int tamEmp)
{
    int legajo;
    int indice;
    char respuesta;
    char auxLegajo[256];

    if (getStringNumeros("Ingrese el legajo que desea dar de baja: ", auxLegajo) == 0)
    {
        printf("Ingrese solo numeros.\n");
    }
    else
    {
        legajo = atoi(auxLegajo);

        indice = buscarEmpleado(empleados, tamEmp, legajo);

        if (indice == -1)
        {
            printf("\nEl empleado ingresado no existe.\n\n");
        }
        else
        {
            printf("\n");
            listarEmpleado(empleados[indice]);
            printf("\nConfirmar baja (s/n): ");
            fflush(stdin);
            scanf("%c", &respuesta);

            if(respuesta == 's')
            {
                empleados[indice].estado = 0;
                printf("Empleado dado de baja con exito\n");
            }
            else
            {
                printf("\nDada de baja cancelada\n.");
            }
        }
    }



}

int menuOpcionesABM()
{
    int opcion;

    system("cls");
    printf("  *** ABM Empleados ***\n\n");
    printf("1- Altas\n");
    printf("2- Modificaciones\n");
    printf("3- Bajas\n");
    printf("4- Informar\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}
