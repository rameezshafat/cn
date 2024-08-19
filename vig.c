#include <stdio.h>
#include <string.h>

void generateKey(char* str, char* key) {
    int strLen = strlen(str);
    int keyLen = strlen(key);
    for (int i = 0; i < strLen; i++) {
        key[i] = key[i % keyLen];
    }
    key[strLen] = '\0';
}

void encryptVigenere(char* str, char* key, char* ct) {
    for (int i = 0; i < strlen(str); i++) {
        ct[i] = (((str[i] - 'a') + (key[i] - 'a')) % 26) + 'a';
    }
    ct[strlen(str)] = '\0';
}

void decryptVigenere(char* ct, char* key, char* rt) {
    for (int i = 0; i < strlen(ct); i++) {
        rt[i] = (((ct[i] - 'a') - (key[i] - 'a') + 26) % 26) + 'a';
    }
    rt[strlen(ct)] = '\0';
}

int main() {
    char pt[100], key[100], ct[100], rt[100];

    printf("Enter the plain text: ");
    fgets(pt, sizeof(pt), stdin);
    pt[strcspn(pt, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    generateKey(pt, key);

    encryptVigenere(pt, key, ct);
    printf("Cipher text: %s\n", ct);

    decryptVigenere(ct, key, rt);
    printf("Plain text: %s\n", rt);

    return 0;
}
