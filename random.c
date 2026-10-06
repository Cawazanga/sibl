#include "func.h"
#include <stdlib.h>
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}
