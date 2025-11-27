//WAP to check if 2 strings are anagrams of each other
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int areAnagrams(const char *str1, const char *str2) {
    int count[256] = {0};

    if (strlen(str1) != strlen(str2)) {
        printf("The strings are not anagrams of each other.\n");
        return 0;
    }
    for (int i = 0; str1[i] != '\0'; i++) {
        count[str1[i]]++;
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        count[str2[i]]--;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            printf("The strings are not anagrams of each other.\n");
        }
    }
    printf("The strings are anagrams of each other.\n");
    return 0;
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%99s", str1);

    printf("Enter second string: ");
    scanf("%99s", str2);

    areAnagrams(str1, str2);

    return 0;
}