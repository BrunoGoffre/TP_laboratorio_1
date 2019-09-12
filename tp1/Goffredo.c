#include <stdio.h>
#include <stdlib.h>

int obtenerMaximo(int x, int y, int z)
{
    int mayor;
    if (x > y && x > y)
    {
        mayor = x;
    }
    else if (y >= x && y > z)
    {
        mayor = y;
    }
    else
    {
        mayor = z;
    }

    return mayor;
}

int mostrarMenu()
{
    int opcion;

    system("cls"); //Limpia la pantalla
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificaciones\n");
    printf("4- Informes\n");
    printf("5- Salir\n");
    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int suma (int num1, int num2)
{
    int resultado;

    resultado = num1 + num2;

    return resultado;
}

int resta (int num1, int num2)
{
    int resultado;

    resultado = num1 - num2;

    return resultado;
}

float divicion (int num1, int num2)
{
    float resultado;

    resultado = (float) num1 / num2;

    return resultado;
}

int multiplicacion (int num1, int num2)
{
    int resultado;

    resultado = num1 * num2;

    return resultado;
}

double factorializacion (int num1)
{
    double factorial = 1;

    if (num1 == 0)
    {
        factorial = 1;
    }
    else if (num1 < 0)
    {
        factorial = -1;
    }
    else
    {
        for (int i = 1; i <= num1; i++)
        {
            factorial *= i;
        }

    }
    return factorial;
}

int menuAyB(int flag, int flagB, int x, int y)
{
    int opcion;

    system("cls");

    printf("      -- MENU PRINCIPAL --\n");
    if (flag == 0 )
    {
        printf("1- Ingresar 1er operando A = x\n");
    }
    else
    {
        printf("1- Ingresar 1er operando A = %d\n", x);
    }
    if (flagB == 0 )
    {
        printf("1- Ingresar 2do operando B = y\n");
    }
    else
    {
        printf("1- Ingresar 2do operando B = %d\n", y);
    }

    printf("3- Calcular todas las operaciones.\n");
    printf("4- Informar resultados.\n");
    printf("5- Salir.\n");
    printf("\n Elija un opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
