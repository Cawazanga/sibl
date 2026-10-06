#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    srand((unsigned)time(NULL));
    while (1) {
        char buf[128];
        char csev[48];
        int recs = scanf("%127[^\n]", buf);
        if (recs == 1)
            scanf("%*c");
        else if (recs == 0) {
            scanf("%*c");
            buf[0] = '\0';
        }
        checkwf(buf, csev, ':');
        runfunc(csev);
    }

}
