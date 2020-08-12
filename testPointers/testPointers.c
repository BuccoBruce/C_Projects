#include <stdio.h>

int main(){
    int x = 4;
    int *p = &x;
    int r = *p;
    r = r + 2;

    printf("address is %p\n", p);
    printf("value is %d\n", r);

    return 0;
}