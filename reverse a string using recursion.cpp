  #include <stdio.h>

void reverseString(char *str) {
    if (*str == '\0') 
        return;
    else {
        reverseString(str + 1); 
        printf("%c", *str); 
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Reverse of the string: ");
    reverseString(str);

    return 0;
}

