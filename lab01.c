#include <stdio.h>

struct Proceso {
    int pid;
    char nombre[20];
    int prioridad;
};

int buscarMayorPrioridad(struct Proceso *procesos, int n) {
    int indice = 0;

    for (int i = 1; i < n; i++) {
        if (procesos[i].prioridad < procesos[indice].prioridad) {
            indice = i;
        }
    }

    return indice;
}

int main() {
    struct Proceso procesos[5];
    int n;

    printf("¿Cuantos procesos desea registrar (maximo 5)? ");
    scanf("%d", &n);

    if (n < 1 || n > 5) {
        printf("Cantidad de procesos no valida.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nProceso %d\n", i + 1);

        printf("PID: ");
        scanf("%d", &procesos[i].pid);

        printf("Nombre: ");
        scanf("%19s", procesos[i].nombre);

        printf("Prioridad (1-5): ");
        scanf("%d", &procesos[i].prioridad);
    }

    int indice = buscarMayorPrioridad(procesos, n);

    printf("\nProceso de mayor prioridad:\n");
    printf("PID: %d\n", procesos[indice].pid);
    printf("Nombre: %s\n", procesos[indice].nombre);
    printf("Prioridad: %d\n", procesos[indice].prioridad);

    return 0;
}
