#ifndef FUNC_H
#define FUNC_H
#include <stdbool.h>

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
int searchdef(const char *namedef);
bool ifthen(int charg, const char *fa, const char *sa);
void initblockvar(const char *nameblock, char blockin[28][64]);

struct intvar {
    char name[12];
    int cap;
};
struct blockvar {
    char name[12];
    char blocks[28][64];
    int size;
};
extern char bufs[2048][1024];
extern struct intvar vararr[64];
extern struct blockvar blockarr[64];
extern int countintarr;
extern int countblockarr;

#endif
