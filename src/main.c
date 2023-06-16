#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<unistd.h>

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
    printf("i: %d\n", i);
    bytes_decrypted[i] = 0;

    return bytes_decrypted;
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        puts("not enough arguments");
        return 0;
    }
    char passwd[150];
    scanf("%s", passwd);

    FILE *f = fopen(argv[1], "r");
    FILE *d = fopen ("dec", "w+");

    char buffer[50] = { 0 };
    int len = 0;
    while ((len = fread(buffer, 1, 50, f))) {
        fwrite(decrypt(buffer, len, passwd, strlen(passwd)), 1, len, d);
    }

    fclose(f);
    fclose(d);
    remove(argv[1]);
    rename("dec", argv[1]);

    return 0;
}
