#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 3 == 0 && i %5 != 0)
        {
            printf("%i: Fizz\n", i);
        }
        else if (i % 5 == 0 && i % 3 != 0)
        {
            printf("%i: Buzz\n", i);
        }
        else if (i % 3 == 0 && i % 5 == 0)
        {
            printf("%i: FizzBuzz\n", i);
        }
        else
        {
            printf("%i\n", i);
        }        
    }
}