#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc == 2) {
        const char *arg = argv[1];
        if (!(arg[0] == '-' && arg[1] == '-')) {
            if (access(arg, R_OK) == 0) {
                srand((unsigned)time(NULL));
                FILE *f = fopen(arg, "r");
                if (!f) {
                    perror("sibl");
                    return 1;
                }
                char line[1024];
                while (fgets(line, sizeof(line), f)) {
                    size_t len = strlen(line);
                    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
                        line[--len] = '\0';
                    }
                    if (len == 0)
                        continue;
                    if (line[0] == '#')
                        continue;
                    if (line[0] == ';')
                        continue;
                    char csev[512];
                    checkwf(line, csev, ':');
                    char cmd[64];
                    checkwf(csev, cmd, '^');
                    if (strcmp(cmd, "iblock") == 0) {
                        char blockline[128];
                        int i = 0;
                        while (i < 28 && fgets(blockline, sizeof(blockline), f)) {
                            size_t blen = strlen(blockline);
                            while (blen > 0 && (blockline[blen - 1] == '\n' || blockline[blen - 1] == '\r')) {
                                blockline[--blen] = '\0';
                            }
                            if (blen == 0) continue;
                            
                            char *percent = strchr(blockline, '%');
                            if (percent) *percent = '\0';
                            if (blen > 0 && blockline[blen - 1] == '|') blockline[--blen] = '\0';
                            
                            if (blen > 0) {
                                strncpy(blockarr[1].blocks[i], blockline, 63);
                                blockarr[1].blocks[i][63] = '\0';
                                i++;
                            }
                            if (percent) break;
                        }
                    } else {
                        runfunc(csev);
                    }
                }
                fclose(f);
                return 0;
            }
        }
    }
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
    return 0;
}
