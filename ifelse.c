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
    return false;
}

bool ifthen(int charg, const char *fa, const char *sa)
{
    bool revalue;
    if (fa[0] != '$' || sa[0] != '$')
    {
        revalue = if_state_without_dollar_char(charg, fa, sa);    
    }
    else {
        puts("Error");
        return 0;
    }
    return revalue;
}

