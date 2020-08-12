//#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //long ccnum = get_long("Please input the credit card number: ");
    long ccnum;
    scanf("%ld", &ccnum);
    long ccnumtmp = ccnum;
    long ccnumtmptwo = ccnum;
    int firstDigit = ccnum;
    int secondDigit = ccnum;
    long counttmp = ccnum;
    int count = 0;

    while (counttmp)
    {
        counttmp /= 10;
        count++;
    }
    printf("Card number is %i digits long.\n", count);

    while (ccnumtmp)
    {
        firstDigit = ccnumtmp;
        ccnumtmp /= 10;
    }
    printf("First digit is %i\n", firstDigit);

    while (ccnumtmptwo > 100)
    {
        ccnumtmptwo /= 10;
        secondDigit = ccnumtmptwo;
    }
    printf("Two digits is %i\n", secondDigit);


    int x = 0;
    int y = 0;
    int tmp = 0;

    do
    {
        y = y + ccnum % 10;
        ccnum = floor(ccnum / 10);
        if ((ccnum % 10) * 2 >= 10)
        {
            tmp = ((ccnum % 10) * 2);
            do
            {
                x = x + (tmp % 10);
                tmp = floor(tmp / 10);
            }
            while (tmp > 0);
        }
        else
        {
            x = x + ((ccnum % 10) * 2);
        }
        ccnum = floor(ccnum / 10);
    }
    while (ccnum > 0);

    printf("==================================================\n");
    printf("x final value: %i\n", x);
    printf("y final value: %i\n", y);
    printf("Total sum is %i\n", (x + y));

    if ((x + y) % 10 == 0)
    {
        printf("Card is valid!\n");
        if (count == 16)
        {
            if (firstDigit == 4)
            {
                printf("VISA\n");
            }
            else if (secondDigit == 51 || secondDigit == 52 || secondDigit == 53 || secondDigit == 54 || secondDigit == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 15)
        {
            if (secondDigit == 34 || secondDigit == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (count == 13)
        {
            if (firstDigit == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
