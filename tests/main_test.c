#include<unicki.h>
#include"../src/main.h"
#include<string.h>

_testSection_
suite("test") {
    test("first_test") {
        char *bytes = "Das ist ein Test";
        decrypt(bytes, strlen(bytes), "code", 4);
        decrypt(bytes, strlen(bytes), "code", 4);
    }
}_end;
_endSection_
