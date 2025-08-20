#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptText(char *message, char *key, char *encrypted) {
	int i;
    int msgLen = strlen(message);
    int keyLen = strlen(key);
    for (i = 0; i < msgLen; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            encrypted[i] = ((message[i] - base) + (tolower(key[i % keyLen]) - 'a')) % 26 + base;
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[msgLen] = '\0';
}

void decryptText(char *cipher, char *key, char *decrypted) {
	int i;
    int msgLen = strlen(cipher);
    int keyLen = strlen(key);
    for (i = 0; i < msgLen; i++) {
        if (isalpha(cipher[i])) {
            char base = isupper(cipher[i]) ? 'A' : 'a';
            decrypted[i] = ((cipher[i] - base) - (tolower(key[i % keyLen]) - 'a') + 26) % 26 + base;
        } else {
            decrypted[i] = cipher[i];
        }
    }
    decrypted[msgLen] = '\0';
}

int main() {
    char message[200], key[50], encrypted[200], decrypted[200];

    printf("=============================================\n");
    printf("     Simple Vigenere Cipher Encryption Tool  \n");
    printf("=============================================\n");

    printf("Enter the encryption key: ");
    scanf("%s", key);
    getchar();

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';

    encryptText(message, key, encrypted);
    printf("\n---------- Encryption Complete ----------\n");
    printf("Original Message : %s\n", message);
    printf("Key Used         : %s\n", key);
    printf("Encrypted Text   : %s\n", encrypted);

    decryptText(encrypted, key, decrypted);
    printf("\n---------- Decryption Complete ----------\n");
    printf("Decrypted Text   : %s\n", decrypted);
    printf("=============================================\n");

    return 0;
}


