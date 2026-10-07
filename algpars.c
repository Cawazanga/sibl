#include "func.h"
#include <stdio.h>
#include <stdlib.h>
int algpars(const char *buf) {
    char op[7];
    char ps1[12], ps2[12];
    char s1[12], s2[12];
    int result;
    if (sscanf(buf, "%6s %7s %7s", op, ps1, ps2) != 3) {
        return atoi(op);
    }
    {
        if (ps1[0] == '$') {
            char namevar[12];
            checkwd(ps1, '$', namevar);
            snprintf(s1, sizeof(s1), "%d", vararr[searchvar(namevar)].cap);
        } else {
            snprintf(s1, sizeof(s1), "%s", ps1);
        }
    }

    {
        if (ps2[0] == '$') {
            char namevar[12];
            checkwd(ps2, '$', namevar);
            snprintf(s2, sizeof(s2), "%d", vararr[searchvar(namevar)].cap);
        } else {
            snprintf(s2, sizeof(s2), "%s", ps2);
        }
    }
    switch(op[0]) {
        case '*':
            result = atoi(s1) * atoi(s2);
            break;
        case '/':
            result = atoi(s1) / atoi(s2);
            break;
        case '+':
            result = atoi(s1) + atoi(s2);
            break;
        case '-':
            result = atoi(s1) - atoi(s2);
            break;
        default:
            puts("Error");
            exit(-1);
    }
    return result;
}
