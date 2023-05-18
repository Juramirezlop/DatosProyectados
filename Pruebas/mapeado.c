#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
    int archivo;
    struct stat s;
    char *contenido;

    // Abre el archivo
    archivo = open("/home/juanramirez2001/Documentos/Pruebas/MOCK_DATA.csv", O_RDONLY);
    if (archivo == -1) {
        perror("No se pudo abrir el archivo");
        return 1;
    }

    // Tamaño del archivo
    if (fstat(archivo, &s) == -1) {
        perror("Error al obtener el tamaño del archivo");
        close(archivo);
        return 1;
    }

    // Proyección
    contenido = mmap(0, s.st_size, PROT_READ, MAP_PRIVATE, archivo, 0);
    if (contenido == MAP_FAILED) {
        perror("Error al proyectar el archivo en memoria");
        close(archivo);
        return 1;
    }

    //Muestra contenido en consola
    printf("Contenido del archivo:\n%s\n", contenido);

    munmap(contenido, s.st_size);
    close(archivo);

    return 0;
}
