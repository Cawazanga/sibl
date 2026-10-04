#include <string.h>
#include <stdio.h>
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

    return 0;
}
