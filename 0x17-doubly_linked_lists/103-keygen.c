#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to generate a valid key for the given username
// This function is just a placeholder; replace it with the actual logic
char* generate_key(const char* username) {
    // Implement the logic based on how the key is validated
    // For demonstration, this example just returns a fixed key
    // You need to replace this with actual key generation logic
    char* key = (char*)malloc(20 * sizeof(char));
    snprintf(key, 20, "valid_key_for_%s", username);
    return key;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s username\n", argv[0]);
        return 1;
    }

    char* username = argv[1];
    char* key = generate_key(username);

    printf("%s\n", key);
    free(key);

    return 0;
}
