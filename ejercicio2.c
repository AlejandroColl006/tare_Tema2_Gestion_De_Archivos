#include <stdio.h>
#include <ctype.h>

void to_lowercase (char *cadena) {
    int i =0;
    int j;
    int inicio;
    char temp;

    while (cadena[i] != '\0') {
        cadena[i] = tolower ((unsigned char) cadena[i]);
        i++;
    }

    j = i -1;
    inicio = 0;

    while (inicio < j) {
        temp = cadena[inicio];
        cadena[inicio] = cadena[j];
        cadena[j] = temp;
        inicio++;
        j--;
    }
}

int main() {
    FILE *origen , *destino;
    origen = fopen("original.txt", "r");
    if (origen == NULL) {
        perror("Error opening file");
        return 1;
    }

    destino = fopen("destino.txt", "w");
    if (destino == NULL) {
        perror("Error opening file");
        fclose(origen);
        return 1;
    }
    char buffer [100];
    int len = 0;
    int c;

    while (c(fgetc(origen) ) != EOF) {
        buffer[len++] = (char)c;
    }
    buffer[len] = '\0';
    to_lowercase(buffer);
    fputs(buffer, destino);

    fclose(origen);
    fclose(destino);

    printf("Archivo procesado y escrito al reves en destino.txt.\n");
}
