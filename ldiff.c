/* guido@bravo47.com */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 4096 

void show_line(FILE *file1, FILE *file2, int line_number) {
    char line1[MAX_LINE_LENGTH];
    char line2[MAX_LINE_LENGTH];
    int line_num = 1;

    while (line_num < line_number && fgets(line1, MAX_LINE_LENGTH, file1) != NULL && fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
        line_num++;
    }

    // Si alcanzamos la línea deseada, la mostramos
    if (line_num == line_number) {
        if (fgets(line1, MAX_LINE_LENGTH, file1) != NULL) {
            printf("File1, line %d: %s", line_number, line1);
        } else {
            printf("File1 does not have line %d\n", line_number);
        }

        if (fgets(line2, MAX_LINE_LENGTH, file2) != NULL) {
            printf("File2, line %d: %s", line_number, line2);
        } else {
            printf("File2 does not have line %d\n", line_number);
        }
    } else {
        printf("Both files do not have line %d\n", line_number);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file1> <file2> <line_number>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL) {
        perror("Error opening file1");
        return 1;
    }

    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL) {
        perror("Error opening file2");
        fclose(file1);
        return 1;
    }

    int line_number = atoi(argv[3]);
    if (line_number <= 0) {
        fprintf(stderr, "Invalid line number: %s\n", argv[3]);
        fclose(file1);
        fclose(file2);
        return 1;
    }

    show_line(file1, file2, line_number);

    fclose(file1);
    fclose(file2);

    return 0;
}

