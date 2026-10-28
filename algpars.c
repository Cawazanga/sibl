#include "func.h"
#include <stdio.h>
#include <stdlib.h>
int algpars(const char *buf) {
    char op[70];
    char ps1[129], ps2[129];
    char s1[129], s2[129];
    int result;
    if (buf[0] == '$') {
        char namevar[129];
        checkwd(buf, '$', namevar);
        return vararr[searchvar(namevar)].cap;
    }
    if (sscanf(buf, "%60s %70s %70s", op, ps1, ps2) != 3) {
        return atoi(op);
    }
    {
        if (ps1[0] == '$') {
            char namevar[120];
            checkwd(ps1, '$', namevar);
            snprintf(s1, sizeof(s1), "%d", vararr[searchvar(namevar)].cap);
        } else if (ps1[0] == '#') {
            switch (ps1[1]) {
                    case 'r':
                        char argsstr[160];
                        char arg1[80];
                        char arg2[80];
                        check(ps1, '(', argsstr, ')');
                        checkwf(argsstr, arg1, ',');
                        checkwd(argsstr, ',', arg2); 
                        snprintf(s1, sizeof(s1), "%d", rand_range(atoi(arg1), atoi(arg2)));
                        break;
                    case 2:
                        break;
                    default:
                        puts("Error");
                        exit(-1);
            }   
        } 
        
        else {
            snprintf(s1, sizeof(s1), "%s", ps1);
        }
    }

    {
        if (ps2[0] == '$') {
            char namevar[120];
            checkwd(ps2, '$', namevar);
            snprintf(s2, sizeof(s2), "%d", vararr[searchvar(namevar)].cap);
        } else if (ps2[0] == '#') {
            switch (ps2[1]) {
                    case 'r':
                        char argsstr[160];
                        char arg1[80];
                        char arg2[80];
                        check(ps2, '(', argsstr, ')');
                        checkwf(argsstr, arg1, ',');
                        checkwd(argsstr, ',', arg2); 
                        snprintf(s2, sizeof(s2), "%d", rand_range(atoi(arg1), atoi(arg2)));
                        break;
                    case 2:
                        break;
                    default:
                        puts("Error");
                        exit(-1);
            }
        }
        else {
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
