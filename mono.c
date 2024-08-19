#include <stdio.h>
#include <string.h>

void monoalphabeticEncrypt(char *message, char *key) {
    while (*message) {
        if (*message >= 'A' && *message <= 'Z') {
            *message = key[*message - 65 ];
        }
        message++;
    }
}

int main() {
    char message[100];
    char key[27];

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    printf("Enter the key (26 characters, all uppercase letters): ");
    scanf("%s", key);

    if (strlen(key) != 26 ) {
        printf("Error: Key must be exactly 26 characters long.\n");
        return 1;
    }

    monoalphabeticEncrypt(message, key);
    printf("Encrypted message: %s\n", message);

    return 0;
}
