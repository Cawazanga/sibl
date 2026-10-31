#include "func.h"
#include <string.h>

void initblockvar(const char *nameblock, char blockin[28][64]) {
    if (countblockarr >= 64) {
        return;
    }
    strncpy(blockarr[countblockarr].name, nameblock, 11);
    blockarr[countblockarr].name[11] = '\0';
    memcpy(blockarr[countblockarr].blocks, blockin, sizeof(blockarr[countblockarr].blocks));
    blockarr[countblockarr].size = 0;
    countblockarr++;
}

int searchblock(const char *nameblock) {
    for (int i = 0; i < countblockarr; i++) {
        if (strcmp(nameblock, blockarr[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

