#include "func.h"
#include <stdio.h>
int main() {
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
    printf("%s", csev);
}
