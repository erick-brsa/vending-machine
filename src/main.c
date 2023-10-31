#include <stdio.h>
#include <stdlib.h>

struct producto {
    int precio;
    int cantidad;
    int clave;
    char nombre[10];
};

void imprimir(struct producto *productos, const int *size) {
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("|                            M%cQUINA EXPENDEDORA DE PRODUCTOS                                   |\n", 181);
    printf("-------------------------------------------------------------------------------------------------");

    for (int i = 0; i < *size; i++) {
        if (i % 3 == 0) {
            printf("\n|-----------------------------------------------------------------------------------------------|\n");
        }
        struct producto p = productos[i];
        printf("| [%d] %s - $%d (%d) \t|", p.clave, p.nombre, p.precio, p.cantidad);
    }
    printf("\n|-----------------------------------------------------------------------------------------------|\n");
}

void obtener_productos(struct producto *productos, const int *size) {
    FILE *archivo = fopen("productos.txt", "r");

    if (archivo == NULL) {
        printf("No se pudo encontrar el archivo.\n");
        exit(1);
    }

    char linea[100];
    int contador = 0;

    while (contador < *size && fgets(linea, sizeof(linea), archivo) != NULL) {
        if (sscanf(linea, "%d, %d, %d, %9[^\r\n]", &productos[contador].precio, &productos[contador].cantidad,
                   &productos[contador].clave, productos[contador].nombre) == 4) {
            contador++;
        }
    }

    fclose(archivo);
}

int main() {
    const int size = 15;
    struct producto productos[size];

    obtener_productos(productos, &size);
    imprimir(productos, &size);

    return 0;
}