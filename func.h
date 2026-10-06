#ifndef FUNC_H
#define FUNC_H


void check(const char *buf, char from, char *var, char doas);
void checkwf(const char *buf, char *var, char doas);
void checkwd(const char *buf, char from, char *var);
int runfunc(const char *bodyb);
char runbuf(const char *buf);
int algpars(const char *buf);
int workvar(int arg, const char *namevar, const char *value);
int searchvar(const char *namevar);
int getnumargforvar(const char *argname);
int rand_range(int min, int max);
struct intvar {
    char name[12];
    int cap;
};
extern char bufs[2048][1024];
extern struct intvar vararr[64];
extern int countintarr;


#endif
