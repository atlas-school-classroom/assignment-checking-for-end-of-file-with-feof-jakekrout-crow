#include <stdio.h>
#include <stdlib.h>
#include <example.txt>

int main(){
    FILE *file;
    char filename[] = example.txt;
    char data[150];

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    if (fgets(data, sizeof(data), file) == NULL) {
        if (feof(file)) {
            printf("End of file reached.\n");
        } else {
            perror("Error reading file");
            fclose(file);
            return EXIT_FAILURE;
        }
    } 
    else {
        printf("File content: %s\n", data);
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
        return EXIT_FAILURE;
}
    return EXIT_SUCCESS;
}