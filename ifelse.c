#include "func.h"
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

bool if_state_without_dollar_char(int charg, const char *fa, const char *sa)
{
    switch (charg) {
        case 2:
            return atoi(fa) == atoi(sa);
            break;
        case 3:
            return atoi(fa) != atoi(sa);
            break;
        case 4:
            return atoi(fa) > atoi(sa);
            break;
        case 5:
            return atoi(fa) < atoi(sa);
            break;
        default:
            puts("Error");
            exit(-1);
    }
}

bool if_state_with_dollar_char(int charg, const char *fa, const char *sa)
{
    int value1, value2 = 0;
    if (fa[0] != '$')
        value1 = atoi(fa);
    else {
        char namevar[48];
        checkwd(fa, '$', namevar);
        value1 = vararr[searchvar(namevar)].cap;
    }
    if (sa[0] != '$')
        value2 = atoi(sa);
    else {
        char namevar2[48];
        checkwd(sa, '$', namevar2);
        value2 = vararr[searchvar(namevar2)].cap;
    }
    switch (charg) {
        case 2:
            return value1 == value2;
            break;
        case 3:
            return value1 != value2;
            break;
        case 4:
            return value1 > value2;
            break;
        case 5:
            return value1 < value2;
            break;
        default:
            puts("Error");
            exit(-1);
    }

}

bool ifthen(int charg, const char *fa, const char *sa)
{
    bool revalue;
    if (fa[0] != '$' || sa[0] != '$')
        revalue = if_state_without_dollar_char(charg, fa, sa);    
    else 
        revalue = if_state_with_dollar_char(charg, fa, sa);
    return revalue;
}

void elsethen(const char *runbuf)
{
    if (ifs) 
    {
        runfunc(runbuf);
    }
}

