#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to generate the key matrix for encryption
void getKeyMatrix(int n, int keyMatrix[n][n], char key[])
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

// Function to encrypt the message using the key matrix
void encrypt(int n, int cipherMatrix[n][1], int keyMatrix[n][n], int messageVector[n][1])
{
    for (int i = 0; i < n; i++)
    {
        cipherMatrix[i][0] = 0;
        for (int j = 0; j < n; j++)
        {
            cipherMatrix[i][0] += keyMatrix[i][j] * messageVector[j][0];
        }
        cipherMatrix[i][0] = cipherMatrix[i][0] % 26;
    }
}

// Function to implement the Hill Cipher
void HillCipher(char message[], char key[])
{
    int n = (int)sqrt(strlen(key));  // Determine the size of the key matrix (n x n)
    int keyMatrix[n][n];
    getKeyMatrix(n, keyMatrix, key);

    int messageVector[n][1];

    for (int i = 0; i < n; i++)
        messageVector[i][0] = (message[i]) % 65;

    int cipherMatrix[n][1];
    encrypt(n, cipherMatrix, keyMatrix, messageVector);

    char CipherText[n+1];
    for (int i = 0; i < n; i++)
        CipherText[i] = cipherMatrix[i][0] + 65;

    CipherText[n] = '\0';  // Null-terminate the cipher text
    printf("Ciphertext: %s\n", CipherText);
}

int main()
{
    char message[] = "ACT";  // Adjust message length to be the same as matrix size n
    char key[] = "GYBNQKURP"; // Example key for 3x3 matrix (length of key should be n^2)

    int keyLength = strlen(key);
    int n = (int)sqrt(keyLength);

    // Check if the key length is a perfect square
    if (n * n != keyLength)
    {
        printf("Error: Key length must be a perfect square (e.g., 4, 9, 16, ...)\n");
        return 1;
    }

    // Check if the message length is the same as the matrix size
    if (strlen(message) != n)
    {
        printf("Error: Message length must be equal to the matrix size (n=%d)\n", n);
        return 1;
    }

    HillCipher(message, key);

    return 0;
}
