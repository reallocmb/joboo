#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<unistd.h>
#include"main.h"

char *decrypt(char *bytes, uint16_t bytes_length, char *key, uint16_t key_length) {
    char *bytes_decrypted = malloc((bytes_length + 1) * sizeof(char));
    if (bytes_decrypted == NULL)
        fprintf(stderr, "failed to alloc bytes_decrypted -> line: %d\n", __LINE__);

    int i, j;
    for (i = 0, j = 0; i < bytes_length; i++, j++) {
        if (j >= key_length)
            j = 0;
        bytes_decrypted[i] = bytes[i] ^ key[j];
        /*
        bytes_decrypted[i] = bytes[i];
        */
    }
    bytes_decrypted[i] = 0;

    return bytes_decrypted;
}

