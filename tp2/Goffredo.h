
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

/*typedef struct
{
    int legajo;
    char nombre[50];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int sector;
    int estado;

}eEmpleado;*/

float getFloat ();
char getChar();
int getInt ();


int obtenerMaximo(int x[], int);
double factorializacion(int);
//void HarcodeoDeVector (eEmpleado vec [], int tam);
int menuOpciones (char opcion1[], char opcion2[], char opcion3[], char opcion4[], char opcion5[]);

int esNumerico (char str[]);
int esSoloLetras (char str[]);
int esAlfanumerico (char str[]);

int getStringNumeros(char mensaje[], char input[]);
int getStringLetras(char mensaje[], char input[]);
void getString(char mensaje[], char input[]);



