#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "empleado.h"
#include "Goffredo.h"

#define TAMEMP 1000

int main()
{
    char salir = 's';
    char confirma;
    int id = 100;
    int flag = 0;
    float promedio;

    eEmpleado empleados[TAMEMP];

    inicializarEmpleados(empleados, TAMEMP);


    do
    {
        switch (menuOpcionesABM())
        {
        case 1:
            altaEmpleados(empleados, TAMEMP, &id, &flag);
            system("pause");
            break;
        case 2:
            if (flag == 0)
            {
                printf("\nError, porfavor ingrese un empleado\n\n.");
                system("pause");
            }
            else
            {
                modificarEmpleado(empleados, TAMEMP);
                system("pause");
            }
            break;
        case 3:
            if (flag == 0)
            {
                printf("\nError, porfavor ingrese un empleado\n\n.");
                system("pause");
            }
            else
            {
                bajaEmpleado(empleados, TAMEMP);
                system("pause");
            }
            break;
        case 4:
            if (flag == 0)
            {
                printf("\nError, porfavor ingrese un empleado.\n\n");
                system("pause");
            }
            else
            {
                ordenarAlfabeticamenteEmpleados(empleados, TAMEMP);
                listarEmpleados(empleados, TAMEMP);
                promedio = promedioSalariosEmpleados(empleados, TAMEMP);
                empleadosMejorPagos(empleados, TAMEMP, promedio);
                system("pause");
            }
            break;
        case 5:
            printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();
            while (confirma != 's' && confirma != 'n')
            {
                printf("\nReingrese su respuesta s/n?: ");
                fflush(stdin);
                confirma = getche();
            }
            if( tolower(confirma) == 's')
                {
                    salir = 'n';
                }

            break;
        default:
            printf("\nError. Ingrese una opcion valida\n\n");
            system("pause");
            break;
        }
    }
    while (salir == 's');
    return 0;
}

