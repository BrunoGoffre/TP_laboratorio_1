typedef struct
{
    int id;
    char nombre [51];
    char apellido[51];
    float salario;
    int sector;
    int estado;

} eEmpleado;

void inicializarEmpleados             (eEmpleado empleados[], int tamEmp);
void altaEmpleados                    (eEmpleado empleados[], int tamEmp, int *id, int *flag);
void listarEmpleado                   (eEmpleado empleado);
void listarEmpleados                  (eEmpleado empleados[], int tamEmp);
void ordenarAlfabeticamenteEmpleados  (eEmpleado empleados[], int tamEmp);
void empleadosMejorPagos              (eEmpleado empleados[], int tamEmp, float sueldoPromedio);
void modificarEmpleado                (eEmpleado empledaos[], int tamEmp);
void bajaEmpleado                     (eEmpleado empleados[], int tamEmp);

int buscarEmpleado                    (eEmpleado empleados[], int tamEmp, int legajo);
int buscarVacio                       (eEmpleado empleados[], int tamEmp);
int menuOpcionesABM                   ();

float promedioSalariosEmpleados       (eEmpleado empleados[], int tamEmp);
