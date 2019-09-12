#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Goffredo.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        switch(option = menuOpciones("Cargar los datos de los empleados desde el archivo data.csv (modo texto).",
                            "Cargar los datos de los empleados desde el archivo data.csv (modo binario).",
                            "Alta de empleado.",
                            "Modificar datos de empleado.",
                            "Baja de empleado.",
                            "Listar empleados.",
                            "Ordenar empleados.",
                            "Guardar los datos de los empleados en el archivo data.csv. (Texto)",
                            "Guardar los datos de los empleados en el archivo data.csv. (Binarios)",
                            "Salir.\n"))
        {
            case 1:
                controller_loadFromText("./data.csv", listaEmpleados);
                system("pause");
                break;

            case 2:
                controller_loadFromBinary("./data.bin", listaEmpleados);
                system("pause");
                break;

            case 3:
                controller_addEmployee(listaEmpleados);
                system("pause");
                break;

            case 4:
                controller_editEmployee(listaEmpleados);
                system("pause");
                break;

            case 5:
                controller_removeEmployee(listaEmpleados);
                system("pause");
                break;

            case 6:
                controller_ListEmployee(listaEmpleados);
                system("pause");

                break;

            case 7:
                controller_sortEmployee(listaEmpleados);
                system("pause");
                break;

            case 8:
                controller_saveAsText("data.csv", listaEmpleados);
                system("pause");
                break;

            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                system("pause");
                break;
            case 10:
                break;
            default:
                printf("- %d - No es una opcion valida\n", option);
                system("pause");
                break;
        }
    }while(option != 10);

    /*Employee* emp1 = employee_newParametros("1111", "Juan", "234", "25000");
    Employee* emp2 = employee_newParametros("2222", "Julia", "100", "15000");
    Employee* emp3 = employee_newParametros("3333", "Juana", "335", "35000");
    Employee* emp4 = employee_newParametros("4444", "Sofia", "435", "55000");
    Employee* emp5 = employee_newParametros("4443", "Sofiss", "435", "515000");


    printf("Cantidad elementos: %d\n\n", ll_len(listaEmpleados));

    if (ll_add(listaEmpleados, emp1) == 0)
    {
        printf("Se a agregado exitosamente a la lista\n\n");
    }

    if (ll_add(listaEmpleados, emp2) == 0)
    {
        printf("Se a agregado exitosamente a la lista\n\n");
    }

    if (ll_add(listaEmpleados, emp3) == 0)
    {
        printf("Se a agregado exitosamente a la lista\n\n");
    }
    if (ll_add(listaEmpleados, emp5) == 0)
    {
        printf("Se a agregado exitosamente a la lista\n\n");
    }


    if(ll_push(listaEmpleados, 1 , emp4))

    mostrarEmpleado((Employee*) ll_get(listaEmpleados,2));

    if(ll_set(listaEmpleados, 1 , emp4) == 0)
    {
        printf("Se seteo con exito");
    }

        printf("Cantidad elementos: %d\n\n", ll_len(listaEmpleados));

        mostrarEmpleado((Employee*) ll_get(listaEmpleados,1));
        mostrarEmpleado((Employee*) ll_get(listaEmpleados,2));

        printf("--------------------------------------------------------------------------\n\n\n");


        for(int i = 0; i < ll_len(listaEmpleados); i++)
        {
            mostrarEmpleado((Employee*) ll_get(listaEmpleados,i));
        }

printf("Ordeno la lista por sueldo\n\n");
ll_sort(listaEmpleados, ordenarPorSueldo, 0);

 for(int i = 0; i < ll_len(listaEmpleados); i++)
        {
            mostrarEmpleado((Employee*) ll_get(listaEmpleados, i));
        }*/

    return 0;
}
