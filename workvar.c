#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"
void initvar(const char *namevar, int value);
int workvar(int arg, const char *namevar, const char *value) {
    switch (arg) {
        case 1:
            initvar(namevar, atoi(value));
            break;
        case 2:
            vararr[searchvar(namevar)].cap = algpars(value);
            break;
        case 3:
            vararr[searchvar(namevar)].cap = atoi(value);
            break;
    }
}
void initvar(const char *namevar, int value) {
    if (countintarr >= 64) {
        return;
    }
    strncpy(vararr[countintarr].name, namevar, 11);
    vararr[countintarr].name[11] = '\0';
    vararr[countintarr].cap = value;
    countintarr++;
}
int searchvar(const char *namevar) {
    for (int i = 0; i < countintarr; i++) {
        if (strcmp(namevar, vararr[i].name) == 0) {
            return i;
        }
    }
    return -1;
}
int getnumargforvar(const char *argname) {
    if (strcmp(argname, "init") == 0)
        return 1;
    if (strcmp(argname, "equals") == 0)
        return 2;
    if (strcmp(argname, "equal") == 0)
        return 3;
}
