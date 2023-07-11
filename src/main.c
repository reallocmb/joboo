#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<unistd.h>
#include"main.h"

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
