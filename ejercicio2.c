#include <stdio.h>


int main() {
    FILE *origen = fopen("ejemplo.txt", "r");
    FILE *destino = fopen("destino.txt", "w");  // lo crea si no existe

    if (!origen) {
        printf("No se pudo abrir ejemplo.txt\n");
        return 1;
    }
    if (!destino) {
        printf("No se pudo crear destino.txt\n");
        fclose(origen);
        return 1;
    }

    char buffer[1024];
    int len = 0;

    char c;
    while ((c = fgetc(origen)) != EOF) {
        buffer[len++] = c;
    }
    buffer[len] = '\0';

    for (int i = 0; i < len / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[len - 1 - i];
        buffer[len - 1 - i] = temp;
    }
    fprintf(destino, "%s", buffer);

    fclose(origen);
    fclose(destino);

    printf("Archivo destino.txt creado y escrito correctamente.\n");
    return 0;
}
