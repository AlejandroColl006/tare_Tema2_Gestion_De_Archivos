#include <stdio.h>

int main() {
    FILE *archivo;

    archivo = fopen("ejemplo.txt", "w");
    if (archivo == NULL) {
        perror ("Error al abrir el archivo. \n");
        return 1;
    }

    fprintf(archivo, "Hola, este es un saludo desde otro archivo. \n");
    fclose(archivo);

    archivo = fopen("ejemplo.txt", "r");
    if (archivo == NULL) {
        perror ("Error al abrir el archivo. \n");
        return 1;
    }

    char linea[100];
    fgets(linea, sizeof(linea), archivo);
    printf("Contenido del archivo: %s", linea);

    fclose(archivo);
    return 0;
}
