#include <stdio.h>
#include <stdlib.h>

struct Producto {
    int codigo;
    char nombre[50];
    char marca[50];
    float costo;
};

struct Turno {
    struct Producto productos[100];
    int cantidadProductos;
};

int main() {
    struct Turno turnos[3];
    int turnoActual = 0;
    int opcion;

    while (1) {
        printf("Turno actual: ");
        if (turnoActual == 0) {
            printf("Manana (7:00-15:00)\n");
        } else if (turnoActual == 1) {
            printf("Tarde (15:00-23:00)\n");
        } else if (turnoActual == 2) {
            printf("Noche (23:00-7:00)\n");
        }

        printf("Seleccione una opcion:\n");
        printf("1. Ingresar datos de costos\n");
        printf("2. Cambio de turno\n");
        printf("3. Ver turno con menos desperdicio de material\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Ingresar datos de costos
                printf("Ingrese el codigo del producto: ");
                scanf("%d", &turnos[turnoActual].productos[turnos[turnoActual].cantidadProductos].codigo);
                printf("Ingrese el nombre del producto: ");
                scanf("%s", turnos[turnoActual].productos[turnos[turnoActual].cantidadProductos].nombre);
                printf("Ingrese la marca del producto: ");
                scanf("%s", turnos[turnoActual].productos[turnos[turnoActual].cantidadProductos].marca);
                printf("Ingrese el costo del producto: ");
                scanf("%f", &turnos[turnoActual].productos[turnos[turnoActual].cantidadProductos].costo);

                turnos[turnoActual].cantidadProductos++;
                break;
            case 2:
                // Cambio de turno
                turnoActual = (turnoActual + 1) % 3;
                break;
            case 3:
                
                int turnoMenosDesperdicio = 0;
                float menorDesperdicio = turnos[0].productos[0].costo;
                for (int i = 1; i < 3; i++) {
                    float totalDesperdicio = 0;
                    for (int j = 0; j < turnos[i].cantidadProductos; j++) {
                        totalDesperdicio += turnos[i].productos[j].costo;
                    }
                    if (totalDesperdicio < menorDesperdicio) {
                        menorDesperdicio = totalDesperdicio;
                        turnoMenosDesperdicio = i;
                    }
                }

                printf("El turno con menos desperdicio de material es: ");
                if (turnoMenosDesperdicio == 0) {
                    printf("Manana (7:00-15:00)\n");
                } else if (turnoMenosDesperdicio == 1) {
                    printf("Tarde (15:00-23:00)\n");
                } else if (turnoMenosDesperdicio == 2) {
                    printf("Noche (23:00-7:00)\n");
                }
                break;
            case 4:
                // Salir
                exit(0);
                break;
            default:
                printf("Opción inválida. Por favor, seleccione una opción válida.\n");
                break;
        }
    }

    return 0;
}