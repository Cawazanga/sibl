#ifndef FUNC_H
#define FUNC_H


void check(const char *buf, char from, char *var, char doas);
void checkwf(const char *buf, char *var, char doas);
void checkwd(const char *buf, char from, char *var);
int runfunc(const char *bodyb);
char runbuf(const char *buf);

char bufs[2048][1024];

#endif
