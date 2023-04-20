#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

int main() {
    FILE *f = fopen("data.csv", "w");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    char var1[MAX_LEN], var2[MAX_LEN], var3[MAX_LEN];
    char input[MAX_LEN];
    while (1) {
        printf("Enter three variables (separated by spaces), or 'stop' to quit:\n");
        fgets(input, MAX_LEN, stdin);
        if (strcmp(input, "stop\n") == 0) {
            break;
        }
        char var1[MAX_LEN], var2[MAX_LEN], var3[MAX_LEN];
        sscanf(input, "%s %s %s", var1, var2, var3);
        fprintf(f, "%s %s %s\n", var1, var2, var3);
    }
    fclose(f);
    return 0;
}