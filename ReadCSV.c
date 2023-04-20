#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_LINE_LENGTH 100

int main() {
    char filename[] = "data.csv";
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // Initialize the data array
    double data[MAX_ROWS][MAX_COLS];
    int row = 0;

    // Read each line of the file
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        // Parse the line into tokens
        char* token = strtok(line, ",");
        int col = 0;
        while (token != NULL) {
            // Convert the token to a double and store it in the data array
            data[row][col] = atof(token);
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    // Print the data array for testing
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%.2f ", data[i][j]);
        }
        printf("\n");
    }

    fclose(file);
    return 0;
}
