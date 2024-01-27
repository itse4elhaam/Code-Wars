#include <stdio.h>
#include <stdlib.h>

const int upperCaseAsciiBounds[] = {65, 90};
const int lowerCaseAsciiBounds[] = {97, 122};

// Returns 0 => not alphabet, returns 1 => lowercase, returns 2 => uppercase
int isCap(char chr) {
    const int ascii = (int)chr;

    if (ascii >= upperCaseAsciiBounds[0] && ascii <= upperCaseAsciiBounds[1]) {
        return 2;
    } else if (ascii >= lowerCaseAsciiBounds[0] && ascii <= lowerCaseAsciiBounds[1]) {
        return 1;
    } else {
        return 0;
    }
}

int getLen(const char *src) {
    int len = 0;
    while (src[len] != '\0') {
        len++;
    }
    return len;
}

char *rot13(const char *src) {
    const int CHARS_TO_JUMP = 13;
    const int len = getLen(src);

    // Dynamically allocate memory for the result
    // we are creating a dynamic array of chars(string) acc to the length determined
    char *rot13Src = (char *)malloc((len + 1) * sizeof(char));

    for (int i = 0; i < len; i++) {
        const char chr = src[i];
        int charCondition = isCap(chr);

        if (charCondition < 1) {
            rot13Src[i] = chr;
            continue;
        }
        
        int base = (charCondition == 1) ? 'a' : 'A';
        // this makes sure that it stays within the max count, if it goes up it rotates back
        rot13Src[i] = (chr - base + CHARS_TO_JUMP) % 26 + base;
    }

    // Null-terminate the result
    rot13Src[len] = '\0';

    return rot13Src;
}

int main() {
    const char *src = "Test";
    const char *expected = "Grfg";
    char *actual = rot13(src);

    printf("Original: %s\n", src);
    printf("Expected: %s\n", expected);
    printf("Actual  : %s\n", actual);

    // Free dynamically allocated memory
    free(actual);

    return 0;
}

