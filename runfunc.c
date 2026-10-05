#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
int runfunc(const char *bodyb) {
    char namefunc[48];
    checkwf(bodyb, namefunc, '^');
    //sprintf(namefunc, "%s", )
    if (strcmp(namefunc, "putl") == 0) {
        char putbuf[64];
        checkwd(bodyb, '^', putbuf);
        printf("%s\n", putbuf);
    }
    if (strcmp(namefunc, "puts") == 0) {
        char putbuf[64];
        checkwd(bodyb, '^', putbuf);
        printf("%s", putbuf);
    }
    if (strcmp(namefunc, "put") == 0 ||strcmp(namefunc, "putc") == 0) {
        char putch[1];
        checkwd(bodyb, '^', putch);
        printf("%s", putch);
    }
    if (strcmp(namefunc, "putcl") == 0) {
        char putch[1];
        checkwd(bodyb, '^', putch);
        printf("%s\n", putch);
    }
    if (strcmp(namefunc, "puti") == 0) {
        char algbuf[48];
        checkwd(bodyb, '^', algbuf);
        int result = algpars(algbuf);
        printf("%d\n", result);
    }
    if (strcmp(namefunc, "syscomm") == 0) {
        char runcomm[64];
        checkwd(bodyb, '^', runcomm);
        system(runcomm);
    }
    if (strcmp(namefunc, "putw") == 0) {
        char putbuf[64];
        checkwd(bodyb, '^', putbuf);
        printf("%s ", putbuf);
    }
 
    return 0;
}
