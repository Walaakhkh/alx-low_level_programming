#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 20

/* Function to generate a valid key for the given username
   Replace this placeholder function with the actual key generation logic */
char* generate_key(const char* username) {
    char* key;
    /* Allocate memory for the key */
    key = (char*)malloc(MAX_KEY_LENGTH * sizeof(char));
    if (key == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    /* Generate a dummy key - replace this with actual logic */
    snprintf(key, MAX_KEY_LENGTH, "valid_key_for_%s", username);
    return key;
}

int main(int argc, char* argv[]) {
    char* username;
    char* key;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return 1;
    }

    username = argv[1];
    key = generate_key(username);

    printf("%s\n", key);
    free(key);

    return 0;
}
