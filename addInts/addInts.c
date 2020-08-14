#include <stdio.h>

int addInts(int x, int y)
{
    return x + y;
}

int main(void)
{
    printf("Please input first value: \n");
    int* x = 0;
    scanf("%i", &x);

    printf("Please input second value: \n");
    int* y = 0;
    scanf("%i", &y);
    //int sum = addInts(x, y);
    printf("%i\n", addInts(*x, *y));
}