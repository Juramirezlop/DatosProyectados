#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *archivo;
    char *contenido;
    long tamaño;

    // Abre el archivo en modo lectura
    archivo = fopen("/home/juanramirez2001/Descargas/MOCK_DATA.csv", "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Obtiene el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    tamaño = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);

    // Proyecta el archivo en memoria
    contenido = (char *)malloc(tamaño + 1);
    if (contenido == NULL) {
        printf("No se pudo asignar memoria para el archivo.\n");
        fclose(archivo);
        return 1;
    }

    fread(contenido, tamaño, 1, archivo);
    contenido[tamaño] = '\0'; // Agrega el carácter nulo al final

    // Accede al contenido proyectado en memoria
    printf("Contenido del archivo:\n%s\n", contenido);

    // Libera la memoria y cierra el archivo
    free(contenido);
    fclose(archivo);

    return 0;
}
