#include <stdbool.h>
bool test(int n1, int n2)
{
    return n1 == n2;
}
int main(void) 
{
    if (test(1, 2))
        return 1;
    else
        return -1;
}
