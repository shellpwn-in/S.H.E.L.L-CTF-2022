#include <stdio.h>
#include <string.h>

// shellctf{b1tWi5e_0p3rAt0rS}

int main()
{
    char flag[28];

    printf("enter the flag: ");
    scanf("%s", flag);

    if(strlen(flag) != 27)
        printf("wrong length\n");
    else
    {
    
        int check[] = {460, 416, 404, 432, 432, 396, 464, 408, 492, 392, 196, 464, 348, 420, 212, 404, 380, 192, 448, 204, 456, 260, 464, 192, 456, 332, 500};

        int res = 1;
        for(int i = 0; i < 27; i++)
            res &= !((check[i] >> 2) ^ flag[i]);

        if(res != 1)
            printf("nah that's not it\n");
        else
            printf("yes, that's it\n");
    }
}

