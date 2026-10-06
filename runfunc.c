#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
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
    if (strcmp(namefunc, "v") == 0) {
        char putbuf1[24];
        char putbuf11[24];
        char putbuf2[24];
        char putbuf12[24];
        char putbuf3[24];

        checkwd(bodyb, '^', putbuf1);
        checkwf(putbuf1,  putbuf11, '^');
        checkwd(putbuf1, '^', putbuf2);
        checkwf(putbuf2,  putbuf12, '^');
        checkwd(putbuf2, '^', putbuf3);

        workvar(getnumargforvar(putbuf11), putbuf12, putbuf3);
    }
    if (strcmp(namefunc, "putvl") == 0) {
        char putbuf[24];
        checkwd(bodyb, '^', putbuf);
        printf("%d\n", vararr[searchvar(putbuf)].cap);
    }
    if (strcmp(namefunc, "putv") == 0) {
        char putbuf[24];
        checkwd(bodyb, '^', putbuf);
        printf("%d", vararr[searchvar(putbuf)].cap);
    }
    if (strcmp(namefunc, "delay") == 0) {
        char putbuf[24];
        checkwd(bodyb, '^', putbuf);
        sleep(atoi(putbuf));
    }
    return 0;
}
