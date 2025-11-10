#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source, *dest;
    char inputFile[50], outputFile[50];
    char ch;

    printf("Enter input file name: ");
    scanf("%s", inputFile);

    printf("Enter output file name: ");
    scanf("%s", outputFile);

    source = fopen(inputFile, "r");
    if (source == NULL) {
        printf("Unable to open source file.\n");
        exit(1);
    }

    dest = fopen(outputFile, "w");
    if (dest == NULL) {
        printf("Unable to create destination file.\n");
        fclose(source);
        exit(1);
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    fclose(source);
    fclose(dest);
    return 0;
}