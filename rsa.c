#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to generate keys for RSA encryption
void generateKeys(int p, int q, int *n, int *e, int *d) {
    int phi;

    *n = p * q;
    phi = (p - 1) * (q - 1);

    for (*e = 2; *e < phi; (*e)++) {
        if (gcd(*e, phi) == 1)
            break;
    }

    *d = 1;
    while (((*d) * (*e)) % phi != 1) {
        (*d)++;
    }
}

// Function to encrypt a message using RSA
int encrypt(int msg, int e, int n) {
    int c = pow(msg, e);
    return fmod(c, n);
}

// Function to decrypt a message using RSA
int decrypt(int c, int d, int n) {
    int msg = pow(c, d);
    return fmod(msg, n);
}

int main() {
    int p, q, n, e, d, msg, encrypted_msg, decrypted_msg;

    printf("Enter two prime numbers (p and q): ");
    scanf("%d %d", &p, &q);

    if (!isPrime(p) || !isPrime(q)) {
        printf("Both numbers should be prime.\n");
        return 1;
    }

    generateKeys(p, q, &n, &e, &d);

    printf("\nPublic Key: (n = %d, e = %d)\n", n, e);
    printf("Private Key: (n = %d, d = %d)\n", n, d);

    printf("\nEnter a message to encrypt: ");
    scanf("%d", &msg);

    encrypted_msg = encrypt(msg, e, n);
    printf("Encrypted message: %d\n", encrypted_msg);

    decrypted_msg = decrypt(encrypted_msg, d, n);
    printf("Decrypted message: %d\n", decrypted_msg);

    return 0;
}
