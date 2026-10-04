#include "func.h"
#include <stdio.h>
#include <stdlib.h>
int algpars(const char *buf) {
    char op[7];
    char s1[12], s2[12];
    int result;
    if (sscanf(buf, "%6s %7s %7s", op, s1, s2) != 3) {
        return atoi(op);
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
