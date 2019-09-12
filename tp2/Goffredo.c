#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[50];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int sector;
    int estado;
}eEmpleado;

/** \brief Sirve para obtener el entero maximo, recibe 3 enteros y dice cual es el mas grande.
 * \param Array enteros
 * \param entero 1
 * \return Retorna el entero que sea mas grande entre los 3.
 */
int obtenerMaximo(int array[], int tamEnteros)
{
    int mayor;
    int flag = 0;

    for (int i = 0; i < tamEnteros; i++)
    {
        if (flag == 0 || array[i] > mayor)
        {
            mayor = array[i];
            flag++;
        }
    }

    return mayor;
}

/** \brief Menu de opciones generico
 * \return Entero.
 */
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

/** \brief Calcula el factorial de un entero
 * \param Entero 1.
 * \param Entero 2.
 * \return Retorna Rta. double.
 */
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


void harcodeoDeVector (eEmpleado vec[], int tam)
{
    eEmpleado aux [] =
    {
        {1234, "Juan", 'm', 30000,{12,3,2000},5, 1},
        {2222, "Ana", 'f', 32000, {2,7,2010}, 2,1},
        {2211, "Jorge", 'm', 28000,{14,5,2013}, 2,1},
        {3241, "Alberto", 'm', 35000, {2,9,2010},1, 1},
        {8944, "Sonia", 'f', 39000, {12,3,2012},3,1},
        {2231, "Miguel", 'm', 29700, {28,7,2009}, 2,1},
        {6578, "Adrian", 'm', 43200, {11,1,2016},5, 1},
        {3425, "Lucia", 'f', 32300, {19,10,2004}, 2,1},
        {5546, "Gaston", 'm', 29760, {13,9,2006},4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 1},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,1},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,1},
        {7654, "Diego", 'm', 35000, {23,6,2010},1, 1},
        {9040, "Viviana", 'f', 47000,{18, 7,2011}, 1,1},
        {7439, "Gustavo", 'm', 25000, {12,12,2003}, 4,1}
    };

    for (int i = 0; i < tam; i++)
    {
        vec[i] = aux[i];
    }
}

/** \brief La funcion pide un numero y lo retorna como float
  * \return numero flotante.
 */

float getFloat (char mensaje[])
{
    float numero;

    printf("%s", mensaje);
    scanf("%f", &numero);

    return numero;
}


char getChar(char mensaje[])
{
    char letra;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letra);

    return letra;
}

int getInt (char mensaje[])
{
    int numero;

    printf("%s", mensaje);
    scanf("%d", &numero);

    return numero;
}

int menuOpciones (char opcion1[], char opcion2[], char opcion3[], char opcion4[], char opcion5[])
{
    int opcionElegida;

    system("cls");

    printf("1- %s\n", opcion1);
    printf("2- %s\n", opcion2);
    printf("3- %s\n", opcion3);
    printf("4- %s\n", opcion4);
    printf("5- %s\n", opcion5);

    printf("Elija una opcion: ");
    scanf("%d", &opcionElegida);

    return opcionElegida;
}

/** \brief verifica si el valor recibido es numerico.
 * \param  str Array con la cadena a ser analizada.
 * \return 1 si es numerico y 0 si no lo es.
 */

int esNumerico (char str[])
{
    int i = 0;
    while(str[i] != '\0')
    {
        if ((str[i] < '0' || str[i] > '9') && (str[i] != '.'))
        {
           return 0;
        }

        i++;
    }

    return 1;
}
/** \brief analiza una cadena de caracteres
 *
 * \param
 * \param
 * \return 1 si son solo letras (espacios y mayusculas tenidos en cuenta) y 0 si no son solo letras.
 */

int esSoloLetras (char str[])
{
     int i = 0;
    while(str[i] != '\0')
    {
        if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
           return 0;
        }
        i++;
    }

    return 1;
}

int esAlfanumerico (char str[])
{
     int i = 0;
    while(str[i] != '\0')
    {
        if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
        {
           return 0;
        }
        i++;
    }

    return 1;
}

void getString(char mensaje[], char input[])
{
    printf(mensaje);
    scanf("%s", input);
}

int getStringLetras(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esSoloLetras(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[], char input[])
{
    char aux[256];
    getString(mensaje, aux);
    if(esNumerico(aux))
    {
        strcpy(input, aux);
        return 1;
    }
    return 0;
}



