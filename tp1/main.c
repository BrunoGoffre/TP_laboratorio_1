#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Goffredo.h"

int main()
{
    int operando1=0;
    int operando2=0;
    int flagA = 0;
    int flagB = 0;
    int flagC = 0;
    int sumaMain;
    int restaMain;
    int multiplicacionMain;
    float divicionMain;
    double factorialMainA;
    double factorialMainB;
    char seguir = 's';


    do
    {
        switch (menuAyB(flagA, flagB, operando1, operando2))
        {
        case 1:
            printf("\nIngrese el primer operando: ");
            scanf("%d", &operando1);
            flagA++;
            break;
        case 2:
            printf("\nIngrese el segundo operando: ");
            scanf("%d", &operando2);
            flagB++;
            break;
        case 3:
            if (flagA == 0 || flagB == 0)
            {
                printf("\nPorfavor ingrese los operandos.\n");
                break;
            }
            else
            {
                sumaMain = suma(operando1, operando2);
                restaMain = resta(operando1, operando2);
                multiplicacionMain = multiplicacion(operando1, operando2);
                if (operando2 == 0)
                {

                }else
                {
                    divicionMain = divicion(operando1, operando2);
                }
                factorialMainA = factorializacion(operando1);
                factorialMainB = factorializacion(operando2);
                printf("\nLas operaciones fueron calculadas.\n");
                flagC++;
                break;
            }
        case 4:
            if (flagC == 0)
            {
                printf("Porfavor primero calcule las operaciones.\n");
                break;
            }
            printf("\nLos resultados de las operacion son: \n\n");
            printf("Suma = %d\n", sumaMain);
            printf("Resta = %d\n", restaMain);
            printf("Multiplicacion = %d\n", multiplicacionMain);
            if (operando2 == 0)
            {
                printf("Divicion = Error, no se puede dividir por 0.\n");
            }else
            {
                printf("Divicion = %.2f\n", divicionMain);
            }

            if (factorialMainA == -1)
            {
                printf("Factorial A = No se puede calcular el factorial de un numero negativo.\n");
            }
            else
            {
                printf("Factorial A = %.0f\n", factorialMainA);
            }
            if (factorialMainB == -1)
            {
                printf("Factorial B = No se puede calcular el factorial de un numero negativo.\n");
            }
            else
            {
                printf("Factorial B = %.0f\n\n", factorialMainB);
            }


            break;
        case 5:
            seguir = 'n';
            printf("\n");
            break;
        default:
            printf("\nOpcion invalida.\n");
            break;
        }
        printf ("\nPresione una tecla para continuar");
        getch();
    }
    while (seguir == 's');
    return 0;
}



















