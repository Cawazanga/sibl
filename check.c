#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include <stdbool.h>
#include <string.h>
void check(const char *buf, const char from, char *var, const char doas)
{
    bool start = false;
    int j = 0;


    for (int i = 0; buf[i] != '\0'; i++) {
        if (start == false && buf[i] == from) {
            start = true;
            continue;
        }

        if (start == true && buf[i] == doas) {

            break;
        }

        if (start == true) {
            var[j] = buf[i];
            j++;
        }
    }

    var[j] = '\0';

}
void checkwf(const char *buf, char *var, const char doas)
{
    bool start = true;
    int j = 0;

    for (int i = 0; buf[i] != doas; i++) {


        if (start == true) {
            var[j] = buf[i];
            j++;
        }
        if (buf[i] == '\0') {
            printf("Error");
            exit(-1);
        }
    }

    var[j] = '\0';

}
