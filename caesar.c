#include <stdlib.h>
#include <stdio.h>

void caesarEncrypt(char *message, int shift ){
while(*message){
    if(*message >= 'a' && *message <='z')
    {
        *message = (*message - 'a' + shift ) % 26 + 'a';
    }
    else if(*message >= 'A' && *message <+'Z')
    {
        *message = (*message -'A'+ shift )%26 +'A';
    }
    message++;
    }
}
void caesarDecrypt(char *message, int shift ){
while(*message){
    if(*message >= 'a' && *message <='z')
    {
        *message = (*message - 'a' - shift + 26 ) % 26 + 'a';
    }
    else if(*message >= 'A' && *message <+'Z')
    {
        *message = (*message -'A' - shift + 26 )%26 +'A';
    }
    message++;
    }
    // to handle negative shifts
    
}
int main() {
    char message[100];
    int shift;

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    printf("Original message: %s\n", message);

    caesarEncrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    caesarDecrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}
