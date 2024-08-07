#include "analyzer.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

int analyze_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[BUFFER_SIZE];
    int line_number = 0;
    while (fgets(line, sizeof(line), file)) {
        line_number++;
	printf("%s", line);
        check_for_errors(line, line_number);
    }

    fclose(file);
    return 0;
}

void check_for_errors(const char *line, int line_number) {
    if (strstr(line, "ERR") == NULL && strstr(line, ";") == NULL) {
        printf("Possible missing semicolon at line %d\n", line_number);
    }

}

