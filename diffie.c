#include <stdio.h>
#include <stdlib.h>

#define P 23 // Prime number
#define G 5  // Primitive root modulo

// Function to calculate modular exponentiation (base^exp % modulus)
int mod_exp(int base, int exp, int modulus) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp /= 2;
    }
    return result;
}

// Function to perform Diffie-Hellman Key Exchange
void diffie_hellman(int private_key, int *public_key) {
    *public_key = mod_exp(G, private_key, P);
}

int main() {
    int private_key_client, private_key_server;
    int public_key_client, public_key_server;
    int shared_secret_client, shared_secret_server;

    private_key_client = rand() % (P - 1) + 1;
    private_key_server = rand() % (P - 1) + 1;

    diffie_hellman(private_key_client, &public_key_client);
    diffie_hellman(private_key_server, &public_key_server);

    shared_secret_client = mod_exp(public_key_server, private_key_client, P);
    shared_secret_server = mod_exp(public_key_client, private_key_server, P);

    printf("Client shared secret: %d\n", shared_secret_client);
    printf("Server shared secret: %d\n", shared_secret_server);

    return 0;
}
