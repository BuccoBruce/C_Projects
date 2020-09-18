#include <stdio.h>
#include <string.h>
#include <strings.h>

int main(void){
    char *str1 = "apple";
    char *str2 = "apple";

    if (strcasecmp(str1, str2) == 0 )
    {
        printf("Match found!\n");
    }
    else
    {
        printf("Not found\n");
    }
    
}

