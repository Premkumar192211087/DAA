#include <stdio.h>

void copyString(char *source, char *destination) {
    if (*source == '\0') {
        *destination = '\0';
        return;
    }
    *destination = *source;
    copyString(source + 1, destination + 1);
}

int main() {
    char source[100], destination[100];

    printf("Enter a string to copy: ");
    fgets(source, sizeof(source), stdin);

    copyString(source, destination);

    printf("Copied string: %s\n", destination);

    return 0;
}

