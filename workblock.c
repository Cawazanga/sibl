#include "func.h"
#include <string.h>

void initblockvar(const char *nameblock, char blockin[28][64]) {
    if (countintarr >= 64) {
        return;
    }
    strncpy(blockarr[countblockarr].name, nameblock, 11);
    blockarr[countblockarr].name[11] = '\0';
    memcpy(blockarr[countintarr], blockin, sizeof(blockin));
    countblockarr++;
}

