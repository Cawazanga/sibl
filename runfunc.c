#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "func.h"
int runfunc(const char *bodyb) {
    char namefunc[48];
    checkwf(bodyb, namefunc, '^');
    //sprintf(namefunc, "%s", )
    if (strcmp(namefunc, "putl") == 0) {
        char putbuf[64];
        checkwd(bodyb, '^', putbuf);
        printf("%s\n", putbuf);
    }
    if (strcmp(namefunc, "puts") == 0) {
        char putbuf[64];
        checkwd(bodyb, '^', putbuf);
        printf("%s", putbuf);
    }
    if (strcmp(namefunc, "put") == 0 ||strcmp(namefunc, "putc") == 0) {
        char putch[1];
        checkwd(bodyb, '^', putch);
        printf("%s", putch);
    }
    if (strcmp(namefunc, "putcl") == 0) {
        char putch[1];
        checkwd(bodyb, '^', putch);
        printf("%s\n", putch);
    } 
    if (strcmp(namefunc, "puti") == 0) {
        char algbuf[48];
        checkwd(bodyb, '^', algbuf);
        int result = algpars(algbuf);
        printf("%d\n", result);
    }
    if (strcmp(namefunc, "syscomm") == 0) {
        char runcomm[64];
        checkwd(bodyb, '^', runcomm);
        system(runcomm);
    }
    if (strcmp(namefunc, "putw") == 0) {
        char putbuf[64];
        checkwd(bodyb, '^', putbuf);
        printf("%s ", putbuf);
    }
    if (strcmp(namefunc, "v") == 0) {
        char putbuf1[24];
        char putbuf11[24];
        char putbuf2[24];
        char putbuf12[24];
        char putbuf3[24];

        checkwd(bodyb, '^', putbuf1);
        checkwf(putbuf1,  putbuf11, '^');
        checkwd(putbuf1, '^', putbuf2);
        checkwf(putbuf2,  putbuf12, '^');
        checkwd(putbuf2, '^', putbuf3);

        workvar(getnumargforvar(putbuf11), putbuf12, putbuf3);
    }
    if (strcmp(namefunc, "putvl") == 0) {
        char putbuf[24];
        checkwd(bodyb, '^', putbuf);
        printf("%d\n", vararr[searchvar(putbuf)].cap);
    }
    if (strcmp(namefunc, "putv") == 0) {
        char putbuf[24];
        checkwd(bodyb, '^', putbuf);
        printf("%d", vararr[searchvar(putbuf)].cap);
    }
    if (strcmp(namefunc, "delay") == 0) {
        char putbuf[24];
        checkwd(bodyb, '^', putbuf);
        sleep(atoi(putbuf));
    }
    if (strcmp(namefunc, "tputrl") == 0) {
        char putbuf1[24];
        char putbuf11[24];
        char putbuf2[24];
        checkwd(bodyb, '^', putbuf1);
        checkwf(putbuf1, putbuf11, '^');
        checkwd(putbuf1, '^', putbuf2);
        printf("%d\n", rand_range(atoi(putbuf11), atoi(putbuf2)));
    }
    if (strcmp(namefunc, "tputr") == 0) {
        char putbuf1[24];
        char putbuf11[24];
        char putbuf2[24];
        checkwd(bodyb, '^', putbuf1);
        checkwf(putbuf1, putbuf11, '^');
        checkwd(putbuf1, '^', putbuf2);
        printf("%d", rand_range(atoi(putbuf11), atoi(putbuf2)));
    }
    if (strcmp(namefunc, "loop") == 0) {
        char howmanyc[4];
        char cycbuf[127];
        check(bodyb, '^', howmanyc, '^');
        check(bodyb, '[', cycbuf, ']');
        for (int i = atoi(howmanyc); i != 0; i--)
            runfunc(cycbuf);
    }
    if (strcmp(namefunc, "ee") == 0) {
        char reresstr[99];
        int reres;
        checkwd(bodyb, '^', reresstr);
        reres = atoi(reresstr);
        fflush(stdout);
        exit(reres);
    }
    if (strcmp(namefunc, "if") == 0) {
        
        char  putbuf1[1023];
        char putbuf11[1023];
        char  putbuf2[1023];
        char putbuf12[1023];
        char  putbuf3[1023];
        char     rbuf[1023];
        char putbuf13[1023];
        
        checkwd(bodyb, '^', putbuf1);
        checkwf(putbuf1,  putbuf11, '^');
        checkwd(putbuf1, '^', putbuf2);
        checkwf(putbuf2,  putbuf12, '^');
        checkwd(putbuf2, '^', putbuf3);
        checkwf(putbuf3, putbuf13, '^');
        check(putbuf3, '[', rbuf, ']');
        if (ifthen(getnumargforvar(putbuf11), putbuf12, putbuf13)) {
            runfunc(rbuf);
            ifs = false;
        } 
        else
            ifs = true;
    }
    if (strcmp(namefunc, "else") == 0) {
        char runbuf[1023];
        check(bodyb, '[', runbuf, ']');
        elsethen(runbuf);
    }
    if (strcmp(namefunc, "block") == 0) {
        int i = 0;
        while (i < 28 && blockarr[1].blocks[i][0] != '\0') {
            char runnow[64];
            checkwf(blockarr[1].blocks[i], runnow, ':');
            runfunc(runnow);
            i++;
        }
    }
    if (strcmp(namefunc, "iblock") == 0) {
        char line[128];
        int i = 0;
        while (i < 28 && fgets(line, sizeof(line), stdin)) {
            size_t len = strlen(line);
        
            while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
                line[--len] = '\0';
            }
            if (len == 0) continue;
            
            char *percent = strchr(line, '%');
            if (percent) {
                *percent = '\0';
                len = strlen(line);
            }
            
            if (len > 0 && line[len - 1] == '|') {
                line[--len] = '\0';
            }
            
            if (len > 0) {
                strncpy(blockarr[1].blocks[i], line, 63);
                blockarr[1].blocks[i][63] = '\0';
                i++;
            }
            
            if (percent) break;
        }
    }    
}
